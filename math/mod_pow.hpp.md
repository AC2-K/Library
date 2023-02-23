---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/DLP.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':question:'
    path: string/rolling_hash.hpp
    title: rolling hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS/14/B.test.cpp
    title: test/AOJ/ALDS/14/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/B.test.cpp
    title: test/AOJ/NTL/1/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/math/Discrete Logarithm.test.cpp
    title: test/yosupo judge/math/Discrete Logarithm.test.cpp
  - icon: ':x:'
    path: test/yosupo judge/string/Z algorithm with Hash.test.cpp
    title: test/yosupo judge/string/Z algorithm with Hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
    links: []
  bundledCode: "#line 1 \"math/mod_pow.hpp\"\nll mod_pow(ll base, ll exp, ll mod)\
    \ {\n    if(base==0)return 0;\n    ll ans = 1;\n    base %= mod;\n    while (exp\
    \ > 0) {\n        if (exp & 1) {\n            ans *= base;\n            ans %=\
    \ mod;\n        }\n        base *= base;\n        base %= mod;\n        exp >>=\
    \ 1;\n    }\n    return ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5\
    )\n"
  code: "ll mod_pow(ll base, ll exp, ll mod) {\n    if(base==0)return 0;\n    ll ans\
    \ = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp & 1) {\n    \
    \        ans *= base;\n            ans %= mod;\n        }\n        base *= base;\n\
    \        base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n///@brief\
    \ mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.hpp
  requiredBy:
  - math/DLP.hpp
  - string/rolling_hash.hpp
  timestamp: '2023-02-24 00:27:24+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo judge/math/Discrete Logarithm.test.cpp
  - test/yosupo judge/string/Z algorithm with Hash.test.cpp
  - test/AOJ/ALDS/14/B.test.cpp
  - test/AOJ/NTL/1/B.test.cpp
documentation_of: math/mod_pow.hpp
layout: document
redirect_from:
- /library/math/mod_pow.hpp
- /library/math/mod_pow.hpp.html
title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
---
