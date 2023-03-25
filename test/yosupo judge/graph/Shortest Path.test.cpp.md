---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/yosupo judge/graph/Shortest Path.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = vector<vector<int>>;\nusing P = pair<int, int>;\nconstexpr int inf =\
    \ 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long double\
    \ pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 =\
    \ 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] = { 0,1,0,-1\
    \ };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class\
    \ T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 2 \"graph/dijkstra.hpp\"\n\n\
    \nstruct edge {\n\tint to;\n\tll cost;\n\tedge(int to, ll cost) : to(to), cost(cost)\
    \ {}\n};\n/// @brief Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n///\
    \ @note edge\u69CB\u9020\u4F53\u3092\u3055\u3089\u306B\u5BA3\u8A00\u3057\u306A\
    \u3044\u3053\u3068!!!\npair<vector<uint64_t>, vector<int>> dijkstra(int s,\n\t\
    const vector<vector<edge>>& g) {\n\tvector<uint64_t> dist(g.size(), infl);\n\t\
    vector<int> pre(g.size(), -1);\n\tpriority_queue<pair<ll, int>, vector<pair<ll,\
    \ int>>, greater<pair<ll, int>>> que;\n\tque.emplace(0, s);\n\tdist[s] = 0;\n\t\
    pre[s] = s;\n\twhile (!que.empty()) {\n\t\tauto [d, v] = que.top();\n\t\tque.pop();\n\
    \t\tif (dist[v] != d) {\n\t\t\tcontinue;\n\t\t}\n\n\t\tfor (const auto& [nv, c]\
    \ : g[v]) {\n\t\t\tif (dist[v] + c < dist[nv]) {\n\t\t\t\tdist[nv] = dist[v] +\
    \ c;\n\t\t\t\tpre[nv] = v;\n\t\t\t\tque.emplace(dist[nv], nv);\n\t\t\t}\n\t\t\
    }\n\t}\n\treturn { dist, pre };\n}\n#line 4 \"test/yosupo judge/graph/Shortest\
    \ Path.test.cpp\"\nint main() {\n    int n,m,s,t;\n    cin>>n>>m>>s>>t;\n    vector<vector<edge>>\
    \ g(n);\n    rep(i,m){\n        int a,b,c;\n        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n\
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
  isVerificationFile: true
  path: test/yosupo judge/graph/Shortest Path.test.cpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/graph/Shortest Path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/graph/Shortest Path.test.cpp
- /verify/test/yosupo judge/graph/Shortest Path.test.cpp.html
title: test/yosupo judge/graph/Shortest Path.test.cpp
---
