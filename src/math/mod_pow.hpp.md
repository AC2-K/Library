---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/DLP.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':warning:'
    path: src/math/miller.hpp
    title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A)"
  - icon: ':warning:'
    path: src/math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  - icon: ':warning:'
    path: src/math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':warning:'
    path: src/math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':warning:'
    path: src/math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  - icon: ':warning:'
    path: src/string/rolling_hash.hpp
    title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
    links: []
  bundledCode: "#line 1 \"src/math/mod_pow.hpp\"\ntemplate <class T, class U = T>\n\
    U mod_pow(T base, T exp, T mod){\n    T ans = 1;\n    base %= mod;\n    while\
    \ (exp > 0) {\n        if (exp & 1) {\n            ans *= base;\n            ans\
    \ %= mod;\n        }\n        base *= base;\n        base %= mod;\n        exp\
    \ >>= 1;\n    }\n    return ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\
    \u6CD5)\n"
  code: "template <class T, class U = T>\nU mod_pow(T base, T exp, T mod){\n    T\
    \ ans = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp & 1) {\n\
    \            ans *= base;\n            ans %= mod;\n        }\n        base *=\
    \ base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n\
    ///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  dependsOn: []
  isVerificationFile: false
  path: src/math/mod_pow.hpp
  requiredBy:
  - src/math/DLP.hpp
  - src/math/primitive_root.hpp
  - src/math/primitive_root.hpp
  - src/math/rho.hpp
  - src/math/miller.hpp
  - src/math/phi_function.hpp
  - src/string/rolling_hash.hpp
  timestamp: '2023-03-27 01:42:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/mod_pow.hpp
layout: document
redirect_from:
- /library/src/math/mod_pow.hpp
- /library/src/math/mod_pow.hpp.html
title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
---
