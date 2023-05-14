---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
    title: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
    title: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/doubling.md
    document_title: "\u6728\u306E\u30C0\u30D6\u30EA\u30F3\u30B0"
    links: []
  bundledCode: "#line 2 \"src/tree/doubling.hpp\"\n#include <cassert>\n#include <vector>\n\
    \n/**\n * @brief \u6728\u306E\u30C0\u30D6\u30EA\u30F3\u30B0\n */\nnamespace kyopro\
    \ {\nclass doubling {\n    struct edge {\n        const int to;\n        const\
    \ int cost;\n        edge() = default;\n        constexpr explicit edge(int to,\
    \ int cost) : to(to), cost(cost) {}\n    };\n    const int n;\n    static constexpr\
    \ int lg = 21;\n    std::vector<std::vector<edge>> g;\n    std::vector<int> parent[lg];\n\
    \    std::vector<long long> _dist;\n    std::vector<int> _depth;\n\npublic:\n\
    \    explicit doubling(int n) : n(n), g(n), _dist(n, -1), _depth(n) {\n      \
    \  std::fill(parent, parent + lg, std::vector<int>(n));\n    }\n    void add_edge(int\
    \ a, int b, int c = 1) {\n        g[a].emplace_back(b, 1);\n        g[b].emplace_back(a,\
    \ 1);\n    }\n    void build(int root = 0) {\n        std::vector<int> st;\n \
    \       st.reserve(n);\n\n        st.emplace_back(root);\n        _dist[root]\
    \ = 0, _depth[root] = 0, parent[0][root] = root;\n        while (!st.empty())\
    \ {\n            int v = st.back();\n            st.pop_back();\n\n          \
    \  for (auto [nv, c] : g[v]) {\n                if (_dist[nv] != -1) continue;\n\
    \                _dist[nv] = _dist[v] + c;\n                _depth[nv] = _depth[v]\
    \ + 1;\n                parent[0][nv] = v;\n\n                st.emplace_back(nv);\n\
    \            }\n        }\n\n        for (int i = 0; i < lg; ++i) {\n        \
    \    for (int v = 0; v < n; ++v) {\n                parent[i + 1][v] = parent[i][parent[i][v]];\n\
    \            }\n        }\n    }\n\n    int level_ancestor(int v, const int k)\
    \ const {\n        if (_depth[v] < k) return -1;\n\n        for (int i = 0; i\
    \ < lg; ++i) {\n            if (k >> i & 1) {\n                v = parent[i][v];\n\
    \            }\n        }\n        return v;\n    }\n\n    long long dist(int\
    \ v) const { return _dist[v]; }\n    long long dist(int u, int v) const {\n  \
    \      return _dist[u] + _dist[v] - 2 * _dist[lca(u, v)];\n    }\n    int depth(int\
    \ v) const { return _depth[v]; }\n    int unweighted_dist(int u, int v) const\
    \ {\n        return _depth[u] + _depth[v] - 2 * _depth[lca(u, v)];\n    }\n  \
    \  int lca(int a, int b) const {\n        if (_depth[a] > _depth[b]) {\n     \
    \       std::swap(a, b);\n        }\n        if (_depth[a] != _depth[b]) {\n \
    \           b = level_ancestor(b, _depth[b] - _depth[a]);\n        }\n       \
    \ if (a == b) return a;\n        for (int k = lg - 1; k >= 0; --k) {\n       \
    \     if (parent[k][a] != parent[k][b]) {\n                a = parent[k][a];\n\
    \                b = parent[k][b];\n            }\n        }\n        return parent[0][a];\n\
    \    }\n\n    int jump(const int from, const int to, const int k) const {\n  \
    \      int p = lca(from, to);\n        int d1 = _depth[from] - _depth[p];\n  \
    \      int d2 = _depth[to] - _depth[p];\n\n        if (d1 + d2 < k) {\n      \
    \      return -1;\n        }\n\n        if (d1 >= k) {\n            return level_ancestor(from,\
    \ k);\n        } else {\n            return level_ancestor(to, d1 + d2 - k);\n\
    \        }\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/tree/doubling.md\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n/**\n * @brief \u6728\
    \u306E\u30C0\u30D6\u30EA\u30F3\u30B0\n */\nnamespace kyopro {\nclass doubling\
    \ {\n    struct edge {\n        const int to;\n        const int cost;\n     \
    \   edge() = default;\n        constexpr explicit edge(int to, int cost) : to(to),\
    \ cost(cost) {}\n    };\n    const int n;\n    static constexpr int lg = 21;\n\
    \    std::vector<std::vector<edge>> g;\n    std::vector<int> parent[lg];\n   \
    \ std::vector<long long> _dist;\n    std::vector<int> _depth;\n\npublic:\n   \
    \ explicit doubling(int n) : n(n), g(n), _dist(n, -1), _depth(n) {\n        std::fill(parent,\
    \ parent + lg, std::vector<int>(n));\n    }\n    void add_edge(int a, int b, int\
    \ c = 1) {\n        g[a].emplace_back(b, 1);\n        g[b].emplace_back(a, 1);\n\
    \    }\n    void build(int root = 0) {\n        std::vector<int> st;\n       \
    \ st.reserve(n);\n\n        st.emplace_back(root);\n        _dist[root] = 0, _depth[root]\
    \ = 0, parent[0][root] = root;\n        while (!st.empty()) {\n            int\
    \ v = st.back();\n            st.pop_back();\n\n            for (auto [nv, c]\
    \ : g[v]) {\n                if (_dist[nv] != -1) continue;\n                _dist[nv]\
    \ = _dist[v] + c;\n                _depth[nv] = _depth[v] + 1;\n             \
    \   parent[0][nv] = v;\n\n                st.emplace_back(nv);\n            }\n\
    \        }\n\n        for (int i = 0; i < lg; ++i) {\n            for (int v =\
    \ 0; v < n; ++v) {\n                parent[i + 1][v] = parent[i][parent[i][v]];\n\
    \            }\n        }\n    }\n\n    int level_ancestor(int v, const int k)\
    \ const {\n        if (_depth[v] < k) return -1;\n\n        for (int i = 0; i\
    \ < lg; ++i) {\n            if (k >> i & 1) {\n                v = parent[i][v];\n\
    \            }\n        }\n        return v;\n    }\n\n    long long dist(int\
    \ v) const { return _dist[v]; }\n    long long dist(int u, int v) const {\n  \
    \      return _dist[u] + _dist[v] - 2 * _dist[lca(u, v)];\n    }\n    int depth(int\
    \ v) const { return _depth[v]; }\n    int unweighted_dist(int u, int v) const\
    \ {\n        return _depth[u] + _depth[v] - 2 * _depth[lca(u, v)];\n    }\n  \
    \  int lca(int a, int b) const {\n        if (_depth[a] > _depth[b]) {\n     \
    \       std::swap(a, b);\n        }\n        if (_depth[a] != _depth[b]) {\n \
    \           b = level_ancestor(b, _depth[b] - _depth[a]);\n        }\n       \
    \ if (a == b) return a;\n        for (int k = lg - 1; k >= 0; --k) {\n       \
    \     if (parent[k][a] != parent[k][b]) {\n                a = parent[k][a];\n\
    \                b = parent[k][b];\n            }\n        }\n        return parent[0][a];\n\
    \    }\n\n    int jump(const int from, const int to, const int k) const {\n  \
    \      int p = lca(from, to);\n        int d1 = _depth[from] - _depth[p];\n  \
    \      int d2 = _depth[to] - _depth[p];\n\n        if (d1 + d2 < k) {\n      \
    \      return -1;\n        }\n\n        if (d1 >= k) {\n            return level_ancestor(from,\
    \ k);\n        } else {\n            return level_ancestor(to, d1 + d2 - k);\n\
    \        }\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/tree/doubling.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/doubling.hpp
  requiredBy: []
  timestamp: '2023-05-14 15:21:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
  - test/yosupo_judge/tree/Jump_on_Tree.test.cpp
