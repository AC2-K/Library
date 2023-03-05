---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  - icon: ':x:'
    path: math/DLP.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':x:'
    path: math/fast_fact.hpp
    title: math/fast_fact.hpp
  - icon: ':x:'
    path: math/fast_prime_check.hpp
    title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A)"
  - icon: ':x:'
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  - icon: ':x:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':warning:'
    path: sub.cpp
    title: sub.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/NTL/1/B.test.cpp
    title: test/AOJ/NTL/1/B.test.cpp
  - icon: ':x:'
    path: test/AOJ/NTL/1/D.test.cpp
    title: test/AOJ/NTL/1/D.test.cpp
  - icon: ':x:'
    path: test/yosupo judge/math/Discrete Logarithm.test.cpp
    title: test/yosupo judge/math/Discrete Logarithm.test.cpp
  - icon: ':x:'
    path: test/yosupo judge/math/Factorize.test.cpp
    title: test/yosupo judge/math/Factorize.test.cpp
  - icon: ':x:'
    path: test/yosupo judge/new/Primitive Root.test.cpp
    title: test/yosupo judge/new/Primitive Root.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
    links: []
  bundledCode: "#line 1 \"math/mod_pow.hpp\"\ntemplate <class T, class U = T>\nU mod_pow(T\
    \ base, T exp, T mod){\n    if(base==0)return 0;\n    T ans = 1;\n    base %=\
    \ mod;\n    while (exp > 0) {\n        if (exp & 1) {\n            ans *= base;\n\
    \            ans %= mod;\n        }\n        base *= base;\n        base %= mod;\n\
    \        exp >>= 1;\n    }\n    return ans;\n}\n///@brief mod pow(\u30D0\u30A4\
    \u30CA\u30EA\u6CD5)\n"
  code: "template <class T, class U = T>\nU mod_pow(T base, T exp, T mod){\n    if(base==0)return\
    \ 0;\n    T ans = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp\
    \ & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n     \
    \   base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.hpp
  requiredBy:
  - math/DLP.hpp
  - math/fast_fact.hpp
  - math/fast_prime_check.hpp
  - math/phi_function.hpp
  - math/primitive_root.hpp
  - sub.cpp
  - main.cpp
  timestamp: '2023-03-05 17:21:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo judge/math/Discrete Logarithm.test.cpp
  - test/yosupo judge/math/Factorize.test.cpp
  - test/yosupo judge/new/Primitive Root.test.cpp
  - test/AOJ/NTL/1/D.test.cpp
  - test/AOJ/NTL/1/B.test.cpp
documentation_of: math/mod_pow.hpp
layout: document
redirect_from:
- /library/math/mod_pow.hpp
- /library/math/mod_pow.hpp.html
title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
---
