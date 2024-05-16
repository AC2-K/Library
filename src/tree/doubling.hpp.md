---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/CSR.hpp
    title: "CSR\u5F62\u5F0F(\u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u306E\u5727\
      \u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
    title: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
    title: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/tree/doubling.md
    document_title: "Binary Lifting(\u6728\u4E0A\u306E\u30C0\u30D6\u30EA\u30F3\u30B0\
      )"
    links: []
  bundledCode: "#line 2 \"src/tree/doubling.hpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"src/internal/CSR.hpp\"\n\n#line 4 \"src/internal/CSR.hpp\"\n#include\
    \ <iterator>\n#include <utility>\n#line 7 \"src/internal/CSR.hpp\"\n\nnamespace\
    \ kyopro {\nnamespace internal {\n\ntemplate <typename T, typename _size_t> class\
    \ csr {\n    _size_t n;\n    std::vector<T> d;\n    std::vector<_size_t> ssum;\n\
    \npublic:\n    csr() = default;\n    csr(_size_t n, const std::vector<std::pair<_size_t,\
    \ T>>& v)\n        : n(n), ssum(n + 1), d(v.size()) {\n        for (int i = 0;\
    \ i < (int)v.size(); ++i) {\n            ++ssum[v[i].first + 1];\n        }\n\
    \        for (int i = 0; i < n; ++i) {\n            ssum[i + 1] += ssum[i];\n\
    \        }\n\n        std::vector cnt = ssum;\n        for (auto e : v) d[cnt[e.first]++]\
    \ = e.second;\n    }\n\n    struct vector_range {\n        using iterator = typename\
    \ std::vector<T>::iterator;\n        iterator l, r;\n\n        iterator begin()\
    \ const { return l; }\n        iterator end() const { return r; }\n        _size_t\
    \ size() { return std::distance(l, r); }\n        T& operator[](_size_t i) const\
    \ { return l[i]; }\n    };\n    struct const_vector_range {\n        using const_iterator\
    \ = typename std::vector<T>::const_iterator;\n        const_iterator l, r;\n\n\
    \        const_iterator begin() const { return l; }\n        const_iterator end()\
    \ const { return r; }\n        _size_t size() { return (_size_t)std::distance(l,\
    \ r); }\n        const T& operator[](_size_t i) const { return l[i]; }\n    };\n\
    \n    vector_range operator[](_size_t i) {\n        return vector_range{d.begin()\
    \ + ssum[i], d.begin() + ssum[i + 1]};\n    }\n    const_vector_range operator[](_size_t\
    \ i) const {\n        return const_vector_range{d.begin() + ssum[i], d.begin()\
    \ + ssum[i + 1]};\n    }\n\n    _size_t size() const { return (_size_t)n; }\n\
    };\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n * @brief CSR\u5F62\
    \u5F0F(\u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u306E\u5727\u7E2E)\n */\n#line\
    \ 5 \"src/tree/doubling.hpp\"\n\nnamespace kyopro {\n\ntemplate <typename Cost,\
    \ int lg> class doubling {\n    struct edge {\n        int to;\n        Cost cost;\n\
    \n        edge() : to(0), cost(0) {}\n        edge(int to, Cost cost) : to(to),\
    \ cost(cost) {}\n    };\n\n    const int n;\n\n    std::vector<std::pair<int,\
    \ edge>> es;\n    std::vector<int> parent[lg];\n    std::vector<Cost> _dist;\n\
    \    std::vector<int> _depth;\n\npublic:\n    doubling(int n) : n(n), _dist(n,\
    \ -1), _depth(n) {\n        std::fill(parent, parent + lg, std::vector<int>(n));\n\
    \        es.reserve(2 * (n - 1));\n    }\n\n    void add_edge(int a, int b, Cost\
    \ c = 1) {\n        es.emplace_back(a, edge{b, c});\n        es.emplace_back(b,\
    \ edge{a, c});\n    }\n    \n    void build(int root = 0) {\n        internal::csr\
    \ g(n, es);\n\n        std::vector<int> st;\n        st.reserve(n);\n\n      \
    \  st.emplace_back(root);\n        _dist[root] = 0, _depth[root] = 0, parent[0][root]\
    \ = root;\n        while (!st.empty()) {\n            int v = st.back();\n   \
    \         st.pop_back();\n\n            for (auto [nv, c] : g[v]) {\n        \
    \        if (_dist[nv] != -1) continue;\n                _dist[nv] = _dist[v]\
    \ + c;\n                _depth[nv] = _depth[v] + 1;\n                parent[0][nv]\
    \ = v;\n\n                st.emplace_back(nv);\n            }\n        }\n\n \
    \       for (int i = 0; i < lg; ++i) {\n            for (int v = 0; v < n; ++v)\
    \ {\n                parent[i + 1][v] = parent[i][parent[i][v]];\n           \
    \ }\n        }\n    }\n\n    int level_ancestor(int v, const int k) const {\n\
    \        if (_depth[v] < k) return -1;\n\n        for (int i = 0; i < lg; ++i)\
    \ {\n            if (k >> i & 1) {\n                v = parent[i][v];\n      \
    \      }\n        }\n        return v;\n    }\n\n    long long dist(int v) const\
    \ { return _dist[v]; }\n    long long dist(int u, int v) const {\n        return\
    \ dist(u) + dist(v) - 2 * dist(lca(u, v));\n    }\n    int depth(int v) const\
    \ { return _depth[v]; }\n    int unweighted_dist(int u, int v) const {\n     \
    \   return _depth[u] + _depth[v] - 2 * _depth[lca(u, v)];\n    }\n    int lca(int\
    \ a, int b) const {\n        if (_depth[a] > _depth[b]) {\n            std::swap(a,\
    \ b);\n        }\n        if (_depth[a] != _depth[b]) {\n            b = level_ancestor(b,\
    \ _depth[b] - _depth[a]);\n        }\n        if (a == b) return a;\n        for\
    \ (int k = lg - 1; k >= 0; --k) {\n            if (parent[k][a] != parent[k][b])\
    \ {\n                a = parent[k][a];\n                b = parent[k][b];\n  \
    \          }\n        }\n        return parent[0][a];\n    }\n\n    int jump(const\
    \ int from, const int to, const int k) const {\n        int p = lca(from, to);\n\
    \        int d1 = _depth[from] - _depth[p];\n        int d2 = _depth[to] - _depth[p];\n\
    \n        if (d1 + d2 < k) {\n            return -1;\n        }\n\n        if\
    \ (d1 >= k) {\n            return level_ancestor(from, k);\n        } else {\n\
    \            return level_ancestor(to, d1 + d2 - k);\n        }\n    }\n};\n};\
    \  // namespace kyopro\n\n/**\n *\n * @brief Binary Lifting(\u6728\u4E0A\u306E\
    \u30C0\u30D6\u30EA\u30F3\u30B0)\n * @docs docs/tree/doubling.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../internal/CSR.hpp\"\
    \n\nnamespace kyopro {\n\ntemplate <typename Cost, int lg> class doubling {\n\
    \    struct edge {\n        int to;\n        Cost cost;\n\n        edge() : to(0),\
    \ cost(0) {}\n        edge(int to, Cost cost) : to(to), cost(cost) {}\n    };\n\
    \n    const int n;\n\n    std::vector<std::pair<int, edge>> es;\n    std::vector<int>\
    \ parent[lg];\n    std::vector<Cost> _dist;\n    std::vector<int> _depth;\n\n\
    public:\n    doubling(int n) : n(n), _dist(n, -1), _depth(n) {\n        std::fill(parent,\
    \ parent + lg, std::vector<int>(n));\n        es.reserve(2 * (n - 1));\n    }\n\
    \n    void add_edge(int a, int b, Cost c = 1) {\n        es.emplace_back(a, edge{b,\
    \ c});\n        es.emplace_back(b, edge{a, c});\n    }\n    \n    void build(int\
    \ root = 0) {\n        internal::csr g(n, es);\n\n        std::vector<int> st;\n\
    \        st.reserve(n);\n\n        st.emplace_back(root);\n        _dist[root]\
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
    \      return dist(u) + dist(v) - 2 * dist(lca(u, v));\n    }\n    int depth(int\
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
    \        }\n    }\n};\n};  // namespace kyopro\n\n/**\n *\n * @brief Binary Lifting(\u6728\
    \u4E0A\u306E\u30C0\u30D6\u30EA\u30F3\u30B0)\n * @docs docs/tree/doubling.md\n\
    \ */"
  dependsOn:
  - src/internal/CSR.hpp
  isVerificationFile: false
  path: src/tree/doubling.hpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
  - test/yosupo_judge/tree/Jump_on_Tree.test.cpp
