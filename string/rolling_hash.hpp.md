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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\
      )"
    links: []
  bundledCode: "#line 2 \"math/mod_pow.hpp\"\ntemplate <class T, class U = T>\nU mod_pow(T\
    \ base, T exp, T mod){\n    T ans = 1;\n    base %= mod;\n    while (exp > 0)\
    \ {\n        if (exp & 1) {\n            ans *= base;\n            ans %= mod;\n\
    \        }\n        base *= base;\n        base %= mod;\n        exp >>= 1;\n\
    \    }\n    return ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)\n\
    #line 3 \"string/rolling_hash.hpp\"\nclass RollingHash {\n\tusing ull = uint_fast64_t;\n\
    \    using i128 = __int128_t;\n    using u128 = __uint128_t;\n    // mod\n\tstatic\
    \ constexpr ull msk30 = (1ul << 30) - 1;\n\tstatic constexpr ull msk61 = (1ul\
    \ << 31) - 1;\n\tstring str;\n\tvector<ull> hash, pow;\n\n    static const ull\
    \ mod = (1uL << 61) - 1;\n    static const ull primitive_root = 37;\npublic:\n\
    \tstatic const uint mapping_max = 'Z' + 1;\n\tstatic ull base;\nprivate:\n\tull\
    \ mul(const u128& a,const u128& b) const {\n        u128 t = a * b;\n\n\t\tt =\
    \ (t >> 61) + (t & mod);\n\n\t\tif (t >= mod) {\n\t\t\tt -= mod;\n\t\t}\n\n\n\t\
    \treturn t;\n    }\n\n    ull mapping(const char& c) const {\n\t\treturn (ull)c;\t\
    //\u5909\u66F4\u3059\u308B?\n\t}\n\n\n    static ull strong_rand() {\n\t\tmt19937_64\
    \ engine(chrono::steady_clock::now().time_since_epoch().count());\n\t\tuniform_int_distribution<ull>\
    \ rand(1uL, mod - 1);\n\t\treturn rand(engine);\n\t}\t\n    static void generate_base()\
    \ {\n\t\tif (base != 0){\n\t\t\treturn;\n\t\t}\n\t\tull r = mod - 1;\n\n\t\twhile\
    \ (gcd(r, mod - 1) != 1 || r <= mapping_max){\n\t\t\tr = strong_rand();\n\t\t\
    }\n\t\tbase = mod_pow<__uint128_t>(primitive_root, r, mod);\n\t}\npublic:\n\t\
    RollingHash() :str() {\t}\n\n\tRollingHash(const string& str) :str(str) {\n\t\t\
    generate_base();\n\t\tbuild();\n\t}\n\n\tvoid build() {\n\t\thash.resize(str.size()\
    \ + 1);\n\t\tpow.resize(str.size() + 1, 1);\n\n\t\tfor (int i = 0; i < str.size();\
    \ i++) {\n\t\t\thash[i + 1] = mul(hash[i], base) + mapping(str[i]);\n\t\t\tpow[i\
    \ + 1] = mul(pow[i], base);\n\t\t\tif (hash[i + 1] >= mod) {\n\t\t\t\thash[i +\
    \ 1] -= mod;\n\t\t\t}\n\t\t}\n\t}\n\tull range(int l, int r) const {\n\t\tull\
    \ res = mod + hash[r] - mul(hash[l], pow[r - l]);\n\t\treturn res < mod ? res\
    \ : res - mod;\n\t}\n\tull get_all() const {\n\t\treturn hash.back();\n\t}\n\t\
    int size() const {return str.size();}\n\n    static int lcp(const RollingHash\
    \ &a, const RollingHash &b, const int &start_a, const int &start_b) {\n      \
    \  int ok = 0;\n        int ng = min(a.size() - start_a, b.size() - start_b) +\
    \ 1;\n\t\twhile (abs(ok - ng) > 1){\n\t\t\tint md = (ok + ng) >> 1;\n        \
    \    if (a.range(start_a, start_a + md) == b.range(start_b, start_b + md)){\n\
    \                ok = md;\n            }\n            else{\n                ng\
    \ = md;\n            }\n\t\t}\n\n\t\treturn ok;\n    }\n};\ntypename RollingHash::ull\
    \ RollingHash::base;\n\n///@brief Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\
    \u30C3\u30B7\u30E5)\n"
  code: "#pragma once\n#include\"math/mod_pow.hpp\"\nclass RollingHash {\n\tusing\
    \ ull = uint_fast64_t;\n    using i128 = __int128_t;\n    using u128 = __uint128_t;\n\
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
    \u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  dependsOn:
  - math/mod_pow.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-03-07 15:26:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS/14/B.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
---