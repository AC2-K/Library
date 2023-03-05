---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/dijkstra.hpp
    title: "dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  - icon: ':question:'
    path: graph/edge.hpp
    title: edge
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/yosupo judge/tree/Tree Diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = vector<vector<int>>;\nusing P = pair<int, int>;\nconstexpr int inf =\
    \ 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long double\
    \ pi = acos(-1);\nconstexpr ll MOD = 1e9 + 7;\nconstexpr ll MOD2 = 998244353;\n\
    constexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class\
    \ T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T\
    \ y){if(x>y)x=y;}\n#line 1 \"graph/edge.hpp\"\nstruct edge{\n    int to;\n   \
    \ ll cost;\n    edge(int to,ll cost):to(to),cost(cost){}\n};\n///@brief edge\n\
    #line 3 \"graph/dijkstra.hpp\"\npair<vector<ll>,vector<int>> dijkstra(int s,const\
    \ vector<vector<edge>>&g){\n    vector<ll> dist(g.size(),infl);\n    vector<int>\
    \ pre(g.size(),-1);\n    using st=pair<ll,int>;\n    priority_queue<st,vector<st>,greater<st>>\
    \ que;\n    que.emplace(0,s);\n    dist[s]=0;\n    pre[s]=s;\n    while(!que.empty()){\n\
    \        auto[d,v]=que.top();\n        que.pop();\n        if(dist[v]!=d){\n \
    \           continue;\n        }\n\n        for(const auto&[nv,c]:g[v]){\n   \
    \         if(dist[v]+c<dist[nv]){\n                dist[nv]=dist[v]+c;\n     \
    \           pre[nv]=v;\n                que.emplace(dist[nv],nv);\n          \
    \  }\n        }\n    }\n    return make_pair(dist,pre);\n}\n///@brief dijkstra(\u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n#line 4 \"test/yosupo judge/tree/Tree Diameter.test.cpp\"\
    \nint main() {\n    int n;\n    cin>>n;\n    vector<vector<edge>> g(n);\n    rep(i,n-1){\n\
    \        int a,b,c;\n        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n\
    \        g[b].emplace_back(a,c);\n    }\n\n    auto dist=dijkstra(0,g).first;\n\
    \    ll dist_max=*max_element(all(dist));\n    int v=find(all(dist),dist_max)-dist.begin();\n\
    \    dist=dijkstra(v,g).first;\n    dist_max=*max_element(all(dist));\n    int\
    \ u=find(all(dist),dist_max)-dist.begin();\n    cout<<dist_max<<' ';\n\n    int\
    \ cur=u;\n    vector<int> ans;\n    while(cur!=v){\n        ans.emplace_back(cur);\n\
    \        for(auto&[p,c]:g[cur]){\n            if(dist[p]+c==dist[cur]){\n    \
    \            cur=p;\n                break;\n            }\n        }\n    }\n\
    \    ans.emplace_back(v);\n    cout<<ans.size()<<'\\n';\n    for(auto&k:ans)cout<<k<<'\
    \ ';\n    cout<<'\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\"\
    template.hpp\"\n#include\"graph/dijkstra.hpp\"\nint main() {\n    int n;\n   \
    \ cin>>n;\n    vector<vector<edge>> g(n);\n    rep(i,n-1){\n        int a,b,c;\n\
    \        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n        g[b].emplace_back(a,c);\n\
    \    }\n\n    auto dist=dijkstra(0,g).first;\n    ll dist_max=*max_element(all(dist));\n\
    \    int v=find(all(dist),dist_max)-dist.begin();\n    dist=dijkstra(v,g).first;\n\
    \    dist_max=*max_element(all(dist));\n    int u=find(all(dist),dist_max)-dist.begin();\n\
    \    cout<<dist_max<<' ';\n\n    int cur=u;\n    vector<int> ans;\n    while(cur!=v){\n\
    \        ans.emplace_back(cur);\n        for(auto&[p,c]:g[cur]){\n           \
    \ if(dist[p]+c==dist[cur]){\n                cur=p;\n                break;\n\
    \            }\n        }\n    }\n    ans.emplace_back(v);\n    cout<<ans.size()<<'\\\
    n';\n    for(auto&k:ans)cout<<k<<' ';\n    cout<<'\\n';\n}"
  dependsOn:
  - template.hpp
  - graph/dijkstra.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/yosupo judge/tree/Tree Diameter.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 19:36:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo judge/tree/Tree Diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/tree/Tree Diameter.test.cpp
- /verify/test/yosupo judge/tree/Tree Diameter.test.cpp.html
title: test/yosupo judge/tree/Tree Diameter.test.cpp
---
