---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/DLP.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Discrete Logarithm.test.cpp
    title: test/Library-Checker/Discrete Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u3079\u304D\u4E57"
    links: []
  bundledCode: "#line 1 \"math/mod_pow.hpp\"\nll mod_pow(ll base, ll exp, ll mod)\
    \ {\n    if(base==0)return 0;\n    ll ans = 1;\n    base %= mod;\n    while (exp\
    \ > 0) {\n        if (exp & 1) {\n            ans *= base;\n            ans %=\
    \ mod;\n        }\n        base *= base;\n        base %= mod;\n        exp >>=\
    \ 1;\n    }\n    return ans;\n}\n///@brief \u3079\u304D\u4E57\n"
  code: "ll mod_pow(ll base, ll exp, ll mod) {\n    if(base==0)return 0;\n    ll ans\
    \ = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp & 1) {\n    \
    \        ans *= base;\n            ans %= mod;\n        }\n        base *= base;\n\
    \        base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n///@brief\
    \ \u3079\u304D\u4E57"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.hpp
  requiredBy:
  - math/DLP.hpp
  timestamp: '2023-02-21 12:21:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Library-Checker/Discrete Logarithm.test.cpp
documentation_of: math/mod_pow.hpp
layout: document
redirect_from:
- /library/math/mod_pow.hpp
- /library/math/mod_pow.hpp.html
title: "\u3079\u304D\u4E57"
---
