---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Treap
    links: []
  bundledCode: "#line 2 \"src/BST/Treap.hpp\"\n#include<cstdint>\n#include <cassert>\n\
    namespace kyopro {\n/// @brief Treap\n/// @tparam T \u578B\ntemplate <class T>\n\
    class multiset_treap {\n    using u32 = uint32_t;\n    uint32_t rng = 1;\n   \
    \ struct node {\n        T key;\n        u32 priority;\n        node *l, *r;\n\
    \        node(T key, u32 priority)\n            : key(key), priority(priority),\
    \ l(nullptr), r(nullptr){}\n        \n        ~node() {\n            delete l;\n\
    \            delete r;\n        }\n    };\n    node* root = nullptr;\n    void\
    \ split(node* t, T key, node*& l, node*& r) {\n        if (!t) {\n           \
    \ l = r = nullptr;\n        } else if (key < t->key) {\n            split(t->l,\
    \ key, l, t->l), r = t;\n        } else {\n            split(t->r, key, t->r,\
    \ r), l = t;\n        }\n    }\n \n    void merge(node*& t, node* l, node* r)\
    \ {\n        if (!l || !r) {\n            t = l ? l : r;\n        } else if (l->priority\
    \ > r->priority) {\n            merge(l->r, l->r, r), t = l;\n        } else {\n\
    \            merge(r->l, l, r->l), t = r;\n        }\n    }\n \n    void insert(node*&\
    \ t, node* item) {\n        if (!t) {\n            t = item;\n        } else if\
    \ (item->priority > t->priority) {\n            split(t, item->key, item->l, item->r),\
    \ t = item;\n        } else {\n            insert(item->key < t->key ? t->l :\
    \ t->r, item);\n        }\n    }\n \n    void erase(node*& t, T key) {\n     \
    \   if (!t) return;\n        if (t->key == key) {\n            merge(t, t->l,\
    \ t->r);\n        } else {\n            erase(key < t->key ? t->l : t->r, key);\n\
    \        }\n    }\n \n    const node* find(node* t, T key) const {\n        if\
    \ (!t) {\n            return nullptr;\n        } else if (t->key == key) {\n \
    \           return t;\n        } else {\n            return find(key < t->key\
    \ ? t->l : t->r, key);\n        }\n    }\n \npublic:\n    ~multiset_treap() {\
    \ delete root; }\n    void insert(T key) {\n        rng ^= rng << 13;\n      \
    \  rng ^= rng >> 17;\n        rng ^= rng << 5;\n        if (!find(key)) {\n  \
    \          insert(root, new node(key, rng));\n        }\n    }\n \n    void erase(T\
    \ key) {\n        erase(root, key);\n    }\n\n    const node* find(T key) const\
    \ { return find(root, key); }\n    T min_element() const {\n        assert(root);\n\
    \        auto cur = root;\n        while (cur->l) cur = cur->l;\n        return\
    \ cur->key;\n    }\n    T max_element() const {\n        assert(root);\n     \
    \   auto cur = root;\n        while (cur->r) cur = cur->r;\n        return cur->key;\n\
    \    }\n};\n};  // namespace kyopro\n"
  code: "#pragma once\n#include<cstdint>\n#include <cassert>\nnamespace kyopro {\n\
    /// @brief Treap\n/// @tparam T \u578B\ntemplate <class T>\nclass multiset_treap\
    \ {\n    using u32 = uint32_t;\n    uint32_t rng = 1;\n    struct node {\n   \
    \     T key;\n        u32 priority;\n        node *l, *r;\n        node(T key,\
    \ u32 priority)\n            : key(key), priority(priority), l(nullptr), r(nullptr){}\n\
    \        \n        ~node() {\n            delete l;\n            delete r;\n \
    \       }\n    };\n    node* root = nullptr;\n    void split(node* t, T key, node*&\
    \ l, node*& r) {\n        if (!t) {\n            l = r = nullptr;\n        } else\
    \ if (key < t->key) {\n            split(t->l, key, l, t->l), r = t;\n       \
    \ } else {\n            split(t->r, key, t->r, r), l = t;\n        }\n    }\n\
    \ \n    void merge(node*& t, node* l, node* r) {\n        if (!l || !r) {\n  \
    \          t = l ? l : r;\n        } else if (l->priority > r->priority) {\n \
    \           merge(l->r, l->r, r), t = l;\n        } else {\n            merge(r->l,\
    \ l, r->l), t = r;\n        }\n    }\n \n    void insert(node*& t, node* item)\
    \ {\n        if (!t) {\n            t = item;\n        } else if (item->priority\
    \ > t->priority) {\n            split(t, item->key, item->l, item->r), t = item;\n\
    \        } else {\n            insert(item->key < t->key ? t->l : t->r, item);\n\
    \        }\n    }\n \n    void erase(node*& t, T key) {\n        if (!t) return;\n\
    \        if (t->key == key) {\n            merge(t, t->l, t->r);\n        } else\
    \ {\n            erase(key < t->key ? t->l : t->r, key);\n        }\n    }\n \n\
    \    const node* find(node* t, T key) const {\n        if (!t) {\n           \
    \ return nullptr;\n        } else if (t->key == key) {\n            return t;\n\
    \        } else {\n            return find(key < t->key ? t->l : t->r, key);\n\
    \        }\n    }\n \npublic:\n    ~multiset_treap() { delete root; }\n    void\
    \ insert(T key) {\n        rng ^= rng << 13;\n        rng ^= rng >> 17;\n    \
    \    rng ^= rng << 5;\n        if (!find(key)) {\n            insert(root, new\
    \ node(key, rng));\n        }\n    }\n \n    void erase(T key) {\n        erase(root,\
    \ key);\n    }\n\n    const node* find(T key) const { return find(root, key);\
    \ }\n    T min_element() const {\n        assert(root);\n        auto cur = root;\n\
    \        while (cur->l) cur = cur->l;\n        return cur->key;\n    }\n    T\
    \ max_element() const {\n        assert(root);\n        auto cur = root;\n   \
    \     while (cur->r) cur = cur->r;\n        return cur->key;\n    }\n};\n};  //\
    \ namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/BST/Treap.hpp
  requiredBy: []
  timestamp: '2023-05-02 14:34:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/BST/Treap.hpp
layout: document
redirect_from:
- /library/src/BST/Treap.hpp
- /library/src/BST/Treap.hpp.html
title: Treap
---
