---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo judge/string/Z algorithm with Hash.test.cpp
    title: test/yosupo judge/string/Z algorithm with Hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: rolling hash
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.hpp\"\nclass RollingHash {\n\tstatic\
    \ const ll mod = 998244353;\n\tconst ll base;\n\tvector<ll> pow;\n\tstatic inline\
    \ ll generate_base() {\n\t\tmt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\tuniform_int_distribution<ll> rand((ll)1, (ll)mod - 1);\n\t\treturn rand(engine);\n\
    \t}\n\t//id\n\tll id(char c) {\n\t\treturn (c - 'a' + 1);\n\t}\n\tvoid expand(int\
    \ siz) {\n\t\tif ((int)pow.size() >= siz)return;\n\n\t\tint pre_siz = pow.size();\n\
    \t\tpow.resize(siz + 1);\n\t\tfor (int i = pre_siz; i <= siz; i++) {\n\t\t\tpow[i]\
    \ = (pow[i - 1] * base) % mod;\n\t\t}\n\t}\n\npublic:\n\tRollingHash(ll base_\
    \ = generate_base()) :base(base_), pow{ 1 } {\t}\n\tvector<ll> build(string& s)\
    \ {\n\t\tvector<ll> hash(s.size() + 1);\n\t\tfor (int i = 0; i < (int)s.size();\
    \ i++) {\n\t\t\thash[i + 1] = (hash[i] * base % mod + id(s[i])) % mod;\n\t\t}\n\
    \t\treturn hash;\n\t}\n\tll range(vector<ll>& hash, int l, int r) {\n\t\texpand(r\
    \ - l);\n\t\treturn ((hash[r] + mod - hash[l] * pow[r - l]) % mod + mod) % mod;\n\
    \t}\n};\n///@brief rolling hash\n"
  code: "class RollingHash {\n\tstatic const ll mod = 998244353;\n\tconst ll base;\n\
    \tvector<ll> pow;\n\tstatic inline ll generate_base() {\n\t\tmt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\tuniform_int_distribution<ll> rand((ll)1, (ll)mod - 1);\n\t\treturn rand(engine);\n\
    \t}\n\t//id\n\tll id(char c) {\n\t\treturn (c - 'a' + 1);\n\t}\n\tvoid expand(int\
    \ siz) {\n\t\tif ((int)pow.size() >= siz)return;\n\n\t\tint pre_siz = pow.size();\n\
    \t\tpow.resize(siz + 1);\n\t\tfor (int i = pre_siz; i <= siz; i++) {\n\t\t\tpow[i]\
    \ = (pow[i - 1] * base) % mod;\n\t\t}\n\t}\n\npublic:\n\tRollingHash(ll base_\
    \ = generate_base()) :base(base_), pow{ 1 } {\t}\n\tvector<ll> build(string& s)\
    \ {\n\t\tvector<ll> hash(s.size() + 1);\n\t\tfor (int i = 0; i < (int)s.size();\
    \ i++) {\n\t\t\thash[i + 1] = (hash[i] * base % mod + id(s[i])) % mod;\n\t\t}\n\
    \t\treturn hash;\n\t}\n\tll range(vector<ll>& hash, int l, int r) {\n\t\texpand(r\
    \ - l);\n\t\treturn ((hash[r] + mod - hash[l] * pow[r - l]) % mod + mod) % mod;\n\
    \t}\n};\n///@brief rolling hash"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-02-21 12:11:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo judge/string/Z algorithm with Hash.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: rolling hash
---
