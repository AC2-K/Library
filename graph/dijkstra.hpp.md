---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.hpp
    title: edge
  _extendedRequiredBy: []
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
    document_title: "dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\
      \u984C)"
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
    }\n///@brief dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C\
    )\n"
  code: "#pragma once\n#include\"edge.hpp\"\npair<vector<ll>,vector<int>> dijkstra(int\
    \ s,const vector<vector<edge>>&g){\n    vector<ll> dist(g.size(),infl);\n    vector<int>\
    \ pre(g.size(),-1);\n    using st=pair<ll,int>;\n    priority_queue<st,vector<st>,greater<st>>\
    \ que;\n    que.emplace(0,s);\n    dist[s]=0;\n    pre[s]=s;\n    while(!que.empty()){\n\
    \        auto[d,v]=que.top();\n        que.pop();\n        if(dist[v]!=d){\n \
    \           continue;\n        }\n\n        for(const auto&[nv,c]:g[v]){\n   \
    \         if(dist[v]+c<dist[nv]){\n                dist[nv]=dist[v]+c;\n     \
    \           pre[nv]=v;\n                que.emplace(dist[nv],nv);\n          \
    \  }\n        }\n    }\n    return make_pair(dist,pre);\n}\n///@brief dijkstra(\u5358\
    \u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C)"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-02-23 13:41:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Library-Checker/Tree Diameter.test.cpp
  - test/Library-Checker/Shortest Path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: "dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C)"
---
