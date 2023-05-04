---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/1_A.test.cpp
    title: test/AOJ/GRL/1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/graph/Shortest_Path.test.cpp
    title: test/yosupo_judge/graph/Shortest_Path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/tree/Tree_Diameter.test.cpp
    title: test/yosupo_judge/tree/Tree_Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
    links: []
  bundledCode: "#line 2 \"src/graph/dijkstra.hpp\"\n#include <queue>\n#include <vector>\n\
    namespace kyopro {\nstruct edge {\n    int to;\n    long long cost;\n    edge(int\
    \ to, long long cost) : to(to), cost(cost) {}\n};\n/// @brief \u30C0\u30A4\u30AF\
    \u30B9\u30C8\u30E9\u6CD5\nstd::pair<std::vector<long long>, std::vector<int>>\
    \ dijkstra(\n    int s,\n    const std::vector<std::vector<edge>>& g) {\n    std::vector<long\
    \ long> dist(g.size(), (long long)1e18);\n    std::vector<int> pre(g.size(), -1);\n\
    \    std::priority_queue<std::pair<long long, int>,\n                        std::vector<std::pair<long\
    \ long, int>>,\n                        std::greater<std::pair<long long, int>>>\n\
    \        que;\n    que.emplace(0, s);\n    dist[s] = 0;\n    pre[s] = s;\n   \
    \ while (!que.empty()) {\n        auto [d, v] = que.top();\n        que.pop();\n\
    \        if (dist[v] != d) {\n            continue;\n        }\n\n        for\
    \ (const auto& [nv, c] : g[v]) {\n            if (dist[v] + c < dist[nv]) {\n\
    \                dist[nv] = dist[v] + c;\n                pre[nv] = v;\n     \
    \           que.emplace(dist[nv], nv);\n            }\n        }\n    }\n    return\
    \ {dist, pre};\n}\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\nnamespace kyopro {\nstruct\
    \ edge {\n    int to;\n    long long cost;\n    edge(int to, long long cost) :\
    \ to(to), cost(cost) {}\n};\n/// @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
    \nstd::pair<std::vector<long long>, std::vector<int>> dijkstra(\n    int s,\n\
    \    const std::vector<std::vector<edge>>& g) {\n    std::vector<long long> dist(g.size(),\
    \ (long long)1e18);\n    std::vector<int> pre(g.size(), -1);\n    std::priority_queue<std::pair<long\
    \ long, int>,\n                        std::vector<std::pair<long long, int>>,\n\
    \                        std::greater<std::pair<long long, int>>>\n        que;\n\
    \    que.emplace(0, s);\n    dist[s] = 0;\n    pre[s] = s;\n    while (!que.empty())\
    \ {\n        auto [d, v] = que.top();\n        que.pop();\n        if (dist[v]\
    \ != d) {\n            continue;\n        }\n\n        for (const auto& [nv, c]\
    \ : g[v]) {\n            if (dist[v] + c < dist[nv]) {\n                dist[nv]\
    \ = dist[v] + c;\n                pre[nv] = v;\n                que.emplace(dist[nv],\
    \ nv);\n            }\n        }\n    }\n    return {dist, pre};\n}\n};  // namespace\
    \ kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-05-03 22:08:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/1_A.test.cpp
  - test/yosupo_judge/graph/Shortest_Path.test.cpp
  - test/yosupo_judge/tree/Tree_Diameter.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---
