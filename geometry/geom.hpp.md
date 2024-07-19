---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Geometry(\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
    links: []
  bundledCode: "#line 2 \"geometry/geom.hpp\"\n\n#include<complex>\n#include<vector>\n\
    #include<algorithm>\n\nnamespace geometry {\n\nusing T = ; // \u5909\u66F4\u3059\
    \u308B\n\nconstexpr T eps = 0;  // \u7CBE\u5EA6\u306B\u3088\u3063\u3066\u5909\u66F4\
    \u3059\u308B\nconstexpr inline int sgn(T x) noexcept {\n    return x < -eps ?\
    \ -1 : (x > eps ? 1 : 0);\n}\n\nusing point = complex<T>;\nusing vec = point;\n\
    \nconstexpr inline point rotate_complex(T theta) noexcept {  // \u56DE\u8EE2\u884C\
    \u5217\n    return complex<T>(cos(theta), sin(theta));\n}\n\nconstexpr inline\
    \ T dot(point x, point y) noexcept {  // \u5185\u7A4D\n    return x.real() * y.real()\
    \ + x.imag() * y.imag();\n}\n\nconstexpr inline T det(point x, point y) noexcept\
    \ {  // \u5916\u7A4D(\u306Ez\u6210\u5206)\n    return x.real() * y.imag() - x.imag()\
    \ * y.real();\n}\n\nconstexpr inline T arg(point z) noexcept {  // \u504F\u89D2\
    \n    return atan2(z.imag(), z.real());\n}\n\nconstexpr inline bool operator==(point\
    \ x, point y) noexcept {   \n    return sgn(x.real() - y.real()) == 0 && sgn(x.imag()\
    \ - y.imag()) == 0;\n}\nconstexpr inline bool operator<(point x, point y) noexcept\
    \ {\n    if (sgn(x.real() - y.real()) != 0) {\n        return sgn(x.real() - y.real())\
    \ == -1;\n    } else {\n        return sgn(x.imag() - y.imag()) == -1;\n    }\n\
    }\nconstexpr inline bool operator>(point x, point y) noexcept {\n    if (sgn(x.real()\
    \ - y.real()) != 0) {\n        return sgn(x.real() - y.real()) == 1;\n    } else\
    \ {\n        return sgn(x.imag() - y.imag()) == 1;\n    }\n}\nconstexpr inline\
    \ bool operator<=(point x, point y) noexcept {\n    return x == y || x < y;\n\
    }\nconstexpr inline bool operator>=(point x, point y) noexcept {\n    return x\
    \ == y || x > y;\n}\n\nvoid sort_by_arg(vector<point>& points) {   // \u504F\u89D2\
    \u30BD\u30FC\u30C8(arg\u306F(-pi,pi])\n    auto where_area = [&](const point&\
    \ x) {\n        if (x.imag() < 0) {\n            return -1;\n        } else if\
    \ (x.imag() == 0 && x.real() >= 0) {\n            return 0;\n        } else {\n\
    \            return 1;\n        }\n    };\n\n    auto compare = [&](const point&\
    \ x, const point& y) {\n        if (where_area(x) != where_area(y)) {\n      \
    \      return where_area(x) < where_area(y);\n        } else {\n            //\
    \ \u53CD\u6642\u8A08\u56DE\u308A\u306B x -> y\u306B\u306A\u3063\u3066\u305F\u3089\
    \ det(x,y) > 0\n            return sgn(det(x, y)) > 0;\n        }\n    };\n\n\
    \    std::sort(points.begin(), points.end(), compare);\n}\n\n};  // namespace\
    \ geometry\n\n/**\n * @brief Geometry(\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8)\n */\n"
  code: "#pragma once\n\n#include<complex>\n#include<vector>\n#include<algorithm>\n\
    \nnamespace geometry {\n\nusing T = ; // \u5909\u66F4\u3059\u308B\n\nconstexpr\
    \ T eps = 0;  // \u7CBE\u5EA6\u306B\u3088\u3063\u3066\u5909\u66F4\u3059\u308B\n\
    constexpr inline int sgn(T x) noexcept {\n    return x < -eps ? -1 : (x > eps\
    \ ? 1 : 0);\n}\n\nusing point = complex<T>;\nusing vec = point;\n\nconstexpr inline\
    \ point rotate_complex(T theta) noexcept {  // \u56DE\u8EE2\u884C\u5217\n    return\
    \ complex<T>(cos(theta), sin(theta));\n}\n\nconstexpr inline T dot(point x, point\
    \ y) noexcept {  // \u5185\u7A4D\n    return x.real() * y.real() + x.imag() *\
    \ y.imag();\n}\n\nconstexpr inline T det(point x, point y) noexcept {  // \u5916\
    \u7A4D(\u306Ez\u6210\u5206)\n    return x.real() * y.imag() - x.imag() * y.real();\n\
    }\n\nconstexpr inline T arg(point z) noexcept {  // \u504F\u89D2\n    return atan2(z.imag(),\
    \ z.real());\n}\n\nconstexpr inline bool operator==(point x, point y) noexcept\
    \ {   \n    return sgn(x.real() - y.real()) == 0 && sgn(x.imag() - y.imag()) ==\
    \ 0;\n}\nconstexpr inline bool operator<(point x, point y) noexcept {\n    if\
    \ (sgn(x.real() - y.real()) != 0) {\n        return sgn(x.real() - y.real()) ==\
    \ -1;\n    } else {\n        return sgn(x.imag() - y.imag()) == -1;\n    }\n}\n\
    constexpr inline bool operator>(point x, point y) noexcept {\n    if (sgn(x.real()\
    \ - y.real()) != 0) {\n        return sgn(x.real() - y.real()) == 1;\n    } else\
    \ {\n        return sgn(x.imag() - y.imag()) == 1;\n    }\n}\nconstexpr inline\
    \ bool operator<=(point x, point y) noexcept {\n    return x == y || x < y;\n\
    }\nconstexpr inline bool operator>=(point x, point y) noexcept {\n    return x\
    \ == y || x > y;\n}\n\nvoid sort_by_arg(vector<point>& points) {   // \u504F\u89D2\
    \u30BD\u30FC\u30C8(arg\u306F(-pi,pi])\n    auto where_area = [&](const point&\
    \ x) {\n        if (x.imag() < 0) {\n            return -1;\n        } else if\
    \ (x.imag() == 0 && x.real() >= 0) {\n            return 0;\n        } else {\n\
    \            return 1;\n        }\n    };\n\n    auto compare = [&](const point&\
    \ x, const point& y) {\n        if (where_area(x) != where_area(y)) {\n      \
    \      return where_area(x) < where_area(y);\n        } else {\n            //\
    \ \u53CD\u6642\u8A08\u56DE\u308A\u306B x -> y\u306B\u306A\u3063\u3066\u305F\u3089\
    \ det(x,y) > 0\n            return sgn(det(x, y)) > 0;\n        }\n    };\n\n\
    \    std::sort(points.begin(), points.end(), compare);\n}\n\n};  // namespace\
    \ geometry\n\n/**\n * @brief Geometry(\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8)\n */"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geom.hpp
  requiredBy: []
  timestamp: '2024-07-20 00:25:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geom.hpp
layout: document
redirect_from:
- /library/geometry/geom.hpp
- /library/geometry/geom.hpp.html
title: "Geometry(\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
---
