---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/gcd.hpp
    title: "gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306A\
      \u3069)"
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/DLP.md
    document_title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
    links: []
  bundledCode: "#line 2 \"math/mod_pow.hpp\"\ntemplate <class T, class U = T>\nconstexpr\
    \ U mod_pow(T base, T exp, T mod){\n    T ans = 1;\n    base %= mod;\n    while\
    \ (exp > 0) {\n        if (exp & 1) {\n            ans *= base;\n            ans\
    \ %= mod;\n        }\n        base *= base;\n        base %= mod;\n        exp\
    \ >>= 1;\n    }\n    return ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\
    \u6CD5)\n#line 1 \"math/gcd.hpp\"\ntemplate<typename T>\nstatic constexpr inline\
    \ T _gcd(T a,T b){\n    T s = a, t = b;\n    while (s % t != 0) {\n        T u\
    \ = s % t;\n\n        s = t;\n        t = u;\n    }\n    return t;\n}\ntemplate<typename\
    \ T>\nstatic constexpr inline T ext_gcd(T a, T b, T &x, T &y) {\n    x = 1, y\
    \ = 0;\n    T nx = 0, ny = 1;\n    while(b) {\n        T q = a / b;\n        tie(a,\
    \ b) = make_pair(b, a % b);\n        tie(x, nx) = make_pair(nx, x - nx*q);\n \
    \       tie(y, ny) = make_pair(ny, y - ny*q);\n    }\n    return a;\n}\n/// @return\
    \ ax+by=gcd(a,b)\u306A\u308Bx,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\u5024\
    \u306Bgcd(a,b)\n\n/// @brief gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5\u306A\u3069)\n#line 4 \"math/DLP.hpp\"\ninline ll dlp(ll x, ll y,\
    \ ll p) {\n    if (y == 1 || p == 1) {\n        return 0;\n    }\n    if (x ==\
    \ 0) {\n        if (y == 0) {\n            return 1;\n        }\n        else\
    \ {\n            return -1;\n        }\n    }\n    ll m = sqrt(p) + 1;\n    unordered_map<ll,\
    \ int> mp;\n    ll xm = mod_pow(x, m, p);\n    ll add = 0, g, k = 1 % p;\n   \
    \ while ((g = _gcd(x, p)) > 1) {\n        if (y == k)return add;\n        if (y\
    \ % g)return -1;\n        y /= g, p /= g, add++;\n        k = (k * (x / g)) %\
    \ p;\n    }\n    ll pr = y;\n    for (int j = 0; j <= m; j++) {\n        mp[pr]\
    \ = j;\n        (pr *= x) %= p;\n    }\n    pr = k;\n    for (int i = 1; i <=\
    \ m; i++) {\n        (pr *= xm) %= p;\n        if (mp.find(pr) != mp.end()) {\n\
    \            int j = mp[pr];\n            return m * i - j + add;\n        }\n\
    \    }\n    return -1;\n}\n\n///@brief Discrete Logarithm(\u96E2\u6563\u5BFE\u6570\
    )\n///@docs docs/math/DLP.md\n"
  code: "#pragma once\n#include\"math/mod_pow.hpp\"\n#include\"math/gcd.hpp\"\ninline\
    \ ll dlp(ll x, ll y, ll p) {\n    if (y == 1 || p == 1) {\n        return 0;\n\
    \    }\n    if (x == 0) {\n        if (y == 0) {\n            return 1;\n    \
    \    }\n        else {\n            return -1;\n        }\n    }\n    ll m = sqrt(p)\
    \ + 1;\n    unordered_map<ll, int> mp;\n    ll xm = mod_pow(x, m, p);\n    ll\
    \ add = 0, g, k = 1 % p;\n    while ((g = _gcd(x, p)) > 1) {\n        if (y ==\
    \ k)return add;\n        if (y % g)return -1;\n        y /= g, p /= g, add++;\n\
    \        k = (k * (x / g)) % p;\n    }\n    ll pr = y;\n    for (int j = 0; j\
    \ <= m; j++) {\n        mp[pr] = j;\n        (pr *= x) %= p;\n    }\n    pr =\
    \ k;\n    for (int i = 1; i <= m; i++) {\n        (pr *= xm) %= p;\n        if\
    \ (mp.find(pr) != mp.end()) {\n            int j = mp[pr];\n            return\
    \ m * i - j + add;\n        }\n    }\n    return -1;\n}\n\n///@brief Discrete\
    \ Logarithm(\u96E2\u6563\u5BFE\u6570)\n///@docs docs/math/DLP.md"
  dependsOn:
  - math/mod_pow.hpp
  - math/gcd.hpp
  isVerificationFile: false
  path: math/DLP.hpp
  requiredBy: []
  timestamp: '2023-03-29 21:25:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
documentation_of: math/DLP.hpp
layout: document
redirect_from:
- /library/math/DLP.hpp
- /library/math/DLP.hpp.html
title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
---
## 概要
$x,y,p$に対して、$x^n\equiv y (\bmod p)$なる最小の**非負整数**$n$を求めます。ただし、存在しない場合は$-1$をreturnします。

## 使い方
```cpp
long long dlp(long long x,long long y,long long p)
```
上のやつを解きます

- 計算量:$O(\sqrt P)$
- 制約:
    - $0\leq x,y <p$
    - $x,y\in\mathbb{Z}$
    - $M\in\mathbb{N}$
    - $0^0=1$と定めている
