---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/rolling_hash.hpp
    title: rolling hash
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo judge/string/Z algorithm with Hash.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#line 1 \"template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using ll = long long;\n//using i128=__int128_t;\nusing ld = long double;\nusing\
    \ graph = vector<vector<int>>;\nusing P = pair<int, int>;\nconst int inf = 1e9;\n\
    const ll infl = 1e18;\nconst ld eps = 1e-6;\nconst long double pi = acos(-1);\n\
    const ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\nconst int dx[4] = { 1,0,-1,0\
    \ };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"string/rolling_hash.hpp\"\nclass RollingHash {\n\tstatic const ll mod\
    \ = 998244353;\n\tconst ll base;\n\tvector<ll> pow;\n\tstatic inline ll generate_base()\
    \ {\n\t\tmt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \t}\n};\n///@brief rolling hash\n#line 4 \"test/yosupo judge/string/Z algorithm\
    \ with Hash.test.cpp\"\nint main() {\n    string s;\n    cin>>s;\n    RollingHash\
    \ rh;\n    auto hash=rh.build(s);\n    rep(i,s.size()){\n        int ng=s.size()-i+1;\n\
    \        int ok=0;\n        while(ok+1!=ng){\n            int md=(ok+ng)>>1;\n\
    \            if(rh.range(hash,i,i+md)==rh.range(hash,0,md)){\n               \
    \ ok=md;\n            }else{\n                ng=md;\n            }\n        }\n\
    \        cout<<ok<<'\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\"\
    template.hpp\"\n#include\"string/rolling_hash.hpp\"\nint main() {\n    string\
    \ s;\n    cin>>s;\n    RollingHash rh;\n    auto hash=rh.build(s);\n    rep(i,s.size()){\n\
    \        int ng=s.size()-i+1;\n        int ok=0;\n        while(ok+1!=ng){\n \
    \           int md=(ok+ng)>>1;\n            if(rh.range(hash,i,i+md)==rh.range(hash,0,md)){\n\
    \                ok=md;\n            }else{\n                ng=md;\n        \
    \    }\n        }\n        cout<<ok<<'\\n';\n    }\n}"
  dependsOn:
  - template.hpp
  - string/rolling_hash.hpp
  isVerificationFile: true
  path: test/yosupo judge/string/Z algorithm with Hash.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 14:54:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo judge/string/Z algorithm with Hash.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/string/Z algorithm with Hash.test.cpp
- /verify/test/yosupo judge/string/Z algorithm with Hash.test.cpp.html
title: test/yosupo judge/string/Z algorithm with Hash.test.cpp
---
