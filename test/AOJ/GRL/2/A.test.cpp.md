---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dsu.hpp
    title: disjoint set(union find)
  - icon: ':heavy_check_mark:'
    path: graph/mst.hpp
    title: "Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/AOJ/GRL/2/A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing ll = long long;\n//using i128=__int128_t;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps = 1e-6;\nconst\
    \ long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\n\
    const int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class\
    \ T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T\
    \ y){if(x>y)x=y;}\n#line 1 \"data-structure/dsu.hpp\"\nclass DSU {\nprivate:\n\
    \tvector<int> par, rank, siz;\n\tint N;\npublic:\n\tDSU(int n) : par(n, -1), rank(n,\
    \ 0), siz(n, 1), N(n) {}\n\n\tint root(int x) {\n\t\tif (par[x] == -1)\n\t\t\t\
    return x;\n\t\telse\n\t\t\treturn par[x] = root(par[x]);\n\t}\n\tbool same(int\
    \ x, int y) {\n\t\treturn root(x) == root(y);\n\t}\n\n\tbool merge(int x, int\
    \ y) {\n\t\tint rx = root(x), ry = root(y);\n\t\tif (rx == ry)\n\t\t\treturn false;\n\
    \n\t\tif (rank[rx] < rank[ry])\n\t\t\tswap(rx, ry);\n\t\tpar[ry] = rx;\n\n\t\t\
    siz[rx] += siz[ry];\n\t\treturn true;\n\t}\n\n\tint size(int x) {\n\t\treturn\
    \ siz[root(x)];\n\t}\n\tint group_size() {\n\t\tint cnt = 0;\n\t\tfor (int i =\
    \ 0; i < N; i++)\n\t\t\tif (root(i) == i)\n\t\t\t\tcnt++;\n\t\treturn cnt;\n\t\
    }\n};\n///@brief disjoint set(union find)\n#line 2 \"graph/mst.hpp\"\nclass MST{\n\
    \    DSU dsu;\n    struct Edge\n    {\n        int v1,v2;\n        int cost;\n\
    \        int id;\n        Edge(int v1,int v2,int cost,int id):v1(v1),v2(v2),cost(cost),id(id){\
    \  }\n    };\n    vector<Edge> E;\n    vector<int> V1,V2;\npublic:\n    MST(int\
    \ V):dsu(V){}\n    void add_edge(int a,int b,ll cost){\n        int sz=E.size();\n\
    \        E.emplace_back(a,b,cost,sz);\n        V1.emplace_back(a),V2.emplace_back(b);\n\
    \    }\n    ll result() {\n        sort(E.begin(), E.end(),[&](Edge e1,Edge e2){\n\
    \            return e1.cost<e2.cost;\n        });\n        ll ans = 0;\n     \
    \   rep(i, E.size()) {\n            int len = E[i].cost;\n            int id =\
    \ E[i].id;\n            int a = V1[id], b = V2[id];\n            if (dsu.same(a,\
    \ b))continue;\n            dsu.merge(a, b);\n            ans += len;\n      \
    \  }\n        return ans;\n    }\n};\n///@brief Minimum Spannning Tree(\u6700\u5C0F\
    \u5168\u57DF\u6728)\n#line 5 \"test/AOJ/GRL/2/A.test.cpp\"\n\nint main(){\n  \
    \  int n,m;\n    cin>>n>>m;\n    MST g(n);\n    rep(i,m){\n        int s,t,w;\n\
    \        cin>>s>>t>>w;\n        g.add_edge(s,t,w);\n    }\n\n    cout<<g.result()<<'\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include\"template.hpp\"\n#include\"graph/mst.hpp\"\n\nint main(){\n    int\
    \ n,m;\n    cin>>n>>m;\n    MST g(n);\n    rep(i,m){\n        int s,t,w;\n   \
    \     cin>>s>>t>>w;\n        g.add_edge(s,t,w);\n    }\n\n    cout<<g.result()<<'\\\
    n';\n}"
  dependsOn:
  - template.hpp
  - graph/mst.hpp
  - data-structure/dsu.hpp
  isVerificationFile: true
  path: test/AOJ/GRL/2/A.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 14:54:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL/2/A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL/2/A.test.cpp
- /verify/test/AOJ/GRL/2/A.test.cpp.html
title: test/AOJ/GRL/2/A.test.cpp
---
