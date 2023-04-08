---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/dynamic_modint.hpp
    title: "dynamic modint(\u52D5\u7684modint)"
  - icon: ':heavy_check_mark:'
    path: src/math/miller.hpp
    title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':heavy_check_mark:'
    path: src/math/phi_function.hpp
    title: "phi function($\\phi$ \u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: src/math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: barrett reduction
    links: []
  bundledCode: "#line 2 \"src/internal/barrett.hpp\"\nnamespace kyopro {\nnamespace\
    \ internal {\n///@brief barrett reduction\nclass barrett {\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    u64 m;\n    u64 im;\n\n  public:\n    explicit\
    \ barrett() = default;\n    explicit barrett(u64 m_)\n        : m(m_), im((u64)(long\
    \ double)static_cast<u64>(-1) / m_ + 1) {}\n\n    inline u64 get_mod() const {\
    \ return m; }\n    constexpr u64 reduce(int64_t a) const {\n        if (a < 0)\
    \ return m - reduce(-a);\n        u64 q = ((__uint128_t)a * im) >> 64;\n     \
    \   a -= m * q;\n        if (a >= m) a -= m;\n        return a;\n    }\n    constexpr\
    \ u64 mul(u64 a, u64 b) const {\n        if (a == 0 || b == 0) {\n           \
    \ return 0;\n        }\n        u64 z = a;\n        z *= b;\n        u64 x = (u64)(((__uint128_t)z\
    \ * im) >> 64);\n\n        u32 v = (u32)(z - x * m);\n\n        if (v >= m) v\
    \ += m;\n        return v;\n    }\n};\n};  // namespace internal\n};  // namespace\
    \ kyopro\n"
  code: "#pragma once\nnamespace kyopro {\nnamespace internal {\n///@brief barrett\
    \ reduction\nclass barrett {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \n    u64 m;\n    u64 im;\n\n  public:\n    explicit barrett() = default;\n  \
    \  explicit barrett(u64 m_)\n        : m(m_), im((u64)(long double)static_cast<u64>(-1)\
    \ / m_ + 1) {}\n\n    inline u64 get_mod() const { return m; }\n    constexpr\
    \ u64 reduce(int64_t a) const {\n        if (a < 0) return m - reduce(-a);\n \
    \       u64 q = ((__uint128_t)a * im) >> 64;\n        a -= m * q;\n        if\
    \ (a >= m) a -= m;\n        return a;\n    }\n    constexpr u64 mul(u64 a, u64\
    \ b) const {\n        if (a == 0 || b == 0) {\n            return 0;\n       \
    \ }\n        u64 z = a;\n        z *= b;\n        u64 x = (u64)(((__uint128_t)z\
    \ * im) >> 64);\n\n        u32 v = (u32)(z - x * m);\n\n        if (v >= m) v\
    \ += m;\n        return v;\n    }\n};\n};  // namespace internal\n};  // namespace\
    \ kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/internal/barrett.hpp
  requiredBy:
  - src/math/dynamic_modint.hpp
  - src/math/miller.hpp
  - src/math/phi_function.hpp
  - src/math/mod_log.hpp
  - src/math/primitive_root.hpp
  - src/math/rho.hpp
  timestamp: '2023-04-08 13:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/AOJ/NTL/1_D.test.cpp
documentation_of: src/internal/barrett.hpp
layout: document
redirect_from:
- /library/src/internal/barrett.hpp
- /library/src/internal/barrett.hpp.html
title: barrett reduction
---
