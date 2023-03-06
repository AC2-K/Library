---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 1 \"math/dynamic_modint.hpp\"\nnamespace modint {\n\tclass dynamic_modint\
    \ {\n\t\tusing mint = dynamic_modint;\n\t\tusing i64 = int64_t;\n\t\tusing u64\
    \ = uint64_t;\n\t\tusing u128 = __uint128_t;\n\n\t\tstatic u64 mod;\n\t\tstatic\
    \ u64 r;\n\t\tstatic u64 n2;\n\n\t\tstatic u64 get_r() {\n\t\t\tu64 ret = mod;\n\
    \t\t\tfor (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;\n\t\t\treturn ret;\n\t\
    \t}\n\tpublic:\n\t\tstatic void set_mod(u64 m) {\n\t\t\tassert(m < ((u128)1 <<\
    \ 64));\n\t\t\tassert((m & 1) == 1);\n\t\t\tmod = m;\n\t\t\tn2 = -u128(m) % m;\n\
    \t\t\tr = get_r();\n\t\t\tassert(r * mod == 1);\n\t\t}\n\tprotected:\n\t\tu64\
    \ a;\n\tpublic:\n\t\tdynamic_modint() : a(0) {}\n\t\tdynamic_modint(const int64_t&\
    \ b) : a(reduce((u128(b) + mod)* n2)) {};\n\tprivate:\n\t\tstatic u64 reduce(const\
    \ u128& b) {\n\t\t\treturn (b + u128(u64(b) * u64(-r)) * mod) >> 64;\n\t\t}\n\t\
    public:\n\t\tmint& operator+=(const mint& b) {\n\t\t\tif (i64(a += b.a - 2 * mod)\
    \ < 0) a += 2 * mod;\n\t\t\treturn *this;\n\t\t}\n\n\t\tmint& operator-=(const\
    \ mint& b) {\n\t\t\tif (i64(a -= b.a) < 0) a += 2 * mod;\n\t\t\treturn *this;\n\
    \t\t}\n\n\t\tmint& operator*=(const mint& b) {\n\t\t\ta = reduce(u128(a) * b.a);\n\
    \t\t\treturn *this;\n\t\t}\n\n\t\tmint& operator/=(const mint& b) {\n\t\t\t*this\
    \ *= b.inv();\n\t\t\treturn *this;\n\t\t}\n\n\t\tmint operator+(const mint& b)\
    \ const { return mint(*this) += b; }\n\t\tmint operator-(const mint& b) const\
    \ { return mint(*this) -= b; }\n\t\tmint operator*(const mint& b) const { return\
    \ mint(*this) *= b; }\n\t\tmint operator/(const mint& b) const { return mint(*this)\
    \ /= b; }\n\t\tbool operator==(const mint& b) const {\n\t\t\treturn (a >= mod\
    \ ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n\t\t}\n\t\tbool operator!=(const\
    \ mint& b) const {\n\t\t\treturn (a >= mod ? a - mod : a) != (b.a >= mod ? b.a\
    \ - mod : b.a);\n\t\t}\n\t\tmint operator-() const { return mint() - mint(*this);\
    \ }\n\n\t\tmint pow(u128 n) const {\n\t\t\tmint ret(1), mul(*this);\n\t\t\twhile\
    \ (n > 0) {\n\t\t\t\tif (n & 1) ret *= mul;\n\t\t\t\tmul *= mul;\n\t\t\t\tn >>=\
    \ 1;\n\t\t\t}\n\t\t\treturn ret;\n\t\t}\n\n\t\tfriend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n\t\t\treturn os << b.val();\n\t\t}\n\n\t\tfriend istream&\
    \ operator>>(istream& is, mint& b) {\n\t\t\tint64_t t;\n\t\t\tis >> t;\n\t\t\t\
    b = dynamic_modint(t);\n\t\t\treturn (is);\n\t\t}\n\n\t\tmint inv() const { return\
    \ pow(mod - 2); }\n\n\t\tu64 val() const {\n\t\t\tu64 ret = reduce(a);\n\t\t\t\
    return ret >= mod ? ret - mod : ret;\n\t\t}\n\n\t\tstatic u64 get_mod() { \n\t\
    \t\treturn mod;\n\t\t}\n\n\n\t\tfriend mint operator+(const mint& lhs, const mint&\
    \ rhs) {\n\t\t\treturn mint(lhs) += rhs;\n\t\t}\n\t\tfriend mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n\t\t\treturn mint(lhs) -= rhs;\n\t\t}\n\t\tfriend\
    \ mint operator*(const mint& lhs, const mint& rhs) {\n\t\t\treturn mint(lhs) *=\
    \ rhs;\n\t\t}\n\t\tfriend mint operator/(const mint& lhs, const mint& rhs) {\n\
    \t\t\treturn mint(lhs) /= rhs;\n\t\t}\n\n\n\n\t\tfriend mint operator+(const mint&\
    \ lhs, const u64& rhs) {\n\t\t\treturn mint(lhs) += rhs;\n\t\t}\n\t\tfriend mint\
    \ operator+(const u64& lhs, const mint& rhs) {\n\t\t\treturn mint(lhs) += rhs;\n\
    \t\t}\n\n\t\tfriend mint operator-(const mint& lhs, const u64& rhs) {\n\t\t\t\
    return mint(lhs) -= rhs;\n\t\t}\n\t\tfriend mint operator-(const u64& lhs, const\
    \ mint& rhs) {\n\t\t\treturn mint(lhs) += rhs;\n\t\t}\n\n\t\tfriend mint operator*(const\
    \ mint& lhs, const u64& rhs) {\n\t\t\treturn mint(lhs) *= rhs;\n\t\t}\n\t\tfriend\
    \ mint operator*(const u64& lhs, const mint& rhs) {\n\t\t\treturn mint(lhs) +=\
    \ rhs;\n\t\t}\n\n\t\tfriend mint operator/(const u64& lhs, const mint& rhs) {\n\
    \t\t\treturn mint(lhs) /= rhs;\n\t\t}\n\t\tfriend mint operator/(const mint& lhs,\
    \ const u64& rhs) {\n\t\t\treturn mint(lhs) /= mint(rhs);\n\t\t}\n\n\t};\n\ttypename\
    \ dynamic_modint::u64 dynamic_modint::mod, dynamic_modint::r, dynamic_modint::n2;\n\
    };\n///@brief dynamic modint(\u52D5\u7684modint)\n#line 2 \"math/static_modint.hpp\"\
    \nnamespace modint {\n\ttemplate<unsigned long long mod>\n\tclass static_modint\
    \ {\n\tprivate:\n\t\tusing mint = static_modint<mod>;\n\t\tusing i64 = __int64_t;\n\
    \t\tusing u64 = __uint64_t;\n\t\tusing u128 = __uint128_t;\n\t\tusing i128 = __int128_t;\n\
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
    \t\t}\n\t\tmint pow(u128 e) {\n\t\t\tmint ans(1), base(*this);\n\t\t\twhile (e)\
    \ {\n\t\t\t\tif (e & 1) {\n\t\t\t\t\tans *= base;\n\t\t\t\t}\n\t\t\t\tbase *=\
    \ base;\n\t\t\t\te >>= 1;\n\t\t\t}\n\t\t\treturn ans;\n\t\t}\n\n\t\tmint inv()\
    \ {\n\t\t\treturn pow(mod - 2);\n\t\t}\n\n\t\tmint& operator/=(const mint& r)\
    \ {\n\t\t\treturn (*this) *= r.inv();\n\t\t}\n\t\tfriend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\t\treturn mint(l) /= mint(r);\n\t\t}\n\n\t\t//iostream\n\
    \t\tfriend ostream& operator<<(ostream& os, const mint& mt) {\n\t\t\tos << mt.val();\n\
    \t\t\treturn os;\n\t\t}\n\t\tfriend istream& operator>>(istream& is, mint& mt)\
    \ {\n\t\t\ti64 vv;\n\t\t\tis >> vv;\n\t\t\tmt = vv;\n\t\t\treturn is;\n\t\t}\n\
    \t};\n}\nusing modint::static_modint;\n\n///@brief static modint(\u9759\u7684\
    modint)\n#line 4 \"math/modint.hpp\"\n"
  code: '#pragma once

    #include "math/dynamic_modint.hpp"

    #include "math/static_modint.hpp"'
  dependsOn:
  - math/dynamic_modint.hpp
  - math/static_modint.hpp
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2023-03-06 14:05:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
