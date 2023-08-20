---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/dual_segtree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/stream.hpp
    title: "\u5165\u51FA\u529B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
  bundledCode: "#line 1 \"test/AOJ/DSL/2_E_dual.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\
    \n\n#line 2 \"src/data-structure/dual_segtree.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nnamespace kyopro {\n/**\n * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\n * @tparam F \u4F5C\u7528\u7D20\n * @tparam id F \u306E\u5358\u4F4D\
    \u5143\n */\ntemplate <class F, F (*composition)(F, F), F (*id)()> class dual_segtree\
    \ {\n    std::vector<F> dat;\n    int _n, sz, lg;\n\npublic:\n    dual_segtree()\
    \ {}\n    dual_segtree(int _n) : _n(_n) {\n        sz = 1, lg = 0;\n        while\
    \ (sz < _n) {\n            ++lg;\n            sz <<= 1;\n        }\n        dat.assign(sz\
    \ << 1, id());\n    }\n\nprivate:\n    void update(int p, const F& v) { dat[p]\
    \ = composition(dat[p], v); }\n    void push(int p) {\n        if (dat[p] == id())\
    \ {\n            return;\n        }\n        update(p << 1 | 0, dat[p]);\n   \
    \     update(p << 1 | 1, dat[p]);\n        dat[p] = id();\n    }\n\npublic:\n\
    \    F operator[](int p) {\n        assert(0 <= p && p < _n);\n\n        F res\
    \ = id();\n\n        p += sz;\n        for (int i = lg; i > 0; i--) {\n      \
    \      push(p >> i);\n        }\n        return dat[p];\n    }\n\n    void apply(int\
    \ l, int r, const F& v) {\n        assert(0 <= l && l <= r && r <= _n);\n    \
    \    if (l == r) return;\n        l += sz, r += sz;\n        for (int i = lg;\
    \ i > 0; i--) {\n            if (((l >> i) << i) != l) {\n                push(l\
    \ >> i);\n            }\n            if (((r >> i) << i) != r) {\n           \
    \     push((r - 1) >> i);\n            }\n        }\n        while (l < r) {\n\
    \            if (l & 1) {\n                update(l++, v);\n            }\n  \
    \          if (r & 1) {\n                update(--r, v);\n            }\n    \
    \        l >>= 1, r >>= 1;\n        }\n    }\n};\n\n};  // namespace kyopro\n\n\
    /**\n * @docs docs/data-structure/dual_segtree.md\n */\n#line 2 \"src/stream.hpp\"\
    \n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n#line 2 \"src/internal/type_traits.hpp\"\
    \n#include <iostream>\n#include <limits>\n#include <numeric>\n#include <typeinfo>\n\
    namespace kyopro {\nnamespace internal {\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
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
    };  // namespace internal\n};  // namespace kyopro\n#line 6 \"src/stream.hpp\"\
    \n\nnamespace kyopro {\n// read\nvoid single_read(char& c) noexcept {\n    c =\
    \ getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n}\ntemplate\
    \ <typename T, internal::is_integral_t<T>* = nullptr>\nconstexpr void single_read(T&\
    \ a) noexcept {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if constexpr\
    \ (std::is_signed<T>::value) {\n        if (c == '-') is_negative = true, c =\
    \ getchar_unlocked();\n    }\n    while (isdigit(c)) {\n        a = 10 * a + (c\
    \ - '0');\n        c = getchar_unlocked();\n    }\n    if constexpr (std::is_signed<T>::value)\
    \ {\n        if (is_negative) a *= -1;\n    }\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_read(T& a) noexcept {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\nvoid single_read(std::string& str) noexcept {\n    char c =\
    \ getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n    while\
    \ (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n    }\n\
    }\ntemplate <typename T> constexpr inline void read(T& x) noexcept {\n    single_read(x);\n\
    }\ntemplate <typename Head, typename... Tail>\nconstexpr inline void read(Head&\
    \ head, Tail&... tail) noexcept {\n    single_read(head), read(tail...);\n}\n\n\
    // write\nvoid single_write(char c) noexcept { putchar_unlocked(c); }\ntemplate\
    \ <typename T, internal::is_integral_t<T>* = nullptr>\nvoid single_write(T a)\
    \ noexcept {\n    if (!a) {\n        putchar_unlocked('0');\n        return;\n\
    \    }\n    if constexpr (std::is_signed<T>::value) {\n        if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    }\n    constexpr int d = std::numeric_limits<T>::digits10;\n \
    \   char s[d];\n    int now = d;\n    while (a) {\n        s[--now] = static_cast<char>('0'\
    \ + a % 10);\n        a /= 10;\n    }\n    while (now < d) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T, internal::is_modint_t<T>* = nullptr>\nvoid single_write(T\
    \ a) noexcept {\n    single_write(a.val());\n}\n\nvoid single_write(const std::string&\
    \ str) noexcept {\n    for (auto c : str) {\n        putchar_unlocked(c);\n  \
    \  }\n}\n\ntemplate <typename T> constexpr inline void write(T x) noexcept {\n\
    \    single_write(x);\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void write(Head head, Tail... tail) noexcept {\n    single_write(head);\n\
    \    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate <typename... Args>\
    \ constexpr inline void put(Args... x) noexcept {\n    write(x...);\n    putchar_unlocked('\\\
    n');\n}\n};  // namespace kyopro\n\n/**\n * @brief \u5165\u51FA\u529B\n */\n#line\
    \ 5 \"test/AOJ/DSL/2_E_dual.test.cpp\"\n\nusing ull = unsigned long long;\ninline\
    \ ull op(ull x, ull y) { return x + y; }\ninline ull e() { return 0; }\nint main()\
    \ {\n    int n, q;\n    kyopro::read(n, q);\n    kyopro::dual_segtree<ull, op,\
    \ e> seg(n);\n    while (q--) {\n        int ty;\n        kyopro::read(ty);\n\
    \        if (!ty) {\n            int l, r;\n            ull x;\n            kyopro::read(l,\
    \ r, x);\n            l--, r--;\n            seg.apply(l, r + 1, x);\n       \
    \ } else {\n            int i;\n            kyopro::read(i);\n            i--;\n\
    \            kyopro::put(seg[i]);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\n\n\
    #include \"../../../src/data-structure/dual_segtree.hpp\"\n#include \"../../../src/stream.hpp\"\
    \n\nusing ull = unsigned long long;\ninline ull op(ull x, ull y) { return x +\
    \ y; }\ninline ull e() { return 0; }\nint main() {\n    int n, q;\n    kyopro::read(n,\
    \ q);\n    kyopro::dual_segtree<ull, op, e> seg(n);\n    while (q--) {\n     \
    \   int ty;\n        kyopro::read(ty);\n        if (!ty) {\n            int l,\
    \ r;\n            ull x;\n            kyopro::read(l, r, x);\n            l--,\
    \ r--;\n            seg.apply(l, r + 1, x);\n        } else {\n            int\
    \ i;\n            kyopro::read(i);\n            i--;\n            kyopro::put(seg[i]);\n\
    \        }\n    }\n}\n"
  dependsOn:
  - src/data-structure/dual_segtree.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2_E_dual.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 07:26:53+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2_E_dual.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2_E_dual.test.cpp
- /verify/test/AOJ/DSL/2_E_dual.test.cpp.html
title: test/AOJ/DSL/2_E_dual.test.cpp
---
