---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
    links: []
  bundledCode: "#line 2 \"math/sieve.hpp\"\n#include<vector>\nnamespace library {\n\
    \n///@brief \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\ninline std::vector<bool>\
    \ sieve(int N){\n    std::vector<bool> primes(N + 1, true);\n\n    primes[0] =\
    \ false;\n    primes[1] = false;\n\n    for (int p = 2; p <= N; ++p) {\n     \
    \   if (!primes[p]) continue;\n        for (int i = (p << 1); p <= N; i += p)\
    \ {\n            primes[i] = false;\n        }\n    }\n\n    return primes;\n\
    }\n\n};  // namespace library\n"
  code: "#pragma once\n#include<vector>\nnamespace library {\n\n///@brief \u30A8\u30E9\
    \u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\ninline std::vector<bool> sieve(int\
    \ N){\n    std::vector<bool> primes(N + 1, true);\n\n    primes[0] = false;\n\
    \    primes[1] = false;\n\n    for (int p = 2; p <= N; ++p) {\n        if (!primes[p])\
    \ continue;\n        for (int i = (p << 1); p <= N; i += p) {\n            primes[i]\
    \ = false;\n        }\n    }\n\n    return primes;\n}\n\n};  // namespace library"
  dependsOn: []
  isVerificationFile: false
  path: math/sieve.hpp
  requiredBy: []
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/sieve.hpp
layout: document
redirect_from:
- /library/math/sieve.hpp
- /library/math/sieve.hpp.html
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
