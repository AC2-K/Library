---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS/1_C.test.cpp
    title: test/AOJ/ALDS/1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
    links: []
  bundledCode: "#line 2 \"math/sieve.hpp\"\n#include <vector>\nnamespace kyopro {\n\
    /// @brief \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\nstd::vector<bool>\
    \ sieve(int N) {\n    std::vector<bool> primes(N + 1, true);\n\n    primes[0]\
    \ = false;\n    primes[1] = false;\n\n    for (int p = 2; p <= N; ++p) {\n   \
    \     if (!primes[p]) continue;\n        for (int i = p * 2; i <= N; i += p) {\n\
    \            primes[i] = false;\n        }\n    }\n\n    return primes;\n}\n};\
    \  // namespace kyopro\n"
  code: "#pragma once\n#include <vector>\nnamespace kyopro {\n/// @brief \u30A8\u30E9\
    \u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\nstd::vector<bool> sieve(int N) {\n\
    \    std::vector<bool> primes(N + 1, true);\n\n    primes[0] = false;\n    primes[1]\
    \ = false;\n\n    for (int p = 2; p <= N; ++p) {\n        if (!primes[p]) continue;\n\
    \        for (int i = p * 2; i <= N; i += p) {\n            primes[i] = false;\n\
    \        }\n    }\n\n    return primes;\n}\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: math/sieve.hpp
  requiredBy: []
  timestamp: '2023-04-08 03:34:55+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS/1_C.test.cpp
documentation_of: math/sieve.hpp
layout: document
redirect_from:
- /library/math/sieve.hpp
- /library/math/sieve.hpp.html
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
