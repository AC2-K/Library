---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL/1_A.test.cpp
    title: test/AOJ/DSL/1_A.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/UnionFind.test.cpp
    title: test/yosupo_judge/data_structure/UnionFind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/data-structure/dsu.md
    document_title: Disjoint Set(Union Find)
    links: []
  bundledCode: "#line 2 \"src/data-structure/dsu.hpp\"\n#include <utility>\n#include\
    \ <vector>\nnamespace kyopro {\n\n/**\n * @brief Disjoint Set(Union Find)\n */\n\
    class dsu {\nprivate:\n    std::vector<int> find;\n\npublic:\n    dsu(int n) :\
    \ find(n, -1) {}\n\n    int root(int x) {\n        if (find[x] < 0) {\n      \
    \      return x;\n        } else {\n            return find[x] = root(find[x]);\n\
    \        }\n    }\n    bool same(int x, int y) { return root(x) == root(y); }\n\
    \    int merge(int x, int y) {\n        x = root(x), y = root(y);\n        if\
    \ (x == y) return x;\n        if (find[x] > find[y]) std::swap(x, y);\n      \
    \  find[x] += find[y];\n        find[y] = x;\n        return x;\n    }\n    int\
    \ size(int x) { return -find[root(x)]; }\n};\n\n};  // namespace kyopro\n\n/**\n\
    \ * @docs docs/data-structure/dsu.md\n */\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\nnamespace kyopro {\n\
    \n/**\n * @brief Disjoint Set(Union Find)\n */\nclass dsu {\nprivate:\n    std::vector<int>\
    \ find;\n\npublic:\n    dsu(int n) : find(n, -1) {}\n\n    int root(int x) {\n\
    \        if (find[x] < 0) {\n            return x;\n        } else {\n       \
    \     return find[x] = root(find[x]);\n        }\n    }\n    bool same(int x,\
    \ int y) { return root(x) == root(y); }\n    int merge(int x, int y) {\n     \
    \   x = root(x), y = root(y);\n        if (x == y) return x;\n        if (find[x]\
    \ > find[y]) std::swap(x, y);\n        find[x] += find[y];\n        find[y] =\
    \ x;\n        return x;\n    }\n    int size(int x) { return -find[root(x)]; }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/dsu.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/dsu.hpp
  requiredBy: []
  timestamp: '2023-05-24 09:26:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/DSL/1_A.test.cpp
  - test/yosupo_judge/data_structure/UnionFind.test.cpp
documentation_of: src/data-structure/dsu.hpp
layout: document
redirect_from:
- /library/src/data-structure/dsu.hpp
- /library/src/data-structure/dsu.hpp.html
title: Disjoint Set(Union Find)
---
## 概要

$n$頂点の無向グラフに対して、以下のクエリを**ならし** $O(\alpha(n))$ で処理します。

1. 頂点 $v,u$ の間に無向辺を追加する
1. 頂点 $v,u$ が連結か判定する。

$\alpha$ はアッカーマン関数の逆関数です。

## コンストラクタ

```cpp
kypro::dsu uf(int n)
```

$n$ 頂点 $0$ 辺の無向グラフを生成します。

### 計算量

- $O(n)$

## root

```cpp
int root(int x)
```

頂点 $x$ の属する連結成分の代表元をひとつ返します。

### 制約

- $0 \leq x \lt n$

### 計算量

- ならし $O(\alpha(n))$

## same

```cpp
bool same(int x,int y)
```

頂点 $x,y$ が連結かを判定します。

### 制約

- $0 \leq x,y \lt n$

### 計算量

- ならし $O(\alpha(n))$

## merge

```cpp
int merge(int x,int y)
```

頂点 $x,y$ の間に無向辺を張ります。
また、 $x,y$ の属する連結成分の代表元の番号を返します

### 制約

- $0 \leq x,y \lt n$

### 計算量

- ならし $O(\alpha(n))$

## size

```cpp
int size(int x)
```

頂点 $x$ の属する連結成分の頂点数を求めます

### 制約

- $0 \leq x \lt n$

### 計算量

- ならし $O(\alpha(n))$
