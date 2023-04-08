---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':warning:'
    path: src/string/rolling_hash.hpp
    title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_B.test.cpp
    title: test/AOJ/NTL/1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)"
    links: []
  bundledCode: "#line 2 \"src/math/mod_pow.hpp\"\nnamespace kyopro {\n\n///@brief\
    \ mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)\ntemplate <class T, class\
    \ U = T> constexpr T mod_pow(T base, T exp, T mod) {\n    U ans = 1;\n    base\
    \ %= mod;\n    while (exp) {\n        if (exp & 1) {\n            ans *= base;\n\
    \            ans %= mod;\n        }\n        base *= base;\n        base %= mod;\n\
    \        exp >>= 1;\n    }\n    return ans;\n}\n};  // namespace kyopro\n"
  code: "#pragma once\nnamespace kyopro {\n\n///@brief mod pow(\u7E70\u308A\u8FD4\u3057\
    \u30CB\u4E57\u6CD5)\ntemplate <class T, class U = T> constexpr T mod_pow(T base,\
    \ T exp, T mod) {\n    U ans = 1;\n    base %= mod;\n    while (exp) {\n     \
    \   if (exp & 1) {\n            ans *= base;\n            ans %= mod;\n      \
    \  }\n        base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n\
    \    return ans;\n}\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/math/mod_pow.hpp
  requiredBy:
  - src/string/rolling_hash.hpp
  - src/math/mod_log.hpp
  timestamp: '2023-04-08 13:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/AOJ/NTL/1_B.test.cpp
documentation_of: src/math/mod_pow.hpp
layout: document
redirect_from:
- /library/src/math/mod_pow.hpp
- /library/src/math/mod_pow.hpp.html
title: "mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)"
---
