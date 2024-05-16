---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: Xor Shift
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/Range_Reverse_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Reverse_Range_Sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728"
    links:
    - https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_reverse_range_sum/sol/correct.cpp
  bundledCode: "#line 2 \"src/data-structure/bbst/reversible_bbst.hpp\"\n#include\
    \ <cassert>\n#include <memory>\n#include <utility>\n#line 2 \"src/random/xor_shift.hpp\"\
    \n#include <chrono>\n#include <cstdint>\n#include <random>\n\nnamespace kyopro\
    \ {\nstruct xor_shift32 {\n    uint32_t rng;\n    constexpr explicit xor_shift32(uint32_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr explicit xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief Xor Shift\n */\n#line 6 \"src/data-structure/bbst/reversible_bbst.hpp\"\
    \n\nnamespace kyopro {\ntemplate <class S, auto op, auto e> class reversible_bbst\
    \ {\n    using u32 = uint32_t;\n    xor_shift32 rng;\n    struct Node {\n    \
    \    Node *l, *r;\n        u32 priority;\n        S value, prod;\n        int\
    \ size;\n        bool rev;\n\n        Node(const S& v, u32 prio)\n           \
    \ : l(nullptr),\n              r(nullptr),\n              priority(prio),\n  \
    \            value(v),\n              prod(v),\n              size(1),\n     \
    \         rev(false) {}\n    };\n\n    using uptr = std::unique_ptr<Node>;\n \
    \   std::vector<uptr> nodes;\n    Node* make_ptr(const S& v, u32 prio) {\n   \
    \     nodes.emplace_back(std::make_unique<Node>(v, prio));\n        return nodes.back().get();\n\
    \    }\n    int size(Node* p) const { return p ? p->size : 0; }\n    S fold(Node*\
    \ p) { return p ? p->prod : e(); }\n\n    void reverse(Node*& p) {\n        if\
    \ (p) {\n            p->rev ^= 1;\n        }\n    }\n    void push_down(Node*&\
    \ p) {\n        if (p->rev) {\n            p->rev = false;\n            std::swap(p->l,\
    \ p->r);\n            reverse(p->l), reverse(p->r);\n        }\n    }\n    void\
    \ push_up(Node*& p) {\n        p->size = size(p->l) + size(p->r) + 1;\n      \
    \  p->prod = op(p->value, op(fold(p->l), fold(p->r)));\n    }\n\n    std::pair<Node*,\
    \ Node*> split(Node* p, int k) {\n        if (!p) return {nullptr, nullptr};\n\
    \n        push_down(p);\n        int s = size(p->l);\n        if (s >= k) {\n\
    \            auto [l, r] = split(p->l, k);\n            p->l = r;\n          \
    \  push_up(p);\n            return {std::move(l), std::move(p)};\n        } else\
    \ {\n            auto [l, r] = split(p->r, k - s - 1);\n\n            p->r = l;\n\
    \            push_up(p);\n\n            return {std::move(p), std::move(r)};\n\
    \        }\n    }\n\n    Node* merge(Node* l, Node* r) {\n        if (!l) return\
    \ std::move(r);\n        if (!r) return std::move(l);\n\n        push_down(l);\n\
    \        push_down(r);\n\n        if (l->priority < r->priority) {\n         \
    \   r->l = merge(l, r->l);\n            push_up(r);\n            return std::move(r);\n\
    \        } else {\n            l->r = merge(l->r, r);\n            push_up(l);\n\
    \n            return std::move(l);\n        }\n    }\n\n    Node* root;\n\npublic:\n\
    \    reversible_bbst() : rng(2023), root(nullptr) {}\n    void insert(int i, const\
    \ S& a) {\n        Node* item = make_ptr(a, rng());\n        auto [l, r] = split(root,\
    \ i);\n        root = merge(l, item);\n        root = merge(root, r);\n    }\n\
    \    void erase(int i) {\n        auto [x, yz] = split(root, i);\n        auto\
    \ [y, z] = split(yz, 1);\n        root = merge(x, z);\n    }\n\n    void update(int\
    \ i, const S& v) {\n        erase(i);\n        insert(i, v);\n    }\n\n    S access(int\
    \ i) {\n        assert(0 <= i && i < size(root));\n        Node* x = root;\n \
    \       while (1) {\n            push_down(x);\n            int z = size(x->l);\n\
    \n            if (i < z) {\n                x = x->l;\n            } else if (i\
    \ == z) {\n                return x->value;\n            } else {\n          \
    \      x = x->r;\n                i -= z + 1;\n            }\n        }\n    }\n\
    \n    S fold(int l, int r) {\n        assert(0 <= l && l <= r && r <= size(root));\n\
    \        auto [xy, z] = split(root, r);\n        auto [x, y] = split(xy, l);\n\
    \        S res = fold(y);\n        xy = merge(x, y);\n        root = merge(xy,\
    \ z);\n        return res;\n    }\n    void reverse(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= size(root));\n        auto [xy, z] = split(root, r);\n\
    \        auto [x, y] = split(xy, l);\n        reverse(y);\n        xy = merge(x,\
    \ y);\n        root = merge(xy, z);\n    }\n};\n};  // namespace kyopro\n\n/**\n\
    \ * @brief \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728\n * @see\n *\
    \ https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_reverse_range_sum/sol/correct.cpp\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include <utility>\n\
    #include \"../../random/xor_shift.hpp\"\n\nnamespace kyopro {\ntemplate <class\
    \ S, auto op, auto e> class reversible_bbst {\n    using u32 = uint32_t;\n   \
    \ xor_shift32 rng;\n    struct Node {\n        Node *l, *r;\n        u32 priority;\n\
    \        S value, prod;\n        int size;\n        bool rev;\n\n        Node(const\
    \ S& v, u32 prio)\n            : l(nullptr),\n              r(nullptr),\n    \
    \          priority(prio),\n              value(v),\n              prod(v),\n\
    \              size(1),\n              rev(false) {}\n    };\n\n    using uptr\
    \ = std::unique_ptr<Node>;\n    std::vector<uptr> nodes;\n    Node* make_ptr(const\
    \ S& v, u32 prio) {\n        nodes.emplace_back(std::make_unique<Node>(v, prio));\n\
    \        return nodes.back().get();\n    }\n    int size(Node* p) const { return\
    \ p ? p->size : 0; }\n    S fold(Node* p) { return p ? p->prod : e(); }\n\n  \
    \  void reverse(Node*& p) {\n        if (p) {\n            p->rev ^= 1;\n    \
    \    }\n    }\n    void push_down(Node*& p) {\n        if (p->rev) {\n       \
    \     p->rev = false;\n            std::swap(p->l, p->r);\n            reverse(p->l),\
    \ reverse(p->r);\n        }\n    }\n    void push_up(Node*& p) {\n        p->size\
    \ = size(p->l) + size(p->r) + 1;\n        p->prod = op(p->value, op(fold(p->l),\
    \ fold(p->r)));\n    }\n\n    std::pair<Node*, Node*> split(Node* p, int k) {\n\
    \        if (!p) return {nullptr, nullptr};\n\n        push_down(p);\n       \
    \ int s = size(p->l);\n        if (s >= k) {\n            auto [l, r] = split(p->l,\
    \ k);\n            p->l = r;\n            push_up(p);\n            return {std::move(l),\
    \ std::move(p)};\n        } else {\n            auto [l, r] = split(p->r, k -\
    \ s - 1);\n\n            p->r = l;\n            push_up(p);\n\n            return\
    \ {std::move(p), std::move(r)};\n        }\n    }\n\n    Node* merge(Node* l,\
    \ Node* r) {\n        if (!l) return std::move(r);\n        if (!r) return std::move(l);\n\
    \n        push_down(l);\n        push_down(r);\n\n        if (l->priority < r->priority)\
    \ {\n            r->l = merge(l, r->l);\n            push_up(r);\n           \
    \ return std::move(r);\n        } else {\n            l->r = merge(l->r, r);\n\
    \            push_up(l);\n\n            return std::move(l);\n        }\n    }\n\
    \n    Node* root;\n\npublic:\n    reversible_bbst() : rng(2023), root(nullptr)\
    \ {}\n    void insert(int i, const S& a) {\n        Node* item = make_ptr(a, rng());\n\
    \        auto [l, r] = split(root, i);\n        root = merge(l, item);\n     \
    \   root = merge(root, r);\n    }\n    void erase(int i) {\n        auto [x, yz]\
    \ = split(root, i);\n        auto [y, z] = split(yz, 1);\n        root = merge(x,\
    \ z);\n    }\n\n    void update(int i, const S& v) {\n        erase(i);\n    \
    \    insert(i, v);\n    }\n\n    S access(int i) {\n        assert(0 <= i && i\
    \ < size(root));\n        Node* x = root;\n        while (1) {\n            push_down(x);\n\
    \            int z = size(x->l);\n\n            if (i < z) {\n               \
    \ x = x->l;\n            } else if (i == z) {\n                return x->value;\n\
    \            } else {\n                x = x->r;\n                i -= z + 1;\n\
    \            }\n        }\n    }\n\n    S fold(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= size(root));\n        auto [xy, z] = split(root, r);\n\
    \        auto [x, y] = split(xy, l);\n        S res = fold(y);\n        xy = merge(x,\
    \ y);\n        root = merge(xy, z);\n        return res;\n    }\n    void reverse(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= size(root));\n        auto\
    \ [xy, z] = split(root, r);\n        auto [x, y] = split(xy, l);\n        reverse(y);\n\
    \        xy = merge(x, y);\n        root = merge(xy, z);\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728\
    \n * @see\n * https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_reverse_range_sum/sol/correct.cpp\n\
    \ */"
  dependsOn:
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/data-structure/bbst/reversible_bbst.hpp
  requiredBy: []
  timestamp: '2024-05-06 12:52:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/data_structure/Range_Reverse_Range_Sum.test.cpp
documentation_of: src/data-structure/bbst/reversible_bbst.hpp
layout: document
redirect_from:
- /library/src/data-structure/bbst/reversible_bbst.hpp
- /library/src/data-structure/bbst/reversible_bbst.hpp.html
title: "\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728"
---
