---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki/No789.test.cpp
    title: test/yuki/No789.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/dynamic_segtree.md
    document_title: "dynamic_segtree(\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
    links: []
  bundledCode: "#line 1 \"data-structure/dynamic_segtree.hpp\"\ntemplate<class S,S(*op)(S,S),S(*e)()>\n\
    class dynamic_segtree {\npublic:\n\tdynamic_segtree(const size_t& n) :n(n), root(nullptr)\
    \ {}\nprivate:\n\tstruct node {\n\t\tS val;\n\t\tnode* left;\n\t\tnode* right;\n\
    \n\t\tnode(const S& v) :val(v), left(nullptr), right(nullptr) {}\n\t};\n\tnode*\
    \ root;\n\tsize_t n;\npublic:\n\tvoid update(const size_t& p, const S& x) { \n\
    \t\tassert(0 <= p && p < n);\n\t\tinternal_update(root, 0, n, p, x); \n\t}\n\t\
    void add(const size_t& p, const S& x) { \n\t\tassert(0 <= p && p < n);\n\t\tinternal_add(root,\
    \ 0, n, p, x); \n\t}\n\tS operator[](const size_t& p) { \n\t\tassert(0 <= p &&\
    \ p < n);\n\t\treturn internal_access(root, 0, n, p); \n\t}\n\tS prod(const size_t&\
    \ l, const size_t& r) {\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\tif (l ==\
    \ r) {\n\t\t\treturn e();\n\t\t}\n\n\t\treturn internal_prod(root, 0, n, l, r);\n\
    \t}\n\nprivate:\n\tvoid internal_update(node*& p, const size_t& l, const size_t&\
    \ r, const  size_t& idx, const S& new_val) {\n\t\tif (p == nullptr) {\n\t\t\t\
    p = new node(e());\n\t\t}\n\n\t\tif (r - l == 1) {\n\t\t\tp->val = new_val;\n\t\
    \t\treturn;\n\t\t}\n\n\t\tsize_t mid = (l + r) >> 1;\n\t\tif (idx < mid) internal_update(p->left,\
    \ l, mid, idx, new_val);\n\t\telse internal_update(p->right, mid, r, idx, new_val);\n\
    \t\tp->val = e();\n\t\tif (p->left!=nullptr) p->val = op(p->left->val, p->val);\n\
    \t\tif (p->right!=nullptr) p->val = op(p->val, p->right->val);\n\t}\n\tvoid internal_add(node*&\
    \ p, const size_t& l, const size_t& r, const  size_t& idx, const S& new_val) {\n\
    \t\tif (p == nullptr) {\n\t\t\tp = new node(e());\n\t\t}\n\n\t\tif (r - l == 1)\
    \ {\n\t\t\tp->val = op(p->val, new_val);;\n\t\t\treturn;\n\t\t}\n\n\t\tsize_t\
    \ mid = (l + r) >> 1;\n\t\tif (idx < mid) internal_add(p->left, l, mid, idx, new_val);\n\
    \t\telse internal_add(p->right, mid, r, idx, new_val);\n\t\tp->val = e();\n\t\t\
    if (p->left!=nullptr) p->val = op(p->left->val, p->val);\n\t\tif (p->right!=nullptr)\
    \ p->val = op(p->val, p->right->val);\n\t}\n\n\n\tS internal_access(node*& p,\
    \ const size_t& l, const size_t& r, const  size_t& idx) {\n\t\tif (p == nullptr)\
    \ {\n\t\t\treturn e();\n\t\t}\n\t\tif (r - l == 1) {\n\t\t\treturn p->val;\n\t\
    \t}\n\n\t\tsize_t mid = (l + r) >> 1;\n\t\tif (idx < mid) return internal_access(p->left,\
    \ l, mid, idx);\n\t\telse return internal_access(p->right, mid, r, idx);\n\t}\n\
    \n\tS internal_prod(node*& p, const size_t& l, const size_t& r, const size_t&\
    \ L, const size_t& R) {\n\t\tif (p == nullptr || r <= L || R <= l) {\n\t\t\treturn\
    \ e();\n\t\t}\n\t\tif (L <= l && r <= R) {\n\t\t\treturn p->val;\n\t\t}\n\n\t\t\
    size_t mid = (l + r) >> 1;\n\t\treturn op(internal_prod(p->left, l, mid, L, R),\
    \ internal_prod(p->right, mid, r, L, R));\n\t}\n};\n\n\n///@brief  dynamic_segtree(\u52D5\
    \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n///@docs docs/data-structure/dynamic_segtree.md\n"
  code: "template<class S,S(*op)(S,S),S(*e)()>\nclass dynamic_segtree {\npublic:\n\
    \tdynamic_segtree(const size_t& n) :n(n), root(nullptr) {}\nprivate:\n\tstruct\
    \ node {\n\t\tS val;\n\t\tnode* left;\n\t\tnode* right;\n\n\t\tnode(const S& v)\
    \ :val(v), left(nullptr), right(nullptr) {}\n\t};\n\tnode* root;\n\tsize_t n;\n\
    public:\n\tvoid update(const size_t& p, const S& x) { \n\t\tassert(0 <= p && p\
    \ < n);\n\t\tinternal_update(root, 0, n, p, x); \n\t}\n\tvoid add(const size_t&\
    \ p, const S& x) { \n\t\tassert(0 <= p && p < n);\n\t\tinternal_add(root, 0, n,\
    \ p, x); \n\t}\n\tS operator[](const size_t& p) { \n\t\tassert(0 <= p && p < n);\n\
    \t\treturn internal_access(root, 0, n, p); \n\t}\n\tS prod(const size_t& l, const\
    \ size_t& r) {\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\tif (l == r) {\n\t\
    \t\treturn e();\n\t\t}\n\n\t\treturn internal_prod(root, 0, n, l, r);\n\t}\n\n\
    private:\n\tvoid internal_update(node*& p, const size_t& l, const size_t& r, const\
    \  size_t& idx, const S& new_val) {\n\t\tif (p == nullptr) {\n\t\t\tp = new node(e());\n\
    \t\t}\n\n\t\tif (r - l == 1) {\n\t\t\tp->val = new_val;\n\t\t\treturn;\n\t\t}\n\
    \n\t\tsize_t mid = (l + r) >> 1;\n\t\tif (idx < mid) internal_update(p->left,\
    \ l, mid, idx, new_val);\n\t\telse internal_update(p->right, mid, r, idx, new_val);\n\
    \t\tp->val = e();\n\t\tif (p->left!=nullptr) p->val = op(p->left->val, p->val);\n\
    \t\tif (p->right!=nullptr) p->val = op(p->val, p->right->val);\n\t}\n\tvoid internal_add(node*&\
    \ p, const size_t& l, const size_t& r, const  size_t& idx, const S& new_val) {\n\
    \t\tif (p == nullptr) {\n\t\t\tp = new node(e());\n\t\t}\n\n\t\tif (r - l == 1)\
    \ {\n\t\t\tp->val = op(p->val, new_val);;\n\t\t\treturn;\n\t\t}\n\n\t\tsize_t\
    \ mid = (l + r) >> 1;\n\t\tif (idx < mid) internal_add(p->left, l, mid, idx, new_val);\n\
    \t\telse internal_add(p->right, mid, r, idx, new_val);\n\t\tp->val = e();\n\t\t\
    if (p->left!=nullptr) p->val = op(p->left->val, p->val);\n\t\tif (p->right!=nullptr)\
    \ p->val = op(p->val, p->right->val);\n\t}\n\n\n\tS internal_access(node*& p,\
    \ const size_t& l, const size_t& r, const  size_t& idx) {\n\t\tif (p == nullptr)\
    \ {\n\t\t\treturn e();\n\t\t}\n\t\tif (r - l == 1) {\n\t\t\treturn p->val;\n\t\
    \t}\n\n\t\tsize_t mid = (l + r) >> 1;\n\t\tif (idx < mid) return internal_access(p->left,\
    \ l, mid, idx);\n\t\telse return internal_access(p->right, mid, r, idx);\n\t}\n\
    \n\tS internal_prod(node*& p, const size_t& l, const size_t& r, const size_t&\
    \ L, const size_t& R) {\n\t\tif (p == nullptr || r <= L || R <= l) {\n\t\t\treturn\
    \ e();\n\t\t}\n\t\tif (L <= l && r <= R) {\n\t\t\treturn p->val;\n\t\t}\n\n\t\t\
    size_t mid = (l + r) >> 1;\n\t\treturn op(internal_prod(p->left, l, mid, L, R),\
    \ internal_prod(p->right, mid, r, L, R));\n\t}\n};\n\n\n///@brief  dynamic_segtree(\u52D5\
    \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n///@docs docs/data-structure/dynamic_segtree.md"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2023-03-06 17:56:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/No789.test.cpp
documentation_of: data-structure/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic_segtree.hpp
- /library/data-structure/dynamic_segtree.hpp.html
title: "dynamic_segtree(\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
## 概要
普通のセグメント木では、以下のような処理をするのが難しい。

> 問題:\
> モノイド $(S,\cdot,e)$ の列 $a=(a_1,a_2,\dots,a_{10^9}) $ について
>    - $i$ と $x\in X$ が与えられたとき $a_i\leftarrow x$
>    - 区間 $[l,r)$ が与えられたとき 区間積を計算
>
> ただし、 $a$ は最初 $e$ で埋められているとする。

オンラインで処理するとなると、TLE,MLEしてしまう...と思う。\
なので、クエリに出てくる添え字を座標圧縮し、オフラインで答えることになる。
\
\
ただ、このDynamic Segtreeを使えば**オンラインで**処理できる!!!
\
普通のセグメント木に比べてメモリ消費は少ないが、若干重い。
## 使い方
普通のセグメント木と同じ。

### コンストラクタ