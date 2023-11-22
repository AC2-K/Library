#pragma once
#include <cassert>
#include <memory>
#include "../../random/xor_shift.hpp"

namespace kyopro {
template <class T> struct Treap {
    using u32 = std::uint32_t;
    xor_shift32 rng;
    struct Node {
        const T key;
        const u32 priority;
        Node *l, *r;
        Node(const T& key, u32 priority)
            : key(key), priority(priority), l(nullptr), r(nullptr) {}
    };
    using uptr = std::unique_ptr<Node>;
    std::vector<uptr> nodes;
    Node* make_ptr(const T& key, u32 priority) {
        nodes.emplace_back(std::make_unique<Node>(key,priority));
        return nodes.back().get();
    }

    Node* root;
    
    void split(Node* t, const T& key, Node*& l, Node*& r) {
        if (!t) {
            l = r = nullptr;
        } else if (key < t->key) {
            split(t->l, key, l, t->l);
            r = t;
        } else {
            split(t->r, key, t->r, r), l = t;
        }
    }

    void merge(Node*& t, Node* l, Node* r) {
        if (!l || !r) {
            t = l ? l : r;
        } else if (l->priority > r->priority) {
            merge(l->r, l->r, r), t = l;
        } else {
            merge(r->l, l, r->l), t = r;
        }
    }

    void insert(Node*& t, Node* item) {
        if (!t) {
            t = item;
        } else if (item->priority > t->priority) {
            split(t, item->key, item->l, item->r);
            t = item;
        } else {
            insert(item->key < t->key ? t->l : t->r, item);
        }
    }

    void erase(Node*& t, const T& key) {
        if (!t) return;
        if (t->key == key) {
            merge(t, t->l, t->r);
        } else {
            erase(key < t->key ? t->l : t->r, key);
        }
    }

    Node* find(Node*& t, const T& key) {
        if (!t) {
            return nullptr;
        } else if (t->key == key) {
            return t;
        } else {
            return find(key < t->key ? t->l : t->r, key);
        }
    }

public:
    explicit Treap() : rng(2023), root(nullptr) {}
    bool empty() const { return root == nullptr; }
    void insert(const T& key) { insert(root, make_ptr(key, rng())); }
    void erase(const T& key) { erase(root, key); }

    const Node* find(const T& key) const { return find(root, key); }

    T min_element() {
        assert(root != nullptr);
        Node* cur = root;
        while (cur->l) {
            cur = cur->l;
        }
        T ans = cur->key;
        return ans;
    }
    T max_element() {
        assert(root);
        Node* cur = root;
        while (cur->r) {
            cur = cur->r;
        }
        T ans = cur->key;
        return ans;
    }
};
};  // namespace kyopro

/**
 * @brief Treap
 */