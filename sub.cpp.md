---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/fast_prime_check.hpp
    title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A)"
  - icon: ':x:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':x:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"sub.cpp\"\n#line 1 \"main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconstexpr long double pi = acos(-1);\nconstexpr ll MOD = 1e9 + 7;\n\
    constexpr ll MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"math/mod_pow.hpp\"\
    \ntemplate <class T, class U = T>\nU mod_pow(T base, T exp, T mod){\n    if(base==0)return\
    \ 0;\n    T ans = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp\
    \ & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n     \
    \   base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)\n#line 3 \"math/fast_prime_check.hpp\"\
    \nnamespace prime {\n    namespace miller{\n        using i128 = __int128_t;\n\
    \        using u128 = __uint128_t;\n        using u64 = __uint64_t;\n        bool\
    \ miller_rabin(u64 n,const u64 bases[],int siz) {\n            u64 d = n - 1;\n\
    \            u64 q = __builtin_ctz(d);\n            d >>= q;\n\n            for(int\
    \ i=0;i<siz;i++){\n                u64 a = bases[i];\n                if (a ==\
    \ n) {\n                    return true;\n                } else if (n % a ==\
    \ 0) {\n                    return false;\n                }\n               \
    \ if (mod_pow<u128>(a, d, n) != 1) {\n                    bool flag = true;\n\
    \                    for (u64 r = 0; r < q; r++) {\n                        u64\
    \ pow = mod_pow<u128>(a, d * (1ll << r), n);\n                        if (pow\
    \ == n - 1) {\n                            flag = false;\n                   \
    \         break;\n                        }\n                    }\n\n       \
    \             if (flag) {\n                        return false;\n           \
    \         }\n                }\n            }\n            return true;\n    \
    \    }\n\n\n        bool is_prime(u64 n){\n            static constexpr u64 bases_int[3]\
    \ = {2, 7, 61};  // int\u3060\u3068\u30012,7,61\u3067\u5341\u5206\n          \
    \  static constexpr u64 bases_ll[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\
    \            if (n < 2) {\n                return false;\n            } else if\
    \ (n == 2) {\n                return true;\n            } else if (~n & 1) {\n\
    \                return false;\n            }\n\n            if(n<(1ul<<31)){\n\
    \                return miller_rabin(n, bases_int, 3);\n            } else {\n\
    \                return miller_rabin(n, bases_ll, 7);\n            }\n       \
    \ }\n    };\n};\nusing prime::miller::is_prime;\n///@brief fast prime check(MillerRabin\u306E\
    \u7D20\u6570\u5224\u5B9A)\n#line 5 \"sub.cpp\"\nnamespace prime{\n    namespace\
    \ pollard{\n        using i128 = __int128_t;\n        using u128 = __uint128_t;\n\
    \        using u64 = __uint64_t;\n        u64 c;\n        u64 xor_shift() { \n\
    \            static u64 v = 7001;\n            v ^= v << 13;\n            v ^=\
    \ v >> 7;\n            v ^= v << 17;\n\n            return v;\n        }\n   \
    \     i128 gcd(i128 x,i128 y){\n            while(y!=0){\n                i128\
    \ ny = x % y;\n                i128 nx = y;\n                x = nx, y = ny;\n\
    \            }\n            return x;\n        }\n        u64 find_factor(u64\
    \ n){\n            if (~n & 1ul) {\n                return 2;\n            }\n\
    \            if (is_prime(n)) {\n                return n;\n            }\n  \
    \          while(1){\n                auto f = [&](i128 x) -> u64 {\n        \
    \            x %= n;\n                    return (x * x % n + c) % n;\n      \
    \          };\n                c = xor_shift() % n;\n                ll x = xor_shift()\
    \ % n;\n                ll y = x;\n                ll d = 1;\n               \
    \ while (d == 1) {\n                    x = f(x);\n                    y = f(f(y));\n\
    \n                    d = gcd(abs(x - y), n);\n                }\n           \
    \     if (d != n) {\n                    return d;\n                }\n      \
    \      }\n            exit(0);\n        }\n\n        vector<u64> rho_fact(u64\
    \ n){\n            vector<u64> v;\n            while (n != 1) {\n            \
    \    u64 d = 0;\n                d = find_factor(n);\n                while (n\
    \ % d == 0) {\n                    n /= d;\n                    v.emplace_back(d);\n\
    \                }\n            }\n            return v;\n        }\n        vector<u64>\
    \ naive(u64&n){\n            static constexpr u64 basic_prime[] = {2, 3, 5, 7,\
    \ 11, 13, 17, 1000000007, 998244353};\n            vector<u64> res;\n        \
    \    for (const auto& p : basic_prime) {\n                while (n % p == 0) {\n\
    \                    n /= p;\n                    res.emplace_back(p);\n     \
    \           }\n            }\n\n            return res;\n        }\n        vector<u64>\
    \ fact(u64 n){\n            if (n < 2) {\n                return {};\n       \
    \     }\n            if (is_prime(n)) {\n                return {n};\n       \
    \     }\n\n            vector<u64> v = naive(n);\n            if (n != 1) {\n\
    \                vector<u64> res = rho_fact(n);\n                v.insert(v.end(),\
    \ all(res));\n            }\n            sort(all(v));\n            return v;\n\
    \        }\n    };  // namespace pollard\n};  // namespace prime\nusing prime::pollard::fact;\n\
    \nint main(){\n    int t;\n    cin >> t;\n    while (t--) {\n        __uint64_t\
    \ x;\n        cin >> x;\n        auto pf = fact(x);\n        cout << pf.size()\
    \ << ' ';\n        for (const auto& p : pf) {\n            cout << p << ' ';\n\
    \        }\n        cout << '\\n';\n    }\n}\n"
  code: "#line 1 \"main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#include\"template.hpp\"\n#include\"math/fast_prime_check.hpp\"\nnamespace prime{\n\
    \    namespace pollard{\n        using i128 = __int128_t;\n        using u128\
    \ = __uint128_t;\n        using u64 = __uint64_t;\n        u64 c;\n        u64\
    \ xor_shift() { \n            static u64 v = 7001;\n            v ^= v << 13;\n\
    \            v ^= v >> 7;\n            v ^= v << 17;\n\n            return v;\n\
    \        }\n        i128 gcd(i128 x,i128 y){\n            while(y!=0){\n     \
    \           i128 ny = x % y;\n                i128 nx = y;\n                x\
    \ = nx, y = ny;\n            }\n            return x;\n        }\n        u64\
    \ find_factor(u64 n){\n            if (~n & 1ul) {\n                return 2;\n\
    \            }\n            if (is_prime(n)) {\n                return n;\n  \
    \          }\n            while(1){\n                auto f = [&](i128 x) -> u64\
    \ {\n                    x %= n;\n                    return (x * x % n + c) %\
    \ n;\n                };\n                c = xor_shift() % n;\n             \
    \   ll x = xor_shift() % n;\n                ll y = x;\n                ll d =\
    \ 1;\n                while (d == 1) {\n                    x = f(x);\n      \
    \              y = f(f(y));\n\n                    d = gcd(abs(x - y), n);\n \
    \               }\n                if (d != n) {\n                    return d;\n\
    \                }\n            }\n            exit(0);\n        }\n\n       \
    \ vector<u64> rho_fact(u64 n){\n            vector<u64> v;\n            while\
    \ (n != 1) {\n                u64 d = 0;\n                d = find_factor(n);\n\
    \                while (n % d == 0) {\n                    n /= d;\n         \
    \           v.emplace_back(d);\n                }\n            }\n           \
    \ return v;\n        }\n        vector<u64> naive(u64&n){\n            static\
    \ constexpr u64 basic_prime[] = {2, 3, 5, 7, 11, 13, 17, 1000000007, 998244353};\n\
    \            vector<u64> res;\n            for (const auto& p : basic_prime) {\n\
    \                while (n % p == 0) {\n                    n /= p;\n         \
    \           res.emplace_back(p);\n                }\n            }\n\n       \
    \     return res;\n        }\n        vector<u64> fact(u64 n){\n            if\
    \ (n < 2) {\n                return {};\n            }\n            if (is_prime(n))\
    \ {\n                return {n};\n            }\n\n            vector<u64> v =\
    \ naive(n);\n            if (n != 1) {\n                vector<u64> res = rho_fact(n);\n\
    \                v.insert(v.end(), all(res));\n            }\n            sort(all(v));\n\
    \            return v;\n        }\n    };  // namespace pollard\n};  // namespace\
    \ prime\nusing prime::pollard::fact;\n\nint main(){\n    int t;\n    cin >> t;\n\
    \    while (t--) {\n        __uint64_t x;\n        cin >> x;\n        auto pf\
    \ = fact(x);\n        cout << pf.size() << ' ';\n        for (const auto& p :\
    \ pf) {\n            cout << p << ' ';\n        }\n        cout << '\\n';\n  \
    \  }\n}"
  dependsOn:
  - template.hpp
  - math/fast_prime_check.hpp
  - math/mod_pow.hpp
  isVerificationFile: false
  path: sub.cpp
  requiredBy: []
  timestamp: '2023-03-05 17:39:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: sub.cpp
layout: document
redirect_from:
- /library/sub.cpp
- /library/sub.cpp.html
title: sub.cpp
---
