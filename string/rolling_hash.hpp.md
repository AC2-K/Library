---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS/14/B.test.cpp
    title: test/AOJ/ALDS/14/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/string/Z algorithm with Hash.test.cpp
    title: test/yosupo judge/string/Z algorithm with Hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: rolling hash
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n\n#line 1 \"math/mod_pow.hpp\"\
    \nll mod_pow(ll base, ll exp, ll mod) {\n    if(base==0)return 0;\n    ll ans\
    \ = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp & 1) {\n    \
    \        ans *= base;\n            ans %= mod;\n        }\n        base *= base;\n\
    \        base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n///@brief\
    \ mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)\n#line 4 \"string/rolling_hash.hpp\"\
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
    \ % mod;\n\t}\n};\n\n///@brief rolling hash\n"
  code: "#pragma once\n\n#include\"math/mod_pow.hpp\"\nclass RollingHash {\n\t\n\t\
    static const ll mod = 998244343;\n\tstatic const ll g = 3;\t//\u539F\u59CB\u6839\
    \n\tll base;\n\tvector<ll> powers;\n\tstatic inline ll generate_base() {\n\t\t\
    mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\t\
    \tuniform_int_distribution<ll> rand((ll)1, (ll)mod - 1);\n\t\treturn rand(engine);\n\
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
    \ % mod;\n\t}\n};\n\n///@brief rolling hash"
  dependsOn:
  - math/mod_pow.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-02-23 15:50:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo judge/string/Z algorithm with Hash.test.cpp
  - test/AOJ/ALDS/14/B.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: rolling hash
---
