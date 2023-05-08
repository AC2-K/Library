---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/matrix/Matrix Product.test.cpp
    title: test/yosupo_judge/matrix/Matrix Product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/static_modint.md
    document_title: "\u9759\u7684modint"
    links: []
  bundledCode: "#line 2 \"src/math/static_modint.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#line 3 \"src/math/gcd.hpp\"\n#include <tuple>\nnamespace kyopro\
    \ {\ntemplate <typename T>\nconstexpr T inline _gcd(T a, T b) {\n    assert(a\
    \ >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a),\
    \ __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n\
    \    while (a != b) {\n        if (!a||!b) {\n            return a + b;\n    \
    \    }\n        if (a >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate <typename T>\nconstexpr T\
    \ ext_gcd(T a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while (b) {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T,\
    \ T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n\
    \        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return\
    \ a;\n}\n};  // namespace kyopro\n#line 5 \"src/math/static_modint.hpp\"\nnamespace\
    \ kyopro {\ntemplate <__uint64_t mod>\nclass static_modint {\nprivate:\n    using\
    \ mint = static_modint<mod>;\n    using i64 = long long;\n    using u64 = unsigned\
    \ long long;\n    using u128 = __uint128_t;\n    using i128 = __int128_t;\n\n\
    \    u64 v;\n    constexpr inline u64 normalize(i64 v_) const {\n        v_ %=\
    \ mod;\n        if (v_ < 0) {\n            v_ += mod;\n        }\n        return\
    \ v_;\n    }\n\npublic:\n    constexpr static_modint() : v(0) {}\n    constexpr\
    \ static_modint(i64 v_) : v(normalize(v_)) {}\n\n    // operator\n    constexpr\
    \ u64 val() const { return v; }\n    constexpr mint& operator+=(const mint& rhs)\
    \ {\n        v += rhs.val();\n        if (v >= mod) {\n            v -= mod;\n\
    \        }\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ mint& rhs) {\n        v += mod - rhs.val();\n        if (v >= mod) {\n     \
    \       v -= mod;\n        }\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(const mint& rhs) {\n        v = (u128)v * rhs.val() % mod;\n    \
    \    return (*this);\n    }\n\n    constexpr mint operator+(const mint& r) const\
    \ { return mint(*this) += r; }\n    constexpr mint operator-(const mint& r) const\
    \ { return mint(*this) -= r; }\n    constexpr mint operator*(const mint& r) const\
    \ { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(const i64& rhs)\
    \ {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(const i64& rhs) {\n        (*this) -= mint(rhs);\n        return\
    \ (*this);\n    }\n    constexpr mint& operator*=(const i64& rhs) {\n        (*this)\
    \ *= mint(rhs);\n        return (*this);\n    }\n    constexpr friend mint operator+(const\
    \ i64& l, const mint& r) {\n        return mint(l) += r;\n    }\n    constexpr\
    \ friend mint operator-(const i64& l, const mint& r) {\n        return mint(l)\
    \ -= r;\n    }\n    constexpr friend mint operator*(const i64& l, const mint&\
    \ r) {\n        return mint(l) *= r;\n    }\n\n    constexpr mint operator+(i64\
    \ r) { return mint(*this) += r; }\n    constexpr mint operator-(i64 r) { return\
    \ mint(*this) -= r; }\n    constexpr mint operator*(i64 r) { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator=(i64 r) { return (*this) = mint(r);\
    \ }\n\n    constexpr bool operator==(const mint& r) const {\n        return (*this).val()\
    \ == r.val();\n    }\n\n    template <typename T>\n    constexpr mint pow(T e)\
    \ const {\n        mint ans(1), base(*this);\n        while (e) {\n          \
    \  if (e & 1) {\n                ans *= base;\n            }\n            base\
    \ *= base;\n            e >>= 1;\n        }\n        return ans;\n    }\n    constexpr\
    \ inline mint inv() const {\n        long long x, y;\n        auto d = ext_gcd((long\
    \ long)mod, (long long)v, x, y);\n        assert(d == 1);\n        return mint(y);\n\
    \    }\n\n    constexpr mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n    constexpr mint inv(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n    constexpr friend mint operator/(const mint& l, i64 r) {\n        return\
    \ mint(l) /= mint(r);\n    }\n    constexpr friend mint operator/(i64 l, const\
    \ mint& r) {\n        return mint(l) /= mint(r);\n    }\n\n    // stream\n   \
    \ constexpr friend std::ostream& operator<<(std::ostream& os,\n              \
    \                                const mint& mt) {\n        os << mt.val();\n\
    \        return os;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n        i64 v_;\n        is >> v_;\n        mt = v_;\n    \
    \    return is;\n    }\n};\ntemplate <__uint32_t mod>\nclass static_modint32 {\n\
    private:\n    using mint = static_modint32<mod>;\n    using i32 = __int32_t;\n\
    \    using u32 = __uint32_t;\n    using i64 = __int64_t;\n    using u64 = __uint64_t;\n\
    \n    u32 v;\n    constexpr inline u32 normalize(i64 v_) const {\n        v_ %=\
    \ mod;\n        if (v_ < 0) {\n            v_ += mod;\n        }\n        return\
    \ v_;\n    }\n\npublic:\n    constexpr static_modint32() : v(0) {}\n    constexpr\
    \ static_modint32(const i64& v_) : v(normalize(v_)) {}\n\n    // operator\n  \
    \  static mint raw(u32 a) {\n        mint m;\n        m.v = a;\n        return\
    \ m;\n    }\n    constexpr u32 val() const { return v; }\n    constexpr mint&\
    \ operator+=(const mint& rhs) {\n        v += rhs.val();\n        if (v >= mod)\
    \ {\n            v -= mod;\n        }\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(const mint& rhs) {\n        v += mod - rhs.val();\n       \
    \ if (v >= mod) {\n            v -= mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(const mint& rhs) {\n        v = (u64)v\
    \ * rhs.val() % mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const { return mint(*this) += r; }\n    constexpr mint operator-(const\
    \ mint& r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ mint& r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(const\
    \ i64& rhs) {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n\
    \    constexpr mint& operator-=(const i64& rhs) {\n        (*this) -= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator*=(const i64& rhs)\
    \ {\n        (*this) *= mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ friend mint operator+(const i64& l, const mint& r) {\n        return mint(l)\
    \ += r;\n    }\n    constexpr friend mint operator-(i64 l, const mint& r) {\n\
    \        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(i64\
    \ l, const mint& r) {\n        return mint(l) *= r;\n    }\n\n    constexpr mint\
    \ operator+(i64 r) { return mint(*this) += r; }\n    constexpr mint operator-(i64\
    \ r) { return mint(*this) -= r; }\n    constexpr mint operator*(i64 r) { return\
    \ mint(*this) *= r; }\n\n    constexpr mint& operator=(i64 r) { return (*this)\
    \ = mint(r); }\n\n    constexpr bool operator==(const mint& r) const {\n     \
    \   return (*this).val() == r.val();\n    }\n    template <typename T>\n    constexpr\
    \ mint pow(T e) const {\n        mint ans(1), base(*this);\n        while (e)\
    \ {\n            if (e & 1) {\n                ans *= base;\n            }\n \
    \           base *= base;\n            e >>= 1;\n        }\n        return ans;\n\
    \    }\n\n    constexpr inline mint inv() const {\n        long long x, y;\n \
    \       auto d = ext_gcd((long long)mod, (long long)v, x, y);\n        assert(d\
    \ == 1);\n        return mint(y);\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& r) { return (*this) *= r.inv(); }\n    constexpr mint operator/(const\
    \ mint& r) const {\n        return mint(*this) *= r.inv();\n    }\n    constexpr\
    \ friend mint operator/(const mint& l, i64 r) {\n        return mint(l) /= mint(r);\n\
    \    }\n    constexpr friend mint operator/(i64 l, const mint& r) {\n        return\
    \ mint(l) /= mint(r);\n    }\n\n    // stream\n    constexpr friend std::ostream&\
    \ operator<<(std::ostream& os,\n                                             \
    \ const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n    constexpr\
    \ friend std::istream& operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n\
    \        is >> v_;\n        mt = v_;\n        return is;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief \u9759\u7684modint\n * @docs docs/math/static_modint.md\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include \"../math/gcd.hpp\"\
    \nnamespace kyopro {\ntemplate <__uint64_t mod>\nclass static_modint {\nprivate:\n\
    \    using mint = static_modint<mod>;\n    using i64 = long long;\n    using u64\
    \ = unsigned long long;\n    using u128 = __uint128_t;\n    using i128 = __int128_t;\n\
    \n    u64 v;\n    constexpr inline u64 normalize(i64 v_) const {\n        v_ %=\
    \ mod;\n        if (v_ < 0) {\n            v_ += mod;\n        }\n        return\
    \ v_;\n    }\n\npublic:\n    constexpr static_modint() : v(0) {}\n    constexpr\
    \ static_modint(i64 v_) : v(normalize(v_)) {}\n\n    // operator\n    constexpr\
    \ u64 val() const { return v; }\n    constexpr mint& operator+=(const mint& rhs)\
    \ {\n        v += rhs.val();\n        if (v >= mod) {\n            v -= mod;\n\
    \        }\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ mint& rhs) {\n        v += mod - rhs.val();\n        if (v >= mod) {\n     \
    \       v -= mod;\n        }\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(const mint& rhs) {\n        v = (u128)v * rhs.val() % mod;\n    \
    \    return (*this);\n    }\n\n    constexpr mint operator+(const mint& r) const\
    \ { return mint(*this) += r; }\n    constexpr mint operator-(const mint& r) const\
    \ { return mint(*this) -= r; }\n    constexpr mint operator*(const mint& r) const\
    \ { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(const i64& rhs)\
    \ {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(const i64& rhs) {\n        (*this) -= mint(rhs);\n        return\
    \ (*this);\n    }\n    constexpr mint& operator*=(const i64& rhs) {\n        (*this)\
    \ *= mint(rhs);\n        return (*this);\n    }\n    constexpr friend mint operator+(const\
    \ i64& l, const mint& r) {\n        return mint(l) += r;\n    }\n    constexpr\
    \ friend mint operator-(const i64& l, const mint& r) {\n        return mint(l)\
    \ -= r;\n    }\n    constexpr friend mint operator*(const i64& l, const mint&\
    \ r) {\n        return mint(l) *= r;\n    }\n\n    constexpr mint operator+(i64\
    \ r) { return mint(*this) += r; }\n    constexpr mint operator-(i64 r) { return\
    \ mint(*this) -= r; }\n    constexpr mint operator*(i64 r) { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator=(i64 r) { return (*this) = mint(r);\
    \ }\n\n    constexpr bool operator==(const mint& r) const {\n        return (*this).val()\
    \ == r.val();\n    }\n\n    template <typename T>\n    constexpr mint pow(T e)\
    \ const {\n        mint ans(1), base(*this);\n        while (e) {\n          \
    \  if (e & 1) {\n                ans *= base;\n            }\n            base\
    \ *= base;\n            e >>= 1;\n        }\n        return ans;\n    }\n    constexpr\
    \ inline mint inv() const {\n        long long x, y;\n        auto d = ext_gcd((long\
    \ long)mod, (long long)v, x, y);\n        assert(d == 1);\n        return mint(y);\n\
    \    }\n\n    constexpr mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n    constexpr mint inv(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n    constexpr friend mint operator/(const mint& l, i64 r) {\n        return\
    \ mint(l) /= mint(r);\n    }\n    constexpr friend mint operator/(i64 l, const\
    \ mint& r) {\n        return mint(l) /= mint(r);\n    }\n\n    // stream\n   \
    \ constexpr friend std::ostream& operator<<(std::ostream& os,\n              \
    \                                const mint& mt) {\n        os << mt.val();\n\
    \        return os;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n        i64 v_;\n        is >> v_;\n        mt = v_;\n    \
    \    return is;\n    }\n};\ntemplate <__uint32_t mod>\nclass static_modint32 {\n\
    private:\n    using mint = static_modint32<mod>;\n    using i32 = __int32_t;\n\
    \    using u32 = __uint32_t;\n    using i64 = __int64_t;\n    using u64 = __uint64_t;\n\
    \n    u32 v;\n    constexpr inline u32 normalize(i64 v_) const {\n        v_ %=\
    \ mod;\n        if (v_ < 0) {\n            v_ += mod;\n        }\n        return\
    \ v_;\n    }\n\npublic:\n    constexpr static_modint32() : v(0) {}\n    constexpr\
    \ static_modint32(const i64& v_) : v(normalize(v_)) {}\n\n    // operator\n  \
    \  static mint raw(u32 a) {\n        mint m;\n        m.v = a;\n        return\
    \ m;\n    }\n    constexpr u32 val() const { return v; }\n    constexpr mint&\
    \ operator+=(const mint& rhs) {\n        v += rhs.val();\n        if (v >= mod)\
    \ {\n            v -= mod;\n        }\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(const mint& rhs) {\n        v += mod - rhs.val();\n       \
    \ if (v >= mod) {\n            v -= mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(const mint& rhs) {\n        v = (u64)v\
    \ * rhs.val() % mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const { return mint(*this) += r; }\n    constexpr mint operator-(const\
    \ mint& r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ mint& r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(const\
    \ i64& rhs) {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n\
    \    constexpr mint& operator-=(const i64& rhs) {\n        (*this) -= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator*=(const i64& rhs)\
    \ {\n        (*this) *= mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ friend mint operator+(const i64& l, const mint& r) {\n        return mint(l)\
    \ += r;\n    }\n    constexpr friend mint operator-(i64 l, const mint& r) {\n\
    \        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(i64\
    \ l, const mint& r) {\n        return mint(l) *= r;\n    }\n\n    constexpr mint\
    \ operator+(i64 r) { return mint(*this) += r; }\n    constexpr mint operator-(i64\
    \ r) { return mint(*this) -= r; }\n    constexpr mint operator*(i64 r) { return\
    \ mint(*this) *= r; }\n\n    constexpr mint& operator=(i64 r) { return (*this)\
    \ = mint(r); }\n\n    constexpr bool operator==(const mint& r) const {\n     \
    \   return (*this).val() == r.val();\n    }\n    template <typename T>\n    constexpr\
    \ mint pow(T e) const {\n        mint ans(1), base(*this);\n        while (e)\
    \ {\n            if (e & 1) {\n                ans *= base;\n            }\n \
    \           base *= base;\n            e >>= 1;\n        }\n        return ans;\n\
    \    }\n\n    constexpr inline mint inv() const {\n        long long x, y;\n \
    \       auto d = ext_gcd((long long)mod, (long long)v, x, y);\n        assert(d\
    \ == 1);\n        return mint(y);\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& r) { return (*this) *= r.inv(); }\n    constexpr mint operator/(const\
    \ mint& r) const {\n        return mint(*this) *= r.inv();\n    }\n    constexpr\
    \ friend mint operator/(const mint& l, i64 r) {\n        return mint(l) /= mint(r);\n\
    \    }\n    constexpr friend mint operator/(i64 l, const mint& r) {\n        return\
    \ mint(l) /= mint(r);\n    }\n\n    // stream\n    constexpr friend std::ostream&\
    \ operator<<(std::ostream& os,\n                                             \
    \ const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n    constexpr\
    \ friend std::istream& operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n\
    \        is >> v_;\n        mt = v_;\n        return is;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief \u9759\u7684modint\n * @docs docs/math/static_modint.md\n\
    \ */"
  dependsOn:
  - src/math/gcd.hpp
  isVerificationFile: false
  path: src/math/static_modint.hpp
  requiredBy: []
  timestamp: '2023-05-08 02:55:40+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
documentation_of: src/math/static_modint.hpp
layout: document
redirect_from:
- /library/src/math/static_modint.hpp
- /library/src/math/static_modint.hpp.html
title: "\u9759\u7684modint"
---
# static modint
## 概要
modint構造体のstaticバージョンです。**法がコンパイル時に定まる必要があります。**
- `static_modint`
- `static_modint32`

のふたつがありますが、法が32bit整数の時は`static_modint32`を使ってください。\
たとえば、法が$10^9+7$や$998244353$のときは`static_modint32`を使ったほうが速い...はずです。\
ただし、法が32bit整数に収まらないときは`static_modint`の方を使ってください。