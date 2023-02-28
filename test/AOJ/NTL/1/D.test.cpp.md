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
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  - icon: ':question:'
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
    \ T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"math/fast_prime_check.hpp\"\
    \nclass MillerRabin {\n    using i128 = __int128_t;\n    const vector<ll> bases\
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
    \u6CD5)\n#line 3 \"math/fast_fact.hpp\"\nclass Rho{\n    using i128=__int128_t;\n\
    \    mt19937 mt;\n    MillerRabin mr;\n    long long c;\n    ll f(i128 x,ll n){\n\
    \        x%=n;\n        return (x*x%n+c)%n;\n    }\npublic:\n    Rho(){\n    \
    \    mt.seed(clock());\n    }\nprivate:\n    ll find_factor(ll n){\n        if(n==4){\n\
    \            return 2;\n        }\n        c=mt()%n;\n        ll x=mt()%n;\n \
    \       ll y=x;\n        ll d=1;\n\n        while(d==1){\n            x=f(x,n);\n\
    \            y=f(f(y,n),n);\n            d=__gcd(abs(x-y),n);\n        }\n\n \
    \       if(d==n){\n            return -1;\n        }\n        return d;\n    }\n\
    \n\n    vector<ll> rho_fact(const ll&n){\n        if(n<2){\n            return\
    \ {};\n        }\n        if(mr.is_prime(n)){\n            return{n};\n      \
    \  }\n        ll d=-1;\n        while(d==-1){\n            d=find_factor(n);\n\
    \        }\n        vector<ll> v1=fact(d);\n        vector<ll> v2=fact(n/d);\n\
    \        v1.insert(v1.end(),v2.begin(),v2.end());\n        return v1;\n    }\n\
    \    vector<ll> naive_fact(ll n){\n        vector<ll> ret;\n        for (ll div\
    \ = 2; div * div <= n; div++) {\n            if (n % div != 0)continue;\n    \
    \        ll exp = 0;\n            while (n % div == 0) {\n                ret.push_back(div);\n\
    \                n /= div;\n            }\n        }\n        if (n != 1)ret.push_back(n);\n\
    \        return ret;\n    }\n\npublic:\n    vector<ll> fact(const ll n){\n   \
    \     vector<ll> res;\n        res=rho_fact(n);\n        sort(all(res));\n   \
    \     return res;\n    }\n};\n///@brief fast factorize(Pollard Rho\u306E\u7D20\
    \u56E0\u6570\u5206\u89E3)\n#line 3 \"math/phi_function.hpp\"\nll phi_func(ll n){\n\
    \    ll res=n;\n    Rho rho;\n    auto pf=rho.fact(n);\n    pf.erase(unique(all(pf)),pf.end());\
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
  isVerificationFile: true
  path: test/AOJ/NTL/1/D.test.cpp
  requiredBy: []
  timestamp: '2023-02-28 20:50:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL/1/D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL/1/D.test.cpp
- /verify/test/AOJ/NTL/1/D.test.cpp.html
title: test/AOJ/NTL/1/D.test.cpp
---
