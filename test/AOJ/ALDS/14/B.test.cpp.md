---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/large_mod.hpp
    title: math/large_mod.hpp
  - icon: ':x:'
    path: string/rolling_hash.hpp
    title: rolling hash
  - icon: ':x:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ ld eps = 1e-6;\nconstexpr long double pi = acos(-1);\nconstexpr ll MOD = 1e9\
    \ + 7;\nconstexpr ll MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 2 \"math/large_mod.hpp\"\
    \ninline long long safe_mod(long long a, long long m){\n    return (a % m + m)\
    \ % m;\n}\nlong long mul(long long a, long long b, long long m) {\n    a = safe_mod(a,\
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
    \ res;\n}\n#line 3 \"string/rolling_hash.hpp\"\nnamespace for_hash {\n\tusing\
    \ ull = uint_fast64_t;\n\tconstexpr ull mapping_max = (ull)'Z';\n\tull base =\
    \ -1;\t//base\u3092\u30E9\u30F3\u30C0\u30E0\u306B\u3068\u308B\n\tconstexpr ull\
    \ mod = (1uL << 61) - 1;\n\tconstexpr ull primitive_root = 37;\n\tull strong_rand()\
    \ {\n\t\tmt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\tuniform_int_distribution<ull> rand(1uL, mod - 1);\n\t\treturn rand(engine);\n\
    \t}\n\tvoid generate_base() {\n        if(base != -1) return;\n\t\tull r = mod\
    \ - 1;\n\t\twhile (gcd(r, mod - 1) != 1 || r <= mapping_max) {\n\t\t\tr = strong_rand();\n\
    \t\t}\n\t\tbase = large_modpow(primitive_root, r, mod);\n\t}\n};\n\nclass RollingHash\
    \ {\n\tusing ull = uint_fast64_t;\n\tusing i128 = __int128_t;\t//\u5909\u3048\u307E\
    \u3057\u3087\u3046\u306D~\n\tstatic constexpr ull msk30 = (1ul << 30) - 1;\n\t\
    static constexpr ull msk61 = (1ul << 31) - 1;\n\tstring str;\n\tvector<ull> hash,\
    \ pow;\n\n\n\tull mul(i128 a, i128 b)const {\n\t\ti128 t = a * b;\n\n\t\tt = (t\
    \ >> 61) + (t & for_hash::mod);\n\n\t\tif (t >= for_hash::mod) {\n\t\t\tt -= for_hash::mod;\n\
    \t\t}\n\n\n\t\treturn t;\n\t}\n\n\tull mapping(const char& c) {\n\t\treturn (ull)c;\t\
    //\u5909\u66F4\u3059\u308B?\n\t}\npublic:\n\tRollingHash() :str() {\t}\n\n\tRollingHash(const\
    \ string& str) :str(str) {\n\t\tfor_hash::generate_base();\n\t\tbuild();\n\t}\n\
    \n\tvoid build() {\n\t\thash.resize(str.size() + 1);\n\t\tpow.resize(str.size()\
    \ + 1, 1);\n\n\t\tfor (int i = 0; i < str.size(); i++) {\n\t\t\thash[i + 1] =\
    \ mul(hash[i], for_hash::base) + mapping(str[i]);\n\t\t\tpow[i + 1] = mul(pow[i],\
    \ for_hash::base);\n\t\t\tif (hash[i + 1] >= for_hash::mod) {\n\t\t\t\thash[i\
    \ + 1] -= for_hash::mod;\n\t\t\t}\n\t\t}\n\t}\n\tull range(int l, int r) const\
    \ {\n\t\tull res = for_hash::mod + hash[r] - mul(hash[l], pow[r - l]);\n\t\treturn\
    \ res < for_hash::mod ? res : res - for_hash::mod;\n\t}\n\tull get_all(){\n\t\t\
    return hash.back();\n\t}\n\tint size(){return str.size();}\n};\n\n///@brief rolling\
    \ hash\n#line 5 \"test/AOJ/ALDS/14/B.test.cpp\"\nint main() {\n\tstring t, p;\n\
    \tcin >> t >> p;\n\tRollingHash hasht(t), hashp(p);\n\tfor (int i = 0; i + p.size()\
    \ <= t.size(); i++) {\n\t\tif (hasht.range(i, i + p.size()) == hashp.range(0,p.size()))\
    \ {\n\t\t\tcout << i << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\
    \n#include\"template.hpp\"\n#include\"string/rolling_hash.hpp\"\nint main() {\n\
    \tstring t, p;\n\tcin >> t >> p;\n\tRollingHash hasht(t), hashp(p);\n\tfor (int\
    \ i = 0; i + p.size() <= t.size(); i++) {\n\t\tif (hasht.range(i, i + p.size())\
    \ == hashp.range(0,p.size())) {\n\t\t\tcout << i << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - template.hpp
  - string/rolling_hash.hpp
  - math/large_mod.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS/14/B.test.cpp
  requiredBy: []
  timestamp: '2023-03-04 11:54:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/ALDS/14/B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS/14/B.test.cpp
- /verify/test/AOJ/ALDS/14/B.test.cpp.html
title: test/AOJ/ALDS/14/B.test.cpp
---
