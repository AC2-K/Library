---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/gcd.hpp
    title: "gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306A\
      \u3069)"
  - icon: ':heavy_check_mark:'
    path: math/miller.hpp
    title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
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
    \u5B9A\n#line 1 \"math/gcd.hpp\"\ntemplate<typename T>\nstatic constexpr inline\
    \ T _gcd(T a,T b){\n    T s = a, t = b;\n    while (s % t != 0) {\n        T u\
    \ = s % t;\n\n        s = t;\n        t = u;\n    }\n    return t;\n}\ntemplate<typename\
    \ T>\nstatic constexpr inline T ext_gcd(T a, T b, T &x, T &y) {\n    x = 1, y\
    \ = 0;\n    T nx = 0, ny = 1;\n    while(b) {\n        T q = a / b;\n        tie(a,\
    \ b) = make_pair(b, a % b);\n        tie(x, nx) = make_pair(nx, x - nx*q);\n \
    \       tie(y, ny) = make_pair(ny, y - ny*q);\n    }\n    return a;\n}\n/// @return\
    \ ax+by=gcd(a,b)\u306A\u308Bx,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\u5024\
    \u306Bgcd(a,b)\n\n/// @brief gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5\u306A\u3069)\n#line 4 \"math/rho.hpp\"\n///@brief \u9AD8\u901F\u7D20\
    \u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)\nnamespace prime {\n    namespace\
    \ rho {\n        using i128 = __int128_t;\n        using u128 = __uint128_t;\n\
    \        using u64 = __uint64_t;\n\n        inline u64 find_factor(u64 n) {\n\
    \            u64 v = rand();\n\n            if (~n & 1uL) {\n                return\
    \ 2;\n            }\n            if (prime::miller::is_prime(n)) {\n         \
    \       return n;\n            }\n            while (1) {\n                v ^=\
    \ v << 13, v ^= v >> 7, v ^= v << 17;\n                u64 c = v;\n          \
    \      auto f = [&](u128 x) -> u128 {\n                    x %= n;\n         \
    \           return (x * x + c) % n;\n                };\n                v ^=\
    \ v << 13, v ^= v >> 7, v ^= v << 17;\n                ll x = v % n;\n       \
    \         ll y = f(x);\n                u64 d = 1;\n                while (d ==\
    \ 1) {\n                    d = _gcd((u64)abs(x - y), n);\n                  \
    \  x = f(x);\n                    y = f(f(y));\n                }\n          \
    \      if (1 < d && d < n) {\n                    return d;\n                }\n\
    \            }\n            exit(0);\n        }\n\n        inline vector<u64>\
    \ rho_fact(u64 n) {\n            if (n < 2) {\n                return {};\n  \
    \          }\n            if (prime::miller::is_prime(n)) {\n                return\
    \ { n };\n            }\n            vector<u64> v;\n            vector<u64> st{\
    \ n };\n            while (st.size()) {\n                u64& m = st.back();\n\
    \                if (prime::miller::is_prime(m)) {\n                    v.emplace_back(m);\n\
    \                    st.pop_back();\n                }\n                else {\n\
    \                    u64 d = find_factor(m);\n                    m /= d;\n  \
    \                  st.emplace_back(d);\n                }\n            }\n   \
    \         return v;\n        }\n        constexpr u64 basic_prime[] = { 2, 3,\
    \ 5, 7, 11, 13, 17, 1000000007, 998244353 };\n        inline vector<u64> naive(u64&\
    \ n) {\n            \n            vector<u64> res;\n            for (const auto&\
    \ p : basic_prime) {\n                while (n % p == 0) {\n                 \
    \   n /= p;\n                    res.emplace_back(p);\n                }\n   \
    \         }\n\n            return res;\n        }\n        inline vector<u64>\
    \ factorize(u64 n) {\n            if (n < 2) {\n                return {};\n \
    \           }\n            vector<u64> v = naive(n);\n            if (n != 1)\
    \ {\n                vector<u64> v2 = rho_fact(n);\n                v.insert(v.end(),\
    \ all(v2));\n            }\n            sort(all(v));\n            return v;\n\
    \        }\n\n        vector<pair<u64, int>> exp_factorize(u64 n) {\n        \
    \    auto pf = factorize(n);\n            if (pf.empty()) {\n                return\
    \ {};\n            }\n            vector<pair<u64, int>> res;\n            res.emplace_back(pf.front(),\
    \ 1);\n            //rle\n            for (int i = 1; i < pf.size(); i++) {\n\
    \                if (res.back().first == pf[i]) {\n                    res.back().second++;\n\
    \                }\n                else {\n                    res.emplace_back(pf[i],\
    \ 1);\n                }\n            }\n\n            return res;\n        }\n\
    \    };  // namespace pollard\n};  // namespace prime\n"
  code: "#pragma once\n#include\"math/miller.hpp\"\n#include\"math/gcd.hpp\"\n///@brief\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)\nnamespace prime\
    \ {\n    namespace rho {\n        using i128 = __int128_t;\n        using u128\
    \ = __uint128_t;\n        using u64 = __uint64_t;\n\n        inline u64 find_factor(u64\
    \ n) {\n            u64 v = rand();\n\n            if (~n & 1uL) {\n         \
    \       return 2;\n            }\n            if (prime::miller::is_prime(n))\
    \ {\n                return n;\n            }\n            while (1) {\n     \
    \           v ^= v << 13, v ^= v >> 7, v ^= v << 17;\n                u64 c =\
    \ v;\n                auto f = [&](u128 x) -> u128 {\n                    x %=\
    \ n;\n                    return (x * x + c) % n;\n                };\n      \
    \          v ^= v << 13, v ^= v >> 7, v ^= v << 17;\n                ll x = v\
    \ % n;\n                ll y = f(x);\n                u64 d = 1;\n           \
    \     while (d == 1) {\n                    d = _gcd((u64)abs(x - y), n);\n  \
    \                  x = f(x);\n                    y = f(f(y));\n             \
    \   }\n                if (1 < d && d < n) {\n                    return d;\n\
    \                }\n            }\n            exit(0);\n        }\n\n       \
    \ inline vector<u64> rho_fact(u64 n) {\n            if (n < 2) {\n           \
    \     return {};\n            }\n            if (prime::miller::is_prime(n)) {\n\
    \                return { n };\n            }\n            vector<u64> v;\n  \
    \          vector<u64> st{ n };\n            while (st.size()) {\n           \
    \     u64& m = st.back();\n                if (prime::miller::is_prime(m)) {\n\
    \                    v.emplace_back(m);\n                    st.pop_back();\n\
    \                }\n                else {\n                    u64 d = find_factor(m);\n\
    \                    m /= d;\n                    st.emplace_back(d);\n      \
    \          }\n            }\n            return v;\n        }\n        constexpr\
    \ u64 basic_prime[] = { 2, 3, 5, 7, 11, 13, 17, 1000000007, 998244353 };\n   \
    \     inline vector<u64> naive(u64& n) {\n            \n            vector<u64>\
    \ res;\n            for (const auto& p : basic_prime) {\n                while\
    \ (n % p == 0) {\n                    n /= p;\n                    res.emplace_back(p);\n\
    \                }\n            }\n\n            return res;\n        }\n    \
    \    inline vector<u64> factorize(u64 n) {\n            if (n < 2) {\n       \
    \         return {};\n            }\n            vector<u64> v = naive(n);\n \
    \           if (n != 1) {\n                vector<u64> v2 = rho_fact(n);\n   \
    \             v.insert(v.end(), all(v2));\n            }\n            sort(all(v));\n\
    \            return v;\n        }\n\n        vector<pair<u64, int>> exp_factorize(u64\
    \ n) {\n            auto pf = factorize(n);\n            if (pf.empty()) {\n \
    \               return {};\n            }\n            vector<pair<u64, int>>\
    \ res;\n            res.emplace_back(pf.front(), 1);\n            //rle\n    \
    \        for (int i = 1; i < pf.size(); i++) {\n                if (res.back().first\
    \ == pf[i]) {\n                    res.back().second++;\n                }\n \
    \               else {\n                    res.emplace_back(pf[i], 1);\n    \
    \            }\n            }\n\n            return res;\n        }\n    };  //\
    \ namespace pollard\n};  // namespace prime"
  dependsOn:
  - math/miller.hpp
  - math/mod_pow.hpp
  - math/gcd.hpp
  isVerificationFile: false
  path: math/rho.hpp
  requiredBy:
  - math/primitive_root.hpp
  - math/phi_function.hpp
  timestamp: '2023-03-31 15:06:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/new/Primitive_Root.test.cpp
documentation_of: math/rho.hpp
layout: document
redirect_from:
- /library/math/rho.hpp
- /library/math/rho.hpp.html
title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
---
