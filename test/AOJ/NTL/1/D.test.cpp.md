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
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/prime_list.hpp
    title: "\u7D20\u6570\u8868"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
  bundledCode: "#line 1 \"test/AOJ/NTL/1/D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll\
    \ MOD2 = 998244353;\nconst int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1\
    \ };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class\
    \ T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 2 \"math/large_mod.hpp\"\n\
    inline long long safe_mod(long long a, long long m){\n    return (a % m + m) %\
    \ m;\n}\nlong long mul(long long a, long long b, long long m) {\n    a = safe_mod(a,\
    \ m);\n    b = safe_mod(b, m);\n    if (b == 0) return 0;\n    long long res =\
    \ mul(safe_mod(a + a, m), b >> 1, m);\n    if (b & 1){\n        res = safe_mod(res\
    \ + a, m);\n    }\n    return res;\n}\ntemplate<typename T>\nT large_modpow(T\
    \ base,T exp,T mod){\n    T ans = 1 % mod;\n    base %= mod;\n    while (exp)\
    \ {\n        if (exp & 1) {\n            ans = mul(ans, base, mod);\n        }\n\
    \        base = mul(base, base, mod);\n        exp >>= 1;\n    }\n    return ans;\n\
    }\n\nunsigned long long i128_modpow(__uint128_t base, __uint128_t exp, unsigned\
    \ long long mod){\n    i128 res = (mod == 1 ? 0 : 1);\n    base %= mod;\n    while\
    \ (exp){\n        if (exp & 1){\n            res = (res * base) % mod;\n     \
    \   }\n        base = (base * base) % mod;\n        exp >>= 1;\n    }\n    return\
    \ res;\n}\n#line 3 \"math/fast_prime_check.hpp\"\n\nnamespace prime\n{\n    using\
    \ ull = unsigned long long;\n    // MillerRabin\n    bool is_prime_long(ull n){\n\
    \        static const vector<ull> bases \n            = {2ull, 325ull, 9375ull,\
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
    \ 983, 991, 997};\n//\u7D20\u6570300\u500B\nconstexpr int small_prime [] = {2,\
    \ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,\
    \ 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,\
    \ 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241,\
    \ 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347,\
    \ 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439,\
    \ 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547,\
    \ 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,\
    \ 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751,\
    \ 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859,\
    \ 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977,\
    \ 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063,\
    \ 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163,\
    \ 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259,\
    \ 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361,\
    \ 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453,\
    \ 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549,\
    \ 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621,\
    \ 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733,\
    \ 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847,\
    \ 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949,\
    \ 1951, 1973, 1979, 1987};\n\n///@brief \u7D20\u6570\u8868\n#line 4 \"math/fast_fact.hpp\"\
    \nnamespace prime\n{\n    using ull = unsigned long long;\n    // Rho factorize\n\
    \n    ull find_factor(ull& n) {\n        if (is_prime(n)) {\n            return\
    \ n;\n        }\n        static ull v = 7001;\n        v ^= v << 13, v ^= v >>\
    \ 7, v ^= v << 17;\n\n        if (~n & 1uL) {\n            return 2;\n       \
    \ }\n        static ull c = v;\n        auto f = [&](i128 xx) -> ll {\n      \
    \      xx %= n;\n            return (xx * xx % n + c) % n;\n        };\n     \
    \   ll x = v % n;\n        ll y = x;\n        ull d = 1;\n\n        while (d ==\
    \ 1) {\n            x = f(x);\n            y = f(f(y));\n            d = gcd(abs(x\
    \ - y), n);\n        }\n\n        if (d == n) {\n            return 0;\n     \
    \   }\n        return d;\n    }\n    vector<ull> rho_fact(ull& n) {\n        if\
    \ (n < 2) {\n            return {};\n        }\n        if (is_prime(n)) {\n\n\
    \        }\n        vector<ull> res;\n        while (n != 1) {\n            ull\
    \ d = 0;\n            while (d == 0) {\n                d = find_factor(n);\n\
    \            }\n            while (n % d == 0) {\n                res.emplace_back(d);\n\
    \                n /= d;\n            }\n        }\n\n        return res;\n  \
    \  }\n\n    vector<ull> naive_fact(ull& n) {\n        vector<ull> res;\n\n   \
    \     for (const ull& d : small_prime) {\n            while (n % d == 0) {\n \
    \               res.emplace_back(d);\n                n /= d;\n            }\n\
    \        }\n        return res;\n    }\n\n    vector<ull> fact(ull n) {\n    \
    \    vector<ull> res = naive_fact(n);\n        if (n != 1) {\n            vector<ull>\
    \ res2 = rho_fact(n);\n            res.insert(res.end(), all(res2));\n       \
    \ }\n        sort(all(res));\n        return res;\n    }\n};\n///@brief fast factorize(Pollard\
    \ Rho\u306E\u7D20\u56E0\u6570\u5206\u89E3)\n#line 3 \"math/phi_function.hpp\"\n\
    ll phi_func(ll n){\n    ll res=n;\n    auto pf=prime::fact(n);\n    pf.erase(unique(all(pf)),pf.end());\
    \     \n    for(auto&d:pf){\n        res=res/d*(d-1);\n    }\n    return res;\n\
    }\n///@brief phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)\n\
    #line 5 \"test/AOJ/NTL/1/D.test.cpp\"\nint main(){\n    int n;\n    cin>>n;\n\
    \    cout<<phi_func(n)<<'\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n\n#include\"template.hpp\"\n#include\"math/phi_function.hpp\"\nint main(){\n\
    \    int n;\n    cin>>n;\n    cout<<phi_func(n)<<'\\n';\n}"
  dependsOn:
  - template.hpp
  - math/phi_function.hpp
  - math/fast_fact.hpp
  - math/fast_prime_check.hpp
  - math/large_mod.hpp
  - math/prime_list.hpp
  isVerificationFile: true
  path: test/AOJ/NTL/1/D.test.cpp
  requiredBy: []
  timestamp: '2023-03-01 23:19:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL/1/D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL/1/D.test.cpp
- /verify/test/AOJ/NTL/1/D.test.cpp.html
title: test/AOJ/NTL/1/D.test.cpp
---
