---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/FormalPowerSeries/fps-sqrt.hpp
    title: Sqrt of FPS
  - icon: ':heavy_check_mark:'
    path: src/math/dynamic_modint.hpp
    title: Dynamic modint
  - icon: ':heavy_check_mark:'
    path: src/math/miller.hpp
    title: "Primality Test(MillerRabin\u7D20\u6570\u5224\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: src/math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59(O(\u221Ap))"
  - icon: ':heavy_check_mark:'
    path: src/math/phi_function.hpp
    title: "Euler\u306E $\\varphi$ \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: src/math/primitive_root.hpp
    title: "Primitive Root(\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: src/math/rho.hpp
    title: "PollardRho\u7D20\u56E0\u6570\u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Binomial_Coeffcient_Prime.test.cpp
    title: test/yosupo_judge/math/Binomial_Coeffcient_Prime.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No3030.test.cpp
    title: test/yuki/No3030.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Barrett Reduction
    links:
    - https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
  bundledCode: "#line 2 \"src/internal/barrett.hpp\"\n#include <cstdint>\nnamespace\
    \ kyopro {\nnamespace internal {\nclass barrett {\n    using u32 = std::uint32_t;\n\
    \    using u64 = std::uint64_t;\n    using u128 = __uint128_t;\n\n    u32 m;\n\
    \    u64 im;\n\npublic:\n    constexpr barrett() : m(0), im(0) {}\n    constexpr\
    \ barrett(u32 m)\n        : m(m), im(static_cast<u64>(-1) / m + 1) {}\n\n    constexpr\
    \ u32 get_mod() const { return m; }\n    constexpr u32 reduce(u32 a) const { return\
    \ mul(1, a); }\n    constexpr u32 mul(u32 a, u32 b) const {\n        u64 z = (u64)a\
    \ * b;\n        u64 x = (u64)(((u128)(z)*im) >> 64);\n        u64 y = x * m;\n\
    \        return (u32)(z - y + (z < y ? m : 0));\n    }\n};\n};  // namespace internal\n\
    };  // namespace kyopro\n\n/**\n * @brief Barrett Reduction\n * @see https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */\n"
  code: "#pragma once\n#include <cstdint>\nnamespace kyopro {\nnamespace internal\
    \ {\nclass barrett {\n    using u32 = std::uint32_t;\n    using u64 = std::uint64_t;\n\
    \    using u128 = __uint128_t;\n\n    u32 m;\n    u64 im;\n\npublic:\n    constexpr\
    \ barrett() : m(0), im(0) {}\n    constexpr barrett(u32 m)\n        : m(m), im(static_cast<u64>(-1)\
    \ / m + 1) {}\n\n    constexpr u32 get_mod() const { return m; }\n    constexpr\
    \ u32 reduce(u32 a) const { return mul(1, a); }\n    constexpr u32 mul(u32 a,\
    \ u32 b) const {\n        u64 z = (u64)a * b;\n        u64 x = (u64)(((u128)(z)*im)\
    \ >> 64);\n        u64 y = x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n\
    \    }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n * @brief\
    \ Barrett Reduction\n * @see https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: src/internal/barrett.hpp
  requiredBy:
  - src/math/primitive_root.hpp
  - src/math/dynamic_modint.hpp
  - src/math/rho.hpp
  - src/math/phi_function.hpp
  - src/math/miller.hpp
  - src/math/mod_sqrt.hpp
  - src/FormalPowerSeries/fps-sqrt.hpp
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yuki/No3030.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yosupo_judge/math/Binomial_Coeffcient_Prime.test.cpp
  - test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
documentation_of: src/internal/barrett.hpp
layout: document
redirect_from:
- /library/src/internal/barrett.hpp
- /library/src/internal/barrett.hpp.html
title: Barrett Reduction
---
