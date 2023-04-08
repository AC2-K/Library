---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':question:'
    path: src/math/mod_pow.hpp
    title: "mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\
      )"
    links: []
  bundledCode: "#line 2 \"src/string/rolling_hash.hpp\"\n#include <chrono>\n#include\
    \ <random>\n#include <string>\n#include <vector>\n#line 2 \"src/math/gcd.hpp\"\
    \n#include <cassert>\n#include <tuple>\nnamespace kyopro {\ntemplate <typename\
    \ T> constexpr T _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n    if (a ==\
    \ 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n\
    \    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n\
    \        if (a == 0 || b == 0) {\n            return a + b;\n        }\n     \
    \   if (a > b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate <typename T> constexpr T\
    \ ext_gcd(T a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while (b) {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T,\
    \ T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n\
    \        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return\
    \ a;\n}\n};  // namespace kyopro\n#line 2 \"src/math/mod_pow.hpp\"\nnamespace\
    \ kyopro {\n\n///@brief mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)\n\
    template <class T, class U = T> constexpr T mod_pow(T base, T exp, T mod) {\n\
    \    U ans = 1;\n    base %= mod;\n    while (exp) {\n        if (exp & 1) {\n\
    \            ans *= base;\n            ans %= mod;\n        }\n        base *=\
    \ base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n\
    };  // namespace kyopro\n#line 8 \"src/string/rolling_hash.hpp\"\nnamespace kyopro\
    \ {\nclass RollingHash {\n    using ull = uint_fast64_t;\n    using i128 = __int128_t;\n\
    \    using u128 = __uint128_t;\n    // mod\n    static constexpr ull msk30 = (1ul\
    \ << 30) - 1;\n    static constexpr ull msk61 = (1ul << 31) - 1;\n    const std::string\
    \ str;\n    std::vector<ull> hash, pow;\n\n    static constexpr ull mod = (1uL\
    \ << 61) - 1;\n    static constexpr ull primitive_root = 37;\n\n  public:\n  \
    \  static const uint mapping_max = (uint)'Z' + 2;\n    static ull base;\n\n  private:\n\
    \    constexpr ull mul(const u128& a, const u128& b) const {\n        u128 t =\
    \ a * b;\n\n        t = (t >> 61) + (t & mod);\n\n        if (t >= mod) {\n  \
    \          t -= mod;\n        }\n\n        return t;\n    }\n\n    constexpr ull\
    \ mapping(const char& c) const {\n        return (ull)c;  // \u5909\u66F4\u3059\
    \u308B?\n    }\n\n    static inline ull generate() {\n        std::mt19937_64\
    \ engine(\n            std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<ull> rand(1uL, mod - 1);\n        return\
    \ rand(engine);\n    }\n    static inline void generate_base() {\n        if (base\
    \ != 0) {\n            return;\n        }\n        ull r = mod - 1;\n\n      \
    \  while (_gcd(r, mod - 1) != 1 || r <= mapping_max) {\n            r = generate();\n\
    \        }\n        base = mod_pow<__uint128_t>(primitive_root, r, mod);\n   \
    \ }\n\n  public:\n    RollingHash() : str() {}\n\n    RollingHash(const std::string&\
    \ str) : str(str) {\n        generate_base();\n        build();\n    }\n\n   \
    \ void build() {\n        hash.resize(str.size() + 1);\n        pow.resize(str.size()\
    \ + 1, 1);\n\n        for (int i = 0; i < (int)str.size(); i++) {\n          \
    \  hash[i + 1] = mul(hash[i], base) + mapping(str[i]);\n            pow[i + 1]\
    \ = mul(pow[i], base);\n            if (hash[i + 1] >= mod) {\n              \
    \  hash[i + 1] -= mod;\n            }\n        }\n    }\n    ull range(int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r <= str.size());\n\n   \
    \     ull res = mod + hash[r] - mul(hash[l], pow[r - l]);\n        return res\
    \ < mod ? res : res - mod;\n    }\n    ull get_all() const { return hash.back();\
    \ }\n    int size() const { return str.size(); }\n\n    static int lcp(const RollingHash&\
    \ a,\n                   const RollingHash& b,\n                   const int&\
    \ start_a,\n                   const int& start_b) {\n        int ok = 0;\n  \
    \      int ng = std::min(a.size() - start_a, b.size() - start_b) + 1;\n      \
    \  while (abs(ok - ng) > 1) {\n            int md = (ok + ng) >> 1;\n        \
    \    if (a.range(start_a, start_a + md) ==\n                b.range(start_b, start_b\
    \ + md)) {\n                ok = md;\n            } else {\n                ng\
    \ = md;\n            }\n        }\n\n        return ok;\n    }\n};\n}  // namespace\
    \ kyopro\ntypename kyopro::RollingHash::ull kyopro::RollingHash::base;\n\n///@brief\
    \ Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)\n"
  code: "#pragma once\n#include <chrono>\n#include <random>\n#include <string>\n#include\
    \ <vector>\n#include \"../math/gcd.hpp\"\n#include \"../math/mod_pow.hpp\"\nnamespace\
    \ kyopro {\nclass RollingHash {\n    using ull = uint_fast64_t;\n    using i128\
    \ = __int128_t;\n    using u128 = __uint128_t;\n    // mod\n    static constexpr\
    \ ull msk30 = (1ul << 30) - 1;\n    static constexpr ull msk61 = (1ul << 31) -\
    \ 1;\n    const std::string str;\n    std::vector<ull> hash, pow;\n\n    static\
    \ constexpr ull mod = (1uL << 61) - 1;\n    static constexpr ull primitive_root\
    \ = 37;\n\n  public:\n    static const uint mapping_max = (uint)'Z' + 2;\n   \
    \ static ull base;\n\n  private:\n    constexpr ull mul(const u128& a, const u128&\
    \ b) const {\n        u128 t = a * b;\n\n        t = (t >> 61) + (t & mod);\n\n\
    \        if (t >= mod) {\n            t -= mod;\n        }\n\n        return t;\n\
    \    }\n\n    constexpr ull mapping(const char& c) const {\n        return (ull)c;\
    \  // \u5909\u66F4\u3059\u308B?\n    }\n\n    static inline ull generate() {\n\
    \        std::mt19937_64 engine(\n            std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<ull> rand(1uL, mod - 1);\n        return\
    \ rand(engine);\n    }\n    static inline void generate_base() {\n        if (base\
    \ != 0) {\n            return;\n        }\n        ull r = mod - 1;\n\n      \
    \  while (_gcd(r, mod - 1) != 1 || r <= mapping_max) {\n            r = generate();\n\
    \        }\n        base = mod_pow<__uint128_t>(primitive_root, r, mod);\n   \
    \ }\n\n  public:\n    RollingHash() : str() {}\n\n    RollingHash(const std::string&\
    \ str) : str(str) {\n        generate_base();\n        build();\n    }\n\n   \
    \ void build() {\n        hash.resize(str.size() + 1);\n        pow.resize(str.size()\
    \ + 1, 1);\n\n        for (int i = 0; i < (int)str.size(); i++) {\n          \
    \  hash[i + 1] = mul(hash[i], base) + mapping(str[i]);\n            pow[i + 1]\
    \ = mul(pow[i], base);\n            if (hash[i + 1] >= mod) {\n              \
    \  hash[i + 1] -= mod;\n            }\n        }\n    }\n    ull range(int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r <= str.size());\n\n   \
    \     ull res = mod + hash[r] - mul(hash[l], pow[r - l]);\n        return res\
    \ < mod ? res : res - mod;\n    }\n    ull get_all() const { return hash.back();\
    \ }\n    int size() const { return str.size(); }\n\n    static int lcp(const RollingHash&\
    \ a,\n                   const RollingHash& b,\n                   const int&\
    \ start_a,\n                   const int& start_b) {\n        int ok = 0;\n  \
    \      int ng = std::min(a.size() - start_a, b.size() - start_b) + 1;\n      \
    \  while (abs(ok - ng) > 1) {\n            int md = (ok + ng) >> 1;\n        \
    \    if (a.range(start_a, start_a + md) ==\n                b.range(start_b, start_b\
    \ + md)) {\n                ok = md;\n            } else {\n                ng\
    \ = md;\n            }\n        }\n\n        return ok;\n    }\n};\n}  // namespace\
    \ kyopro\ntypename kyopro::RollingHash::ull kyopro::RollingHash::base;\n\n///@brief\
    \ Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  dependsOn:
  - src/math/gcd.hpp
  - src/math/mod_pow.hpp
  isVerificationFile: false
  path: src/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-04-08 13:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/rolling_hash.hpp
layout: document
redirect_from:
- /library/src/string/rolling_hash.hpp
- /library/src/string/rolling_hash.hpp.html
title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
---
