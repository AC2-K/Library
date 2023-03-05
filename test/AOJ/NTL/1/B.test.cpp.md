---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':x:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
  bundledCode: "#line 1 \"test/AOJ/NTL/1/B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconstexpr long double pi = acos(-1);\nconstexpr ll MOD = 1e9\
    \ + 7;\nconstexpr ll MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"math/mod_pow.hpp\"\
    \ntemplate <class T, class U = T>\nU mod_pow(T base, T exp, T mod){\n    if(base==0)return\
    \ 0;\n    T ans = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp\
    \ & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n     \
    \   base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)\n#line 5 \"test/AOJ/NTL/1/B.test.cpp\"\
    \n#line 3 \"main.cpp\"\nint main(){\n    int n,m;\n    cin>>n>>m;\n    cout<<mod_pow(n,m,MOD)<<'\\\
    n';\n}\n\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B\"\n\n\
    #include \"template.hpp\"\n#include \"math/mod_pow.hpp\"\n#line 3 \"main.cpp\"\
    \nint main(){\n    int n,m;\n    cin>>n>>m;\n    cout<<mod_pow(n,m,MOD)<<'\\n';\n\
    }\n\n"
  dependsOn:
  - template.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/AOJ/NTL/1/B.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 17:21:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/NTL/1/B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL/1/B.test.cpp
- /verify/test/AOJ/NTL/1/B.test.cpp.html
title: test/AOJ/NTL/1/B.test.cpp
---
