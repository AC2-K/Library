---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/math/static_modint.hpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
      \u4E92\u9664\u6CD5)"
    links: []
  bundledCode: "#line 1 \"src/math/ext_gcd.hpp\"\nstatic constexpr ll ext_gcd(ll a,\
    \ ll b, ll& x, ll& y) {\n    ll u = 0, v = 1, q = 0, tmp = 0;\n    x = 1;\n  \
    \  y = 0;\n    while (b) {\n        q = a / b;\n        tmp = u;\n        u =\
    \ x - q * u;\n        x = tmp;\n        tmp = v;\n        v = y - q * v;\n   \
    \     y = tmp;\n        tmp = b;\n        b = a - q * b;\n        a = tmp;\n \
    \   }\n    return a;\n}\n/// @brief ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\
    \u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n/// @return ax+by=gcd(a,b)\u306A\u308B\
    x,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\u5024\u306Bgcd(a,b)\n"
  code: "static constexpr ll ext_gcd(ll a, ll b, ll& x, ll& y) {\n    ll u = 0, v\
    \ = 1, q = 0, tmp = 0;\n    x = 1;\n    y = 0;\n    while (b) {\n        q = a\
    \ / b;\n        tmp = u;\n        u = x - q * u;\n        x = tmp;\n        tmp\
    \ = v;\n        v = y - q * v;\n        y = tmp;\n        tmp = b;\n        b\
    \ = a - q * b;\n        a = tmp;\n    }\n    return a;\n}\n/// @brief ext gcd(\u62E1\
    \u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n/// @return\
    \ ax+by=gcd(a,b)\u306A\u308Bx,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\u5024\
    \u306Bgcd(a,b)"
  dependsOn: []
  isVerificationFile: false
  path: src/math/ext_gcd.hpp
  requiredBy:
  - src/math/static_modint.hpp
  timestamp: '2023-03-27 01:42:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
  - test/AOJ/NTL/1/E.test.cpp
documentation_of: src/math/ext_gcd.hpp
layout: document
redirect_from:
- /library/src/math/ext_gcd.hpp
- /library/src/math/ext_gcd.hpp.html
title: "ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
  \u6CD5)"
---
