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
  bundledCode: "#line 2 \"math/static_modint.hpp\"\n\ntemplate<unsigned long long\
    \ mod>\nclass static_modint {\nprivate:\n\tusing mint = static_modint<mod>;\n\t\
    using i64 = __int64_t;\n\tusing u64 = __uint64_t;\n\tusing u128 = __uint128_t;\n\
    \tusing i128 = __int128_t;\n\n\ti128 v;\n\tvoid normalize(i128& v) {\n\t\tv %=\
    \ mod;\n\t\tif (v < 0) {\n\t\t\tv += mod;\n\t\t}\n\t}\n\tpublic:\n\t\tstatic_modint(const\
    \ u64& v_ = 0) :v(v_) { normalize(v); }\n\n\t\t//operator\n\t\tu64 val() const\
    \ {\n\t\t\treturn (u64)v;\n\t\t}\n\t\tmint& operator+=(const mint& rhs) {\n\t\t\
    \tv += rhs.val();\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\t}\n\t\tmint&\
    \ operator-=(const mint& rhs) {\n\t\t\tv -= rhs.val();\n\t\t\tnormalize(v);\n\t\
    \t\treturn (*this);\n\t\t}\n\t\tmint& operator*=(const mint& rhs) {\n\t\t\tv *=\
    \ rhs.val();\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\t}\n\n\n\t\tmint\
    \ operator+(const mint& r) const {\n\t\t\treturn mint(*this) += r;\n\t\t}\n\t\t\
    mint operator-(const mint& r) const {\n\t\t\treturn mint(*this) -= r;\n\t\t}\n\
    \t\tmint operator*(const mint& r) const {\n\t\t\treturn mint(*this) *= r;\n\t\t\
    }\n\n\t\tmint& operator+=(const i64& rhs) {\n\t\t\tv += rhs;\n\t\t\tnormalize(v);\n\
    \t\t\treturn (*this);\n\t\t}\n\t\tmint& operator-=(const i64& rhs) {\n\t\t\tv\
    \ -= rhs;\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\t}\n\t\tmint& operator*=(const\
    \ i64& rhs) {\n\t\t\tv *= rhs;\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\
    \t}\n\t\tfriend mint operator+(const i64& l, const mint& r) {\n\t\t\treturn mint(l)\
    \ += r;\n\t\t}\n\t\tfriend mint operator-(const i64& l, const mint& r) {\n\t\t\
    \treturn mint(l) -= r;\n\t\t}\n\t\tfriend mint operator*(const i64& l, const mint&\
    \ r) {\n\t\t\treturn mint(l) *= r;\n\t\t}\n\n\t\tmint operator+(const i64& r)\
    \ {\n\t\t\treturn mint(*this) += r;\n\t\t}\n\t\tmint operator-(const i64& r) {\n\
    \t\t\treturn mint(*this) -= r;\n\t\t}\n\t\tmint operator*(const i64& r) {\n\t\t\
    \treturn mint(*this) *= r;\n\t\t}\n\n\n\t\tmint& operator=(const i64& r) {\n\t\
    \t\treturn (*this) = mint(r);\n\t\t}\n\n\t\tbool operator==(const mint& r) {\n\
    \t\t\treturn (*this).val() == r.val();\n\t\t}\n\t\tmint pow(u128 e) const {\n\t\
    \t\tmint ans(1), base(*this);\n\t\t\twhile (e) {\n\t\t\t\tif (e & 1) {\n\t\t\t\
    \t\tans *= base;\n\t\t\t\t}\n\t\t\t\tbase *= base;\n\t\t\t\te >>= 1;\n\t\t\t}\n\
    \t\t\treturn ans;\n\t\t}\n\n\t\tmint inv() const {\n\t\t\treturn pow(mod - 2);\n\
    \t\t}\n\n\t\tmint& operator/=(const mint& r) {\n\t\t\treturn (*this) *= r.inv();\n\
    \t\t}\n\t\tfriend mint operator/(const mint& l, const i64& r) {\n\t\t\treturn\
    \ mint(l) /= mint(r);\n\t\t}\n\n\t\t//iostream\n\t\tfriend ostream& operator<<(ostream&\
    \ os, const mint& mt) {\n\t\t\tos << mt.val();\n\t\t\treturn os;\n\t\t}\n\t\t\
    friend istream& operator>>(istream& is, mint& mt) {\n\t\t\ti64 vv;\n\t\t\tis >>\
    \ vv;\n\t\t\tmt = vv;\n\t\t\treturn is;\n\t\t}\n\t};\n///@brief static modint(\u9759\
    \u7684modint)\n"
  code: "#pragma once\n\ntemplate<unsigned long long mod>\nclass static_modint {\n\
    private:\n\tusing mint = static_modint<mod>;\n\tusing i64 = __int64_t;\n\tusing\
    \ u64 = __uint64_t;\n\tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\
    \n\ti128 v;\n\tvoid normalize(i128& v) {\n\t\tv %= mod;\n\t\tif (v < 0) {\n\t\t\
    \tv += mod;\n\t\t}\n\t}\n\tpublic:\n\t\tstatic_modint(const u64& v_ = 0) :v(v_)\
    \ { normalize(v); }\n\n\t\t//operator\n\t\tu64 val() const {\n\t\t\treturn (u64)v;\n\
    \t\t}\n\t\tmint& operator+=(const mint& rhs) {\n\t\t\tv += rhs.val();\n\t\t\t\
    normalize(v);\n\t\t\treturn (*this);\n\t\t}\n\t\tmint& operator-=(const mint&\
    \ rhs) {\n\t\t\tv -= rhs.val();\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\
    \t}\n\t\tmint& operator*=(const mint& rhs) {\n\t\t\tv *= rhs.val();\n\t\t\tnormalize(v);\n\
    \t\t\treturn (*this);\n\t\t}\n\n\n\t\tmint operator+(const mint& r) const {\n\t\
    \t\treturn mint(*this) += r;\n\t\t}\n\t\tmint operator-(const mint& r) const {\n\
    \t\t\treturn mint(*this) -= r;\n\t\t}\n\t\tmint operator*(const mint& r) const\
    \ {\n\t\t\treturn mint(*this) *= r;\n\t\t}\n\n\t\tmint& operator+=(const i64&\
    \ rhs) {\n\t\t\tv += rhs;\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\t}\n\
    \t\tmint& operator-=(const i64& rhs) {\n\t\t\tv -= rhs;\n\t\t\tnormalize(v);\n\
    \t\t\treturn (*this);\n\t\t}\n\t\tmint& operator*=(const i64& rhs) {\n\t\t\tv\
    \ *= rhs;\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\t}\n\t\tfriend mint\
    \ operator+(const i64& l, const mint& r) {\n\t\t\treturn mint(l) += r;\n\t\t}\n\
    \t\tfriend mint operator-(const i64& l, const mint& r) {\n\t\t\treturn mint(l)\
    \ -= r;\n\t\t}\n\t\tfriend mint operator*(const i64& l, const mint& r) {\n\t\t\
    \treturn mint(l) *= r;\n\t\t}\n\n\t\tmint operator+(const i64& r) {\n\t\t\treturn\
    \ mint(*this) += r;\n\t\t}\n\t\tmint operator-(const i64& r) {\n\t\t\treturn mint(*this)\
    \ -= r;\n\t\t}\n\t\tmint operator*(const i64& r) {\n\t\t\treturn mint(*this) *=\
    \ r;\n\t\t}\n\n\n\t\tmint& operator=(const i64& r) {\n\t\t\treturn (*this) = mint(r);\n\
    \t\t}\n\n\t\tbool operator==(const mint& r) {\n\t\t\treturn (*this).val() == r.val();\n\
    \t\t}\n\t\tmint pow(u128 e) const {\n\t\t\tmint ans(1), base(*this);\n\t\t\twhile\
    \ (e) {\n\t\t\t\tif (e & 1) {\n\t\t\t\t\tans *= base;\n\t\t\t\t}\n\t\t\t\tbase\
    \ *= base;\n\t\t\t\te >>= 1;\n\t\t\t}\n\t\t\treturn ans;\n\t\t}\n\n\t\tmint inv()\
    \ const {\n\t\t\treturn pow(mod - 2);\n\t\t}\n\n\t\tmint& operator/=(const mint&\
    \ r) {\n\t\t\treturn (*this) *= r.inv();\n\t\t}\n\t\tfriend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\t\treturn mint(l) /= mint(r);\n\t\t}\n\n\t\t//iostream\n\
    \t\tfriend ostream& operator<<(ostream& os, const mint& mt) {\n\t\t\tos << mt.val();\n\
    \t\t\treturn os;\n\t\t}\n\t\tfriend istream& operator>>(istream& is, mint& mt)\
    \ {\n\t\t\ti64 vv;\n\t\t\tis >> vv;\n\t\t\tmt = vv;\n\t\t\treturn is;\n\t\t}\n\
    \t};\n///@brief static modint(\u9759\u7684modint)"
  dependsOn: []
  isVerificationFile: false
  path: math/static_modint.hpp
  requiredBy:
  - math/modint.hpp
  timestamp: '2023-03-10 13:31:13+09:00'
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
