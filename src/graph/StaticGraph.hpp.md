---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/internal/CSR.hpp
    title: "CSR\u5F62\u5F0F"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/1_A.test.cpp
    title: test/AOJ/GRL/1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9759\u7684\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "#line 2 \"src/graph/StaticGraph.hpp\"\n#include <limits>\n#line 2\
    \ \"src/internal/CSR.hpp\"\n\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace kyopro {\nnamespace internal {\n\n/**\n * @brief CSR\u5F62\
    \u5F0F\n */\ntemplate <typename T> class CSR {\npublic:\n    using usize = std::size_t;\n\
    \    const usize n;\n\nprivate:\n    std::vector<std::vector<T>> mat;\n    std::vector<T>\
    \ csr;\n    std::vector<usize> ssum;\n    \npublic:\n    class range {\n     \
    \   typename std::vector<T>::iterator l, r;\n\n    public:\n        range(const\
    \ typename std::vector<T>::iterator& l,\n              const typename std::vector<T>::iterator&\
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
    \  // namespace kyopro\n"
  code: "#pragma once\n#include <limits>\n#include \"../../src/internal/CSR.hpp\"\n\
    \nnamespace kyopro {\n/**\n * @brief \u9759\u7684\u30B0\u30E9\u30D5\n */\ntemplate\
    \ <bool is_directed> class UnweightedStaticGraph {\n    internal::CSR<int> g;\n\
    \npublic:\n    UnweightedStaticGraph(std::size_t n) : g(n) {}\n    void add_edge(int\
    \ a, int b) {\n        assert(0 <= a && a < g.n);\n        assert(0 <= b && b\
    \ < g.n);\n\n        g.add(a, b);\n        if constexpr (!is_directed) g.add(b,\
    \ a);\n    }\n    std::size_t size() const { return g.n; }\n    void build() {\
    \ g.build(); }\n    const typename internal::CSR<int>::range operator[](std::size_t\
    \ i) {\n        return g[i];\n    }\n};\ntemplate <typename weight, bool is_directed>\
    \ class WeightedStaticGraph {\n    internal::CSR<std::pair<int, weight>> g;\n\n\
    public:\n    WeightedStaticGraph(std::size_t n) : g(n){}\n    void add_edge(int\
    \ a, int b, weight w) {\n        assert(0 <= a && a < g.n);\n        assert(0\
    \ <= a && a < g.n);\n\n        g.add(a, std::pair<int, weight>(b, w));\n     \
    \   if constexpr (!is_directed) g.add(a, std::pair<int, weight>(b, w));\n    }\n\
    \    std::size_t size() const { return g.n; }\n    void build() { g.build(); }\n\
    \    const typename internal::CSR<std::pair<int, weight>>::range operator[](\n\
    \        std::size_t i) {\n        return g[i];\n    }\n};\n\n};  // namespace\
    \ kyopro"
  dependsOn:
  - src/internal/CSR.hpp
  isVerificationFile: false
  path: src/graph/StaticGraph.hpp
  requiredBy:
  - src/graph/dijkstra.hpp
  timestamp: '2023-10-08 22:37:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/1_A.test.cpp
documentation_of: src/graph/StaticGraph.hpp
layout: document
redirect_from:
- /library/src/graph/StaticGraph.hpp
- /library/src/graph/StaticGraph.hpp.html
title: "\u9759\u7684\u30B0\u30E9\u30D5"
---
