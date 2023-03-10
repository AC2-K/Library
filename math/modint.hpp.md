---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/barrett.hpp
    title: math/barrett.hpp
  - icon: ':warning:'
    path: math/dynamic_modint.hpp
    title: "dynamic modint(\u52D5\u7684modint)"
  - icon: ':heavy_check_mark:'
    path: math/static_modint.hpp
    title: "static modint(\u9759\u7684modint)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/barrett.hpp\"\nnamespace internal {\n\t//burret reduction\n\
    \tclass barrett {\n\t\tusing u32 = uint32_t;\n\t\tusing u64 = uint64_t;\n\n\t\t\
    u32 m;\n\t\tu64 im;\n\tpublic:\n\t\texplicit barrett() = default;\n\t\texplicit\
    \ barrett(const u32& m_) :m(m_), im((u64)(-1) / m_ + 1) {}\n\n\t\tu32 get_mod()\
    \ const { return m; }\n\t\tu32 mul(u32 a, u32 b) {\n\t\t\tif (a == 0 || b == 0)\
    \ {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tu64 z = a;\n\t\t\tz *= b;\n#ifdef _MSC_VER\n\
    \t\t\tu64 x;\n\n\t\t\t_umul128(z, im, &x);\n#else\n\t\t\tu64 x = (u64)(((__uint128_t)(z)*im)\
    \ >> 64);\n#endif\n\n\t\t\tu32 v = (u32)(z - x * m);\n\n\t\t\tif (v >= m)v +=\
    \ m;\n\t\t\treturn v;\n\t\t}\n\t};\n}\n#line 3 \"math/dynamic_modint.hpp\"\nclass\
    \ dynamic_modint32 {\n\tusing u32 = uint32_t;\n\tusing u64 = uint64_t;\n\n\tusing\
    \ i32 = int32_t;\n\tusing i64 = int64_t;\n\tusing br = internal::barrett;\n\n\t\
    static br brt;\n\tstatic u32 mod;\n\tu32 v;\t//value\npublic:\n\tstatic void set_mod(const\
    \ u32& mod_) {\n\t\tbrt = br(mod_);\t//change burrett\n\t\tmod = mod_;\n\t}\n\
    private:\n\tu32 normalize(const i64& x) const {\n\t\tu32 m = x % mod;\n\t\tif\
    \ (m < 0) {\n\t\t\tm += mod;\n\t\t}\n\t\treturn m;\n\t}\npublic:\n\tdynamic_modint32()\
    \ :v(0) { assert(mod); }\n\tdynamic_modint32(const i64& v_) :v(normalize(v_))\
    \ { assert(mod); }\n\n\tu32 val() const { return v; }\n\n\tusing mint = dynamic_modint32;\n\
    \n\t//operators\n\tmint& operator=(const i64& r) {\n\t\tv = normalize(r); \n\t\
    \treturn (*this);\n\t}\n\tmint& operator+=(const mint& r) {\n\t\tv += r.v;\n\t\
    \tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const\
    \ mint&r) {\n\t\tv += mod - r.v;\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\
    \n\t\treturn (*this);\n\t}\n\tmint& operator*=(const mint& r) {\n\t\tv = brt.mul(v,\
    \ r.v);\n\t\treturn (*this);\n\t}\n\n\tmint operator+(const mint& r) const { return\
    \ mint(*this) += r; }\n\tmint operator-(const mint& r) const { return mint(*this)\
    \ -= r; }\n\tmint operator*(const mint& r) const { return mint(*this) *= r; }\n\
    \n\n\n\tmint& operator+= (const i64& r) { return (*this) += mint(r); }\n\tmint&\
    \ operator-= (const i64& r) { return (*this) -= mint(r); }\n\tmint& operator*=\
    \ (const i64& r) { return (*this) *= mint(r); }\n\n\tfriend mint operator+(const\
    \ i64& l, const mint& r) { return mint(l) += r; }\n\tfriend mint operator+(const\
    \ mint& l, const i64& r) { return mint(l) += r; }\n\tfriend mint operator-(const\
    \ i64& l, const mint& r) { return mint(l) -= r; }\n\tfriend mint operator-(const\
    \ mint& l, const i64& r) { return mint(l) -= r; }\n\tfriend mint operator*(const\
    \ i64& l, const mint& r) { return mint(l) *= r; }\n\tfriend mint operator*(const\
    \ mint& l, const i64& r) { return mint(l) += r; }\n\n\n\tfriend ostream& operator<<(ostream&\
    \ os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\
    \t\treturn is;\n\t}\n\tmint pow(u64 e) const {\n\t\tmint res(1), base(*this);\n\
    \n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tres *= base;\n\t\t\t}\n\t\t\te\
    \ >>= 1;\n\t\t\tbase *= base;\n\t\t}\n\t\treturn base;\n\t}\n\tmint inv() const\
    \ {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const mint& r) { return\
    \ (*this) *= r.inv(); }\n\tmint operator/(const mint& r) const { return mint(*this)\
    \ *= r.inv(); }\n\tmint& operator/=(const i64& r) { return (*this) /= mint(r);\
    \ }\n\tfriend mint operator/(const mint& l, const i64& r) { return mint(l) /=\
    \ r; }\n\tfriend mint operator/(const i64& l, const mint& r) { return mint(l)\
    \ /= r; }\n};\ntypename dynamic_modint32::u32 dynamic_modint32::mod;\ntypename\
    \ dynamic_modint32::br dynamic_modint32::brt;\n\n///@brief dynamic modint(\u52D5\
    \u7684modint)\n///@docs docs/math/dynamic_modint.md\n#line 2 \"math/static_modint.hpp\"\
    \n\ntemplate<unsigned long long mod>\nclass static_modint {\nprivate:\n\tusing\
    \ mint = static_modint<mod>;\n\tusing i64 = __int64_t;\n\tusing u64 = __uint64_t;\n\
    \tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\n\ti128 v;\n\tvoid normalize(i128&\
    \ v) {\n\t\tv %= mod;\n\t\tif (v < 0) {\n\t\t\tv += mod;\n\t\t}\n\t}\n\tpublic:\n\
    \t\tstatic_modint(const u64& v_ = 0) :v(v_) { normalize(v); }\n\n\t\t//operator\n\
    \t\tu64 val() const {\n\t\t\treturn (u64)v;\n\t\t}\n\t\tmint& operator+=(const\
    \ mint& rhs) {\n\t\t\tv += rhs.val();\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\
    \t\t}\n\t\tmint& operator-=(const mint& rhs) {\n\t\t\tv -= rhs.val();\n\t\t\t\
    normalize(v);\n\t\t\treturn (*this);\n\t\t}\n\t\tmint& operator*=(const mint&\
    \ rhs) {\n\t\t\tv *= rhs.val();\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\
    \t}\n\n\n\t\tmint operator+(const mint& r) const {\n\t\t\treturn mint(*this) +=\
    \ r;\n\t\t}\n\t\tmint operator-(const mint& r) const {\n\t\t\treturn mint(*this)\
    \ -= r;\n\t\t}\n\t\tmint operator*(const mint& r) const {\n\t\t\treturn mint(*this)\
    \ *= r;\n\t\t}\n\n\t\tmint& operator+=(const i64& rhs) {\n\t\t\tv += rhs;\n\t\t\
    \tnormalize(v);\n\t\t\treturn (*this);\n\t\t}\n\t\tmint& operator-=(const i64&\
    \ rhs) {\n\t\t\tv -= rhs;\n\t\t\tnormalize(v);\n\t\t\treturn (*this);\n\t\t}\n\
    \t\tmint& operator*=(const i64& rhs) {\n\t\t\tv *= rhs;\n\t\t\tnormalize(v);\n\
    \t\t\treturn (*this);\n\t\t}\n\t\tfriend mint operator+(const i64& l, const mint&\
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
    i64 vv;\n\t\t\tis >> vv;\n\t\t\tmt = vv;\n\t\t\treturn is;\n\t\t}\n\t};\n///@brief\
    \ static modint(\u9759\u7684modint)\n#line 4 \"math/modint.hpp\"\n"
  code: '#pragma once

    #include "math/dynamic_modint.hpp"

    #include "math/static_modint.hpp"'
  dependsOn:
  - math/dynamic_modint.hpp
  - math/barrett.hpp
  - math/static_modint.hpp
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2023-03-10 13:31:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
