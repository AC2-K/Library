---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: rolling hash
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
  bundledCode: "#line 1 \"test/AOJ/ALDS/14/B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing ll = long long;\n//using i128=__int128_t;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps = 1e-6;\nconst\
    \ long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\n\
    const int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class\
    \ T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T\
    \ y){if(x>y)x=y;}\n#line 2 \"string/rolling_hash.hpp\"\n\n#line 1 \"math/mod_pow.hpp\"\
    \nll mod_pow(ll base, ll exp, ll mod) {\n    if(base==0)return 0;\n    ll ans\
    \ = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp & 1) {\n    \
    \        ans *= base;\n            ans %= mod;\n        }\n        base *= base;\n\
    \        base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\ntemplate<typename\
    \ T>\n__int128_t large_modpow(T base,T exp,T mod){\n    if(base==0)return 0;\n\
    \    __int128_t ans = 1;\n    base %= mod;\n    while (exp > 0) {\n        if\
    \ (exp & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n\
    \        base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)\n#line 4 \"string/rolling_hash.hpp\"\
    \nclass RollingHash {\n\t\n\tstatic const ll mod = 998244343;\n\tstatic const\
    \ ll g = 3;\t//\u539F\u59CB\u6839\n\tll base;\n\tvector<ll> powers;\n\tstatic\
    \ inline ll generate_base() {\n\t\tmt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\tuniform_int_distribution<ll> rand((ll)1, (ll)mod - 1);\n\t\treturn rand(engine);\n\
    \t}\n\t//id\u306E\u632F\u308A\u65B9\n\tll mapping(char c) {\n\t\treturn (c - 'a'\
    \ + 1);\n\t}\n\tvoid expand(int siz) {\n\t\tif (powers.size() < siz + 1) {\n\t\
    \t\tint pre_siz = powers.size();\n\t\t\tpowers.resize(siz + 1);\n\t\t\tfor (int\
    \ i = pre_siz; i <= siz; i++) {\n\t\t\t\tpowers[i] = (powers[i - 1] * base) %\
    \ mod;\n\t\t\t}\n\t\t}\n\t}\n\npublic:\n\tRollingHash() :base(), powers{ 1 } {\n\
    \t\tll r = mod - 1;\n\t\twhile(gcd(r,mod-1) != 1){\n\t\t\tr = generate_base();\n\
    \t\t}\n\n\t\tbase = mod_pow(g,r,mod);\n\t} \n\n\tvector<ll> build(string& s) {\n\
    \t\tvector<ll> hash(s.size() + 1);\n\t\tfor (int i = 0; i < s.size(); i++) {\n\
    \t\t\thash[i + 1] = (hash[i] * base % mod + mapping(s[i])) % mod;\n\t\t}\n\t\t\
    return hash;\n\t}\n\tll range(vector<ll>&hash,int l, int r) {\n\t\texpand(r -\
    \ l);\n\t\treturn ((hash.at(r) + mod - hash.at(l) * powers[r - l]) % mod + mod)\
    \ % mod;\n\t}\n};\n\n///@brief rolling hash\n#line 5 \"test/AOJ/ALDS/14/B.test.cpp\"\
    \nint main() {\n\tstring T, P;\n\tcin >> T >> P;\n\tif (T.size() < P.size())exit(0);\n\
    \tRollingHash rh;\n\tauto t = rh.build(T);\n\tauto p = rh.build(P);\n\tll hash\
    \ = rh.range(p,0, P.size());\n\tfor (int i = 0; i < T.size() - P.size() + 1; i++)\
    \ {\n\t\tif (rh.range(t, i, i + P.size()) == hash) {\n\n\t\t\tcout << i << '\\\
    n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\
    \n#include \"template.hpp\"\n#include\"string/rolling_hash.hpp\"\nint main() {\n\
    \tstring T, P;\n\tcin >> T >> P;\n\tif (T.size() < P.size())exit(0);\n\tRollingHash\
    \ rh;\n\tauto t = rh.build(T);\n\tauto p = rh.build(P);\n\tll hash = rh.range(p,0,\
    \ P.size());\n\tfor (int i = 0; i < T.size() - P.size() + 1; i++) {\n\t\tif (rh.range(t,\
    \ i, i + P.size()) == hash) {\n\n\t\t\tcout << i << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - template.hpp
  - string/rolling_hash.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS/14/B.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 23:47:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS/14/B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS/14/B.test.cpp
- /verify/test/AOJ/ALDS/14/B.test.cpp.html
title: test/AOJ/ALDS/14/B.test.cpp
---
