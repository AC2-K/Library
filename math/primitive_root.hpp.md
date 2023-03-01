---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/fast_fact.hpp
    title: "fast factorize(Pollard Rho\u306E\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: math/fast_prime_check.hpp
    title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: math/large_mod.hpp
    title: math/large_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_list.hpp
    title: "\u7D20\u6570\u8868"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: main.test.cpp
    title: main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/new/Primitive Root.test.cpp
    title: test/yosupo judge/new/Primitive Root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "primitive root(\u539F\u59CB\u6839)"
    links: []
  bundledCode: "#line 2 \"math/large_mod.hpp\"\ninline long long safe_mod(long long\
    \ a, long long m){\n    return (a % m + m) % m;\n}\nlong long mul(long long a,\
    \ long long b, long long m) {\n    a = safe_mod(a, m);\n    b = safe_mod(b, m);\n\
    \    if (b == 0) return 0;\n    long long res = mul(safe_mod(a + a, m), b >> 1,\
    \ m);\n    if (b & 1){\n        res = safe_mod(res + a, m);\n    }\n    return\
    \ res;\n}\ntemplate<typename T>\nT large_modpow(T base,T exp,T mod){\n    T ans\
    \ = 1 % mod;\n    base %= mod;\n    while (exp) {\n        if (exp & 1) {\n  \
    \          ans = mul(ans, base, mod);\n        }\n        base = mul(base, base,\
    \ mod);\n        exp >>= 1;\n    }\n    return ans;\n}\n\nunsigned long long i128_modpow(__uint128_t\
    \ base, __uint128_t exp, unsigned long long mod){\n    i128 res = (mod == 1 ?\
    \ 0 : 1);\n    base %= mod;\n    while (exp){\n        if (exp & 1){\n       \
    \     res = (res * base) % mod;\n        }\n        base = (base * base) % mod;\n\
    \        exp >>= 1;\n    }\n    return res;\n}\n#line 3 \"math/fast_prime_check.hpp\"\
    \n\nnamespace prime\n{\n    using ull = unsigned long long;\n    // MillerRabin\n\
    \    bool is_prime_long(ull n){\n        static const vector<ull> bases \n   \
    \         = {2ull, 325ull, 9375ull, 28178ull, 450775ull, 9780504ull, 1795265022ull};\n\
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
    \ fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5)\n#line 2 \"\
    math/prime_list.hpp\"\n//1000\u4EE5\u4E0B\u306E\u7D20\u6570\nconstexpr int prime_list1000[]\
    \ = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,\
    \ 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,\
    \ 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241,\
    \ 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347,\
    \ 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439,\
    \ 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547,\
    \ 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,\
    \ 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751,\
    \ 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859,\
    \ 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977,\
    \ 983, 991, 997};\n///@brief \u7D20\u6570\u8868\n#line 4 \"math/fast_fact.hpp\"\
    \nnamespace prime\n{\n    using ull = unsigned long long;\n    // Rho factorize\n\
    \    \n    ll find_factor(ll n){\n        static ull v = 7001;\n        v ^= v\
    \ << 13, v ^= v >> 7, v ^= v << 17;\n        /*\n        if (n == 4){\n      \
    \      return 2;\n        }\n        */\n\n        if (~n & 1uL){\n          \
    \  return 2;\n        }\n        static ull c=v;\n        auto f = [&](i128 x)\
    \ -> ll {\n            x %= n;\n            return (x * x % n + c) % n;\n    \
    \    };\n        ll x = v % n;\n        ll y=x;\n        ll d=1;\n\n        while\
    \ (d == 1){\n            x = f(x);\n            y = f(f(y));\n            d =\
    \ __gcd(abs(x - y), n);\n        }\n\n        if (d == n){\n            return\
    \ -1;\n        }\n        return d;\n    }\n    vector<ll> rho_fact(ll&n){\n \
    \       if (n < 2){\n            return {};\n        }\n        if(is_prime(n)){\n\
    \            return {n};\n        }\n        ll d=-1;\n        while (d == -1){\n\
    \            d=find_factor(n);\n        }\n        n /= d;\n        vector<ll>\
    \ v1 = rho_fact(n);\n        vector<ll> v2 = rho_fact(d);\n        v1.insert(v1.end(),\
    \ v2.begin(), v2.end());\n        return v1;\n    }\n\n    vector<ll> naive_fact(ll&n){\n\
    \        vector<ll> res;\n        \n        for (const ll d :prime_list1000){\n\
    \            while (n % d == 0){\n                res.push_back(d);\n        \
    \        n /= d;\n            }\n        }\n        return res;\n    }\n\n   \
    \ vector<ll> fact(ll n){\n        vector<ll> res = naive_fact(n);\n        vector<ll>\
    \ res2=rho_fact(n);\n        res.insert(res.end(), all(res2));\n        sort(all(res));\n\
    \        return res;\n    }\n};\n///@brief fast factorize(Pollard Rho\u306E\u7D20\
    \u56E0\u6570\u5206\u89E3)\n#line 4 \"math/primitive_root.hpp\"\nll primitive_root(ll\
    \ p){\n    if(p == 2) return 1;\n    auto pf = prime::fact(p - 1);\n    pf.erase(unique(all(pf)),pf.end());\n\
    \    for(auto&q:pf){\n        q=(p-1)/q;\n    }\n    using ull = unsigned long\
    \ long;\n    static ull rnd = 7001;\n    while(1){\n        rnd^=rnd<<13; rnd^=rnd>>7;\
    \ rnd^=rnd<<17;\n        ll g = (ull)rnd%p;\n        if(g == 0) continue;\n  \
    \      bool is_ok = true;\n        for(ll q : pf){\n            if(large_modpow(g,q,p)\
    \ == 1){ \n                is_ok = false; \n                break; \n        \
    \    }\n        }\n        if(is_ok){\n            return g;\n        }\n    }\n\
    }\n\n//@brief primitive root(\u539F\u59CB\u6839)\n"
  code: "#pragma once\n#include\"math/large_mod.hpp\"\n#include\"math/fast_fact.hpp\"\
    \nll primitive_root(ll p){\n    if(p == 2) return 1;\n    auto pf = prime::fact(p\
    \ - 1);\n    pf.erase(unique(all(pf)),pf.end());\n    for(auto&q:pf){\n      \
    \  q=(p-1)/q;\n    }\n    using ull = unsigned long long;\n    static ull rnd\
    \ = 7001;\n    while(1){\n        rnd^=rnd<<13; rnd^=rnd>>7; rnd^=rnd<<17;\n \
    \       ll g = (ull)rnd%p;\n        if(g == 0) continue;\n        bool is_ok =\
    \ true;\n        for(ll q : pf){\n            if(large_modpow(g,q,p) == 1){ \n\
    \                is_ok = false; \n                break; \n            }\n   \
    \     }\n        if(is_ok){\n            return g;\n        }\n    }\n}\n\n//@brief\
    \ primitive root(\u539F\u59CB\u6839)"
  dependsOn:
  - math/large_mod.hpp
  - math/fast_fact.hpp
  - math/fast_prime_check.hpp
  - math/prime_list.hpp
  isVerificationFile: false
  path: math/primitive_root.hpp
  requiredBy: []
  timestamp: '2023-03-01 17:28:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - main.test.cpp
  - test/yosupo judge/new/Primitive Root.test.cpp
documentation_of: math/primitive_root.hpp
layout: document
redirect_from:
- /library/math/primitive_root.hpp
- /library/math/primitive_root.hpp.html
title: "primitive root(\u539F\u59CB\u6839)"
---