documentation_of: src/tree/doubling.hpp
layout: document
redirect_from:
- /library/src/tree/doubling.hpp
- /library/src/tree/doubling.hpp.html
title: "Binary Lifting(\u6728\u4E0A\u306E\u30C0\u30D6\u30EA\u30F3\u30B0)"
---
## 概要

木をダブリングを用いて管理することで

- Level Ancestor
- Lowest Common Ancestor

を高速に求めます.

## コンストラクタ

```cpp
doubling T(int n)
```

頂点数 $n$ で初期化します. この時点ではまだ辺は貼られていません.

### 制約

- 木 $T$ の**高さは** $2^{21} = 2097152 \gt 2\times 10^6$ を超えない.

### 計算量

- $O(n\log n)$

## add_edge

```cpp
void add_edge(int a, int b, int c)
```

頂点 $a,b$ の間に重み $c$ の無向辺を張ります. $c$ は省略可能で, デフォルトでは $c = 1$ です.

### 制約

- $0\leq a,b < n$

### 計算量

- $O(1)$

## build

```cpp
void build(int r)
```

$T$ の根を頂点 $r$ として前処理を行います. $r$ は省略可能で, デフォルトでは $r=0$ です.

### 制約

- $0\leq r < n$
- これが呼び出される時点で $T$ の辺は全て張り終えている.

