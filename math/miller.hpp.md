---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/barrett.hpp
    title: barrett reduction
  - icon: ':question:'
    path: math/dynamic_modint.hpp
    title: dynamic_modint(64bit)
  - icon: ':question:'
    path: math/montgomery.hpp
    title: MontgomeryReduction
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\\phi \u95A2\u6570)"
  - icon: ':x:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':question:'
    path: math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  - icon: ':x:'
    path: test/yuki/No-3030.test.cpp
    title: test/yuki/No-3030.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
    links: []
  bundledCode: "#line 2 \"math/barrett.hpp\"\nnamespace internal {\n\t///@brief barrett\
    \ reduction\n\tclass barrett {\n\t\tusing u32 = uint32_t;\n\t\tusing u64 = uint64_t;\n\
    \n\t\tu64 m;\n\t\tu64 im;\n\tpublic:\n\t\texplicit barrett() = default;\n\t\t\
    explicit barrett(u64 m_) :m(m_), im((u64)(long double)static_cast<u64>(-1) / m_\
    \ + 1) {}\n\n\t\tu64 get_mod() const { return m; }\n\t\tu64 reduce(int64_t a)const{\n\
    \        \tif (a < 0) return m - reduce(-a);\n            u64 q = ((__uint128_t)a\
    \ * im) >> 64;\n            a -= m * q;\n            if (a >= m) a -= m;\n   \
    \         return a;\n        }\n\t\tu64 mul(u64 a, u64 b) {\n\t\t\tif (a == 0\
    \ || b == 0) {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tu64 z = a;\n\t\t\tz *= b;\n\t\
    \t\tu64 x = (u64)(((__uint128_t)(z)*im) >> 64);\n\n\t\t\tu32 v = (u32)(z - x *\
    \ m);\n\n\t\t\tif (v >= m)v += m;\n\t\t\treturn v;\n\t\t}\n\t};\n}\n#line 2 \"\
    math/montgomery.hpp\"\nnamespace internal {\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n    using i32 = int32_t;\n    using i64 = int64_t;\n    using\
    \ u128 = __uint128_t;\n    using i128 = __int128_t;\n    /// @brief MontgomeryReduction\n\
    \    template<typename T,typename LargeT>\n    class MontgomeryReduction64 {\n\
    \        static constexpr int lg = numeric_limits<T>::digits;\n        T mod,\
    \ r, r2, minv;\n        T calc_inv() {\n            T t = 0, res = 0;\n      \
    \      for (int i = 0; i < lg; i++) {\n                if (~t & 1) {\n       \
    \             t += mod;\n                    res += static_cast<T>(1) << i;\n\
    \                }\n                t >>= 1;\n            }\n            return\
    \ res;\n        }\n\n\n    public:\n        MontgomeryReduction64() = default;\n\
    \        constexpr T get_mod() { return mod; }\n        constexpr int get_lg()\
    \ { return lg; }\n\n\n        void set_mod(const T& m) {\n            assert(m\
    \ > 0);\n            assert(m & 1);\n\n            mod = m;\n\n            r =\
    \ (-static_cast<T>(mod)) % mod;\n            r2 = (-static_cast<LargeT>(mod))\
    \ % mod;\n            minv = calc_inv();\n        }\n\n\n        T reduce(LargeT\
    \ x) const {\n            u64 res = (x + static_cast<LargeT>(static_cast<T>(x)\
    \ * minv) * mod) >> lg;\n\n            if (res >= mod)res -= mod;\n          \
    \  return res;\n        }\n\n        T generate(LargeT x) {\n            return\
    \ reduce(x * r2);\n        }\n\n        T mult(T x, T y) {\n            return\
    \ reduce(static_cast<LargeT>(x) * y);\n        }\n    };\n};\n#line 4 \"math/dynamic_modint.hpp\"\
    \ntemplate<int id=-1>\nclass barrett_modint {\n\tusing u32 = uint32_t;\n\tusing\
    \ u64 = uint64_t;\n\n\tusing i32 = int32_t;\n\tusing i64 = int64_t;\n\tusing br\
    \ = internal::barrett;\n\n\tstatic br brt;\n\tstatic u32 mod;\n\tu32 v;\t//value\n\
    public:\n\tstatic void set_mod(u32 mod_) {\n\t\tbrt = br(mod_);\n\t\tmod = mod_;\n\
    \t}\npublic:\n\texplicit constexpr barrett_modint() :v(0) { assert(mod); }\t//mod\u304C\
    \u6C7A\u5B9A\u6E08\u307F\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n\texplicit\
    \ constexpr barrett_modint(i64 v_) :v(brt.reduce(v_)) { assert(mod); }\t\n\n\t\
    u32 val() const { return v; }\n    static u32 get_mod() { return mod; }\n    using\
    \ mint = barrett_modint;\n\n\t//operators\n\tconstexpr mint& operator=(i64 r)\
    \ {\n\t\tv = brt.reduce(r); \n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator+=(const\
    \ mint& r) {\n\t\tv += r.v;\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\t\
    return (*this);\n\t}\n\tconstexpr mint& operator-=(const mint&r) {\n\t\tv += mod\
    \ - r.v;\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator*=(const mint& r) {\n\t\tv = brt.mul(v, r.v);\n\
    \t\treturn (*this);\n\t}\n\n\tconstexpr mint operator+(const mint& r) const {\
    \ return mint(*this) += r; }\n\tconstexpr mint operator-(const mint& r) const\
    \ { return mint(*this) -= r; }\n\tconstexpr mint operator*(const mint& r) const\
    \ { return mint(*this) *= r; }\n\n\n\n\tconstexpr mint& operator+= (i64 r) { return\
    \ (*this) += mint(r); }\n\tconstexpr mint& operator-= (i64 r) { return (*this)\
    \ -= mint(r); }\n\tconstexpr mint& operator*= (i64 r) { return (*this) *= mint(r);\
    \ }\n\n\tfriend mint operator+(i64 l, const mint& r) { return mint(l) += r; }\n\
    \tfriend mint operator+(const mint& l, i64 r) { return mint(l) += r; }\n\tfriend\
    \ mint operator-(i64 l, const mint& r) { return mint(l) -= r; }\n\tfriend mint\
    \ operator-(const mint& l, i64 r) { return mint(l) -= r; }\n\tfriend mint operator*(i64\
    \ l, const mint& r) { return mint(l) *= r; }\n\tfriend mint operator*(const mint&\
    \ l, i64 r) { return mint(l) += r; }\n\n\n\tfriend ostream& operator<<(ostream&\
    \ os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\
    \t\treturn is;\n\t}\n\tconstexpr mint pow(u64 e) const {\n\t\tmint res(1), base(*this);\n\
    \n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tres *= base;\n\t\t\t}\n\t\t\te\
    \ >>= 1;\n\t\t\tbase *= base;\n\t\t}\n\t\treturn res;\n\t}\n\tconstexpr mint inv()\
    \ const {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const mint& r)\
    \ { return (*this) *= r.inv(); }\n\tmint operator/(const mint& r) const { return\
    \ mint(*this) *= r.inv(); }\n\tmint& operator/=(i64 r) { return (*this) /= mint(r);\
    \ }\n\tfriend mint operator/(const mint& l, i64 r) { return mint(l) /= r; }\n\t\
    friend mint operator/(i64 l, const mint& r) { return mint(l) /= r; }\n};\ntemplate<int\
    \ id>typename barrett_modint<id>::u32 barrett_modint<id>::mod;\ntemplate<int id>typename\
    \ barrett_modint<id>::br barrett_modint<id>::brt;\n\n\n/// @brief dynamic_modint(64bit)\n\
    /// @tparam T \u578B(64bit,32bit\u306A\u3069)\n/// @tparam LargeT \u7A4D\u304C\
    \u53CE\u307E\u3063\u3066\u304F\u308C\u308B\u578B\n/// @note T,LargeT\u306E\u3044\
    \u305A\u308C\u3082unsigned\u3067\u6E21\u3059\ntemplate <typename T = uint32_t,\
    \ typename LargeT = uint64_t, int id = -1>\nclass dynamic_modint {\n        static\
    \ T mod;\n        static internal::MontgomeryReduction64<T, LargeT> mr;\n\n  \
    \    public:\n        static void set_mod(T mod_) {\n                mr.set_mod(mod_);\n\
    \                mod = mod_;\n        }\n\n        static T get_mod() { return\
    \ mod; }\n\n      private:\n        T v;\n      public:\n        dynamic_modint(T\
    \ v_ = 0) {\n                assert(mod);\n                v = mr.generate(v_);\n\
    \        }\n        T val() const { return mr.reduce(v); }\n\n        using mint\
    \ = dynamic_modint<T, LargeT>;\n        mint& operator+=(const mint& r) {\n  \
    \              v += r.v;\n                if (v >= mr.get_mod()) {\n         \
    \               v -= mr.get_mod();\n                }\n\n                return\
    \ (*this);\n        }\n\n        mint& operator-=(const mint& r) {\n         \
    \       v += mr.get_mod() - r.v;\n                if (v >= mr.get_mod) {\n   \
    \                     v -= mr.get_mod();\n                }\n\n              \
    \  return (*this);\n        }\n\n        mint& operator*=(const mint& r) {\n \
    \               v = mr.mult(v, r.v);\n                return (*this);\n      \
    \  }\n\n        mint operator+(const mint& r) { return mint(*this) += r; }\n \
    \       mint operator-(const mint& r) { return mint(*this) -= r; }\n        mint\
    \ operator*(const mint& r) { return mint(*this) *= r; }\n\n        mint& operator=(const\
    \ T& v_) {\n                (*this) = mint(v_);\n                return (*this);\n\
    \        }\n\n        friend ostream& operator<<(ostream& os, const mint& mt)\
    \ {\n                os << mt.val();\n                return os;\n        }\n\
    \        friend istream& operator>>(istream& is, mint& mt) {\n               \
    \ T v_;\n                is >> v_;\n                mt = v_;\n               \
    \ return is;\n        }\n        template <typename P> mint pow(P e) const {\n\
    \                assert(e >= 0);\n                mint res(1), base(*this);\n\n\
    \                while (e) {\n                        if (e & 1) {\n         \
    \                       res *= base;\n                        }\n            \
    \            e >>= 1;\n                        base *= base;\n               \
    \ }\n                return res;\n        }\n        mint inv() const { return\
    \ pow(mod - 2); }\n\n        mint& operator/=(const mint& r) { return (*this)\
    \ *= r.inv(); }\n        mint operator/(const mint& r) const { return mint(*this)\
    \ *= r.inv(); }\n        mint& operator/=(T r) { return (*this) /= mint(r); }\n\
    \        friend mint operator/(const mint& l, T r) {\n                return mint(l)\
    \ /= r;\n        }\n        friend mint operator/(T l, const mint& r) {\n    \
    \            return mint(l) /= r;\n        }\n};\ntemplate<typename T, typename\
    \ LargeT,int id>T dynamic_modint<T, LargeT,id>::mod;\ntemplate<typename T,typename\
    \ LargeT,int id>internal::MontgomeryReduction64<T,LargeT> dynamic_modint<T,LargeT,id>::mr;\n\
    \n\n///@brief dynamic modint(\u52D5\u7684modint)\n///@docs docs/math/dynamic_modint.md\n\
    #line 3 \"math/miller.hpp\"\nnamespace prime {\n    namespace miller {\n     \
    \   using i128 = __int128_t;\n        using u128 = __uint128_t;\n        using\
    \ u64 = uint64_t;\n        using u32 = uint32_t;\n\n        template<typename\
    \ mint>\n        bool inline miller_rabin(u64 n, const u64 bases[], int length)\
    \ {\n            u64 d = n - 1;\n\n            while (~d & 1) {\n            \
    \    d >>= 1;\n            }\n\n            u64 rev = n - 1;\n            if (mint::get_mod()\
    \ != n) {\n                mint::set_mod(n);\n            }\n            for (int\
    \ i = 0; i < length; i++) {\n                u64 a = bases[i];\n\n           \
    \     if (n <= a) {\n                    return true;\n                }\n   \
    \             u64 t = d;\n                mint y = mint(a).pow(t);\n         \
    \       while (t != n - 1 && y.val() != 1 && y.val() != rev) {\n             \
    \       y *= y;\n                    t <<= 1;\n                }\n\n         \
    \       if (y.val() != rev && (~t & 1))return false;\n            }\n        \
    \    return true;\n        }\n\n\n        constexpr u64 bases_int[3] = { 2, 7,\
    \ 61 };  // int\u3060\u3068\u30012,7,61\u3067\u5341\u5206\n        constexpr u64\
    \ bases_ll[7] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };\n      \
    \  constexpr bool is_prime(u64 n) {\n            if (n < 2) {\n              \
    \  return false;\n            }\n            else if (n == 2) {\n            \
    \    return true;\n            }\n            else if (~n & 1) {\n           \
    \     return false;\n            }\n            if (n < (1ul << 31)) {\n     \
    \           return miller_rabin<barrett_modint<-1>>(n, bases_int, 3);\n      \
    \      }\n            else {\n                return miller_rabin<dynamic_modint<u64,u128,-1>>(n,\
    \ bases_ll, 7);\n            }\n        }\n    };\n};\n///@brief MillerRabin\u306E\
    \u7D20\u6570\u5224\u5B9A\n"
  code: "#pragma once\n#include\"math/dynamic_modint.hpp\"\nnamespace prime {\n  \
    \  namespace miller {\n        using i128 = __int128_t;\n        using u128 =\
    \ __uint128_t;\n        using u64 = uint64_t;\n        using u32 = uint32_t;\n\
    \n        template<typename mint>\n        bool inline miller_rabin(u64 n, const\
    \ u64 bases[], int length) {\n            u64 d = n - 1;\n\n            while\
    \ (~d & 1) {\n                d >>= 1;\n            }\n\n            u64 rev =\
    \ n - 1;\n            if (mint::get_mod() != n) {\n                mint::set_mod(n);\n\
    \            }\n            for (int i = 0; i < length; i++) {\n             \
    \   u64 a = bases[i];\n\n                if (n <= a) {\n                    return\
    \ true;\n                }\n                u64 t = d;\n                mint y\
    \ = mint(a).pow(t);\n                while (t != n - 1 && y.val() != 1 && y.val()\
    \ != rev) {\n                    y *= y;\n                    t <<= 1;\n     \
    \           }\n\n                if (y.val() != rev && (~t & 1))return false;\n\
    \            }\n            return true;\n        }\n\n\n        constexpr u64\
    \ bases_int[3] = { 2, 7, 61 };  // int\u3060\u3068\u30012,7,61\u3067\u5341\u5206\
    \n        constexpr u64 bases_ll[7] = { 2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022 };\n        constexpr bool is_prime(u64 n) {\n            if (n <\
    \ 2) {\n                return false;\n            }\n            else if (n ==\
    \ 2) {\n                return true;\n            }\n            else if (~n &\
    \ 1) {\n                return false;\n            }\n            if (n < (1ul\
    \ << 31)) {\n                return miller_rabin<barrett_modint<-1>>(n, bases_int,\
    \ 3);\n            }\n            else {\n                return miller_rabin<dynamic_modint<u64,u128,-1>>(n,\
    \ bases_ll, 7);\n            }\n        }\n    };\n};\n///@brief MillerRabin\u306E\
    \u7D20\u6570\u5224\u5B9A"
  dependsOn:
  - math/dynamic_modint.hpp
  - math/barrett.hpp
  - math/montgomery.hpp
  isVerificationFile: false
  path: math/miller.hpp
  requiredBy:
  - math/rho.hpp
  - math/phi_function.hpp
  - math/primitive_root.hpp
  timestamp: '2023-04-05 12:24:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yuki/No-3030.test.cpp
documentation_of: math/miller.hpp
layout: document
redirect_from:
- /library/math/miller.hpp
- /library/math/miller.hpp.html
title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
---
