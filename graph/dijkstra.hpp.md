---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/1_A.test.cpp
    title: test/AOJ/GRL/1_A.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/graph/Shortest_Path.test.cpp
    title: test/yosupo_judge/graph/Shortest_Path.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n#include <vector>\n#include<queue>\n\
    struct edge {\n    int to;\n    long long cost;\n    edge(int to, long long cost)\
    \ : to(to), cost(cost) {}\n};\n/// @brief Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\
    \u30E9\u6CD5)\n/// @note edge\u69CB\u9020\u4F53\u3092\u3055\u3089\u306B\u5BA3\u8A00\
    \u3057\u306A\u3044\u3053\u3068!!!\nstd::vector<long long> dijkstra(int s, const\
    \ std::vector<std::vector<edge>>& g) {\n    std::vector<long long> dist(g.size(),\
    \ (long long)1e18);\n    std::priority_queue<std::pair<long long, int>,\n    \
    \                    std::vector<std::pair<long long, int>>,\n               \
    \         std::greater<std::pair<long long, int>>>\n        que;\n    que.emplace(0,\
    \ s);\n    dist[s] = 0;\n    while (!que.empty()) {\n        auto [d, v] = que.top();\n\
    \        que.pop();\n        if (dist[v] != d) {\n            continue;\n    \
    \    }\n        for (const auto& [nv, c] : g[v]) {\n            if (dist[v] +\
    \ c < dist[nv]) {\n                dist[nv] = dist[v] + c;\n                que.emplace(dist[nv],\
    \ nv);\n            }\n        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n#include <vector>\n#include<queue>\nstruct edge {\n    int\
    \ to;\n    long long cost;\n    edge(int to, long long cost) : to(to), cost(cost)\
    \ {}\n};\n/// @brief Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n///\
    \ @note edge\u69CB\u9020\u4F53\u3092\u3055\u3089\u306B\u5BA3\u8A00\u3057\u306A\
    \u3044\u3053\u3068!!!\nstd::vector<long long> dijkstra(int s, const std::vector<std::vector<edge>>&\
    \ g) {\n    std::vector<long long> dist(g.size(), (long long)1e18);\n    std::priority_queue<std::pair<long\
    \ long, int>,\n                        std::vector<std::pair<long long, int>>,\n\
    \                        std::greater<std::pair<long long, int>>>\n        que;\n\
    \    que.emplace(0, s);\n    dist[s] = 0;\n    while (!que.empty()) {\n      \
    \  auto [d, v] = que.top();\n        que.pop();\n        if (dist[v] != d) {\n\
    \            continue;\n        }\n        for (const auto& [nv, c] : g[v]) {\n\
    \            if (dist[v] + c < dist[nv]) {\n                dist[nv] = dist[v]\
    \ + c;\n                que.emplace(dist[nv], nv);\n            }\n        }\n\
    \    }\n    return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-04-07 13:50:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/GRL/1_A.test.cpp
  - test/yosupo_judge/graph/Shortest_Path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
---
