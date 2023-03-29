---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/miller.hpp
    title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\
      )"
    links: []
  bundledCode: "#line 2 \"math/rho.hpp\"\n#include<bits/stdc++.h>\n#line 2 \"math/mod_pow.hpp\"\
    \ntemplate <class T, class U = T>\nU mod_pow(T base, T exp, T mod){\n    T ans\
    \ = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp & 1) {\n    \
    \        ans *= base;\n            ans %= mod;\n        }\n        base *= base;\n\
    \        base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n///@brief\
    \ mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)\n#line 3 \"math/miller.hpp\"\nnamespace\
    \ prime {\n    namespace miller{\n        using i128 = __int128_t;\n        using\
    \ u128 = __uint128_t;\n        using u64 = __uint64_t;\n        bool miller_rabin(u64\
    \ n,const u64 bases[],int siz) {\n            u64 d = n - 1;\n            u64\
    \ q = __builtin_ctz(d);\n            d >>= q;\n\n            for (int i = 0; i\
    \ < siz; i++) {\n                u64 a = bases[i];\n                if (a == n)\
    \ {\n                    return true;\n                } else if (n % a == 0)\
    \ {\n                    return false;\n                }\n                if\
    \ (mod_pow<u128>(a, d, n) != 1) {\n                    bool flag = true;\n   \
    \                 for (u64 r = 0; r < q; r++) {\n                        u64 pow\
    \ = mod_pow<u128>(a, d * (1ll << r), n);\n                        if (pow == n\
    \ - 1) {\n                            flag = false;\n                        \
    \    break;\n                        }\n                    }\n\n            \
    \        if (flag) {\n                        return false;\n                \
    \    }\n                }\n            }\n            return true;\n        }\n\
    \n\n        bool is_prime(u64 n){\n            static constexpr u64 bases_int[3]\
    \ = {2, 7, 61};  // int\u3060\u3068\u30012,7,61\u3067\u5341\u5206\n          \
    \  static constexpr u64 bases_ll[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\
    \            if (n < 2) {\n                return false;\n            } else if\
    \ (n == 2) {\n                return true;\n            } else if (~n & 1) {\n\
    \                return false;\n            }\n            if (n < (1ul << 31))\
    \ {\n                return miller_rabin(n, bases_int, 3);\n            } else\
    \ {\n                return miller_rabin(n, bases_ll, 7);\n            }\n   \
    \     }\n    };\n};\n///@brief fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\
    \u5B9A)\n#line 4 \"math/rho.hpp\"\nusing namespace std;\n///@brief \u9AD8\u901F\
    \u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)\nnamespace prime {\n    namespace\
    \ rho {\n        using i128 = __int128_t;\n        using u128 = __uint128_t;\n\
    \        using u64 = __uint64_t;\n\n        template<typename T>\n        T _gcd(T\
    \ x, T y) {\n            while (y != 0) {\n                T ny = x % y;\n   \
    \             T nx = y;\n                x = nx, y = ny;\n            }\n    \
    \        return x;\n        }\n        u64 find_factor(u64 n) {\n            static\
    \ u64 v = rand();\n\n            if (~n & 1uL) {\n                return 2;\n\
    \            }\n            if (prime::miller::is_prime(n)) {\n              \
    \  return n;\n            }\n            while (1) {\n                v ^= v <<\
    \ 13, v ^= v >> 7, v ^= v << 17;\n                u64 c = v;\n               \
    \ auto f = [&](u128 x) -> u128 {\n                    x %= n;\n              \
    \      return (x * x + c) % n;\n                };\n                v ^= v <<\
    \ 13, v ^= v >> 7, v ^= v << 17;\n                ll x = v % n;\n            \
    \    ll y = f(x);\n                u64 d = 1;\n                while (d == 1)\
    \ {\n                    d = _gcd((u64)abs(x - y), n);\n                    x\
    \ = f(x);\n                    y = f(f(y));\n                }\n             \
    \   if (1 < d && d < n) {\n                    return d;\n                }\n\
    \            }\n            exit(0);\n        }\n\n        vector<u64> rho_fact(u64\
    \ n) {\n            if (n < 2) {\n                return {};\n            }\n\
    \            if (prime::miller::is_prime(n)) {\n                return { n };\n\
    \            }\n            vector<u64> v;\n            vector<u64> st{ n };\n\
    \            while (st.size()) {\n                u64& m = st.back();\n      \
    \          if (prime::miller::is_prime(m)) {\n                    v.emplace_back(m);\n\
    \                    st.pop_back();\n                }\n                else {\n\
    \                    u64 d = find_factor(m);\n                    m /= d;\n  \
    \                  st.emplace_back(d);\n                }\n            }\n   \
    \         return v;\n        }\n        vector<u64> naive(u64& n) {\n        \
    \    static constexpr u64 basic_prime[] = { 2, 3, 5, 7, 11, 13, 17, 1000000007,\
    \ 998244353 };\n            vector<u64> res;\n            for (const auto& p :\
    \ basic_prime) {\n                while (n % p == 0) {\n                    n\
    \ /= p;\n                    res.emplace_back(p);\n                }\n       \
    \     }\n\n            return res;\n        }\n        vector<u64> factorize(u64\
    \ n) {\n            if (n < 2) {\n                return {};\n            }\n\
    \            vector<u64> v = naive(n);\n            if (n != 1) {\n          \
    \      vector<u64> v2 = rho_fact(n);\n                v.insert(v.end(), all(v2));\n\
    \            }\n            sort(all(v));\n            return v;\n        }\n\n\
    \        vector<pair<u64, int>> exp_factorize(u64 n) {\n            auto pf =\
    \ factorize(n);\n            if (pf.empty()) {\n                return {};\n \
    \           }\n            vector<pair<u64, int>> res;\n            res.emplace_back(pf.front(),\
    \ 1);\n            //rle\n            for (int i = 1; i < pf.size(); i++) {\n\
    \                if (res.back().first == pf[i]) {\n                    res.back().second++;\n\
    \                }\n                else {\n                    res.emplace_back(pf[i],\
    \ 1);\n                }\n            }\n\n            return res;\n        }\n\
    \    };  // namespace pollard\n};  // namespace prime\n#line 3 \"math/phi_function.hpp\"\
    \nll phi_func(ll n){\n    ll res=n;\n    auto pf=prime::rho::factorize(n);\n \
    \   pf.erase(unique(all(pf)),pf.end());     \n    for(auto&d:pf){\n        res=res/d*(d-1);\n\
    \    }\n    return res;\n}\n///@brief phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\
    \u30C8\u95A2\u6570)\n"
  code: "#pragma once\n#include\"math/rho.hpp\"\nll phi_func(ll n){\n    ll res=n;\n\
    \    auto pf=prime::rho::factorize(n);\n    pf.erase(unique(all(pf)),pf.end());\
    \     \n    for(auto&d:pf){\n        res=res/d*(d-1);\n    }\n    return res;\n\
    }\n///@brief phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  dependsOn:
  - math/rho.hpp
  - math/miller.hpp
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/phi_function.hpp
  requiredBy: []
  timestamp: '2023-03-29 13:45:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
documentation_of: math/phi_function.hpp
layout: document
redirect_from:
- /library/math/phi_function.hpp
- /library/math/phi_function.hpp.html
title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
---
