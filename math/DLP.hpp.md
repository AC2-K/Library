---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/math/Discrete Logarithm.test.cpp
    title: test/yosupo judge/math/Discrete Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
    links: []
  bundledCode: "#line 1 \"math/mod_pow.hpp\"\nll mod_pow(ll base, ll exp, ll mod)\
    \ {\n    if(base==0)return 0;\n    ll ans = 1;\n    base %= mod;\n    while (exp\
    \ > 0) {\n        if (exp & 1) {\n            ans *= base;\n            ans %=\
    \ mod;\n        }\n        base *= base;\n        base %= mod;\n        exp >>=\
    \ 1;\n    }\n    return ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5\
    )\n#line 3 \"math/DLP.hpp\"\n\nll dlp(ll x, ll y, ll p) {\n    if (y == 1 || p\
    \ == 1) {\n        return 0;\n    }\n    if (x == 0) {\n        if (y == 0) {\n\
    \            return 1;\n        }\n        else {\n            return -1;\n  \
    \      }\n    }\n    ll m = sqrt(p) + 1;\n    unordered_map<ll, int> mp;\n   \
    \ ll xm = mod_pow(x, m, p);\n    ll add = 0, g, k = 1 % p;\n    while ((g = gcd(x,\
    \ p)) > 1) {\n        if (y == k)return add;\n        if (y % g)return -1;\n \
    \       y /= g, p /= g, add++;\n        k = (k * (x / g)) % p;\n    }\n    ll\
    \ pr = y;\n    for (int j = 0; j <= m; j++) {\n        mp[pr] = j;\n        (pr\
    \ *= x) %= p;\n    }\n    pr = k;\n    for (int i = 1; i <= m; i++) {\n      \
    \  (pr *= xm) %= p;\n        if (mp.find(pr) != mp.end()) {\n            int j\
    \ = mp[pr];\n            return m * i - j + add;\n        }\n    }\n    return\
    \ -1;\n}\n///@brief Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)\n"
  code: "#pragma once\n#include\"math/mod_pow.hpp\"\n\nll dlp(ll x, ll y, ll p) {\n\
    \    if (y == 1 || p == 1) {\n        return 0;\n    }\n    if (x == 0) {\n  \
    \      if (y == 0) {\n            return 1;\n        }\n        else {\n     \
    \       return -1;\n        }\n    }\n    ll m = sqrt(p) + 1;\n    unordered_map<ll,\
    \ int> mp;\n    ll xm = mod_pow(x, m, p);\n    ll add = 0, g, k = 1 % p;\n   \
    \ while ((g = gcd(x, p)) > 1) {\n        if (y == k)return add;\n        if (y\
    \ % g)return -1;\n        y /= g, p /= g, add++;\n        k = (k * (x / g)) %\
    \ p;\n    }\n    ll pr = y;\n    for (int j = 0; j <= m; j++) {\n        mp[pr]\
    \ = j;\n        (pr *= x) %= p;\n    }\n    pr = k;\n    for (int i = 1; i <=\
    \ m; i++) {\n        (pr *= xm) %= p;\n        if (mp.find(pr) != mp.end()) {\n\
    \            int j = mp[pr];\n            return m * i - j + add;\n        }\n\
    \    }\n    return -1;\n}\n///@brief Discrete Logarithm(\u96E2\u6563\u5BFE\u6570\
    )"
  dependsOn:
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/DLP.hpp
  requiredBy: []
  timestamp: '2023-02-23 13:41:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo judge/math/Discrete Logarithm.test.cpp
documentation_of: math/DLP.hpp
layout: document
redirect_from:
- /library/math/DLP.hpp
- /library/math/DLP.hpp.html
title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
---