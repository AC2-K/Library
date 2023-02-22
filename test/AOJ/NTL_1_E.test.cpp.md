---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext_gcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
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
  bundledCode: "#line 1 \"test/AOJ/NTL_1_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing ll = long long;\n//using i128=__int128_t;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps = 1e-6;\nconst\
    \ long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\n\
    const int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class\
    \ T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T\
    \ y){if(x>y)x=y;}\n#line 1 \"math/ext_gcd.hpp\"\nll ext_gcd(ll a,ll b,ll&x,ll&y){\n\
    \    if(b==0){\n        x=1,y=0;\n        return a;\n    }else{\n        ll d=ext_gcd(b,a%b,y,x);\
    \    //\u9061\u308B\n        y-=a/b*x;\n        return d;\n    }\n}\n/// @brief\
    \ \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n///\
    \ @return ax+by=gcd(a,b)\u306A\u308Bx,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\
    \u5024\u306Bgcd(a,b)\n#line 5 \"test/AOJ/NTL_1_E.test.cpp\"\n\nint main(){\n \
    \   int a,b;\n    cin>>a>>b;\n    ll x,y;\n    ext_gcd(a,b,x,y);\n    cout<<x<<'\
    \ '<<y<<'\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include\"template.hpp\"\n#include\"math/ext_gcd.hpp\"\n\nint main(){\n  \
    \  int a,b;\n    cin>>a>>b;\n    ll x,y;\n    ext_gcd(a,b,x,y);\n    cout<<x<<'\
    \ '<<y<<'\\n';\n}"
  dependsOn:
  - template.hpp
  - math/ext_gcd.hpp
  isVerificationFile: true
  path: test/AOJ/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2023-02-21 13:24:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL_1_E.test.cpp
- /verify/test/AOJ/NTL_1_E.test.cpp.html
title: test/AOJ/NTL_1_E.test.cpp
---
