---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/internal/barrett.hpp
    title: Barrett Reduction
  - icon: ':heavy_check_mark:'
    path: src/internal/montgomery.hpp
    title: Montgomery Reduction
  - icon: ':heavy_check_mark:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/dynamic_modint.hpp
    title: dynamic modint
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/miller.hpp
    title: "MillerRabin\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/random/xor_shift.hpp
    title: xor shift
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/phi_function.hpp
    title: "Euler\u306E $\\varphi$ \u95A2\u6570"
  - icon: ':warning:'
    path: src/math/primitive_root.hpp
    title: "\u539F\u59CB\u6839"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/rho.md
    document_title: "PollardRho\u7D20\u56E0\u6570\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"src/math/rho.hpp\"\n#include <algorithm>\n#include <vector>\n\
    #line 2 \"src/math/gcd.hpp\"\n#include <cassert>\n#include <tuple>\nnamespace\
    \ kyopro {\ntemplate <typename T> constexpr inline T _gcd(T a, T b) noexcept {\n\
    \    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int\
    \ d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a),\
    \ b >>= __builtin_ctzll(b);\n    while (a != b) {\n        if (!a || !b) {\n \
    \           return a + b;\n        }\n        if (a >= b) {\n            a -=\
    \ b;\n            a >>= __builtin_ctzll(a);\n        } else {\n            b -=\
    \ a;\n            b >>= __builtin_ctzll(b);\n        }\n    }\n\n    return a\
    \ << d;\n}\ntemplate <typename T> constexpr inline T ext_gcd(T a, T b, T& x, T&\
    \ y) noexcept {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while (b) {\n \
    \       T q = a / b;\n        std::tie(a, b) = std::pair<T, T>{b, a % b};\n  \
    \      std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n        std::tie(y,\
    \ ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return a;\n}\n};  // namespace\
    \ kyopro\n#line 3 \"src/math/dynamic_modint.hpp\"\n#include <iostream>\n#line\
    \ 2 \"src/internal/barrett.hpp\"\n#include <cstdint>\nnamespace kyopro {\nnamespace\
    \ internal {\n\n/**\n * @brief Barrett Reduction\n */\nclass barrett {\n    using\
    \ u32 = std::uint32_t;\n    using u64 = std::uint64_t;\n    using u128 = __uint128_t;\n\
    \n    u32 m;\n    u64 im;\n\npublic:\n    constexpr barrett() : m(0), im(0) {}\n\
    \    constexpr barrett(u32 m)\n        : m(m), im(static_cast<u64>(-1) / m + 1)\
    \ {}\n\n    constexpr u32 get_mod() const { return m; }\n    constexpr u32 reduce(u32\
    \ a) const { return mul(1, a); }\n    constexpr u32 mul(u32 a, u32 b) const {\n\
    \        u64 z = (u64)a * b;\n        u64 x = (u64)(((u128)(z)*im) >> 64);\n \
    \       u64 y = x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n    }\n\
    };\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n * @ref\n * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */\n#line 3 \"src/internal/montgomery.hpp\"\n#include <limits>\n#include <numeric>\n\
    #line 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\n#line 7 \"src/internal/type_traits.hpp\"\
    \n\nnamespace kyopro {\nnamespace internal {\ntemplate <typename... Args> struct\
    \ first_enabled {};\n\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
    \ T>, Args...> {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt, std::enable_if_t<dgt\
    \ <= 128>* = nullptr> struct int_least {\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, std::int8_t>,\n                                 std::enable_if<dgt <=\
    \ 16, std::int16_t>,\n                                 std::enable_if<dgt <= 32,\
    \ std::int32_t>,\n                                 std::enable_if<dgt <= 64, std::int64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __int128_t>>;\n};\n\
    \ntemplate <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct uint_least\
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
    \n/**\n * @brief dynamic modint\n */\n#line 3 \"src/math/miller.hpp\"\nnamespace\
    \ kyopro {\n\n\nclass miller {\n    using i128 = __int128_t;\n    using u128 =\
    \ __uint128_t;\n    using u64 = std::uint64_t;\n    using u32 = std::uint32_t;\n\
    \n    template <typename T, typename mint, const int bases[], int length>\n  \
    \  static constexpr bool miller_rabin(T n) {\n        T d = n - 1;\n\n       \
    \ while (~d & 1) {\n            d >>= 1;\n        }\n\n        const T rev = n\
    \ - 1;\n        if (mint::mod() != n) {\n            mint::set_mod(n);\n     \
    \   }\n        for (int i = 0; i < length; ++i) {\n            if (n <= bases[i])\
    \ {\n                return true;\n            }\n            T t = d;\n     \
    \       mint y = mint(bases[i]).pow(t);\n\n            while (t != n - 1 && y.val()\
    \ != 1 && y.val() != rev) {\n                y *= y;\n                t <<= 1;\n\
    \            }\n\n            if (y.val() != rev && (~t & 1)) return false;\n\
    \        }\n        return true;\n    }\n    // \u5E95\n    static constexpr int\
    \ bases_int[3] = {2, 7, 61};\n    static constexpr int bases_ll[7] = {2,     \
    \ 325,     9375,      28178,\n                                        450775,\
    \ 9780504, 1795265022};\n\npublic:\n    template <typename T> static constexpr\
    \ bool is_prime(T n) {\n        if (n < 2) {\n            return false;\n    \
    \    } else if (n == 2) {\n            return true;\n        } else if (~n & 1)\
    \ {\n            return false;\n        };\n        if constexpr (std::numeric_limits<T>::digits\
    \ < 32) {\n            return miller_rabin<T, montgomery_modint<std::make_unsigned_t<T>>,\n\
    \                                bases_int, 3>(n);\n\n        } else {\n     \
    \       if (n <= 1 << 30)\n                return miller_rabin<T,\n          \
    \                          montgomery_modint<std::make_unsigned_t<T>>,\n     \
    \                               bases_int, 3>(n);\n            else\n        \
    \        return miller_rabin<\n                    T, montgomery_modint<std::make_unsigned_t<T>>,\
    \ bases_ll, 7>(\n                    n);\n        }\n        return false;\n \
    \   }\n};\n};  // namespace kyopro\n\n/**\n * @brief MillerRabin\u7D20\u6570\u5224\
    \u5B9A\n * @docs docs/math/miller.md\n */\n#line 2 \"src/random/xor_shift.hpp\"\
    \n#include <chrono>\n#line 4 \"src/random/xor_shift.hpp\"\n#include <random>\n\
    \nnamespace kyopro {\nstruct xor_shift32 {\n    uint32_t rng;\n    constexpr explicit\
    \ xor_shift32(uint32_t seed) : rng(seed) {}\n    explicit xor_shift32()\n    \
    \    : rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}\n \
    \   constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n        rng\
    \ ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n};\n\n\
    struct xor_shift {\n    uint64_t rng;\n    constexpr xor_shift(uint64_t seed)\
    \ : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief xor shift\n */\n#line 7 \"src/math/rho.hpp\"\
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
    \u56E0\u6570\u5206\u89E3\n * @docs docs/math/rho.md\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"../math/gcd.hpp\"\
    \n#include \"../math/miller.hpp\"\n#include \"../random/xor_shift.hpp\"\nnamespace\
    \ kyopro {\n\n\nclass rho {\n    using i128 = __int128_t;\n    using u128 = __uint128_t;\n\
    \    using u64 = uint64_t;\n    using u32 = uint32_t;\n\n    template <typename\
    \ T,typename mint> static constexpr T find_factor(T n) {\n        xor_shift32\
    \ rng(2023);\n\n        if (~n & 1uL) {\n            return 2;\n        }\n  \
    \      if (kyopro::miller::is_prime(n)) {\n            return n;\n        }\n\n\
    \        if (mint::mod() != n) {\n            mint::set_mod(n);\n        }\n \
    \       while (1) {\n            T c = rng();\n            const auto f = [&](mint\
    \ x) -> mint { return x * x + c; };\n            mint x = rng();\n           \
    \ mint y = f(x);\n            T d = 1;\n            while (d == 1) {\n       \
    \         d = _gcd<std::make_signed_t<T>>(\n                    std::abs((std::make_signed_t<T>)x.val()\
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
    \u56E0\u6570\u5206\u89E3\n * @docs docs/math/rho.md\n */"
  dependsOn:
  - src/math/gcd.hpp
  - src/math/miller.hpp
  - src/math/dynamic_modint.hpp
  - src/internal/barrett.hpp
  - src/internal/montgomery.hpp
  - src/internal/type_traits.hpp
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/math/rho.hpp
  requiredBy:
  - src/math/primitive_root.hpp
  - src/math/phi_function.hpp
  timestamp: '2023-10-22 17:06:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
documentation_of: src/math/rho.hpp
layout: document
redirect_from:
- /library/src/math/rho.hpp
- /library/src/math/rho.hpp.html
title: "PollardRho\u7D20\u56E0\u6570\u5206\u89E3"
---
## 概要

PollardRho素因数分解法を実装したものです.

## factorize

```cpp
vector<T> rho::factorize(T n)
```

以下の条件をすべて満たす列 $p$ を返します.

- 各 $i$ について、 $p_i$ は素数
- $p_0 \leq p_1 \leq \dots \leq p_{\vert p \vert -1}$
- $p_0 p_1 \cdots p_{\vert p \vert -2} p_{\vert p \vert -1} = n$

簡単に言うと, $n$ の素因数のリストをソートしたものです.

## exp_factorize

```cpp
std::vector<std::pair<T, int>> rho::exp_factorize(T n)
```

$n$ の素因数分解を $n=p_0^{e_0} p_1^{e_1} \cdots p_k^{e_k}$ とします.\
この時 $(p_i,e_i)$ の列, $((p_0,e_0),(p_1,e_1),\dots,(p_k,e_k))$ を返します. この列は $p_i$ らに関して昇順であることが保証されます.