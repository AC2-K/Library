---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Primitive_Root.test.cpp
    title: test/yosupo_judge/new/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No-3030.test.cpp
    title: test/yuki/No-3030.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
    links: []
  bundledCode: "#line 2 \"math/mod_pow.hpp\"\ntemplate <class T, class U = T>\nconstexpr\
    \ U mod_pow(T base, T exp, T mod){\n    T ans = 1;\n    base %= mod;\n    while\
    \ (exp > 0) {\n        if (exp & 1) {\n            ans *= base;\n            ans\
    \ %= mod;\n        }\n        base *= base;\n        base %= mod;\n        exp\
    \ >>= 1;\n    }\n    return ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\
    \u6CD5)\n#line 3 \"math/miller.hpp\"\nnamespace prime {\n    namespace miller\
    \ {\n        using i128 = __int128_t;\n        using u128 = __uint128_t;\n   \
    \     using u64 = uint64_t;\n        using u32 = uint32_t;\n\n        bool miller_rabin(u64\
    \ n, const u64 bases[], int length) {\n            u64 d = n - 1;\n\n        \
    \    while (~d & 1) {\n                d >>= 1;\n            }\n\n           \
    \ u64 rev = n - 1;\n\n            for (int i = 0; i < length; i++) {\n       \
    \         u64 a = bases[i];\n\n                if (n <= a) {\n               \
    \     return true;\n                }\n                u64 t = d;\n          \
    \      u128 y = mod_pow<u128>(a, t, n);\n                while (t != n - 1 &&\
    \ y != 1 && y != rev) {\n                    (y *= y) %= n;\n                \
    \    t <<= 1;\n                }\n\n                if (y != rev && (~t & 1))return\
    \ false;\n            }\n            return true;\n        }\n\n\n        constexpr\
    \ u64 bases_int[3] = { 2, 7, 61 };  // int\u3060\u3068\u30012,7,61\u3067\u5341\
    \u5206\n        constexpr u64 bases_ll[7] = { 2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022 };\n        bool is_prime(u64 n) {\n            if (n < 2) {\n  \
    \              return false;\n            }\n            else if (n == 2) {\n\
    \                return true;\n            }\n            else if (~n & 1) {\n\
    \                return false;\n            }\n            if (n < (1ul << 31))\
    \ {\n                return miller_rabin(n, bases_int, 3);\n            }\n  \
    \          else {\n                return miller_rabin(n, bases_ll, 7);\n    \
    \        }\n        }\n    };\n};\n///@brief MillerRabin\u306E\u7D20\u6570\u5224\
    \u5B9A\n"
  code: "#pragma once\n#include\"math/mod_pow.hpp\"\nnamespace prime {\n    namespace\
    \ miller {\n        using i128 = __int128_t;\n        using u128 = __uint128_t;\n\
    \        using u64 = uint64_t;\n        using u32 = uint32_t;\n\n        bool\
    \ miller_rabin(u64 n, const u64 bases[], int length) {\n            u64 d = n\
    \ - 1;\n\n            while (~d & 1) {\n                d >>= 1;\n           \
    \ }\n\n            u64 rev = n - 1;\n\n            for (int i = 0; i < length;\
    \ i++) {\n                u64 a = bases[i];\n\n                if (n <= a) {\n\
    \                    return true;\n                }\n                u64 t =\
    \ d;\n                u128 y = mod_pow<u128>(a, t, n);\n                while\
    \ (t != n - 1 && y != 1 && y != rev) {\n                    (y *= y) %= n;\n \
    \                   t <<= 1;\n                }\n\n                if (y != rev\
    \ && (~t & 1))return false;\n            }\n            return true;\n       \
    \ }\n\n\n        constexpr u64 bases_int[3] = { 2, 7, 61 };  // int\u3060\u3068\
    \u30012,7,61\u3067\u5341\u5206\n        constexpr u64 bases_ll[7] = { 2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022 };\n        bool is_prime(u64 n) {\n\
    \            if (n < 2) {\n                return false;\n            }\n    \
    \        else if (n == 2) {\n                return true;\n            }\n   \
    \         else if (~n & 1) {\n                return false;\n            }\n \
    \           if (n < (1ul << 31)) {\n                return miller_rabin(n, bases_int,\
    \ 3);\n            }\n            else {\n                return miller_rabin(n,\
    \ bases_ll, 7);\n            }\n        }\n    };\n};\n///@brief MillerRabin\u306E\
    \u7D20\u6570\u5224\u5B9A"
  dependsOn:
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/miller.hpp
  requiredBy:
  - math/rho.hpp
  - math/primitive_root.hpp
  - math/phi_function.hpp
  timestamp: '2023-03-31 15:06:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yuki/No-3030.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/new/Primitive_Root.test.cpp
documentation_of: math/miller.hpp
layout: document
redirect_from:
- /library/math/miller.hpp
- /library/math/miller.hpp.html
title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
---
