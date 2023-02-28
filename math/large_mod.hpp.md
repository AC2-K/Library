---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
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
    path: test/yosupo judge/new/Primitive Root.test.cpp
    title: test/yosupo judge/new/Primitive Root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/large_mod.hpp\"\ninline long long safe_mod(long long\
    \ a, long long m) {\n    return (a % m + m) % m;\n}\ninline long long mul(long\
    \ long a, long long b, long long m) {\n    a = safe_mod(a, m); b = safe_mod(b,\
    \ m);\n    if (b == 0) return 0;\n    long long res = mul(safe_mod(a + a, m),\
    \ b>>1, m);\n    if (b & 1) res = safe_mod(res + a, m);\n    return res;\n}\n\
    template<typename T>\n__uint128_t large_modpow(T base,T exp,T mod){\n    if(base==0)return\
    \ 0;\n    __uint128_t ans = 1;\n    base %= mod;\n    while (exp) {\n        if\
    \ (exp & 1) {\n            ans = mul(ans,base,mod);\n        }\n        base =\
    \ mul(base,base,mod);\n        exp >>= 1;\n    }\n    return ans;\n}\n"
  code: "inline long long safe_mod(long long a, long long m) {\n    return (a % m\
    \ + m) % m;\n}\ninline long long mul(long long a, long long b, long long m) {\n\
    \    a = safe_mod(a, m); b = safe_mod(b, m);\n    if (b == 0) return 0;\n    long\
    \ long res = mul(safe_mod(a + a, m), b>>1, m);\n    if (b & 1) res = safe_mod(res\
    \ + a, m);\n    return res;\n}\ntemplate<typename T>\n__uint128_t large_modpow(T\
    \ base,T exp,T mod){\n    if(base==0)return 0;\n    __uint128_t ans = 1;\n   \
    \ base %= mod;\n    while (exp) {\n        if (exp & 1) {\n            ans = mul(ans,base,mod);\n\
    \        }\n        base = mul(base,base,mod);\n        exp >>= 1;\n    }\n  \
    \  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/large_mod.hpp
  requiredBy:
  - math/primitive_root.hpp
  - string/rolling_hash.hpp
  timestamp: '2023-02-28 20:50:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
