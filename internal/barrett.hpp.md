---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/dynamic_modint.hpp
    title: dynamic_modint(64bit)
  - icon: ':heavy_check_mark:'
    path: math/miller.hpp
    title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\\phi \u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: math/rho.hpp
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
    path: test/yuki/No-3030.test.cpp
    title: test/yuki/No-3030.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: barrett reduction
    links: []
  bundledCode: "#line 2 \"internal/barrett.hpp\"\nnamespace internal {\n\t///@brief\
    \ barrett reduction\n\tclass barrett {\n\t\tusing u32 = uint32_t;\n\t\tusing u64\
    \ = uint64_t;\n\n\t\tu64 m;\n\t\tu64 im;\n\tpublic:\n\t\texplicit barrett() =\
    \ default;\n\t\texplicit barrett(u64 m_) :m(m_), im((u64)(long double)static_cast<u64>(-1)\
    \ / m_ + 1) {}\n\n\t\tu64 get_mod() const { return m; }\n\t\tu64 reduce(int64_t\
    \ a)const{\n        \tif (a < 0) return m - reduce(-a);\n            u64 q = ((__uint128_t)a\
    \ * im) >> 64;\n            a -= m * q;\n            if (a >= m) a -= m;\n   \
    \         return a;\n        }\n\t\tu64 mul(u64 a, u64 b) {\n\t\t\tif (a == 0\
    \ || b == 0) {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tu64 z = a;\n\t\t\tz *= b;\n\t\
    \t\tu64 x = (u64)(((__uint128_t)(z)*im) >> 64);\n\n\t\t\tu32 v = (u32)(z - x *\
    \ m);\n\n\t\t\tif (v >= m)v += m;\n\t\t\treturn v;\n\t\t}\n\t};\n}\n"
  code: "#pragma once\nnamespace internal {\n\t///@brief barrett reduction\n\tclass\
    \ barrett {\n\t\tusing u32 = uint32_t;\n\t\tusing u64 = uint64_t;\n\n\t\tu64 m;\n\
    \t\tu64 im;\n\tpublic:\n\t\texplicit barrett() = default;\n\t\texplicit barrett(u64\
    \ m_) :m(m_), im((u64)(long double)static_cast<u64>(-1) / m_ + 1) {}\n\n\t\tu64\
    \ get_mod() const { return m; }\n\t\tu64 reduce(int64_t a)const{\n        \tif\
    \ (a < 0) return m - reduce(-a);\n            u64 q = ((__uint128_t)a * im) >>\
    \ 64;\n            a -= m * q;\n            if (a >= m) a -= m;\n            return\
    \ a;\n        }\n\t\tu64 mul(u64 a, u64 b) {\n\t\t\tif (a == 0 || b == 0) {\n\t\
    \t\t\treturn 0;\n\t\t\t}\n\t\t\tu64 z = a;\n\t\t\tz *= b;\n\t\t\tu64 x = (u64)(((__uint128_t)(z)*im)\
    \ >> 64);\n\n\t\t\tu32 v = (u32)(z - x * m);\n\n\t\t\tif (v >= m)v += m;\n\t\t\
    \treturn v;\n\t\t}\n\t};\n}"
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
  timestamp: '2023-04-07 10:30:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
