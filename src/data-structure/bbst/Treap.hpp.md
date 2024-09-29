---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: Xor Shift
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Treap.test.cpp
    title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Treap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Treap
    links: []
  bundledCode: "#line 2 \"src/data-structure/bbst/Treap.hpp\"\n#include <cassert>\n\
    #include <memory>\n#line 2 \"src/random/xor_shift.hpp\"\n#include <chrono>\n#include\
    \ <cstdint>\n#include <random>\n\nnamespace kyopro {\nstruct xor_shift32 {\n \
    \   uint32_t rng;\n    constexpr explicit xor_shift32(uint32_t seed) : rng(seed)\
    \ {}\n    explicit xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr explicit xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief Xor Shift\n */\n#line 5 \"src/data-structure/bbst/Treap.hpp\"\
    \n\nnamespace kyopro {\ntemplate <class T> struct Treap {\n    using u32 = std::uint32_t;\n\
    \    xor_shift32 rng;\n    struct Node {\n        const T key;\n        const\
    \ u32 priority;\n        Node *l, *r;\n        Node(const T& key, u32 priority)\n\
    \            : key(key), priority(priority), l(nullptr), r(nullptr) {}\n    };\n\
    \    using uptr = std::unique_ptr<Node>;\n    std::vector<uptr> nodes;\n    Node*\
    \ make_ptr(const T& key, u32 priority) {\n        nodes.emplace_back(std::make_unique<Node>(key,priority));\n\
    \        return nodes.back().get();\n    }\n\n    Node* root;\n    \n    void\
    \ split(Node* t, const T& key, Node*& l, Node*& r) {\n        if (!t) {\n    \
    \        l = r = nullptr;\n        } else if (key < t->key) {\n            split(t->l,\
    \ key, l, t->l);\n            r = t;\n        } else {\n            split(t->r,\
    \ key, t->r, r), l = t;\n        }\n    }\n\n    void merge(Node*& t, Node* l,\
    \ Node* r) {\n        if (!l || !r) {\n            t = l ? l : r;\n        } else\
    \ if (l->priority > r->priority) {\n            merge(l->r, l->r, r), t = l;\n\
    \        } else {\n            merge(r->l, l, r->l), t = r;\n        }\n    }\n\
    \n    void insert(Node*& t, Node* item) {\n        if (!t) {\n            t =\
    \ item;\n        } else if (item->priority > t->priority) {\n            split(t,\
    \ item->key, item->l, item->r);\n            t = item;\n        } else {\n   \
    \         insert(item->key < t->key ? t->l : t->r, item);\n        }\n    }\n\n\
    \    void erase(Node*& t, const T& key) {\n        if (!t) return;\n        if\
    \ (t->key == key) {\n            merge(t, t->l, t->r);\n        } else {\n   \
    \         erase(key < t->key ? t->l : t->r, key);\n        }\n    }\n\n    Node*\
    \ find(Node*& t, const T& key) {\n        if (!t) {\n            return nullptr;\n\
    \        } else if (t->key == key) {\n            return t;\n        } else {\n\
    \            return find(key < t->key ? t->l : t->r, key);\n        }\n    }\n\
    \npublic:\n    explicit Treap() : rng(2023), root(nullptr) {}\n    bool empty()\
    \ const { return root == nullptr; }\n    void insert(const T& key) { insert(root,\
    \ make_ptr(key, rng())); }\n    void erase(const T& key) { erase(root, key); }\n\
    \n    const Node* find(const T& key) const { return find(root, key); }\n\n   \
    \ T min_element() {\n        assert(root != nullptr);\n        Node* cur = root;\n\
    \        while (cur->l) {\n            cur = cur->l;\n        }\n        T ans\
    \ = cur->key;\n        return ans;\n    }\n    T max_element() {\n        assert(root);\n\
    \        Node* cur = root;\n        while (cur->r) {\n            cur = cur->r;\n\
    \        }\n        T ans = cur->key;\n        return ans;\n    }\n};\n};  //\
    \ namespace kyopro\n\n/**\n * @brief Treap\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include \"../../random/xor_shift.hpp\"\
    \n\nnamespace kyopro {\ntemplate <class T> struct Treap {\n    using u32 = std::uint32_t;\n\
    \    xor_shift32 rng;\n    struct Node {\n        const T key;\n        const\
    \ u32 priority;\n        Node *l, *r;\n        Node(const T& key, u32 priority)\n\
    \            : key(key), priority(priority), l(nullptr), r(nullptr) {}\n    };\n\
    \    using uptr = std::unique_ptr<Node>;\n    std::vector<uptr> nodes;\n    Node*\
    \ make_ptr(const T& key, u32 priority) {\n        nodes.emplace_back(std::make_unique<Node>(key,priority));\n\
    \        return nodes.back().get();\n    }\n\n    Node* root;\n    \n    void\
    \ split(Node* t, const T& key, Node*& l, Node*& r) {\n        if (!t) {\n    \
    \        l = r = nullptr;\n        } else if (key < t->key) {\n            split(t->l,\
    \ key, l, t->l);\n            r = t;\n        } else {\n            split(t->r,\
    \ key, t->r, r), l = t;\n        }\n    }\n\n    void merge(Node*& t, Node* l,\
    \ Node* r) {\n        if (!l || !r) {\n            t = l ? l : r;\n        } else\
    \ if (l->priority > r->priority) {\n            merge(l->r, l->r, r), t = l;\n\
    \        } else {\n            merge(r->l, l, r->l), t = r;\n        }\n    }\n\
    \n    void insert(Node*& t, Node* item) {\n        if (!t) {\n            t =\
    \ item;\n        } else if (item->priority > t->priority) {\n            split(t,\
    \ item->key, item->l, item->r);\n            t = item;\n        } else {\n   \
    \         insert(item->key < t->key ? t->l : t->r, item);\n        }\n    }\n\n\
    \    void erase(Node*& t, const T& key) {\n        if (!t) return;\n        if\
    \ (t->key == key) {\n            merge(t, t->l, t->r);\n        } else {\n   \
    \         erase(key < t->key ? t->l : t->r, key);\n        }\n    }\n\n    Node*\
    \ find(Node*& t, const T& key) {\n        if (!t) {\n            return nullptr;\n\
    \        } else if (t->key == key) {\n            return t;\n        } else {\n\
    \            return find(key < t->key ? t->l : t->r, key);\n        }\n    }\n\
    \npublic:\n    explicit Treap() : rng(2023), root(nullptr) {}\n    bool empty()\
    \ const { return root == nullptr; }\n    void insert(const T& key) { insert(root,\
    \ make_ptr(key, rng())); }\n    void erase(const T& key) { erase(root, key); }\n\
    \n    const Node* find(const T& key) const { return find(root, key); }\n\n   \
    \ T min_element() {\n        assert(root != nullptr);\n        Node* cur = root;\n\
    \        while (cur->l) {\n            cur = cur->l;\n        }\n        T ans\
    \ = cur->key;\n        return ans;\n    }\n    T max_element() {\n        assert(root);\n\
    \        Node* cur = root;\n        while (cur->r) {\n            cur = cur->r;\n\
    \        }\n        T ans = cur->key;\n        return ans;\n    }\n};\n};  //\
    \ namespace kyopro\n\n/**\n * @brief Treap\n */"
  dependsOn:
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/data-structure/bbst/Treap.hpp
  requiredBy: []
  timestamp: '2023-11-23 03:11:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Treap.test.cpp
documentation_of: src/data-structure/bbst/Treap.hpp
layout: document
redirect_from:
- /library/src/data-structure/bbst/Treap.hpp
- /library/src/data-structure/bbst/Treap.hpp.html
title: Treap
---
