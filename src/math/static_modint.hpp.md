---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/math/ext_gcd.hpp
    title: "ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
      \u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/static_modint.md
    document_title: "static modint(\u9759\u7684modint)"
    links: []
  bundledCode: "#line 1 \"src/math/ext_gcd.hpp\"\nstatic constexpr ll ext_gcd(ll a,\
    \ ll b, ll& x, ll& y) {\n    ll u = 0, v = 1, q = 0, tmp = 0;\n    x = 1;\n  \
    \  y = 0;\n    while (b) {\n        q = a / b;\n        tmp = u;\n        u =\
    \ x - q * u;\n        x = tmp;\n        tmp = v;\n        v = y - q * v;\n   \
    \     y = tmp;\n        tmp = b;\n        b = a - q * b;\n        a = tmp;\n \
    \   }\n    return a;\n}\n/// @brief ext gcd(\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\
    \u30C3\u30C9\u306E\u4E92\u9664\u6CD5)\n/// @return ax+by=gcd(a,b)\u306A\u308B\
    x,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\u5024\u306Bgcd(a,b)\n#line 2 \"\
    src/math/static_modint.hpp\"\ntemplate<__uint64_t mod>\nclass static_modint {\n\
    private:\n\tusing mint = static_modint<mod>;\n\tusing i64 = long long;\n\tusing\
    \ u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\
    \n\tu64 v;\n\tconstexpr u64 normalize(i64 v_) const {\n\t\tv_ %= mod;\n\t\tif\
    \ (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tconstexpr\
    \ static_modint() :v(0) {}\n\tconstexpr static_modint(const i64& v_) :v(normalize(v_))\
    \ { }\n\n\t//operator\n\tconstexpr u64 val() const {\n\t\treturn v;\n\t}\n\tconstexpr\
    \ mint& operator+=(const mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod)\
    \ {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const\
    \ mint& rhs) {\n\t\tv += mod - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\
    \t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator*=(const mint& rhs)\
    \ {\n\t\tv = (u128)v * rhs.val() % mod;\n\t\treturn (*this);\n\t}\n\n\n\tconstexpr\
    \ mint operator+(const mint& r) const {\n\t\treturn mint(*this) += r;\n\t}\n\t\
    constexpr mint operator-(const mint& r) const {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const mint& r) const {\n\t\treturn mint(*this)\
    \ *= r;\n\t}\n\n\tconstexpr mint& operator+=(const i64& rhs) {\n\t\t(*this) +=\
    \ mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const i64&\
    \ rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint&\
    \ operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr friend mint operator+(const i64& l, const mint& r) {\n\t\treturn\
    \ mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) -= r;\n\t}\n\tfriend mint operator*(const i64& l, const\
    \ mint& r) {\n\t\treturn mint(l) *= r;\n\t}\n\n\tconstexpr mint operator+(const\
    \ i64& r) {\n\t\treturn mint(*this) += r;\n\t}\n\tconstexpr mint operator-(const\
    \ i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint operator*(const\
    \ i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tconstexpr mint& operator=(const\
    \ i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tconstexpr bool operator==(const\
    \ mint& r) const {\n\t\treturn (*this).val() == r.val();\n\t}\n\tconstexpr mint\
    \ pow(u128 e) const {\n\t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\t\
    if (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>=\
    \ 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv() const {\n        ll\
    \ x,y;\n        assert(ext_gcd(mod, val, x, y) != 1);\n        return mint(y);\n\
    \    }\n\n\tconstexpr mint& operator/=(const mint& r) {\n\t\treturn (*this) *=\
    \ r.inv();\n\t}\n\tconstexpr friend mint operator/(const mint& l, const i64& r)\
    \ {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\tfriend ostream& operator<<(ostream&\
    \ os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\
    \t\treturn is;\n\t}\n};\ntemplate <__uint32_t mod> \nclass static_modint32 {\n\
    \      private:\n\tusing mint = static_modint32<mod>;\n\tusing i32 = __int32_t;\n\
    \tusing u32 = __uint32_t;\n\tusing i64 = __int64_t;\n\tusing u64 = unsigned long\
    \ long;\n\n\tu32 v;\n\tconstexpr u32 normalize(i64 v_) const {\n\t\tv_ %= mod;\n\
    \t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tconstexpr\
    \ static_modint32() :v(0) {}\n\tconstexpr static_modint32(const i64& v_) :v(normalize(v_))\
    \ { }\n\n\t//operator\n\tu64 val() const {\n\t\treturn (u64)v;\n\t}\n\tconstexpr\
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
    \ const {\n        ll x,y;\n        assert(ext_gcd(mod, val, x, y) != 1);\n  \
    \      return mint(y);\n    }\n\n\tconstexpr mint& operator/=(const mint& r) {\n\
    \t\treturn (*this) *= r.inv();\n\t}\n    constexpr mint operator/(const mint&\
    \ r) { return mint(*this) *= r.inv(); }\n    constexpr friend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\
    \tconstexpr friend ostream& operator<<(ostream& os, const mint& mt) {\n\t\tos\
    \ << mt.val();\n\t\treturn os;\n\t}\n\tconstexpr friend istream& operator>>(istream&\
    \ is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t\
    }\n};\n///@brief static modint(\u9759\u7684modint)\n///@docs docs/math/static_modint.md\n"
  code: "#include\"../math/ext_gcd.hpp\"\ntemplate<__uint64_t mod>\nclass static_modint\
    \ {\nprivate:\n\tusing mint = static_modint<mod>;\n\tusing i64 = long long;\n\t\
    using u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\
    \n\tu64 v;\n\tconstexpr u64 normalize(i64 v_) const {\n\t\tv_ %= mod;\n\t\tif\
    \ (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tconstexpr\
    \ static_modint() :v(0) {}\n\tconstexpr static_modint(const i64& v_) :v(normalize(v_))\
    \ { }\n\n\t//operator\n\tconstexpr u64 val() const {\n\t\treturn v;\n\t}\n\tconstexpr\
    \ mint& operator+=(const mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod)\
    \ {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const\
    \ mint& rhs) {\n\t\tv += mod - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\
    \t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator*=(const mint& rhs)\
    \ {\n\t\tv = (u128)v * rhs.val() % mod;\n\t\treturn (*this);\n\t}\n\n\n\tconstexpr\
    \ mint operator+(const mint& r) const {\n\t\treturn mint(*this) += r;\n\t}\n\t\
    constexpr mint operator-(const mint& r) const {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const mint& r) const {\n\t\treturn mint(*this)\
    \ *= r;\n\t}\n\n\tconstexpr mint& operator+=(const i64& rhs) {\n\t\t(*this) +=\
    \ mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const i64&\
    \ rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint&\
    \ operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr friend mint operator+(const i64& l, const mint& r) {\n\t\treturn\
    \ mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) -= r;\n\t}\n\tfriend mint operator*(const i64& l, const\
    \ mint& r) {\n\t\treturn mint(l) *= r;\n\t}\n\n\tconstexpr mint operator+(const\
    \ i64& r) {\n\t\treturn mint(*this) += r;\n\t}\n\tconstexpr mint operator-(const\
    \ i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint operator*(const\
    \ i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tconstexpr mint& operator=(const\
    \ i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tconstexpr bool operator==(const\
    \ mint& r) const {\n\t\treturn (*this).val() == r.val();\n\t}\n\tconstexpr mint\
    \ pow(u128 e) const {\n\t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\t\
    if (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>=\
    \ 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv() const {\n        ll\
    \ x,y;\n        assert(ext_gcd(mod, val, x, y) != 1);\n        return mint(y);\n\
    \    }\n\n\tconstexpr mint& operator/=(const mint& r) {\n\t\treturn (*this) *=\
    \ r.inv();\n\t}\n\tconstexpr friend mint operator/(const mint& l, const i64& r)\
    \ {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\tfriend ostream& operator<<(ostream&\
    \ os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\
    \t\treturn is;\n\t}\n};\ntemplate <__uint32_t mod> \nclass static_modint32 {\n\
    \      private:\n\tusing mint = static_modint32<mod>;\n\tusing i32 = __int32_t;\n\
    \tusing u32 = __uint32_t;\n\tusing i64 = __int64_t;\n\tusing u64 = unsigned long\
    \ long;\n\n\tu32 v;\n\tconstexpr u32 normalize(i64 v_) const {\n\t\tv_ %= mod;\n\
    \t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tconstexpr\
    \ static_modint32() :v(0) {}\n\tconstexpr static_modint32(const i64& v_) :v(normalize(v_))\
    \ { }\n\n\t//operator\n\tu64 val() const {\n\t\treturn (u64)v;\n\t}\n\tconstexpr\
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
    \ const {\n        ll x,y;\n        assert(ext_gcd(mod, val, x, y) != 1);\n  \
    \      return mint(y);\n    }\n\n\tconstexpr mint& operator/=(const mint& r) {\n\
    \t\treturn (*this) *= r.inv();\n\t}\n    constexpr mint operator/(const mint&\
    \ r) { return mint(*this) *= r.inv(); }\n    constexpr friend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\
    \tconstexpr friend ostream& operator<<(ostream& os, const mint& mt) {\n\t\tos\
    \ << mt.val();\n\t\treturn os;\n\t}\n\tconstexpr friend istream& operator>>(istream&\
    \ is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t\
    }\n};\n///@brief static modint(\u9759\u7684modint)\n///@docs docs/math/static_modint.md"
  dependsOn:
  - src/math/ext_gcd.hpp
  isVerificationFile: false
  path: src/math/static_modint.hpp
  requiredBy: []
  timestamp: '2023-03-27 01:42:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/static_modint.hpp
layout: document
redirect_from:
- /library/src/math/static_modint.hpp
- /library/src/math/static_modint.hpp.html
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