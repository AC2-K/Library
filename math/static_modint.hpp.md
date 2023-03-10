---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/modint.hpp
    title: math/modint.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
    title: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "static modint(\u9759\u7684modint)"
    links: []
  bundledCode: "#line 2 \"math/static_modint.hpp\"\ntemplate<unsigned long long mod>\n\
    class static_modint {\nprivate:\n\tusing mint = static_modint<mod>;\n\tusing i64\
    \ = long long;\n\tusing u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\
    \tusing i128 = __int128_t;\n\n\tu64 v;\n\tu64 normalize(i128 v_) {\n\t\tv_ %=\
    \ mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\
    \tstatic_modint() :v(0) {}\n\tstatic_modint(const i64& v_) :v(normalize(v_)) {\
    \ }\n\n\t//operator\n\tu64 val() const {\n\t\treturn (u64)v;\n\t}\n\tmint& operator+=(const\
    \ mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t\
    }\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv += mod\
    \ - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tmint& operator*=(const mint& rhs) {\n\t\ti128 m = v * rhs.val();\n\t\t\
    v = normalize(m);\n\t\treturn (*this);\n\t}\n\n\n\tmint operator+(const mint&\
    \ r) const {\n\t\treturn mint(*this) += r;\n\t}\n\tmint operator-(const mint&\
    \ r) const {\n\t\treturn mint(*this) -= r;\n\t}\n\tmint operator*(const mint&\
    \ r) const {\n\t\treturn mint(*this) *= r;\n\t}\n\n\tmint& operator+=(const i64&\
    \ rhs) {\n\t\t(*this) += mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const\
    \ i64& rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
    \ i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\t}\n\tfriend mint\
    \ operator+(const i64& l, const mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\t\
    friend mint operator-(const i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\
    \t}\n\tfriend mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l)\
    \ *= r;\n\t}\n\n\tmint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tmint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tmint\
    \ operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tmint& operator=(const\
    \ i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tbool operator==(const mint&\
    \ r) {\n\t\treturn (*this).val() == r.val();\n\t}\n\tmint pow(u128 e) const {\n\
    \t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans\
    \ *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\
    \t}\n\n\tmint inv() const {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tfriend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\
    \tfriend ostream& operator<<(ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\
    \t\treturn os;\n\t}\n\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\
    \ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\n///@brief static\
    \ modint(\u9759\u7684modint)\n"
  code: "#pragma once\ntemplate<unsigned long long mod>\nclass static_modint {\nprivate:\n\
    \tusing mint = static_modint<mod>;\n\tusing i64 = long long;\n\tusing u64 = unsigned\
    \ long long;\n\tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\n\tu64\
    \ v;\n\tu64 normalize(i128 v_) {\n\t\tv_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\tv_\
    \ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tstatic_modint() :v(0) {}\n\t\
    static_modint(const i64& v_) :v(normalize(v_)) { }\n\n\t//operator\n\tu64 val()\
    \ const {\n\t\treturn (u64)v;\n\t}\n\tmint& operator+=(const mint& rhs) {\n\t\t\
    v += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv += mod - rhs.val();\n\t\tif\
    \ (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
    \ mint& rhs) {\n\t\ti128 m = v * rhs.val();\n\t\tv = normalize(m);\n\t\treturn\
    \ (*this);\n\t}\n\n\n\tmint operator+(const mint& r) const {\n\t\treturn mint(*this)\
    \ += r;\n\t}\n\tmint operator-(const mint& r) const {\n\t\treturn mint(*this)\
    \ -= r;\n\t}\n\tmint operator*(const mint& r) const {\n\t\treturn mint(*this)\
    \ *= r;\n\t}\n\n\tmint& operator+=(const i64& rhs) {\n\t\t(*this) += mint(rhs);\n\
    \t\treturn (*this);\n\t}\n\tmint& operator-=(const i64& rhs) {\n\t\t(*this) -=\
    \ mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const i64& rhs) {\n\
    \t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\t}\n\tfriend mint operator+(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\tfriend mint operator-(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\t}\n\tfriend mint operator*(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t}\n\n\tmint operator+(const\
    \ i64& r) {\n\t\treturn mint(*this) += r;\n\t}\n\tmint operator-(const i64& r)\
    \ {\n\t\treturn mint(*this) -= r;\n\t}\n\tmint operator*(const i64& r) {\n\t\t\
    return mint(*this) *= r;\n\t}\n\n\n\tmint& operator=(const i64& r) {\n\t\treturn\
    \ (*this) = mint(r);\n\t}\n\n\tbool operator==(const mint& r) {\n\t\treturn (*this).val()\
    \ == r.val();\n\t}\n\tmint pow(u128 e) const {\n\t\tmint ans(1), base(*this);\n\
    \t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase\
    \ *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tmint inv() const\
    \ {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const mint& r) {\n\t\t\
    return (*this) *= r.inv();\n\t}\n\tfriend mint operator/(const mint& l, const\
    \ i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\tfriend ostream&\
    \ operator<<(ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\
    \t}\n\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\ti64 v_;\n\t\t\
    is >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\n///@brief static modint(\u9759\
    \u7684modint)"
  dependsOn: []
  isVerificationFile: false
  path: math/static_modint.hpp
  requiredBy:
  - math/modint.hpp
  timestamp: '2023-03-10 15:19:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo judge/data structure/Point Set Range Composite.test.cpp
documentation_of: math/static_modint.hpp
layout: document
redirect_from:
- /library/math/static_modint.hpp
- /library/math/static_modint.hpp.html
title: "static modint(\u9759\u7684modint)"
---
