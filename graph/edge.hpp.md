---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "dijkstra\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Shortest Path.test.cpp
    title: test/Library-Checker/Shortest Path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Tree Diameter.test.cpp
    title: test/Library-Checker/Tree Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u8FBA"
    links: []
  bundledCode: "#line 1 \"graph/edge.hpp\"\nstruct edge{\n    int to;\n    ll cost;\n\
    \    edge(int to,ll cost):to(to),cost(cost){}\n};\n///@brief \u8FBA\n"
  code: "struct edge{\n    int to;\n    ll cost;\n    edge(int to,ll cost):to(to),cost(cost){}\n\
    };\n///@brief \u8FBA"
  dependsOn: []
  isVerificationFile: false
  path: graph/edge.hpp
  requiredBy:
  - graph/dijkstra.hpp
  timestamp: '2023-02-21 12:21:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Library-Checker/Tree Diameter.test.cpp
  - test/Library-Checker/Shortest Path.test.cpp
documentation_of: graph/edge.hpp
layout: document
redirect_from:
- /library/graph/edge.hpp
- /library/graph/edge.hpp.html
title: "\u8FBA"
---
