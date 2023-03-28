---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
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
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline\
    \ void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void\
    \ chmin(T&x,T y){if(x>y)x=y;}\n#line 2 \"math/mod_pow.hpp\"\ntemplate <class T,\
    \ class U = T>\nU mod_pow(T base, T exp, T mod){\n    T ans = 1;\n    base %=\
    \ mod;\n    while (exp > 0) {\n        if (exp & 1) {\n            ans *= base;\n\
    \            ans %= mod;\n        }\n        base *= base;\n        base %= mod;\n\
    \        exp >>= 1;\n    }\n    return ans;\n}\n///@brief mod pow(\u30D0\u30A4\
    \u30CA\u30EA\u6CD5)\n#line 3 \"string/rolling_hash.hpp\"\nclass RollingHash {\n\
    \tusing ull = uint_fast64_t;\n    using i128 = __int128_t;\n    using u128 = __uint128_t;\n\
    \    // mod\n\tstatic constexpr ull msk30 = (1ul << 30) - 1;\n\tstatic constexpr\
    \ ull msk61 = (1ul << 31) - 1;\n\tstring str;\n\tvector<ull> hash, pow;\n\n  \
    \  static const ull mod = (1uL << 61) - 1;\n    static const ull primitive_root\
    \ = 37;\npublic:\n\tstatic const uint mapping_max = 'Z' + 1;\n\tstatic ull base;\n\
    private:\n\tull mul(const u128& a,const u128& b) const {\n        u128 t = a *\
    \ b;\n\n\t\tt = (t >> 61) + (t & mod);\n\n\t\tif (t >= mod) {\n\t\t\tt -= mod;\n\
    \t\t}\n\n\n\t\treturn t;\n    }\n\n    ull mapping(const char& c) const {\n\t\t\
    return (ull)c;\t//\u5909\u66F4\u3059\u308B?\n\t}\n\n\n    static ull strong_rand()\
    \ {\n\t\tmt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\tuniform_int_distribution<ull> rand(1uL, mod - 1);\n\t\treturn rand(engine);\n\
    \t}\t\n    static void generate_base() {\n\t\tif (base != 0){\n\t\t\treturn;\n\
    \t\t}\n\t\tull r = mod - 1;\n\n\t\twhile (gcd(r, mod - 1) != 1 || r <= mapping_max){\n\
    \t\t\tr = strong_rand();\n\t\t}\n\t\tbase = mod_pow<__uint128_t>(primitive_root,\
    \ r, mod);\n\t}\npublic:\n\tRollingHash() :str() {\t}\n\n\tRollingHash(const string&\
    \ str) :str(str) {\n\t\tgenerate_base();\n\t\tbuild();\n\t}\n\n\tvoid build()\
    \ {\n\t\thash.resize(str.size() + 1);\n\t\tpow.resize(str.size() + 1, 1);\n\n\t\
    \tfor (int i = 0; i < str.size(); i++) {\n\t\t\thash[i + 1] = mul(hash[i], base)\
    \ + mapping(str[i]);\n\t\t\tpow[i + 1] = mul(pow[i], base);\n\t\t\tif (hash[i\
    \ + 1] >= mod) {\n\t\t\t\thash[i + 1] -= mod;\n\t\t\t}\n\t\t}\n\t}\n\tull range(int\
    \ l, int r) const {\n\t\tull res = mod + hash[r] - mul(hash[l], pow[r - l]);\n\
    \t\treturn res < mod ? res : res - mod;\n\t}\n\tull get_all() const {\n\t\treturn\
    \ hash.back();\n\t}\n\tint size() const {return str.size();}\n\n    static int\
    \ lcp(const RollingHash &a, const RollingHash &b, const int &start_a, const int\
    \ &start_b) {\n        int ok = 0;\n        int ng = min(a.size() - start_a, b.size()\
    \ - start_b) + 1;\n\t\twhile (abs(ok - ng) > 1){\n\t\t\tint md = (ok + ng) >>\
    \ 1;\n            if (a.range(start_a, start_a + md) == b.range(start_b, start_b\
    \ + md)){\n                ok = md;\n            }\n            else{\n      \
    \          ng = md;\n            }\n\t\t}\n\n\t\treturn ok;\n    }\n};\ntypename\
    \ RollingHash::ull RollingHash::base;\n\n///@brief Rollinghash(\u30ED\u30FC\u30EA\
    \u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)\n#line 5 \"test/AOJ/ALDS/14/B.test.cpp\"\
    \nint main() {\n\tstring t, p;\n\tcin >> t >> p;\n\tRollingHash hasht(t), hashp(p);\n\
    \tfor (int i = 0; i + p.size() <= t.size(); i++) {\n\t\tif (hasht.range(i, i +\
    \ p.size()) == hashp.range(0,p.size())) {\n\t\t\tcout << i << '\\n';\n\t\t}\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\
    \n#include\"template.hpp\"\n#include\"string/rolling_hash.hpp\"\nint main() {\n\
    \tstring t, p;\n\tcin >> t >> p;\n\tRollingHash hasht(t), hashp(p);\n\tfor (int\
    \ i = 0; i + p.size() <= t.size(); i++) {\n\t\tif (hasht.range(i, i + p.size())\
    \ == hashp.range(0,p.size())) {\n\t\t\tcout << i << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - template.hpp
  - string/rolling_hash.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS/14/B.test.cpp
  requiredBy: []
  timestamp: '2023-03-28 10:54:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS/14/B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS/14/B.test.cpp
- /verify/test/AOJ/ALDS/14/B.test.cpp.html
title: test/AOJ/ALDS/14/B.test.cpp
---
