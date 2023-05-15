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
    title: "\u52D5\u7684modint"
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/miller.hpp
    title: "MillerRabin\u7D20\u6570\u5224\u5B9A\u6CD5"
  - icon: ':heavy_check_mark:'
    path: src/math/rho.hpp
    title: "Pollard Rho \u7D20\u56E0\u6570\u5206\u89E3\u6CD5"
  - icon: ':heavy_check_mark:'
    path: src/random/xor_shift.hpp
    title: xor shift
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u539F\u59CB\u6839"
    links: []
  bundledCode: "#line 2 \"src/math/dynamic_modint.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#line 2 \"src/internal/barrett.hpp\"\n#include <cstdint>\nnamespace\
    \ kyopro {\nnamespace internal {\n\n/**\n * @brief Barrett Reduction\n */\nclass\
    \ barrett {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u32 m;\n\
    \    u64 im;\n\npublic:\n    constexpr barrett() : m(0), im(0) {}\n    constexpr\
    \ barrett(u32 m_)\n        : m(m_), im((u64) static_cast<u64>(-1) / m_ + 1) {}\n\
    \n    constexpr u32 get_mod() const { return m; }\n    constexpr u32 reduce(int64_t\
    \ a) const { return mul(a, 1); }\n    constexpr u32 mul(u32 a, u32 b) const {\n\
    \        if (!a || !b) {\n            return 0;\n        }\n        u64 z = (u64)a\
    \ * b;\n        u64 x = (u64)(((__uint128_t)z * im) >> 64);\n\n        u64 y =\
    \ x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n    }\n};\n};  // namespace\
    \ internal\n};  // namespace kyopro\n\n/**\n * @ref\n * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */\n#line 3 \"src/internal/montgomery.hpp\"\n#include <limits>\n#include <numeric>\n\
    #line 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\nnamespace kyopro\
    \ {\nnamespace internal {\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\ntemplate <typename... Args>\nstruct first_enabled {};\n\ntemplate <typename\
    \ T, typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...>\
    \ {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct\
    \ first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args>\nstruct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt>\nstruct int_least\
    \ {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __int8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __int16_t>,\n                                 std::enable_if<dgt <= 32, __int32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __int64_t>,\n    \
    \                             std::enable_if<dgt <= 128, __int128_t> >;\n};\n\
    template <int dgt>\nstruct uint_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __uint8_t>,\n              \
    \                   std::enable_if<dgt <= 16, __uint16_t>,\n                 \
    \                std::enable_if<dgt <= 32, __uint32_t>,\n                    \
    \             std::enable_if<dgt <= 64, __uint64_t>,\n                       \
    \          std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\ntemplate <int dgt>\n\
    using int_least_t = typename int_least<dgt>::type;\ntemplate <int dgt>\nusing\
    \ uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename T>\nusing\
    \ double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\ntemplate\
    \ <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    };  // namespace internal\n};  // namespace kyopro\n#line 6 \"src/internal/montgomery.hpp\"\
    \nnamespace kyopro {\nnamespace internal {\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i32 = int32_t;\nusing i64 = int64_t;\nusing u128 = __uint128_t;\n\
    using i128 = __int128_t;\n\n/**\n * @brief Montgomery Reduction\n */\ntemplate\
    \ <typename T>\nclass Montgomery {\n    static constexpr int lg = std::numeric_limits<T>::digits;\n\
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
    src/math/dynamic_modint.hpp\"\nnamespace kyopro {\ntemplate <int id = -1>\nclass\
    \ barrett_modint {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n \
    \   using i32 = int32_t;\n    using i64 = int64_t;\n    using br = internal::barrett;\n\
    \n    static br brt;\n    static u32 mod;\n    u32 v;\n\npublic:\n    static void\
    \ set_mod(u32 mod_) {\n        brt = br(mod_);\n        mod = mod_;\n    }\n\n\
    public:\n    explicit constexpr barrett_modint() : v(0) { assert(mod); }\n   \
    \ explicit constexpr barrett_modint(i64 v_) : v(brt.reduce(v_)) {\n        assert(mod);\n\
    \    }\n\n    u32 val() const { return v; }\n    static u32 get_mod() { return\
    \ mod; }\n    using mint = barrett_modint<id>;\n\n    constexpr mint& operator=(i64\
    \ r) {\n        v = brt.reduce(r);\n        return (*this);\n    }\n    constexpr\
    \ mint& operator+=(const mint& r) {\n        v += r.v;\n        if (v >= mod)\
    \ {\n            v -= mod;\n        }\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(const mint& r) {\n        v += mod - r.v;\n        if (v >=\
    \ mod) {\n            v -= mod;\n        }\n\n        return (*this);\n    }\n\
    \    constexpr mint& operator*=(const mint& r) {\n        v = brt.mul(v, r.v);\n\
    \        return (*this);\n    }\n\n    constexpr mint operator+(const mint& r)\
    \ const { return mint(*this) += r; }\n    constexpr mint operator-(const mint&\
    \ r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const mint&\
    \ r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(i64\
    \ r) { return (*this) += mint(r); }\n    constexpr mint& operator-=(i64 r) { return\
    \ (*this) -= mint(r); }\n    constexpr mint& operator*=(i64 r) { return (*this)\
    \ *= mint(r); }\n\n    friend mint operator+(i64 l, const mint& r) { return mint(l)\
    \ += r; }\n    friend mint operator+(const mint& l, i64 r) { return mint(l) +=\
    \ r; }\n    friend mint operator-(i64 l, const mint& r) { return mint(l) -= r;\
    \ }\n    friend mint operator-(const mint& l, i64 r) { return mint(l) -= r; }\n\
    \    friend mint operator*(i64 l, const mint& r) { return mint(l) *= r; }\n  \
    \  friend mint operator*(const mint& l, i64 r) { return mint(l) += r; }\n\n  \
    \  friend std::ostream& operator<<(std::ostream& os, const mint& mt) {\n     \
    \   os << mt.val();\n        return os;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n        i64 v_;\n        is >> v_;\n        mt = v_;\n    \
    \    return is;\n    }\n    template <typename T>\n    mint pow(T e) const {\n\
    \        mint res(1), base(*this);\n\n        while (e) {\n            if (e &\
    \ 1) {\n                res *= base;\n            }\n            e >>= 1;\n  \
    \          base *= base;\n        }\n        return res;\n    }\n    mint inv()\
    \ const { return pow(mod - 2); }\n\n    mint& operator/=(const mint& r) { return\
    \ (*this) *= r.inv(); }\n    mint operator/(const mint& r) const { return mint(*this)\
    \ *= r.inv(); }\n    mint& operator/=(i64 r) { return (*this) /= mint(r); }\n\
    \    friend mint operator/(const mint& l, i64 r) { return mint(l) /= r; }\n  \
    \  friend mint operator/(i64 l, const mint& r) { return mint(l) /= r; }\n};\n\
    };  // namespace kyopro\ntemplate <int id>\ntypename kyopro::barrett_modint<id>::u32\
    \ kyopro::barrett_modint<id>::mod;\ntemplate <int id>\ntypename kyopro::barrett_modint<id>::br\
    \ kyopro::barrett_modint<id>::brt;\n\nnamespace kyopro {\ntemplate <typename T,\
    \ int id = -1>\nclass dynamic_modint {\n    using LargeT = internal::double_size_uint_t<T>;\n\
    \    static T mod;\n    static internal::Montgomery<T> mr;\n\npublic:\n    static\
    \ void set_mod(T mod_) {\n        mr.set_mod(mod_);\n        mod = mod_;\n   \
    \ }\n\n    static T get_mod() { return mod; }\n\nprivate:\n    T v;\n\npublic:\n\
    \    dynamic_modint(T v_ = 0) {\n        assert(mod);\n        v = mr.generate(v_);\n\
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
    \ <typename P>\n    mint pow(P e) const {\n        assert(e >= 0);\n        mint\
    \ res(1), base(*this);\n\n        while (e) {\n            if (e & 1) {\n    \
    \            res *= base;\n            }\n            e >>= 1;\n            base\
    \ *= base;\n        }\n        return res;\n    }\n    mint inv() const { return\
    \ pow(mod - 2); }\n\n    mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n    mint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n    mint& operator/=(T r) { return (*this) /= mint(r); }\n    friend mint\
    \ operator/(const mint& l, T r) { return mint(l) /= r; }\n    friend mint operator/(T\
    \ l, const mint& r) { return mint(l) /= r; }\n};\n};  // namespace kyopro\ntemplate\
    \ <typename T, int id>\nT kyopro::dynamic_modint<T, id>::mod;\ntemplate <typename\
    \ T, int id>\nkyopro::internal::Montgomery<T> kyopro::dynamic_modint<T, id>::mr;\n\
    \n/**\n * @brief \u52D5\u7684modint\n * @docs docs/math/dynamic_modint.md\n */\n\
    #line 2 \"src/math/rho.hpp\"\n#include <algorithm>\n#include <vector>\n#line 3\
    \ \"src/math/gcd.hpp\"\n#include <tuple>\nnamespace kyopro {\ntemplate <typename\
    \ T>\nconstexpr T inline _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n   \
    \ if (a == 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a),\
    \ __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n\
    \    while (a != b) {\n        if (!a||!b) {\n            return a + b;\n    \
    \    }\n        if (a >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate <typename T>\nconstexpr T\
    \ ext_gcd(T a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while (b) {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T,\
    \ T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n\
    \        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return\
    \ a;\n}\n};  // namespace kyopro\n#line 3 \"src/math/miller.hpp\"\nnamespace kyopro\
    \ {\n\n/**\n * @brief MillerRabin\u7D20\u6570\u5224\u5B9A\u6CD5\n */\nclass miller\
    \ {\n    using i128 = __int128_t;\n    using u128 = __uint128_t;\n    using u64\
    \ = uint64_t;\n    using u32 = uint32_t;\n\n    template <typename T, typename\
    \ mint, const int bases[], int length>\n    static constexpr bool miller_rabin(T\
    \ n) {\n        T d = n - 1;\n\n        while (~d & 1) {\n            d >>= 1;\n\
    \        }\n\n        const T rev = n - 1;\n        if (mint::get_mod() != n)\
    \ {\n            mint::set_mod(n);\n        }\n        for (int i = 0; i < length;\
    \ ++i) {\n            if (n <= bases[i]) {\n                return true;\n   \
    \         }\n            T t = d;\n            mint y = mint(bases[i]).pow(t);\n\
    \n            while (t != n - 1 && y.val() != 1 && y.val() != rev) {\n       \
    \         y *= y;\n                t <<= 1;\n            }\n\n            if (y.val()\
    \ != rev && (~t & 1)) return false;\n        }\n        return true;\n    }\n\
    \    // \u5E95\n    static constexpr int bases_int[3] = {2, 7, 61};\n    static\
    \ constexpr int bases_ll[7] = {2,      325,     9375,      28178,\n          \
    \                              450775, 9780504, 1795265022};\n\npublic:\n    template\
    \ <typename T> static constexpr bool is_prime(T n) {\n        if (n < 2) {\n \
    \           return false;\n        } else if (n == 2) {\n            return true;\n\
    \        } else if (~n & 1) {\n            return false;\n        };\n       \
    \ if (std::numeric_limits<T>::digits < 32 || n <= 1 << 30) {\n            return\
    \ miller_rabin<T, dynamic_modint<std::make_unsigned_t<T>>,\n                 \
    \               bases_int, 3>(n);\n        } else {\n            return miller_rabin<T,\
    \ dynamic_modint<std::make_unsigned_t<T>>,\n                                bases_ll,\
    \ 7>(n);\n        }\n        return false;\n    }\n};\n};  // namespace kyopro\n\
    \n/**\n * @docs docs/math/miller.md\n */\n#line 2 \"src/random/xor_shift.hpp\"\
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
    };\n\n};  // namespace kyopro\n\n/**\n * @brief xor shift\n*/\n#line 7 \"src/math/rho.hpp\"\
    \nnamespace kyopro {\n\n/**\n * @brief Pollard Rho \u7D20\u56E0\u6570\u5206\u89E3\
    \u6CD5\n */\nclass rho {\n    using i128 = __int128_t;\n    using u128 = __uint128_t;\n\
    \    using u64 = uint64_t;\n    using u32 = uint32_t;\n\n    template <typename\
    \ mint> static u64 find_factor(u64 n) {\n        xor_shift32 rng(2023);\n\n  \
    \      if (~n & 1uL) {\n            return 2;\n        }\n        if (kyopro::miller::is_prime(n))\
    \ {\n            return n;\n        }\n\n        if (mint::get_mod() != n) {\n\
    \            mint::set_mod(n);\n        }\n        while (1) {\n            u64\
    \ c = rng();\n            const auto f = [&](mint x) -> mint { return x * x +\
    \ c; };\n            mint x = rng();\n            mint y = f(x);\n           \
    \ u64 d = 1;\n            while (d == 1) {\n                d = _gcd<long long>(\n\
    \                    std::abs((long long)x.val() - (long long)y.val()), n);\n\
    \                x = f(x);\n                y = f(f(y));\n            }\n    \
    \        if (1 < d && d < n) {\n                return d;\n            }\n   \
    \     }\n        exit(0);\n    }\n    template <typename mint> static std::vector<u64>\
    \ rho_fact(u64 n) {\n        if (n < 2) {\n            return {};\n        }\n\
    \        if (kyopro::miller::is_prime(n)) {\n            return {n};\n       \
    \ }\n        std::vector<u64> v;\n        std::vector<u64> st{n};\n        while\
    \ (st.size()) {\n            u64& m = st.back();\n            if (kyopro::miller::is_prime(m))\
    \ {\n                v.emplace_back(m);\n                st.pop_back();\n    \
    \        } else {\n                u64 d = find_factor<mint>(m);\n           \
    \     m /= d;\n                st.emplace_back(d);\n            }\n        }\n\
    \        return v;\n    }\n\npublic:\n    static std::vector<u64> factorize(u64\
    \ n) {\n        if (n < 2) {\n            return {};\n        }\n        auto\
    \ v = (n < (1uL << 31) ? rho_fact<dynamic_modint<u32>>(n)\n                  \
    \                : rho_fact<dynamic_modint<u64>>(n));\n        std::sort(v.begin(),\
    \ v.end());\n        return v;\n    }\n\n    static std::vector<std::pair<u64,\
    \ int>> exp_factorize(u64 n) {\n        std::vector<u64> pf = factorize(n);\n\
    \        if (pf.empty()) {\n            return {};\n        }\n        std::vector<std::pair<u64,\
    \ int>> res;\n        res.emplace_back(pf.front(), 1);\n        for (int i = 1;\
    \ i < (int)pf.size(); i++) {\n            if (res.back().first == pf[i]) {\n \
    \               res.back().second++;\n            } else {\n                res.emplace_back(pf[i],\
    \ 1);\n            }\n        }\n\n        return res;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @docs docs/math/rho.md\n */\n#line 5 \"src/math/primitive_root.hpp\"\
    \nnamespace kyopro {\n\n/**\n * @brief \u539F\u59CB\u6839\n */\ninline uint64_t\
    \ primitive_root(uint64_t p) {\n    if (p == 2) return 1;\n    auto pf = kyopro::rho::factorize(p\
    \ - 1);\n    pf.erase(std::unique(pf.begin(), pf.end()), pf.end());\n    for (auto&\
    \ q : pf) {\n        q = (p - 1) / q;\n    }\n    using ull = unsigned long long;\n\
    \    if (dynamic_modint<uint64_t>::get_mod() != p) {\n        dynamic_modint<uint64_t>::set_mod(p);\n\
    \    }\n    xor_shift rng(2023);\n    while (1) {\n        dynamic_modint<uint64_t>\
    \ g(rng());\n        if (g.val() == 0) continue;\n        bool is_ok = true;\n\
    \n        for (auto q : pf) {\n            if (dynamic_modint<uint64_t>(g).pow(q).val()\
    \ == 1) {\n                is_ok = false;\n                break;\n          \
    \  }\n        }\n        if (is_ok) {\n            return g.val();\n        }\n\
    \    }\n}\n};  // namespace kyopro\n"
  code: "#pragma once\n#include \"../math/dynamic_modint.hpp\"\n#include \"../math/rho.hpp\"\
    \n#include \"../random/xor_shift.hpp\"\nnamespace kyopro {\n\n/**\n * @brief \u539F\
    \u59CB\u6839\n */\ninline uint64_t primitive_root(uint64_t p) {\n    if (p ==\
    \ 2) return 1;\n    auto pf = kyopro::rho::factorize(p - 1);\n    pf.erase(std::unique(pf.begin(),\
    \ pf.end()), pf.end());\n    for (auto& q : pf) {\n        q = (p - 1) / q;\n\
    \    }\n    using ull = unsigned long long;\n    if (dynamic_modint<uint64_t>::get_mod()\
    \ != p) {\n        dynamic_modint<uint64_t>::set_mod(p);\n    }\n    xor_shift\
    \ rng(2023);\n    while (1) {\n        dynamic_modint<uint64_t> g(rng());\n  \
    \      if (g.val() == 0) continue;\n        bool is_ok = true;\n\n        for\
    \ (auto q : pf) {\n            if (dynamic_modint<uint64_t>(g).pow(q).val() ==\
    \ 1) {\n                is_ok = false;\n                break;\n            }\n\
    \        }\n        if (is_ok) {\n            return g.val();\n        }\n   \
    \ }\n}\n};  // namespace kyopro\n"
  dependsOn:
  - src/math/dynamic_modint.hpp
  - src/internal/barrett.hpp
  - src/internal/montgomery.hpp
  - src/internal/type_traits.hpp
  - src/math/rho.hpp
  - src/math/gcd.hpp
  - src/math/miller.hpp
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/math/primitive_root.hpp
  requiredBy: []
  timestamp: '2023-05-15 06:47:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Primitive_Root.test.cpp
documentation_of: src/math/primitive_root.hpp
layout: document
redirect_from:
- /library/src/math/primitive_root.hpp
- /library/src/math/primitive_root.hpp.html
title: "\u539F\u59CB\u6839"
---