---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS/1/C.test.cpp
    title: test/AOJ/ALDS/1/C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
    links: []
  bundledCode: "#line 1 \"src/math/eratosthenes.hpp\"\nvector<bool> prime_checker(int\
    \ N){\n    vector<bool> primes(N + 1, true);\n\n    primes[0] = false;\n    primes[1]\
    \ = false;\n\n    for (int p = 2; p <= N; ++p) {\n        if (!primes[p]) continue;\n\
    \        for (int i = 2; p * i <= N; i++) {\n            primes[p * i] = false;\n\
    \        }\n    }\n\n    return primes;\n}\n///@brief \u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9\n"
  code: "vector<bool> prime_checker(int N){\n    vector<bool> primes(N + 1, true);\n\
    \n    primes[0] = false;\n    primes[1] = false;\n\n    for (int p = 2; p <= N;\
    \ ++p) {\n        if (!primes[p]) continue;\n        for (int i = 2; p * i <=\
    \ N; i++) {\n            primes[p * i] = false;\n        }\n    }\n\n    return\
    \ primes;\n}\n///@brief \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
  dependsOn: []
  isVerificationFile: false
  path: src/math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2023-03-27 01:42:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS/1/C.test.cpp
documentation_of: src/math/eratosthenes.hpp
layout: document
redirect_from:
- /library/src/math/eratosthenes.hpp
- /library/src/math/eratosthenes.hpp.html
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
