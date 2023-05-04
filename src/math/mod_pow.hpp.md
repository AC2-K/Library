---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash.hpp
    title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_B.test.cpp
    title: test/AOJ/NTL/1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No430.test.cpp
    title: test/yuki/No430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)"
    links: []
  bundledCode: "#line 2 \"src/internal/type_traits.hpp\"\n#include <iostream>\n#include\
    \ <limits>\n#include <numeric>\n#include <typeinfo>\nnamespace kyopro {\nnamespace\
    \ internal {\n/// @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    template <typename... Args> struct first_enabled {};\n\ntemplate <typename T,\
    \ typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...> {\n\
    \    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<false,\
    \ T>, Args...>\n    : first_enabled<Args...> {};\ntemplate <typename T, typename...\
    \ Args> struct first_enabled<T, Args...> {\n    using type = T;\n};\n\ntemplate\
    \ <typename... Args>\nusing first_enabled_t = typename first_enabled<Args...>::type;\n\
    \ntemplate <int dgt> struct int_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __int8_t>,\n               \
    \                  std::enable_if<dgt <= 16, __int16_t>,\n                   \
    \              std::enable_if<dgt <= 32, __int32_t>,\n                       \
    \          std::enable_if<dgt <= 64, __int64_t>,\n                           \
    \      std::enable_if<dgt <= 128, __int128_t> >;\n};\ntemplate <int dgt> struct\
    \ uint_least {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __uint8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __uint16_t>,\n                                 std::enable_if<dgt <= 32, __uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __uint64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\
    \ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\ntemplate\
    \ <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename\
    \ T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    };  // namespace internal\n};  // namespace kyopro\n#line 3 \"src/math/mod_pow.hpp\"\
    \nnamespace kyopro {\n\n///@brief mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\
    \u6CD5)\ntemplate <typename T> \nconstexpr T mod_pow(internal::double_size_uint_t<T>\
    \ base, T exp, T mod) {\n    internal::double_size_uint_t<T> ans = (mod == 1 ?\
    \ 0 : 1);\n    base %= mod;\n    while (exp) {\n        if (exp & 1) {\n     \
    \       ans *= base;\n            ans %= mod;\n        }\n        base *= base;\n\
    \        base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n};  // namespace\
    \ kyopro\n"
  code: "#pragma once\n#include \"../internal/type_traits.hpp\"\nnamespace kyopro\
    \ {\n\n///@brief mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)\ntemplate\
    \ <typename T> \nconstexpr T mod_pow(internal::double_size_uint_t<T> base, T exp,\
    \ T mod) {\n    internal::double_size_uint_t<T> ans = (mod == 1 ? 0 : 1);\n  \
    \  base %= mod;\n    while (exp) {\n        if (exp & 1) {\n            ans *=\
    \ base;\n            ans %= mod;\n        }\n        base *= base;\n        base\
    \ %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n};  // namespace kyopro"
  dependsOn:
  - src/internal/type_traits.hpp
  isVerificationFile: false
  path: src/math/mod_pow.hpp
  requiredBy:
  - src/string/rolling_hash.hpp
  - src/math/mod_log.hpp
  timestamp: '2023-05-03 22:08:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_B.test.cpp
  - test/yuki/No430.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
documentation_of: src/math/mod_pow.hpp
layout: document
redirect_from:
- /library/src/math/mod_pow.hpp
- /library/src/math/mod_pow.hpp.html
title: "mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)"
---
