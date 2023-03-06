---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: edge
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/1/A.test.cpp
    title: test/AOJ/GRL/1/A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/graph/Shortest Path.test.cpp
    title: test/yosupo judge/graph/Shortest Path.test.cpp
  - icon: ':x:'
    path: test/yosupo judge/tree/Tree Diameter.test.cpp
    title: test/yosupo judge/tree/Tree Diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
    links: []
  bundledCode: "#line 1 \"graph/edge.hpp\"\nstruct edge{\n    int to;\n    ll cost;\n\
    \    edge(int to,ll cost):to(to),cost(cost){}\n};\n///@brief edge\n#line 3 \"\
    graph/dijkstra.hpp\"\npair<vector<ll>,vector<int>> dijkstra(int s,const vector<vector<edge>>&g){\n\
    \    vector<ll> dist(g.size(),infl);\n    vector<int> pre(g.size(),-1);\n    using\
    \ st=pair<ll,int>;\n    priority_queue<st,vector<st>,greater<st>> que;\n    que.emplace(0,s);\n\
    \    dist[s]=0;\n    pre[s]=s;\n    while(!que.empty()){\n        auto[d,v]=que.top();\n\
    \        que.pop();\n        if(dist[v]!=d){\n            continue;\n        }\n\
    \n        for(const auto&[nv,c]:g[v]){\n            if(dist[v]+c<dist[nv]){\n\
    \                dist[nv]=dist[v]+c;\n                pre[nv]=v;\n           \
    \     que.emplace(dist[nv],nv);\n            }\n        }\n    }\n    return make_pair(dist,pre);\n\
    }\n///@brief dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n"
  code: "#pragma once\n#include\"edge.hpp\"\npair<vector<ll>,vector<int>> dijkstra(int\
    \ s,const vector<vector<edge>>&g){\n    vector<ll> dist(g.size(),infl);\n    vector<int>\
    \ pre(g.size(),-1);\n    using st=pair<ll,int>;\n    priority_queue<st,vector<st>,greater<st>>\
    \ que;\n    que.emplace(0,s);\n    dist[s]=0;\n    pre[s]=s;\n    while(!que.empty()){\n\
    \        auto[d,v]=que.top();\n        que.pop();\n        if(dist[v]!=d){\n \
    \           continue;\n        }\n\n        for(const auto&[nv,c]:g[v]){\n   \
    \         if(dist[v]+c<dist[nv]){\n                dist[nv]=dist[v]+c;\n     \
    \           pre[nv]=v;\n                que.emplace(dist[nv],nv);\n          \
    \  }\n        }\n    }\n    return make_pair(dist,pre);\n}\n///@brief dijkstra(\u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-03-06 04:18:20+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo judge/tree/Tree Diameter.test.cpp
  - test/yosupo judge/graph/Shortest Path.test.cpp
  - test/AOJ/GRL/1/A.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: "dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
---
