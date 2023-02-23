---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/dijkstra.hpp
    title: "dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Shortest Path.test.cpp
    title: test/Library-Checker/Shortest Path.test.cpp
  - icon: ':x:'
    path: test/Library-Checker/Tree Diameter.test.cpp
    title: test/Library-Checker/Tree Diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: edge
    links: []
  bundledCode: "#line 1 \"graph/edge.hpp\"\nstruct edge{\n    int to;\n    ll cost;\n\
    \    edge(int to,ll cost):to(to),cost(cost){}\n};\n///@brief edge\n"
  code: "struct edge{\n    int to;\n    ll cost;\n    edge(int to,ll cost):to(to),cost(cost){}\n\
    };\n///@brief edge"
  dependsOn: []
  isVerificationFile: false
  path: graph/edge.hpp
  requiredBy:
  - graph/dijkstra.hpp
  timestamp: '2023-02-21 13:24:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/Library-Checker/Tree Diameter.test.cpp
  - test/Library-Checker/Shortest Path.test.cpp
documentation_of: graph/edge.hpp
layout: document
redirect_from:
- /library/graph/edge.hpp
- /library/graph/edge.hpp.html
title: edge
---
