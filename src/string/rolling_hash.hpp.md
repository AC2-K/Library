---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/mod_pow.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki/No430.test.cpp
    title: test/yuki/No430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Rolling Hash
    links: []
  bundledCode: "#line 2 \"src/string/rolling_hash.hpp\"\n#include <chrono>\n#include\
    \ <random>\n#include <string>\n#include <vector>\n#line 2 \"src/math/gcd.hpp\"\
    \n#include <cassert>\n#include <tuple>\nnamespace kyopro {\ntemplate <typename\
    \ T> constexpr T inline _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n    if\
    \ (a == 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a),\
    \ __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n\
    \    while (a != b) {\n        if (!a || !b) {\n            return a + b;\n  \
    \      }\n        if (a >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate <typename T> constexpr T\
    \ ext_gcd(T a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while (b) {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T,\
    \ T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n\
    \        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return\
    \ a;\n}\n};  // namespace kyopro\n#line 2 \"src/internal/type_traits.hpp\"\n#include\
    \ <iostream>\n#include <limits>\n#include <numeric>\n#include <typeinfo>\nnamespace\
    \ kyopro {\nnamespace internal {\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\ntemplate <typename... Args> struct first_enabled {};\n\ntemplate <typename\
    \ T, typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...>\
    \ {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct\
    \ first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt> struct int_least\
    \ {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __int8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __int16_t>,\n                                 std::enable_if<dgt <= 32, __int32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __int64_t>,\n    \
    \                             std::enable_if<dgt <= 128, __int128_t> >;\n};\n\
    template <int dgt> struct uint_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __uint8_t>,\n              \
    \                   std::enable_if<dgt <= 16, __uint16_t>,\n                 \
    \                std::enable_if<dgt <= 32, __uint32_t>,\n                    \
    \             std::enable_if<dgt <= 64, __uint64_t>,\n                       \
    \          std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\ntemplate <int dgt>\
    \ using int_least_t = typename int_least<dgt>::type;\ntemplate <int dgt> using\
    \ uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename T>\nusing\
    \ double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\ntemplate\
    \ <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    };  // namespace internal\n};  // namespace kyopro\n#line 3 \"src/math/mod_pow.hpp\"\
    \nnamespace kyopro {\n\n/**\n * @brief \u30D0\u30A4\u30CA\u30EA\u6CD5\n */\ntemplate\
    \ <typename T>\nconstexpr T mod_pow(internal::double_size_uint_t<T> base, T exp,\
    \ T mod) {\n    internal::double_size_uint_t<T> ans = (mod == 1 ? 0 : 1);\n  \
    \  base %= mod;\n    while (exp) {\n        if (exp & 1) {\n            ans *=\
    \ base;\n            ans %= mod;\n        }\n        base *= base;\n        base\
    \ %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n};  // namespace kyopro\n\
    #line 8 \"src/string/rolling_hash.hpp\"\nnamespace kyopro {\n\n/**\n * @brief\
    \ Rolling Hash\n */\nclass RollingHash {\n    using ull = uint_fast64_t;\n   \
    \ using i128 = __int128_t;\n    using u128 = __uint128_t;\n    // mod\n    static\
    \ constexpr ull msk30 = (1ul << 30) - 1;\n    static constexpr ull msk61 = (1ul\
    \ << 31) - 1;\n    const std::string str;\n    std::vector<ull> hash, pow;\n\n\
    \    static constexpr ull mod = (1uL << 61) - 1;\n    static constexpr ull primitive_root\
    \ = 37;\n\npublic:\n    static constexpr uint mapping_max = (uint)'Z' + 2;\n \
    \   static ull base;\n\nprivate:\n    constexpr ull mul(const u128& a, const u128&\
    \ b) const {\n        u128 t = a * b;\n\n        t = (t >> 61) + (t & mod);\n\n\
    \        if (t >= mod) {\n            t -= mod;\n        }\n\n        return t;\n\
    \    }\n\n    constexpr ull mapping(char c) const {\n        return (ull)c;  //\
    \ \u5909\u66F4\u3059\u308B?\n    }\n\n    static ull generate() {\n        std::mt19937_64\
    \ engine(\n            std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<ull> rand(1uL, mod - 1);\n        return\
    \ rand(engine);\n    }\n    static void generate_base() {\n        if (base !=\
    \ 0) {\n            return;\n        }\n        ull r = mod - 1;\n\n        while\
    \ (_gcd(r, mod - 1) != 1 || r <= mapping_max) {\n            r = generate();\n\
    \        }\n        base = mod_pow(primitive_root, r, mod);\n    }\n\npublic:\n\
    \    RollingHash() : str() {}\n\n    RollingHash(const std::string& str) : str(str)\
    \ {\n        generate_base();\n        build();\n    }\n\n    void build() {\n\
    \        hash.resize(str.size() + 1);\n        pow.resize(str.size() + 1, 1);\n\
    \n        for (int i = 0; i < (int)str.size(); i++) {\n            hash[i + 1]\
    \ = mul(hash[i], base) + mapping(str[i]);\n            pow[i + 1] = mul(pow[i],\
    \ base);\n            if (hash[i + 1] >= mod) {\n                hash[i + 1] -=\
    \ mod;\n            }\n        }\n    }\n    ull range(int l, int r) const {\n\
    \        assert(0 <= l && l <= r && r <= str.size());\n\n        ull res = mod\
    \ + hash[r] - mul(hash[l], pow[r - l]);\n        return res < mod ? res : res\
    \ - mod;\n    }\n    ull get_all() const { return hash.back(); }\n    int size()\
    \ const { return str.size(); }\n\n    static int lcp(const RollingHash& a,\n \
    \                  const RollingHash& b,\n                   int start_a,\n  \
    \                 int start_b) {\n        int ok = 0;\n        int ng = std::min(a.size()\
    \ - start_a, b.size() - start_b) + 1;\n        while (ng - ok > 1) {\n       \
    \     int md = (ok + ng) >> 1;\n            if (a.range(start_a, start_a + md)\
    \ ==\n                b.range(start_b, start_b + md)) {\n                ok =\
    \ md;\n            } else {\n                ng = md;\n            }\n       \
    \ }\n\n        return ok;\n    }\n};\n}  // namespace kyopro\ntypename kyopro::RollingHash::ull\
    \ kyopro::RollingHash::base;\n"
  code: "#pragma once\n#include <chrono>\n#include <random>\n#include <string>\n#include\
    \ <vector>\n#include \"../math/gcd.hpp\"\n#include \"../math/mod_pow.hpp\"\nnamespace\
    \ kyopro {\n\n/**\n * @brief Rolling Hash\n */\nclass RollingHash {\n    using\
    \ ull = uint_fast64_t;\n    using i128 = __int128_t;\n    using u128 = __uint128_t;\n\
    \    // mod\n    static constexpr ull msk30 = (1ul << 30) - 1;\n    static constexpr\
    \ ull msk61 = (1ul << 31) - 1;\n    const std::string str;\n    std::vector<ull>\
    \ hash, pow;\n\n    static constexpr ull mod = (1uL << 61) - 1;\n    static constexpr\
    \ ull primitive_root = 37;\n\npublic:\n    static constexpr uint mapping_max =\
    \ (uint)'Z' + 2;\n    static ull base;\n\nprivate:\n    constexpr ull mul(const\
    \ u128& a, const u128& b) const {\n        u128 t = a * b;\n\n        t = (t >>\
    \ 61) + (t & mod);\n\n        if (t >= mod) {\n            t -= mod;\n       \
    \ }\n\n        return t;\n    }\n\n    constexpr ull mapping(char c) const {\n\
    \        return (ull)c;  // \u5909\u66F4\u3059\u308B?\n    }\n\n    static ull\
    \ generate() {\n        std::mt19937_64 engine(\n            std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<ull> rand(1uL, mod - 1);\n        return\
    \ rand(engine);\n    }\n    static void generate_base() {\n        if (base !=\
    \ 0) {\n            return;\n        }\n        ull r = mod - 1;\n\n        while\
    \ (_gcd(r, mod - 1) != 1 || r <= mapping_max) {\n            r = generate();\n\
    \        }\n        base = mod_pow(primitive_root, r, mod);\n    }\n\npublic:\n\
    \    RollingHash() : str() {}\n\n    RollingHash(const std::string& str) : str(str)\
    \ {\n        generate_base();\n        build();\n    }\n\n    void build() {\n\
    \        hash.resize(str.size() + 1);\n        pow.resize(str.size() + 1, 1);\n\
    \n        for (int i = 0; i < (int)str.size(); i++) {\n            hash[i + 1]\
    \ = mul(hash[i], base) + mapping(str[i]);\n            pow[i + 1] = mul(pow[i],\
    \ base);\n            if (hash[i + 1] >= mod) {\n                hash[i + 1] -=\
    \ mod;\n            }\n        }\n    }\n    ull range(int l, int r) const {\n\
    \        assert(0 <= l && l <= r && r <= str.size());\n\n        ull res = mod\
    \ + hash[r] - mul(hash[l], pow[r - l]);\n        return res < mod ? res : res\
    \ - mod;\n    }\n    ull get_all() const { return hash.back(); }\n    int size()\
    \ const { return str.size(); }\n\n    static int lcp(const RollingHash& a,\n \
    \                  const RollingHash& b,\n                   int start_a,\n  \
    \                 int start_b) {\n        int ok = 0;\n        int ng = std::min(a.size()\
    \ - start_a, b.size() - start_b) + 1;\n        while (ng - ok > 1) {\n       \
    \     int md = (ok + ng) >> 1;\n            if (a.range(start_a, start_a + md)\
    \ ==\n                b.range(start_b, start_b + md)) {\n                ok =\
    \ md;\n            } else {\n                ng = md;\n            }\n       \
    \ }\n\n        return ok;\n    }\n};\n}  // namespace kyopro\ntypename kyopro::RollingHash::ull\
    \ kyopro::RollingHash::base;\n"
  dependsOn:
  - src/math/gcd.hpp
  - src/math/mod_pow.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: false
  path: src/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-05-15 08:00:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/No430.test.cpp
documentation_of: src/string/rolling_hash.hpp
layout: document
redirect_from:
- /library/src/string/rolling_hash.hpp
- /library/src/string/rolling_hash.hpp.html
title: Rolling Hash
---
