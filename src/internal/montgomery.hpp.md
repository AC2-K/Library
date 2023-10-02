---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/math/dynamic_modint.hpp
    title: "\u52D5\u7684modint"
  - icon: ':question:'
    path: src/math/miller.hpp
    title: "MillerRabin\u7D20\u6570\u5224\u5B9A\u6CD5"
  - icon: ':heavy_check_mark:'
    path: src/math/phi_function.hpp
    title: "Euler\u306E $\\phi$ \u95A2\u6570"
  - icon: ':x:'
    path: src/math/primitive_root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':question:'
    path: src/math/rho.hpp
    title: "Pollard Rho \u7D20\u56E0\u6570\u5206\u89E3\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
    title: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
  - icon: ':x:'
    path: test/yuki/No3030.test.cpp
    title: test/yuki/No3030.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Montgomery Reduction
    links: []
  bundledCode: "#line 2 \"src/internal/montgomery.hpp\"\n#include <cassert>\n#include\
    \ <limits>\n#include <numeric>\n#line 2 \"src/internal/type_traits.hpp\"\n#include\
    \ <iostream>\n#line 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\n\
    namespace kyopro {\nnamespace internal {\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\ntemplate <typename... Args> struct first_enabled {};\n\ntemplate <typename\
    \ T, typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...>\
    \ {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct\
    \ first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt> struct int_least\
    \ {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, std::int8_t>,\n                                 std::enable_if<dgt <=\
    \ 16, std::int16_t>,\n                                 std::enable_if<dgt <= 32,\
    \ std::int32_t>,\n                                 std::enable_if<dgt <= 64, std::int64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __int128_t>>;\n};\n\
    template <int dgt> struct uint_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, std::uint8_t>,\n           \
    \                      std::enable_if<dgt <= 16, std::uint16_t>,\n           \
    \                      std::enable_if<dgt <= 32, std::uint32_t>,\n           \
    \                      std::enable_if<dgt <= 64, std::uint64_t>,\n           \
    \                      std::enable_if<dgt <= 128, __uint128_t>>;\n};\n\ntemplate\
    \ <int dgt> using int_least_t = typename int_least<dgt>::type;\ntemplate <int\
    \ dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename\
    \ T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                     std::is_same_v<T,\
    \ __uint128_t>>;\n};  // namespace internal\n};  // namespace kyopro\n#line 6\
    \ \"src/internal/montgomery.hpp\"\nnamespace kyopro {\nnamespace internal {\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i32 = int32_t;\nusing i64\
    \ = int64_t;\nusing u128 = __uint128_t;\nusing i128 = __int128_t;\n\n/**\n * @brief\
    \ Montgomery Reduction\n */\ntemplate <typename T> class Montgomery {\n    static\
    \ constexpr int lg = std::numeric_limits<T>::digits;\n    using LargeT = internal::double_size_uint_t<T>;\n\
    \    T mod, r, r2, minv;\n    T inv() {\n        T t = 0, res = 0;\n        for\
    \ (int i = 0; i < lg; ++i) {\n            if (~t & 1) {\n                t +=\
    \ mod;\n                res += static_cast<T>(1) << i;\n            }\n      \
    \      t >>= 1;\n        }\n        return res;\n    }\n\npublic:\n    Montgomery()\
    \ = default;\n    constexpr T get_mod() { return mod; }\n\n    void set_mod(T\
    \ m) {\n        assert(m);\n        assert(m & 1);\n\n        mod = m;\n\n   \
    \     r = (-static_cast<T>(mod)) % mod;\n        r2 = (-static_cast<LargeT>(mod))\
    \ % mod;\n        minv = inv();\n    }\n\n    T reduce(LargeT x) const {\n   \
    \     u64 res =\n            (x + static_cast<LargeT>(static_cast<T>(x) * minv)\
    \ * mod) >> lg;\n\n        if (res >= mod) res -= mod;\n        return res;\n\
    \    }\n\n    T generate(LargeT x) { return reduce(x * r2); }\n\n    T mul(T x,\
    \ T y) { return reduce((LargeT)x * y); }\n};\n};  // namespace internal\n};  //\
    \ namespace kyopro\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <numeric>\n\
    #include \"../internal/type_traits.hpp\"\nnamespace kyopro {\nnamespace internal\
    \ {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i32 = int32_t;\nusing\
    \ i64 = int64_t;\nusing u128 = __uint128_t;\nusing i128 = __int128_t;\n\n/**\n\
    \ * @brief Montgomery Reduction\n */\ntemplate <typename T> class Montgomery {\n\
    \    static constexpr int lg = std::numeric_limits<T>::digits;\n    using LargeT\
    \ = internal::double_size_uint_t<T>;\n    T mod, r, r2, minv;\n    T inv() {\n\
    \        T t = 0, res = 0;\n        for (int i = 0; i < lg; ++i) {\n         \
    \   if (~t & 1) {\n                t += mod;\n                res += static_cast<T>(1)\
    \ << i;\n            }\n            t >>= 1;\n        }\n        return res;\n\
    \    }\n\npublic:\n    Montgomery() = default;\n    constexpr T get_mod() { return\
    \ mod; }\n\n    void set_mod(T m) {\n        assert(m);\n        assert(m & 1);\n\
    \n        mod = m;\n\n        r = (-static_cast<T>(mod)) % mod;\n        r2 =\
    \ (-static_cast<LargeT>(mod)) % mod;\n        minv = inv();\n    }\n\n    T reduce(LargeT\
    \ x) const {\n        u64 res =\n            (x + static_cast<LargeT>(static_cast<T>(x)\
    \ * minv) * mod) >> lg;\n\n        if (res >= mod) res -= mod;\n        return\
    \ res;\n    }\n\n    T generate(LargeT x) { return reduce(x * r2); }\n\n    T\
    \ mul(T x, T y) { return reduce((LargeT)x * y); }\n};\n};  // namespace internal\n\
    };  // namespace kyopro"
  dependsOn:
  - src/internal/type_traits.hpp
  isVerificationFile: false
  path: src/internal/montgomery.hpp
  requiredBy:
  - src/math/phi_function.hpp
  - src/math/rho.hpp
  - src/math/primitive_root.hpp
  - src/math/miller.hpp
  - src/math/dynamic_modint.hpp
  timestamp: '2023-10-02 16:13:09+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yuki/No3030.test.cpp
  - test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
documentation_of: src/internal/montgomery.hpp
layout: document
redirect_from:
- /library/src/internal/montgomery.hpp
- /library/src/internal/montgomery.hpp.html
title: Montgomery Reduction
---
