#pragma once
#include <cassert>
#include <memory>
#include "../../random/xor_shift.hpp"

namespace kyopro {
template <class T> class Treap {
    using u32 = std::uint32_t;
    xor_shift32 rng;
    struct Node {
        const T key;
        const u32 priority;
        std::shared_ptr<Node> l, r;
        Node(const T& key, u32 priority)
            : key(key), priority(priority), l(nullptr), r(nullptr) {}
    };
    using sptr = std::shared_ptr<Node>;
    sptr root = nullptr;
    void split(const sptr t, const T& key, sptr& l, sptr& r) {
        if (!t) {
            l = r = nullptr;
        } else if (key < t->key) {
            split(t->l, key, l, t->l);
            r = t;
        } else {
            split(t->r, key, t->r, r), l = t;
        }
    }

    void merge(sptr& t, const sptr& l, const sptr& r) {
        if (!l || !r) {
            t = l ? l : r;
        } else if (l->priority > r->priority) {
            merge(l->r, l->r, r), t = l;
        } else {
            merge(r->l, l, r->l), t = r;
        }
    }

    void insert(sptr& t, const sptr& item) {
        if (!t) {
            t = item;
        } else if (item->priority > t->priority) {
            split(t, item->key, item->l, item->r);
            t = item;
        } else {
            insert(item->key < t->key ? t->l : t->r, item);
        }
    }

    void erase(sptr& t, const T& key) {
        if (!t) return;
        if (t->key == key) {
            merge(t, t->l, t->r);
        } else {
            erase(key < t->key ? t->l : t->r, key);
        }
    }

    const sptr find(const sptr& t, const T& key) const {
        if (!t) {
            return nullptr;
        } else if (t->key == key) {
            return t;
        } else {
            return find(key < t->key ? t->l : t->r, key);
        }
    }

public:
    constexpr explicit Treap() : rng(2023) {}
    void insert(const T& key) {
        insert(root, std::make_shared<Node>(key, rng()));
    }

    void erase(const T& key) { erase(root, key); }

    const Node* find(const T& key) const { return find(root, key).get(); }
    T min_element() const {
        assert(root);
        sptr cur = root;
        while (cur->l) {
            cur = cur->l;
        }
        T ans = cur->key;
        return ans;
    }
    T max_element() {
        assert(root);
        sptr cur = root;
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