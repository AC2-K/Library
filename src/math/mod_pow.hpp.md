---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/FormalPowerSeries/fps-sqrt.hpp
    title: Sqrt of FPS
  - icon: ':x:'
    path: src/math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':x:'
    path: src/math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59(O(\u221Ap))"
  - icon: ':x:'
    path: src/string/rolling_hash.hpp
    title: Rolling Hash
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/NTL/1_B.test.cpp
    title: test/AOJ/NTL/1_B.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/yuki/No430.test.cpp
    title: test/yuki/No430.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Modulo Power(\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)"
    links: []
  bundledCode: "#line 2 \"src/internal/type_traits.hpp\"\n#include <iostream>\n#include\
    \ <limits>\n#include <numeric>\n#include <typeinfo>\n#include <cstdint>\n\nnamespace\
    \ kyopro {\nnamespace internal {\ntemplate <typename... Args> struct first_enabled\
    \ {};\n\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
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
    \ \"src/math/mod_pow.hpp\"\nnamespace kyopro {\n\ntemplate <typename T, typename\
    \ E,typename M>\nconstexpr T mod_pow(T base, E exp, M mod) {\n    internal::double_size_uint_t<M>\
    \ ans = (mod == 1 ? 0 : 1);\n    base %= mod;\n    while (exp) {\n        if (exp\
    \ & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n     \
    \   base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n};  // namespace kyopro\n\n/**\n * @brief Modulo Power(\u7E70\u308A\
    \u8FD4\u3057\u4E8C\u4E57\u6CD5)\n */\n"
  code: "#pragma once\n#include \"../internal/type_traits.hpp\"\nnamespace kyopro\
    \ {\n\ntemplate <typename T, typename E,typename M>\nconstexpr T mod_pow(T base,\
    \ E exp, M mod) {\n    internal::double_size_uint_t<M> ans = (mod == 1 ? 0 : 1);\n\
    \    base %= mod;\n    while (exp) {\n        if (exp & 1) {\n            ans\
    \ *= base;\n            ans %= mod;\n        }\n        base *= base;\n      \
    \  base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Modulo Power(\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\
    )\n */"
  dependsOn:
  - src/internal/type_traits.hpp
  isVerificationFile: false
  path: src/math/mod_pow.hpp
  requiredBy:
  - src/FormalPowerSeries/fps-sqrt.hpp
  - src/string/rolling_hash.hpp
  - src/math/mod_sqrt.hpp
  - src/math/mod_log.hpp
  timestamp: '2024-09-29 11:09:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/NTL/1_B.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/yuki/No430.test.cpp
documentation_of: src/math/mod_pow.hpp
layout: document
redirect_from:
- /library/src/math/mod_pow.hpp
- /library/src/math/mod_pow.hpp.html
title: "Modulo Power(\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)"
---
