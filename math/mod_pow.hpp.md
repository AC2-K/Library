---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':x:'
    path: string/rolling_hash.hpp
    title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_B.test.cpp
    title: test/AOJ/NTL/1_B.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - icon: ':x:'
    path: test/yuki/No-430.test.cpp
    title: test/yuki/No-430.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)"
    links: []
  bundledCode: "#line 2 \"math/mod_pow.hpp\"\nnamespace library {\n\n///@brief mod\
    \ pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)\ntemplate <class T, class U\
    \ = T>\nconstexpr T mod_pow(T base, T exp, T mod){\n    U ans = 1;\n    base %=\
    \ mod;\n    while (exp) {\n        if (exp & 1) {\n            ans *= base;\n\
    \            ans %= mod;\n        }\n        base *= base;\n        base %= mod;\n\
    \        exp >>= 1;\n    }\n    return ans;\n}\n\n};  // namespace library\n"
  code: "#pragma once\nnamespace library {\n\n///@brief mod pow(\u7E70\u308A\u8FD4\
    \u3057\u30CB\u4E57\u6CD5)\ntemplate <class T, class U = T>\nconstexpr T mod_pow(T\
    \ base, T exp, T mod){\n    U ans = 1;\n    base %= mod;\n    while (exp) {\n\
    \        if (exp & 1) {\n            ans *= base;\n            ans %= mod;\n \
    \       }\n        base *= base;\n        base %= mod;\n        exp >>= 1;\n \
    \   }\n    return ans;\n}\n\n};  // namespace library"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.hpp
  requiredBy:
  - string/rolling_hash.hpp
  - math/mod_log.hpp
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/NTL/1_B.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/yuki/No-430.test.cpp
documentation_of: math/mod_pow.hpp
layout: document
redirect_from:
- /library/math/mod_pow.hpp
- /library/math/mod_pow.hpp.html
title: "mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)"
---