### 計算量

- $O(n\log n)$

## level_ancestor

```cpp
int level_ancestor(int v, int k)
```

頂点 $v$ から根の方向に $k$ 辿った頂点を返します. すなわち, 頂点 $v$ から根へのパスを

$$p = (p_0=v , p_1 , p_2 \dots p_{\vert p\vert -1} = r)$$

とするときの $p_k$  を返します. 条件を満たす頂点が存在しなければ $-1$ をreturnします.
### 制約

- $0\leq v\lt n$

### 計算量

- $O(\log k)$

## lca

```cpp
int lca(int u, int v)
```

頂点 $u,v$ のLowest Common Ancestor(最深共通祖先)を返します

### 制約

- $0\leq u,v < n$

### 計算量

- $O(\log n)$

## depth

```cpp
int depth(int v)
```

頂点 $u$ の深さを返します. ここでの「深さ」は**重み無し**であることに注意してください.

## unweighted_dist

```cpp
int unweighted_dist(int u, int v)
```

頂点 $u,v$ の距離を返します. ここでの「距離」は**重み無し**です.

### 制約

- $0\leq u,v < n$

### 計算量

- $O(\log n)$

## dist

```cpp
long long dist(int u, int v)
```

頂点 $u,v$ の距離を返します.ここでの「距離」は**重み付き**です.
$v$ は省略可能で, デフォルトでは $v$ は$r$(=根)となります.

### 制約

- $0\leq u,v\lt n$

### 計算量

- $O(\log n)$

## jump

```cpp
int jump(int from, int to, int k)
```

$\mathtt{from}$ から $\mathtt{to}$ に $k$ 進んだ頂点を返します. すなわち, $\mathtt{from}\to\mathtt{to}$の最短パスを

$$p=(p_0=\mathtt{from},p_1,p_2,\dots,p_{\vert p\vert-1}=\mathtt{to})$$

としたときの $p_k$ を返します. ただし, そのような $p_k$ が存在しなければ $-1$ をreturnします.

### 制約

- $0\leq\mathtt{from},\mathtt{to}\lt n$

### 計算量

- $O(\log k)$
