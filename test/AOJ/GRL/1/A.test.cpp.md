---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/dijkstra.hpp
    title: "dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C)"
  - icon: ':question:'
    path: graph/edge.hpp
    title: edge
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
  bundledCode: "#line 1 \"test/AOJ/GRL/1/A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll\
    \ MOD2 = 998244353;\nconst int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1\
    \ };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class\
    \ T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"graph/edge.hpp\"\nstruct\
    \ edge{\n    int to;\n    ll cost;\n    edge(int to,ll cost):to(to),cost(cost){}\n\
    };\n///@brief edge\n#line 3 \"graph/dijkstra.hpp\"\npair<vector<ll>,vector<int>>\
    \ dijkstra(int s,const vector<vector<edge>>&g){\n    vector<ll> dist(g.size(),infl);\n\
    \    vector<int> pre(g.size(),-1);\n    using st=pair<ll,int>;\n    priority_queue<st,vector<st>,greater<st>>\
    \ que;\n    que.emplace(0,s);\n    dist[s]=0;\n    pre[s]=s;\n    while(!que.empty()){\n\
    \        auto[d,v]=que.top();\n        que.pop();\n        if(dist[v]!=d){\n \
    \           continue;\n        }\n\n        for(const auto&[nv,c]:g[v]){\n   \
    \         if(dist[v]+c<dist[nv]){\n                dist[nv]=dist[v]+c;\n     \
    \           pre[nv]=v;\n                que.emplace(dist[nv],nv);\n          \
    \  }\n        }\n    }\n    return make_pair(dist,pre);\n}\n///@brief dijkstra(\u5358\
    \u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C)\n#line 5 \"test/AOJ/GRL/1/A.test.cpp\"\
    \n\nint main(){\n    int n,m,r;\n    cin>>n>>m>>r;\n    vector<vector<edge>> g(n);\n\
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
  timestamp: '2023-02-28 13:51:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL/1/A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL/1/A.test.cpp
- /verify/test/AOJ/GRL/1/A.test.cpp.html
title: test/AOJ/GRL/1/A.test.cpp
---
