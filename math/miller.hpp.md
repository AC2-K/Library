---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: internal/barrett.hpp
    title: barrett reduction
  - icon: ':question:'
    path: internal/montgomery.hpp
    title: MontgomeryReduction
  - icon: ':question:'
    path: math/dynamic_modint.hpp
    title: "dynamic modint(\u52D5\u7684modint)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "$\\phi$ \u95A2\u6570"
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
  bundledCode: "#line 2 \"internal/barrett.hpp\"\n#include<iostream>\nnamespace library\
    \ {\nnamespace internal {\n/// @brief barrett reduction\nclass barrett {\n   \
    \ using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u64 m;\n    u64 im;\n\
    \n  public:\n    explicit barrett() = default;\n    constexpr explicit barrett(u64\
    \ m_)\n        : m(m_), im((u64)(long double)static_cast<u64>(-1) / m_ + 1) {}\n\
    \n    inline u64 get_mod() const { return m; }\n    inline u64 reduce(int64_t\
    \ a) const {\n        if (a < 0) return m - reduce(-a);\n        u64 q = ((__uint128_t)a\
    \ * im) >> 64;\n        a -= m * q;\n        if (a >= m) a -= m;\n        return\
    \ a;\n    }\n    inline u64 mul(u64 a, u64 b) {\n        if (a == 0 || b == 0)\
    \ {\n            return 0;\n        }\n        u64 z = a;\n        z *= b;\n \
    \       u64 x = (u64)(((__uint128_t)(z)*im) >> 64);\n\n        u32 v = (u32)(z\
    \ - x * m);\n\n        if (v >= m) v += m;\n        return v;\n    }\n};\n}; \
    \ // namespace internal\n};  // namespace library\n#line 3 \"internal/montgomery.hpp\"\
    \nnamespace library {\nnamespace internal {\nusing u32 = uint32_t;\nusing u64\
    \ = uint64_t;\nusing i32 = int32_t;\nusing i64 = int64_t;\nusing u128 = __uint128_t;\n\
    using i128 = __int128_t;\n/// @brief MontgomeryReduction\ntemplate <typename T,\
    \ typename LargeT>\nclass MontgomeryReduction {\n    static constexpr int lg =\
    \ std::numeric_limits<T>::digits;\n    T mod, r, r2, minv;\n    T calc_inv() {\n\
    \        T t = 0, res = 0;\n        for (int i = 0; i < lg; i++) {\n         \
    \   if (~t & 1) {\n                t += mod;\n                res += static_cast<T>(1)\
    \ << i;\n            }\n            t >>= 1;\n        }\n        return res;\n\
    \    }\n\n  public:\n    MontgomeryReduction() = default;\n    constexpr T get_mod()\
    \ { return mod; }\n    constexpr int get_lg() { return lg; }\n\n    void set_mod(const\
    \ T& m) {\n\n        assert(m > 0);\n        assert(m & 1);\n\n        mod = m;\n\
    \n        r = (-static_cast<T>(mod)) % mod;\n        r2 = (-static_cast<LargeT>(mod))\
    \ % mod;\n        minv = calc_inv();\n    }\n\n    T reduce(LargeT x) const {\n\
    \        u64 res =\n            (x + static_cast<LargeT>(static_cast<T>(x) * minv)\
    \ * mod) >> lg;\n\n        if (res >= mod) res -= mod;\n        return res;\n\
    \    }\n\n    T generate(LargeT x) { return reduce(x * r2); }\n\n    T mult(T\
    \ x, T y) { return reduce(static_cast<LargeT>(x) * y); }\n};\n};  // namespace\
    \ internal\n};  // namespace library\n#line 4 \"math/dynamic_modint.hpp\"\n\n\
    namespace library{\ntemplate<int id=-1>\nclass barrett_modint {\n\tusing u32 =\
    \ uint32_t;\n\tusing u64 = uint64_t;\n\n\tusing i32 = int32_t;\n\tusing i64 =\
    \ int64_t;\n\tusing br = internal::barrett;\n\n\tstatic br brt;\n\tstatic u32\
    \ mod;\n\tu32 v;\t//value\npublic:\n\tstatic void set_mod(u32 mod_) {\n\t\tbrt\
    \ = br(mod_);\n\t\tmod = mod_;\n\t}\npublic:\n\texplicit constexpr barrett_modint()\
    \ :v(0) { assert(mod); }\t//mod\u304C\u6C7A\u5B9A\u6E08\u307F\u3067\u3042\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\n\texplicit constexpr barrett_modint(i64 v_) :v(brt.reduce(v_))\
    \ { assert(mod); }\t\n\n\tu32 val() const { return v; }\n    static u32 get_mod()\
    \ { return mod; }\n    using mint = barrett_modint<id>;\n\n\t//operators\n\tconstexpr\
    \ mint& operator=(i64 r) {\n\t\tv = brt.reduce(r); \n\t\treturn (*this);\n\t}\n\
    \tconstexpr mint& operator+=(const mint& r) {\n\t\tv += r.v;\n\t\tif (v >= mod)\
    \ {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const\
    \ mint&r) {\n\t\tv += mod - r.v;\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\
    \n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator*=(const mint& r) {\n\t\t\
    v = brt.mul(v, r.v);\n\t\treturn (*this);\n\t}\n\n\tconstexpr mint operator+(const\
    \ mint& r) const { return mint(*this) += r; }\n\tconstexpr mint operator-(const\
    \ mint& r) const { return mint(*this) -= r; }\n\tconstexpr mint operator*(const\
    \ mint& r) const { return mint(*this) *= r; }\n\n\n\n\tconstexpr mint& operator+=\
    \ (i64 r) { return (*this) += mint(r); }\n\tconstexpr mint& operator-= (i64 r)\
    \ { return (*this) -= mint(r); }\n\tconstexpr mint& operator*= (i64 r) { return\
    \ (*this) *= mint(r); }\n\n\tfriend mint operator+(i64 l, const mint& r) { return\
    \ mint(l) += r; }\n\tfriend mint operator+(const mint& l, i64 r) { return mint(l)\
    \ += r; }\n\tfriend mint operator-(i64 l, const mint& r) { return mint(l) -= r;\
    \ }\n\tfriend mint operator-(const mint& l, i64 r) { return mint(l) -= r; }\n\t\
    friend mint operator*(i64 l, const mint& r) { return mint(l) *= r; }\n\tfriend\
    \ mint operator*(const mint& l, i64 r) { return mint(l) += r; }\n\n\n\tfriend\
    \ std::ostream& operator<<(std::ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\
    \t\treturn os;\n\t}\n\tfriend std::istream& operator>>(std::istream& is, mint&\
    \ mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n\tconstexpr\
    \ mint pow(u64 e) const {\n\t\tmint res(1), base(*this);\n\n\t\twhile (e) {\n\t\
    \t\tif (e & 1) {\n\t\t\t\tres *= base;\n\t\t\t}\n\t\t\te >>= 1;\n\t\t\tbase *=\
    \ base;\n\t\t}\n\t\treturn res;\n\t}\n\tconstexpr mint inv() const {\n\t\treturn\
    \ pow(mod - 2);\n\t}\n\n\tmint& operator/=(const mint& r) { return (*this) *=\
    \ r.inv(); }\n\tmint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n\tmint& operator/=(i64 r) { return (*this) /= mint(r); }\n\tfriend mint operator/(const\
    \ mint& l, i64 r) { return mint(l) /= r; }\n\tfriend mint operator/(i64 l, const\
    \ mint& r) { return mint(l) /= r; }\n};\n};  // namespace library\ntemplate <int\
    \ id> typename library::barrett_modint<id>::u32 library::barrett_modint<id>::mod;\n\
    template<int id>typename library::barrett_modint<id>::br library::barrett_modint<id>::brt;\n\
    \nnamespace library{\n\ntemplate <typename T = uint32_t, typename LargeT = uint64_t,\
    \ int id = -1>\nclass dynamic_modint {\n        static T mod;\n        static\
    \ internal::MontgomeryReduction<T, LargeT> mr;\n\n      public:\n        static\
    \ void set_mod(T mod_) {\n            mr.set_mod(mod_);\n            mod = mod_;\n\
    \        }\n\n        static T get_mod() { return mod; }\n\n      private:\n \
    \       T v;\n      public:\n        dynamic_modint(T v_ = 0) {\n            \
    \    assert(mod);\n                v = mr.generate(v_);\n        }\n        T\
    \ val() const { return mr.reduce(v); }\n\n        using mint = dynamic_modint<T,\
    \ LargeT,id>;\n        mint& operator+=(const mint& r) {\n                v +=\
    \ r.v;\n                if (v >= mr.get_mod()) {\n                        v -=\
    \ mr.get_mod();\n                }\n\n                return (*this);\n      \
    \  }\n\n        mint& operator-=(const mint& r) {\n                v += mr.get_mod()\
    \ - r.v;\n                if (v >= mr.get_mod) {\n                        v -=\
    \ mr.get_mod();\n                }\n\n                return (*this);\n      \
    \  }\n\n        mint& operator*=(const mint& r) {\n                v = mr.mult(v,\
    \ r.v);\n                return (*this);\n        }\n\n        mint operator+(const\
    \ mint& r) { return mint(*this) += r; }\n        mint operator-(const mint& r)\
    \ { return mint(*this) -= r; }\n        mint operator*(const mint& r) { return\
    \ mint(*this) *= r; }\n\n        mint& operator=(const T& v_) {\n            \
    \    (*this) = mint(v_);\n                return (*this);\n        }\n\n     \
    \   friend std::ostream& operator<<(std::ostream& os, const mint& mt) {\n    \
    \            os << mt.val();\n                return os;\n        }\n        friend\
    \ std::istream& operator>>(std::istream& is, mint& mt) {\n                T v_;\n\
    \                is >> v_;\n                mt = v_;\n                return is;\n\
    \        }\n        template <typename P> mint pow(P e) const {\n            \
    \    assert(e >= 0);\n                mint res(1), base(*this);\n\n          \
    \      while (e) {\n                        if (e & 1) {\n                   \
    \             res *= base;\n                        }\n                      \
    \  e >>= 1;\n                        base *= base;\n                }\n      \
    \          return res;\n        }\n        mint inv() const { return pow(mod -\
    \ 2); }\n\n        mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n        mint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n        mint& operator/=(T r) { return (*this) /= mint(r); }\n        friend\
    \ mint operator/(const mint& l, T r) {\n                return mint(l) /= r;\n\
    \        }\n        friend mint operator/(T l, const mint& r) {\n            \
    \    return mint(l) /= r;\n        }\n};\n\n};  // namespace library\n\ntemplate\
    \ <typename T, typename LargeT, int id>\nT library::dynamic_modint<T, LargeT,\
    \ id>::mod;\ntemplate <typename T, typename LargeT, int id>\nlibrary::internal::MontgomeryReduction<T,\
    \ LargeT>\n    library::dynamic_modint<T, LargeT, id>::mr;\n\n///@brief dynamic\
    \ modint(\u52D5\u7684modint)\n///@docs docs/math/dynamic_modint.md\n#line 3 \"\
    math/miller.hpp\"\nnamespace library {\n    namespace miller {\n        using\
    \ i128 = __int128_t;\n        using u128 = __uint128_t;\n        using u64 = uint64_t;\n\
    \        using u32 = uint32_t;\n\n        template<typename mint>\n        bool\
    \ miller_rabin(u64 n, const u64 bases[], int length) {\n            u64 d = n\
    \ - 1;\n\n            while (~d & 1) {\n                d >>= 1;\n           \
    \ }\n\n            u64 rev = n - 1;\n            if (mint::get_mod() != n) {\n\
    \                mint::set_mod(n);\n            }\n            for (int i = 0;\
    \ i < length; i++) {\n                u64 a = bases[i];\n\n                if\
    \ (n <= a) {\n                    return true;\n                }\n          \
    \      u64 t = d;\n                mint y = mint(a).pow(t);\n                while\
    \ (t != n - 1 && y.val() != 1 && y.val() != rev) {\n                    y *= y;\n\
    \                    t <<= 1;\n                }\n\n                if (y.val()\
    \ != rev && (~t & 1))return false;\n            }\n            return true;\n\
    \        }\n\n\n        constexpr u64 bases_int[3] = { 2, 7, 61 };  // int\u3060\
    \u3068\u30012,7,61\u3067\u5341\u5206\n        constexpr u64 bases_ll[7] = { 2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022 };\n        bool is_prime(u64\
    \ n) {\n            if (n < 2) {\n                return false;\n            }\n\
    \            else if (n == 2) {\n                return true;\n            }\n\
    \            else if (~n & 1) {\n                return false;\n            }\n\
    \            if (n < (1ul << 31)) {\n                return miller_rabin<barrett_modint<-1>>(n,\
    \ bases_int, 3);\n            }\n            else {\n                return miller_rabin<dynamic_modint<u64,u128,-1>>(n,\
    \ bases_ll, 7);\n            }\n        }\n    };\n};\n///@brief MillerRabin\u306E\
    \u7D20\u6570\u5224\u5B9A\n"
  code: "#pragma once\n#include\"math/dynamic_modint.hpp\"\nnamespace library {\n\
    \    namespace miller {\n        using i128 = __int128_t;\n        using u128\
    \ = __uint128_t;\n        using u64 = uint64_t;\n        using u32 = uint32_t;\n\
    \n        template<typename mint>\n        bool miller_rabin(u64 n, const u64\
    \ bases[], int length) {\n            u64 d = n - 1;\n\n            while (~d\
    \ & 1) {\n                d >>= 1;\n            }\n\n            u64 rev = n -\
    \ 1;\n            if (mint::get_mod() != n) {\n                mint::set_mod(n);\n\
    \            }\n            for (int i = 0; i < length; i++) {\n             \
    \   u64 a = bases[i];\n\n                if (n <= a) {\n                    return\
    \ true;\n                }\n                u64 t = d;\n                mint y\
    \ = mint(a).pow(t);\n                while (t != n - 1 && y.val() != 1 && y.val()\
    \ != rev) {\n                    y *= y;\n                    t <<= 1;\n     \
    \           }\n\n                if (y.val() != rev && (~t & 1))return false;\n\
    \            }\n            return true;\n        }\n\n\n        constexpr u64\
    \ bases_int[3] = { 2, 7, 61 };  // int\u3060\u3068\u30012,7,61\u3067\u5341\u5206\
    \n        constexpr u64 bases_ll[7] = { 2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022 };\n        bool is_prime(u64 n) {\n            if (n < 2) {\n  \
    \              return false;\n            }\n            else if (n == 2) {\n\
    \                return true;\n            }\n            else if (~n & 1) {\n\
    \                return false;\n            }\n            if (n < (1ul << 31))\
    \ {\n                return miller_rabin<barrett_modint<-1>>(n, bases_int, 3);\n\
    \            }\n            else {\n                return miller_rabin<dynamic_modint<u64,u128,-1>>(n,\
    \ bases_ll, 7);\n            }\n        }\n    };\n};\n///@brief MillerRabin\u306E\
    \u7D20\u6570\u5224\u5B9A"
  dependsOn:
  - math/dynamic_modint.hpp
  - internal/barrett.hpp
  - internal/montgomery.hpp
  isVerificationFile: false
  path: math/miller.hpp
  requiredBy:
  - math/rho.hpp
  - math/phi_function.hpp
  - math/primitive_root.hpp
  timestamp: '2023-04-06 21:43:06+09:00'
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
