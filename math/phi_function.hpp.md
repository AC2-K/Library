---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/fast_fact.hpp
    title: "Rho\u6CD5"
  - icon: ':heavy_check_mark:'
    path: math/fast_prime_check.hpp
    title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_D.test.cpp
    title: test/AOJ/NTL_1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570"
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
    \    }\n            }\n        }\n        return true;\n    }\n};\n///@brief MillerRabin\u306E\
    \u7D20\u6570\u5224\u5B9A\n#line 3 \"math/fast_fact.hpp\"\nclass Rho{\n    using\
    \ i128=__int128_t;\n    mt19937 mt;\n    MillerRabin mr;\n    long long c;\n \
    \   ll f(i128 x,ll n){\n        x%=n;\n        return (x*x%n+c)%n;\n    }\npublic:\n\
    \    Rho(){\n        mt.seed(clock());\n    }\nprivate:\n    ll find_factor(ll\
    \ n){\n        if(n==4){\n            return 2;\n        }\n        c=mt()%n;\n\
    \        ll x=mt()%n;\n        ll y=x;\n        ll d=1;\n\n        while(d==1){\n\
    \            x=f(x,n);\n            y=f(f(y,n),n);\n            d=__gcd(abs(x-y),n);\n\
    \        }\n\n        if(d==n){\n            return -1;\n        }\n        return\
    \ d;\n    }\n\n\n    vector<ll> rho_fact(const ll&n){\n        if(n<2){\n    \
    \        return {};\n        }\n        if(mr.is_prime(n)){\n            return{n};\n\
    \        }\n        ll d=-1;\n        while(d==-1){\n            d=find_factor(n);\n\
    \        }\n        vector<ll> v1=fact(d);\n        vector<ll> v2=fact(n/d);\n\
    \        v1.insert(v1.end(),v2.begin(),v2.end());\n        return v1;\n    }\n\
    \    vector<ll> naive_fact(ll n){\n        vector<ll> ret;\n        for (ll div\
    \ = 2; div * div <= n; div++) {\n            if (n % div != 0)continue;\n    \
    \        ll exp = 0;\n            while (n % div == 0) {\n                ret.push_back(div);\n\
    \                n /= div;\n            }\n        }\n        if (n != 1)ret.push_back(n);\n\
    \        return ret;\n    }\n\npublic:\n    vector<ll> fact(const ll n){\n   \
    \     vector<ll> res;\n        if(n<=1000){\n            res=naive_fact(n);\n\
    \        }else{\n            res=rho_fact(n);\n        }\n        sort(all(res));\n\
    \        return res;\n    }\n};\n///@brief Rho\u6CD5\n#line 3 \"math/phi_function.hpp\"\
    \nll phi_func(ll n){\n    ll res=n;\n    Rho rho;\n    auto pf=rho.fact(n);\n\
    \    pf.erase(unique(all(pf)),pf.end());     \n    for(auto&d:pf){\n        res=res/d*(d-1);\n\
    \    }\n    return res;\n}\n///@brief \u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\
    \u6570\n"
  code: "#pragma once\n#include\"math/fast_fact.hpp\"\nll phi_func(ll n){\n    ll\
    \ res=n;\n    Rho rho;\n    auto pf=rho.fact(n);\n    pf.erase(unique(all(pf)),pf.end());\
    \     \n    for(auto&d:pf){\n        res=res/d*(d-1);\n    }\n    return res;\n\
    }\n///@brief \u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570"
  dependsOn:
  - math/fast_fact.hpp
  - math/fast_prime_check.hpp
  isVerificationFile: false
  path: math/phi_function.hpp
  requiredBy: []
  timestamp: '2023-02-21 12:21:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL_1_D.test.cpp
documentation_of: math/phi_function.hpp
layout: document
redirect_from:
- /library/math/phi_function.hpp
- /library/math/phi_function.hpp.html
title: "\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570"
---
