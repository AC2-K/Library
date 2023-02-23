---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/fast_fact.hpp
    title: "fast factorize(Pollard Rho\u306E\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/D.test.cpp
    title: test/AOJ/NTL/1/D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/math/Factorize.test.cpp
    title: test/yosupo judge/math/Factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5\
      )"
    links: []
  bundledCode: "#line 1 \"math/fast_prime_check.hpp\"\nclass MillerRabin {\n    using\
    \ i128 = __int128_t;\n    const vector<ll> bases = { 2, 3, 5, 7, 11, 13, 17, 19,\
    \ 23, 29, 31, 37 };    //int\u3060\u3068\u30012,7,61\u3067\u5341\u5206\n    i128\
    \ mod_pow(i128 base, i128 exp, ll mod) {\n        i128 ans = 1;\n        base\
    \ %= mod;\n        while (exp) {\n            if (exp & 1) {\n               \
    \ ans *= base;\n                ans %= mod;\n            }\n            base *=\
    \ base;\n            base %= mod;\n            exp >>= 1;\n        }\n       \
    \ return ans;\n    }\npublic:\n    bool is_prime(ll n) {\n        if (n < 2) {\n\
    \            return false;\n        }\n        ll d = n - 1;\n        ll q = 0;\n\
    \        while ((d & 1) == 0) {\n            d >>= 1;\n            q++;\n    \
    \    }\n\n        for (const auto&a : bases) {\n            if (a == n) {\n  \
    \              return true;\n            }\n\n            if (mod_pow(a, d, n)\
    \ != 1) {\n                bool flag = true;\n                for (ll r = 0; r\
    \ < q; r++) {\n                    ll pow = mod_pow(a, d * (1ll << r), n);\n \
    \                   if (pow == n - 1) {\n                        flag = false;\n\
    \                        break;\n                    }\n                }\n\n\
    \                if (flag) {\n                    return false;\n            \
    \    }\n            }\n        }\n        return true;\n    }\n};\n///@brief fast\
    \ prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5)\n"
  code: "class MillerRabin {\n    using i128 = __int128_t;\n    const vector<ll> bases\
    \ = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };    //int\u3060\u3068\u3001\
    2,7,61\u3067\u5341\u5206\n    i128 mod_pow(i128 base, i128 exp, ll mod) {\n  \
    \      i128 ans = 1;\n        base %= mod;\n        while (exp) {\n          \
    \  if (exp & 1) {\n                ans *= base;\n                ans %= mod;\n\
    \            }\n            base *= base;\n            base %= mod;\n        \
    \    exp >>= 1;\n        }\n        return ans;\n    }\npublic:\n    bool is_prime(ll\
    \ n) {\n        if (n < 2) {\n            return false;\n        }\n        ll\
    \ d = n - 1;\n        ll q = 0;\n        while ((d & 1) == 0) {\n            d\
    \ >>= 1;\n            q++;\n        }\n\n        for (const auto&a : bases) {\n\
    \            if (a == n) {\n                return true;\n            }\n\n  \
    \          if (mod_pow(a, d, n) != 1) {\n                bool flag = true;\n \
    \               for (ll r = 0; r < q; r++) {\n                    ll pow = mod_pow(a,\
    \ d * (1ll << r), n);\n                    if (pow == n - 1) {\n             \
    \           flag = false;\n                        break;\n                  \
    \  }\n                }\n\n                if (flag) {\n                    return\
    \ false;\n                }\n            }\n        }\n        return true;\n\
    \    }\n};\n///@brief fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\
    \u6CD5)"
  dependsOn: []
  isVerificationFile: false
  path: math/fast_prime_check.hpp
  requiredBy:
  - math/fast_fact.hpp
  - math/phi_function.hpp
  timestamp: '2023-02-23 13:41:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo judge/math/Factorize.test.cpp
  - test/AOJ/NTL/1/D.test.cpp
documentation_of: math/fast_prime_check.hpp
layout: document
redirect_from:
- /library/math/fast_prime_check.hpp
- /library/math/fast_prime_check.hpp.html
title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5)"
---
