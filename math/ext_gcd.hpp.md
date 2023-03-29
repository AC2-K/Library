---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/static_modint.hpp
    title: "static modint(\u9759\u7684modint)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/E.test.cpp
    title: test/AOJ/NTL/1/E.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/matrix/Matrix Product.test.cpp
    title: test/yosupo_judge/matrix/Matrix Product.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
    title: test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
  - icon: ':x:'
    path: test/yuki/No.891.test.cpp
    title: test/yuki/No.891.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
      \u4E92\u9664\u6CD5)"
    links: []
  bundledCode: "#line 1 \"math/ext_gcd.hpp\"\nstatic constexpr inline ll ext_gcd(ll\
    \ a, ll b, ll &x, ll &y) {\n    x = 1, y = 0;\n    ll nx = 0, ny = 1;\n    while(b)\
    \ {\n        long long q = a / b;\n        tie(a, b) = make_pair(b, a % b);\n\
    \        tie(x, nx) = make_pair(nx, x - nx*q);\n        tie(y, ny) = make_pair(ny,\
    \ y - ny*q);\n    }\n    return a;\n}\n\n/// @brief ext gcd(\u62E1\u5F35\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n/// @return ax+by=gcd(a,b)\u306A\
    \u308Bx,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\u5024\u306Bgcd(a,b)\n"
  code: "static constexpr inline ll ext_gcd(ll a, ll b, ll &x, ll &y) {\n    x = 1,\
    \ y = 0;\n    ll nx = 0, ny = 1;\n    while(b) {\n        long long q = a / b;\n\
    \        tie(a, b) = make_pair(b, a % b);\n        tie(x, nx) = make_pair(nx,\
    \ x - nx*q);\n        tie(y, ny) = make_pair(ny, y - ny*q);\n    }\n    return\
    \ a;\n}\n\n/// @brief ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\
    \u306E\u4E92\u9664\u6CD5)\n/// @return ax+by=gcd(a,b)\u306A\u308Bx,y\u3092\u683C\
    \u7D0D\u3059\u308B,\u8FD4\u308A\u5024\u306Bgcd(a,b)"
  dependsOn: []
  isVerificationFile: false
  path: math/ext_gcd.hpp
  requiredBy:
  - math/static_modint.hpp
  timestamp: '2023-03-29 14:13:41+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yuki/No.891.test.cpp
  - test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
  - test/AOJ/NTL/1/E.test.cpp
documentation_of: math/ext_gcd.hpp
layout: document
redirect_from:
- /library/math/ext_gcd.hpp
- /library/math/ext_gcd.hpp.html
title: "ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
  \u6CD5)"
---
