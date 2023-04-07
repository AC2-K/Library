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
    document_title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n#include <queue>\n#include <vector>\n\
    \nstruct edge {\n\tint to;\n\tlong long cost;\n\tedge(int to, long long cost)\
    \ : to(to), cost(cost) {}\n};\n/// @brief Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\
    \u30E9\u6CD5)\nstd::pair<std::vector<long long>, std::vector<int>> dijkstra(int\
    \ s,\n\tconst std::vector<std::vector<edge>>& g) {\n\tstd::vector<long long> dist(g.size(),\
    \ infl);\n\tstd::vector<int> pre(g.size(), -1);\n\tstd::priority_queue<std::pair<long\
    \ long, int>,std::vector<std::pair<long long, int>>, std::greater<std::pair<long\
    \ long, int>>> que;\n\tque.emplace(0, s);\n\tdist[s] = 0;\n\tpre[s] = s;\n\twhile\
    \ (!que.empty()) {\n\t\tauto [d, v] = que.top();\n\t\tque.pop();\n\t\tif (dist[v]\
    \ != d) {\n\t\t\tcontinue;\n\t\t}\n\n\t\tfor (const auto& [nv, c] : g[v]) {\n\t\
    \t\tif (dist[v] + c < dist[nv]) {\n\t\t\t\tdist[nv] = dist[v] + c;\n\t\t\t\tpre[nv]\
    \ = v;\n\t\t\t\tque.emplace(dist[nv], nv);\n\t\t\t}\n\t\t}\n\t}\n\treturn { dist,\
    \ pre };\n}\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\n\nstruct edge {\n\tint\
    \ to;\n\tlong long cost;\n\tedge(int to, long long cost) : to(to), cost(cost)\
    \ {}\n};\n/// @brief Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\nstd::pair<std::vector<long\
    \ long>, std::vector<int>> dijkstra(int s,\n\tconst std::vector<std::vector<edge>>&\
    \ g) {\n\tstd::vector<long long> dist(g.size(), infl);\n\tstd::vector<int> pre(g.size(),\
    \ -1);\n\tstd::priority_queue<std::pair<long long, int>,std::vector<std::pair<long\
    \ long, int>>, std::greater<std::pair<long long, int>>> que;\n\tque.emplace(0,\
    \ s);\n\tdist[s] = 0;\n\tpre[s] = s;\n\twhile (!que.empty()) {\n\t\tauto [d, v]\
    \ = que.top();\n\t\tque.pop();\n\t\tif (dist[v] != d) {\n\t\t\tcontinue;\n\t\t\
    }\n\n\t\tfor (const auto& [nv, c] : g[v]) {\n\t\t\tif (dist[v] + c < dist[nv])\
    \ {\n\t\t\t\tdist[nv] = dist[v] + c;\n\t\t\t\tpre[nv] = v;\n\t\t\t\tque.emplace(dist[nv],\
    \ nv);\n\t\t\t}\n\t\t}\n\t}\n\treturn { dist, pre };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-04-07 18:51:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/1_A.test.cpp
  - test/yosupo_judge/tree/Tree_Diameter.test.cpp
  - test/yosupo_judge/graph/Shortest_Path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
---
