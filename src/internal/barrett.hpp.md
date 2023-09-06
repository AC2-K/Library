---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/dynamic_modint.hpp
    title: "\u52D5\u7684modint"
  - icon: ':heavy_check_mark:'
    path: src/math/miller.hpp
    title: "MillerRabin\u7D20\u6570\u5224\u5B9A\u6CD5"
  - icon: ':heavy_check_mark:'
    path: src/math/phi_function.hpp
    title: "Euler\u306E $\\phi$ \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: src/math/primitive_root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':heavy_check_mark:'
    path: src/math/rho.hpp
    title: "Pollard Rho \u7D20\u56E0\u6570\u5206\u89E3\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
    title: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
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
    \ kyopro {\nnamespace internal {\n\n/**\n * @brief Barrett Reduction\n */\nclass\
    \ barrett {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n    using u128\
    \ = __uint128_t;\n\n    u32 m;\n    u64 im;\n\npublic:\n    constexpr explicit\
    \ barrett() : m(0), im(0) {}\n    constexpr explicit barrett(u32 m)\n        :\
    \ m(m), im(static_cast<u64>(-1) / m + 1) {}\n\n    constexpr u32 get_mod() const\
    \ { return m; }\n    constexpr u32 reduce(u32 a) const { return mul(1, a); }\n\
    \    constexpr u32 mul(u32 a, u32 b) const {\n        u64 z = (u64)a * b;\n  \
    \      u64 x = (u64)(((u128)(z)*im) >> 64);\n        u64 y = x * m;\n        return\
    \ (u32)(z - y + (z < y ? m : 0));\n    }\n};\n};  // namespace internal\n};  //\
    \ namespace kyopro\n\n/**\n * @ref\n * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */\n"
  code: "#pragma once\n#include <cstdint>\nnamespace kyopro {\nnamespace internal\
    \ {\n\n/**\n * @brief Barrett Reduction\n */\nclass barrett {\n    using u32 =\
    \ uint32_t;\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\n    u32\
    \ m;\n    u64 im;\n\npublic:\n    constexpr explicit barrett() : m(0), im(0) {}\n\
    \    constexpr explicit barrett(u32 m)\n        : m(m), im(static_cast<u64>(-1)\
    \ / m + 1) {}\n\n    constexpr u32 get_mod() const { return m; }\n    constexpr\
    \ u32 reduce(u32 a) const { return mul(1, a); }\n    constexpr u32 mul(u32 a,\
    \ u32 b) const {\n        u64 z = (u64)a * b;\n        u64 x = (u64)(((u128)(z)*im)\
    \ >> 64);\n        u64 y = x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n\
    \    }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n * @ref\n\
    \ * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: src/internal/barrett.hpp
  requiredBy:
  - src/math/primitive_root.hpp
  - src/math/phi_function.hpp
  - src/math/dynamic_modint.hpp
  - src/math/rho.hpp
  - src/math/miller.hpp
  timestamp: '2023-06-25 12:32:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yuki/No3030.test.cpp
  - test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
documentation_of: src/internal/barrett.hpp
layout: document
redirect_from:
- /library/src/internal/barrett.hpp
- /library/src/internal/barrett.hpp.html
title: Barrett Reduction
---
