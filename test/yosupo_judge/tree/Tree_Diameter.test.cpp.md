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
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/yosupo_judge/tree/Tree_Diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#line 2 \"template.hpp\"\
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
    \ pre };\n}\n#line 4 \"test/yosupo_judge/tree/Tree_Diameter.test.cpp\"\n\nusing\
    \ namespace std;\nint main() {\n    int n;\n    cin>>n;\n    vector<vector<edge>>\
    \ g(n);\n    rep(i,n-1){\n        int a,b,c;\n        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n\
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
    template.hpp\"\n#include\"graph/dijkstra.hpp\"\n\nusing namespace std;\nint main()\
    \ {\n    int n;\n    cin>>n;\n    vector<vector<edge>> g(n);\n    rep(i,n-1){\n\
    \        int a,b,c;\n        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n\
    \        g[b].emplace_back(a,c);\n    }\n\n    auto dist=dijkstra(0,g).first;\n\
    \    ll dist_max=*max_element(all(dist));\n    int v=find(all(dist),dist_max)-dist.begin();\n\
    \    dist=dijkstra(v,g).first;\n    dist_max=*max_element(all(dist));\n    int\
    \ u=find(all(dist),dist_max)-dist.begin();\n    cout<<dist_max<<' ';\n\n    int\
    \ cur=u;\n    vector<int> ans;\n    while(cur!=v){\n        ans.emplace_back(cur);\n\
    \        for(auto&[p,c]:g[cur]){\n            if(dist[p]+c==dist[cur]){\n    \
    \            cur=p;\n                break;\n            }\n        }\n    }\n\
    \    ans.emplace_back(v);\n    cout<<ans.size()<<'\\n';\n    for(auto&k:ans)cout<<k<<'\
    \ ';\n    cout<<'\\n';\n}"
  dependsOn:
  - template.hpp
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/yosupo_judge/tree/Tree_Diameter.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 14:59:40+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Tree_Diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Tree_Diameter.test.cpp
- /verify/test/yosupo_judge/tree/Tree_Diameter.test.cpp.html
title: test/yosupo_judge/tree/Tree_Diameter.test.cpp
---
