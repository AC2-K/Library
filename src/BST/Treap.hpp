#pragma once
#include<cstdint>
#include <cassert>
namespace kyopro {
/// @brief Treap



/// @brief 多重集合
/// @tparam T 型
template <class T>
class multiset_treap {
    using u32 = uint32_t;
    uint32_t rng = 1;
    struct node {
        T key;
        u32 priority;
        node *l, *r;
        node(T key, u32 priority)
            : key(key), priority(priority), l(nullptr), r(nullptr){}
        
        ~node() {
            delete l;
            delete r;
        }
    };
    node* root = nullptr;
    void split(node* t, T key, node*& l, node*& r) {
        if (!t) {
            l = r = nullptr;
        } else if (key < t->key) {
            split(t->l, key, l, t->l), r = t;
        } else {
            split(t->r, key, t->r, r), l = t;
        }
    }
 
    void merge(node*& t, node* l, node* r) {
        if (!l || !r) {
            t = l ? l : r;
        } else if (l->priority > r->priority) {
            merge(l->r, l->r, r), t = l;
        } else {
            merge(r->l, l, r->l), t = r;
        }
    }
 
    void insert(node*& t, node* item) {
        if (!t) {
            t = item;
        } else if (item->priority > t->priority) {
            split(t, item->key, item->l, item->r), t = item;
        } else {
            insert(item->key < t->key ? t->l : t->r, item);
        }
    }
 
    void erase(node*& t, T key) {
        if (!t) return;
        if (t->key == key) {
            merge(t, t->l, t->r);
        } else {
            erase(key < t->key ? t->l : t->r, key);
        }
    }
 
    const node* find(node* t, T key) const {
        if (!t) {
            return nullptr;
        } else if (t->key == key) {
            return t;
        } else {
            return find(key < t->key ? t->l : t->r, key);
        }
    }
 
public:
    ~multiset_treap() { delete root; }
    void insert(T key) {
        rng ^= rng << 13;
        rng ^= rng >> 17;
        rng ^= rng << 5;
        insert(root, new node(key, rng));
    }

    void erase(T key) {
        erase(root, key);
    }

    const node* find(T key) const { return find(root, key); }
    T min_element() const {
        assert(root);
        auto cur = root;
        while (cur->l) cur = cur->l;
        return cur->key;
    }
    T max_element() const {
        assert(root);
        auto cur = root;
        while (cur->r) cur = cur->r;
        return cur->key;
    }
};

/// @brief 集合
/// @tparam T 型
template <class T>
class set_treap {
    using u32 = uint32_t;
    uint32_t rng = 1;
    struct node {
        T key;
        u32 priority;
        node *l, *r;
        node(T key, u32 priority)
            : key(key), priority(priority), l(nullptr), r(nullptr){}
        
        ~node() {
            delete l;
            delete r;
        }
    };
    node* root = nullptr;
    void split(node* t, T key, node*& l, node*& r) {
        if (!t) {
            l = r = nullptr;
        } else if (key < t->key) {
            split(t->l, key, l, t->l), r = t;
        } else {
            split(t->r, key, t->r, r), l = t;
        }
    }
 
    void merge(node*& t, node* l, node* r) {
        if (!l || !r) {
            t = l ? l : r;
        } else if (l->priority > r->priority) {
            merge(l->r, l->r, r), t = l;
        } else {
            merge(r->l, l, r->l), t = r;
        }
    }
 
    void insert(node*& t, node* item) {
        if (!t) {
            t = item;
        } else if (item->priority > t->priority) {
            split(t, item->key, item->l, item->r), t = item;
        } else {
            insert(item->key < t->key ? t->l : t->r, item);
        }
    }
 
    void erase(node*& t, T key) {
        if (!t) return;
        if (t->key == key) {
            merge(t, t->l, t->r);
        } else {
            erase(key < t->key ? t->l : t->r, key);
        }
    }
 
    const node* find(node* t, T key) const {
        if (!t) {
            return nullptr;
        } else if (t->key == key) {
            return t;
        } else {
            return find(key < t->key ? t->l : t->r, key);
        }
    }
 
public:
    ~set_treap() { delete root; }
    void insert(T key) {
        rng ^= rng << 13;
        rng ^= rng >> 17;
        rng ^= rng << 5;
        if (!find(key)) {
            insert(root, new node(key, rng));
        }
    }
 
    void erase(T key) {
        erase(root, key);
    }

    const node* find(T key) const { return find(root, key); }
    T min_element() const {
        assert(root);
        auto cur = root;
        while (cur->l) cur = cur->l;
        return cur->key;
    }
    T max_element() const {
        assert(root);
        auto cur = root;
        while (cur->r) cur = cur->r;
        return cur->key;
    }
};

};  // namespace kyopro