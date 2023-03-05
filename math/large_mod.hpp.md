---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':x:'
    path: string/rolling_hash.hpp
    title: rolling hash
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/ALDS/14/B.test.cpp
    title: test/AOJ/ALDS/14/B.test.cpp
  - icon: ':x:'
    path: test/yosupo judge/new/Primitive Root.test.cpp
    title: test/yosupo judge/new/Primitive Root.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/large_mod.hpp\"\ninline long long safe_mod(long long\
    \ a, long long m){\n    return (a % m + m) % m;\n}\nlong long mul(long long a,\
    \ long long b, long long m) {\n    a = safe_mod(a, m);\n    b = safe_mod(b, m);\n\
    \    if (b == 0) return 0;\n    long long res = mul(safe_mod(a + a, m), b >> 1,\
    \ m);\n    if (b & 1){\n        res = safe_mod(res + a, m);\n    }\n    return\
    \ res;\n}\ntemplate<typename T>\nT large_modpow(T base,T exp,T mod){\n    T ans\
    \ = 1 % mod;\n    base %= mod;\n    while (exp) {\n        if (exp & 1) {\n  \
    \          ans = mul(ans, base, mod);\n        }\n        base = mul(base, base,\
    \ mod);\n        exp >>= 1;\n    }\n    return ans;\n}\n"
  code: "#pragma once\ninline long long safe_mod(long long a, long long m){\n    return\
    \ (a % m + m) % m;\n}\nlong long mul(long long a, long long b, long long m) {\n\
    \    a = safe_mod(a, m);\n    b = safe_mod(b, m);\n    if (b == 0) return 0;\n\
    \    long long res = mul(safe_mod(a + a, m), b >> 1, m);\n    if (b & 1){\n  \
    \      res = safe_mod(res + a, m);\n    }\n    return res;\n}\ntemplate<typename\
    \ T>\nT large_modpow(T base,T exp,T mod){\n    T ans = 1 % mod;\n    base %= mod;\n\
    \    while (exp) {\n        if (exp & 1) {\n            ans = mul(ans, base, mod);\n\
    \        }\n        base = mul(base, base, mod);\n        exp >>= 1;\n    }\n\
    \    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/large_mod.hpp
  requiredBy:
  - math/primitive_root.hpp
  - string/rolling_hash.hpp
  timestamp: '2023-03-05 17:53:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo judge/new/Primitive Root.test.cpp
  - test/AOJ/ALDS/14/B.test.cpp
documentation_of: math/large_mod.hpp
layout: document
redirect_from:
- /library/math/large_mod.hpp
- /library/math/large_mod.hpp.html
title: math/large_mod.hpp
---
