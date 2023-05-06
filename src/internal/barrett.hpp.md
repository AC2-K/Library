---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/combination.hpp
    title: "\u4E8C\u9805\u4FC2\u6570\u306A\u3069"
  - icon: ':heavy_check_mark:'
    path: src/math/dynamic_modint.hpp
    title: dynamic modint
  - icon: ':heavy_check_mark:'
    path: src/math/miller.hpp
    title: src/math/miller.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  - icon: ':heavy_check_mark:'
    path: src/math/phi_function.hpp
    title: "phi function($\\phi$ \u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: src/math/primitive_root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':heavy_check_mark:'
    path: src/math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
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
    document_title: barrett reduction
    links:
    - https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
  bundledCode: "#line 2 \"src/internal/barrett.hpp\"\n#include <cstdint>\nnamespace\
    \ kyopro {\nnamespace internal {\n/// @brief barrett reduction\n/// @ref\n///\
    \ https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    class barrett {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u32\
    \ m;\n    u64 im;\n\npublic:\n    constexpr barrett() : m(0), im(0) {}\n    constexpr\
    \ barrett(u32 m_)\n        : m(m_), im((u64) static_cast<u64>(-1) / m_ + 1) {}\n\
    \n    constexpr u32 get_mod() const { return m; }\n    constexpr u32 reduce(int64_t\
    \ a) const { return mul(a, 1); }\n    constexpr u32 mul(u32 a, u32 b) const {\n\
    \        if (!a || !b) {\n            return 0;\n        }\n        u64 z = (u64)a\
    \ * b;\n        u64 x = (u64)(((__uint128_t)z * im) >> 64);\n\n        u64 y =\
    \ x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n    }\n};\n};  // namespace\
    \ internal\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <cstdint>\nnamespace kyopro {\nnamespace internal\
    \ {\n/// @brief barrett reduction\n/// @ref\n/// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    class barrett {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u32\
    \ m;\n    u64 im;\n\npublic:\n    constexpr barrett() : m(0), im(0) {}\n    constexpr\
    \ barrett(u32 m_)\n        : m(m_), im((u64) static_cast<u64>(-1) / m_ + 1) {}\n\
    \n    constexpr u32 get_mod() const { return m; }\n    constexpr u32 reduce(int64_t\
    \ a) const { return mul(a, 1); }\n    constexpr u32 mul(u32 a, u32 b) const {\n\
    \        if (!a || !b) {\n            return 0;\n        }\n        u64 z = (u64)a\
    \ * b;\n        u64 x = (u64)(((__uint128_t)z * im) >> 64);\n\n        u64 y =\
    \ x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n    }\n};\n};  // namespace\
    \ internal\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/internal/barrett.hpp
  requiredBy:
  - src/math/primitive_root.hpp
  - src/math/miller.hpp
  - src/math/rho.hpp
  - src/math/mod_log.hpp
  - src/math/combination.hpp
  - src/math/dynamic_modint.hpp
  - src/math/phi_function.hpp
  timestamp: '2023-05-06 03:56:17+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yuki/No3030.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
documentation_of: src/internal/barrett.hpp
layout: document
redirect_from:
- /library/src/internal/barrett.hpp
- /library/src/internal/barrett.hpp.html
title: barrett reduction
---
