---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dsu.hpp
    title: disjoint set(union find)
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"test/AOJ/DSL/1/A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll\
    \ MOD2 = 998244353;\nconst int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1\
    \ };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class\
    \ T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/dsu.hpp\"\
    \nclass DSU {\nprivate:\n\tvector<int> par, rank, siz;\n\tint N;\npublic:\n\t\
    DSU(int n) : par(n, -1), rank(n, 0), siz(n, 1), N(n) {}\n\n\tint root(int x) {\n\
    \t\tif (par[x] == -1)\n\t\t\treturn x;\n\t\telse\n\t\t\treturn par[x] = root(par[x]);\n\
    \t}\n\tbool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t}\n\n\tbool\
    \ merge(int x, int y) {\n\t\tint rx = root(x), ry = root(y);\n\t\tif (rx == ry)\n\
    \t\t\treturn false;\n\n\t\tif (rank[rx] < rank[ry])\n\t\t\tswap(rx, ry);\n\t\t\
    par[ry] = rx;\n\n\t\tsiz[rx] += siz[ry];\n\t\treturn true;\n\t}\n\n\tint size(int\
    \ x) {\n\t\treturn siz[root(x)];\n\t}\n\tint group_size() {\n\t\tint cnt = 0;\n\
    \t\tfor (int i = 0; i < N; i++)\n\t\t\tif (root(i) == i)\n\t\t\t\tcnt++;\n\t\t\
    return cnt;\n\t}\n};\n///@brief disjoint set(union find)\n///@docs docs/data-structure/dsu.md\n\
    #line 5 \"test/AOJ/DSL/1/A.test.cpp\"\nint main(){\n    int n,q;\n    cin>>n>>q;\n\
    \    DSU dsu(n);\n    while(q--){\n        int t,x,y;\n        cin>>t>>x>>y;\n\
    \        if(t==0){\n            dsu.merge(x,y);\n        }else{\n            cout<<(dsu.same(x,y)?\"\
    1\\n\":\"0\\n\");\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include\"template.hpp\"\n#include\"data-structure/dsu.hpp\"\nint main(){\n\
    \    int n,q;\n    cin>>n>>q;\n    DSU dsu(n);\n    while(q--){\n        int t,x,y;\n\
    \        cin>>t>>x>>y;\n        if(t==0){\n            dsu.merge(x,y);\n     \
    \   }else{\n            cout<<(dsu.same(x,y)?\"1\\n\":\"0\\n\");\n        }\n\
    \    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/dsu.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/1/A.test.cpp
  requiredBy: []
  timestamp: '2023-02-28 20:50:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/1/A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/1/A.test.cpp
- /verify/test/AOJ/DSL/1/A.test.cpp.html
title: test/AOJ/DSL/1/A.test.cpp
---
