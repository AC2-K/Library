---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/AOJ/DSL/2/D2.cpp
    title: test/AOJ/DSL/2/D2.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2/E2.test.cpp
    title: test/AOJ/DSL/2/E2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/dual_segtree.md
    document_title: "dual segtree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
    links: []
  bundledCode: "#line 1 \"data-structure/dual_segtree.hpp\"\ntemplate<class F, F(*comp)(F,\
    \ F), F(*id)()>\nclass dual_segtree {\n\tint n;\t\n\n\tint sz;\n\n\tconst int\
    \ lowest = -1;\n\tvector<pair<int, F>> dat;\n\n\n\tint cur;\npublic:\n\tdual_segtree(const\
    \ int& n_) :n(n_), cur(0) {\n\t\tsz = 1;\n\t\twhile (sz < n) {\n\t\t\tsz <<= 1;\n\
    \t\t}\n\n\t\tdat.assign(sz << 1 , make_pair(lowest, id()));\n\t}\n\nprivate:\n\
    \tvoid innner_apply(const int& p, const int& l, const int& r, const int& L, const\
    \  int& R, const  F& f) {\n\t\tif (r <= L || R <= l) {\n\t\t\treturn;\n\t\t}\n\
    \t\tif (L <= l && r <= R) {\n\t\t\tF nf = comp(dat[p].second, f);\n\t\t\tdat[p]\
    \ = make_pair(cur, nf);\n\t\t\treturn;\n\t\t}\n\t\telse {\n\t\t\tint md = (l +\
    \ r) >> 1;\n\t\t\tinnner_apply(2 * p + 1, l, md, L, R, f);\n\t\t\tinnner_apply(2\
    \ * p + 2, md, r, L, R, f);\n\t\t}\n\t}\npublic:\n\tvoid apply(const int& l, const\
    \ int& r, const F& x) {\n\t\t//assert(0 <= l && l <= r && r <= n);\n\t\tinnner_apply(0,\
    \ 0, sz, l, r, x);\n\t\tcur++;\n\t}\n\n\tF operator[](int p) {\n\t\tp = p + sz\
    \ - 1;\t//1-index\n\n\t\tvector<pair<int, F>> path;\n\t\tpath.emplace_back(dat[p]);\n\
    \t\twhile (p) {\n\t\t\tp = (p - 1) >> 1;\n\t\t\tpath.emplace_back(dat[p]);\n\t\
    \t};\n\n\n\t\tsort(path.begin(), path.end());\n\n\t\tF res = id();\n\t\tfor (const\
    \ auto& q : path) {\n\t\t\tif (q.first == lowest || q.second == id()) {\n\t\t\t\
    \tcontinue;\n\t\t\t}\n\t\t\tres = comp(res, q.second);\n\t\t}\n\n\t\treturn res;\n\
    \t}\n    //debug\n\tvoid print() {\n\t\tcout << \"[\";\n\t\tfor (int i = 0; i\
    \ < n; i++) {\n\t\t\tcout << (*this)[i] << ' ';\n\t\t}\n\t\tcout << \"]\\n\";\n\
    \t}\n};\n\n///@brief dual segtree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\n///@docs docs/data-structure/dual_segtree.md\n"
  code: "template<class F, F(*comp)(F, F), F(*id)()>\nclass dual_segtree {\n\tint\
    \ n;\t\n\n\tint sz;\n\n\tconst int lowest = -1;\n\tvector<pair<int, F>> dat;\n\
    \n\n\tint cur;\npublic:\n\tdual_segtree(const int& n_) :n(n_), cur(0) {\n\t\t\
    sz = 1;\n\t\twhile (sz < n) {\n\t\t\tsz <<= 1;\n\t\t}\n\n\t\tdat.assign(sz <<\
    \ 1 , make_pair(lowest, id()));\n\t}\n\nprivate:\n\tvoid innner_apply(const int&\
    \ p, const int& l, const int& r, const int& L, const  int& R, const  F& f) {\n\
    \t\tif (r <= L || R <= l) {\n\t\t\treturn;\n\t\t}\n\t\tif (L <= l && r <= R) {\n\
    \t\t\tF nf = comp(dat[p].second, f);\n\t\t\tdat[p] = make_pair(cur, nf);\n\t\t\
    \treturn;\n\t\t}\n\t\telse {\n\t\t\tint md = (l + r) >> 1;\n\t\t\tinnner_apply(2\
    \ * p + 1, l, md, L, R, f);\n\t\t\tinnner_apply(2 * p + 2, md, r, L, R, f);\n\t\
    \t}\n\t}\npublic:\n\tvoid apply(const int& l, const int& r, const F& x) {\n\t\t\
    //assert(0 <= l && l <= r && r <= n);\n\t\tinnner_apply(0, 0, sz, l, r, x);\n\t\
    \tcur++;\n\t}\n\n\tF operator[](int p) {\n\t\tp = p + sz - 1;\t//1-index\n\n\t\
    \tvector<pair<int, F>> path;\n\t\tpath.emplace_back(dat[p]);\n\t\twhile (p) {\n\
    \t\t\tp = (p - 1) >> 1;\n\t\t\tpath.emplace_back(dat[p]);\n\t\t};\n\n\n\t\tsort(path.begin(),\
    \ path.end());\n\n\t\tF res = id();\n\t\tfor (const auto& q : path) {\n\t\t\t\
    if (q.first == lowest || q.second == id()) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\
    \tres = comp(res, q.second);\n\t\t}\n\n\t\treturn res;\n\t}\n    //debug\n\tvoid\
    \ print() {\n\t\tcout << \"[\";\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tcout\
    \ << (*this)[i] << ' ';\n\t\t}\n\t\tcout << \"]\\n\";\n\t}\n};\n\n///@brief dual\
    \ segtree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n///@docs docs/data-structure/dual_segtree.md"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dual_segtree.hpp
  requiredBy:
  - test/AOJ/DSL/2/D2.cpp
  timestamp: '2023-03-12 14:55:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/2/E2.test.cpp
documentation_of: data-structure/dual_segtree.hpp
layout: document
redirect_from:
- /library/data-structure/dual_segtree.hpp
- /library/data-structure/dual_segtree.hpp.html
title: "dual segtree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
# Dual SegmentTree(双対セグメント木)

$(F,\circ,\text{id})$ がモノイドをなすとする。\
この時、 $F$ 上の列 $a=(a_1,a_2\dots,a_n)$について、以下のクエリを高速に処理する。
- $v\in F$ と区間 $[l,r)$ が与えられる。 $i\in [l,r)$ なる全ての $i$ に対して $a_i\leftarrow a_i\circ x$ と更新する。

- $i$ が与えられたとき、 $a_i$ を求める。
