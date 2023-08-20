---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/hash_map.hpp
    title: Hash Map
  - icon: ':heavy_check_mark:'
    path: src/internal/barrett.hpp
    title: Barrett Reduction
  - icon: ':heavy_check_mark:'
    path: src/internal/montgomery.hpp
    title: Montgomery Reduction
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/dynamic_modint.hpp
    title: "\u52D5\u7684modint"
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/mod_pow.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/mod_log.md
    document_title: "\u96E2\u6563\u5BFE\u6570"
    links: []
  bundledCode: "#line 2 \"src/math/mod_log.hpp\"\n#include <cmath>\n#line 2 \"src/data-structure/hash_map.hpp\"\
    \n#include <bits/stl_algobase.h>\n#include <chrono>\nnamespace kyopro {\n/**\n\
    \ * @brief Hash Map\n */\ntemplate <typename Key,\n          typename Val,\n \
    \         uint32_t n = 1 << 20,\n          Val default_val = Val()>\nclass hash_map\
    \ {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u64* flag = new\
    \ u64[n];\n    Key* keys = new Key[n];\n    Val* vals = new Val[n];\n\n    static\
    \ constexpr u32 shift = 64 - std::__lg(n);\n\n    u64 r;\n    u32 get_hash(const\
    \ Key& k) const { return ((u64)k * r) >> shift; }\n\n    static constexpr int\
    \ mod_msk = (1 << 6) - 1;\n\npublic:\n    explicit constexpr hash_map() {\n  \
    \      r = std::chrono::steady_clock::now().time_since_epoch().count();\n    \
    \    r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](const Key&\
    \ k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n            if\
    \ (!(flag[hash >> 6] &\n                  (static_cast<u64>(1) << (hash & mod_msk))))\
    \ {\n                keys[hash] = k;\n                flag[hash >> 6] |= static_cast<u64>(1)\
    \ << (hash & mod_msk);\n                return vals[hash] = default_val;\n   \
    \         }\n\n            if (keys[hash] == k) return vals[hash];\n         \
    \   hash = (hash + 1) & (n - 1);\n        }\n    }\n\n    Val* find(const Key&\
    \ k) const {\n        u32 hash = get_hash(k);\n        while (1) {\n         \
    \   if (!(flag[hash >> 6] & (static_cast<u64>(1) << (hash & mod_msk))))\n    \
    \            return nullptr;\n            if (keys[hash] == k) return &(vals[hash]);\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @docs docs/data-structure/hash_map.md\n */\n#line 2 \"src/math/dynamic_modint.hpp\"\
    \n#include <cassert>\n#include <iostream>\n#line 2 \"src/internal/barrett.hpp\"\
    \n#include <cstdint>\nnamespace kyopro {\nnamespace internal {\n\n/**\n * @brief\
    \ Barrett Reduction\n */\nclass barrett {\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n    using u128 = __uint128_t;\n\n    u32 m;\n    u64 im;\n\n\
    public:\n    constexpr explicit barrett() : m(0), im(0) {}\n    constexpr explicit\
    \ barrett(u32 m)\n        : m(m), im(static_cast<u64>(-1) / m + 1) {}\n\n    constexpr\
    \ u32 get_mod() const { return m; }\n    constexpr u32 reduce(u32 a) const { return\
    \ mul(1, a); }\n    constexpr u32 mul(u32 a, u32 b) const {\n        u64 z = (u64)a\
    \ * b;\n        u64 x = (u64)(((u128)(z)*im) >> 64);\n        u64 y = x * m;\n\
    \        return (u32)(z - y + (z < y ? m : 0));\n    }\n};\n};  // namespace internal\n\
    };  // namespace kyopro\n\n/**\n * @ref\n * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
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
    \ barrett_modint : internal::modint_base {\n    using mint = barrett_modint<id>;\n\
    \    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    using i32 = int32_t;\n\
    \    using i64 = int64_t;\n    using br = internal::barrett;\n\n    static br\
    \ brt;\n    u32 v;\n\npublic:\n    static void set_mod(u32 mod_) { brt = br(mod_);\
    \ }\n\npublic:\n    explicit constexpr barrett_modint() : v(0) { assert(mod());\
    \ }\n    explicit constexpr barrett_modint(i64 v_) : v() {\n        assert(mod());\n\
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
    \ int id = -1>\nclass dynamic_modint : internal::modint_base {\n    using LargeT\
    \ = internal::double_size_uint_t<T>;\n    static T _mod;\n    static internal::Montgomery<T>\
    \ mr;\n\npublic:\n    static void set_mod(T mod_) {\n        mr.set_mod(mod_);\n\
    \        _mod = mod_;\n    }\n\n    static T mod() { return _mod; }\n\nprivate:\n\
    \    T v;\n\npublic:\n    dynamic_modint(T v_ = 0) {\n        assert(_mod);\n\
    \        v = mr.generate(v_);\n    }\n    T val() const { return mr.reduce(v);\
    \ }\n\n    using mint = dynamic_modint<T, id>;\n    mint& operator+=(const mint&\
    \ r) {\n        v += r.v;\n        if (v >= mr.get_mod()) {\n            v -=\
    \ mr.get_mod();\n        }\n\n        return (*this);\n    }\n\n    mint& operator-=(const\
    \ mint& r) {\n        v += mr.get_mod() - r.v;\n        if (v >= mr.get_mod) {\n\
    \            v -= mr.get_mod();\n        }\n\n        return (*this);\n    }\n\
    \n    mint& operator*=(const mint& r) {\n        v = mr.mul(v, r.v);\n       \
    \ return (*this);\n    }\n\n    mint operator+(const mint& r) { return mint(*this)\
    \ += r; }\n    mint operator-(const mint& r) { return mint(*this) -= r; }\n  \
    \  mint operator*(const mint& r) { return mint(*this) *= r; }\n\n    mint& operator=(const\
    \ T& v_) {\n        (*this) = mint(v_);\n        return (*this);\n    }\n\n  \
    \  friend std::ostream& operator<<(std::ostream& os, const mint& mt) {\n     \
    \   os << mt.val();\n        return os;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n        T v_;\n        is >> v_;\n        mt = v_;\n      \
    \  return is;\n    }\n    template <typename P> mint pow(P e) const {\n      \
    \  assert(e >= 0);\n        mint res(1), base(*this);\n\n        while (e) {\n\
    \            if (e & 1) {\n                res *= base;\n            }\n     \
    \       e >>= 1;\n            base *= base;\n        }\n        return res;\n\
    \    }\n    mint inv() const { return pow(mod() - 2); }\n\n    mint& operator/=(const\
    \ mint& r) { return (*this) *= r.inv(); }\n    mint operator/(const mint& r) const\
    \ { return mint(*this) *= r.inv(); }\n    mint& operator/=(T r) { return (*this)\
    \ /= mint(r); }\n    friend mint operator/(const mint& l, T r) { return mint(l)\
    \ /= r; }\n    friend mint operator/(T l, const mint& r) { return mint(l) /= r;\
    \ }\n};\n};  // namespace kyopro\ntemplate <typename T, int id> T kyopro::dynamic_modint<T,\
    \ id>::_mod;\ntemplate <typename T, int id>\nkyopro::internal::Montgomery<T> kyopro::dynamic_modint<T,\
    \ id>::mr;\n\n/**\n * @brief \u52D5\u7684modint\n * @docs docs/math/dynamic_modint.md\n\
    \ */\n#line 3 \"src/math/gcd.hpp\"\n#include <tuple>\nnamespace kyopro {\ntemplate\
    \ <typename T> constexpr T inline _gcd(T a, T b) {\n    assert(a >= 0 && b >=\
    \ 0);\n    if (a == 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a),\
    \ __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n\
    \    while (a != b) {\n        if (!a || !b) {\n            return a + b;\n  \
    \      }\n        if (a >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate <typename T> constexpr T\
    \ ext_gcd(T a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while (b) {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T,\
    \ T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n\
    \        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return\
    \ a;\n}\n};  // namespace kyopro\n#line 3 \"src/math/mod_pow.hpp\"\nnamespace\
    \ kyopro {\n\n/**\n * @brief \u30D0\u30A4\u30CA\u30EA\u6CD5\n */\ntemplate <typename\
    \ T>\nconstexpr T mod_pow(internal::double_size_uint_t<T> base, T exp, T mod)\
    \ {\n    internal::double_size_uint_t<T> ans = (mod == 1 ? 0 : 1);\n    base %=\
    \ mod;\n    while (exp) {\n        if (exp & 1) {\n            ans *= base;\n\
    \            ans %= mod;\n        }\n        base *= base;\n        base %= mod;\n\
    \        exp >>= 1;\n    }\n    return ans;\n}\n};  // namespace kyopro\n#line\
    \ 7 \"src/math/mod_log.hpp\"\nnamespace kyopro {\nnamespace internal {\n\ntemplate\
    \ <typename T> constexpr T __mod_log(T x, T y, T p) {\n    if (y == 1 || p ==\
    \ 1) {\n        return 0;\n    }\n    if (x == 0) {\n        if (y == 0) {\n \
    \           return 1;\n        } else {\n            return -1;\n        }\n \
    \   }\n    int m = (int)sqrt(p) + 1;\n    hash_map<T, T> mp;\n    T xm = mod_pow<T>(x,\
    \ m, p);\n    internal::double_size_uint_t<T> add = 0, g, k = (p == 1 ? 0 : 1);\n\
    \    while ((g = _gcd(x, p)) > 1) {\n        if (y == k) return add;\n       \
    \ if (y % g) return -1;\n        y /= g, p /= g, add++;\n        k = (k * (x /\
    \ g)) % p;\n    }\n\n    T pr = y;\n    for (int j = 0; j <= m; ++j) {\n     \
    \   mp[pr] = j;\n        pr = (internal::double_size_uint_t<T>)pr * x % p;\n \
    \   }\n    pr = k;\n    for (int i = 1; i <= m; ++i) {\n        pr = (internal::double_size_uint_t<T>)pr\
    \ * xm % p;\n        auto ptr = mp.find(pr);\n        if (ptr) {\n           \
    \ int j = *ptr;\n            return m * i - j + add;\n        }\n    }\n    return\
    \ -1;\n}\ntemplate <typename T> constexpr T __mod_log_odd(T x, T y, T p) {\n \
    \   if (y == 1 || p == 1) {\n        return 0;\n    }\n    if (x == 0) {\n   \
    \     if (y == 0) {\n            return 1;\n        } else {\n            return\
    \ -1;\n        }\n    }\n    int m = (int)std::sqrt(p) + 1;\n    using mint =\
    \ dynamic_modint<internal::double_size_uint_t<T>, 10>;\n    if (mint::mod() !=\
    \ p) {\n        mint::set_mod(p);\n    }\n\n    T add = 0, g = 0;\n    mint k(1);\n\
    \    while ((g = _gcd(x, p)) != 1) {\n        if (y == k.val()) return add;\n\
    \        if (y % g) return -1;\n        y /= g, p /= g, ++add;\n        k = (k.val()\
    \ * (x / g));\n    }\n\n    hash_map<T, T> mp;\n\n    mint xm = mint(x).pow(m);\n\
    \    mint pr = mint(y);\n    for (int j = 0; j <= m; ++j) {\n        mp[pr.val()]\
    \ = j;\n        pr *= x;\n    }\n    pr = k;\n    for (int i = 1; i <= m; ++i)\
    \ {\n        pr *= xm;\n        auto ptr = mp.find(pr.val());\n        if (ptr)\
    \ {\n            int j = *ptr;\n            return m * i - j + add;\n        }\n\
    \    }\n    return -1;\n}\n\n};  // namespace internal\n\n/**\n * @brief \u96E2\
    \u6563\u5BFE\u6570\n */\ntemplate <typename T> constexpr inline T mod_log(T a,\
    \ T b, T c) {\n    if (c & 1) {\n        return internal::__mod_log_odd(a, b,\
    \ c);\n    } else {\n        return internal::__mod_log(a, b, c);\n    }\n}\n\n\
    };  // namespace kyopro\n\n/**\n * @docs docs/math/mod_log.md\n*/\n"
  code: "#pragma once\n#include <cmath>\n#include \"../data-structure/hash_map.hpp\"\
    \n#include \"../math/dynamic_modint.hpp\"\n#include \"../math/gcd.hpp\"\n#include\
    \ \"../math/mod_pow.hpp\"\nnamespace kyopro {\nnamespace internal {\n\ntemplate\
    \ <typename T> constexpr T __mod_log(T x, T y, T p) {\n    if (y == 1 || p ==\
    \ 1) {\n        return 0;\n    }\n    if (x == 0) {\n        if (y == 0) {\n \
    \           return 1;\n        } else {\n            return -1;\n        }\n \
    \   }\n    int m = (int)sqrt(p) + 1;\n    hash_map<T, T> mp;\n    T xm = mod_pow<T>(x,\
    \ m, p);\n    internal::double_size_uint_t<T> add = 0, g, k = (p == 1 ? 0 : 1);\n\
    \    while ((g = _gcd(x, p)) > 1) {\n        if (y == k) return add;\n       \
    \ if (y % g) return -1;\n        y /= g, p /= g, add++;\n        k = (k * (x /\
    \ g)) % p;\n    }\n\n    T pr = y;\n    for (int j = 0; j <= m; ++j) {\n     \
    \   mp[pr] = j;\n        pr = (internal::double_size_uint_t<T>)pr * x % p;\n \
    \   }\n    pr = k;\n    for (int i = 1; i <= m; ++i) {\n        pr = (internal::double_size_uint_t<T>)pr\
    \ * xm % p;\n        auto ptr = mp.find(pr);\n        if (ptr) {\n           \
    \ int j = *ptr;\n            return m * i - j + add;\n        }\n    }\n    return\
    \ -1;\n}\ntemplate <typename T> constexpr T __mod_log_odd(T x, T y, T p) {\n \
    \   if (y == 1 || p == 1) {\n        return 0;\n    }\n    if (x == 0) {\n   \
    \     if (y == 0) {\n            return 1;\n        } else {\n            return\
    \ -1;\n        }\n    }\n    int m = (int)std::sqrt(p) + 1;\n    using mint =\
    \ dynamic_modint<internal::double_size_uint_t<T>, 10>;\n    if (mint::mod() !=\
    \ p) {\n        mint::set_mod(p);\n    }\n\n    T add = 0, g = 0;\n    mint k(1);\n\
    \    while ((g = _gcd(x, p)) != 1) {\n        if (y == k.val()) return add;\n\
    \        if (y % g) return -1;\n        y /= g, p /= g, ++add;\n        k = (k.val()\
    \ * (x / g));\n    }\n\n    hash_map<T, T> mp;\n\n    mint xm = mint(x).pow(m);\n\
    \    mint pr = mint(y);\n    for (int j = 0; j <= m; ++j) {\n        mp[pr.val()]\
    \ = j;\n        pr *= x;\n    }\n    pr = k;\n    for (int i = 1; i <= m; ++i)\
    \ {\n        pr *= xm;\n        auto ptr = mp.find(pr.val());\n        if (ptr)\
    \ {\n            int j = *ptr;\n            return m * i - j + add;\n        }\n\
    \    }\n    return -1;\n}\n\n};  // namespace internal\n\n/**\n * @brief \u96E2\
    \u6563\u5BFE\u6570\n */\ntemplate <typename T> constexpr inline T mod_log(T a,\
    \ T b, T c) {\n    if (c & 1) {\n        return internal::__mod_log_odd(a, b,\
    \ c);\n    } else {\n        return internal::__mod_log(a, b, c);\n    }\n}\n\n\
    };  // namespace kyopro\n\n/**\n * @docs docs/math/mod_log.md\n*/"
  dependsOn:
  - src/data-structure/hash_map.hpp
  - src/math/dynamic_modint.hpp
  - src/internal/barrett.hpp
  - src/internal/montgomery.hpp
  - src/internal/type_traits.hpp
  - src/math/gcd.hpp
  - src/math/mod_pow.hpp
  isVerificationFile: false
  path: src/math/mod_log.hpp
  requiredBy: []
  timestamp: '2023-07-30 13:18:23+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
documentation_of: src/math/mod_log.hpp
layout: document
redirect_from:
- /library/src/math/mod_log.hpp
- /library/src/math/mod_log.hpp.html
title: "\u96E2\u6563\u5BFE\u6570"
---
## 概要

$x,y,p$ に対して,

$$x^n \equiv y \mod p$$

となる最小の**非負整数**$n$を求めます.

## 使い方

```cpp
long long mod_log(long long x,long long y,long long p)
```

上のやつを解きます.条件を満たす $n$ が存在しない場合は $-1$ をreturnします.

### 計算量

- $O(\sqrt p)$

### 制約

- $0\leq x,y \lt p$
- $x,y\in\mathbb{Z}$
- $p\in\mathbb{N}$
- $0^0=1$ と定めている
