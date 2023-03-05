---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dijkstra.hpp
    title: "dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  - icon: ':x:'
    path: graph/edge.hpp
    title: edge
  - icon: ':x:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
  bundledCode: "#line 1 \"test/AOJ/GRL/1/A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconstexpr long double pi = acos(-1);\nconstexpr ll MOD = 1e9\
    \ + 7;\nconstexpr ll MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"graph/edge.hpp\"\
    \nstruct edge{\n    int to;\n    ll cost;\n    edge(int to,ll cost):to(to),cost(cost){}\n\
    };\n///@brief edge\n#line 3 \"graph/dijkstra.hpp\"\npair<vector<ll>,vector<int>>\
    \ dijkstra(int s,const vector<vector<edge>>&g){\n    vector<ll> dist(g.size(),infl);\n\
    \    vector<int> pre(g.size(),-1);\n    using st=pair<ll,int>;\n    priority_queue<st,vector<st>,greater<st>>\
    \ que;\n    que.emplace(0,s);\n    dist[s]=0;\n    pre[s]=s;\n    while(!que.empty()){\n\
    \        auto[d,v]=que.top();\n        que.pop();\n        if(dist[v]!=d){\n \
    \           continue;\n        }\n\n        for(const auto&[nv,c]:g[v]){\n   \
    \         if(dist[v]+c<dist[nv]){\n                dist[nv]=dist[v]+c;\n     \
    \           pre[nv]=v;\n                que.emplace(dist[nv],nv);\n          \
    \  }\n        }\n    }\n    return make_pair(dist,pre);\n}\n///@brief dijkstra(\u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n#line 5 \"test/AOJ/GRL/1/A.test.cpp\"\n\
    \nint main(){\n    int n,m,r;\n    cin>>n>>m>>r;\n    vector<vector<edge>> g(n);\n\
    \    rep(i,m){\n        int s,t,w;\n        cin>>s>>t>>w;\n        g[s].emplace_back(t,w);\n\
    \    }\n\n    auto res=dijkstra(r,g).first;\n\n    rep(v,n){\n        if(res[v]>=infl)cout<<\"\
    INF\\n\";\n        else cout<<res[v]<<'\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\"\
    \n\n#include\"template.hpp\"\n#include\"graph/dijkstra.hpp\"\n\nint main(){\n\
    \    int n,m,r;\n    cin>>n>>m>>r;\n    vector<vector<edge>> g(n);\n    rep(i,m){\n\
    \        int s,t,w;\n        cin>>s>>t>>w;\n        g[s].emplace_back(t,w);\n\
    \    }\n\n    auto res=dijkstra(r,g).first;\n\n    rep(v,n){\n        if(res[v]>=infl)cout<<\"\
    INF\\n\";\n        else cout<<res[v]<<'\\n';\n    }\n}"
  dependsOn:
  - template.hpp
  - graph/dijkstra.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/AOJ/GRL/1/A.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 17:53:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL/1/A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL/1/A.test.cpp
- /verify/test/AOJ/GRL/1/A.test.cpp.html
title: test/AOJ/GRL/1/A.test.cpp
---
