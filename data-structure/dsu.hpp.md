---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/mst.hpp
    title: "Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/1_A.test.cpp
    title: test/AOJ/DSL/1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/2_A.test.cpp
    title: test/AOJ/GRL/2_A.test.cpp
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
  bundledCode: "#line 1 \"data-structure/dsu.hpp\"\n/// @brief Disjoint Set(Union\
    \ find)\n/// @docs docs/data-structure/dsu.md\nclass DSU {\nprivate:\n    vector<int>\
    \ find, rank;\npublic:\n    DSU(int n) : find(n, -1), rank(n, 1) {}\n\n    int\
    \ root(int x) {\n        if (find[x] < 0) {\n            return x;\n        }\n\
    \        else {\n            return find[x] = root(find[x]);\n        }\n    }\n\
    \    bool same(int x, int y) {\n        return root(x) == root(y);\n    }\n\n\
    \    int merge(int x, int y) {\n        x = root(x), y = root(y);\n        if\
    \ (x == y) return x;\n        if (rank[x] < rank[y]) swap(x, y);\n        if (rank[x]\
    \ == rank[y]) rank[x]++; \n        find[x] += find[y];\n        find[y] = x;\n\
    \        return x;\n    }\n\n    int size(int x) {\n        return -find[root(x)];\n\
    \    }\n\n    inline int group_size() {\n        int c = 0;\n        for (int\
    \ v = 0; v < find.size(); v++) {\n            if (find[v] < 0) {\n           \
    \     c++;\n            }\n        }\n        return c;\n    }\n};\n"
  code: "/// @brief Disjoint Set(Union find)\n/// @docs docs/data-structure/dsu.md\n\
    class DSU {\nprivate:\n    vector<int> find, rank;\npublic:\n    DSU(int n) :\
    \ find(n, -1), rank(n, 1) {}\n\n    int root(int x) {\n        if (find[x] < 0)\
    \ {\n            return x;\n        }\n        else {\n            return find[x]\
    \ = root(find[x]);\n        }\n    }\n    bool same(int x, int y) {\n        return\
    \ root(x) == root(y);\n    }\n\n    int merge(int x, int y) {\n        x = root(x),\
    \ y = root(y);\n        if (x == y) return x;\n        if (rank[x] < rank[y])\
    \ swap(x, y);\n        if (rank[x] == rank[y]) rank[x]++; \n        find[x] +=\
    \ find[y];\n        find[y] = x;\n        return x;\n    }\n\n    int size(int\
    \ x) {\n        return -find[root(x)];\n    }\n\n    inline int group_size() {\n\
    \        int c = 0;\n        for (int v = 0; v < find.size(); v++) {\n       \
    \     if (find[v] < 0) {\n                c++;\n            }\n        }\n   \
    \     return c;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dsu.hpp
  requiredBy:
  - graph/mst.hpp
  timestamp: '2023-03-30 16:15:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/1_A.test.cpp
  - test/AOJ/GRL/2_A.test.cpp
  - test/yosupo_judge/data_structure/UnionFind.test.cpp
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
$n$頂点$0$辺の無向グラフを生成します。
- 計算量:$O(n)$

```cpp
int root(int x)
```
頂点$x$の属する連結成分の代表元を返します。
- 計算量:$O(\alpha(n))$

```cpp
bool same(int x,int y)
```
頂点$x,y$が連結かを判定します。
- 計算量:$O(\alpha(n))$
```cpp
int merge(int x,int y)
```
頂点$x,y$の間に無向辺を張ります。また、マージ後の代表元の番号を返します。
- 計算量: $O(\alpha(n))$

```cpp
int size(int x)
```
頂点$x$の属する連結成分の頂点数を求めます。
- 計算量:$O(\alpha(n))$

```cpp
int group_size()
```
連結成分の個数を求めます。
- 計算量:$O(n)$