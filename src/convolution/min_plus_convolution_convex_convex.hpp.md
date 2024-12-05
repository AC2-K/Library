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
    document_title: (min, +) Convolution(Convex, Convex)
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
    \ {\n\n/**\n * @brief (min, +) Convolution(Convex, Convex)\n * @attention Both\
    \ a, b must be convex\n */\ntemplate <typename T>\nstd::vector<T> min_plus_convolution_convex_convex(const\
    \ std::vector<T>& a,\n                                                  std::vector<T>&\
    \ b) {\n    const int n = a.size();\n    const int m = b.size();\n\n    std::vector<T>\
    \ da(n - 1);\n    std::vector<T> db(m - 1);\n    for (int i = 0; i < n - 1; ++i)\
    \ da[i] = a[i + 1] - a[i];\n    for (int i = 0; i < m - 1; ++i) db[i] = b[i +\
    \ 1] - b[i];\n\n    std::vector<T> ds;\n    std::merge(da.begin(), da.end(), db.begin(),\
    \ db.end(),\n               std::back_inserter(ds));\n\n    std::vector<T> res(n\
    \ + m - 1);\n    res[0] = a[0] + b[0];\n    T sum = 0;\n\n    for (int k = 0;\
    \ k < (int)ds.size(); ++k) {\n        sum += ds[k];\n        res[k + 1] = sum\
    \ + a[0] + b[0];\n    }\n\n    return res;\n}\n\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <numeric>\n\
    #include <utility>\n#include <vector>\n#include \"../../src/internal/type_traits.hpp\"\
    \n\nnamespace kyopro {\n\n/**\n * @brief (min, +) Convolution(Convex, Convex)\n\
    \ * @attention Both a, b must be convex\n */\ntemplate <typename T>\nstd::vector<T>\
    \ min_plus_convolution_convex_convex(const std::vector<T>& a,\n              \
    \                                    std::vector<T>& b) {\n    const int n = a.size();\n\
    \    const int m = b.size();\n\n    std::vector<T> da(n - 1);\n    std::vector<T>\
    \ db(m - 1);\n    for (int i = 0; i < n - 1; ++i) da[i] = a[i + 1] - a[i];\n \
    \   for (int i = 0; i < m - 1; ++i) db[i] = b[i + 1] - b[i];\n\n    std::vector<T>\
    \ ds;\n    std::merge(da.begin(), da.end(), db.begin(), db.end(),\n          \
    \     std::back_inserter(ds));\n\n    std::vector<T> res(n + m - 1);\n    res[0]\
    \ = a[0] + b[0];\n    T sum = 0;\n\n    for (int k = 0; k < (int)ds.size(); ++k)\
    \ {\n        sum += ds[k];\n        res[k + 1] = sum + a[0] + b[0];\n    }\n\n\
    \    return res;\n}\n\n};  // namespace kyopro\n"
  dependsOn:
  - src/internal/type_traits.hpp
  isVerificationFile: false
  path: src/convolution/min_plus_convolution_convex_convex.hpp
  requiredBy: []
  timestamp: '2024-09-29 11:09:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Convex.test.cpp
documentation_of: src/convolution/min_plus_convolution_convex_convex.hpp
layout: document
redirect_from:
- /library/src/convolution/min_plus_convolution_convex_convex.hpp
- /library/src/convolution/min_plus_convolution_convex_convex.hpp.html
title: (min, +) Convolution(Convex, Convex)
---
