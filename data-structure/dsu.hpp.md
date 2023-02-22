---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/mst.hpp
    title: MST
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/UnionFind.test.cpp
    title: test/Library-Checker/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: disjoint set
    links: []
  bundledCode: "#line 1 \"data-structure/dsu.hpp\"\nclass DSU {\nprivate:\n\tvector<int>\
    \ par, rank, siz;\n\tint N;\npublic:\n\tDSU(int n) : par(n, -1), rank(n, 0), siz(n,\
    \ 1), N(n) {}\n\n\tint root(int x) {\n\t\tif (par[x] == -1)\n\t\t\treturn x;\n\
    \t\telse\n\t\t\treturn par[x] = root(par[x]);\n\t}\n\tbool same(int x, int y)\
    \ {\n\t\treturn root(x) == root(y);\n\t}\n\n\tbool merge(int x, int y) {\n\t\t\
    int rx = root(x), ry = root(y);\n\t\tif (rx == ry)\n\t\t\treturn false;\n\n\t\t\
    if (rank[rx] < rank[ry])\n\t\t\tswap(rx, ry);\n\t\tpar[ry] = rx;\n\n\t\tsiz[rx]\
    \ += siz[ry];\n\t\treturn true;\n\t}\n\n\tint size(int x) {\n\t\treturn siz[root(x)];\n\
    \t}\n\tint group_size() {\n\t\tint cnt = 0;\n\t\tfor (int i = 0; i < N; i++)\n\
    \t\t\tif (root(i) == i)\n\t\t\t\tcnt++;\n\t\treturn cnt;\n\t}\n};\n///@brief disjoint\
    \ set\n"
  code: "class DSU {\nprivate:\n\tvector<int> par, rank, siz;\n\tint N;\npublic:\n\
    \tDSU(int n) : par(n, -1), rank(n, 0), siz(n, 1), N(n) {}\n\n\tint root(int x)\
    \ {\n\t\tif (par[x] == -1)\n\t\t\treturn x;\n\t\telse\n\t\t\treturn par[x] = root(par[x]);\n\
    \t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t}\n\n\tbool\
    \ merge(int x, int y) {\n\t\tint rx = root(x), ry = root(y);\n\t\tif (rx == ry)\n\
    \t\t\treturn false;\n\n\t\tif (rank[rx] < rank[ry])\n\t\t\tswap(rx, ry);\n\t\t\
    par[ry] = rx;\n\n\t\tsiz[rx] += siz[ry];\n\t\treturn true;\n\t}\n\n\tint size(int\
    \ x) {\n\t\treturn siz[root(x)];\n\t}\n\tint group_size() {\n\t\tint cnt = 0;\n\
    \t\tfor (int i = 0; i < N; i++)\n\t\t\tif (root(i) == i)\n\t\t\t\tcnt++;\n\t\t\
    return cnt;\n\t}\n};\n///@brief disjoint set"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dsu.hpp
  requiredBy:
  - graph/mst.hpp
  timestamp: '2023-02-21 08:23:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Library-Checker/UnionFind.test.cpp
documentation_of: data-structure/dsu.hpp
layout: document
redirect_from:
- /library/data-structure/dsu.hpp
- /library/data-structure/dsu.hpp.html
title: disjoint set
---
