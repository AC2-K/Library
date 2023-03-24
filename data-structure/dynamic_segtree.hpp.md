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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/dynamic_segtree.hpp: line 7: #pragma once found in a non-first\
    \ line\n"
  code: "/// @brief Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728)\n/// @tparam S \u8981\u7D20\u306E\u578B\n/// @tparam op \u4E8C\u9805\u6F14\
    \u7B97\n/// @tparam e \u5358\u4F4D\u5143\n/// @docs docs/data-structure/dynamic_segtree.md\n\
    \n#pragma once\ntemplate<class S,S(*op)(S,S),S(*e)()>\nclass dynamic_segtree {\n\
    public:\n\tdynamic_segtree(const size_t& n) :n(n), root(nullptr) {}\nprivate:\n\
    \tstruct node {\n\t\tS val;\n\t\tnode* left;\n\t\tnode* right;\n\n\t\tnode(const\
    \ S& v) :val(v), left(nullptr), right(nullptr) {}\n\t};\n\tnode* root;\n\tsize_t\
    \ n;\npublic:\n\tvoid update(const size_t& p, const S& x) { \n\t\tassert(0 <=\
    \ p && p < n);\n\t\tinternal_update(root, 0, n, p, x); \n\t}\n\tvoid add(const\
    \ size_t& p, const S& x) { \n\t\tassert(0 <= p && p < n);\n\t\tinternal_add(root,\
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
    \ internal_prod(p->right, mid, r, L, R));\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic_segtree.hpp
- /library/data-structure/dynamic_segtree.hpp.html
title: "Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
普通のセグメント木と同じなので省きます