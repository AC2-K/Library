---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/DLP.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  - icon: ':question:'
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
    path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/matrix/Matrix Product.test.cpp
    title: test/yosupo_judge/matrix/Matrix Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Primitive_Root.test.cpp
    title: test/yosupo_judge/new/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
    title: test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No-430.test.cpp
    title: test/yuki/No-430.test.cpp
  - icon: ':x:'
    path: test/yuki/No.891.test.cpp
    title: test/yuki/No.891.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\
      \u306A\u3069)"
    links: []
  bundledCode: "#line 1 \"math/gcd.hpp\"\ntemplate<typename T>\nstatic constexpr inline\
    \ T _gcd(T a,T b){\n    T s = a, t = b;\n    while (s % t != 0) {\n        T u\
    \ = s % t;\n\n        s = t;\n        t = u;\n    }\n    return t;\n}\ntemplate<typename\
    \ T>\nstatic constexpr inline T ext_gcd(T a, T b, T &x, T &y) {\n    x = 1, y\
    \ = 0;\n    T nx = 0, ny = 1;\n    while(b) {\n        T q = a / b;\n        tie(a,\
    \ b) = make_pair(b, a % b);\n        tie(x, nx) = make_pair(nx, x - nx*q);\n \
    \       tie(y, ny) = make_pair(ny, y - ny*q);\n    }\n    return a;\n}\n/// @return\
    \ ax+by=gcd(a,b)\u306A\u308Bx,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\u5024\
    \u306Bgcd(a,b)\n\n/// @brief gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5\u306A\u3069)\n"
  code: "template<typename T>\nstatic constexpr inline T _gcd(T a,T b){\n    T s =\
    \ a, t = b;\n    while (s % t != 0) {\n        T u = s % t;\n\n        s = t;\n\
    \        t = u;\n    }\n    return t;\n}\ntemplate<typename T>\nstatic constexpr\
    \ inline T ext_gcd(T a, T b, T &x, T &y) {\n    x = 1, y = 0;\n    T nx = 0, ny\
    \ = 1;\n    while(b) {\n        T q = a / b;\n        tie(a, b) = make_pair(b,\
    \ a % b);\n        tie(x, nx) = make_pair(nx, x - nx*q);\n        tie(y, ny) =\
    \ make_pair(ny, y - ny*q);\n    }\n    return a;\n}\n/// @return ax+by=gcd(a,b)\u306A\
    \u308Bx,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\u5024\u306Bgcd(a,b)\n\n///\
    \ @brief gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306A\
    \u3069)"
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
  timestamp: '2023-03-29 14:48:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/AOJ/NTL/1_E.test.cpp
  - test/yuki/No.891.test.cpp
  - test/yuki/No-430.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/new/Primitive_Root.test.cpp
  - test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
documentation_of: math/gcd.hpp
layout: document
redirect_from:
- /library/math/gcd.hpp
- /library/math/gcd.hpp.html
title: "gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306A\u3069\
  )"
---
