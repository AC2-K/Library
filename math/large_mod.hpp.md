---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  - icon: ':question:'
    path: math/fast_fact.hpp
    title: "fast factorize(Pollard Rho\u306E\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':question:'
    path: math/fast_prime_check.hpp
    title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  - icon: ':x:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: rolling hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS/14/B.test.cpp
    title: test/AOJ/ALDS/14/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/D.test.cpp
    title: test/AOJ/NTL/1/D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/math/Factorize.test.cpp
    title: test/yosupo judge/math/Factorize.test.cpp
  - icon: ':x:'
    path: test/yosupo judge/new/Primitive Root.test.cpp
    title: test/yosupo judge/new/Primitive Root.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/large_mod.hpp\"\ninline unsigned long long safe_mod(unsigned\
    \ long long a, unsigned long long m) {\n    return (a % m + m) % m;\n}\nunsigned\
    \ long long mul(unsigned long long a, unsigned long long b, unsigned long long\
    \ m) {\n    a = safe_mod(a, m);\n    b = safe_mod(b, m);\n    if (b == 0) return\
    \ 0;\n    unsigned long long res = mul(safe_mod(a + a, m), b >> 1, m);\n    if\
    \ (b & 1){\n        res = safe_mod(res + a, m);\n    }\n    return res;\n}\ntemplate<typename\
    \ T>\nT large_modpow(T base,T exp,T mod){\n    T ans = 1 % mod;\n    base %= mod;\n\
    \    while (exp) {\n        if (exp & 1) {\n            ans = mul(ans, base, mod);\n\
    \        }\n        base = mul(base, base, mod);\n        exp >>= 1;\n    }\n\
    \    return ans;\n}\n\nunsigned long long i128_modpow(__uint128_t base, __uint128_t\
    \ exp, unsigned long long mod){\n    i128 res = (mod == 1 ? 0 : 1);\n    base\
    \ %= mod;\n    while (exp){\n        if (exp & 1){\n            res = (res * base)\
    \ % mod;\n        }\n        base = (base * base) % mod;\n        exp >>= 1;\n\
    \    }\n    return res;\n}\n"
  code: "inline unsigned long long safe_mod(unsigned long long a, unsigned long long\
    \ m) {\n    return (a % m + m) % m;\n}\nunsigned long long mul(unsigned long long\
    \ a, unsigned long long b, unsigned long long m) {\n    a = safe_mod(a, m);\n\
    \    b = safe_mod(b, m);\n    if (b == 0) return 0;\n    unsigned long long res\
    \ = mul(safe_mod(a + a, m), b >> 1, m);\n    if (b & 1){\n        res = safe_mod(res\
    \ + a, m);\n    }\n    return res;\n}\ntemplate<typename T>\nT large_modpow(T\
    \ base,T exp,T mod){\n    T ans = 1 % mod;\n    base %= mod;\n    while (exp)\
    \ {\n        if (exp & 1) {\n            ans = mul(ans, base, mod);\n        }\n\
    \        base = mul(base, base, mod);\n        exp >>= 1;\n    }\n    return ans;\n\
    }\n\nunsigned long long i128_modpow(__uint128_t base, __uint128_t exp, unsigned\
    \ long long mod){\n    i128 res = (mod == 1 ? 0 : 1);\n    base %= mod;\n    while\
    \ (exp){\n        if (exp & 1){\n            res = (res * base) % mod;\n     \
    \   }\n        base = (base * base) % mod;\n        exp >>= 1;\n    }\n    return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/large_mod.hpp
  requiredBy:
  - math/fast_fact.hpp
  - math/fast_prime_check.hpp
  - math/phi_function.hpp
  - math/primitive_root.hpp
  - main.cpp
  - string/rolling_hash.hpp
  timestamp: '2023-03-01 17:03:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo judge/math/Factorize.test.cpp
  - test/yosupo judge/new/Primitive Root.test.cpp
  - test/AOJ/ALDS/14/B.test.cpp
  - test/AOJ/NTL/1/D.test.cpp
documentation_of: math/large_mod.hpp
layout: document
redirect_from:
- /library/math/large_mod.hpp
- /library/math/large_mod.hpp.html
title: math/large_mod.hpp
---
