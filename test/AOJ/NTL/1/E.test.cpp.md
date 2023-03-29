---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/gcd.hpp
    title: "ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
      \u6CD5)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"test/AOJ/NTL/1/E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline\
    \ void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void\
    \ chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"math/gcd.hpp\"\ntemplate<class T>\nstatic\
    \ constexpr inline T _gcd(T a,T b){\n    T s = a, t = b;\n    while (s % t !=\
    \ 0) {\n        T u = s % t;\n\n        s = t;\n        t = u;\n    }\n    return\
    \ t;\n}\nstatic constexpr inline ll ext_gcd(ll a, ll b, ll &x, ll &y) {\n    x\
    \ = 1, y = 0;\n    ll nx = 0, ny = 1;\n    while(b) {\n        long long q = a\
    \ / b;\n        tie(a, b) = make_pair(b, a % b);\n        tie(x, nx) = make_pair(nx,\
    \ x - nx*q);\n        tie(y, ny) = make_pair(ny, y - ny*q);\n    }\n    return\
    \ a;\n}\n\n/// @brief ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
    \u306E\u4E92\u9664\u6CD5)\n/// @return ax+by=gcd(a,b)\u306A\u308Bx,y\u3092\u683C\
    \u7D0D\u3059\u308B,\u8FD4\u308A\u5024\u306Bgcd(a,b)\n#line 5 \"test/AOJ/NTL/1/E.test.cpp\"\
    \n\nint main(){\n    int a, b;\n    cin >> a >> b;\n    ll x, y;\n    ext_gcd(a,\
    \ b, x, y);\n    cout << x << ' ' << y << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include\"template.hpp\"\n#include\"math/gcd.hpp\"\n\nint main(){\n    int\
    \ a, b;\n    cin >> a >> b;\n    ll x, y;\n    ext_gcd(a, b, x, y);\n    cout\
    \ << x << ' ' << y << '\\n';\n}"
  dependsOn:
  - template.hpp
  - math/gcd.hpp
  isVerificationFile: true
  path: test/AOJ/NTL/1/E.test.cpp
  requiredBy: []
  timestamp: '2023-03-29 14:26:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL/1/E.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL/1/E.test.cpp
- /verify/test/AOJ/NTL/1/E.test.cpp.html
title: test/AOJ/NTL/1/E.test.cpp
---
