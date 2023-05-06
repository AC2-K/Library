---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/xor_shift.hpp
    title: src/random/xor_shift.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
    title: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u53CD\u8EE2\u53EF\u80FD\u62BD\u8C61\u5316\u5E73\u8861\u4E8C\u5206\
      \u63A2\u7D22\u6728"
    links:
    - https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_reverse_range_sum/sol/correct.cpp
  bundledCode: "#line 2 \"src/BST/Reversible.hpp\"\n#include <cassert>\n#include <memory>\n\
    #include <utility>\n#line 2 \"src/random/xor_shift.hpp\"\n#include <cstdint>\n\
    #include <random>\n#include <chrono>\n\nnamespace kyopro {\nstruct xor_shift32\
    \ {\n    uint32_t rng;\n    constexpr explicit xor_shift32(uint32_t seed) : rng(seed)\
    \ {}\n    explicit xor_shift32():rng(std::chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n        rng\
    \ ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n};\n\n\
    struct xor_shift{\n    uint64_t rng;\n    constexpr xor_shift(uint64_t seed):rng(seed){}\n\
    \    explicit xor_shift():rng(std::chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n        rng\
    \ ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n};\n\n\
    };  // namespace kyopro\n#line 6 \"src/BST/Reversible.hpp\"\n\n/// @ref\n/// https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_reverse_range_sum/sol/correct.cpp\n\
    \nnamespace kyopro {\n/// @brief \u53CD\u8EE2\u53EF\u80FD\u62BD\u8C61\u5316\u5E73\
    \u8861\u4E8C\u5206\u63A2\u7D22\u6728\n/// @tparam S \u30E2\u30CE\u30A4\u30C9\n\
    /// @tparam op \u6F14\u7B97\n/// @tparam e \u5358\u4F4D\u5143\ntemplate <typename\
    \ S, S (*op)(S, S), S (*e)()>\nclass reversible_bst {\n    using u32 = uint32_t;\n\
    \    xor_shift32 rng;\n    struct Node {\n        std::unique_ptr<Node> l, r;\n\
    \        u32 priority;\n        S value, prod;\n        int size;\n        bool\
    \ rev;\n\n        Node(S v, u32 prio)\n            : l(),\n              r(),\n\
    \              priority(prio),\n              value(v),\n              prod(v),\n\
    \              size(1),\n              rev(false) {}\n    };\n\n    using ptr\
    \ = std::unique_ptr<Node>;\n    int size(const ptr& p) const { return p ? p->size\
    \ : 0; }\n    S fold(const ptr& p) { return p ? p->prod : e(); }\n\n    void reverse(const\
    \ ptr& p) {\n        if (p) {\n            p->rev ^= 1;\n        }\n    }\n\n\
    \    void push(const ptr& p) {\n        if (p->rev) {\n            p->rev = false;\n\
    \            std::swap(p->l, p->r);\n            reverse(p->l), reverse(p->r);\n\
    \        }\n    }\n\n    void update(const ptr& p) {\n        p->size = size(p->l)\
    \ + size(p->r) + 1;\n        p->prod = op(p->value, op(fold(p->l), fold(p->r)));\n\
    \    }\n\n    std::pair<ptr, ptr> split(ptr p, int k) {\n        if (!p) return\
    \ {nullptr, nullptr};\n\n        push(p);\n        int s = size(p->l);\n     \
    \   if (s >= k) {\n            auto [l, r] = split(std::move(p->l), k);\n    \
    \        p->l = std::move(r);\n            update(p);\n\n            return {std::move(l),\
    \ std::move(p)};\n        } else {\n            auto [l, r] = split(std::move(p->r),\
    \ k - s - 1);\n\n            p->r = std::move(l);\n            update(p);\n\n\
    \            return {std::move(p), std::move(r)};\n        }\n    }\n\n    ptr\
    \ merge(ptr l, ptr r) {\n        if (!l) return r;\n        if (!r) return l;\n\
    \n        if (l->priority < r->priority) {\n            push(r);\n           \
    \ r->l = merge(std::move(l), std::move(r->l));\n            update(r);\n     \
    \       return r;\n        } else {\n            push(l);\n            l->r =\
    \ merge(std::move(l->r), std::move(r));\n            update(l);\n\n          \
    \  return l;\n        }\n    }\n\n    ptr root = nullptr;\n\npublic:\n    constexpr\
    \ explicit reversible_bst() : rng(2023) {}\n    void insert(int i, S a) {\n  \
    \      auto [l, r] = split(std::move(root), i);\n        ptr item = std::make_unique<Node>(a,\
    \ rng());\n        root = merge(std::move(l), std::move(item));\n        root\
    \ = merge(std::move(root), std::move(r));\n    }\n    S fold(int l, int r) {\n\
    \        assert(0 <= l && l <= r && r <= size(root));\n        auto [xy, z] =\
    \ split(std::move(root), r);\n        auto [x, y] = split(std::move(xy), l);\n\
    \        auto res = fold(y);\n        xy = merge(std::move(x), std::move(y));\n\
    \        root = merge(std::move(xy), std::move(z));\n        return res;\n   \
    \ }\n    void reverse(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ size(root));\n        auto [xy, z] = split(std::move(root), r);\n        auto\
    \ [x, y] = split(std::move(xy), l);\n        reverse(y);\n        xy = merge(std::move(x),\
    \ std::move(y));\n        root = merge(std::move(xy), std::move(z));\n    }\n\
    };\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include <utility>\n\
    #include \"../random/xor_shift.hpp\"\n\n/// @ref\n/// https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_reverse_range_sum/sol/correct.cpp\n\
    \nnamespace kyopro {\n/// @brief \u53CD\u8EE2\u53EF\u80FD\u62BD\u8C61\u5316\u5E73\
    \u8861\u4E8C\u5206\u63A2\u7D22\u6728\n/// @tparam S \u30E2\u30CE\u30A4\u30C9\n\
    /// @tparam op \u6F14\u7B97\n/// @tparam e \u5358\u4F4D\u5143\ntemplate <typename\
    \ S, S (*op)(S, S), S (*e)()>\nclass reversible_bst {\n    using u32 = uint32_t;\n\
    \    xor_shift32 rng;\n    struct Node {\n        std::unique_ptr<Node> l, r;\n\
    \        u32 priority;\n        S value, prod;\n        int size;\n        bool\
    \ rev;\n\n        Node(S v, u32 prio)\n            : l(),\n              r(),\n\
    \              priority(prio),\n              value(v),\n              prod(v),\n\
    \              size(1),\n              rev(false) {}\n    };\n\n    using ptr\
    \ = std::unique_ptr<Node>;\n    int size(const ptr& p) const { return p ? p->size\
    \ : 0; }\n    S fold(const ptr& p) { return p ? p->prod : e(); }\n\n    void reverse(const\
    \ ptr& p) {\n        if (p) {\n            p->rev ^= 1;\n        }\n    }\n\n\
    \    void push(const ptr& p) {\n        if (p->rev) {\n            p->rev = false;\n\
    \            std::swap(p->l, p->r);\n            reverse(p->l), reverse(p->r);\n\
    \        }\n    }\n\n    void update(const ptr& p) {\n        p->size = size(p->l)\
    \ + size(p->r) + 1;\n        p->prod = op(p->value, op(fold(p->l), fold(p->r)));\n\
    \    }\n\n    std::pair<ptr, ptr> split(ptr p, int k) {\n        if (!p) return\
    \ {nullptr, nullptr};\n\n        push(p);\n        int s = size(p->l);\n     \
    \   if (s >= k) {\n            auto [l, r] = split(std::move(p->l), k);\n    \
    \        p->l = std::move(r);\n            update(p);\n\n            return {std::move(l),\
    \ std::move(p)};\n        } else {\n            auto [l, r] = split(std::move(p->r),\
    \ k - s - 1);\n\n            p->r = std::move(l);\n            update(p);\n\n\
    \            return {std::move(p), std::move(r)};\n        }\n    }\n\n    ptr\
    \ merge(ptr l, ptr r) {\n        if (!l) return r;\n        if (!r) return l;\n\
    \n        if (l->priority < r->priority) {\n            push(r);\n           \
    \ r->l = merge(std::move(l), std::move(r->l));\n            update(r);\n     \
    \       return r;\n        } else {\n            push(l);\n            l->r =\
    \ merge(std::move(l->r), std::move(r));\n            update(l);\n\n          \
    \  return l;\n        }\n    }\n\n    ptr root = nullptr;\n\npublic:\n    constexpr\
    \ explicit reversible_bst() : rng(2023) {}\n    void insert(int i, S a) {\n  \
    \      auto [l, r] = split(std::move(root), i);\n        ptr item = std::make_unique<Node>(a,\
    \ rng());\n        root = merge(std::move(l), std::move(item));\n        root\
    \ = merge(std::move(root), std::move(r));\n    }\n    S fold(int l, int r) {\n\
    \        assert(0 <= l && l <= r && r <= size(root));\n        auto [xy, z] =\
    \ split(std::move(root), r);\n        auto [x, y] = split(std::move(xy), l);\n\
    \        auto res = fold(y);\n        xy = merge(std::move(x), std::move(y));\n\
    \        root = merge(std::move(xy), std::move(z));\n        return res;\n   \
    \ }\n    void reverse(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ size(root));\n        auto [xy, z] = split(std::move(root), r);\n        auto\
    \ [x, y] = split(std::move(xy), l);\n        reverse(y);\n        xy = merge(std::move(x),\
    \ std::move(y));\n        root = merge(std::move(xy), std::move(z));\n    }\n\
    };\n};  // namespace kyopro"
  dependsOn:
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/BST/Reversible.hpp
  requiredBy: []
  timestamp: '2023-05-06 08:11:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
documentation_of: src/BST/Reversible.hpp
layout: document
redirect_from:
- /library/src/BST/Reversible.hpp
- /library/src/BST/Reversible.hpp.html
title: "\u53CD\u8EE2\u53EF\u80FD\u62BD\u8C61\u5316\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\
  \u6728"
---