---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':heavy_check_mark:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: gcd
  - icon: ':heavy_check_mark:'
    path: src/math/static_modint.hpp
    title: static modint
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: "Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)"
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/yosupo_judge/convolution/Subset_Convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n#line\
    \ 2 \"src/math/static_modint.hpp\"\n#include <cassert>\n#include <cstdint>\n#include\
    \ <iostream>\n\n#line 3 \"src/internal/type_traits.hpp\"\n#include <limits>\n\
    #include <numeric>\n#include <typeinfo>\n#line 7 \"src/internal/type_traits.hpp\"\
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
    };  // namespace internal\n};  // namespace kyopro\n\n/**\n * @brief Type Traits\n\
    \ * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\n#line 3\
    \ \"src/math/gcd.hpp\"\n#include <cmath>\n#include <tuple>\nnamespace kyopro {\n\
    template <typename T> constexpr inline T _gcd(T a, T b) noexcept {\n    assert(a\
    \ >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a),\
    \ __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n\
    \    while (a != b) {\n        if (!a || !b) {\n            return a + b;\n  \
    \      }\n        if (a >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\n\ntemplate <typename T>\nconstexpr\
    \ inline T ext_gcd(T a, T b, T& x, T& y) noexcept {\n    x = 1, y = 0;\n    T\
    \ nx = 0, ny = 1;\n    while (b) {\n        T q = a / b;\n        std::tie(a,\
    \ b) = std::pair<T, T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx,\
    \ x - nx * q};\n        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n \
    \   }\n    return a;\n}\n};  // namespace kyopro\n\n/**\n * @brief gcd\n*/\n#line\
    \ 8 \"src/math/static_modint.hpp\"\nnamespace kyopro {\ntemplate <int _mod, std::enable_if_t<_mod\
    \ >= 0>* = nullptr>\nclass modint : internal::modint_base {\n    using mint =\
    \ modint<_mod>;\n    using i32 = std::int32_t;\n    using u32 = std::uint32_t;\n\
    \    using i64 = std::int64_t;\n    using u64 = std::uint64_t;\n\n    u32 v;\n\
    \    constexpr u32 normalize(i64 v_) const noexcept {\n        v_ %= _mod;\n \
    \       if (v_ < 0) {\n            v_ += _mod;\n        }\n        return v_;\n\
    \    }\n\npublic:\n    static constexpr u32 mod() noexcept { return _mod; }\n\
    \    constexpr modint() noexcept : v(0) {}\n    constexpr modint(i64 v_) noexcept\
    \ : v(normalize(v_)) {}\n\n    static mint raw(u32 a) {\n        mint m;\n   \
    \     m.v = a;\n        return m;\n    }\n    constexpr u32 val() const noexcept\
    \ { return v; }\n    constexpr mint& operator+=(const mint& rhs) noexcept {\n\
    \        v += rhs.val();\n        if (v >= _mod) {\n            v -= _mod;\n \
    \       }\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ mint& rhs) noexcept {\n        v += _mod - rhs.val();\n        if (v >= _mod)\
    \ {\n            v -= _mod;\n        }\n        return (*this);\n    }\n    constexpr\
    \ mint& operator*=(const mint& rhs) noexcept {\n        v = (u64)v * rhs.val()\
    \ % _mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const noexcept {\n        return mint(*this) += r;\n    }\n    constexpr\
    \ mint operator-(const mint& r) const noexcept {\n        return mint(*this) -=\
    \ r;\n    }\n    constexpr mint operator*(const mint& r) const noexcept {\n  \
    \      return mint(*this) *= r;\n    }\n\n    constexpr mint& operator+=(i64 rhs)\
    \ noexcept {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n\
    \    constexpr mint& operator-=(i64 rhs) noexcept {\n        (*this) -= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator*=(i64 rhs) noexcept\
    \ {\n        (*this) *= mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ friend mint operator+(i64 l, const mint& r) noexcept {\n        return mint(l)\
    \ += r;\n    }\n    constexpr friend mint operator-(i64 l, const mint& r) noexcept\
    \ {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(i64\
    \ l, const mint& r) noexcept {\n        return mint(l) *= r;\n    }\n\n    constexpr\
    \ mint operator+(i64 r) const noexcept { return mint(*this) += r; }\n    constexpr\
    \ mint operator-(i64 r) const noexcept { return mint(*this) -= r; }\n    constexpr\
    \ mint operator*(i64 r) const noexcept { return mint(*this) *= r; }\n    constexpr\
    \ mint operator-() noexcept {\n        return raw(mint::mod() - this->val());\n\
    \    }\n\n    constexpr mint& operator=(i64 r) noexcept { return (*this) = mint(r);\
    \ }\n    \n\n    constexpr bool operator==(const mint& r) const noexcept {\n \
    \       return (*this).val() == r.val();\n    }\n\n    template <typename T, internal::is_integral_t<T>*\
    \ = nullptr>\n    constexpr mint pow(T e) const noexcept {\n        mint ans(1),\
    \ base(*this);\n        while (e) {\n            if (e & 1) {\n              \
    \  ans *= base;\n            }\n            base *= base;\n            e >>= 1;\n\
    \        }\n        return ans;\n    }\n\n    constexpr mint inv() const noexcept\
    \ {\n        long long x, y;\n        auto d = ext_gcd((long long)_mod, (long\
    \ long)v, x, y);\n        assert(d == 1);\n        return mint(y);\n    }\n\n\
    \    constexpr mint& operator/=(const mint& r) noexcept {\n        return (*this)\
    \ *= r.inv();\n    }\n    constexpr mint operator/(const mint& r) const noexcept\
    \ {\n        return mint(*this) *= r.inv();\n    }\n    constexpr friend mint\
    \ operator/(const mint& l, i64 r) noexcept {\n        return mint(l) /= mint(r);\n\
    \    }\n    constexpr friend mint operator/(i64 l, const mint& r) noexcept {\n\
    \        return mint(l) /= mint(r);\n    }\n};\n};  // namespace kyopro\n\n/**\n\
    \ * @brief static modint\n */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n\
    #include <stdio.h>\n#include <string>\n#line 6 \"src/stream.hpp\"\n\nnamespace\
    \ kyopro {\n\ninline void single_read(char& c) {\n    c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n}\ntemplate <typename T, internal::is_integral_t<T>*\
    \ = nullptr>\ninline void single_read(T& a) {\n    a = 0;\n    bool is_negative\
    \ = false;\n    char c = getchar_unlocked();\n    while (isspace(c)) {\n     \
    \   c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true, c =\
    \ getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 * a + (c - '0');\n\
    \        c = getchar_unlocked();\n    }\n    if (is_negative) a *= -1;\n}\ntemplate\
    \ <typename T, internal::is_modint_t<T>* = nullptr>\ninline void single_read(T&\
    \ a) {\n    long long x;\n    single_read(x);\n    a = T(x);\n}\ninline void single_read(std::string&\
    \ str) noexcept {\n    char c = getchar_unlocked();\n    while (isspace(c)) c\
    \ = getchar_unlocked();\n    while (!isspace(c)) {\n        str += c;\n      \
    \  c = getchar_unlocked();\n    }\n}\ntemplate<typename T>\ninline void read(T&\
    \ x) noexcept {single_read(x);}\ntemplate <typename Head, typename... Tail>\n\
    inline void read(Head& head, Tail&... tail) noexcept {\n    single_read(head),\
    \ read(tail...);\n}\n\ninline void single_write(char c) noexcept { putchar_unlocked(c);\
    \ }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\ninline void\
    \ single_write(T a) noexcept {\n    if (!a) {\n        putchar_unlocked('0');\n\
    \        return;\n    }\n    if constexpr (std::is_signed_v<T>) {\n        if\
    \ (a < 0) putchar_unlocked('-'), a *= -1;\n    }\n    constexpr int d = std::numeric_limits<T>::digits10;\n\
    \    char s[d + 1];\n    int now = d + 1;\n    while (a) {\n        s[--now] =\
    \ (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now <= d) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T, internal::is_modint_t<T>* = nullptr>\ninline void single_write(T\
    \ a) noexcept {\n    single_write(a.val());\n}\ninline void single_write(const\
    \ std::string& str) noexcept {\n    for (auto c : str) {\n        putchar_unlocked(c);\n\
    \    }\n}\ntemplate <typename T> inline void write(T x) noexcept { single_write(x);\
    \ }\ntemplate <typename Head, typename... Tail>\ninline void write(Head head,\
    \ Tail... tail) noexcept {\n    single_write(head);\n    putchar_unlocked(' ');\n\
    \    write(tail...);\n}\ntemplate <typename... Args> inline void put(Args... x)\
    \ noexcept {\n    write(x...);\n    putchar_unlocked('\\n');\n}\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)\n */\n#line\
    \ 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i, n) for (int\
    \ i = 0; i < (n); i++)\n#define all(x) std::begin(x), std::end(x)\n#define popcount(x)\
    \ __builtin_popcountll(x)\nusing i128 = __int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = std::numeric_limits<int>::max() / 2;\nconstexpr ll\
    \ infl = std::numeric_limits<ll>::max() / 2;\nconst long double pi = acosl(-1);\n\
    constexpr int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr int dy[] = {0,\
    \ 1, 0, -1, 1, 1, -1, -1, 0};\ntemplate <typename T1, typename T2> constexpr inline\
    \ bool chmax(T1& a, T2 b) {\n    return a < b && (a = b, true);\n}\ntemplate <typename\
    \ T1, typename T2> constexpr inline bool chmin(T1& a, T2 b) {\n    return a >\
    \ b && (a = b, true);\n}\n\n/**\n * @brief Template\n*/\n#line 3 \"src/convolution/subset_convolution.hpp\"\
    \n\nnamespace kyopro {\nnamespace internal {\n\ntemplate <typename T> void add(std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    if (a.size() < b.size()) a.resize(b.size());\n\
    \    for (int i = 0; i < (int)b.size(); ++i) a[i] += b[i];\n}\ntemplate <typename\
    \ T> void sub(std::vector<T>& a, const std::vector<T>& b) {\n    if (a.size()\
    \ < b.size()) a.resize(b.size());\n    for (int i = 0; i < (int)b.size(); ++i)\
    \ a[i] -= b[i];\n}\n\ntemplate <typename T> void ranked_zeta(int n, std::vector<std::vector<T>>&\
    \ a) {\n    for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < (int)a.size();\
    \ ++j) {\n            if (j >> i & 1) add(a[j], a[j & ~(1 << i)]);\n        }\n\
    \    }\n}\ntemplate <typename T>\nvoid ranked_mobius(int n, std::vector<std::vector<T>>&\
    \ a) {\n    for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < (int)a.size();\
    \ ++j) {\n            if (j >> i & 1) sub(a[j], a[j & ~(1 << i)]);\n        }\n\
    \    }\n}\n};  // namespace internal\n\n\n/**\n * @brief Subset Convolution\n\
    \ */\ntemplate <typename T>\nstd::vector<T> subset_convolution(int n, std::vector<T>\
    \ a, std::vector<T> b) {\n    std::vector<std::vector<T>> ranked_a(a.size()),\
    \ ranked_b(b.size());\n    for (int i = 0; i < (1 << n); ++i) {\n        ranked_a[i].resize(__builtin_popcount(i)\
    \ + 1);\n        ranked_b[i].resize(__builtin_popcount(i) + 1);\n\n        ranked_a[i][__builtin_popcount(i)]\
    \ = a[i];\n        ranked_b[i][__builtin_popcount(i)] = b[i];\n    }\n\n    internal::ranked_zeta(n,\
    \ ranked_a), internal::ranked_zeta(n, ranked_b);\n    for (int i = 0; i < (1 <<\
    \ n); ++i) {\n        std::vector<T> c(ranked_a[i].size() + ranked_b[i].size());\n\
    \        for (int j = 0; j < (int)ranked_b[i].size(); ++j) {\n            for\
    \ (int k = 0; k < (int)ranked_b[i].size(); ++k) {\n                c[j + k] +=\
    \ ranked_a[i][j] * ranked_b[i][k];\n            }\n        }\n        swap(ranked_a[i],\
    \ c);\n    }\n\n    internal::ranked_mobius(n, ranked_a);\n    std::vector<T>\
    \ answer(a.size());\n    for (int i = 0; i < (int)a.size(); ++i) {\n        answer[i]\
    \ = ranked_a[i][__builtin_popcount(i)];\n    }\n    return answer;\n}\n};  //\
    \ namespace kyopro\n#line 7 \"test/yosupo_judge/convolution/Subset_Convolution.test.cpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nusing mint = modint<998244353>;\n\
    \nint main() {\n    int n;\n    read(n);\n    vector<mint> a(1 << n), b(1 << n);\n\
    \    rep(i, (int)a.size()) read(a[i]);\n    rep(i, (int)b.size()) read(b[i]);\n\
    \n    vector c = subset_convolution(n, a, b);\n\n    rep(i, (int)c.size()) put(c[i]);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n\
    #include \"../../../src/math/static_modint.hpp\"\n#include \"../../../src/stream.hpp\"\
    \n#include \"../../../src/template.hpp\"\n#include \"../../../src/convolution/subset_convolution.hpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nusing mint = modint<998244353>;\n\
    \nint main() {\n    int n;\n    read(n);\n    vector<mint> a(1 << n), b(1 << n);\n\
    \    rep(i, (int)a.size()) read(a[i]);\n    rep(i, (int)b.size()) read(b[i]);\n\
    \n    vector c = subset_convolution(n, a, b);\n\n    rep(i, (int)c.size()) put(c[i]);\n\
    }"
  dependsOn:
  - src/math/static_modint.hpp
  - src/internal/type_traits.hpp
  - src/math/gcd.hpp
  - src/stream.hpp
  - src/template.hpp
  - src/convolution/subset_convolution.hpp
  isVerificationFile: true
  path: test/yosupo_judge/convolution/Subset_Convolution.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 11:09:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/convolution/Subset_Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/convolution/Subset_Convolution.test.cpp
- /verify/test/yosupo_judge/convolution/Subset_Convolution.test.cpp.html
title: test/yosupo_judge/convolution/Subset_Convolution.test.cpp
---