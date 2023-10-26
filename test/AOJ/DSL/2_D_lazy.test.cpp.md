---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/lazy_segtree.hpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/stream.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"test/AOJ/DSL/2_D_lazy.test.cpp\"\n#define PROBLEM \\\n \
    \   \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\n\n#line\
    \ 2 \"src/data-structure/lazy_segtree.hpp\"\n#include <cassert>\n#include <vector>\n\
    namespace kyopro {\n\ntemplate <class S,\n          class F,\n          auto op,\n\
    \          auto e,\n          auto composition,\n          auto id,\n        \
    \  auto mapping>\nclass lazy_segtree {\n    int lg, sz, n;\n    std::vector<S>\
    \ dat;\n    std::vector<F> lazy;\n\npublic:\n    lazy_segtree() {}\n    lazy_segtree(int\
    \ n) : lazy_segtree(std::vector<S>(n, e())) {}\n    lazy_segtree(const std::vector<S>&\
    \ a) : n((int)a.size()) {\n        sz = 1, lg = 0;\n        while (sz <= n) {\n\
    \            sz <<= 1;\n            lg++;\n        }\n\n        dat = std::vector<S>(sz\
    \ << 1, e());\n        lazy = std::vector<F>(sz, id());\n        for (int i =\
    \ 0; i < n; ++i) {\n            set(i, a[i]);\n        }\n        build();\n \
    \   }\n\npublic:\n    void set(int i, const S& v) {\n        assert(0 <= i &&\
    \ i < sz);\n        dat[i + sz] = v;\n    }\n    void build() {\n        for (int\
    \ i = sz - 1; i > 0; --i) {\n            push_up(i);\n        }\n    }\n\nprivate:\n\
    \    void all_apply(int p, const F& f) {\n        dat[p] = mapping(dat[p], f);\n\
    \        if (p < sz) lazy[p] = composition(lazy[p], f);\n    }\n    void push_up(int\
    \ k) { dat[k] = op(dat[k << 1 | 0], dat[k << 1 | 1]); }\n    void push_down(int\
    \ p) {\n        if (lazy[p] == id()) {\n            return;\n        }\n     \
    \   all_apply(p << 1 | 0, lazy[p]);\n        all_apply(p << 1 | 1, lazy[p]);\n\
    \        lazy[p] = id();\n    }\n\npublic:\n    S operator[](int p) {\n      \
    \  assert(0 <= p && p < n);\n        p += sz;\n        for (int i = lg; i > 0;\
    \ --i) push_down(p >> i);\n        return dat[p];\n    }\n    S fold(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return\
    \ e();\n\n        l += sz, r += sz;\n        for (int i = lg; i > 0; --i) {\n\
    \            if (((l >> i) << i) != l) {\n                push_down(l >> i);\n\
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
    \ Lazy Segment Tree\n */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include\
    \ <stdio.h>\n#include <string>\n#line 2 \"src/internal/type_traits.hpp\"\n#include\
    \ <iostream>\n#include <limits>\n#include <numeric>\n#include <typeinfo>\n#include\
    \ <cstdint>\n\nnamespace kyopro {\nnamespace internal {\ntemplate <typename...\
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
    \ */\n#line 6 \"src/stream.hpp\"\n\nnamespace kyopro {\n\ninline void single_read(char&\
    \ c) {\n    c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\ninline void single_read(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\ninline void single_read(T& a) {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\ninline void single_read(std::string& str) noexcept {\n    char\
    \ c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n  \
    \  while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\ntemplate<typename T>\ninline void read(T& x) noexcept {single_read(x);}\n\
    template <typename Head, typename... Tail>\ninline void read(Head& head, Tail&...\
    \ tail) noexcept {\n    single_read(head), read(tail...);\n}\n\ninline void single_write(char\
    \ c) noexcept { putchar_unlocked(c); }\ntemplate <typename T, internal::is_integral_t<T>*\
    \ = nullptr>\ninline void single_write(T a) noexcept {\n    if (!a) {\n      \
    \  putchar_unlocked('0');\n        return;\n    }\n    if constexpr (std::is_signed_v<T>)\
    \ {\n        if (a < 0) putchar_unlocked('-'), a *= -1;\n    }\n    constexpr\
    \ int d = std::numeric_limits<T>::digits10;\n    char s[d + 1];\n    int now =\
    \ d + 1;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n        a /=\
    \ 10;\n    }\n    while (now <= d) putchar_unlocked(s[now++]);\n}\ntemplate <typename\
    \ T, internal::is_modint_t<T>* = nullptr>\ninline void single_write(T a) noexcept\
    \ {\n    single_write(a.val());\n}\ninline void single_write(const std::string&\
    \ str) noexcept {\n    for (auto c : str) {\n        putchar_unlocked(c);\n  \
    \  }\n}\ntemplate <typename T> inline void write(T x) noexcept { single_write(x);\
    \ }\ntemplate <typename Head, typename... Tail>\ninline void write(Head head,\
    \ Tail... tail) noexcept {\n    single_write(head);\n    putchar_unlocked(' ');\n\
    \    write(tail...);\n}\ntemplate <typename... Args> inline void put(Args... x)\
    \ noexcept {\n    write(x...);\n    putchar_unlocked('\\n');\n}\n};  // namespace\
    \ kyopro\n\n/**\n * @brief \u9AD8\u901F\u5165\u51FA\u529B\n */\n#line 6 \"test/AOJ/DSL/2_D_lazy.test.cpp\"\
    \ninline int op(int x, int y) { return std::min(x, y); }\ninline int comp(int\
    \ x, int y) { return y; }\ninline int mapping(int x, int y) { return y; }\ninline\
    \ int e() { return (1ll << 31) - 1; }\ninline int id() { return (1ll << 31) -\
    \ 1; }\n\nint main() {\n    int n, q;\n    kyopro::read(n, q);\n    kyopro::lazy_segtree<int,\
    \ int, op, e, comp, id, mapping> seg(n);\n    while (q--) {\n        int t;\n\
    \        kyopro::read(t);\n        if (!t) {\n            int l, r, add;\n   \
    \         kyopro::read(l, r, add);\n            seg.apply(l, r + 1, add);\n  \
    \      } else {\n            int i;\n            kyopro::read(i);\n          \
    \  kyopro::put(seg[i]);\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#include \"../../../src/data-structure/lazy_segtree.hpp\"\n#include \"../../../src/stream.hpp\"\
    \ninline int op(int x, int y) { return std::min(x, y); }\ninline int comp(int\
    \ x, int y) { return y; }\ninline int mapping(int x, int y) { return y; }\ninline\
    \ int e() { return (1ll << 31) - 1; }\ninline int id() { return (1ll << 31) -\
    \ 1; }\n\nint main() {\n    int n, q;\n    kyopro::read(n, q);\n    kyopro::lazy_segtree<int,\
    \ int, op, e, comp, id, mapping> seg(n);\n    while (q--) {\n        int t;\n\
    \        kyopro::read(t);\n        if (!t) {\n            int l, r, add;\n   \
    \         kyopro::read(l, r, add);\n            seg.apply(l, r + 1, add);\n  \
    \      } else {\n            int i;\n            kyopro::read(i);\n          \
    \  kyopro::put(seg[i]);\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/lazy_segtree.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2_D_lazy.test.cpp
  requiredBy: []
  timestamp: '2023-10-22 17:06:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2_D_lazy.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2_D_lazy.test.cpp
- /verify/test/AOJ/DSL/2_D_lazy.test.cpp.html
title: test/AOJ/DSL/2_D_lazy.test.cpp
---
