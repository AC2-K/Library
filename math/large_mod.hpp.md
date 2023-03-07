---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  requiredBy: []
  timestamp: '2023-03-06 04:18:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/large_mod.hpp
layout: document
redirect_from:
- /library/math/large_mod.hpp
- /library/math/large_mod.hpp.html
title: math/large_mod.hpp
---
