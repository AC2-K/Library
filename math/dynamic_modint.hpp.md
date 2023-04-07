---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: internal/barrett.hpp
    title: barrett reduction
  - icon: ':question:'
    path: internal/montgomery.hpp
    title: MontgomeryReduction
  _extendedRequiredBy:
  - icon: ':question:'
    path: math/miller.hpp
    title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\\phi \u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  - icon: ':x:'
    path: test/yuki/No-3030.test.cpp
    title: test/yuki/No-3030.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/math/dynamic_modint.md
    document_title: "dynamic modint(\u52D5\u7684modint)"
    links: []
  bundledCode: "#line 2 \"math/dynamic_modint.hpp\"\n#include <iostream>\n#include\
    \ <cassert>\n#line 2 \"internal/barrett.hpp\"\nnamespace internal {\n\t///@brief\
    \ barrett reduction\n\tclass barrett {\n\t\tusing u32 = uint32_t;\n\t\tusing u64\
    \ = uint64_t;\n\n\t\tu64 m;\n\t\tu64 im;\n\tpublic:\n\t\texplicit barrett() =\
    \ default;\n\t\texplicit barrett(u64 m_) :m(m_), im((u64)(long double)static_cast<u64>(-1)\
    \ / m_ + 1) {}\n\n\t\tu64 get_mod() const { return m; }\n\t\tu64 reduce(int64_t\
    \ a)const{\n        \tif (a < 0) return m - reduce(-a);\n            u64 q = ((__uint128_t)a\
    \ * im) >> 64;\n            a -= m * q;\n            if (a >= m) a -= m;\n   \
    \         return a;\n        }\n\t\tu64 mul(u64 a, u64 b) const {\n\t\t\tif (a\
    \ == 0 || b == 0) {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tu64 z = a;\n\t\t\tz *=\
    \ b;\n\t\t\tu64 x = (u64)(((__uint128_t)(z)*im) >> 64);\n\n\t\t\tu32 v = (u32)(z\
    \ - x * m);\n\n\t\t\tif (v >= m)v += m;\n\t\t\treturn v;\n\t\t}\n\t};\n}\n#line\
    \ 2 \"internal/montgomery.hpp\"\n#include<limits>\n#include<numeric>\nnamespace\
    \ internal {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n    using\
    \ i32 = int32_t;\n    using i64 = int64_t;\n    using u128 = __uint128_t;\n  \
    \  using i128 = __int128_t;\n    /// @brief MontgomeryReduction\n    template<typename\
    \ T,typename LargeT>\n    class MontgomeryReduction64 {\n        static constexpr\
    \ int lg = std::numeric_limits<T>::digits;\n        T mod, r, r2, minv;\n    \
    \    T calc_inv() {\n            T t = 0, res = 0;\n            for (int i = 0;\
    \ i < lg; i++) {\n                if (~t & 1) {\n                    t += mod;\n\
    \                    res += static_cast<T>(1) << i;\n                }\n     \
    \           t >>= 1;\n            }\n            return res;\n        }\n\n\n\
    \    public:\n        MontgomeryReduction64() = default;\n        constexpr T\
    \ get_mod() { return mod; }\n        constexpr int get_lg() { return lg; }\n\n\
    \n        void set_mod(const T& m) {\n            assert(m > 0);\n           \
    \ assert(m & 1);\n\n            mod = m;\n\n            r = (-static_cast<T>(mod))\
    \ % mod;\n            r2 = (-static_cast<LargeT>(mod)) % mod;\n            minv\
    \ = calc_inv();\n        }\n\n\n        T reduce(LargeT x) const {\n         \
    \   u64 res = (x + static_cast<LargeT>(static_cast<T>(x) * minv) * mod) >> lg;\n\
    \n            if (res >= mod)res -= mod;\n            return res;\n        }\n\
    \n        T generate(LargeT x) {\n            return reduce(x * r2);\n       \
    \ }\n\n        T mult(T x, T y) {\n            return reduce(static_cast<LargeT>(x)\
    \ * y);\n        }\n    };\n};\n#line 6 \"math/dynamic_modint.hpp\"\ntemplate\
    \ <int id = -1> class barrett_modint {\n    using u32 = uint32_t;\n    using u64\
    \ = uint64_t;\n\n    using i32 = int32_t;\n    using i64 = int64_t;\n    using\
    \ br = internal::barrett;\n\n    static br brt;\n    static u32 mod;\n    u32\
    \ v;  // value\n  public:\n    static void set_mod(u32 mod_) {\n        brt =\
    \ br(mod_);\n        mod = mod_;\n    }\n\n  public:\n    explicit constexpr barrett_modint()\
    \ : v(0) {\n        assert(mod);\n    }  // mod\u304C\u6C7A\u5B9A\u6E08\u307F\u3067\
    \u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n    explicit constexpr barrett_modint(i64\
    \ v_) : v(brt.reduce(v_)) {\n        assert(mod);\n    }\n\n    u32 val() const\
    \ { return v; }\n    static u32 get_mod() { return mod; }\n    using mint = barrett_modint<id>;\n\
    \n    // operators\n    constexpr mint& operator=(i64 r) {\n        v = brt.reduce(r);\n\
    \        return (*this);\n    }\n    constexpr mint& operator+=(const mint& r)\
    \ {\n        v += r.v;\n        if (v >= mod) {\n            v -= mod;\n     \
    \   }\n        return (*this);\n    }\n    constexpr mint& operator-=(const mint&\
    \ r) {\n        v += mod - r.v;\n        if (v >= mod) {\n            v -= mod;\n\
    \        }\n\n        return (*this);\n    }\n    constexpr mint& operator*=(const\
    \ mint& r) {\n        v = brt.mul(v, r.v);\n        return (*this);\n    }\n\n\
    \    constexpr mint operator+(const mint& r) const { return mint(*this) += r;\
    \ }\n    constexpr mint operator-(const mint& r) const { return mint(*this) -=\
    \ r; }\n    constexpr mint operator*(const mint& r) const { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator+=(i64 r) { return (*this) += mint(r);\
    \ }\n    constexpr mint& operator-=(i64 r) { return (*this) -= mint(r); }\n  \
    \  constexpr mint& operator*=(i64 r) { return (*this) *= mint(r); }\n\n    friend\
    \ mint operator+(i64 l, const mint& r) { return mint(l) += r; }\n    friend mint\
    \ operator+(const mint& l, i64 r) { return mint(l) += r; }\n    friend mint operator-(i64\
    \ l, const mint& r) { return mint(l) -= r; }\n    friend mint operator-(const\
    \ mint& l, i64 r) { return mint(l) -= r; }\n    friend mint operator*(i64 l, const\
    \ mint& r) { return mint(l) *= r; }\n    friend mint operator*(const mint& l,\
    \ i64 r) { return mint(l) += r; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n\
    \    friend std::istream& operator>>(std::istream& is, mint& mt) {\n        i64\
    \ v_;\n        is >> v_;\n        mt = v_;\n        return is;\n    }\n    template\
    \ <typename T> mint pow(T e) const {\n        mint res(1), base(*this);\n\n  \
    \      while (e) {\n            if (e & 1) {\n                res *= base;\n \
    \           }\n            e >>= 1;\n            base *= base;\n        }\n  \
    \      return res;\n    }\n    inline mint inv() const { return pow(mod - 2);\
    \ }\n\n    mint& operator/=(const mint& r) { return (*this) *= r.inv(); }\n  \
    \  mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }\n  \
    \  mint& operator/=(i64 r) { return (*this) /= mint(r); }\n    friend mint operator/(const\
    \ mint& l, i64 r) { return mint(l) /= r; }\n    friend mint operator/(i64 l, const\
    \ mint& r) { return mint(l) /= r; }\n};\ntemplate <int id> typename barrett_modint<id>::u32\
    \ barrett_modint<id>::mod;\ntemplate <int id> typename barrett_modint<id>::br\
    \ barrett_modint<id>::brt;\n\ntemplate <typename T = uint32_t, typename LargeT\
    \ = uint64_t, int id = -1>\nclass dynamic_modint {\n    static T mod;\n    static\
    \ internal::MontgomeryReduction64<T, LargeT> mr;\n\n  public:\n    static void\
    \ set_mod(T mod_) {\n        mr.set_mod(mod_);\n        mod = mod_;\n    }\n\n\
    \    static T get_mod() { return mod; }\n\n  private:\n    T v;\n\n  public:\n\
    \    dynamic_modint(T v_ = 0) {\n        assert(mod);\n        v = mr.generate(v_);\n\
    \    }\n    T val() const { return mr.reduce(v); }\n\n    using mint = dynamic_modint<T,\
    \ LargeT, id>;\n    mint& operator+=(const mint& r) {\n        v += r.v;\n   \
    \     if (v >= mr.get_mod()) {\n            v -= mr.get_mod();\n        }\n\n\
    \        return (*this);\n    }\n\n    mint& operator-=(const mint& r) {\n   \
    \     v += mr.get_mod() - r.v;\n        if (v >= mr.get_mod) {\n            v\
    \ -= mr.get_mod();\n        }\n\n        return (*this);\n    }\n\n    mint& operator*=(const\
    \ mint& r) {\n        v = mr.mult(v, r.v);\n        return (*this);\n    }\n\n\
    \    mint operator+(const mint& r) { return mint(*this) += r; }\n    mint operator-(const\
    \ mint& r) { return mint(*this) -= r; }\n    mint operator*(const mint& r) { return\
    \ mint(*this) *= r; }\n\n    mint& operator=(const T& v_) {\n        (*this) =\
    \ mint(v_);\n        return (*this);\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n\
    \    friend std::istream& operator>>(std::istream& is, mint& mt) {\n        T\
    \ v_;\n        is >> v_;\n        mt = v_;\n        return is;\n    }\n    template\
    \ <typename P> mint pow(P e) const {\n        assert(e >= 0);\n        mint res(1),\
    \ base(*this);\n\n        while (e) {\n            if (e & 1) {\n            \
    \    res *= base;\n            }\n            e >>= 1;\n            base *= base;\n\
    \        }\n        return res;\n    }\n    mint inv() const { return pow(mod\
    \ - 2); }\n\n    mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n    mint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n    mint& operator/=(T r) { return (*this) /= mint(r); }\n    friend mint\
    \ operator/(const mint& l, T r) { return mint(l) /= r; }\n    friend mint operator/(T\
    \ l, const mint& r) { return mint(l) /= r; }\n};\ntemplate <typename T, typename\
    \ LargeT, int id>\nT dynamic_modint<T, LargeT, id>::mod;\ntemplate <typename T,\
    \ typename LargeT, int id>\ninternal::MontgomeryReduction64<T, LargeT> dynamic_modint<T,\
    \ LargeT, id>::mr;\n\n/// @brief dynamic modint(\u52D5\u7684modint)\n/// @docs\
    \ docs/math/dynamic_modint.md\n"
  code: "#pragma once\n#include <iostream>\n#include <cassert>\n#include \"internal/barrett.hpp\"\
    \n#include \"internal/montgomery.hpp\"\ntemplate <int id = -1> class barrett_modint\
    \ {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    using i32 = int32_t;\n\
    \    using i64 = int64_t;\n    using br = internal::barrett;\n\n    static br\
    \ brt;\n    static u32 mod;\n    u32 v;  // value\n  public:\n    static void\
    \ set_mod(u32 mod_) {\n        brt = br(mod_);\n        mod = mod_;\n    }\n\n\
    \  public:\n    explicit constexpr barrett_modint() : v(0) {\n        assert(mod);\n\
    \    }  // mod\u304C\u6C7A\u5B9A\u6E08\u307F\u3067\u3042\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\n    explicit constexpr barrett_modint(i64 v_) : v(brt.reduce(v_))\
    \ {\n        assert(mod);\n    }\n\n    u32 val() const { return v; }\n    static\
    \ u32 get_mod() { return mod; }\n    using mint = barrett_modint<id>;\n\n    //\
    \ operators\n    constexpr mint& operator=(i64 r) {\n        v = brt.reduce(r);\n\
    \        return (*this);\n    }\n    constexpr mint& operator+=(const mint& r)\
    \ {\n        v += r.v;\n        if (v >= mod) {\n            v -= mod;\n     \
    \   }\n        return (*this);\n    }\n    constexpr mint& operator-=(const mint&\
    \ r) {\n        v += mod - r.v;\n        if (v >= mod) {\n            v -= mod;\n\
    \        }\n\n        return (*this);\n    }\n    constexpr mint& operator*=(const\
    \ mint& r) {\n        v = brt.mul(v, r.v);\n        return (*this);\n    }\n\n\
    \    constexpr mint operator+(const mint& r) const { return mint(*this) += r;\
    \ }\n    constexpr mint operator-(const mint& r) const { return mint(*this) -=\
    \ r; }\n    constexpr mint operator*(const mint& r) const { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator+=(i64 r) { return (*this) += mint(r);\
    \ }\n    constexpr mint& operator-=(i64 r) { return (*this) -= mint(r); }\n  \
    \  constexpr mint& operator*=(i64 r) { return (*this) *= mint(r); }\n\n    friend\
    \ mint operator+(i64 l, const mint& r) { return mint(l) += r; }\n    friend mint\
    \ operator+(const mint& l, i64 r) { return mint(l) += r; }\n    friend mint operator-(i64\
    \ l, const mint& r) { return mint(l) -= r; }\n    friend mint operator-(const\
    \ mint& l, i64 r) { return mint(l) -= r; }\n    friend mint operator*(i64 l, const\
    \ mint& r) { return mint(l) *= r; }\n    friend mint operator*(const mint& l,\
    \ i64 r) { return mint(l) += r; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n\
    \    friend std::istream& operator>>(std::istream& is, mint& mt) {\n        i64\
    \ v_;\n        is >> v_;\n        mt = v_;\n        return is;\n    }\n    template\
    \ <typename T> mint pow(T e) const {\n        mint res(1), base(*this);\n\n  \
    \      while (e) {\n            if (e & 1) {\n                res *= base;\n \
    \           }\n            e >>= 1;\n            base *= base;\n        }\n  \
    \      return res;\n    }\n    inline mint inv() const { return pow(mod - 2);\
    \ }\n\n    mint& operator/=(const mint& r) { return (*this) *= r.inv(); }\n  \
    \  mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }\n  \
    \  mint& operator/=(i64 r) { return (*this) /= mint(r); }\n    friend mint operator/(const\
    \ mint& l, i64 r) { return mint(l) /= r; }\n    friend mint operator/(i64 l, const\
    \ mint& r) { return mint(l) /= r; }\n};\ntemplate <int id> typename barrett_modint<id>::u32\
    \ barrett_modint<id>::mod;\ntemplate <int id> typename barrett_modint<id>::br\
    \ barrett_modint<id>::brt;\n\ntemplate <typename T = uint32_t, typename LargeT\
    \ = uint64_t, int id = -1>\nclass dynamic_modint {\n    static T mod;\n    static\
    \ internal::MontgomeryReduction64<T, LargeT> mr;\n\n  public:\n    static void\
    \ set_mod(T mod_) {\n        mr.set_mod(mod_);\n        mod = mod_;\n    }\n\n\
    \    static T get_mod() { return mod; }\n\n  private:\n    T v;\n\n  public:\n\
    \    dynamic_modint(T v_ = 0) {\n        assert(mod);\n        v = mr.generate(v_);\n\
    \    }\n    T val() const { return mr.reduce(v); }\n\n    using mint = dynamic_modint<T,\
    \ LargeT, id>;\n    mint& operator+=(const mint& r) {\n        v += r.v;\n   \
    \     if (v >= mr.get_mod()) {\n            v -= mr.get_mod();\n        }\n\n\
    \        return (*this);\n    }\n\n    mint& operator-=(const mint& r) {\n   \
    \     v += mr.get_mod() - r.v;\n        if (v >= mr.get_mod) {\n            v\
    \ -= mr.get_mod();\n        }\n\n        return (*this);\n    }\n\n    mint& operator*=(const\
    \ mint& r) {\n        v = mr.mult(v, r.v);\n        return (*this);\n    }\n\n\
    \    mint operator+(const mint& r) { return mint(*this) += r; }\n    mint operator-(const\
    \ mint& r) { return mint(*this) -= r; }\n    mint operator*(const mint& r) { return\
    \ mint(*this) *= r; }\n\n    mint& operator=(const T& v_) {\n        (*this) =\
    \ mint(v_);\n        return (*this);\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n\
    \    friend std::istream& operator>>(std::istream& is, mint& mt) {\n        T\
    \ v_;\n        is >> v_;\n        mt = v_;\n        return is;\n    }\n    template\
    \ <typename P> mint pow(P e) const {\n        assert(e >= 0);\n        mint res(1),\
    \ base(*this);\n\n        while (e) {\n            if (e & 1) {\n            \
    \    res *= base;\n            }\n            e >>= 1;\n            base *= base;\n\
    \        }\n        return res;\n    }\n    mint inv() const { return pow(mod\
    \ - 2); }\n\n    mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n    mint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n    mint& operator/=(T r) { return (*this) /= mint(r); }\n    friend mint\
    \ operator/(const mint& l, T r) { return mint(l) /= r; }\n    friend mint operator/(T\
    \ l, const mint& r) { return mint(l) /= r; }\n};\ntemplate <typename T, typename\
    \ LargeT, int id>\nT dynamic_modint<T, LargeT, id>::mod;\ntemplate <typename T,\
    \ typename LargeT, int id>\ninternal::MontgomeryReduction64<T, LargeT> dynamic_modint<T,\
    \ LargeT, id>::mr;\n\n/// @brief dynamic modint(\u52D5\u7684modint)\n/// @docs\
    \ docs/math/dynamic_modint.md"
  dependsOn:
  - internal/barrett.hpp
  - internal/montgomery.hpp
  isVerificationFile: false
  path: math/dynamic_modint.hpp
  requiredBy:
  - math/mod_log.hpp
  - math/rho.hpp
  - math/miller.hpp
  - math/phi_function.hpp
  - math/primitive_root.hpp
  timestamp: '2023-04-07 14:59:40+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yuki/No-3030.test.cpp
documentation_of: math/dynamic_modint.hpp
layout: document
redirect_from:
- /library/math/dynamic_modint.hpp
- /library/math/dynamic_modint.hpp.html
title: "dynamic modint(\u52D5\u7684modint)"
---
