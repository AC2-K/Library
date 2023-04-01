---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/DLP.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/gcd.hpp
    title: "gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306A\
      \u3069)"
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)"
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
  bundledCode: "#line 1 \"test/yosupo_judge/math/Discrete_Logarithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n#line 2\
    \ \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i,\
    \ N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int, int>;\n\
    constexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\n\
    const long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr\
    \ uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int\
    \ dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 2 \"math/mod_pow.hpp\"\ntemplate <class T, class U = T>\nconstexpr T mod_pow(T\
    \ base, T exp, T mod){\n    U ans = 1;\n    base %= mod;\n    while (exp) {\n\
    \        if (exp & 1) {\n            ans *= base;\n            ans %= mod;\n \
    \       }\n        base *= base;\n        base %= mod;\n        exp >>= 1;\n \
    \   }\n    return ans;\n}\n///@brief mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\
    \u6CD5)\n#line 2 \"math/gcd.hpp\"\ntemplate<typename T>\nconstexpr inline T _gcd(T\
    \ a, T b) {\n    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a\
    \ + b;\n    int d = min(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a),\
    \ b >>= __builtin_ctzll(b);\n    while (a != b) {\n        if (a == 0 || b ==\
    \ 0) {\n            return a + b;\n        }\n        if (a > b) {\n         \
    \   a -= b;\n            a >>= __builtin_ctzll(a);\n        }else{\n         \
    \   b -= a;\n            b >>= __builtin_ctzll(b);\n        }\n    }\n\n    return\
    \ a << d;\n}\ntemplate<typename T>\nconstexpr inline T ext_gcd(T a, T b, T &x,\
    \ T &y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while(b) {\n        T\
    \ q = a / b;\n        tie(a, b) = make_pair(b, a % b);\n        tie(x, nx) = make_pair(nx,\
    \ x - nx*q);\n        tie(y, ny) = make_pair(ny, y - ny*q);\n    }\n    return\
    \ a;\n}\n/// @return ax + by = gcd(a,b)\u306A\u308Bx,y\u3092\u683C\u7D0D\u3059\
    \u308B,\u8FD4\u308A\u5024\u306Bgcd(a,b)\n\n/// @brief gcd(\u30E6\u30FC\u30AF\u30EA\
    \u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306A\u3069)\n#line 4 \"math/DLP.hpp\"\n\
    inline ll dlp(ll x, ll y, ll p) {\n    if (y == 1 || p == 1) {\n        return\
    \ 0;\n    }\n    if (x == 0) {\n        if (y == 0) {\n            return 1;\n\
    \        }\n        else {\n            return -1;\n        }\n    }\n    ll m\
    \ = sqrt(p) + 1;\n    unordered_map<ll, int> mp;\n    ll xm = mod_pow(x, m, p);\n\
    \    ll add = 0, g, k = 1 % p;\n    while ((g = _gcd(x, p)) > 1) {\n        if\
    \ (y == k)return add;\n        if (y % g)return -1;\n        y /= g, p /= g, add++;\n\
    \        k = (k * (x / g)) % p;\n    }\n    ll pr = y;\n    for (int j = 0; j\
    \ <= m; j++) {\n        mp[pr] = j;\n        (pr *= x) %= p;\n    }\n    pr =\
    \ k;\n    for (int i = 1; i <= m; i++) {\n        (pr *= xm) %= p;\n        if\
    \ (mp.find(pr) != mp.end()) {\n            int j = mp[pr];\n            return\
    \ m * i - j + add;\n        }\n    }\n    return -1;\n}\n\n///@brief Discrete\
    \ Logarithm(\u96E2\u6563\u5BFE\u6570)\n///@docs docs/math/DLP.md\n#line 4 \"test/yosupo_judge/math/Discrete_Logarithm.test.cpp\"\
    \nint main() {\n    int t;\n    scanf(\"%d\", &t);\n    while (t--) {\n      \
    \  int x, y, p;\n        scanf(\"%d%d%d\", &x, &y, &p);\n        printf(\"%lld\\\
    n\", dlp(x, y, p));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include\"template.hpp\"\n#include\"math/DLP.hpp\"\nint main() {\n    int t;\n\
    \    scanf(\"%d\", &t);\n    while (t--) {\n        int x, y, p;\n        scanf(\"\
    %d%d%d\", &x, &y, &p);\n        printf(\"%lld\\n\", dlp(x, y, p));\n    }\n}"
  dependsOn:
  - template.hpp
  - math/DLP.hpp
  - math/mod_pow.hpp
  - math/gcd.hpp
  isVerificationFile: true
  path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  requiredBy: []
  timestamp: '2023-04-01 11:49:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/math/Discrete_Logarithm.test.cpp
- /verify/test/yosupo_judge/math/Discrete_Logarithm.test.cpp.html
title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
---
