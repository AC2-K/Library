---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/gcd.hpp
    title: math/gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/matrix/Matrix Product.test.cpp
    title: test/yosupo_judge/matrix/Matrix Product.test.cpp
  - icon: ':x:'
    path: test/yuki/No.891.test.cpp
    title: test/yuki/No.891.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/math/static_modint.md
    document_title: "static modint(\u9759\u7684modint)"
    links: []
  bundledCode: "#line 2 \"math/static_modint.hpp\"\n#include<iostream>\n#line 1 \"\
    math/gcd.hpp\"\n#include <tuple>\nnamespace library {\ntemplate <typename T> constexpr\
    \ inline T _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n    if (a == 0 ||\
    \ b == 0) return a + b;\n    int d = std::min(__builtin_ctzll(a), __builtin_ctzll(b));\n\
    \    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n\
    \        if (a == 0 || b == 0) {\n            return a + b;\n        }\n     \
    \   if (a > b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        }else{\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate<typename T>\nconstexpr inline\
    \ T ext_gcd(T a, T b, T &x, T &y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while(b) {\n        T q = a / b;\n        std::tie(a, b) = std::make_pair(b,\
    \ a % b);\n        std::tie(x, nx) = std::make_pair(nx, x - nx * q);\n       \
    \ std::tie(y, ny) = std::make_pair(ny, y - ny * q);\n    }\n    return a;\n}\n\
    \n};  // namespace library\n#line 4 \"math/static_modint.hpp\"\n\nnamespace library{\n\
    \    \n///@brief static modint(\u9759\u7684modint)\ntemplate<__uint64_t mod>\n\
    class static_modint {\nprivate:\n\tusing mint = static_modint<mod>;\n\tusing i64\
    \ = long long;\n\tusing u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\
    \tusing i128 = __int128_t;\n\n\tu64 v;\n\tu64 normalize(i64 v_) const {\n\t\t\
    v_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\n\
    public:\n\tconstexpr static_modint() :v(0) {}\n\tconstexpr static_modint(const\
    \ i64& v_) :v(normalize(v_)) { }\n\n\t//operator\n\tconstexpr u64 val() const\
    \ {\n\t\treturn v;\n\t}\n\tconstexpr mint& operator+=(const mint& rhs) {\n\t\t\
    v += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator-=(const mint& rhs) {\n\t\tv += mod - rhs.val();\n\
    \t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator*=(const mint& rhs) {\n\t\tv = (u128)v * rhs.val() % mod;\n\t\t\
    return (*this);\n\t}\n\n\n\tconstexpr mint operator+(const mint& r) const {\n\t\
    \treturn mint(*this) += r;\n\t}\n\tconstexpr mint operator-(const mint& r) const\
    \ {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint operator*(const mint&\
    \ r) const {\n\t\treturn mint(*this) *= r;\n\t}\n\n\tconstexpr mint& operator+=(const\
    \ i64& rhs) {\n\t\t(*this) += mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator-=(const i64& rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\
    \t\treturn (*this);\n\t}\n\tconstexpr friend mint operator+(const i64& l, const\
    \ mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\t}\n\tconstexpr friend\
    \ mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t\
    }\n\n\tconstexpr mint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tconstexpr mint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\
    \t}\n\n\n\tconstexpr mint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\
    \t}\n\n\tconstexpr bool operator==(const mint& r) const {\n\t\treturn (*this).val()\
    \ == r.val();\n\t}\n\tconstexpr mint pow(u128 e) const {\n\t\tmint ans(1), base(*this);\n\
    \t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase\
    \ *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv()\
    \ const {\n\t\tll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n   \
    \     assert(d == 1);\n        return mint(y);\n\t}\n\n\tconstexpr mint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tconstexpr mint inv(const\
    \ mint&r)const{\n\t\treturn mint(*this) *= r.inv();\n\t}\n\tconstexpr friend mint\
    \ operator/(const mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t\
    }\n\tconstexpr friend mint operator/(const i64& l, const mint& r) {\n\t\treturn\
    \ mint(l) /= mint(r);\n\t}\n\n\t//istd::ostream\n\tconstexpr friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn\
    \ os;\n\t}\n\tconstexpr friend std::istream& operator>>(std::istream& is, mint&\
    \ mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\n\n\
    \n///@brief static modint(32bit ver)\ntemplate<__uint32_t mod>\nclass static_modint32\
    \ {\nprivate:\n\tusing mint = static_modint32<mod>;\n\tusing i32 = __int32_t;\n\
    \tusing u32 = __uint32_t;\n\tusing i64 = __int64_t;\n\tusing u64 = __uint64_t;\n\
    \n\tu32 v;\n\tinline u32 normalize(i64 v_) const {\n\t\tv_ %= mod;\n\t\tif (v_\
    \ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tconstexpr static_modint32()\
    \ :v(0) {}\n\tconstexpr static_modint32(const i64& v_) :v(normalize(v_)) { }\n\
    \n\t//operator\n\tconstexpr u64 val() const {\n\t\treturn (u64)v;\n\t}\n\tconstexpr\
    \ mint& operator+=(const mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod)\
    \ {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const\
    \ mint& rhs) {\n\t\tv += mod - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\
    \t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator*=(const mint& rhs)\
    \ {\n\t\tv = (u64)v * rhs.val() % mod;\n\t\treturn (*this);\n\t}\n\n\tconstexpr\
    \ mint operator+(const mint& r) const {\n\t\treturn mint(*this) += r;\n\t}\n\t\
    constexpr mint operator-(const mint& r) const {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const mint& r) const {\n\t\treturn mint(*this)\
    \ *= r;\n\t}\n\n\tconstexpr mint& operator+=(const i64& rhs) {\n\t\t(*this) +=\
    \ mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const i64&\
    \ rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint&\
    \ operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr friend mint operator+(const i64& l, const mint& r) {\n\t\treturn\
    \ mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) -= r;\n\t}\n\tconstexpr friend mint operator*(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t}\n\n\tconstexpr mint\
    \ operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\t}\n\tconstexpr mint\
    \ operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint\
    \ operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tconstexpr\
    \ mint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tconstexpr\
    \ bool operator==(const mint& r) const {\n\t\treturn (*this).val() == r.val();\n\
    \t}\n\tconstexpr mint pow(u64 e) const {\n\t\tmint ans(1), base(*this);\n\t\t\
    while (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase *=\
    \ base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv()\
    \ const {\n        ll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n\
    \        assert(d == 1);\n        return mint(y);\n    }\n\n\tconstexpr mint&\
    \ operator/=(const mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n    constexpr\
    \ mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }\n   \
    \ constexpr friend mint operator/(const mint& l, const i64& r) {\n\t\treturn mint(l)\
    \ /= mint(r);\n\t}\n\tconstexpr friend mint operator/(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\n\t//istd::ostream\n\tconstexpr\
    \ friend std::ostream& operator<<(std::ostream& os, const mint& mt) {\n\t\tos\
    \ << mt.val();\n\t\treturn os;\n\t}\n\tconstexpr friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t\
    }\n\n};\n\n};  // namespace library\n\n///@docs docs/math/static_modint.md\n"
  code: "#pragma once\n#include<iostream>\n#include\"math/gcd.hpp\"\n\nnamespace library{\n\
    \    \n///@brief static modint(\u9759\u7684modint)\ntemplate<__uint64_t mod>\n\
    class static_modint {\nprivate:\n\tusing mint = static_modint<mod>;\n\tusing i64\
    \ = long long;\n\tusing u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\
    \tusing i128 = __int128_t;\n\n\tu64 v;\n\tu64 normalize(i64 v_) const {\n\t\t\
    v_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\n\
    public:\n\tconstexpr static_modint() :v(0) {}\n\tconstexpr static_modint(const\
    \ i64& v_) :v(normalize(v_)) { }\n\n\t//operator\n\tconstexpr u64 val() const\
    \ {\n\t\treturn v;\n\t}\n\tconstexpr mint& operator+=(const mint& rhs) {\n\t\t\
    v += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator-=(const mint& rhs) {\n\t\tv += mod - rhs.val();\n\
    \t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator*=(const mint& rhs) {\n\t\tv = (u128)v * rhs.val() % mod;\n\t\t\
    return (*this);\n\t}\n\n\n\tconstexpr mint operator+(const mint& r) const {\n\t\
    \treturn mint(*this) += r;\n\t}\n\tconstexpr mint operator-(const mint& r) const\
    \ {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint operator*(const mint&\
    \ r) const {\n\t\treturn mint(*this) *= r;\n\t}\n\n\tconstexpr mint& operator+=(const\
    \ i64& rhs) {\n\t\t(*this) += mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator-=(const i64& rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\
    \t\treturn (*this);\n\t}\n\tconstexpr friend mint operator+(const i64& l, const\
    \ mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\t}\n\tconstexpr friend\
    \ mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t\
    }\n\n\tconstexpr mint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tconstexpr mint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\
    \t}\n\n\n\tconstexpr mint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\
    \t}\n\n\tconstexpr bool operator==(const mint& r) const {\n\t\treturn (*this).val()\
    \ == r.val();\n\t}\n\tconstexpr mint pow(u128 e) const {\n\t\tmint ans(1), base(*this);\n\
    \t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase\
    \ *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv()\
    \ const {\n\t\tll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n   \
    \     assert(d == 1);\n        return mint(y);\n\t}\n\n\tconstexpr mint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tconstexpr mint inv(const\
    \ mint&r)const{\n\t\treturn mint(*this) *= r.inv();\n\t}\n\tconstexpr friend mint\
    \ operator/(const mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t\
    }\n\tconstexpr friend mint operator/(const i64& l, const mint& r) {\n\t\treturn\
    \ mint(l) /= mint(r);\n\t}\n\n\t//istd::ostream\n\tconstexpr friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn\
    \ os;\n\t}\n\tconstexpr friend std::istream& operator>>(std::istream& is, mint&\
    \ mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\n\n\
    \n///@brief static modint(32bit ver)\ntemplate<__uint32_t mod>\nclass static_modint32\
    \ {\nprivate:\n\tusing mint = static_modint32<mod>;\n\tusing i32 = __int32_t;\n\
    \tusing u32 = __uint32_t;\n\tusing i64 = __int64_t;\n\tusing u64 = __uint64_t;\n\
    \n\tu32 v;\n\tinline u32 normalize(i64 v_) const {\n\t\tv_ %= mod;\n\t\tif (v_\
    \ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tconstexpr static_modint32()\
    \ :v(0) {}\n\tconstexpr static_modint32(const i64& v_) :v(normalize(v_)) { }\n\
    \n\t//operator\n\tconstexpr u64 val() const {\n\t\treturn (u64)v;\n\t}\n\tconstexpr\
    \ mint& operator+=(const mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod)\
    \ {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const\
    \ mint& rhs) {\n\t\tv += mod - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\
    \t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator*=(const mint& rhs)\
    \ {\n\t\tv = (u64)v * rhs.val() % mod;\n\t\treturn (*this);\n\t}\n\n\tconstexpr\
    \ mint operator+(const mint& r) const {\n\t\treturn mint(*this) += r;\n\t}\n\t\
    constexpr mint operator-(const mint& r) const {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const mint& r) const {\n\t\treturn mint(*this)\
    \ *= r;\n\t}\n\n\tconstexpr mint& operator+=(const i64& rhs) {\n\t\t(*this) +=\
    \ mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const i64&\
    \ rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint&\
    \ operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr friend mint operator+(const i64& l, const mint& r) {\n\t\treturn\
    \ mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) -= r;\n\t}\n\tconstexpr friend mint operator*(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t}\n\n\tconstexpr mint\
    \ operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\t}\n\tconstexpr mint\
    \ operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint\
    \ operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tconstexpr\
    \ mint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tconstexpr\
    \ bool operator==(const mint& r) const {\n\t\treturn (*this).val() == r.val();\n\
    \t}\n\tconstexpr mint pow(u64 e) const {\n\t\tmint ans(1), base(*this);\n\t\t\
    while (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase *=\
    \ base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv()\
    \ const {\n        ll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n\
    \        assert(d == 1);\n        return mint(y);\n    }\n\n\tconstexpr mint&\
    \ operator/=(const mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n    constexpr\
    \ mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }\n   \
    \ constexpr friend mint operator/(const mint& l, const i64& r) {\n\t\treturn mint(l)\
    \ /= mint(r);\n\t}\n\tconstexpr friend mint operator/(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\n\t//istd::ostream\n\tconstexpr\
    \ friend std::ostream& operator<<(std::ostream& os, const mint& mt) {\n\t\tos\
    \ << mt.val();\n\t\treturn os;\n\t}\n\tconstexpr friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t\
    }\n\n};\n\n};  // namespace library\n\n///@docs docs/math/static_modint.md"
  dependsOn:
  - math/gcd.hpp
  isVerificationFile: false
  path: math/static_modint.hpp
  requiredBy: []
  timestamp: '2023-04-06 20:41:27+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
  - test/yuki/No.891.test.cpp
documentation_of: math/static_modint.hpp
layout: document
redirect_from:
- /library/math/static_modint.hpp
- /library/math/static_modint.hpp.html
title: "static modint(\u9759\u7684modint)"
---
# static modint
## 概要
modint構造体のstaticバージョンです。**法がコンパイル時に定まる必要があります。**
- `static_modint`
- `static_modint32`

のふたつがありますが、法が32bit整数の時は`static_modint32`を使ってください。\
たとえば、法が$10^9+7$や$998244353$のときは`static_modint32`を使ったほうが速い...はずです。\
ただし、法が32bit整数に収まらないときは`static_modint`の方を使ってください。