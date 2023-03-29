---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/DLP.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/static_modint.hpp
    title: "static modint(\u9759\u7684modint)"
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: "Rollinghash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS/14/B.test.cpp
    title: test/AOJ/ALDS/14/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/E.test.cpp
    title: test/AOJ/NTL/1/E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/matrix/Matrix Product.test.cpp
    title: test/yosupo_judge/matrix/Matrix Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
    title: test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No-430.test.cpp
    title: test/yuki/No-430.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No.891.test.cpp
    title: test/yuki/No.891.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
      \u4E92\u9664\u6CD5)"
    links: []
  bundledCode: "#line 1 \"math/gcd.hpp\"\ntemplate<class T>\nstatic constexpr inline\
    \ T _gcd(T a,T b){\n    T s = a, t = b;\n    while (s % t != 0) {\n        T u\
    \ = s % t;\n\n        s = t;\n        t = u;\n    }\n    return t;\n}\nstatic\
    \ constexpr inline ll ext_gcd(ll a, ll b, ll &x, ll &y) {\n    x = 1, y = 0;\n\
    \    ll nx = 0, ny = 1;\n    while(b) {\n        long long q = a / b;\n      \
    \  tie(a, b) = make_pair(b, a % b);\n        tie(x, nx) = make_pair(nx, x - nx*q);\n\
    \        tie(y, ny) = make_pair(ny, y - ny*q);\n    }\n    return a;\n}\n\n///\
    \ @brief ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
    \u6CD5)\n/// @return ax+by=gcd(a,b)\u306A\u308Bx,y\u3092\u683C\u7D0D\u3059\u308B\
    ,\u8FD4\u308A\u5024\u306Bgcd(a,b)\n"
  code: "template<class T>\nstatic constexpr inline T _gcd(T a,T b){\n    T s = a,\
    \ t = b;\n    while (s % t != 0) {\n        T u = s % t;\n\n        s = t;\n \
    \       t = u;\n    }\n    return t;\n}\nstatic constexpr inline ll ext_gcd(ll\
    \ a, ll b, ll &x, ll &y) {\n    x = 1, y = 0;\n    ll nx = 0, ny = 1;\n    while(b)\
    \ {\n        long long q = a / b;\n        tie(a, b) = make_pair(b, a % b);\n\
    \        tie(x, nx) = make_pair(nx, x - nx*q);\n        tie(y, ny) = make_pair(ny,\
    \ y - ny*q);\n    }\n    return a;\n}\n\n/// @brief ext gcd(\u62E1\u5F35\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n/// @return ax+by=gcd(a,b)\u306A\
    \u308Bx,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\u5024\u306Bgcd(a,b)"
  dependsOn: []
  isVerificationFile: false
  path: math/gcd.hpp
  requiredBy:
  - math/DLP.hpp
  - math/static_modint.hpp
  - string/rolling_hash.hpp
  timestamp: '2023-03-29 14:26:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/No-430.test.cpp
  - test/yuki/No.891.test.cpp
  - test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
  - test/yosupo_judge/math/Discrete Logarithm.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
  - test/AOJ/NTL/1/E.test.cpp
  - test/AOJ/ALDS/14/B.test.cpp
documentation_of: math/gcd.hpp
layout: document
redirect_from:
- /library/math/gcd.hpp
- /library/math/gcd.hpp.html
title: "ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
  \u6CD5)"
---
