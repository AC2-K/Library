---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/large_mod.hpp
    title: math/large_mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/ALDS/14/B.test.cpp
    title: test/AOJ/ALDS/14/B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: rolling hash
    links: []
  bundledCode: "#line 2 \"math/large_mod.hpp\"\ninline long long safe_mod(long long\
    \ a, long long m){\n    return (a % m + m) % m;\n}\nlong long mul(long long a,\
    \ long long b, long long m) {\n    a = safe_mod(a, m);\n    b = safe_mod(b, m);\n\
    \    if (b == 0) return 0;\n    long long res = mul(safe_mod(a + a, m), b >> 1,\
    \ m);\n    if (b & 1){\n        res = safe_mod(res + a, m);\n    }\n    return\
    \ res;\n}\ntemplate<typename T>\nT large_modpow(T base,T exp,T mod){\n    T ans\
    \ = 1 % mod;\n    base %= mod;\n    while (exp) {\n        if (exp & 1) {\n  \
    \          ans = mul(ans, base, mod);\n        }\n        base = mul(base, base,\
    \ mod);\n        exp >>= 1;\n    }\n    return ans;\n}\n\nunsigned long long i128_modpow(__uint128_t\
    \ base, __uint128_t exp, unsigned long long mod){\n    i128 res = (mod == 1 ?\
    \ 0 : 1);\n    base %= mod;\n    while (exp){\n        if (exp & 1){\n       \
    \     res = (res * base) % mod;\n        }\n        base = (base * base) % mod;\n\
    \        exp >>= 1;\n    }\n    return res;\n}\n#line 3 \"string/rolling_hash.hpp\"\
    \nnamespace for_hash {\n\tusing ull = uint_fast64_t;\n\tconstexpr ull mapping_max\
    \ = (ull)'Z';\n\tull base = -1;\t//base\u3092\u30E9\u30F3\u30C0\u30E0\u306B\u3068\
    \u308B\n\tconstexpr ull mod = (1uL << 61) - 1;\n\tconstexpr ull primitive_root\
    \ = 37;\n\tull strong_rand() {\n\t\tmt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \ hash\n"
  code: "#pragma once\n#include\"math/large_mod.hpp\"\nnamespace for_hash {\n\tusing\
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
    \ hash"
  dependsOn:
  - math/large_mod.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-03-01 17:28:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/ALDS/14/B.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: rolling hash
---
