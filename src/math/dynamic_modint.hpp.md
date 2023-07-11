---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/barrett.hpp
    title: Barrett Reduction
  - icon: ':question:'
    path: src/internal/montgomery.hpp
    title: Montgomery Reduction
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/math/miller.hpp
    title: "MillerRabin\u7D20\u6570\u5224\u5B9A\u6CD5"
  - icon: ':heavy_check_mark:'
    path: src/math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  - icon: ':heavy_check_mark:'
    path: src/math/phi_function.hpp
    title: "Euler\u306E $\\phi$ \u95A2\u6570"
  - icon: ':x:'
    path: src/math/primitive_root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':question:'
    path: src/math/rho.hpp
    title: "Pollard Rho \u7D20\u56E0\u6570\u5206\u89E3\u6CD5"
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
  - icon: ':x:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
    title: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
  - icon: ':x:'
    path: test/yuki/No3030.test.cpp
    title: test/yuki/No3030.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/math/dynamic_modint.md
    document_title: "\u52D5\u7684modint"
    links: []
  bundledCode: "#line 2 \"src/math/dynamic_modint.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#line 2 \"src/internal/barrett.hpp\"\n#include <cstdint>\nnamespace\
    \ kyopro {\nnamespace internal {\n\n/**\n * @brief Barrett Reduction\n */\nclass\
    \ barrett {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n    using u128\
    \ = __uint128_t;\n\n    u32 m;\n    u64 im;\n\npublic:\n    constexpr explicit\
    \ barrett() : m(0), im(0) {}\n    constexpr explicit barrett(u32 m)\n        :\
    \ m(m), im(static_cast<u64>(-1) / m + 1) {}\n\n    constexpr u32 get_mod() const\
    \ { return m; }\n    constexpr u32 reduce(u32 a) const { return mul(1, a); }\n\
    \    constexpr u32 mul(u32 a, u32 b) const {\n        u64 z = (u64)a * b;\n  \
    \      u64 x = (u64)(((u128)(z)*im) >> 64);\n        u64 y = x * m;\n        return\
    \ (u32)(z - y + (z < y ? m : 0));\n    }\n};\n};  // namespace internal\n};  //\
    \ namespace kyopro\n\n/**\n * @ref\n * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */\n#line 3 \"src/internal/montgomery.hpp\"\n#include <limits>\n#include <numeric>\n\
    #line 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\nnamespace kyopro\
    \ {\nnamespace internal {\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\ntemplate <typename... Args> struct first_enabled {};\n\ntemplate <typename\
    \ T, typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...>\
    \ {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct\
    \ first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt> struct int_least\
    \ {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __int8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __int16_t>,\n                                 std::enable_if<dgt <= 32, __int32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __int64_t>,\n    \
    \                             std::enable_if<dgt <= 128, __int128_t> >;\n};\n\
    template <int dgt> struct uint_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __uint8_t>,\n              \
    \                   std::enable_if<dgt <= 16, __uint16_t>,\n                 \
    \                std::enable_if<dgt <= 32, __uint32_t>,\n                    \
    \             std::enable_if<dgt <= 64, __uint64_t>,\n                       \
    \          std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\ntemplate <int dgt>\
    \ using int_least_t = typename int_least<dgt>::type;\ntemplate <int dgt> using\
    \ uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename T>\nusing\
    \ double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\ntemplate\
    \ <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    };  // namespace internal\n};  // namespace kyopro\n#line 6 \"src/internal/montgomery.hpp\"\
    \nnamespace kyopro {\nnamespace internal {\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i32 = int32_t;\nusing i64 = int64_t;\nusing u128 = __uint128_t;\n\
    using i128 = __int128_t;\n\n/**\n * @brief Montgomery Reduction\n */\ntemplate\
    \ <typename T> class Montgomery {\n    static constexpr int lg = std::numeric_limits<T>::digits;\n\
    \    using LargeT = internal::double_size_uint_t<T>;\n    T mod, r, r2, minv;\n\
    \    T inv() {\n        T t = 0, res = 0;\n        for (int i = 0; i < lg; ++i)\
    \ {\n            if (~t & 1) {\n                t += mod;\n                res\
    \ += static_cast<T>(1) << i;\n            }\n            t >>= 1;\n        }\n\
    \        return res;\n    }\n\npublic:\n    Montgomery() = default;\n    constexpr\
    \ T get_mod() { return mod; }\n\n    void set_mod(T m) {\n        assert(m);\n\
    \        assert(m & 1);\n\n        mod = m;\n\n        r = (-static_cast<T>(mod))\
    \ % mod;\n        r2 = (-static_cast<LargeT>(mod)) % mod;\n        minv = inv();\n\
    \    }\n\n    T reduce(LargeT x) const {\n        u64 res =\n            (x +\
    \ static_cast<LargeT>(static_cast<T>(x) * minv) * mod) >> lg;\n\n        if (res\
    \ >= mod) res -= mod;\n        return res;\n    }\n\n    T generate(LargeT x)\
    \ { return reduce(x * r2); }\n\n    T mul(T x, T y) { return reduce((LargeT)x\
    \ * y); }\n};\n};  // namespace internal\n};  // namespace kyopro\n#line 6 \"\
    src/math/dynamic_modint.hpp\"\nnamespace kyopro {\ntemplate <int id = -1> class\
    \ barrett_modint {\n    using mint = barrett_modint<id>;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    using i32 = int32_t;\n    using i64 = int64_t;\n\
    \    using br = internal::barrett;\n\n    static br brt;\n    u32 v;\n\npublic:\n\
    \    static void set_mod(u32 mod_) { brt = br(mod_); }\n\npublic:\n    explicit\
    \ constexpr barrett_modint() : v(0) { assert(mod()); }\n    explicit constexpr\
    \ barrett_modint(i64 v_) : v() {\n        assert(mod());\n        if (v_ < 0)\
    \ v_ = (i64)mod() - v_;\n        v = brt.reduce(v_);\n    }\n\n    u32 val() const\
    \ { return v; }\n    static u32 mod() { return brt.get_mod(); }\n    static mint\
    \ raw(u32 v) {\n        mint x;\n        x.v = v;\n        return x;\n    }\n\n\
    \    constexpr mint& operator++() {\n        ++v;\n        if (v == mod()) v =\
    \ 0;\n        return (*this);\n    }\n    constexpr mint& operator--() {\n   \
    \     if (v == 0) v = mod();\n        --v;\n        return (*this);\n    }\n \
    \   constexpr mint operator++(int) {\n        mint res(*this);\n        ++(*this);\n\
    \        return res;\n    }\n    constexpr mint operator--(int) {\n        mint\
    \ res(*this);\n        --(*this);\n        return res;\n    }\n\n    constexpr\
    \ mint& operator+=(const mint& r) {\n        v += r.v;\n        if (v >= mod())\
    \ v -= mod();\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ mint& r) {\n        v += mod() - r.v;\n        if (v >= mod()) {\n         \
    \   v -= mod();\n        }\n\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(const mint& r) {\n        v = brt.mul(v, r.v);\n        return (*this);\n\
    \    }\n    constexpr mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n       \
    \ return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n    constexpr mint& operator+=(i64 r) { return (*this) += mint(r); }\n\
    \    constexpr mint& operator-=(i64 r) { return (*this) -= mint(r); }\n    constexpr\
    \ mint& operator*=(i64 r) { return (*this) *= mint(r); }\n\n    friend mint operator+(i64\
    \ l, const mint& r) { return mint(l) += r; }\n    friend mint operator+(const\
    \ mint& l, i64 r) { return mint(l) += r; }\n    friend mint operator-(i64 l, const\
    \ mint& r) { return mint(l) -= r; }\n    friend mint operator-(const mint& l,\
    \ i64 r) { return mint(l) -= r; }\n    friend mint operator*(i64 l, const mint&\
    \ r) { return mint(l) *= r; }\n    friend mint operator*(const mint& l, i64 r)\
    \ { return mint(l) *= r; }\n\n    constexpr mint operator+() const { return *this;\
    \ }\n    constexpr mint operator-() const { return mint() - *this; }\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const mint& mt) {\n        os <<\
    \ mt.val();\n        return os;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n        i64 v_;\n        is >> v_;\n        mt = mint(v_);\n\
    \        return is;\n    }\n    template <typename T> mint pow(T e) const {\n\
    \        mint res(1), base(*this);\n\n        while (e) {\n            if (e &\
    \ 1) {\n                res *= base;\n            }\n            e >>= 1;\n  \
    \          base *= base;\n        }\n        return res;\n    }\n    constexpr\
    \ mint inv() const { return pow(mod() - 2); }\n};\n};  // namespace kyopro\ntemplate\
    \ <int id>\ntypename kyopro::barrett_modint<id>::br kyopro::barrett_modint<id>::brt;\n\
    \nnamespace kyopro {\ntemplate <typename T, int id = -1> class dynamic_modint\
    \ {\n    using LargeT = internal::double_size_uint_t<T>;\n    static T _mod;\n\
    \    static internal::Montgomery<T> mr;\n\npublic:\n    static void set_mod(T\
    \ mod_) {\n        mr.set_mod(mod_);\n        _mod = mod_;\n    }\n\n    static\
    \ T mod() { return _mod; }\n\nprivate:\n    T v;\n\npublic:\n    dynamic_modint(T\
    \ v_ = 0) {\n        assert(_mod);\n        v = mr.generate(v_);\n    }\n    T\
    \ val() const { return mr.reduce(v); }\n\n    using mint = dynamic_modint<T, id>;\n\
    \    mint& operator+=(const mint& r) {\n        v += r.v;\n        if (v >= mr.get_mod())\
    \ {\n            v -= mr.get_mod();\n        }\n\n        return (*this);\n  \
    \  }\n\n    mint& operator-=(const mint& r) {\n        v += mr.get_mod() - r.v;\n\
    \        if (v >= mr.get_mod) {\n            v -= mr.get_mod();\n        }\n\n\
    \        return (*this);\n    }\n\n    mint& operator*=(const mint& r) {\n   \
    \     v = mr.mul(v, r.v);\n        return (*this);\n    }\n\n    mint operator+(const\
    \ mint& r) { return mint(*this) += r; }\n    mint operator-(const mint& r) { return\
    \ mint(*this) -= r; }\n    mint operator*(const mint& r) { return mint(*this)\
    \ *= r; }\n\n    mint& operator=(const T& v_) {\n        (*this) = mint(v_);\n\
    \        return (*this);\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n\
    \    friend std::istream& operator>>(std::istream& is, mint& mt) {\n        T\
    \ v_;\n        is >> v_;\n        mt = v_;\n        return is;\n    }\n    template\
    \ <typename P> mint pow(P e) const {\n        assert(e >= 0);\n        mint res(1),\
    \ base(*this);\n\n        while (e) {\n            if (e & 1) {\n            \
    \    res *= base;\n            }\n            e >>= 1;\n            base *= base;\n\
    \        }\n        return res;\n    }\n    mint inv() const { return pow(mod()\
    \ - 2); }\n\n    mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n    mint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n    mint& operator/=(T r) { return (*this) /= mint(r); }\n    friend mint\
    \ operator/(const mint& l, T r) { return mint(l) /= r; }\n    friend mint operator/(T\
    \ l, const mint& r) { return mint(l) /= r; }\n};\n};  // namespace kyopro\ntemplate\
    \ <typename T, int id> T kyopro::dynamic_modint<T, id>::_mod;\ntemplate <typename\
    \ T, int id>\nkyopro::internal::Montgomery<T> kyopro::dynamic_modint<T, id>::mr;\n\
    \n/**\n * @brief \u52D5\u7684modint\n * @docs docs/math/dynamic_modint.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include \"../internal/barrett.hpp\"\
    \n#include \"../internal/montgomery.hpp\"\nnamespace kyopro {\ntemplate <int id\
    \ = -1> class barrett_modint {\n    using mint = barrett_modint<id>;\n    using\
    \ u32 = uint32_t;\n    using u64 = uint64_t;\n\n    using i32 = int32_t;\n   \
    \ using i64 = int64_t;\n    using br = internal::barrett;\n\n    static br brt;\n\
    \    u32 v;\n\npublic:\n    static void set_mod(u32 mod_) { brt = br(mod_); }\n\
    \npublic:\n    explicit constexpr barrett_modint() : v(0) { assert(mod()); }\n\
    \    explicit constexpr barrett_modint(i64 v_) : v() {\n        assert(mod());\n\
    \        if (v_ < 0) v_ = (i64)mod() - v_;\n        v = brt.reduce(v_);\n    }\n\
    \n    u32 val() const { return v; }\n    static u32 mod() { return brt.get_mod();\
    \ }\n    static mint raw(u32 v) {\n        mint x;\n        x.v = v;\n       \
    \ return x;\n    }\n\n    constexpr mint& operator++() {\n        ++v;\n     \
    \   if (v == mod()) v = 0;\n        return (*this);\n    }\n    constexpr mint&\
    \ operator--() {\n        if (v == 0) v = mod();\n        --v;\n        return\
    \ (*this);\n    }\n    constexpr mint operator++(int) {\n        mint res(*this);\n\
    \        ++(*this);\n        return res;\n    }\n    constexpr mint operator--(int)\
    \ {\n        mint res(*this);\n        --(*this);\n        return res;\n    }\n\
    \n    constexpr mint& operator+=(const mint& r) {\n        v += r.v;\n       \
    \ if (v >= mod()) v -= mod();\n        return (*this);\n    }\n    constexpr mint&\
    \ operator-=(const mint& r) {\n        v += mod() - r.v;\n        if (v >= mod())\
    \ {\n            v -= mod();\n        }\n\n        return (*this);\n    }\n  \
    \  constexpr mint& operator*=(const mint& r) {\n        v = brt.mul(v, r.v);\n\
    \        return (*this);\n    }\n    constexpr mint& operator/=(const mint& r)\
    \ { return (*this) *= r.inv(); }\n\n    friend mint operator+(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint\
    \ operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n\
    \    }\n    friend mint operator*(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n    friend bool\
    \ operator==(const mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n\
    \    }\n    friend bool operator!=(const mint& lhs, const mint& rhs) {\n     \
    \   return lhs._v != rhs._v;\n    }\n\n    constexpr mint& operator+=(i64 r) {\
    \ return (*this) += mint(r); }\n    constexpr mint& operator-=(i64 r) { return\
    \ (*this) -= mint(r); }\n    constexpr mint& operator*=(i64 r) { return (*this)\
    \ *= mint(r); }\n\n    friend mint operator+(i64 l, const mint& r) { return mint(l)\
    \ += r; }\n    friend mint operator+(const mint& l, i64 r) { return mint(l) +=\
    \ r; }\n    friend mint operator-(i64 l, const mint& r) { return mint(l) -= r;\
    \ }\n    friend mint operator-(const mint& l, i64 r) { return mint(l) -= r; }\n\
    \    friend mint operator*(i64 l, const mint& r) { return mint(l) *= r; }\n  \
    \  friend mint operator*(const mint& l, i64 r) { return mint(l) *= r; }\n\n  \
    \  constexpr mint operator+() const { return *this; }\n    constexpr mint operator-()\
    \ const { return mint() - *this; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n\
    \    friend std::istream& operator>>(std::istream& is, mint& mt) {\n        i64\
    \ v_;\n        is >> v_;\n        mt = mint(v_);\n        return is;\n    }\n\
    \    template <typename T> mint pow(T e) const {\n        mint res(1), base(*this);\n\
    \n        while (e) {\n            if (e & 1) {\n                res *= base;\n\
    \            }\n            e >>= 1;\n            base *= base;\n        }\n \
    \       return res;\n    }\n    constexpr mint inv() const { return pow(mod()\
    \ - 2); }\n};\n};  // namespace kyopro\ntemplate <int id>\ntypename kyopro::barrett_modint<id>::br\
    \ kyopro::barrett_modint<id>::brt;\n\nnamespace kyopro {\ntemplate <typename T,\
    \ int id = -1> class dynamic_modint {\n    using LargeT = internal::double_size_uint_t<T>;\n\
    \    static T _mod;\n    static internal::Montgomery<T> mr;\n\npublic:\n    static\
    \ void set_mod(T mod_) {\n        mr.set_mod(mod_);\n        _mod = mod_;\n  \
    \  }\n\n    static T mod() { return _mod; }\n\nprivate:\n    T v;\n\npublic:\n\
    \    dynamic_modint(T v_ = 0) {\n        assert(_mod);\n        v = mr.generate(v_);\n\
    \    }\n    T val() const { return mr.reduce(v); }\n\n    using mint = dynamic_modint<T,\
    \ id>;\n    mint& operator+=(const mint& r) {\n        v += r.v;\n        if (v\
    \ >= mr.get_mod()) {\n            v -= mr.get_mod();\n        }\n\n        return\
    \ (*this);\n    }\n\n    mint& operator-=(const mint& r) {\n        v += mr.get_mod()\
    \ - r.v;\n        if (v >= mr.get_mod) {\n            v -= mr.get_mod();\n   \
    \     }\n\n        return (*this);\n    }\n\n    mint& operator*=(const mint&\
    \ r) {\n        v = mr.mul(v, r.v);\n        return (*this);\n    }\n\n    mint\
    \ operator+(const mint& r) { return mint(*this) += r; }\n    mint operator-(const\
    \ mint& r) { return mint(*this) -= r; }\n    mint operator*(const mint& r) { return\
    \ mint(*this) *= r; }\n\n    mint& operator=(const T& v_) {\n        (*this) =\
    \ mint(v_);\n        return (*this);\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n\
    \    friend std::istream& operator>>(std::istream& is, mint& mt) {\n        T\
    \ v_;\n        is >> v_;\n        mt = v_;\n        return is;\n    }\n    template\
    \ <typename P> mint pow(P e) const {\n        assert(e >= 0);\n        mint res(1),\
    \ base(*this);\n\n        while (e) {\n            if (e & 1) {\n            \
    \    res *= base;\n            }\n            e >>= 1;\n            base *= base;\n\
    \        }\n        return res;\n    }\n    mint inv() const { return pow(mod()\
    \ - 2); }\n\n    mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n    mint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n    mint& operator/=(T r) { return (*this) /= mint(r); }\n    friend mint\
    \ operator/(const mint& l, T r) { return mint(l) /= r; }\n    friend mint operator/(T\
    \ l, const mint& r) { return mint(l) /= r; }\n};\n};  // namespace kyopro\ntemplate\
    \ <typename T, int id> T kyopro::dynamic_modint<T, id>::_mod;\ntemplate <typename\
    \ T, int id>\nkyopro::internal::Montgomery<T> kyopro::dynamic_modint<T, id>::mr;\n\
    \n/**\n * @brief \u52D5\u7684modint\n * @docs docs/math/dynamic_modint.md\n */"
  dependsOn:
  - src/internal/barrett.hpp
  - src/internal/montgomery.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: false
  path: src/math/dynamic_modint.hpp
  requiredBy:
  - src/math/phi_function.hpp
  - src/math/primitive_root.hpp
  - src/math/miller.hpp
  - src/math/rho.hpp
  - src/math/mod_log.hpp
  timestamp: '2023-06-25 12:32:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yuki/No3030.test.cpp
  - test/AOJ/NTL/1_D.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
documentation_of: src/math/dynamic_modint.hpp
layout: document
redirect_from:
- /library/src/math/dynamic_modint.hpp
- /library/src/math/dynamic_modint.hpp.html
title: "\u52D5\u7684modint"
---
