---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/DLP.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u6CD5"
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
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/Library-Checker/Discrete Logarithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n#line 1\
    \ \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i,\
    \ N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing ll = long long;\n//using i128=__int128_t;\nusing\
    \ ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int, int>;\n\
    const int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps = 1e-6;\nconst long\
    \ double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\n\
    const int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class\
    \ T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T\
    \ y){if(x>y)x=y;}\n#line 1 \"math/mod_pow.hpp\"\nll mod_pow(ll base, ll exp, ll\
    \ mod) {\n    if(base==0)return 0;\n    ll ans = 1;\n    base %= mod;\n    while\
    \ (exp > 0) {\n        if (exp & 1) {\n            ans *= base;\n            ans\
    \ %= mod;\n        }\n        base *= base;\n        base %= mod;\n        exp\
    \ >>= 1;\n    }\n    return ans;\n}\n///@brief \u30D0\u30A4\u30CA\u30EA\u6CD5\n\
    #line 3 \"math/DLP.hpp\"\n\nll dlp(ll x, ll y, ll p) {\n    if (y == 1 || p ==\
    \ 1) {\n        return 0;\n    }\n    if (x == 0) {\n        if (y == 0) {\n \
    \           return 1;\n        }\n        else {\n            return -1;\n   \
    \     }\n    }\n    ll m = sqrt(p) + 1;\n    unordered_map<ll, int> mp;\n    ll\
    \ xm = mod_pow(x, m, p);\n    ll add = 0, g, k = 1 % p;\n    while ((g = gcd(x,\
    \ p)) > 1) {\n        if (y == k)return add;\n        if (y % g)return -1;\n \
    \       y /= g, p /= g, add++;\n        k = (k * (x / g)) % p;\n    }\n    ll\
    \ pr = y;\n    for (int j = 0; j <= m; j++) {\n        mp[pr] = j;\n        (pr\
    \ *= x) %= p;\n    }\n    pr = k;\n    for (int i = 1; i <= m; i++) {\n      \
    \  (pr *= xm) %= p;\n        if (mp.find(pr) != mp.end()) {\n            int j\
    \ = mp[pr];\n            return m * i - j + add;\n        }\n    }\n    return\
    \ -1;\n}\n///@brief \u96E2\u6563\u5BFE\u6570\n#line 4 \"test/Library-Checker/Discrete\
    \ Logarithm.test.cpp\"\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n\
    \    int t;\n    cin>>t;\n    while(t--){\n        int x,y,p;\n        cin>>x>>y>>p;\n\
    \        cout<<dlp(x,y,p)<<'\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include\"template.hpp\"\n#include\"math/DLP.hpp\"\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    int t;\n    cin>>t;\n    while(t--){\n        int x,y,p;\n\
    \        cin>>x>>y>>p;\n        cout<<dlp(x,y,p)<<'\\n';\n    }\n}"
  dependsOn:
  - template.hpp
  - math/DLP.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/Library-Checker/Discrete Logarithm.test.cpp
  requiredBy: []
  timestamp: '2023-02-21 13:24:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Library-Checker/Discrete Logarithm.test.cpp
layout: document
redirect_from:
- /verify/test/Library-Checker/Discrete Logarithm.test.cpp
- /verify/test/Library-Checker/Discrete Logarithm.test.cpp.html
title: test/Library-Checker/Discrete Logarithm.test.cpp
---
