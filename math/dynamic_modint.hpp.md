---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/barrett.hpp
    title: math/barrett.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  - icon: ':warning:'
    path: math/modint.hpp
    title: math/modint.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/dynamic_modint.md
    document_title: "dynamic modint(\u52D5\u7684modint)"
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
    \u7684modint)\n///@docs docs/math/dynamic_modint.md\n"
  code: "#pragma once\n#include\"math/barrett.hpp\"\nclass dynamic_modint32 {\n\t\
    using u32 = uint32_t;\n\tusing u64 = uint64_t;\n\n\tusing i32 = int32_t;\n\tusing\
    \ i64 = int64_t;\n\tusing br = internal::barrett;\n\n\tstatic br brt;\n\tstatic\
    \ u32 mod;\n\tu32 v;\t//value\npublic:\n\tstatic void set_mod(const u32& mod_)\
    \ {\n\t\tbrt = br(mod_);\t//change burrett\n\t\tmod = mod_;\n\t}\nprivate:\n\t\
    u32 normalize(const i64& x) const {\n\t\tu32 m = x % mod;\n\t\tif (m < 0) {\n\t\
    \t\tm += mod;\n\t\t}\n\t\treturn m;\n\t}\npublic:\n\tdynamic_modint32() :v(0)\
    \ { assert(mod); }\n\tdynamic_modint32(const i64& v_) :v(normalize(v_)) { assert(mod);\
    \ }\n\n\tu32 val() const { return v; }\n\n\tusing mint = dynamic_modint32;\n\n\
    \t//operators\n\tmint& operator=(const i64& r) {\n\t\tv = normalize(r); \n\t\t\
    return (*this);\n\t}\n\tmint& operator+=(const mint& r) {\n\t\tv += r.v;\n\t\t\
    if (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const\
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
    \u7684modint)\n///@docs docs/math/dynamic_modint.md"
  dependsOn:
  - math/barrett.hpp
  isVerificationFile: false
  path: math/dynamic_modint.hpp
  requiredBy:
  - math/modint.hpp
  - main.cpp
  timestamp: '2023-03-10 13:31:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dynamic_modint.hpp
layout: document
redirect_from:
- /library/math/dynamic_modint.hpp
- /library/math/dynamic_modint.hpp.html
title: "dynamic modint(\u52D5\u7684modint)"
---
# dynamic modint
## 概要
modint構造体です。コンパイル時にmodが定まらないときに使います。
## 使いかた
普通のintと同じです。ただし、実際に使う前に
```cpp
dynamic_modint32::set_mod(mod)
```
みたいにする必要があります。また、`mod`は`int`型の範囲に収まる**素数である**必要があります。\
素数でない場合、逆元などの取得がバグります。
## verify
良い感じのverifyが見つからなかったので自作しました...
```cpp
#include"template.hpp"
#include"math/dynamic_modint.hpp"
int mod;
bool eq(ll s, ll t) {
    if(!(0 <= t && t < mod)){
        cout << t << '\n';
    }
    assert(mod > 0);
    s %= mod;
    
    if (s < 0) {
        s += mod;
    }

    return s == t;
}
using mint = dynamic_modint32;
void test() {
    ll a = rand(), b = rand();
    mod = rand();
    if (mod <= 0) {
        return;
    }
    mint::set_mod(mod);
    mint ma = a, mb = b;
    
    if(!eq(a+b,(ma+mb).val())){
        cout << -1 << '\n';
    }

    if (!eq(a*b,(ma*mb).val())) {
        cout << -1 << '\n';
    }

    if(!eq(a-b,(ma-mb).val())){
        cout << -1 << '\n';
    }
}
int main(){
    while (1.*clock()/CLOCKS_PER_SEC <=3.0){
        test();
    }   
}
```

ここでは $+,-,*$ のテストをしています。
```cpp
#include"template.hpp"
#include"math/dynamic_modint.hpp"

int mod;
int q = 100000;
bool is_prime(int q) {
    if (q < 2) {
        return false;
    }
    if (q == 2) {
        return true;
    }
    if (~q & 1) {
        return false;
    }
    for (int d = 2; 1ll * d * d <= q; d++) {
        if (q % d == 0) {
            return false;
        }
    }
    return true;
}
void test() {
    using mint = dynamic_modint32;
    mod = rand();
    if(!is_prime(mod)){
        return;
    }
    q--;
    mint::set_mod(mod);
    mint ma = rand(), mb = rand();
    if (mb.val() == 0) {
        q++;
        return;
    }
    mint mc = ma / mb;
    if ((mc * mb).val() != ma.val()) {

    }
}
int main() {
    while(q){
        test();
    }
}
```
こちらは$/$のテスト

どちらの正常に作動しました。