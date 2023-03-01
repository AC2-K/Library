---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/large_mod.hpp
    title: math/large_mod.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  - icon: ':question:'
    path: math/fast_fact.hpp
    title: "fast factorize(Pollard Rho\u306E\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  - icon: ':x:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  _extendedVerifiedWith:
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
    document_title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5\
      )"
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
    \    }\n    return res;\n}\n#line 3 \"math/fast_prime_check.hpp\"\n\nnamespace\
    \ prime\n{\n    using ull = unsigned long long;\n    // MillerRabin\n    bool\
    \ is_prime_long(ull n){\n        static const vector<ull> bases \n           \
    \ = {2ull, 325ull, 9375ull, 28178ull, 450775ull, 9780504ull, 1795265022ull};\n\
    \n        ull d = n ^ 1uL;\n        ull q = __builtin_ctz(d);\n        d >>= q;\n\
    \n        for (const auto &a : bases){\n            if (a == n){\n           \
    \     return true;\n            }\n            else if (a % n == 0){\n       \
    \         return false;\n            }\n\n            if (i128_modpow(a, d, n)\
    \ != 1){\n                bool is_prime_flag = true;\n                for (ull\
    \ r = 0; r < q;r++){\n                    ull pw = i128_modpow(a, d * (1uL <<\
    \ r), n);\n\n                    if(pw==n-1){\n                        is_prime_flag\
    \ = false;\n                        break;\n                    }\n          \
    \      }\n\n                if(is_prime_flag){\n                    return false;\n\
    \                }\n            }\n        }\n        return true;\n    }\n\n\
    \    bool is_prime_int(ull n){\n        static const vector<ull> bases \n    \
    \        = {2ull, 7ull, 61ull};\n\n        ull d = n ^ 1uL;\n        ull q = __builtin_ctzll(d);\n\
    \        d >>= q;\n        for (const auto &a : bases){\n            if (a ==\
    \ n){\n                return true;\n            }\n            else if (a % n\
    \ == 0){\n                return false;\n            }\n\n            if (i128_modpow(a,\
    \ d, n) != 1){\n                bool is_prime_flag = true;\n                for\
    \ (ull r = 0; r < q;r++){\n                    ull pw = i128_modpow(a, d * (1uL\
    \ << r), n);\n\n                    if(pw==n-1){\n                        is_prime_flag\
    \ = false;\n                        break;\n                    }\n          \
    \      }\n\n                if(is_prime_flag){\n                    return false;\n\
    \                }\n            }\n        }\n        return true;\n    }\n\n\
    \    inline bool is_prime(ull n){\n        if (n < 2){\n            return false;\n\
    \        }\n        if(n == 2){\n            return true;\n        }\n       \
    \ if (~n & 1uL){\n            return false;\n        }\n\n        \n        if\
    \ (n <= (1uL << 31)){\n            return is_prime_int(n);\n        }\n      \
    \  else{\n            return is_prime_long(n);\n        }\n    }\n};\n///@brief\
    \ fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5)\n"
  code: "#pragma once\n#include \"math/large_mod.hpp\"\n\nnamespace prime\n{\n   \
    \ using ull = unsigned long long;\n    // MillerRabin\n    bool is_prime_long(ull\
    \ n){\n        static const vector<ull> bases \n            = {2ull, 325ull, 9375ull,\
    \ 28178ull, 450775ull, 9780504ull, 1795265022ull};\n\n        ull d = n ^ 1uL;\n\
    \        ull q = __builtin_ctz(d);\n        d >>= q;\n\n        for (const auto\
    \ &a : bases){\n            if (a == n){\n                return true;\n     \
    \       }\n            else if (a % n == 0){\n                return false;\n\
    \            }\n\n            if (i128_modpow(a, d, n) != 1){\n              \
    \  bool is_prime_flag = true;\n                for (ull r = 0; r < q;r++){\n \
    \                   ull pw = i128_modpow(a, d * (1uL << r), n);\n\n          \
    \          if(pw==n-1){\n                        is_prime_flag = false;\n    \
    \                    break;\n                    }\n                }\n\n    \
    \            if(is_prime_flag){\n                    return false;\n         \
    \       }\n            }\n        }\n        return true;\n    }\n\n    bool is_prime_int(ull\
    \ n){\n        static const vector<ull> bases \n            = {2ull, 7ull, 61ull};\n\
    \n        ull d = n ^ 1uL;\n        ull q = __builtin_ctzll(d);\n        d >>=\
    \ q;\n        for (const auto &a : bases){\n            if (a == n){\n       \
    \         return true;\n            }\n            else if (a % n == 0){\n   \
    \             return false;\n            }\n\n            if (i128_modpow(a, d,\
    \ n) != 1){\n                bool is_prime_flag = true;\n                for (ull\
    \ r = 0; r < q;r++){\n                    ull pw = i128_modpow(a, d * (1uL <<\
    \ r), n);\n\n                    if(pw==n-1){\n                        is_prime_flag\
    \ = false;\n                        break;\n                    }\n          \
    \      }\n\n                if(is_prime_flag){\n                    return false;\n\
    \                }\n            }\n        }\n        return true;\n    }\n\n\
    \    inline bool is_prime(ull n){\n        if (n < 2){\n            return false;\n\
    \        }\n        if(n == 2){\n            return true;\n        }\n       \
    \ if (~n & 1uL){\n            return false;\n        }\n\n        \n        if\
    \ (n <= (1uL << 31)){\n            return is_prime_int(n);\n        }\n      \
    \  else{\n            return is_prime_long(n);\n        }\n    }\n};\n///@brief\
    \ fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5)"
  dependsOn:
  - math/large_mod.hpp
  isVerificationFile: false
  path: math/fast_prime_check.hpp
  requiredBy:
  - math/fast_fact.hpp
  - math/phi_function.hpp
  - math/primitive_root.hpp
  - main.cpp
  timestamp: '2023-03-01 17:10:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo judge/math/Factorize.test.cpp
  - test/yosupo judge/new/Primitive Root.test.cpp
  - test/AOJ/NTL/1/D.test.cpp
documentation_of: math/fast_prime_check.hpp
layout: document
redirect_from:
- /library/math/fast_prime_check.hpp
- /library/math/fast_prime_check.hpp.html
title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5)"
---