documentation_of: src/tree/doubling.hpp
layout: document
redirect_from:
- /library/src/tree/doubling.hpp
- /library/src/tree/doubling.hpp.html
title: "\u6728\u306E\u30C0\u30D6\u30EA\u30F3\u30B0"
---
## 概要
木をダブリングを用いて管理することで
- Level Ancestor
- Lowest Common Ancestor

を高速に求めます.また,それに派生したクエリを高速に処理します.


## コンストラクタ
```cpp
kyopro::doubling T(int n)
```
$n$ 頂点の木 $T$ を生成します.なお,この時点ではまだ辺は貼られていません. 

### 制約
- 木 $T$ の高さは $2^{21}\approx 2\times10^6$ を超えない.
    - $n\leq 2^{21}$ なら十分.

### 計算量
- $O(n\log n)$

## add_edge
```cpp
void add_edge(int a,int b,int c)
```
頂点 $a,b$ に重み $c$ の無向辺を張ります.\
デフォルトでは $c=1$ です.

### 制約
- $0\leq a,b < n$

### 計算量
- $O(1)$


## build
```cpp
void build(int root)
```
$T$ の根を頂点 $\mathtt{root}$ として前処理を行います.\
デフォルトでは $\mathtt{root}=0$ です.

### 制約
- $0\leq \mathtt{root} < n$

### 計算量
- $O(n\log n)$


## level_ancestor
```cpp
int level_ancestor(int v,int k)
```
頂点 $v$ から根の方向に $k$ 辿った頂点を返します.\
すなわち,頂点 $v$ から根へのパスを

$$p = (p_0=v , p_1 , p_2 \dots p_{|p|-1} = \mathtt{root})$$

とするとき, $p_k$  を返します.ただし, $k\geq \left|p\right|$ の時は $-1$ を返します.

### 制約
- $0\leq v < n$

### 計算量
- $O(\log k)$

## lca
```cpp
int lca(int u,int v)
```

頂点 $u,v$ のLowest Common Ancestor(最小共通祖先)を返します

### 制約
- $0\leq u,v < n$

### 計算量
- $O(\log n)$

## depth
```cpp
int depth(int v)
```
頂点 $u$ の深さを返します.ただし,ここでの「深さ」は**重み無し**です.


## unweighted_dist
```cpp
long long unweighted_dist(int u,int v)
```
頂点 $u,v$ の距離を返します.ここでの「距離」は**重み無し**です.
### 制約
- $0\leq u,v < n$

### 計算量
- $O(\log n)$

## dist
```cpp
long long dist(int v)
```
頂点 $u$ の深さを返します.ただし,ここでの「深さ」は**重み付き**です.

```cpp
long long dist(int u,int v)
```
頂点 $u,v$ の距離を返します.ここでの「距離」は**重み付き**です.
### 制約
- $0\leq u,v < n$

### 計算量
- $O(\log n)$


## jump
```cpp
int jump(int from,int to,int k)
```
$\mathtt{from}$ から $\mathtt{to}$ に $k$ 進んだ頂点を返します.\
すなわち, $\mathtt{from}\to\mathtt{to}$の最短パスを

$$p=(p_0=\mathtt{from},p_1,p_2,\dots,p_{|p|-1}=\mathtt{to})$$

としたとき, $p_k$ を返します.ただし, $k\geq\left|p\right|$ ならば $-1$ を返します.

### 制約
- $0\leq\mathtt{from},\mathtt{to} < n$

### 計算量
- $O(\log k)$
