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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/Library-Checker/Shortest Path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 1 \"template.hpp\"\n\
    #include<bits/stdc++.h>\nusing namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using ll = long long;\n//using i128=__int128_t;\nusing ld = long double;\nusing\
    \ graph = vector<vector<int>>;\nusing P = pair<int, int>;\nconst int inf = 1e9;\n\
    const ll infl = 1e18;\nconst ld eps = 1e-6;\nconst long double pi = acos(-1);\n\
    const ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\nconst int dx[4] = { 1,0,-1,0\
    \ };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"graph/edge.hpp\"\nstruct edge{\n    int to;\n    ll cost;\n    edge(int\
    \ to,ll cost):to(to),cost(cost){}\n};\n///@brief edge\n#line 3 \"graph/dijkstra.hpp\"\
    \npair<vector<ll>,vector<int>> dijkstra(int s,const vector<vector<edge>>&g){\n\
    \    vector<ll> dist(g.size(),infl);\n    vector<int> pre(g.size(),-1);\n    using\
    \ st=pair<ll,int>;\n    priority_queue<st,vector<st>,greater<st>> que;\n    que.emplace(0,s);\n\
    \    dist[s]=0;\n    pre[s]=s;\n    while(!que.empty()){\n        auto[d,v]=que.top();\n\
    \        que.pop();\n        if(dist[v]!=d){\n            continue;\n        }\n\
    \n        for(const auto&[nv,c]:g[v]){\n            if(dist[v]+c<dist[nv]){\n\
    \                dist[nv]=dist[v]+c;\n                pre[nv]=v;\n           \
    \     que.emplace(dist[nv],nv);\n            }\n        }\n    }\n    return make_pair(dist,pre);\n\
    }\n///@brief dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u554F\u984C\
    )\n#line 4 \"test/Library-Checker/Shortest Path.test.cpp\"\nint main() {\n   \
    \ int n,m,s,t;\n    cin>>n>>m>>s>>t;\n    vector<vector<edge>> g(n);\n    rep(i,m){\n\
    \        int a,b,c;\n        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n\
    \    }\n    auto [dist,trace]=dijkstra(s,g);\n    if(dist[t]>=infl){\n       \
    \ cout<<-1<<'\\n';\n        return 0;\n    }\n\n    int cur=t;\n    vector<int>\
    \ path;\n    while(cur!=trace[cur]){\n        path.emplace_back(cur);\n      \
    \  cur=trace[cur];\n    }\n\n    path.emplace_back(cur);\n    cout<<dist[t]<<'\
    \ '<<path.size()-1<<'\\n';\n    reverse(all(path));\n    for(int i=1;i<path.size();i++){\n\
    \        cout<<path[i-1]<<' '<<path[i]<<'\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\"\
    template.hpp\"\n#include\"graph/dijkstra.hpp\"\nint main() {\n    int n,m,s,t;\n\
    \    cin>>n>>m>>s>>t;\n    vector<vector<edge>> g(n);\n    rep(i,m){\n       \
    \ int a,b,c;\n        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n    }\n\
    \    auto [dist,trace]=dijkstra(s,g);\n    if(dist[t]>=infl){\n        cout<<-1<<'\\\
    n';\n        return 0;\n    }\n\n    int cur=t;\n    vector<int> path;\n    while(cur!=trace[cur]){\n\
    \        path.emplace_back(cur);\n        cur=trace[cur];\n    }\n\n    path.emplace_back(cur);\n\
    \    cout<<dist[t]<<' '<<path.size()-1<<'\\n';\n    reverse(all(path));\n    for(int\
    \ i=1;i<path.size();i++){\n        cout<<path[i-1]<<' '<<path[i]<<'\\n';\n   \
    \ }\n}"
  dependsOn:
  - template.hpp
  - graph/dijkstra.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/Library-Checker/Shortest Path.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 13:41:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Library-Checker/Shortest Path.test.cpp
layout: document
redirect_from:
- /verify/test/Library-Checker/Shortest Path.test.cpp
- /verify/test/Library-Checker/Shortest Path.test.cpp.html
title: test/Library-Checker/Shortest Path.test.cpp
---
