---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/1_A.test.cpp
    title: test/AOJ/GRL/1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n#include<iostream>\n#include<vector>\n\
    #include<queue>\nnamespace library {\nstruct edge {\n\tint to;\n\tlong long cost;\n\
    \tedge(int to, long long cost) : to(to), cost(cost) {}\n};\n/// @brief Dijkstra\
    \ (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n/// @note edge\u69CB\u9020\u4F53\
    \u3092\u3055\u3089\u306B\u5BA3\u8A00\u3057\u306A\u3044\u3053\u3068!!!\nstd::vector<long\
    \ long> dijkstra(int s,\n\tconst std::vector<std::vector<edge>>& g) {\n\tstd::vector<long\
    \ long> dist(g.size(), (long long)1e18);\n\tstd::priority_queue<std::pair<long\
    \ long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long\
    \ long, int>>> que;\n\tque.emplace(0, s);\n\tdist[s] = 0;\n\twhile (!que.empty())\
    \ {\n\t\tauto [d, v] = que.top();\n\t\tque.pop();\n\t\tif (dist[v] != d) {\n\t\
    \t\tcontinue;\n\t\t}\n\n\t\tfor (const auto& [nv, c] : g[v]) {\n\t\t\tif (dist[v]\
    \ + c < dist[nv]) {\n\t\t\t\tdist[nv] = dist[v] + c;\n\t\t\t\tque.emplace(dist[nv],\
    \ nv);\n\t\t\t}\n\t\t}\n\t}\n\treturn dist;\n}\n\n};  // namespace library\n"
  code: "#pragma once\n#include<iostream>\n#include<vector>\n#include<queue>\nnamespace\
    \ library {\nstruct edge {\n\tint to;\n\tlong long cost;\n\tedge(int to, long\
    \ long cost) : to(to), cost(cost) {}\n};\n/// @brief Dijkstra (\u30C0\u30A4\u30AF\
    \u30B9\u30C8\u30E9\u6CD5)\n/// @note edge\u69CB\u9020\u4F53\u3092\u3055\u3089\u306B\
    \u5BA3\u8A00\u3057\u306A\u3044\u3053\u3068!!!\nstd::vector<long long> dijkstra(int\
    \ s,\n\tconst std::vector<std::vector<edge>>& g) {\n\tstd::vector<long long> dist(g.size(),\
    \ (long long)1e18);\n\tstd::priority_queue<std::pair<long long, int>, std::vector<std::pair<long\
    \ long, int>>, std::greater<std::pair<long long, int>>> que;\n\tque.emplace(0,\
    \ s);\n\tdist[s] = 0;\n\twhile (!que.empty()) {\n\t\tauto [d, v] = que.top();\n\
    \t\tque.pop();\n\t\tif (dist[v] != d) {\n\t\t\tcontinue;\n\t\t}\n\n\t\tfor (const\
    \ auto& [nv, c] : g[v]) {\n\t\t\tif (dist[v] + c < dist[nv]) {\n\t\t\t\tdist[nv]\
    \ = dist[v] + c;\n\t\t\t\tque.emplace(dist[nv], nv);\n\t\t\t}\n\t\t}\n\t}\n\t\
    return dist;\n}\n\n};  // namespace library"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/1_A.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
---
