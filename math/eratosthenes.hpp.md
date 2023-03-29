---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/ALDS/1_C.test.cpp
    title: test/AOJ/ALDS/1_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
    links: []
  bundledCode: "#line 2 \"math/eratosthenes.hpp\"\nstatic constexpr inline vector<bool>\
    \ prime_checker(int N){\n    vector<bool> primes(N + 1, true);\n\n    primes[0]\
    \ = false;\n    primes[1] = false;\n\n    for (int p = 2; p <= N; ++p) {\n   \
    \     if (!primes[p]) continue;\n        for (int i = 2; p * i <= N; i++) {\n\
    \            primes[p * i] = false;\n        }\n    }\n\n    return primes;\n\
    }\n///@brief \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n"
  code: "#pragma once\nstatic constexpr inline vector<bool> prime_checker(int N){\n\
    \    vector<bool> primes(N + 1, true);\n\n    primes[0] = false;\n    primes[1]\
    \ = false;\n\n    for (int p = 2; p <= N; ++p) {\n        if (!primes[p]) continue;\n\
    \        for (int i = 2; p * i <= N; i++) {\n            primes[p * i] = false;\n\
    \        }\n    }\n\n    return primes;\n}\n///@brief \u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9"
  dependsOn: []
  isVerificationFile: false
  path: math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2023-03-29 21:25:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/ALDS/1_C.test.cpp
documentation_of: math/eratosthenes.hpp
layout: document
redirect_from:
- /library/math/eratosthenes.hpp
- /library/math/eratosthenes.hpp.html
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
