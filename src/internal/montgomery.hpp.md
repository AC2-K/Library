---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/math/dynamic_modint.hpp
    title: "dynamic modint(\u52D5\u7684modint)"
  - icon: ':x:'
    path: src/math/miller.hpp
    title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
  - icon: ':x:'
    path: src/math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':x:'
    path: src/math/phi_function.hpp
    title: "phi function($\\phi$ \u95A2\u6570)"
  - icon: ':x:'
    path: src/math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':x:'
    path: src/math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: MontgomeryReduction
    links: []
  bundledCode: "#line 2 \"src/internal/montgomery.hpp\"\n#include <cassert>\n#include\
    \ <limits>\n#include <numeric>\n#line 2 \"src/internal/type_traits.hpp\"\n#include\
    \ <iostream>\n#line 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\n\
    namespace kyopro {\nnamespace internal {\n/// @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    template <typename... Args> struct first_enabled {};\n\ntemplate <typename T,\
    \ typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...> {\n\
    \    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<false,\
    \ T>, Args...>\n    : first_enabled<Args...> {};\ntemplate <typename T, typename...\
    \ Args> struct first_enabled<T, Args...> {\n    using type = T;\n};\n\ntemplate\
    \ <typename... Args>\nusing first_enabled_t = typename first_enabled<Args...>::type;\n\
    \ntemplate <int dgt> struct int_least {\n    static_assert(dgt <= 128, \"digit\
    \ have to be less or equals to 128\");\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __int8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __int16_t>,\n                                 std::enable_if<dgt <= 32, __int32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __int64_t>,\n    \
    \                             std::enable_if<dgt <= 128, __int128_t> >;\n};\n\
    template <int dgt> struct uint_least {\n    static_assert(dgt <= 128, \"digit\
    \ have to be less or equals to 128\");\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __uint8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __uint16_t>,\n                                 std::enable_if<dgt <= 32, __uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __uint64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\
    \ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\ntemplate\
    \ <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename\
    \ T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    };  // namespace internal\n};  // namespace kyopro\n#line 6 \"src/internal/montgomery.hpp\"\
    \nnamespace kyopro {\nnamespace internal {\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i32 = int32_t;\nusing i64 = int64_t;\nusing u128 = __uint128_t;\n\
    using i128 = __int128_t;\n/// @brief MontgomeryReduction\ntemplate <typename T>\n\
    class Montgomery {\n    static constexpr int lg = std::numeric_limits<T>::digits;\n\
    \    using LargeT = internal::double_size_uint_t<T>;\n    T mod, r, r2, minv;\n\
    \    T calc_inv() {\n        T t = 0, res = 0;\n        for (int i = 0; i < lg;\
    \ i++) {\n            if (~t & 1) {\n                t += mod;\n             \
    \   res += static_cast<T>(1) << i;\n            }\n            t >>= 1;\n    \
    \    }\n        return res;\n    }\n\npublic:\n    Montgomery() = default;\n \
    \   constexpr T get_mod() { return mod; }\n    constexpr int get_lg() { return\
    \ lg; }\n\n    void set_mod(T m) {\n        assert(m > 0);\n        assert(m &\
    \ 1);\n\n        mod = m;\n\n        r = (-static_cast<T>(mod)) % mod;\n     \
    \   r2 = (-static_cast<LargeT>(mod)) % mod;\n        minv = calc_inv();\n    }\n\
    \n    T reduce(LargeT x) const {\n        u64 res =\n            (x + static_cast<LargeT>(static_cast<T>(x)\
    \ * minv) * mod) >> lg;\n\n        if (res >= mod) res -= mod;\n        return\
    \ res;\n    }\n\n    T generate(LargeT x) { return reduce(x * r2); }\n\n    T\
    \ mult(T x, T y) { return reduce((LargeT)x * y); }\n};\n};  // namespace internal\n\
    };  // namespace kyopro\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <numeric>\n\
    #include \"../internal/type_traits.hpp\"\nnamespace kyopro {\nnamespace internal\
    \ {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i32 = int32_t;\nusing\
    \ i64 = int64_t;\nusing u128 = __uint128_t;\nusing i128 = __int128_t;\n/// @brief\
    \ MontgomeryReduction\ntemplate <typename T>\nclass Montgomery {\n    static constexpr\
    \ int lg = std::numeric_limits<T>::digits;\n    using LargeT = internal::double_size_uint_t<T>;\n\
    \    T mod, r, r2, minv;\n    T calc_inv() {\n        T t = 0, res = 0;\n    \
    \    for (int i = 0; i < lg; i++) {\n            if (~t & 1) {\n             \
    \   t += mod;\n                res += static_cast<T>(1) << i;\n            }\n\
    \            t >>= 1;\n        }\n        return res;\n    }\n\npublic:\n    Montgomery()\
    \ = default;\n    constexpr T get_mod() { return mod; }\n    constexpr int get_lg()\
    \ { return lg; }\n\n    void set_mod(T m) {\n        assert(m > 0);\n        assert(m\
    \ & 1);\n\n        mod = m;\n\n        r = (-static_cast<T>(mod)) % mod;\n   \
    \     r2 = (-static_cast<LargeT>(mod)) % mod;\n        minv = calc_inv();\n  \
    \  }\n\n    T reduce(LargeT x) const {\n        u64 res =\n            (x + static_cast<LargeT>(static_cast<T>(x)\
    \ * minv) * mod) >> lg;\n\n        if (res >= mod) res -= mod;\n        return\
    \ res;\n    }\n\n    T generate(LargeT x) { return reduce(x * r2); }\n\n    T\
    \ mult(T x, T y) { return reduce((LargeT)x * y); }\n};\n};  // namespace internal\n\
    };  // namespace kyopro"
  dependsOn:
  - src/internal/type_traits.hpp
  isVerificationFile: false
  path: src/internal/montgomery.hpp
  requiredBy:
  - src/math/primitive_root.hpp
  - src/math/miller.hpp
  - src/math/rho.hpp
  - src/math/mod_log.hpp
  - src/math/dynamic_modint.hpp
  - src/math/phi_function.hpp
  timestamp: '2023-05-01 12:49:55+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
documentation_of: src/internal/montgomery.hpp
layout: document
redirect_from:
- /library/src/internal/montgomery.hpp
- /library/src/internal/montgomery.hpp.html
title: MontgomeryReduction
---
