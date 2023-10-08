---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/graph/StaticGraph.hpp
    title: "\u9759\u7684\u30B0\u30E9\u30D5"
  - icon: ':x:'
    path: src/graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL/1_A.test.cpp
    title: test/AOJ/GRL/1_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "CSR\u5F62\u5F0F"
    links: []
  bundledCode: "#line 2 \"src/internal/CSR.hpp\"\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nnamespace kyopro {\nnamespace internal {\n\n/**\n * @brief\
    \ CSR\u5F62\u5F0F\n */\ntemplate <typename T> class CSR {\npublic:\n    using\
    \ usize = std::size_t;\n    const usize n;\n\nprivate:\n    std::vector<std::vector<T>>\
    \ mat;\n    std::vector<T> csr;\n    std::vector<usize> ssum;\n    \npublic:\n\
    \    class range {\n        std::vector<T>::iterator l, r;\n\n    public:\n  \
    \      range(const std::vector<T>::iterator& l,\n              const std::vector<T>::iterator&\
    \ r)\n            : l(l), r(r){}\n        const std::vector<T>::iterator begin()\
    \ const { return l; }\n        const std::vector<T>::iterator end() const { return\
    \ r; }\n    };\n\n    CSR(usize n) : n(n), mat(n), csr(), ssum(n + 1) {}\n   \
    \ CSR(const std::vector<std::vector<T>>& mat) : mat(mat) {}\n    \n    void add(usize\
    \ a, T b) {\n        assert(0 <= a && a < n);\n        mat[a].emplace_back(b);\n\
    \    }\n    void build() {\n        for (int i = 0; i < n; ++i) {\n          \
    \  ssum[i + 1] += ssum[i] + mat[i].size();\n        }\n        csr.reserve(ssum.back());\n\
    \        for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < (int)mat[i].size();\
    \ ++j) {\n                csr.emplace_back(mat[i][j]);\n            }\n      \
    \  }\n        mat.clear();\n    }\n    const range operator[](usize x) {\n   \
    \     assert(0 <= x && x < n);\n        return range(csr.begin() + ssum[x], csr.begin()\
    \ + ssum[x + 1]);\n    }\n};\n};  // namespace internal\n};  // namespace kyopro\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nnamespace kyopro {\nnamespace internal {\n\n/**\n * @brief CSR\u5F62\u5F0F\n\
    \ */\ntemplate <typename T> class CSR {\npublic:\n    using usize = std::size_t;\n\
    \    const usize n;\n\nprivate:\n    std::vector<std::vector<T>> mat;\n    std::vector<T>\
    \ csr;\n    std::vector<usize> ssum;\n    \npublic:\n    class range {\n     \
    \   std::vector<T>::iterator l, r;\n\n    public:\n        range(const std::vector<T>::iterator&\
    \ l,\n              const std::vector<T>::iterator& r)\n            : l(l), r(r){}\n\
    \        const std::vector<T>::iterator begin() const { return l; }\n        const\
    \ std::vector<T>::iterator end() const { return r; }\n    };\n\n    CSR(usize\
    \ n) : n(n), mat(n), csr(), ssum(n + 1) {}\n    CSR(const std::vector<std::vector<T>>&\
    \ mat) : mat(mat) {}\n    \n    void add(usize a, T b) {\n        assert(0 <=\
    \ a && a < n);\n        mat[a].emplace_back(b);\n    }\n    void build() {\n \
    \       for (int i = 0; i < n; ++i) {\n            ssum[i + 1] += ssum[i] + mat[i].size();\n\
    \        }\n        csr.reserve(ssum.back());\n        for (int i = 0; i < n;\
    \ ++i) {\n            for (int j = 0; j < (int)mat[i].size(); ++j) {\n       \
    \         csr.emplace_back(mat[i][j]);\n            }\n        }\n        mat.clear();\n\
    \    }\n    const range operator[](usize x) {\n        assert(0 <= x && x < n);\n\
    \        return range(csr.begin() + ssum[x], csr.begin() + ssum[x + 1]);\n   \
    \ }\n};\n};  // namespace internal\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/internal/CSR.hpp
  requiredBy:
  - src/graph/dijkstra.hpp
  - src/graph/StaticGraph.hpp
  timestamp: '2023-10-08 22:01:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/GRL/1_A.test.cpp
documentation_of: src/internal/CSR.hpp
layout: document
redirect_from:
- /library/src/internal/CSR.hpp
- /library/src/internal/CSR.hpp.html
title: "CSR\u5F62\u5F0F"
---
