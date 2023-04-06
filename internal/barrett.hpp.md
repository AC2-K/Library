---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: math/dynamic_modint.hpp
    title: "dynamic modint(\u52D5\u7684modint)"
  - icon: ':question:'
    path: math/miller.hpp
    title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "$\\phi$ \u95A2\u6570"
  - icon: ':x:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':question:'
    path: math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  - icon: ':x:'
    path: test/yuki/No-3030.test.cpp
    title: test/yuki/No-3030.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: barrett reduction
    links: []
  bundledCode: "#line 2 \"internal/barrett.hpp\"\n#include<iostream>\nnamespace library\
    \ {\nnamespace internal {\n/// @brief barrett reduction\nclass barrett {\n   \
    \ using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u64 m;\n    u64 im;\n\
    \n  public:\n    explicit barrett() = default;\n    constexpr explicit barrett(u64\
    \ m_)\n        : m(m_), im((u64)(long double)static_cast<u64>(-1) / m_ + 1) {}\n\
    \n    inline u64 get_mod() const { return m; }\n    inline u64 reduce(int64_t\
    \ a) const {\n        if (a < 0) return m - reduce(-a);\n        u64 q = ((__uint128_t)a\
    \ * im) >> 64;\n        a -= m * q;\n        if (a >= m) a -= m;\n        return\
    \ a;\n    }\n    inline u64 mul(u64 a, u64 b) {\n        if (a == 0 || b == 0)\
    \ {\n            return 0;\n        }\n        u64 z = a;\n        z *= b;\n \
    \       u64 x = (u64)(((__uint128_t)(z)*im) >> 64);\n\n        u32 v = (u32)(z\
    \ - x * m);\n\n        if (v >= m) v += m;\n        return v;\n    }\n};\n}; \
    \ // namespace internal\n};  // namespace library\n"
  code: "#pragma once\n#include<iostream>\nnamespace library {\nnamespace internal\
    \ {\n/// @brief barrett reduction\nclass barrett {\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    u64 m;\n    u64 im;\n\n  public:\n    explicit\
    \ barrett() = default;\n    constexpr explicit barrett(u64 m_)\n        : m(m_),\
    \ im((u64)(long double)static_cast<u64>(-1) / m_ + 1) {}\n\n    inline u64 get_mod()\
    \ const { return m; }\n    inline u64 reduce(int64_t a) const {\n        if (a\
    \ < 0) return m - reduce(-a);\n        u64 q = ((__uint128_t)a * im) >> 64;\n\
    \        a -= m * q;\n        if (a >= m) a -= m;\n        return a;\n    }\n\
    \    inline u64 mul(u64 a, u64 b) {\n        if (a == 0 || b == 0) {\n       \
    \     return 0;\n        }\n        u64 z = a;\n        z *= b;\n        u64 x\
    \ = (u64)(((__uint128_t)(z)*im) >> 64);\n\n        u32 v = (u32)(z - x * m);\n\
    \n        if (v >= m) v += m;\n        return v;\n    }\n};\n};  // namespace\
    \ internal\n};  // namespace library"
  dependsOn: []
  isVerificationFile: false
  path: internal/barrett.hpp
  requiredBy:
  - math/mod_log.hpp
  - math/rho.hpp
  - math/miller.hpp
  - math/dynamic_modint.hpp
  - math/phi_function.hpp
  - math/primitive_root.hpp
  timestamp: '2023-04-06 21:43:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yuki/No-3030.test.cpp
documentation_of: internal/barrett.hpp
layout: document
redirect_from:
- /library/internal/barrett.hpp
- /library/internal/barrett.hpp.html
title: barrett reduction
---
