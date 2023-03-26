---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/ext_gcd.hpp
    title: "ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
      \u6CD5)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"test/AOJ/NTL/1/E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#line 2 \"src/template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"src/math/ext_gcd.hpp\"\nstatic constexpr ll ext_gcd(ll a, ll b, ll&\
    \ x, ll& y) {\n    ll u = 0, v = 1, q = 0, tmp = 0;\n    x = 1;\n    y = 0;\n\
    \    while (b) {\n        q = a / b;\n        tmp = u;\n        u = x - q * u;\n\
    \        x = tmp;\n        tmp = v;\n        v = y - q * v;\n        y = tmp;\n\
    \        tmp = b;\n        b = a - q * b;\n        a = tmp;\n    }\n    return\
    \ a;\n}\n/// @brief ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
    \u4E92\u9664\u6CD5)\n/// @return ax+by=gcd(a,b)\u306A\u308Bx,y\u3092\u683C\u7D0D\
    \u3059\u308B,\u8FD4\u308A\u5024\u306Bgcd(a,b)\n#line 5 \"test/AOJ/NTL/1/E.test.cpp\"\
    \n\nint main(){\n    int a,b;\n    cin>>a>>b;\n    ll x,y;\n    ext_gcd(a,b,x,y);\n\
    \    cout<<x<<' '<<y<<'\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include\"../../../../src/template.hpp\"\n#include\"../../../../src/math/ext_gcd.hpp\"\
    \n\nint main(){\n    int a,b;\n    cin>>a>>b;\n    ll x,y;\n    ext_gcd(a,b,x,y);\n\
    \    cout<<x<<' '<<y<<'\\n';\n}"
  dependsOn:
  - src/template.hpp
  - src/math/ext_gcd.hpp
  isVerificationFile: true
  path: test/AOJ/NTL/1/E.test.cpp
  requiredBy: []
  timestamp: '2023-03-27 02:22:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL/1/E.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL/1/E.test.cpp
- /verify/test/AOJ/NTL/1/E.test.cpp.html
title: test/AOJ/NTL/1/E.test.cpp
---
