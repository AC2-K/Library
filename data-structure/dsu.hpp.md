---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/mst.hpp
    title: "Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/1/A.test.cpp
    title: test/AOJ/DSL/1/A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/2/A.test.cpp
    title: test/AOJ/GRL/2/A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/UnionFind.test.cpp
    title: test/yosupo_judge/data_structure/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/dsu.md
    document_title: Disjoint Set(Union find)
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/dsu.hpp: line 4: #pragma once found in a non-first line\n"
  code: "/// @brief Disjoint Set(Union find)\n/// @docs docs/data-structure/dsu.md\n\
    \n#pragma once\nclass DSU {\nprivate:\n\tvector<int> par, rank, siz;\n\tint N;\n\
    public:\n\tDSU(int n) : par(n, -1), rank(n, 0), siz(n, 1), N(n) {}\n\n\tint root(int\
    \ x) {\n\t\tif (par[x] == -1)\n\t\t\treturn x;\n\t\telse\n\t\t\treturn par[x]\
    \ = root(par[x]);\n\t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\
    \t}\n\n\tbool merge(int x, int y) {\n\t\tint rx = root(x), ry = root(y);\n\t\t\
    if (rx == ry)\n\t\t\treturn false;\n\n\t\tif (rank[rx] < rank[ry])\n\t\t\tswap(rx,\
    \ ry);\n\t\tpar[ry] = rx;\n\n\t\tsiz[rx] += siz[ry];\n\t\treturn true;\n\t}\n\n\
    \tint size(int x) {\n\t\treturn siz[root(x)];\n\t}\n\tint group_size() {\n\t\t\
    int cnt = 0;\n\t\tfor (int i = 0; i < N; i++)\n\t\t\tif (root(i) == i)\n\t\t\t\
    \tcnt++;\n\t\treturn cnt;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dsu.hpp
  requiredBy:
  - graph/mst.hpp
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/UnionFind.test.cpp
  - test/AOJ/GRL/2/A.test.cpp
  - test/AOJ/DSL/1/A.test.cpp
documentation_of: data-structure/dsu.hpp
layout: document
redirect_from:
- /library/data-structure/dsu.hpp
- /library/data-structure/dsu.hpp.html
title: Disjoint Set(Union find)
---
## 概要
$n$頂点の無向グラフに対して、以下のクエリを$O(\alpha(n))$で処理します。
1. 頂点$v,u$の間に無向辺を追加する
1. 頂点$v,u$が連結か判定する。

$\alpha$ はアッカーマン関数の逆関数です。
## 使い方
```cpp
DSU dsu(int n)
```
$n$頂点$0$辺の無向グラフを生成します。計算量は$O(n)$

```cpp
int root(int x)
```
頂点$x$の属する連結成分の代表元を返します。計算量は$O(\alpha(n))$

```cpp
bool same(int x,int y)
```
頂点$x,y$が連結かを判定します。計算量は$O(\alpha(n))$
```cpp
bool merge(int x,int y)
```
頂点$x,y$の間に無向辺を張ります。ただし、すでに無向辺が張られていた場合は`false`を返して終了します。計算量は$O(\alpha(n))$

```cpp
int size(int x)
```
頂点$x$の属する連結成分の頂点数を求めます。計算量は$O(\alpha(n))$

```cpp
int group_size()
```
連結成分の個数を求めます。計算量は$O(\alpha(n))$