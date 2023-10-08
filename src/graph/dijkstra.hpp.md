---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/StaticGraph.hpp
    title: "\u9759\u7684\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/internal/CSR.hpp
    title: "CSR\u5F62\u5F0F"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/1_A.test.cpp
    title: test/AOJ/GRL/1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/dijkstra.md
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
    links: []
  bundledCode: "#line 2 \"src/graph/dijkstra.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <numeric>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n#line 2 \"src/graph/StaticGraph.hpp\"\n#include <limits>\n#line 2\
    \ \"src/internal/CSR.hpp\"\n\n#line 6 \"src/internal/CSR.hpp\"\n\nnamespace kyopro\
    \ {\nnamespace internal {\n\n/**\n * @brief CSR\u5F62\u5F0F\n */\ntemplate <typename\
    \ T> class CSR {\npublic:\n    using usize = std::size_t;\n    const usize n;\n\
    \nprivate:\n    std::vector<std::vector<T>> mat;\n    std::vector<T> csr;\n  \
    \  std::vector<usize> ssum;\n    \npublic:\n    class range {\n        typename\
    \ std::vector<T>::iterator l, r;\n\n    public:\n        range(const typename\
    \ std::vector<T>::iterator& l,\n              const typename std::vector<T>::iterator&\
    \ r)\n            : l(l), r(r){}\n        const typename std::vector<T>::iterator\
    \ begin() const { return l; }\n        const typename std::vector<T>::iterator\
    \ end() const { return r; }\n    };\n\n    CSR(usize n) : n(n), mat(n), csr(),\
    \ ssum(n + 1) {}\n    CSR(const std::vector<std::vector<T>>& mat) : mat(mat) {}\n\
    \    \n    void add(usize a, T b) {\n        assert(0 <= a && a < n);\n      \
    \  mat[a].emplace_back(b);\n    }\n    void build() {\n        for (int i = 0;\
    \ i < n; ++i) {\n            ssum[i + 1] += ssum[i] + mat[i].size();\n       \
    \ }\n        csr.reserve(ssum.back());\n        for (int i = 0; i < n; ++i) {\n\
    \            for (int j = 0; j < (int)mat[i].size(); ++j) {\n                csr.emplace_back(mat[i][j]);\n\
    \            }\n        }\n        mat.clear();\n    }\n    const range operator[](usize\
    \ x) {\n        assert(0 <= x && x < n);\n        return range(csr.begin() + ssum[x],\
    \ csr.begin() + ssum[x + 1]);\n    }\n};\n};  // namespace internal\n};  // namespace\
    \ kyopro\n#line 4 \"src/graph/StaticGraph.hpp\"\n\nnamespace kyopro {\n/**\n *\
    \ @brief \u9759\u7684\u30B0\u30E9\u30D5\n */\ntemplate <bool is_directed> class\
    \ UnweightedStaticGraph {\n    internal::CSR<int> g;\n\npublic:\n    UnweightedStaticGraph(std::size_t\
    \ n) : g(n) {}\n    void add_edge(int a, int b) {\n        assert(0 <= a && a\
    \ < g.n);\n        assert(0 <= b && b < g.n);\n\n        g.add(a, b);\n      \
    \  if constexpr (!is_directed) g.add(b, a);\n    }\n    std::size_t size() const\
    \ { return g.n; }\n    void build() { g.build(); }\n    const typename internal::CSR<int>::range\
    \ operator[](std::size_t i) {\n        return g[i];\n    }\n};\ntemplate <typename\
    \ weight, bool is_directed> class WeightedStaticGraph {\n    internal::CSR<std::pair<int,\
    \ weight>> g;\n\npublic:\n    WeightedStaticGraph(std::size_t n) : g(n){}\n  \
    \  void add_edge(int a, int b, weight w) {\n        assert(0 <= a && a < g.n);\n\
    \        assert(0 <= a && a < g.n);\n\n        g.add(a, std::pair<int, weight>(b,\
    \ w));\n        if constexpr (!is_directed) g.add(a, std::pair<int, weight>(b,\
    \ w));\n    }\n    std::size_t size() const { return g.n; }\n    void build()\
    \ { g.build(); }\n    const typename internal::CSR<std::pair<int, weight>>::range\
    \ operator[](\n        std::size_t i) {\n        return g[i];\n    }\n};\n\n};\
    \  // namespace kyopro\n#line 9 \"src/graph/dijkstra.hpp\"\nnamespace kyopro {\n\
    /**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n */\ntemplate <typename\
    \ weight> class dijkstra {\n    std::vector<weight> _dist;\n    const int n;\n\
    \    using Graph = WeightedStaticGraph<long long, true>;\n\n\nprivate:\n    static\
    \ constexpr weight winf = std::numeric_limits<weight>::max() / 2;\n    Graph g;\n\
    \    \npublic:\n    dijkstra(int n) : n(n), g(n), _dist(n, winf){}\n    dijkstra(const\
    \ Graph& g) : n(g.size()), _dist(n, winf), g(g){}\n    void add_edge(int from,\
    \ int to, weight cost) {\n        assert(0 <= from && from < n);\n        assert(0\
    \ <= to && to < n);\n        assert(cost >= 0);\n\n        g.add_edge(from, to,\
    \ cost);\n    }\n    void build(int s) {\n        g.build();\n        std::priority_queue<std::pair<weight,\
    \ int>,\n                            std::vector<std::pair<weight, int>>, std::greater<>>\n\
    \            q;\n        q.emplace(0, s);\n        _dist[s] = 0;\n        while\
    \ (!q.empty()) {\n            auto [d, v] = q.top();\n            q.pop();\n \
    \           if (_dist[v] != d) {\n                continue;\n            }\n\n\
    \            for (auto [nv, c] : g[v]) {\n                if (_dist[v] + c < _dist[nv])\
    \ {\n                    _dist[nv] = _dist[v] + c;\n                    q.emplace(_dist[nv],\
    \ nv);\n                }\n            }\n        }\n    }\n    weight dist(int\
    \ v) const {\n        assert(0 <= v && v < n);\n        return _dist[v];\n   \
    \ }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/graph/dijkstra.md\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n#include \"../../src/graph/StaticGraph.hpp\"\
    \nnamespace kyopro {\n/**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
    \n */\ntemplate <typename weight> class dijkstra {\n    std::vector<weight> _dist;\n\
    \    const int n;\n    using Graph = WeightedStaticGraph<long long, true>;\n\n\
    \nprivate:\n    static constexpr weight winf = std::numeric_limits<weight>::max()\
    \ / 2;\n    Graph g;\n    \npublic:\n    dijkstra(int n) : n(n), g(n), _dist(n,\
    \ winf){}\n    dijkstra(const Graph& g) : n(g.size()), _dist(n, winf), g(g){}\n\
    \    void add_edge(int from, int to, weight cost) {\n        assert(0 <= from\
    \ && from < n);\n        assert(0 <= to && to < n);\n        assert(cost >= 0);\n\
    \n        g.add_edge(from, to, cost);\n    }\n    void build(int s) {\n      \
    \  g.build();\n        std::priority_queue<std::pair<weight, int>,\n         \
    \                   std::vector<std::pair<weight, int>>, std::greater<>>\n   \
    \         q;\n        q.emplace(0, s);\n        _dist[s] = 0;\n        while (!q.empty())\
    \ {\n            auto [d, v] = q.top();\n            q.pop();\n            if\
    \ (_dist[v] != d) {\n                continue;\n            }\n\n            for\
    \ (auto [nv, c] : g[v]) {\n                if (_dist[v] + c < _dist[nv]) {\n \
    \                   _dist[nv] = _dist[v] + c;\n                    q.emplace(_dist[nv],\
    \ nv);\n                }\n            }\n        }\n    }\n    weight dist(int\
    \ v) const {\n        assert(0 <= v && v < n);\n        return _dist[v];\n   \
    \ }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/graph/dijkstra.md\n */"
  dependsOn:
  - src/graph/StaticGraph.hpp
  - src/internal/CSR.hpp
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-10-08 22:37:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/1_A.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---
