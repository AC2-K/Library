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
  - icon: ':x:'
    path: src/math/combination.hpp
    title: "\u4E8C\u9805\u4FC2\u6570"
  - icon: ':question:'
    path: src/math/dynamic_modint.hpp
    title: "\u52D5\u7684modint"
  - icon: ':question:'
    path: src/stream.hpp
    title: fastIO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <iostream>\n#line 2 \"src/math/combination.hpp\"\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\nnamespace kyopro {\n\n/**\n * @brief\
    \ \u4E8C\u9805\u4FC2\u6570\n */\ntemplate <typename mint, int sz> class combination\
    \ {\n    const int M;\n    mint fac[sz + 1], ifac[sz + 1];\n\npublic:\n    explicit\
    \ combination() : M(std::min<int>(mint::mod(), sz)) {\n        assert(mint::mod());\n\
    \        fac[0] = mint(1), ifac[0] = mint(1), fac[1] = mint(1),\n        ifac[1]\
    \ = mint(1);\n\n        for (int i = 2; i <= M; ++i) {\n            fac[i] = fac[i\
    \ - 1] * i;\n        }\n\n        ifac[M - 1] = mint(1) / fac[M - 1];\n      \
    \  for (int i = M - 2; i > 1; --i) {\n            ifac[i] = ifac[i + 1] * (i +\
    \ 1);\n        }\n    }\n\n    constexpr mint fact(int n) const {\n        assert(0\
    \ <= n && n <= sz);\n        return fac[n];\n    }\n    constexpr mint ifact(int\
    \ n) const {\n        assert(0 <= n && n <= sz);\n        return ifac[n];\n  \
    \  }\n\n    constexpr mint binom(int n, int r) const {\n        assert(n >= r);\n\
    \        return fact(n) * ifact(r) * ifact(n - r);\n    }\n    constexpr mint\
    \ perm(int n, int r) const {\n        assert(n >= r);\n        return fact(n)\
    \ * ifact(n - r);\n    }\n};\n\n};  // namespace kyopro\n\n\n/**\n * @docs docs/math/combination.md\n\
    */\n#line 2 \"src/internal/barrett.hpp\"\n#include <cstdint>\nnamespace kyopro\
    \ {\nnamespace internal {\n\n/**\n * @brief Barrett Reduction\n */\nclass barrett\
    \ {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\
    \n    u32 m;\n    u64 im;\n\npublic:\n    constexpr explicit barrett() : m(0),\
    \ im(0) {}\n    constexpr explicit barrett(u32 m)\n        : m(m), im(static_cast<u64>(-1)\
    \ / m + 1) {}\n\n    constexpr u32 get_mod() const { return m; }\n    constexpr\
    \ u32 reduce(u32 a) const { return mul(1, a); }\n    constexpr u32 mul(u32 a,\
    \ u32 b) const {\n        u64 z = (u64)a * b;\n        u64 x = (u64)(((u128)(z)*im)\
    \ >> 64);\n        u64 y = x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n\
    \    }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n * @ref\n\
    \ * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */\n#line 3 \"src/internal/montgomery.hpp\"\n#include <limits>\n#include <numeric>\n\
    #line 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\nnamespace kyopro\
    \ {\nnamespace internal {\ntemplate <typename... Args> struct first_enabled {};\n\
    \ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
    \ T>, Args...> {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
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
    \   using mint = barrett_modint<id>;\n    using u32 = uint32_t;\n    using u64\
    \ = uint64_t;\n\n    using i32 = int32_t;\n    using i64 = int64_t;\n    using\
    \ br = internal::barrett;\n\n    static br brt;\n    u32 v;\n\npublic:\n    static\
    \ void set_mod(u32 mod_) { brt = br(mod_); }\n\npublic:\n    explicit constexpr\
    \ barrett_modint() noexcept : v(0) { assert(mod()); }\n    explicit constexpr\
    \ barrett_modint(i64 v_) noexcept : v() {\n        assert(mod());\n        if\
    \ (v_ < 0) v_ = (i64)mod() - v_;\n        v = brt.reduce(v_);\n    }\n\n    u32\
    \ val() const noexcept { return v; }\n    static u32 mod() { return brt.get_mod();\
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
    \ { return (*this) *= r.inv(); }\n\n    friend mint operator+(const mint& lhs,\
    \ const mint& rhs) noexcept {\n        return mint(lhs) += rhs;\n    }\n    friend\
    \ mint operator-(const mint& lhs, const mint& rhs) noexcept {\n        return\
    \ mint(lhs) -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint&\
    \ rhs) noexcept {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) noexcept {\n        return mint(lhs) /= rhs;\n \
    \   }\n    friend bool operator==(const mint& lhs, const mint& rhs) noexcept {\n\
    \        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const mint&\
    \ lhs, const mint& rhs) noexcept {\n        return lhs._v != rhs._v;\n    }\n\n\
    \    constexpr mint& operator+=(i64 r) noexcept { return (*this) += mint(r); }\n\
    \    constexpr mint& operator-=(i64 r) noexcept { return (*this) -= mint(r); }\n\
    \    constexpr mint& operator*=(i64 r) noexcept { return (*this) *= mint(r); }\n\
    \n    friend mint operator+(i64 l, const mint& r) noexcept { return mint(l) +=\
    \ r; }\n    friend mint operator+(const mint& l, i64 r) noexcept { return mint(l)\
    \ += r; }\n    friend mint operator-(i64 l, const mint& r) noexcept { return mint(l)\
    \ -= r; }\n    friend mint operator-(const mint& l, i64 r) noexcept { return mint(l)\
    \ -= r; }\n    friend mint operator*(i64 l, const mint& r) noexcept { return mint(l)\
    \ *= r; }\n    friend mint operator*(const mint& l, i64 r) noexcept { return mint(l)\
    \ *= r; }\n\n    constexpr mint operator+() const noexcept { return *this; }\n\
    \    constexpr mint operator-() const noexcept { return mint() - *this; }\n  \
    \  \n    template <typename T> mint pow(T e) const noexcept {\n        mint res(1),\
    \ base(*this);\n\n        while (e) {\n            if (e & 1) {\n            \
    \    res *= base;\n            }\n            e >>= 1;\n            base *= base;\n\
    \        }\n        return res;\n    }\n    constexpr mint inv() const noexcept\
    \ { return pow(mod() - 2); }\n};\n};  // namespace kyopro\ntemplate <int id>\n\
    typename kyopro::barrett_modint<id>::br kyopro::barrett_modint<id>::brt;\n\nnamespace\
    \ kyopro {\ntemplate <typename T, int id = -1>\nclass montgomery_modint : internal::modint_base\
    \ {\n    using LargeT = internal::double_size_uint_t<T>;\n    static T _mod;\n\
    \    static internal::Montgomery<T> mr;\n\npublic:\n    static void set_mod(T\
    \ mod_) {\n        mr.set_mod(mod_);\n        _mod = mod_;\n    }\n\n    static\
    \ T mod() { return _mod; }\n\nprivate:\n    T v;\n\npublic:\n    montgomery_modint(T\
    \ v_ = 0) {\n        assert(_mod);\n        v = mr.generate(v_);\n    }\n    T\
    \ val() const { return mr.reduce(v); }\n\n    using mint = montgomery_modint<T,\
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
    \n/**\n * @brief \u52D5\u7684modint\n * @docs docs/math/dynamic_modint.md\n */\n\
    #line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n\
    #line 6 \"src/stream.hpp\"\n\nnamespace kyopro {\n// read\nvoid single_read(char&\
    \ c) {\n    c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\nvoid single_read(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_read(T& a) {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\nvoid single_read(std::string& str) {\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n    while (!isspace(c)) {\n \
    \       str += c;\n        c = getchar_unlocked();\n    }\n}\ntemplate<typename\
    \ T>\nvoid read(T& x) {single_read(x);}\ntemplate <typename Head, typename...\
    \ Tail>\nvoid read(Head& head, Tail&... tail) {\n    single_read(head), read(tail...);\n\
    }\n\n// write\nvoid single_write(char c) { putchar_unlocked(c); }\ntemplate <typename\
    \ T, internal::is_integral_t<T>* = nullptr>\nvoid single_write(T a) {\n    if\
    \ (!a) {\n        putchar_unlocked('0');\n        return;\n    }\n    if (a <\
    \ 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int now = 37;\n   \
    \ while (a) {\n        s[--now] = (char)'0' + a % 10;\n        a /= 10;\n    }\n\
    \    while (now < 37) putchar_unlocked(s[now++]);\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_write(T a) {\n    single_write(a.val());\n}\n\nvoid\
    \ single_write(const std::string& str) {\n    for (auto c : str) {\n        putchar_unlocked(c);\n\
    \    }\n}\n\ntemplate<typename T>\nvoid write(T x) { single_write(x); }\ntemplate\
    \ <typename Head, typename... Tail> void write(Head head, Tail... tail) {\n  \
    \  single_write(head);\n    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate\
    \ <typename... Args> void put(Args... x) {\n    write(x...);\n    putchar_unlocked('\\\
    n');\n}\n};  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 7 \"test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp\"\
    \nusing mint = kyopro::barrett_modint<10>;\nusing namespace std;\nint main() {\n\
    \    int t, m;\n    kyopro::read(t, m);\n    mint::set_mod(m);\n    kyopro::combination<mint,\
    \ (int)1e7> solver;\n    while (t--) {\n        int n, r;\n        kyopro::read(n,\
    \ r);\n        if (n < r) {\n            kyopro::put(0);\n        } else {\n \
    \           kyopro::put(solver.binom(n, r).val());\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <iostream>\n#include \"../../../src/math/combination.hpp\"\n#include\
    \ \"../../../src/math/dynamic_modint.hpp\"\n#include \"../../../src/stream.hpp\"\
    \nusing mint = kyopro::barrett_modint<10>;\nusing namespace std;\nint main() {\n\
    \    int t, m;\n    kyopro::read(t, m);\n    mint::set_mod(m);\n    kyopro::combination<mint,\
    \ (int)1e7> solver;\n    while (t--) {\n        int n, r;\n        kyopro::read(n,\
    \ r);\n        if (n < r) {\n            kyopro::put(0);\n        } else {\n \
    \           kyopro::put(solver.binom(n, r).val());\n        }\n    }\n}"
  dependsOn:
  - src/math/combination.hpp
  - src/math/dynamic_modint.hpp
  - src/internal/barrett.hpp
  - src/internal/montgomery.hpp
  - src/internal/type_traits.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
  requiredBy: []
  timestamp: '2023-09-27 11:04:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
- /verify/test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp.html
title: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
---
