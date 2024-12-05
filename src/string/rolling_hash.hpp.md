---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: gcd
  - icon: ':heavy_check_mark:'
    path: src/math/mod_pow.hpp
    title: "Modulo Power(\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)"
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
    \n#include <cassert>\n#include <cmath>\n#include <tuple>\nnamespace kyopro {\n\
    template <typename T> constexpr inline T _gcd(T a, T b) noexcept {\n    assert(a\
    \ >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a),\
    \ __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n\
    \    while (a != b) {\n        if (!a || !b) {\n            return a + b;\n  \
    \      }\n        if (a >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\n\ntemplate <typename T>\nconstexpr\
    \ inline T ext_gcd(T a, T b, T& x, T& y) noexcept {\n    x = 1, y = 0;\n    T\
    \ nx = 0, ny = 1;\n    while (b) {\n        T q = a / b;\n        std::tie(a,\
    \ b) = std::pair<T, T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx,\
    \ x - nx * q};\n        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n \
    \   }\n    return a;\n}\n};  // namespace kyopro\n\n/**\n * @brief gcd\n*/\n#line\
    \ 2 \"src/internal/type_traits.hpp\"\n#include <iostream>\n#include <limits>\n\
    #include <numeric>\n#include <typeinfo>\n#include <cstdint>\n\nnamespace kyopro\
    \ {\nnamespace internal {\ntemplate <typename... Args> struct first_enabled {};\n\
    \ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
    \ T>, Args...> {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt, std::enable_if_t<dgt\
    \ <= 128>* = nullptr> struct int_least {\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, std::int8_t>,\n                                 std::enable_if<dgt <=\
    \ 16, std::int16_t>,\n                                 std::enable_if<dgt <= 32,\
    \ std::int32_t>,\n                                 std::enable_if<dgt <= 64, std::int64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __int128_t>>;\n};\n\
    \ntemplate <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct uint_least\
    \ {\n    using type = first_enabled_t<std::enable_if<dgt <= 8, std::uint8_t>,\n\
    \                                 std::enable_if<dgt <= 16, std::uint16_t>,\n\
    \                                 std::enable_if<dgt <= 32, std::uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, std::uint64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __uint128_t>>;\n\
    };\n\ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\n\
    template <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate\
    \ <typename T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n\n/**\n * @brief Type Traits\n\
    \ * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\n#line 3\
    \ \"src/math/mod_pow.hpp\"\nnamespace kyopro {\n\ntemplate <typename T>\nconstexpr\
    \ T mod_pow(internal::double_size_uint_t<T> base, T exp, T mod) {\n    internal::double_size_uint_t<T>\
    \ ans = (mod == 1 ? 0 : 1);\n    base %= mod;\n    while (exp) {\n        if (exp\
    \ & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n     \
    \   base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n};  // namespace kyopro\n\n/**\n * @brief Modulo Power(\u7E70\u308A\
    \u8FD4\u3057\u4E8C\u4E57\u6CD5)\n */\n#line 8 \"src/string/rolling_hash.hpp\"\n\
    namespace kyopro {\n\nclass RollingHash {\n    using u64 = std::uint64_t;\n  \
    \  using i128 = __int128_t;\n    using u128 = __uint128_t;\n\n    static constexpr\
    \ u64 msk30 = (static_cast<u64>(1) << 30) - 1;\n    static constexpr u64 msk61\
    \ = (static_cast<u64>(1) << 31) - 1;\n    const std::string str;\n    std::vector<u64>\
    \ _hash, _pow;\n    \n    static constexpr u64 mod = (static_cast<u64>(1) << 61)\
    \ - 1;\n    static constexpr u64 primitive_root = 37;\n    static constexpr uint\
    \ mapping_max = (uint)'Z' + 2;\n    static u64 base;\n    \nprivate:\n    constexpr\
    \ u64 mul(u64 a, u64 b) const {\n        u128 t = (u128)a * b;\n        t = (t\
    \ >> 61) + (t & mod);\n        if (t >= mod) {\n            t -= mod;\n      \
    \  }\n        return t;\n    }\n\n    constexpr u64 mapping(char c) const { return\
    \ (u64)c; }\n\n    static u64 generate() {\n        static std::mt19937_64 engine(\n\
    \            std::chrono::steady_clock::now().time_since_epoch().count());\n \
    \       std::uniform_int_distribution<u64> rand(1, mod - 1);\n        return rand(engine);\n\
    \    }\n    static void generate_base() {\n        if (base != 0) {\n        \
    \    return;\n        }\n        u64 r = mod - 1;\n        \n        while (_gcd(r,\
    \ mod - 1) != 1 || r <= mapping_max) r = generate();\n\n        base = mod_pow(primitive_root,\
    \ r, mod);\n    }\n\npublic:\n    RollingHash() : str() {}\n\n    RollingHash(const\
    \ std::string& str) : str(str) {\n        generate_base();\n        build();\n\
    \    }\n\n    void build() {\n        _hash.resize(str.size() + 1);\n        _pow.resize(str.size()\
    \ + 1, 1);\n\n        for (int i = 0; i < (int)str.size(); i++) {\n          \
    \  _hash[i + 1] = mul(_hash[i], base) + mapping(str[i]);\n            _pow[i +\
    \ 1] = mul(_pow[i], base);\n            if (_hash[i + 1] >= mod) {\n         \
    \       _hash[i + 1] -= mod;\n            }\n        }\n    }\n    u64 hash(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= str.size());\n\n\
    \        u64 res = mod + _hash[r] - mul(_hash[l], _pow[r - l]);\n        return\
    \ res < mod ? res : res - mod;\n    }\n    u64 get_all() const { return _hash.back();\
    \ }\n    int size() const { return str.size(); }\n\n    static int lcp(const RollingHash&\
    \ a,\n                   const RollingHash& b,\n                   int start_a,\n\
    \                   int start_b) {\n        int ok = 0;\n        int ng = std::min(a.size()\
    \ - start_a, b.size() - start_b) + 1;\n        while (ng - ok > 1) {\n       \
    \     int md = (ok + ng) >> 1;\n            if (a.hash(start_a, start_a + md)\
    \ ==\n                b.hash(start_b, start_b + md)) {\n                ok = md;\n\
    \            } else {\n                ng = md;\n            }\n        }\n\n\
    \        return ok;\n    }\n};\n}  // namespace kyopro\ntypename kyopro::RollingHash::u64\
    \ kyopro::RollingHash::base;\n\n\n/**\n * @brief Rolling Hash\n */\n"
  code: "#pragma once\n#include <chrono>\n#include <random>\n#include <string>\n#include\
    \ <vector>\n#include \"../math/gcd.hpp\"\n#include \"../math/mod_pow.hpp\"\nnamespace\
    \ kyopro {\n\nclass RollingHash {\n    using u64 = std::uint64_t;\n    using i128\
    \ = __int128_t;\n    using u128 = __uint128_t;\n\n    static constexpr u64 msk30\
    \ = (static_cast<u64>(1) << 30) - 1;\n    static constexpr u64 msk61 = (static_cast<u64>(1)\
    \ << 31) - 1;\n    const std::string str;\n    std::vector<u64> _hash, _pow;\n\
    \    \n    static constexpr u64 mod = (static_cast<u64>(1) << 61) - 1;\n    static\
    \ constexpr u64 primitive_root = 37;\n    static constexpr uint mapping_max =\
    \ (uint)'Z' + 2;\n    static u64 base;\n    \nprivate:\n    constexpr u64 mul(u64\
    \ a, u64 b) const {\n        u128 t = (u128)a * b;\n        t = (t >> 61) + (t\
    \ & mod);\n        if (t >= mod) {\n            t -= mod;\n        }\n       \
    \ return t;\n    }\n\n    constexpr u64 mapping(char c) const { return (u64)c;\
    \ }\n\n    static u64 generate() {\n        static std::mt19937_64 engine(\n \
    \           std::chrono::steady_clock::now().time_since_epoch().count());\n  \
    \      std::uniform_int_distribution<u64> rand(1, mod - 1);\n        return rand(engine);\n\
    \    }\n    static void generate_base() {\n        if (base != 0) {\n        \
    \    return;\n        }\n        u64 r = mod - 1;\n        \n        while (_gcd(r,\
    \ mod - 1) != 1 || r <= mapping_max) r = generate();\n\n        base = mod_pow(primitive_root,\
    \ r, mod);\n    }\n\npublic:\n    RollingHash() : str() {}\n\n    RollingHash(const\
    \ std::string& str) : str(str) {\n        generate_base();\n        build();\n\
    \    }\n\n    void build() {\n        _hash.resize(str.size() + 1);\n        _pow.resize(str.size()\
    \ + 1, 1);\n\n        for (int i = 0; i < (int)str.size(); i++) {\n          \
    \  _hash[i + 1] = mul(_hash[i], base) + mapping(str[i]);\n            _pow[i +\
    \ 1] = mul(_pow[i], base);\n            if (_hash[i + 1] >= mod) {\n         \
    \       _hash[i + 1] -= mod;\n            }\n        }\n    }\n    u64 hash(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= str.size());\n\n\
    \        u64 res = mod + _hash[r] - mul(_hash[l], _pow[r - l]);\n        return\
    \ res < mod ? res : res - mod;\n    }\n    u64 get_all() const { return _hash.back();\
    \ }\n    int size() const { return str.size(); }\n\n    static int lcp(const RollingHash&\
    \ a,\n                   const RollingHash& b,\n                   int start_a,\n\
    \                   int start_b) {\n        int ok = 0;\n        int ng = std::min(a.size()\
    \ - start_a, b.size() - start_b) + 1;\n        while (ng - ok > 1) {\n       \
    \     int md = (ok + ng) >> 1;\n            if (a.hash(start_a, start_a + md)\
    \ ==\n                b.hash(start_b, start_b + md)) {\n                ok = md;\n\
    \            } else {\n                ng = md;\n            }\n        }\n\n\
    \        return ok;\n    }\n};\n}  // namespace kyopro\ntypename kyopro::RollingHash::u64\
    \ kyopro::RollingHash::base;\n\n\n/**\n * @brief Rolling Hash\n */"
  dependsOn:
  - src/math/gcd.hpp
  - src/math/mod_pow.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: false
  path: src/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-09-29 15:12:55+09:00'
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
