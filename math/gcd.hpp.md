---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/DLP.hpp
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
  - icon: ':heavy_check_mark:'
    path: math/static_modint.hpp
    title: "static modint(\u9759\u7684modint)"
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_E.test.cpp
    title: test/AOJ/NTL/1_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/matrix/Matrix Product.test.cpp
    title: test/yosupo_judge/matrix/Matrix Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No-430.test.cpp
    title: test/yuki/No-430.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No.891.test.cpp
    title: test/yuki/No.891.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/gcd.hpp\"\ntemplate<typename T>\nconstexpr inline T\
    \ _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return\
    \ a + b;\n    int d = min(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>=\
    \ __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n      \
    \  if (a == 0 || b == 0) {\n            return a + b;\n        }\n        if (a\
    \ > b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n       \
    \ }else{\n            b -= a;\n            b >>= __builtin_ctzll(b);\n       \
    \ }\n    }\n\n    return a << d;\n}\ntemplate<typename T>\nconstexpr inline T\
    \ ext_gcd(T a, T b, T &x, T &y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while(b) {\n        T q = a / b;\n        tie(a, b) = make_pair(b, a % b);\n\
    \        tie(x, nx) = make_pair(nx, x - nx*q);\n        tie(y, ny) = make_pair(ny,\
    \ y - ny*q);\n    }\n    return a;\n}\n"
  code: "#pragma once\ntemplate<typename T>\nconstexpr inline T _gcd(T a, T b) {\n\
    \    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int\
    \ d = min(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a),\
    \ b >>= __builtin_ctzll(b);\n    while (a != b) {\n        if (a == 0 || b ==\
    \ 0) {\n            return a + b;\n        }\n        if (a > b) {\n         \
    \   a -= b;\n            a >>= __builtin_ctzll(a);\n        }else{\n         \
    \   b -= a;\n            b >>= __builtin_ctzll(b);\n        }\n    }\n\n    return\
    \ a << d;\n}\ntemplate<typename T>\nconstexpr inline T ext_gcd(T a, T b, T &x,\
    \ T &y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while(b) {\n        T\
    \ q = a / b;\n        tie(a, b) = make_pair(b, a % b);\n        tie(x, nx) = make_pair(nx,\
    \ x - nx*q);\n        tie(y, ny) = make_pair(ny, y - ny*q);\n    }\n    return\
    \ a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/gcd.hpp
  requiredBy:
  - math/static_modint.hpp
  - math/DLP.hpp
  - math/rho.hpp
  - math/primitive_root.hpp
  - math/phi_function.hpp
  - string/rolling_hash.hpp
  timestamp: '2023-04-02 12:04:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/AOJ/NTL/1_E.test.cpp
  - test/yuki/No.891.test.cpp
  - test/yuki/No-430.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
documentation_of: math/gcd.hpp
layout: document
redirect_from:
- /library/math/gcd.hpp
- /library/math/gcd.hpp.html
title: math/gcd.hpp
---
