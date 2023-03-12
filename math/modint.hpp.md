---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/barrett.hpp
    title: math/barrett.hpp
  - icon: ':x:'
    path: math/dynamic_modint.hpp
    title: "dynamic modint(\u52D5\u7684modint)"
  - icon: ':x:'
    path: math/static_modint.hpp
    title: "static modint(\u9759\u7684modint)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/barrett.hpp\"\nnamespace internal {\n\t//barret reduction\n\
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
    \ u32& mod_) {\n\t\tbrt = br(mod_);\n\t\tmod = mod_;\n\t}\nprivate:\n\tu32 normalize(const\
    \ i64& x) const {\n\t\ti32 m = x % mod;\n\t\tif (m < 0) {\n\t\t\tm += mod;\n\t\
    \t}\n\t\treturn m;\n\t}\npublic:\n\tdynamic_modint32() :v(0) { assert(mod); }\t\
    //mod\u304C\u6C7A\u5B9A\u6E08\u307F\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \n\tdynamic_modint32(const i64& v_) :v(normalize(v_)) { assert(mod); }\t\n\n\t\
    u32 val() const { return v; }\n\n\tusing mint = dynamic_modint32;\n\n\t//operators\n\
    \tmint& operator=(const i64& r) {\n\t\tv = normalize(r); \n\t\treturn (*this);\n\
    \t}\n\tmint& operator+=(const mint& r) {\n\t\tv += r.v;\n\t\tif (v >= mod) {\n\
    \t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const mint&r)\
    \ {\n\t\tv += mod - r.v;\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\n\t\t\
    return (*this);\n\t}\n\tmint& operator*=(const mint& r) {\n\t\tv = brt.mul(v,\
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
    \n<<<<<<< HEAD\ntemplate<__uint64_t mod>\n=======\ntemplate<unsigned long long\
    \ mod>\n>>>>>>> 9d32c20b7e4b89933c546ca0e0d26c3be9cd1eda\nclass static_modint\
    \ {\nprivate:\n\tusing mint = static_modint<mod>;\n\tusing i64 = long long;\n\t\
    using u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\
    \n\tu64 v;\n<<<<<<< HEAD\n\tu64 normalize(i128 v_) const {\n=======\n\tu64 normalize(i128\
    \ v_) {\n>>>>>>> 9d32c20b7e4b89933c546ca0e0d26c3be9cd1eda\n\t\tv_ %= mod;\n\t\t\
    if (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tstatic_modint()\
    \ :v(0) {}\n\tstatic_modint(const i64& v_) :v(normalize(v_)) { }\n\n\t//operator\n\
    \tu64 val() const {\n\t\treturn (u64)v;\n\t}\n\tmint& operator+=(const mint& rhs)\
    \ {\n\t\tv += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn\
    \ (*this);\n\t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv += mod - rhs.val();\n\
    \t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tmint&\
    \ operator*=(const mint& rhs) {\n\t\ti128 m = v * rhs.val();\n\t\tv = normalize(m);\n\
    \t\treturn (*this);\n\t}\n\n\n\tmint operator+(const mint& r) const {\n\t\treturn\
    \ mint(*this) += r;\n\t}\n\tmint operator-(const mint& r) const {\n\t\treturn\
    \ mint(*this) -= r;\n\t}\n\tmint operator*(const mint& r) const {\n\t\treturn\
    \ mint(*this) *= r;\n\t}\n\n\tmint& operator+=(const i64& rhs) {\n\t\t(*this)\
    \ += mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const i64& rhs)\
    \ {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
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
    \ modint(\u9759\u7684modint)\n#line 4 \"math/modint.hpp\"\n"
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
  timestamp: '2023-03-12 14:56:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
