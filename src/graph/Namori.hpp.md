---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/Namori.md
    document_title: "\u306A\u3082\u308A\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "#line 2 \"src/graph/Namori.hpp\"\n#include <queue>\n#include <vector>\n\
    namespace kyopro {\nclass Namori {\n    int n;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> root_idx;\n    std::vector<int> deg;\n    std::vector<bool>\
    \ is_cycle;\n\npublic:\n    Namori(int n) : n(n), g(n), deg(n), is_cycle(n, true),\
    \ root_idx(n, -1) {}\n\n    void add_edge(int s, int t) {\n        g[s].emplace_back(t),\
    \ g[t].emplace_back(s);\n        ++deg[s], ++deg[t];\n    }\n\n    void build()\
    \ {\n        {\n            std::queue<int> q;\n            for (int v = 0; v\
    \ < n; ++v) {\n                if (deg[v] == 1) {\n                    q.emplace(v);\n\
    \                }\n            }\n            while (!q.empty()) {\n        \
    \        int v = q.front();\n                q.pop();\n                is_cycle[v]\
    \ = false;\n\n                for (auto nv : g[v]) {\n                    if (deg[nv]\
    \ < 2) continue;\n                    deg[nv]--;\n                    if (deg[nv]\
    \ == 1) q.emplace(nv);\n                }\n            }\n        }\n\n      \
    \  {\n            for (int i = 0; i < n; ++i) {\n                if (!is_cycle[i])\
    \ continue;\n\n                root_idx[i] = i;\n\n                std::vector<std::pair<int,\
    \ int>> st;\n                st.reserve(n);\n                for (auto ch : g[i])\
    \ {\n                    if (is_cycle[ch]) continue;\n                    st.emplace_back(ch,\
    \ i);\n                }\n\n                while (!st.empty()) {\n          \
    \          auto [v, p] = st.back();\n                    st.pop_back();\n\n  \
    \                  root_idx[v] = root_idx[p];\n\n                    for (auto\
    \ to : g[v]) {\n                        if (to != p) {\n                     \
    \       st.emplace_back(to, v);\n                        }\n                 \
    \   }\n                }\n            }\n        }\n    }\n\n    int root(int\
    \ v) const { return root_idx[v]; }\n    bool is_in_cycle(int v) const { return\
    \ is_cycle[v]; }\n};\n};  // namespace kyopro\n\n/**\n * @brief \u306A\u3082\u308A\
    \u30B0\u30E9\u30D5\n * @docs docs/graph/Namori.md\n */\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\nnamespace kyopro {\nclass\
    \ Namori {\n    int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int>\
    \ root_idx;\n    std::vector<int> deg;\n    std::vector<bool> is_cycle;\n\npublic:\n\
    \    Namori(int n) : n(n), g(n), deg(n), is_cycle(n, true), root_idx(n, -1) {}\n\
    \n    void add_edge(int s, int t) {\n        g[s].emplace_back(t), g[t].emplace_back(s);\n\
    \        ++deg[s], ++deg[t];\n    }\n\n    void build() {\n        {\n       \
    \     std::queue<int> q;\n            for (int v = 0; v < n; ++v) {\n        \
    \        if (deg[v] == 1) {\n                    q.emplace(v);\n             \
    \   }\n            }\n            while (!q.empty()) {\n                int v\
    \ = q.front();\n                q.pop();\n                is_cycle[v] = false;\n\
    \n                for (auto nv : g[v]) {\n                    if (deg[nv] < 2)\
    \ continue;\n                    deg[nv]--;\n                    if (deg[nv] ==\
    \ 1) q.emplace(nv);\n                }\n            }\n        }\n\n        {\n\
    \            for (int i = 0; i < n; ++i) {\n                if (!is_cycle[i])\
    \ continue;\n\n                root_idx[i] = i;\n\n                std::vector<std::pair<int,\
    \ int>> st;\n                st.reserve(n);\n                for (auto ch : g[i])\
    \ {\n                    if (is_cycle[ch]) continue;\n                    st.emplace_back(ch,\
    \ i);\n                }\n\n                while (!st.empty()) {\n          \
    \          auto [v, p] = st.back();\n                    st.pop_back();\n\n  \
    \                  root_idx[v] = root_idx[p];\n\n                    for (auto\
    \ to : g[v]) {\n                        if (to != p) {\n                     \
    \       st.emplace_back(to, v);\n                        }\n                 \
    \   }\n                }\n            }\n        }\n    }\n\n    int root(int\
    \ v) const { return root_idx[v]; }\n    bool is_in_cycle(int v) const { return\
    \ is_cycle[v]; }\n};\n};  // namespace kyopro\n\n/**\n * @brief \u306A\u3082\u308A\
    \u30B0\u30E9\u30D5\n * @docs docs/graph/Namori.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/Namori.hpp
  requiredBy: []
  timestamp: '2023-10-22 17:06:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/Namori.hpp
layout: document
redirect_from:
- /library/src/graph/Namori.hpp
- /library/src/graph/Namori.hpp.html
title: "\u306A\u3082\u308A\u30B0\u30E9\u30D5"
---
## 概要

$N$ 頂点 $N$ 辺の連結な単純無向グラフ(通称なもりグラフ)は,

- ちょうどひとつの閉路を含む.
- 閉路上の頂点を根とするいくつかの木に分解できる.

ことが知られています. このライブラリを使うと, 与えられたなもりグラフに対して

- 閉路上の点を列挙
- いくつかの木に分解

が行えます.

## コンストラクタ

```cpp
Namori g(int N)
```

頂点数・辺数 $N$ で初期化します. この時点では辺は貼られていません.

### 計算量

- $O(N)$

## add_edge

```cpp
void add_edge(int a, int b)
```

$a$ と $b$ の間に無向辺を張ります.

### 制約

- $0 \leq a,b \lt N$

### 計算量

- $O(1)$

## build

```cpp
void build()
```

なもりグラフを分解します.

### 制約

- これが呼び出される時点で辺は全て張られている.

### 計算量

- $O(N)$

## root

```cpp
int root(int v)
```

分解後に $v$ の属する木の根の番号を返します.

### 制約

- $0 \leq v \lt N$

### 計算量

- $O(1)$

## is_in_cycle

```cpp
bool is_in_cycle(int v)
```

$v$ が閉路に含まれているか判定します

### 制約

- $0 \leq v \lt N$

### 計算量

- $O(1)$