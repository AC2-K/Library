---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/dijkstra.hpp
    title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo_judge/graph/Shortest_Path.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = vector<vector<int>>;\nusing P = pair<int, int>;\nconstexpr int inf =\
    \ 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long double\
    \ pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 =\
    \ 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] = { 0,1,0,-1\
    \ };\ntemplate<class T>static constexpr inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n#line\
    \ 4 \"graph/dijkstra.hpp\"\nstruct edge {\n    int to;\n    long long cost;\n\
    \    edge(int to, long long cost) : to(to), cost(cost) {}\n};\n/// @brief Dijkstra\
    \ (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n/// @note edge\u69CB\u9020\u4F53\
    \u3092\u3055\u3089\u306B\u5BA3\u8A00\u3057\u306A\u3044\u3053\u3068!!!\nstd::vector<long\
    \ long> dijkstra(int s, const std::vector<std::vector<edge>>& g) {\n    std::vector<long\
    \ long> dist(g.size(), (long long)1e18);\n    std::priority_queue<std::pair<long\
    \ long, int>,\n                        std::vector<std::pair<long long, int>>,\n\
    \                        std::greater<std::pair<long long, int>>>\n        que;\n\
    \    que.emplace(0, s);\n    dist[s] = 0;\n    while (!que.empty()) {\n      \
    \  auto [d, v] = que.top();\n        que.pop();\n        if (dist[v] != d) {\n\
    \            continue;\n        }\n        for (const auto& [nv, c] : g[v]) {\n\
    \            if (dist[v] + c < dist[nv]) {\n                dist[nv] = dist[v]\
    \ + c;\n                que.emplace(dist[nv], nv);\n            }\n        }\n\
    \    }\n    return dist;\n}\n#line 4 \"test/yosupo_judge/graph/Shortest_Path.test.cpp\"\
    \nint main() {\n    int n,m,s,t;\n    cin>>n>>m>>s>>t;\n    vector<vector<edge>>\
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
  path: test/yosupo_judge/graph/Shortest_Path.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 13:50:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/graph/Shortest_Path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp.html
title: test/yosupo_judge/graph/Shortest_Path.test.cpp
---
