---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data-structure/dynamic_segtree.md
    document_title: "Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728)"
    links: []
  bundledCode: "#line 2 \"src/data-structure/dynamic_segtree.hpp\"\n#include <cassert>\n\
    namespace kyopro {\n/// @brief Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728)\ntemplate <class S, S (*op)(S, S), S (*e)()>\nclass dynamic_segtree\
    \ {\npublic:\n    dynamic_segtree(size_t n = 0) : n(n), root(nullptr) {}\n\nprivate:\n\
    \    struct node {\n        S val;\n        node* left;\n        node* right;\n\
    \n        node(const S& v) : val(v), left(nullptr), right(nullptr) {}\n    };\n\
    \    node* root;\n    size_t n;\n\npublic:\n    void update(const size_t& p, const\
    \ S& x) {\n        assert(0 <= p && p < n);\n        internal_update(root, 0,\
    \ n, p, x);\n    }\n    void add(const size_t& p, const S& x) {\n        assert(0\
    \ <= p && p < n);\n        internal_add(root, 0, n, p, x);\n    }\n    S operator[](const\
    \ size_t& p) {\n        assert(0 <= p && p < n);\n        return internal_access(root,\
    \ 0, n, p);\n    }\n    S prod(const size_t& l, const size_t& r) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        if (l == r) {\n            return e();\n\
    \        }\n\n        return internal_prod(root, 0, n, l, r);\n    }\n\nprivate:\n\
    \    void internal_update(node*& p,\n                         size_t l,\n    \
    \                     size_t r,\n                         size_t idx,\n      \
    \                   const S& new_val) {\n        if (p == nullptr) {\n       \
    \     p = new node(e());\n        }\n\n        if (r - l == 1) {\n           \
    \ p->val = new_val;\n            return;\n        }\n\n        size_t mid = (l\
    \ + r) >> 1;\n        if (idx < mid)\n            internal_update(p->left, l,\
    \ mid, idx, new_val);\n        else\n            internal_update(p->right, mid,\
    \ r, idx, new_val);\n        p->val = e();\n        if (p->left != nullptr) p->val\
    \ = op(p->left->val, p->val);\n        if (p->right != nullptr) p->val = op(p->val,\
    \ p->right->val);\n    }\n    void internal_add(node*& p,\n                  \
    \    size_t l,\n                      size_t r,\n                      size_t\
    \ idx,\n                      const S& new_val) {\n        if (p == nullptr) {\n\
    \            p = new node(e());\n        }\n\n        if (r - l == 1) {\n    \
    \        p->val = op(p->val, new_val);\n            return;\n        }\n\n   \
    \     size_t mid = (l + r) >> 1;\n        if (idx < mid)\n            internal_add(p->left,\
    \ l, mid, idx, new_val);\n        else\n            internal_add(p->right, mid,\
    \ r, idx, new_val);\n        p->val = e();\n        if (p->left != nullptr) p->val\
    \ = op(p->left->val, p->val);\n        if (p->right != nullptr) p->val = op(p->val,\
    \ p->right->val);\n    }\n\n    S internal_access(node*& p, size_t l, size_t r,\
    \ size_t idx) {\n        if (p == nullptr) {\n            return e();\n      \
    \  }\n        if (r - l == 1) {\n            return p->val;\n        }\n\n   \
    \     size_t mid = (l + r) >> 1;\n        if (idx < mid)\n            return internal_access(p->left,\
    \ l, mid, idx);\n        else\n            return internal_access(p->right, mid,\
    \ r, idx);\n    }\n\n    S internal_prod(node*& p, size_t l, size_t r, size_t\
    \ L, size_t R) {\n        if (p == nullptr || r <= L || R <= l) {\n          \
    \  return e();\n        }\n        if (L <= l && r <= R) {\n            return\
    \ p->val;\n        }\n\n        size_t mid = (l + r) >> 1;\n        return op(internal_prod(p->left,\
    \ l, mid, L, R),\n                  internal_prod(p->right, mid, r, L, R));\n\
    \    }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/dynamic_segtree.md\n"
  code: "#pragma once\n#include <cassert>\nnamespace kyopro {\n/// @brief Dynamic\
    \ Segment Tree(\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()>\nclass dynamic_segtree {\npublic:\n    dynamic_segtree(size_t\
    \ n = 0) : n(n), root(nullptr) {}\n\nprivate:\n    struct node {\n        S val;\n\
    \        node* left;\n        node* right;\n\n        node(const S& v) : val(v),\
    \ left(nullptr), right(nullptr) {}\n    };\n    node* root;\n    size_t n;\n\n\
    public:\n    void update(const size_t& p, const S& x) {\n        assert(0 <= p\
    \ && p < n);\n        internal_update(root, 0, n, p, x);\n    }\n    void add(const\
    \ size_t& p, const S& x) {\n        assert(0 <= p && p < n);\n        internal_add(root,\
    \ 0, n, p, x);\n    }\n    S operator[](const size_t& p) {\n        assert(0 <=\
    \ p && p < n);\n        return internal_access(root, 0, n, p);\n    }\n    S prod(const\
    \ size_t& l, const size_t& r) {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if (l == r) {\n            return e();\n        }\n\n        return internal_prod(root,\
    \ 0, n, l, r);\n    }\n\nprivate:\n    void internal_update(node*& p,\n      \
    \                   size_t l,\n                         size_t r,\n          \
    \               size_t idx,\n                         const S& new_val) {\n  \
    \      if (p == nullptr) {\n            p = new node(e());\n        }\n\n    \
    \    if (r - l == 1) {\n            p->val = new_val;\n            return;\n \
    \       }\n\n        size_t mid = (l + r) >> 1;\n        if (idx < mid)\n    \
    \        internal_update(p->left, l, mid, idx, new_val);\n        else\n     \
    \       internal_update(p->right, mid, r, idx, new_val);\n        p->val = e();\n\
    \        if (p->left != nullptr) p->val = op(p->left->val, p->val);\n        if\
    \ (p->right != nullptr) p->val = op(p->val, p->right->val);\n    }\n    void internal_add(node*&\
    \ p,\n                      size_t l,\n                      size_t r,\n     \
    \                 size_t idx,\n                      const S& new_val) {\n   \
    \     if (p == nullptr) {\n            p = new node(e());\n        }\n\n     \
    \   if (r - l == 1) {\n            p->val = op(p->val, new_val);\n           \
    \ return;\n        }\n\n        size_t mid = (l + r) >> 1;\n        if (idx <\
    \ mid)\n            internal_add(p->left, l, mid, idx, new_val);\n        else\n\
    \            internal_add(p->right, mid, r, idx, new_val);\n        p->val = e();\n\
    \        if (p->left != nullptr) p->val = op(p->left->val, p->val);\n        if\
    \ (p->right != nullptr) p->val = op(p->val, p->right->val);\n    }\n\n    S internal_access(node*&\
    \ p, size_t l, size_t r, size_t idx) {\n        if (p == nullptr) {\n        \
    \    return e();\n        }\n        if (r - l == 1) {\n            return p->val;\n\
    \        }\n\n        size_t mid = (l + r) >> 1;\n        if (idx < mid)\n   \
    \         return internal_access(p->left, l, mid, idx);\n        else\n      \
    \      return internal_access(p->right, mid, r, idx);\n    }\n\n    S internal_prod(node*&\
    \ p, size_t l, size_t r, size_t L, size_t R) {\n        if (p == nullptr || r\
    \ <= L || R <= l) {\n            return e();\n        }\n        if (L <= l &&\
    \ r <= R) {\n            return p->val;\n        }\n\n        size_t mid = (l\
    \ + r) >> 1;\n        return op(internal_prod(p->left, l, mid, L, R),\n      \
    \            internal_prod(p->right, mid, r, L, R));\n    }\n};\n};  // namespace\
    \ kyopro\n\n/// @docs docs/data-structure/dynamic_segtree.md"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2023-04-23 12:26:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/dynamic_segtree.hpp
- /library/src/data-structure/dynamic_segtree.hpp.html
title: "Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
## 概要
普通のセグメント木では、以下のような処理をするのが難しい。

> 問題:\
> モノイド $(S,\cdot,e)$ の列 $a=(a_1,a_2,\dots,a_{10^9}) $ について
>    - $i$ と $x\in S$ が与えられたとき $a_i\leftarrow x$
>    - 区間 $[l,r)$ が与えられたとき 区間積を計算
>
> ただし、 $a$ は最初 $e$ で埋められているとする。

オンラインで処理するとなると、TLE,MLEしてしまう...と思う。\
なので、クエリに出てくる添え字を座標圧縮し、オフラインで答えることになる。
\
\
ただ、このDynamic Segtreeを使えば**オンラインで**処理できる!!!
メモリをいじるので、普通のセグ木よりけっこう遅い...