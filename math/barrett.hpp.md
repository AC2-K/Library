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
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
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
    path: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Primitive_Root.test.cpp
    title: test/yosupo_judge/new/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No-3030.test.cpp
    title: test/yuki/No-3030.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: barrett reduction
    links: []
  bundledCode: "#line 2 \"math/barrett.hpp\"\nnamespace internal {\n\t///@brief barrett\
    \ reduction\n\tclass barrett {\n\t\tusing u32 = uint32_t;\n\t\tusing u64 = uint64_t;\n\
    \n\t\tu32 m;\n\t\tu64 im;\n\tpublic:\n\t\texplicit barrett() = default;\n\t\t\
    explicit barrett(const u32& m_) :m(m_), im((u64)(-1) / m_ + 1) {}\n\n\t\tu32 get_mod()\
    \ const { return m; }\n\t\tu32 mul(u32 a, u32 b) {\n\t\t\tif (a == 0 || b == 0)\
    \ {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tu64 z = a;\n\t\t\tz *= b;\n#ifdef _MSC_VER\n\
    \t\t\tu64 x;\n\n\t\t\t_umul128(z, im, &x);\n#else\n\t\t\tu64 x = (u64)(((__uint128_t)(z)*im)\
    \ >> 64);\n#endif\n\n\t\t\tu32 v = (u32)(z - x * m);\n\n\t\t\tif (v >= m)v +=\
    \ m;\n\t\t\treturn v;\n\t\t}\n\t};\n}\n"
  code: "#pragma once\nnamespace internal {\n\t///@brief barrett reduction\n\tclass\
    \ barrett {\n\t\tusing u32 = uint32_t;\n\t\tusing u64 = uint64_t;\n\n\t\tu32 m;\n\
    \t\tu64 im;\n\tpublic:\n\t\texplicit barrett() = default;\n\t\texplicit barrett(const\
    \ u32& m_) :m(m_), im((u64)(-1) / m_ + 1) {}\n\n\t\tu32 get_mod() const { return\
    \ m; }\n\t\tu32 mul(u32 a, u32 b) {\n\t\t\tif (a == 0 || b == 0) {\n\t\t\t\treturn\
    \ 0;\n\t\t\t}\n\t\t\tu64 z = a;\n\t\t\tz *= b;\n#ifdef _MSC_VER\n\t\t\tu64 x;\n\
    \n\t\t\t_umul128(z, im, &x);\n#else\n\t\t\tu64 x = (u64)(((__uint128_t)(z)*im)\
    \ >> 64);\n#endif\n\n\t\t\tu32 v = (u32)(z - x * m);\n\n\t\t\tif (v >= m)v +=\
    \ m;\n\t\t\treturn v;\n\t\t}\n\t};\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/barrett.hpp
  requiredBy:
  - math/rho.hpp
  - math/dynamic_modint.hpp
  - math/primitive_root.hpp
  - math/phi_function.hpp
  - math/miller.hpp
  timestamp: '2023-03-26 20:22:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yuki/No-3030.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/new/Primitive_Root.test.cpp
documentation_of: math/barrett.hpp
layout: document
redirect_from:
- /library/math/barrett.hpp
- /library/math/barrett.hpp.html
title: barrett reduction
---
