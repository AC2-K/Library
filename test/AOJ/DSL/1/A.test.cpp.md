---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/dsu.hpp
    title: Disjoint Set(Union find)
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
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
    \n\n#line 2 \"src/template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"src/data-structure/dsu.hpp\"\n/// @brief Disjoint Set(Union find)\n\
    /// @docs docs/data-structure/dsu.md\nclass DSU {\nprivate:\n\tvector<int> par,\
    \ rank, siz;\n\tint N;\npublic:\n\tDSU(int n) : par(n, -1), rank(n, 0), siz(n,\
    \ 1), N(n) {}\n\n\tint root(int x) {\n\t\tif (par[x] == -1)\n\t\t\treturn x;\n\
    \t\telse\n\t\t\treturn par[x] = root(par[x]);\n\t}\n\tbool same(int x, int y)\
    \ {\n\t\treturn root(x) == root(y);\n\t}\n\n\tbool merge(int x, int y) {\n\t\t\
    int rx = root(x), ry = root(y);\n\t\tif (rx == ry)\n\t\t\treturn false;\n\n\t\t\
    if (rank[rx] < rank[ry])\n\t\t\tswap(rx, ry);\n\t\tpar[ry] = rx;\n\n\t\tsiz[rx]\
    \ += siz[ry];\n\t\treturn true;\n\t}\n\n\tint size(int x) {\n\t\treturn siz[root(x)];\n\
    \t}\n\tint group_size() {\n\t\tint cnt = 0;\n\t\tfor (int i = 0; i < N; i++)\n\
    \t\t\tif (root(i) == i)\n\t\t\t\tcnt++;\n\t\treturn cnt;\n\t}\n};\n#line 5 \"\
    test/AOJ/DSL/1/A.test.cpp\"\nint main(){\n    int n,q;\n    cin>>n>>q;\n    DSU\
    \ dsu(n);\n    while(q--){\n        int t,x,y;\n        cin>>t>>x>>y;\n      \
    \  if(t==0){\n            dsu.merge(x,y);\n        }else{\n            cout<<(dsu.same(x,y)?\"\
    1\\n\":\"0\\n\");\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include\"../../../../src/template.hpp\"\n#include\"../../../../src/data-structure/dsu.hpp\"\
    \nint main(){\n    int n,q;\n    cin>>n>>q;\n    DSU dsu(n);\n    while(q--){\n\
    \        int t,x,y;\n        cin>>t>>x>>y;\n        if(t==0){\n            dsu.merge(x,y);\n\
    \        }else{\n            cout<<(dsu.same(x,y)?\"1\\n\":\"0\\n\");\n      \
    \  }\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/data-structure/dsu.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/1/A.test.cpp
  requiredBy: []
  timestamp: '2023-03-27 02:22:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/1/A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/1/A.test.cpp
- /verify/test/AOJ/DSL/1/A.test.cpp.html
title: test/AOJ/DSL/1/A.test.cpp
---
