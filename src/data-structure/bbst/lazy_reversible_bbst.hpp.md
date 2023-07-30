---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: xor shift
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/bbst/lazy_reversible_bbst.md
    document_title: "\u9045\u5EF6\u8A55\u4FA1\u3064\u304D\u30FB\u53CD\u8EE2\u53EF\u80FD\
      \ \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728"
    links:
    - https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
  bundledCode: "#line 2 \"src/data-structure/bbst/lazy_reversible_bbst.hpp\"\n#include\
    \ <cassert>\n#include <memory>\n#include <utility>\n#line 2 \"src/random/xor_shift.hpp\"\
    \n#include <chrono>\n#include <cstdint>\n#include <random>\n\nnamespace kyopro\
    \ {\nstruct xor_shift32 {\n    uint32_t rng;\n    constexpr explicit xor_shift32(uint32_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief xor shift\n */\n#line 6 \"src/data-structure/bbst/lazy_reversible_bbst.hpp\"\
    \n\nnamespace kyopro {\n/**\n * @brief \u9045\u5EF6\u8A55\u4FA1\u3064\u304D\u30FB\
    \u53CD\u8EE2\u53EF\u80FD \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\n * @tparam\
    \ S \u30E2\u30CE\u30A4\u30C9\n * @tparam F \u4F5C\u7528\u7D20\n * @tparam op S\u306E\
    \u4E8C\u9805\u6F14\u7B97\n * @tparam e S\u306E\u5358\u4F4D\u5143\n * @tparam composition\
    \ F\u306E\u4E8C\u9805\u6F14\u7B97\n * @tparam id F\u306E\u5358\u4F4D\u5143\n *\
    \ @tparam mapping \u4F5C\u7528\n */\ntemplate <class S,\n          class F,\n\
    \          S (*op)(S, S),\n          S (*e)(),\n          F (*composition)(F,\
    \ F),\n          F (*id)(),\n          S (*mapping)(S, F, int)>\nclass lazy_reversible_bbst\
    \ {\n    using u32 = uint32_t;\n    xor_shift32 rng;\n    struct Node {\n    \
    \    std::unique_ptr<Node> l, r;\n        u32 priority;\n        S value, prod;\n\
    \n        F lazy;\n        int size;\n        bool rev;\n\n        Node(const\
    \ S& v, u32 prio)\n            : l(),\n              r(),\n              priority(prio),\n\
    \              value(v),\n              prod(e()),\n              lazy(id()),\n\
    \              size(1),\n              rev(false) {}\n    };\n\n    using ptr\
    \ = std::unique_ptr<Node>;\n    int size(const ptr& p) const { return p ? p->size\
    \ : 0; }\n    S fold(const ptr& p) { return p ? p->prod : e(); }\n\n    void update(const\
    \ ptr& p) {\n        if (!p) return;\n        p->size = size(p->l) + size(p->r)\
    \ + 1;\n        p->prod = op(p->value, op(fold(p->l), fold(p->r)));\n    }\n \
    \   void push(const ptr& p) {\n        if (!p) return;\n        if (p->rev) {\n\
    \            p->rev = false;\n            std::swap(p->l, p->r);\n           \
    \ reverse(p->l), reverse(p->r);\n        }\n\n        if (p->lazy != id()) {\n\
    \            if (p->l) {\n                p->l->lazy = composition(p->l->lazy,\
    \ p->lazy);\n                p->l->prod = mapping(p->l->prod, p->lazy, size(p->l));\n\
    \            }\n            if (p->r) {\n                p->r->lazy = composition(p->r->lazy,\
    \ p->lazy);\n                p->r->prod = mapping(p->r->prod, p->lazy, size(p->r));\n\
    \            }\n\n            p->value = mapping(p->value, p->lazy, 1);\n    \
    \        p->lazy = id();\n        }\n\n        update(p);\n    }\n\n    std::pair<ptr,\
    \ ptr> split(ptr p, int k) {\n        if (!p) return {nullptr, nullptr};\n\n \
    \       push(p);\n        int s = size(p->l);\n        if (s >= k) {\n       \
    \     auto [l, r] = split(std::move(p->l), k);\n            p->l = std::move(r);\n\
    \            update(p);\n\n            return {std::move(l), std::move(p)};\n\
    \        } else {\n            auto [l, r] = split(std::move(p->r), k - s - 1);\n\
    \n            p->r = std::move(l);\n            update(p);\n\n            return\
    \ {std::move(p), std::move(r)};\n        }\n    }\n\n    ptr merge(ptr l, ptr\
    \ r) {\n        if (!l) return r;\n        if (!r) return l;\n        push(l),\
    \ push(r);\n        if (l->priority < r->priority) {\n            r->l = merge(std::move(l),\
    \ std::move(r->l));\n            update(r);\n            return r;\n        }\
    \ else {\n            l->r = merge(std::move(l->r), std::move(r));\n         \
    \   update(l);\n            return l;\n        }\n    }\n\n    void reverse(const\
    \ ptr& p) {\n        if (p) {\n            p->rev ^= 1;\n        }\n    }\n  \
    \  ptr root = nullptr;\n\npublic:\n    constexpr explicit lazy_reversible_bbst()\
    \ : rng(2023) {}\n    void insert(int i, S a) {\n        auto [l, r] = split(std::move(root),\
    \ i);\n        ptr item = std::make_unique<Node>(a, rng());\n        root = merge(std::move(l),\
    \ std::move(item));\n        root = merge(std::move(root), std::move(r));\n  \
    \  }\n\n    void erase(int i) {\n        auto [xy, z] = split(std::move(root),\
    \ i + 1);\n        auto [x, y] = split(std::move(xy), i);\n        root = merge(std::move(x),\
    \ std::move(z));\n    }\n\n    S fold(int l, int r) {\n        auto [xy, z] =\
    \ split(std::move(root), r);\n        auto [x, y] = split(std::move(xy), l);\n\
    \        auto res = fold(y);\n        xy = merge(std::move(x), std::move(y));\n\
    \        root = merge(std::move(xy), std::move(z));\n        return res;\n   \
    \ }\n\n    void apply(int l, int r, const F& f) {\n        auto [xy, z] = split(std::move(root),\
    \ r);\n        auto [x, y] = split(std::move(xy), l);\n\n        y->lazy = composition(y->lazy,\
    \ f);\n        y->prod = mapping(y->prod, f, size(y));\n\n        xy = merge(std::move(x),\
    \ std::move(y));\n        root = merge(std::move(xy), std::move(z));\n    }\n\n\
    \    void reverse(int l, int r) {\n        auto [xy, z] = split(std::move(root),\
    \ r);\n        auto [x, y] = split(std::move(xy), l);\n        reverse(y);\n \
    \       xy = merge(std::move(x), std::move(y));\n        root = merge(std::move(xy),\
    \ std::move(z));\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/bbst/lazy_reversible_bbst.md\n\
    \ * @ref https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include <utility>\n\
    #include \"../../random/xor_shift.hpp\"\n\nnamespace kyopro {\n/**\n * @brief\
    \ \u9045\u5EF6\u8A55\u4FA1\u3064\u304D\u30FB\u53CD\u8EE2\u53EF\u80FD \u5E73\u8861\
    \u4E8C\u5206\u63A2\u7D22\u6728\n * @tparam S \u30E2\u30CE\u30A4\u30C9\n * @tparam\
    \ F \u4F5C\u7528\u7D20\n * @tparam op S\u306E\u4E8C\u9805\u6F14\u7B97\n * @tparam\
    \ e S\u306E\u5358\u4F4D\u5143\n * @tparam composition F\u306E\u4E8C\u9805\u6F14\
    \u7B97\n * @tparam id F\u306E\u5358\u4F4D\u5143\n * @tparam mapping \u4F5C\u7528\
    \n */\ntemplate <class S,\n          class F,\n          S (*op)(S, S),\n    \
    \      S (*e)(),\n          F (*composition)(F, F),\n          F (*id)(),\n  \
    \        S (*mapping)(S, F, int)>\nclass lazy_reversible_bbst {\n    using u32\
    \ = uint32_t;\n    xor_shift32 rng;\n    struct Node {\n        std::unique_ptr<Node>\
    \ l, r;\n        u32 priority;\n        S value, prod;\n\n        F lazy;\n  \
    \      int size;\n        bool rev;\n\n        Node(const S& v, u32 prio)\n  \
    \          : l(),\n              r(),\n              priority(prio),\n       \
    \       value(v),\n              prod(e()),\n              lazy(id()),\n     \
    \         size(1),\n              rev(false) {}\n    };\n\n    using ptr = std::unique_ptr<Node>;\n\
    \    int size(const ptr& p) const { return p ? p->size : 0; }\n    S fold(const\
    \ ptr& p) { return p ? p->prod : e(); }\n\n    void update(const ptr& p) {\n \
    \       if (!p) return;\n        p->size = size(p->l) + size(p->r) + 1;\n    \
    \    p->prod = op(p->value, op(fold(p->l), fold(p->r)));\n    }\n    void push(const\
    \ ptr& p) {\n        if (!p) return;\n        if (p->rev) {\n            p->rev\
    \ = false;\n            std::swap(p->l, p->r);\n            reverse(p->l), reverse(p->r);\n\
    \        }\n\n        if (p->lazy != id()) {\n            if (p->l) {\n      \
    \          p->l->lazy = composition(p->l->lazy, p->lazy);\n                p->l->prod\
    \ = mapping(p->l->prod, p->lazy, size(p->l));\n            }\n            if (p->r)\
    \ {\n                p->r->lazy = composition(p->r->lazy, p->lazy);\n        \
    \        p->r->prod = mapping(p->r->prod, p->lazy, size(p->r));\n            }\n\
    \n            p->value = mapping(p->value, p->lazy, 1);\n            p->lazy =\
    \ id();\n        }\n\n        update(p);\n    }\n\n    std::pair<ptr, ptr> split(ptr\
    \ p, int k) {\n        if (!p) return {nullptr, nullptr};\n\n        push(p);\n\
    \        int s = size(p->l);\n        if (s >= k) {\n            auto [l, r] =\
    \ split(std::move(p->l), k);\n            p->l = std::move(r);\n            update(p);\n\
    \n            return {std::move(l), std::move(p)};\n        } else {\n       \
    \     auto [l, r] = split(std::move(p->r), k - s - 1);\n\n            p->r = std::move(l);\n\
    \            update(p);\n\n            return {std::move(p), std::move(r)};\n\
    \        }\n    }\n\n    ptr merge(ptr l, ptr r) {\n        if (!l) return r;\n\
    \        if (!r) return l;\n        push(l), push(r);\n        if (l->priority\
    \ < r->priority) {\n            r->l = merge(std::move(l), std::move(r->l));\n\
    \            update(r);\n            return r;\n        } else {\n           \
    \ l->r = merge(std::move(l->r), std::move(r));\n            update(l);\n     \
    \       return l;\n        }\n    }\n\n    void reverse(const ptr& p) {\n    \
    \    if (p) {\n            p->rev ^= 1;\n        }\n    }\n    ptr root = nullptr;\n\
    \npublic:\n    constexpr explicit lazy_reversible_bbst() : rng(2023) {}\n    void\
    \ insert(int i, S a) {\n        auto [l, r] = split(std::move(root), i);\n   \
    \     ptr item = std::make_unique<Node>(a, rng());\n        root = merge(std::move(l),\
    \ std::move(item));\n        root = merge(std::move(root), std::move(r));\n  \
    \  }\n\n    void erase(int i) {\n        auto [xy, z] = split(std::move(root),\
    \ i + 1);\n        auto [x, y] = split(std::move(xy), i);\n        root = merge(std::move(x),\
    \ std::move(z));\n    }\n\n    S fold(int l, int r) {\n        auto [xy, z] =\
    \ split(std::move(root), r);\n        auto [x, y] = split(std::move(xy), l);\n\
    \        auto res = fold(y);\n        xy = merge(std::move(x), std::move(y));\n\
    \        root = merge(std::move(xy), std::move(z));\n        return res;\n   \
    \ }\n\n    void apply(int l, int r, const F& f) {\n        auto [xy, z] = split(std::move(root),\
    \ r);\n        auto [x, y] = split(std::move(xy), l);\n\n        y->lazy = composition(y->lazy,\
    \ f);\n        y->prod = mapping(y->prod, f, size(y));\n\n        xy = merge(std::move(x),\
    \ std::move(y));\n        root = merge(std::move(xy), std::move(z));\n    }\n\n\
    \    void reverse(int l, int r) {\n        auto [xy, z] = split(std::move(root),\
    \ r);\n        auto [x, y] = split(std::move(xy), l);\n        reverse(y);\n \
    \       xy = merge(std::move(x), std::move(y));\n        root = merge(std::move(xy),\
    \ std::move(z));\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/bbst/lazy_reversible_bbst.md\n\
    \ * @ref https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n */"
  dependsOn:
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/data-structure/bbst/lazy_reversible_bbst.hpp
  requiredBy: []
  timestamp: '2023-07-03 15:58:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
documentation_of: src/data-structure/bbst/lazy_reversible_bbst.hpp
layout: document
redirect_from:
- /library/src/data-structure/bbst/lazy_reversible_bbst.hpp
- /library/src/data-structure/bbst/lazy_reversible_bbst.hpp.html
title: "\u9045\u5EF6\u8A55\u4FA1\u3064\u304D\u30FB\u53CD\u8EE2\u53EF\u80FD \u5E73\u8861\
  \u4E8C\u5206\u63A2\u7D22\u6728"
---
