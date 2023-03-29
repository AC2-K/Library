---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/DLP.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/miller.hpp
    title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS/14/B.test.cpp
    title: test/AOJ/ALDS/14/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/B.test.cpp
    title: test/AOJ/NTL/1/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/D.test.cpp
    title: test/AOJ/NTL/1/D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Primitive_Root.test.cpp
    title: test/yosupo_judge/new/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No-3030.test.cpp
    title: test/yuki/No-3030.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No-430.test.cpp
    title: test/yuki/No-430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
    links: []
  bundledCode: "#line 2 \"math/mod_pow.hpp\"\ntemplate <class T, class U = T>\nU mod_pow(T\
    \ base, T exp, T mod){\n    T ans = 1;\n    base %= mod;\n    while (exp > 0)\
    \ {\n        if (exp & 1) {\n            ans *= base;\n            ans %= mod;\n\
    \        }\n        base *= base;\n        base %= mod;\n        exp >>= 1;\n\
    \    }\n    return ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)\n"
  code: "#pragma once\ntemplate <class T, class U = T>\nU mod_pow(T base, T exp, T\
    \ mod){\n    T ans = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp\
    \ & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n     \
    \   base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.hpp
  requiredBy:
  - math/DLP.hpp
  - math/primitive_root.hpp
  - math/rho.hpp
  - math/miller.hpp
  - math/phi_function.hpp
  - string/rolling_hash.hpp
  timestamp: '2023-03-06 05:55:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/No-3030.test.cpp
  - test/yuki/No-430.test.cpp
  - test/yosupo_judge/new/Primitive_Root.test.cpp
  - test/yosupo_judge/math/Discrete Logarithm.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/AOJ/NTL/1/D.test.cpp
  - test/AOJ/NTL/1/B.test.cpp
  - test/AOJ/ALDS/14/B.test.cpp
documentation_of: math/mod_pow.hpp
layout: document
redirect_from:
- /library/math/mod_pow.hpp
- /library/math/mod_pow.hpp.html
title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
---
