---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Convex.test.cpp
    title: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Min Plus Convolution(Convex, Convex)
    links: []
  bundledCode: "#line 2 \"src/convolution/min_plus_convolution_convex_convex.hpp\"\
    \n#include <algorithm>\n#include <limits>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n#line 2 \"src/internal/type_traits.hpp\"\n#include <iostream>\n\
    #line 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\n#include <cstdint>\n\
    \nnamespace kyopro {\nnamespace internal {\ntemplate <typename... Args> struct\
    \ first_enabled {};\n\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
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
    \ * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\n#line 8\
    \ \"src/convolution/min_plus_convolution_convex_convex.hpp\"\n\nnamespace kyopro\
    \ {\n\n    \n/**\n * @brief Min Plus Convolution(Convex, Convex)\n * @note a,b\
    \ \u3068\u3082\u306B\u4E0B\u306B\u51F8\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\
    \u308B\n * @note \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u304C\u3061\u306A\
    \u306E\u3067\u6C17\u3092\u4ED8\u3051\u3088\u3046!\n */\ntemplate <typename T>\n\
    std::vector<T> MinPlusConvolutionConvexConvex(const std::vector<T>& a,\n     \
    \                                             std::vector<T>& b) {\n    constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n    const int n = a.size();\n  \
    \  const int m = b.size();\n    const T A0 = INF;\n    const T B0 = INF;\n\n \
    \   std::vector<T> da(n);\n    std::vector<T> db(m);\n    for (int i = 1; i <\
    \ n; ++i) da[i] = a[i] - a[i - 1];\n    for (int i = 1; i < m; ++i) db[i] = b[i]\
    \ - b[i - 1];\n    da[0] = a[0] - INF, db[0] = b[0] - INF;\n\n    std::vector<T>\
    \ ds;\n    std::merge(da.begin(), da.end(), db.begin(), db.end(),\n          \
    \     std::back_inserter(ds));\n\n    std::vector<T> res(n + m - 1);\n    T sum\
    \ = ds[0];\n    for (int k = 1; k < (int)ds.size(); ++k) {\n        sum += ds[k];\n\
    \        res[k - 1] = sum + A0 + B0;\n    }\n    return res;\n}\n};  // namespace\
    \ kyopro\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <numeric>\n\
    #include <utility>\n#include <vector>\n#include \"../../src/internal/type_traits.hpp\"\
    \n\nnamespace kyopro {\n\n    \n/**\n * @brief Min Plus Convolution(Convex, Convex)\n\
    \ * @note a,b \u3068\u3082\u306B\u4E0B\u306B\u51F8\u3067\u3042\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\n * @note \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u304C\
    \u3061\u306A\u306E\u3067\u6C17\u3092\u4ED8\u3051\u3088\u3046!\n */\ntemplate <typename\
    \ T>\nstd::vector<T> MinPlusConvolutionConvexConvex(const std::vector<T>& a,\n\
    \                                                  std::vector<T>& b) {\n    constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n    const int n = a.size();\n  \
    \  const int m = b.size();\n    const T A0 = INF;\n    const T B0 = INF;\n\n \
    \   std::vector<T> da(n);\n    std::vector<T> db(m);\n    for (int i = 1; i <\
    \ n; ++i) da[i] = a[i] - a[i - 1];\n    for (int i = 1; i < m; ++i) db[i] = b[i]\
    \ - b[i - 1];\n    da[0] = a[0] - INF, db[0] = b[0] - INF;\n\n    std::vector<T>\
    \ ds;\n    std::merge(da.begin(), da.end(), db.begin(), db.end(),\n          \
    \     std::back_inserter(ds));\n\n    std::vector<T> res(n + m - 1);\n    T sum\
    \ = ds[0];\n    for (int k = 1; k < (int)ds.size(); ++k) {\n        sum += ds[k];\n\
    \        res[k - 1] = sum + A0 + B0;\n    }\n    return res;\n}\n};  // namespace\
    \ kyopro\n"
  dependsOn:
  - src/internal/type_traits.hpp
  isVerificationFile: false
  path: src/convolution/min_plus_convolution_convex_convex.hpp
  requiredBy: []
  timestamp: '2024-06-23 18:35:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Convex.test.cpp
documentation_of: src/convolution/min_plus_convolution_convex_convex.hpp
layout: document
redirect_from:
- /library/src/convolution/min_plus_convolution_convex_convex.hpp
- /library/src/convolution/min_plus_convolution_convex_convex.hpp.html
title: Min Plus Convolution(Convex, Convex)
---
