---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/lazy_segtree.hpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  - icon: ':question:'
    path: src/math/gcd.hpp
    title: gcd
  - icon: ':question:'
    path: src/math/static_modint.hpp
    title: static modint
  - icon: ':question:'
    path: src/stream.hpp
    title: "Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #include <iostream>\n#line 2 \"src/data-structure/lazy_segtree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nnamespace kyopro {\n\ntemplate <class S,\n   \
    \       class F,\n          auto op,\n          auto e,\n          auto composition,\n\
    \          auto id,\n          auto mapping>\nclass lazy_segtree {\n    int lg,\
    \ sz, n;\n    std::vector<S> dat;\n    std::vector<F> lazy;\n\npublic:\n    lazy_segtree()\
    \ {}\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}\n    lazy_segtree(const\
    \ std::vector<S>& a) : n((int)a.size()) {\n        sz = 1, lg = 0;\n        while\
    \ (sz <= n) {\n            sz <<= 1;\n            lg++;\n        }\n\n       \
    \ dat = std::vector<S>(sz << 1, e());\n        lazy = std::vector<F>(sz, id());\n\
    \        for (int i = 0; i < n; ++i) {\n            set(i, a[i]);\n        }\n\
    \        build();\n    }\n\npublic:\n    void set(int i, const S& v) {\n     \
    \   assert(0 <= i && i < sz);\n        dat[i + sz] = v;\n    }\n    void build()\
    \ {\n        for (int i = sz - 1; i > 0; --i) {\n            push_up(i);\n   \
    \     }\n    }\n\nprivate:\n    void all_apply(int p, const F& f) {\n        dat[p]\
    \ = mapping(dat[p], f);\n        if (p < sz) lazy[p] = composition(lazy[p], f);\n\
    \    }\n    void push_up(int k) { dat[k] = op(dat[k << 1 | 0], dat[k << 1 | 1]);\
    \ }\n    void push_down(int p) {\n        if (lazy[p] == id()) {\n           \
    \ return;\n        }\n        all_apply(p << 1 | 0, lazy[p]);\n        all_apply(p\
    \ << 1 | 1, lazy[p]);\n        lazy[p] = id();\n    }\n\npublic:\n    S operator[](int\
    \ p) {\n        assert(0 <= p && p < n);\n        p += sz;\n        for (int i\
    \ = lg; i > 0; --i) push_down(p >> i);\n        return dat[p];\n    }\n    S fold(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r)\
    \ return e();\n\n        l += sz, r += sz;\n        for (int i = lg; i > 0; --i)\
    \ {\n            if (((l >> i) << i) != l) {\n                push_down(l >> i);\n\
    \            }\n            if (((r >> i) << i) != r) {\n                push_down((r\
    \ - 1) >> i);\n            }\n        }\n\n        S sml = e(), smr = e();\n \
    \       while (l < r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n   \
    \         if (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n\
    \        }\n\n        return op(sml, smr);\n    }\n    void apply(int l, int r,\
    \ const F& v) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l ==\
    \ r) return;\n        l += sz, r += sz;\n        for (int i = lg; i > 0; --i)\
    \ {\n            if (((l >> i) << i) != l) {\n                push_down(l >> i);\n\
    \            }\n            if (((r >> i) << i) != r) {\n                push_down((r\
    \ - 1) >> i);\n            }\n        }\n        {\n            int l2 = l, r2\
    \ = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ v);\n                if (r & 1) all_apply(--r, v);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = l2;\n            r =\
    \ r2;\n        }\n\n        for (int i = 1; i <= lg; ++i) {\n            if (((l\
    \ >> i) << i) != l) push_up(l >> i);\n            if (((r >> i) << i) != r) push_up((r\
    \ - 1) >> i);\n        }\n    }\n};\n};  // namespace kyopro\n\n/**\n * @brief\
    \ Lazy Segment Tree\n */\n#line 3 \"src/math/static_modint.hpp\"\n#include <cstdint>\n\
    #line 5 \"src/math/static_modint.hpp\"\n\n#line 3 \"src/internal/type_traits.hpp\"\
    \n#include <limits>\n#include <numeric>\n#include <typeinfo>\n#line 7 \"src/internal/type_traits.hpp\"\
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
    \ mint operator*(i64 r) const noexcept { return mint(*this) *= r; }\n\n    constexpr\
    \ mint& operator=(i64 r) noexcept { return (*this) = mint(r); }\n\n    constexpr\
    \ bool operator==(const mint& r) const noexcept {\n        return (*this).val()\
    \ == r.val();\n    }\n\n    template <typename T, internal::is_integral_t<T>*\
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
    \ 6 \"test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp\"\nusing\
    \ mint = kyopro::modint<998244353>;\nstruct S {\n    mint s;\n    int len;\n};\n\
    inline S op(S a, S b) { return S{a.s + b.s, a.len + b.len}; }\ninline S e() {\
    \ return S{0, 0}; }\nusing Affine = std::pair<mint, mint>;\ninline Affine composition(Affine\
    \ g, Affine f) {\n    // f(g)\n    // a(cx+d)+b\n    auto a = f.first, b = f.second;\n\
    \    auto c = g.first, d = g.second;\n    return Affine(a * c, a * d + b);\n}\n\
    inline Affine id() { return Affine(1, 0); }\ninline S mapping(S d, Affine f) {\n\
    \    mint a = f.first, b = f.second;\n    d.s *= a, d.s += b * d.len;\n    return\
    \ d;\n};\n\nint main() {\n    int n, q;\n    kyopro::read(n, q);\n    kyopro::lazy_segtree<S,\
    \ Affine, op, e, composition, id, mapping> sg(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        mint a;\n        kyopro::read(a);\n        sg.set(i, {a, 1});\n\
    \    }\n    sg.build();\n    while (q--) {\n        int t;\n        kyopro::read(t);\n\
    \        if (t == 0) {\n            int l, r;\n            mint b, c;\n      \
    \      kyopro::read(l, r, b, c);\n            sg.apply(l, r, Affine(b, c));\n\
    \        } else {\n            int l, r;\n            kyopro::read(l, r);\n  \
    \          auto res = sg.fold(l, r);\n            kyopro::put(res.s.val());\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <iostream>\n#include \"../../../src/data-structure/lazy_segtree.hpp\"\
    \n#include \"../../../src/math/static_modint.hpp\"\n#include \"../../../src/stream.hpp\"\
    \nusing mint = kyopro::modint<998244353>;\nstruct S {\n    mint s;\n    int len;\n\
    };\ninline S op(S a, S b) { return S{a.s + b.s, a.len + b.len}; }\ninline S e()\
    \ { return S{0, 0}; }\nusing Affine = std::pair<mint, mint>;\ninline Affine composition(Affine\
    \ g, Affine f) {\n    // f(g)\n    // a(cx+d)+b\n    auto a = f.first, b = f.second;\n\
    \    auto c = g.first, d = g.second;\n    return Affine(a * c, a * d + b);\n}\n\
    inline Affine id() { return Affine(1, 0); }\ninline S mapping(S d, Affine f) {\n\
    \    mint a = f.first, b = f.second;\n    d.s *= a, d.s += b * d.len;\n    return\
    \ d;\n};\n\nint main() {\n    int n, q;\n    kyopro::read(n, q);\n    kyopro::lazy_segtree<S,\
    \ Affine, op, e, composition, id, mapping> sg(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        mint a;\n        kyopro::read(a);\n        sg.set(i, {a, 1});\n\
    \    }\n    sg.build();\n    while (q--) {\n        int t;\n        kyopro::read(t);\n\
    \        if (t == 0) {\n            int l, r;\n            mint b, c;\n      \
    \      kyopro::read(l, r, b, c);\n            sg.apply(l, r, Affine(b, c));\n\
    \        } else {\n            int l, r;\n            kyopro::read(l, r);\n  \
    \          auto res = sg.fold(l, r);\n            kyopro::put(res.s.val());\n\
    \        }\n    }\n}"
  dependsOn:
  - src/data-structure/lazy_segtree.hpp
  - src/math/static_modint.hpp
  - src/internal/type_traits.hpp
  - src/math/gcd.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
---
