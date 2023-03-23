---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/fast_fact.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/D.test.cpp
    title: test/AOJ/NTL/1/D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/math/Factorize.test.cpp
    title: test/yosupo judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/new/Primitive Root.test.cpp
    title: test/yosupo judge/new/Primitive Root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A)"
    links: []
  bundledCode: "#line 2 \"math/mod_pow.hpp\"\ntemplate <class T, class U = T>\nU mod_pow(T\
    \ base, T exp, T mod){\n    T ans = 1;\n    base %= mod;\n    while (exp > 0)\
    \ {\n        if (exp & 1) {\n            ans *= base;\n            ans %= mod;\n\
    \        }\n        base *= base;\n        base %= mod;\n        exp >>= 1;\n\
    \    }\n    return ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)\n\
    #line 3 \"math/fast_prime_check.hpp\"\nnamespace prime {\n    namespace miller{\n\
    \        using i128 = __int128_t;\n        using u128 = __uint128_t;\n       \
    \ using u64 = __uint64_t;\n        bool miller_rabin(u64 n,const u64 bases[],int\
    \ siz) {\n            u64 d = n - 1;\n            u64 q = __builtin_ctz(d);\n\
    \            d >>= q;\n\n            for (int i = 0; i < siz; i++) {\n       \
    \         u64 a = bases[i];\n                if (a == n) {\n                 \
    \   return true;\n                } else if (n % a == 0) {\n                 \
    \   return false;\n                }\n                if (mod_pow<u128>(a, d,\
    \ n) != 1) {\n                    bool flag = true;\n                    for (u64\
    \ r = 0; r < q; r++) {\n                        u64 pow = mod_pow<u128>(a, d *\
    \ (1ll << r), n);\n                        if (pow == n - 1) {\n             \
    \               flag = false;\n                            break;\n          \
    \              }\n                    }\n\n                    if (flag) {\n \
    \                       return false;\n                    }\n               \
    \ }\n            }\n            return true;\n        }\n\n\n        bool is_prime(u64\
    \ n){\n            static constexpr u64 bases_int[3] = {2, 7, 61};  // int\u3060\
    \u3068\u30012,7,61\u3067\u5341\u5206\n            static constexpr u64 bases_ll[7]\
    \ = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n            if (n < 2)\
    \ {\n                return false;\n            } else if (n == 2) {\n       \
    \         return true;\n            } else if (~n & 1) {\n                return\
    \ false;\n            }\n            if (n < (1ul << 31)) {\n                return\
    \ miller_rabin(n, bases_int, 3);\n            } else {\n                return\
    \ miller_rabin(n, bases_ll, 7);\n            }\n        }\n    };\n};\nusing prime::miller::is_prime;\n\
    ///@brief fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A)\n"
  code: "#pragma once\n#include\"math/mod_pow.hpp\"\nnamespace prime {\n    namespace\
    \ miller{\n        using i128 = __int128_t;\n        using u128 = __uint128_t;\n\
    \        using u64 = __uint64_t;\n        bool miller_rabin(u64 n,const u64 bases[],int\
    \ siz) {\n            u64 d = n - 1;\n            u64 q = __builtin_ctz(d);\n\
    \            d >>= q;\n\n            for (int i = 0; i < siz; i++) {\n       \
    \         u64 a = bases[i];\n                if (a == n) {\n                 \
    \   return true;\n                } else if (n % a == 0) {\n                 \
    \   return false;\n                }\n                if (mod_pow<u128>(a, d,\
    \ n) != 1) {\n                    bool flag = true;\n                    for (u64\
    \ r = 0; r < q; r++) {\n                        u64 pow = mod_pow<u128>(a, d *\
    \ (1ll << r), n);\n                        if (pow == n - 1) {\n             \
    \               flag = false;\n                            break;\n          \
    \              }\n                    }\n\n                    if (flag) {\n \
    \                       return false;\n                    }\n               \
    \ }\n            }\n            return true;\n        }\n\n\n        bool is_prime(u64\
    \ n){\n            static constexpr u64 bases_int[3] = {2, 7, 61};  // int\u3060\
    \u3068\u30012,7,61\u3067\u5341\u5206\n            static constexpr u64 bases_ll[7]\
    \ = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n            if (n < 2)\
    \ {\n                return false;\n            } else if (n == 2) {\n       \
    \         return true;\n            } else if (~n & 1) {\n                return\
    \ false;\n            }\n            if (n < (1ul << 31)) {\n                return\
    \ miller_rabin(n, bases_int, 3);\n            } else {\n                return\
    \ miller_rabin(n, bases_ll, 7);\n            }\n        }\n    };\n};\nusing prime::miller::is_prime;\n\
    ///@brief fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A)"
  dependsOn:
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/fast_prime_check.hpp
  requiredBy:
  - math/primitive_root.hpp
  - math/fast_fact.hpp
  - math/phi_function.hpp
  timestamp: '2023-03-23 15:53:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo judge/new/Primitive Root.test.cpp
  - test/yosupo judge/math/Factorize.test.cpp
  - test/AOJ/NTL/1/D.test.cpp
documentation_of: math/fast_prime_check.hpp
layout: document
redirect_from:
- /library/math/fast_prime_check.hpp
- /library/math/fast_prime_check.hpp.html
title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A)"
---
