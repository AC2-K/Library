---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "static modint(\u9759\u7684modint)"
    links: []
  bundledCode: "#line 1 \"out.cpp\"\n#line 1 \"main.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n\n#line 2 \"math/static_modint.hpp\"\nnamespace modint\
    \ {\n\ttemplate<unsigned long long mod>\n\tclass static_modint {\n\tprivate:\n\
    \t\tusing mint = static_modint<mod>;\n\t\tusing i64 = __int64_t;\n\t\tusing u64\
    \ = __uint64_t;\n\t\tusing u128 = __uint128_t;\n\t\tusing i128 = __int128_t;\n\
    \n\t\ti128 v;\n\t\tvoid normalize(i128& v) {\n\t\t\tv %= mod;\n\t\t\tif (v < 0)\
    \ {\n\t\t\t\tv += mod;\n\t\t\t}\n\t\t}\n\tpublic:\n\t\tstatic_modint(const u64&\
    \ v_ = 0) :v(v_) { normalize(v); }\n\n\n\t\tu64 val() const {\n\t\t\treturn (u64)v;\n\
    \t\t}\n\t\tmint& operator+=(const mint& rhs) {\n\t\t\tv += rhs.val();\n\t\t\t\
    normalize(v);\n\t\t\treturn (*this);\n\t\t}\n\t\tmint& operator-=(const mint&\
    \ rhs) {\n\t\t\tv -= rhs.val();\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\
    \t}\n\t\tmint& operator*=(const mint& rhs) {\n\t\t\tv *= rhs.val();\n\t\t\tnormalize(v);\n\
    \t\t\treturn (*this);\n\t\t}\n\n\n\n\n\t\tmint operator+(const mint& r) const\
    \ {\n\t\t\treturn mint(*this) += r;\n\t\t}\n\t\tmint operator-(const mint& r)\
    \ const {\n\t\t\treturn mint(*this) -= r;\n\t\t}\n\t\tmint operator*(const mint&\
    \ r) const {\n\t\t\treturn mint(*this) *= r;\n\t\t}\n\n\t\tmint& operator+=(const\
    \ i64& rhs) {\n\t\t\tv += rhs;\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\
    \t}\n\t\tmint& operator-=(const i64& rhs) {\n\t\t\tv -= rhs;\n\t\t\tnormalize(v);\n\
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
    \t};\n}\nusing modint::static_modint;\n\n///@brief static modint(\u9759\u7684\
    modint)\n#line 6 \"main.cpp\"\n"
  code: "#line 1 \"main.cpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\n\n\
    #line 2 \"math/static_modint.hpp\"\nnamespace modint {\n\ttemplate<unsigned long\
    \ long mod>\n\tclass static_modint {\n\tprivate:\n\t\tusing mint = static_modint<mod>;\n\
    \t\tusing i64 = __int64_t;\n\t\tusing u64 = __uint64_t;\n\t\tusing u128 = __uint128_t;\n\
    \t\tusing i128 = __int128_t;\n\n\t\ti128 v;\n\t\tvoid normalize(i128& v) {\n\t\
    \t\tv %= mod;\n\t\t\tif (v < 0) {\n\t\t\t\tv += mod;\n\t\t\t}\n\t\t}\n\tpublic:\n\
    \t\tstatic_modint(const u64& v_ = 0) :v(v_) { normalize(v); }\n\n\n\t\tu64 val()\
    \ const {\n\t\t\treturn (u64)v;\n\t\t}\n\t\tmint& operator+=(const mint& rhs)\
    \ {\n\t\t\tv += rhs.val();\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\t}\n\
    \t\tmint& operator-=(const mint& rhs) {\n\t\t\tv -= rhs.val();\n\t\t\tnormalize(v);\n\
    \t\t\treturn (*this);\n\t\t}\n\t\tmint& operator*=(const mint& rhs) {\n\t\t\t\
    v *= rhs.val();\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\t}\n\n\n\n\n\t\
    \tmint operator+(const mint& r) const {\n\t\t\treturn mint(*this) += r;\n\t\t\
    }\n\t\tmint operator-(const mint& r) const {\n\t\t\treturn mint(*this) -= r;\n\
    \t\t}\n\t\tmint operator*(const mint& r) const {\n\t\t\treturn mint(*this) *=\
    \ r;\n\t\t}\n\n\t\tmint& operator+=(const i64& rhs) {\n\t\t\tv += rhs;\n\t\t\t\
    normalize(v);\n\t\t\treturn (*this);\n\t\t}\n\t\tmint& operator-=(const i64& rhs)\
    \ {\n\t\t\tv -= rhs;\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\t}\n\t\t\
    mint& operator*=(const i64& rhs) {\n\t\t\tv *= rhs;\n\t\t\tnormalize(v);\n\t\t\
    \treturn (*this);\n\t\t}\n\t\tfriend mint operator+(const i64& l, const mint&\
    \ r) {\n\t\t\treturn mint(l) += r;\n\t\t}\n\t\tfriend mint operator-(const i64&\
    \ l, const mint& r) {\n\t\t\treturn mint(l) -= r;\n\t\t}\n\t\tfriend mint operator*(const\
    \ i64& l, const mint& r) {\n\t\t\treturn mint(l) *= r;\n\t\t}\n\n\t\tmint operator+(const\
    \ i64& r) {\n\t\t\treturn mint(*this) += r;\n\t\t}\n\t\tmint operator-(const i64&\
    \ r) {\n\t\t\treturn mint(*this) -= r;\n\t\t}\n\t\tmint operator*(const i64& r)\
    \ {\n\t\t\treturn mint(*this) *= r;\n\t\t}\n\n\n\t\tmint& operator=(const i64&\
    \ r) {\n\t\t\treturn (*this) = mint(r);\n\t\t}\n\n\t\tbool operator==(const mint&\
    \ r) {\n\t\t\treturn (*this).val() == r.val();\n\t\t}\n\t\tmint pow(u128 e) const\
    \ {\n\t\t\tmint ans(1), base(*this);\n\t\t\twhile (e) {\n\t\t\t\tif (e & 1) {\n\
    \t\t\t\t\tans *= base;\n\t\t\t\t}\n\t\t\t\tbase *= base;\n\t\t\t\te >>= 1;\n\t\
    \t\t}\n\t\t\treturn ans;\n\t\t}\n\n\t\tmint inv() const {\n\t\t\treturn pow(mod\
    \ - 2);\n\t\t}\n\n\t\tmint& operator/=(const mint& r) {\n\t\t\treturn (*this)\
    \ *= r.inv();\n\t\t}\n\t\tfriend mint operator/(const mint& l, const i64& r) {\n\
    \t\t\treturn mint(l) /= mint(r);\n\t\t}\n\n\t\t//iostream\n\t\tfriend ostream&\
    \ operator<<(ostream& os, const mint& mt) {\n\t\t\tos << mt.val();\n\t\t\treturn\
    \ os;\n\t\t}\n\t\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\t\t\
    i64 vv;\n\t\t\tis >> vv;\n\t\t\tmt = vv;\n\t\t\treturn is;\n\t\t}\n\t};\n}\nusing\
    \ modint::static_modint;\n\n///@brief static modint(\u9759\u7684modint)\n#line\
    \ 6 \"main.cpp\"\n"
  dependsOn: []
  isVerificationFile: false
  path: out.cpp
  requiredBy: []
  timestamp: '2023-03-10 13:31:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: out.cpp
layout: document
redirect_from:
- /library/out.cpp
- /library/out.cpp.html
title: "static modint(\u9759\u7684modint)"
---
