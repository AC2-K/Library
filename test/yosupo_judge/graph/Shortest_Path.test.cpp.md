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
  bundledCode: "#line 1 \"test/yosupo_judge/graph/Shortest_Path.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\n#define rep(i, N) for (int i = 0; i < (N); i++)\n#define\
    \ all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\nusing\
    \ i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing graph\
    \ = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long\
    \ double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t\
    \ MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] =\
    \ { 0,1,0,-1 };\ntemplate<class T>constexpr inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 4 \"\
    graph/dijkstra.hpp\"\n\nstruct edge {\n\tint to;\n\tlong long cost;\n\tedge(int\
    \ to, long long cost) : to(to), cost(cost) {}\n};\n/// @brief Dijkstra (\u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\nstd::pair<std::vector<long long>, std::vector<int>>\
    \ dijkstra(int s,\n\tconst std::vector<std::vector<edge>>& g) {\n\tstd::vector<long\
    \ long> dist(g.size(), infl);\n\tstd::vector<int> pre(g.size(), -1);\n\tstd::priority_queue<std::pair<long\
    \ long, int>,std::vector<std::pair<long long, int>>, std::greater<std::pair<long\
    \ long, int>>> que;\n\tque.emplace(0, s);\n\tdist[s] = 0;\n\tpre[s] = s;\n\twhile\
    \ (!que.empty()) {\n\t\tauto [d, v] = que.top();\n\t\tque.pop();\n\t\tif (dist[v]\
    \ != d) {\n\t\t\tcontinue;\n\t\t}\n\n\t\tfor (const auto& [nv, c] : g[v]) {\n\t\
    \t\tif (dist[v] + c < dist[nv]) {\n\t\t\t\tdist[nv] = dist[v] + c;\n\t\t\t\tpre[nv]\
    \ = v;\n\t\t\t\tque.emplace(dist[nv], nv);\n\t\t\t}\n\t\t}\n\t}\n\treturn { dist,\
    \ pre };\n}\n#line 4 \"test/yosupo_judge/graph/Shortest_Path.test.cpp\"\nusing\
    \ namespace std;\nint main() {\n    int n,m,s,t;\n    cin>>n>>m>>s>>t;\n    vector<vector<edge>>\
    \ g(n);\n    rep(i,m){\n        int a,b,c;\n        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n\
    \    }\n    auto [dist,trace]=dijkstra(s,g);\n    if(dist[t]>=infl){\n       \
    \ cout<<-1<<'\\n';\n        return 0;\n    }\n\n    int cur=t;\n    vector<int>\
    \ path;\n    while(cur!=trace[cur]){\n        path.emplace_back(cur);\n      \
    \  cur=trace[cur];\n    }\n\n    path.emplace_back(cur);\n    cout<<dist[t]<<'\
    \ '<<path.size()-1<<'\\n';\n    reverse(all(path));\n    for(int i=1;i<path.size();i++){\n\
    \        cout<<path[i-1]<<' '<<path[i]<<'\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\"\
    template.hpp\"\n#include\"graph/dijkstra.hpp\"\nusing namespace std;\nint main()\
    \ {\n    int n,m,s,t;\n    cin>>n>>m>>s>>t;\n    vector<vector<edge>> g(n);\n\
    \    rep(i,m){\n        int a,b,c;\n        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n\
    \    }\n    auto [dist,trace]=dijkstra(s,g);\n    if(dist[t]>=infl){\n       \
    \ cout<<-1<<'\\n';\n        return 0;\n    }\n\n    int cur=t;\n    vector<int>\
    \ path;\n    while(cur!=trace[cur]){\n        path.emplace_back(cur);\n      \
    \  cur=trace[cur];\n    }\n\n    path.emplace_back(cur);\n    cout<<dist[t]<<'\
    \ '<<path.size()-1<<'\\n';\n    reverse(all(path));\n    for(int i=1;i<path.size();i++){\n\
    \        cout<<path[i-1]<<' '<<path[i]<<'\\n';\n    }\n}"
  dependsOn:
  - template.hpp
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/yosupo_judge/graph/Shortest_Path.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 14:59:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/graph/Shortest_Path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp.html
title: test/yosupo_judge/graph/Shortest_Path.test.cpp
---
