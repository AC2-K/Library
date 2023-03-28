---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/1/A.test.cpp
    title: test/AOJ/GRL/1/A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/graph/Shortest_Path.test.cpp
    title: test/yosupo_judge/graph/Shortest_Path.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/tree/Tree_Diameter.test.cpp
    title: test/yosupo_judge/tree/Tree_Diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n\n\nstruct edge {\n\tint to;\n\tll\
    \ cost;\n\tedge(int to, ll cost) : to(to), cost(cost) {}\n};\n/// @brief Dijkstra\
    \ (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n/// @note edge\u69CB\u9020\u4F53\
    \u3092\u3055\u3089\u306B\u5BA3\u8A00\u3057\u306A\u3044\u3053\u3068!!!\npair<vector<uint64_t>,\
    \ vector<int>> dijkstra(int s,\n\tconst vector<vector<edge>>& g) {\n\tvector<uint64_t>\
    \ dist(g.size(), infl);\n\tvector<int> pre(g.size(), -1);\n\tpriority_queue<pair<ll,\
    \ int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;\n\tque.emplace(0,\
    \ s);\n\tdist[s] = 0;\n\tpre[s] = s;\n\twhile (!que.empty()) {\n\t\tauto [d, v]\
    \ = que.top();\n\t\tque.pop();\n\t\tif (dist[v] != d) {\n\t\t\tcontinue;\n\t\t\
    }\n\n\t\tfor (const auto& [nv, c] : g[v]) {\n\t\t\tif (dist[v] + c < dist[nv])\
    \ {\n\t\t\t\tdist[nv] = dist[v] + c;\n\t\t\t\tpre[nv] = v;\n\t\t\t\tque.emplace(dist[nv],\
    \ nv);\n\t\t\t}\n\t\t}\n\t}\n\treturn { dist, pre };\n}\n"
  code: "#pragma once\n\n\nstruct edge {\n\tint to;\n\tll cost;\n\tedge(int to, ll\
    \ cost) : to(to), cost(cost) {}\n};\n/// @brief Dijkstra (\u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9\u6CD5)\n/// @note edge\u69CB\u9020\u4F53\u3092\u3055\u3089\u306B\u5BA3\
    \u8A00\u3057\u306A\u3044\u3053\u3068!!!\npair<vector<uint64_t>, vector<int>> dijkstra(int\
    \ s,\n\tconst vector<vector<edge>>& g) {\n\tvector<uint64_t> dist(g.size(), infl);\n\
    \tvector<int> pre(g.size(), -1);\n\tpriority_queue<pair<ll, int>, vector<pair<ll,\
    \ int>>, greater<pair<ll, int>>> que;\n\tque.emplace(0, s);\n\tdist[s] = 0;\n\t\
    pre[s] = s;\n\twhile (!que.empty()) {\n\t\tauto [d, v] = que.top();\n\t\tque.pop();\n\
    \t\tif (dist[v] != d) {\n\t\t\tcontinue;\n\t\t}\n\n\t\tfor (const auto& [nv, c]\
    \ : g[v]) {\n\t\t\tif (dist[v] + c < dist[nv]) {\n\t\t\t\tdist[nv] = dist[v] +\
    \ c;\n\t\t\t\tpre[nv] = v;\n\t\t\t\tque.emplace(dist[nv], nv);\n\t\t\t}\n\t\t\
    }\n\t}\n\treturn { dist, pre };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo_judge/graph/Shortest_Path.test.cpp
  - test/yosupo_judge/tree/Tree_Diameter.test.cpp
  - test/AOJ/GRL/1/A.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
---
