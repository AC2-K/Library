---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_check.hpp
    title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C
  bundledCode: "#line 1 \"test/AOJ/ALDS/1/C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C\"\
    \n\n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing ll = long long;\n//using i128=__int128_t;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps = 1e-6;\nconst\
    \ long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\n\
    const int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class\
    \ T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T\
    \ y){if(x>y)x=y;}\n#line 1 \"math/prime_check.hpp\"\nvector<bool> prime_checker(int\
    \ N) {\n    vector<bool> primes(N + 1, true);\n\n    primes[0] = false;\n    primes[1]\
    \ = false;\n\n    for (int p = 2; p <= N; ++p) {\n        if (!primes[p]) continue;\n\
    \        for (int i = 2; p * i <= N; i++) {\n            primes[p * i] = false;\n\
    \        }\n    }\n\n    return primes;\n}\n///@brief \u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9\n#line 6 \"test/AOJ/ALDS/1/C.test.cpp\"\n\nint\
    \ main(){\n    constexpr int INPUT_MAX = 100000000;\n    const auto&res = prime_checker(INPUT_MAX);\n\
    \n    int n;\n    scanf(\"%d\",&n);\n    int ans = 0;\n    while(n--){\n     \
    \   int p;\n        scanf(\"%d\",&p);\n        if(res[p]){\n            ans++;\n\
    \        }\n    }\n    printf(\"%d\\n\",ans);\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C\"\
    \n\n\n#include\"template.hpp\"\n#include\"math/prime_check.hpp\"\n\nint main(){\n\
    \    constexpr int INPUT_MAX = 100000000;\n    const auto&res = prime_checker(INPUT_MAX);\n\
    \n    int n;\n    scanf(\"%d\",&n);\n    int ans = 0;\n    while(n--){\n     \
    \   int p;\n        scanf(\"%d\",&p);\n        if(res[p]){\n            ans++;\n\
    \        }\n    }\n    printf(\"%d\\n\",ans);\n}"
  dependsOn:
  - template.hpp
  - math/prime_check.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS/1/C.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 14:54:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS/1/C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS/1/C.test.cpp
- /verify/test/AOJ/ALDS/1/C.test.cpp.html
title: test/AOJ/ALDS/1/C.test.cpp
---
