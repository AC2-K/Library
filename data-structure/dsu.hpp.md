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
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/UnionFind.test.cpp
    title: test/yosupo_judge/data_structure/UnionFind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \n#pragma once\nclass DSU {\nprivate:\n    vector<int> find;\npublic:\n    DSU(int\
    \ n) : find(n, -1) {    }\n\n    int root(int x) {\n        if (find[x] < 0) {\n\
    \            return x;\n        }\n        else {\n            return find[x]\
    \ = root(find[x]);\n        }\n    }\n    bool same(int x, int y) {\n        return\
    \ root(x) == root(y);\n    }\n\n    bool merge(int x, int y) {\n        int rx\
    \ = root(x), ry = root(y);\n        if (rx == ry)\n            return false;\n\
    \n        if (find[rx] >= find[ry]) {\n            swap(rx, ry);\n        }\n\
    \        find[rx] += find[ry];\n        find[ry] = rx;\n        return true;\n\
    \    }\n\n    int size(int x) {\n        return -find[root(x)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dsu.hpp
  requiredBy:
  - graph/mst.hpp
  timestamp: '2023-03-28 10:54:47+09:00'
  verificationStatus: LIBRARY_SOME_WA
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