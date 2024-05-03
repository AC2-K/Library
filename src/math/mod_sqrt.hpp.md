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
    title: dynamic modint
  - icon: ':question:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/miller.hpp
    title: "MillerRabin\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  - icon: ':heavy_check_mark:'
    path: src/math/mod_pow.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':heavy_check_mark:'
    path: src/math/primitive_root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':heavy_check_mark:'
    path: src/math/rho.hpp
    title: "PollardRho\u7D20\u56E0\u6570\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: src/random/xor_shift.hpp
    title: Xor Shift
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/FormalPowerSeries/fps-sqrt.hpp
    title: Sqrt of FPS
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5E73\u65B9\u5270\u4F59(O(\u221Ap))"
    links: []
  bundledCode: "#line 2 \"src/math/mod_log.hpp\"\n#include <cmath>\n#line 2 \"src/data-structure/hash_map.hpp\"\
    \n#include <chrono>\n#include <utility>\n#line 5 \"src/data-structure/hash_map.hpp\"\
    \n#include <bits/stl_algobase.h>\n\nnamespace kyopro {\ntemplate <typename Key,\n\
    \          typename Val,\n          std::size_t n = 1 << 20,\n          Val default_val\
    \ = Val()>\nclass hash_map {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \n    u64* flag = new u64[n / 64];\n    Key* keys = new Key[n];\n    Val* vals\
    \ = new Val[n];\n\n    static constexpr u32 shift = 64 - std::__lg(n);\n\n   \
    \ u64 r;\n    u32 get_hash(Key k) const { return ((u64)k * r) >> shift; }\n\n\
    \    static constexpr int block = 64;\n\npublic:\n    explicit hash_map() {\n\
    \        r = std::chrono::steady_clock::now().time_since_epoch().count();\n  \
    \      r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](Key k)\
    \ {\n        u32 hash = get_hash(k);\n\n        while (1) {\n            if (~flag[hash\
    \ / block] >> (hash % block) & static_cast<u64>(1)) {\n                keys[hash]\
    \ = k;\n                flag[hash / block] |= (static_cast<u64>(1) << (hash %\
    \ block));\n                return vals[hash] = default_val;\n            }\n\n\
    \            if (keys[hash] == k) return vals[hash];\n            hash = (hash\
    \ + 1) & (n - 1);\n        }\n    }\n\n    Val* find(Key k) const {\n        u32\
    \ hash = get_hash(k);\n        while (1) {\n            if (~flag[hash / block]\
    \ >> (hash % block) & static_cast<u64>(1)) {\n                return nullptr;\n\
    \            }\n            if (keys[hash] == k) return &(vals[hash]);\n     \
    \       hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n};  // namespace kyopro\n\
    \n/**\n * @brief Hash Map\n */\n#line 2 \"src/math/gcd.hpp\"\n#include <cassert>\n\
    #line 4 \"src/math/gcd.hpp\"\n#include <tuple>\nnamespace kyopro {\ntemplate <typename\
    \ T> constexpr inline T _gcd(T a, T b) noexcept {\n    assert(a >= 0 && b >= 0);\n\
    \    if (a == 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a),\
    \ __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n\
    \    while (a != b) {\n        if (!a || !b) {\n            return a + b;\n  \
    \      }\n        if (a >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\n\ntemplate <typename T>\nconstexpr\
    \ inline T ext_gcd(T a, T b, T& x, T& y) noexcept {\n    x = 1, y = 0;\n    T\
    \ nx = 0, ny = 1;\n    while (b) {\n        T q = a / b;\n        std::tie(a,\
    \ b) = std::pair<T, T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx,\
    \ x - nx * q};\n        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n \
    \   }\n    return a;\n}\n};  // namespace kyopro\n#line 2 \"src/internal/type_traits.hpp\"\
    \n#include <iostream>\n#include <limits>\n#include <numeric>\n#include <typeinfo>\n\
    #include <cstdint>\n\nnamespace kyopro {\nnamespace internal {\ntemplate <typename...\
    \ Args> struct first_enabled {};\n\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<true, T>, Args...> {\n    using type = T;\n\
    };\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<false,\
    \ T>, Args...>\n    : first_enabled<Args...> {};\ntemplate <typename T, typename...\
    \ Args> struct first_enabled<T, Args...> {\n    using type = T;\n};\n\ntemplate\
    \ <typename... Args>\nusing first_enabled_t = typename first_enabled<Args...>::type;\n\
    \ntemplate <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct int_least\
    \ {\n    using type = first_enabled_t<std::enable_if<dgt <= 8, std::int8_t>,\n\
    \                                 std::enable_if<dgt <= 16, std::int16_t>,\n \
    \                                std::enable_if<dgt <= 32, std::int32_t>,\n  \
    \                               std::enable_if<dgt <= 64, std::int64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __int128_t>>;\n};\n\n\
    template <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct uint_least\
    \ {\n    using type = first_enabled_t<std::enable_if<dgt <= 8, std::uint8_t>,\n\
    \                                 std::enable_if<dgt <= 16, std::uint16_t>,\n\
    \                                 std::enable_if<dgt <= 32, std::uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, std::uint64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __uint128_t>>;\n\
    };\n\ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\n\
    template <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate\
    \ <typename T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\n#line 3 \"src/math/mod_pow.hpp\"\nnamespace kyopro {\n\n/**\n * @brief \u30D0\
    \u30A4\u30CA\u30EA\u6CD5\n */\ntemplate <typename T>\nconstexpr T mod_pow(internal::double_size_uint_t<T>\
    \ base, T exp, T mod) {\n    internal::double_size_uint_t<T> ans = (mod == 1 ?\
    \ 0 : 1);\n    base %= mod;\n    while (exp) {\n        if (exp & 1) {\n     \
    \       ans *= base;\n            ans %= mod;\n        }\n        base *= base;\n\
    \        base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n};  // namespace\
    \ kyopro\n#line 6 \"src/math/mod_log.hpp\"\nnamespace kyopro {\n\ntemplate <typename\
    \ T> constexpr inline T mod_log(T x, T y, T p) {\n    if (y == 1 || p == 1) {\n\
    \        return 0;\n    }\n    if (x == 0) {\n        if (y == 0) {\n        \
    \    return 1;\n        } else {\n            return -1;\n        }\n    }\n \
    \   int m = (int)sqrt(p) + 1;\n    hash_map<T, T> mp;\n    T xm = mod_pow<T>(x,\
    \ m, p);\n    internal::double_size_uint_t<T> add = 0, g, k = (p == 1 ? 0 : 1);\n\
    \    while ((g = _gcd(x, p)) > 1) {\n        if (y == k) return add;\n       \
    \ if (y % g) return -1;\n        y /= g, p /= g, add++;\n        k = (k * (x /\
    \ g)) % p;\n    }\n\n    T pr = y;\n    for (int j = 0; j <= m; ++j) {\n     \
    \   mp[pr] = j;\n        pr = (internal::double_size_uint_t<T>)pr * x % p;\n \
    \   }\n    pr = k;\n    for (int i = 1; i <= m; ++i) {\n        pr = (internal::double_size_uint_t<T>)pr\
    \ * xm % p;\n        auto ptr = mp.find(pr);\n        if (ptr) {\n           \
    \ int j = *ptr;\n            return m * i - j + add;\n        }\n    }\n    return\
    \ -1;\n}\n\n};  // namespace kyopro\n\n/**\n * @brief \u96E2\u6563\u5BFE\u6570\
    \n * @docs docs/math/mod_log.md\n */\n#line 3 \"src/internal/barrett.hpp\"\nnamespace\
    \ kyopro {\nnamespace internal {\n\n/**\n * @brief Barrett Reduction\n */\nclass\
    \ barrett {\n    using u32 = std::uint32_t;\n    using u64 = std::uint64_t;\n\
    \    using u128 = __uint128_t;\n\n    u32 m;\n    u64 im;\n\npublic:\n    constexpr\
    \ barrett() : m(0), im(0) {}\n    constexpr barrett(u32 m)\n        : m(m), im(static_cast<u64>(-1)\
    \ / m + 1) {}\n\n    constexpr u32 get_mod() const { return m; }\n    constexpr\
    \ u32 reduce(u32 a) const { return mul(1, a); }\n    constexpr u32 mul(u32 a,\
    \ u32 b) const {\n        u64 z = (u64)a * b;\n        u64 x = (u64)(((u128)(z)*im)\
    \ >> 64);\n        u64 y = x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n\
    \    }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n * @ref\n\
    \ * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */\n#line 6 \"src/internal/montgomery.hpp\"\nnamespace kyopro {\nnamespace internal\
    \ {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i32 = int32_t;\nusing\
    \ i64 = int64_t;\nusing u128 = __uint128_t;\nusing i128 = __int128_t;\n\n/**\n\
    \ * @brief Montgomery Reduction\n */\ntemplate <typename T> class Montgomery {\n\
    \    static constexpr int lg = std::numeric_limits<T>::digits;\n    using LargeT\
    \ = internal::double_size_uint_t<T>;\n    T mod, r, r2, minv;\n    T inv() {\n\
    \        T t = 0, res = 0;\n        for (int i = 0; i < lg; ++i) {\n         \
    \   if (~t & 1) {\n                t += mod;\n                res += static_cast<T>(1)\
    \ << i;\n            }\n            t >>= 1;\n        }\n        return res;\n\
    \    }\n\npublic:\n    Montgomery() = default;\n    constexpr T get_mod() { return\
    \ mod; }\n\n    void set_mod(T m) {\n        assert(m);\n        assert(m & 1);\n\
    \n        mod = m;\n\n        r = (-static_cast<T>(mod)) % mod;\n        r2 =\
    \ (-static_cast<LargeT>(mod)) % mod;\n        minv = inv();\n    }\n\n    T reduce(LargeT\
    \ x) const {\n        u64 res =\n            (x + static_cast<LargeT>(static_cast<T>(x)\
    \ * minv) * mod) >> lg;\n\n        if (res >= mod) res -= mod;\n        return\
    \ res;\n    }\n\n    T generate(LargeT x) { return reduce(x * r2); }\n\n    T\
    \ mul(T x, T y) { return reduce((LargeT)x * y); }\n};\n};  // namespace internal\n\
    };  // namespace kyopro\n#line 6 \"src/math/dynamic_modint.hpp\"\nnamespace kyopro\
    \ {\ntemplate <int id = -1> class barrett_modint : internal::modint_base {\n \
    \   using mint = barrett_modint<id>;\n    using u32 = std::uint32_t;\n    using\
    \ u64 = std::uint64_t;\n\n    using i32 = std::int32_t;\n    using i64 = std::int64_t;\n\
    \    using br = internal::barrett;\n\n    static br brt;\n    u32 v;\n\npublic:\n\
    \    static void set_mod(u32 mod_) { brt = br(mod_); }\n\npublic:\n    explicit\
    \ constexpr barrett_modint() noexcept : v(0) { assert(mod()); }\n    explicit\
    \ constexpr barrett_modint(i64 v_) noexcept : v() {\n        assert(mod());\n\
    \        if (v_ < 0) v_ = (i64)mod() - v_;\n        v = brt.reduce(v_);\n    }\n\
    \n    u32 val() const noexcept { return v; }\n    static u32 mod() { return brt.get_mod();\
    \ }\n    static mint raw(u32 v) {\n        mint x;\n        x.v = v;\n       \
    \ return x;\n    }\n\n    constexpr mint& operator++() noexcept {\n        ++v;\n\
    \        if (v == mod()) v = 0;\n        return (*this);\n    }\n    constexpr\
    \ mint& operator--() noexcept {\n        if (v == 0) v = mod();\n        --v;\n\
    \        return (*this);\n    }\n    constexpr mint operator++(int) noexcept {\n\
    \        mint res(*this);\n        ++(*this);\n        return res;\n    }\n  \
    \  constexpr mint operator--(int) noexcept {\n        mint res(*this);\n     \
    \   --(*this);\n        return res;\n    }\n\n    constexpr mint& operator+=(const\
    \ mint& r) noexcept {\n        v += r.v;\n        if (v >= mod()) v -= mod();\n\
    \        return (*this);\n    }\n    constexpr mint& operator-=(const mint& r)\
    \ noexcept {\n        v += mod() - r.v;\n        if (v >= mod()) {\n         \
    \   v -= mod();\n        }\n\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(const mint& r) noexcept {\n        v = brt.mul(v, r.v);\n       \
    \ return (*this);\n    }\n    constexpr mint& operator/=(const mint& r) noexcept\
    \ {\n        return (*this) *= r.inv();\n    }\n\n    friend mint operator+(const\
    \ mint& lhs, const mint& rhs) noexcept {\n        return mint(lhs) += rhs;\n \
    \   }\n    friend mint operator-(const mint& lhs, const mint& rhs) noexcept {\n\
    \        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const mint&\
    \ lhs, const mint& rhs) noexcept {\n        return mint(lhs) *= rhs;\n    }\n\
    \    friend mint operator/(const mint& lhs, const mint& rhs) noexcept {\n    \
    \    return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) noexcept {\n        return lhs.v == rhs.v;\n    }\n    friend\
    \ bool operator!=(const mint& lhs, const mint& rhs) noexcept {\n        return\
    \ lhs.v != rhs.v;\n    }\n\n    constexpr mint& operator+=(i64 r) noexcept { return\
    \ (*this) += mint(r); }\n    constexpr mint& operator-=(i64 r) noexcept { return\
    \ (*this) -= mint(r); }\n    constexpr mint& operator*=(i64 r) noexcept { return\
    \ (*this) *= mint(r); }\n\n    friend mint operator+(i64 l, const mint& r) noexcept\
    \ {\n        return mint(l) += r;\n    }\n    friend mint operator+(const mint&\
    \ l, i64 r) noexcept {\n        return mint(l) += r;\n    }\n    friend mint operator-(i64\
    \ l, const mint& r) noexcept {\n        return mint(l) -= r;\n    }\n    friend\
    \ mint operator-(const mint& l, i64 r) noexcept {\n        return mint(l) -= r;\n\
    \    }\n    friend mint operator*(i64 l, const mint& r) noexcept {\n        return\
    \ mint(l) *= r;\n    }\n    friend mint operator*(const mint& l, i64 r) noexcept\
    \ {\n        return mint(l) *= r;\n    }\n\n    constexpr mint operator+() const\
    \ noexcept { return *this; }\n    constexpr mint operator-() const noexcept {\
    \ return mint() - *this; }\n\n    template <typename T> mint pow(T e) const noexcept\
    \ {\n        mint res(1), base(*this);\n\n        while (e) {\n            if\
    \ (e & 1) {\n                res *= base;\n            }\n            e >>= 1;\n\
    \            base *= base;\n        }\n        return res;\n    }\n    constexpr\
    \ mint inv() const noexcept { return pow(mod() - 2); }\n};\n};  // namespace kyopro\n\
    template <int id>\ntypename kyopro::barrett_modint<id>::br kyopro::barrett_modint<id>::brt;\n\
    \nnamespace kyopro {\ntemplate <typename T, int id = -1>\nclass montgomery_modint\
    \ : internal::modint_base {\n    using LargeT = internal::double_size_uint_t<T>;\n\
    \    static T _mod;\n    static internal::Montgomery<T> mr;\n\npublic:\n    static\
    \ void set_mod(T mod_) {\n        mr.set_mod(mod_);\n        _mod = mod_;\n  \
    \  }\n\n    static T mod() { return _mod; }\n\nprivate:\n    T v;\n\npublic:\n\
    \    montgomery_modint(T v_ = 0) {\n        assert(_mod);\n        v = mr.generate(v_);\n\
    \    }\n    T val() const { return mr.reduce(v); }\n\n    using mint = montgomery_modint<T,\
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
    \ <typename T, int id> T kyopro::montgomery_modint<T, id>::_mod;\ntemplate <typename\
    \ T, int id>\nkyopro::internal::Montgomery<T> kyopro::montgomery_modint<T, id>::mr;\n\
    \n/**\n * @brief dynamic modint\n */\n#line 2 \"src/math/rho.hpp\"\n#include <algorithm>\n\
    #include <vector>\n#line 3 \"src/math/miller.hpp\"\nnamespace kyopro {\n\n\nclass\
    \ miller {\n    using i128 = __int128_t;\n    using u128 = __uint128_t;\n    using\
    \ u64 = std::uint64_t;\n    using u32 = std::uint32_t;\n\n    template <typename\
    \ T, typename mint, const int bases[], int length>\n    static constexpr bool\
    \ miller_rabin(T n) {\n        T d = n - 1;\n\n        while (~d & 1) {\n    \
    \        d >>= 1;\n        }\n\n        const T rev = n - 1;\n        if (mint::mod()\
    \ != n) {\n            mint::set_mod(n);\n        }\n        for (int i = 0; i\
    \ < length; ++i) {\n            if (n <= bases[i]) {\n                return true;\n\
    \            }\n            T t = d;\n            mint y = mint(bases[i]).pow(t);\n\
    \n            while (t != n - 1 && y.val() != 1 && y.val() != rev) {\n       \
    \         y *= y;\n                t <<= 1;\n            }\n\n            if (y.val()\
    \ != rev && (~t & 1)) return false;\n        }\n        return true;\n    }\n\
    \    // \u5E95\n    static constexpr int bases_int[3] = {2, 7, 61};\n    static\
    \ constexpr int bases_ll[7] = {2,      325,     9375,      28178,\n          \
    \                              450775, 9780504, 1795265022};\n\npublic:\n    template\
    \ <typename T> static constexpr bool is_prime(T n) {\n        if (n < 2) {\n \
    \           return false;\n        } else if (n == 2) {\n            return true;\n\
    \        } else if (~n & 1) {\n            return false;\n        };\n       \
    \ if constexpr (std::numeric_limits<T>::digits < 32) {\n            return miller_rabin<T,\
    \ montgomery_modint<std::make_unsigned_t<T>>,\n                              \
    \  bases_int, 3>(n);\n\n        } else {\n            if (n <= 1 << 30)\n    \
    \            return miller_rabin<T,\n                                    montgomery_modint<std::make_unsigned_t<T>>,\n\
    \                                    bases_int, 3>(n);\n            else\n   \
    \             return miller_rabin<\n                    T, montgomery_modint<std::make_unsigned_t<T>>,\
    \ bases_ll, 7>(\n                    n);\n        }\n        return false;\n \
    \   }\n};\n};  // namespace kyopro\n\n/**\n * @brief MillerRabin\u7D20\u6570\u5224\
    \u5B9A\n * @docs docs/math/miller.md\n */\n#line 4 \"src/random/xor_shift.hpp\"\
    \n#include <random>\n\nnamespace kyopro {\nstruct xor_shift32 {\n    uint32_t\
    \ rng;\n    constexpr explicit xor_shift32(uint32_t seed) : rng(seed) {}\n   \
    \ explicit xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr explicit xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief Xor Shift\n */\n#line 7 \"src/math/rho.hpp\"\
    \nnamespace kyopro {\n\n\nclass rho {\n    using i128 = __int128_t;\n    using\
    \ u128 = __uint128_t;\n    using u64 = uint64_t;\n    using u32 = uint32_t;\n\n\
    \    template <typename T,typename mint> static constexpr T find_factor(T n) {\n\
    \        xor_shift32 rng(2023);\n\n        if (~n & 1uL) {\n            return\
    \ 2;\n        }\n        if (kyopro::miller::is_prime(n)) {\n            return\
    \ n;\n        }\n\n        if (mint::mod() != n) {\n            mint::set_mod(n);\n\
    \        }\n        while (1) {\n            T c = rng();\n            const auto\
    \ f = [&](mint x) -> mint { return x * x + c; };\n            mint x = rng();\n\
    \            mint y = f(x);\n            T d = 1;\n            while (d == 1)\
    \ {\n                d = _gcd<std::make_signed_t<T>>(\n                    std::abs((std::make_signed_t<T>)x.val()\
    \ - (std::make_signed_t<T>)y.val()), n);\n                x = f(x);\n        \
    \        y = f(f(y));\n            }\n            if (1 < d && d < n) {\n    \
    \            return d;\n            }\n        }\n        exit(-1);\n    }\n \
    \   template <typename T,typename mint> static std::vector<T> rho_fact(T n) {\n\
    \        if (n < 2) {\n            return {};\n        }\n        if (kyopro::miller::is_prime(n))\
    \ {\n            return {n};\n        }\n        std::vector<T> v;\n        std::vector<T>\
    \ st{n};\n        while (!st.empty()) {\n            u64 m = st.back();\n    \
    \        if (kyopro::miller::is_prime(m)) {\n                v.emplace_back(m);\n\
    \                st.pop_back();\n            } else {\n                T d = find_factor<T,\
    \ mint>(m);\n                st.back() /= d;\n                st.emplace_back(d);\n\
    \            }\n        }\n        return v;\n    }\n\npublic:\n    template <typename\
    \ T> static std::vector<T> factorize(T n) {\n        if (n < 2) {\n          \
    \  return {};\n        }\n\n        if constexpr (std::numeric_limits<T>::digits\
    \ < 32) {\n            std::vector v = rho_fact<T, montgomery_modint<u32>>(n);\n\
    \            std::sort(v.begin(), v.end());\n            return v;\n        }\
    \ else {\n            std::vector v = rho_fact<T, montgomery_modint<u64>>(n);\n\
    \            std::sort(v.begin(), v.end());\n            return v;\n        }\n\
    \    }\n    template<typename T>\n    static std::vector<std::pair<T, int>> exp_factorize(T\
    \ n) {\n        std::vector pf = factorize(n);\n        if (pf.empty()) {\n  \
    \          return {};\n        }\n        std::vector<std::pair<T, int>> res;\n\
    \        res.emplace_back(pf.front(), 1);\n        for (int i = 1; i < (int)pf.size();\
    \ i++) {\n            if (res.back().first == pf[i]) {\n                res.back().second++;\n\
    \            } else {\n                res.emplace_back(pf[i], 1);\n         \
    \   }\n        }\n\n        return res;\n    }\n    template<typename T>\n   \
    \ static std::vector<T> enumerate_divisor(T n) {\n        std::vector<std::pair<T,\
    \ int>> pf = rho::exp_factorize(n);\n        std::vector<T> divisor{1};\n    \
    \    for (auto [p, e] : pf) {\n            u64 pow = p;\n            int sz =\
    \ divisor.size();\n            for (int i = 0; i < e; ++i) {\n               \
    \ for (int j = 0; j < sz; ++j)\n                    divisor.emplace_back(divisor[j]\
    \ * pow);\n                pow *= p;\n            }\n        }\n\n        return\
    \ divisor;\n    }\n};\n};  // namespace kyopro\n\n/**\n * @brief PollardRho\u7D20\
    \u56E0\u6570\u5206\u89E3\n * @docs docs/math/rho.md\n */\n#line 4 \"src/math/primitive_root.hpp\"\
    \nnamespace kyopro {\n\n/**\n * @brief \u539F\u59CB\u6839\n */\ntemplate <typename\
    \ T> constexpr T primitive_root(T p) noexcept {\n    if (p == 2) return 1;\n\n\
    \    auto pf = kyopro::rho::factorize(p - 1);\n    pf.erase(std::unique(pf.begin(),\
    \ pf.end()), pf.end());\n    for (auto& q : pf) {\n        q = (p - 1) / q;\n\
    \    }\n\n    using mint =\n        std::conditional_t<std::numeric_limits<T>::digits\
    \ <= 32,\n                           barrett_modint<-1>, montgomery_modint<uint64_t>>;\n\
    \    if (mint::mod() != p) {\n        mint::set_mod(p);\n    }\n\n    for (int\
    \ _g = 1;; ++_g) {\n        mint g(_g);\n        if (g.val() == 0) continue;\n\
    \        bool is_ok = true;\n\n        for (auto q : pf) {\n            if (g.pow(q).val()\
    \ == 1) {\n                is_ok = false;\n                break;\n          \
    \  }\n        }\n\n        if (is_ok) {\n            return g.val();\n       \
    \ }\n    }\n    return -1;\n}\n};  // namespace kyopro\n#line 4 \"src/math/mod_sqrt.hpp\"\
    \n\nnamespace kyopro {\n/**\n * @brief \u5E73\u65B9\u5270\u4F59(O(\u221Ap))\n\
    \ * @note \u9045\u3044\n */\nconstexpr int mod_sqrt_lazy(int x, int p) {\n   \
    \ if (x == 0) return 0;\n    if (p == 2) return x;\n    int g = primitive_root(p);\n\
    \    int e = mod_log(g, x, p);\n    if (e % 2 != 0) {\n        return -1;\n  \
    \  } else {\n        return mod_pow(g, e / 2, p);\n    }\n}\n};  // namespace\
    \ kyopro\n"
  code: "#pragma once\n#include \"../math/mod_log.hpp\"\n#include \"../math/primitive_root.hpp\"\
    \n\nnamespace kyopro {\n/**\n * @brief \u5E73\u65B9\u5270\u4F59(O(\u221Ap))\n\
    \ * @note \u9045\u3044\n */\nconstexpr int mod_sqrt_lazy(int x, int p) {\n   \
    \ if (x == 0) return 0;\n    if (p == 2) return x;\n    int g = primitive_root(p);\n\
    \    int e = mod_log(g, x, p);\n    if (e % 2 != 0) {\n        return -1;\n  \
    \  } else {\n        return mod_pow(g, e / 2, p);\n    }\n}\n};  // namespace\
    \ kyopro"
  dependsOn:
  - src/math/mod_log.hpp
  - src/data-structure/hash_map.hpp
  - src/math/gcd.hpp
  - src/math/mod_pow.hpp
  - src/internal/type_traits.hpp
  - src/math/primitive_root.hpp
  - src/math/dynamic_modint.hpp
  - src/internal/barrett.hpp
  - src/internal/montgomery.hpp
  - src/math/rho.hpp
  - src/math/miller.hpp
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/math/mod_sqrt.hpp
  requiredBy:
  - src/FormalPowerSeries/fps-sqrt.hpp
  timestamp: '2024-03-18 23:40:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
documentation_of: src/math/mod_sqrt.hpp
layout: document
redirect_from:
- /library/src/math/mod_sqrt.hpp
- /library/src/math/mod_sqrt.hpp.html
title: "\u5E73\u65B9\u5270\u4F59(O(\u221Ap))"
---