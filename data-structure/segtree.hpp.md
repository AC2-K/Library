---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2/B.test.cpp
    title: test/AOJ/DSL/2/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
    title: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
    title: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Static Range Sum.test.cpp
    title: test/yosupo judge/data structure/Static Range Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
    title: test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
    title: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
    title: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segtree.hpp\"\ntemplate<class S, S(*op)(S,\
    \ S), S(*e)()>\nclass segtree {\n\tint lg, sz, n;\n\tvector<S> dat;\n\npublic:\n\
    \tsegtree() :segtree(0) {}\n\tsegtree(int n) : segtree(vector<S>(n, e())) {}\n\
    \tsegtree(const vector<S>& vec) : n((int)vec.size()) {\n\t\tsz = 1, lg = 0;\n\t\
    \twhile (sz <= n) {\n\t\t\tsz <<= 1;\n\t\t\tlg++;\n\t\t}\n\n\t\tdat = vector<S>(sz\
    \ << 1, e());\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tset(i, vec[i]);\n\t\t\
    }\n\t\tbuild();\n\t}\n\n\tinline void set(const int p, const S& v) {\n\t\tdat[sz\
    \ + p] = v;\n\t}\n\tinline void build() {\n\t\tfor (int i = sz - 1; i > 0; i--)\
    \ {\n\t\t\tdat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n\t\t}\n\t}\n\tS operator[](const\
    \ int p) const { return dat[sz + p]; }\n\n\tinline void update(int p, const S&\
    \ v) {\n\t\tp += sz;\n\t\tdat[p] = v;\n\t\twhile (p >>= 1) {\n\t\t\tdat[p] = op(dat[(p\
    \ << 1)], dat[(p << 1) ^ 1]);\n\t\t}\n\t}\n\n\tinline S prod(int l, int r) const\
    \ {\n\t\tl += sz, r += sz;\n\t\tS sml = e(), smr = e();\n\t\twhile (l != r) {\n\
    \t\t\tif (l & 1)sml = op(sml, dat[l++]);\n\t\t\tif (r & 1)smr = op(dat[--r], smr);\n\
    \t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\tinline void apply(int\
    \ p, const S& v) {\n\t\tupdate(p, op(dat[sz + p], v));\n\t}\n};\n"
  code: "template<class S, S(*op)(S, S), S(*e)()>\nclass segtree {\n\tint lg, sz,\
    \ n;\n\tvector<S> dat;\n\npublic:\n\tsegtree() :segtree(0) {}\n\tsegtree(int n)\
    \ : segtree(vector<S>(n, e())) {}\n\tsegtree(const vector<S>& vec) : n((int)vec.size())\
    \ {\n\t\tsz = 1, lg = 0;\n\t\twhile (sz <= n) {\n\t\t\tsz <<= 1;\n\t\t\tlg++;\n\
    \t\t}\n\n\t\tdat = vector<S>(sz << 1, e());\n\n\t\tfor (int i = 0; i < n; i++)\
    \ {\n\t\t\tset(i, vec[i]);\n\t\t}\n\t\tbuild();\n\t}\n\n\tinline void set(const\
    \ int p, const S& v) {\n\t\tdat[sz + p] = v;\n\t}\n\tinline void build() {\n\t\
    \tfor (int i = sz - 1; i > 0; i--) {\n\t\t\tdat[i] = op(dat[i << 1], dat[(i <<\
    \ 1) ^ 1]);\n\t\t}\n\t}\n\tS operator[](const int p) const { return dat[sz + p];\
    \ }\n\n\tinline void update(int p, const S& v) {\n\t\tp += sz;\n\t\tdat[p] = v;\n\
    \t\twhile (p >>= 1) {\n\t\t\tdat[p] = op(dat[(p << 1)], dat[(p << 1) ^ 1]);\n\t\
    \t}\n\t}\n\n\tinline S prod(int l, int r) const {\n\t\tl += sz, r += sz;\n\t\t\
    S sml = e(), smr = e();\n\t\twhile (l != r) {\n\t\t\tif (l & 1)sml = op(sml, dat[l++]);\n\
    \t\t\tif (r & 1)smr = op(dat[--r], smr);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\t\
    return op(sml, smr);\n\t}\n\tinline void apply(int p, const S& v) {\n\t\tupdate(p,\
    \ op(dat[sz + p], v));\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree.hpp
  requiredBy:
  - main.cpp
  timestamp: '2023-03-25 19:44:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo judge/data structure/Static Range Sum.test.cpp
  - test/yosupo judge/data structure/Point Set Range Composite.test.cpp
  - test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
  - test/yosupo judge/data structure/Point Add Range Sum.test.cpp
  - test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
  - test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
  - test/AOJ/DSL/2/B.test.cpp
documentation_of: data-structure/segtree.hpp
layout: document
redirect_from:
- /library/data-structure/segtree.hpp
- /library/data-structure/segtree.hpp.html
title: data-structure/segtree.hpp
---
