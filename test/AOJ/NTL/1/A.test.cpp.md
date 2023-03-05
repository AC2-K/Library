---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/fact.hpp
    title: "factorize(\u7D20\u56E0\u6570\u5206\u89E3)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"test/AOJ/NTL/1/A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr ll MOD = 1e9 + 7;\n\
    constexpr ll MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"math/fact.hpp\"\
    \nvector<pair<ll, ll>> fact(ll n) {\n    vector<pair<ll, ll>> ret;\n    for (ll\
    \ div = 2; div * div <= n; div++) {\n        if (n % div != 0)continue;\n    \
    \    ll exp = 0;\n        while (n % div == 0) {\n            exp++;\n       \
    \     n /= div;\n        }\n        ret.push_back(make_pair(div, exp));\n    }\n\
    \    if (n != 1)ret.push_back(make_pair(n, 1));\n    return ret;\n}\n///@brief\
    \ factorize(\u7D20\u56E0\u6570\u5206\u89E3)\n#line 5 \"test/AOJ/NTL/1/A.test.cpp\"\
    \nint main(){\n    int n;\n    cin>>n;\n    auto res=fact(n);\n    cout<<n<<':';\n\
    \    for(const auto&[p,e]:res){\n        rep(i,e){\n            cout<<' '<<p;\n\
    \        }\n    }\n    cout<<'\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#include\"template.hpp\"\n#include\"math/fact.hpp\"\nint main(){\n    int\
    \ n;\n    cin>>n;\n    auto res=fact(n);\n    cout<<n<<':';\n    for(const auto&[p,e]:res){\n\
    \        rep(i,e){\n            cout<<' '<<p;\n        }\n    }\n    cout<<'\\\
    n';\n}"
  dependsOn:
  - template.hpp
  - math/fact.hpp
  isVerificationFile: true
  path: test/AOJ/NTL/1/A.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 19:36:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL/1/A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL/1/A.test.cpp
- /verify/test/AOJ/NTL/1/A.test.cpp.html
title: test/AOJ/NTL/1/A.test.cpp
---
