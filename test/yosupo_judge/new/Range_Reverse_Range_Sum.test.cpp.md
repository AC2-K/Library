---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data-structure/bbst/reversible_bbst.hpp
    title: "\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728"
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: xor shift
  - icon: ':question:'
    path: src/stream.hpp
    title: "\u5165\u51FA\u529B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_reverse_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_reverse_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\n\
    #include <iostream>\n#line 2 \"src/data-structure/bbst/reversible_bbst.hpp\"\n\
    #include <cassert>\n#include <memory>\n#include <utility>\n#line 2 \"src/random/xor_shift.hpp\"\
    \n#include <chrono>\n#include <cstdint>\n#include <random>\n\nnamespace kyopro\
    \ {\nstruct xor_shift32 {\n    uint32_t rng;\n    constexpr explicit xor_shift32(uint32_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief xor shift\n */\n#line 6 \"src/data-structure/bbst/reversible_bbst.hpp\"\
    \n\nnamespace kyopro {\n/**\n * @brief \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\
    \u5206\u63A2\u7D22\u6728\n * @tparam S \u30E2\u30CE\u30A4\u30C9\n * @tparam op\
    \ S\u306E\u4E8C\u9805\u6F14\u7B97\n * @tparam e S\u306E\u5358\u4F4D\u5143\n */\n\
    template <class S, S (*op)(S, S), S (*e)()> class reversible_bbst {\n    using\
    \ u32 = uint32_t;\n    xor_shift32 rng;\n    struct Node {\n        std::unique_ptr<Node>\
    \ l, r;\n        u32 priority;\n        S value, prod;\n        int size;\n  \
    \      bool rev;\n\n        Node(S v, u32 prio)\n            : l(),\n        \
    \      r(),\n              priority(prio),\n              value(v),\n        \
    \      prod(v),\n              size(1),\n              rev(false) {}\n    };\n\
    \n    using ptr = std::unique_ptr<Node>;\n    int size(const ptr& p) const { return\
    \ p ? p->size : 0; }\n    S fold(const ptr& p) { return p ? p->prod : e(); }\n\
    \n    void reverse(const ptr& p) {\n        if (p) {\n            p->rev ^= 1;\n\
    \        }\n    }\n\n    void push(const ptr& p) {\n        if (p->rev) {\n  \
    \          p->rev = false;\n            std::swap(p->l, p->r);\n            reverse(p->l),\
    \ reverse(p->r);\n        }\n    }\n\n    void update(const ptr& p) {\n      \
    \  p->size = size(p->l) + size(p->r) + 1;\n        p->prod = op(p->value, op(fold(p->l),\
    \ fold(p->r)));\n    }\n\n    std::pair<ptr, ptr> split(ptr p, int k) {\n    \
    \    if (!p) return {nullptr, nullptr};\n\n        push(p);\n        int s = size(p->l);\n\
    \        if (s >= k) {\n            auto [l, r] = split(std::move(p->l), k);\n\
    \            p->l = std::move(r);\n            update(p);\n\n            return\
    \ {std::move(l), std::move(p)};\n        } else {\n            auto [l, r] = split(std::move(p->r),\
    \ k - s - 1);\n\n            p->r = std::move(l);\n            update(p);\n\n\
    \            return {std::move(p), std::move(r)};\n        }\n    }\n\n    ptr\
    \ merge(ptr l, ptr r) {\n        if (!l) return r;\n        if (!r) return l;\n\
    \n        if (l->priority < r->priority) {\n            push(r);\n           \
    \ r->l = merge(std::move(l), std::move(r->l));\n            update(r);\n     \
    \       return r;\n        } else {\n            push(l);\n            l->r =\
    \ merge(std::move(l->r), std::move(r));\n            update(l);\n\n          \
    \  return l;\n        }\n    }\n\n    ptr root = nullptr;\n\npublic:\n    constexpr\
    \ explicit reversible_bbst() : rng(2023) {}\n    void insert(int i, S a) {\n \
    \       auto [l, r] = split(std::move(root), i);\n        ptr item = std::make_unique<Node>(a,\
    \ rng());\n        root = merge(std::move(l), std::move(item));\n        root\
    \ = merge(std::move(root), std::move(r));\n    }\n    S fold(int l, int r) {\n\
    \        assert(0 <= l && l <= r && r <= size(root));\n        auto [xy, z] =\
    \ split(std::move(root), r);\n        auto [x, y] = split(std::move(xy), l);\n\
    \        auto res = fold(y);\n        xy = merge(std::move(x), std::move(y));\n\
    \        root = merge(std::move(xy), std::move(z));\n        return res;\n   \
    \ }\n    void reverse(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ size(root));\n        auto [xy, z] = split(std::move(root), r);\n        auto\
    \ [x, y] = split(std::move(xy), l);\n        reverse(y);\n        xy = merge(std::move(x),\
    \ std::move(y));\n        root = merge(std::move(xy), std::move(z));\n    }\n\
    };\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/bbst/reversible_bbst.md\n\
    \ * @ref\n * https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_reverse_range_sum/sol/correct.cpp\n\
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\n#line 3 \"src/internal/type_traits.hpp\"\n#include <limits>\n#include\
    \ <numeric>\n#include <typeinfo>\nnamespace kyopro {\nnamespace internal {\n/*\n\
    \ * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\ntemplate\
    \ <typename... Args> struct first_enabled {};\n\ntemplate <typename T, typename...\
    \ Args>\nstruct first_enabled<std::enable_if<true, T>, Args...> {\n    using type\
    \ = T;\n};\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<false,\
    \ T>, Args...>\n    : first_enabled<Args...> {};\ntemplate <typename T, typename...\
    \ Args> struct first_enabled<T, Args...> {\n    using type = T;\n};\n\ntemplate\
    \ <typename... Args>\nusing first_enabled_t = typename first_enabled<Args...>::type;\n\
    \ntemplate <int dgt> struct int_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __int8_t>,\n               \
    \                  std::enable_if<dgt <= 16, __int16_t>,\n                   \
    \              std::enable_if<dgt <= 32, __int32_t>,\n                       \
    \          std::enable_if<dgt <= 64, __int64_t>,\n                           \
    \      std::enable_if<dgt <= 128, __int128_t> >;\n};\ntemplate <int dgt> struct\
    \ uint_least {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __uint8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __uint16_t>,\n                                 std::enable_if<dgt <= 32, __uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __uint64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\
    \ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\ntemplate\
    \ <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename\
    \ T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
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
    \ a *= -1;\n    }\n    const int d = std::numeric_limits<T>::digits10;\n    char\
    \ s[d];\n    int now = d;\n    while (a) {\n        s[--now] = (char)'0' + a %\
    \ 10;\n        a /= 10;\n    }\n    while (now < d) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T, internal::is_modint_t<T>* = nullptr>\nvoid single_write(T\
    \ a) noexcept {\n    single_write(a.val());\n}\n\nvoid single_write(const std::string&\
    \ str) noexcept {\n    for (auto c : str) {\n        putchar_unlocked(c);\n  \
    \  }\n}\n\ntemplate <typename T> constexpr inline void write(T x) noexcept {\n\
    \    single_write(x);\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void write(Head head, Tail... tail) noexcept {\n    single_write(head);\n\
    \    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate <typename... Args>\
    \ constexpr inline void put(Args... x) noexcept {\n    write(x...);\n    putchar_unlocked('\\\
    n');\n}\n};  // namespace kyopro\n\n/**\n * @brief \u5165\u51FA\u529B\n */\n#line\
    \ 5 \"test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp\"\nusing ll = long\
    \ long;\ninline ll op(ll x, ll y) { return x + y; }\ninline ll e() { return 0;\
    \ }\nint main() {\n    int n, q;\n    kyopro::read(n, q);\n    kyopro::reversible_bbst<ll,\
    \ op, e> bbst;\n    for (int i = 0; i < n; i++) {\n        int a;\n        kyopro::read(a);\n\
    \        bbst.insert(i, a);\n    }\n\n    while (q--) {\n        int t, l, r;\n\
    \        kyopro::read(t, l, r);\n        if (!t) {\n            bbst.reverse(l,\
    \ r);\n        } else {\n            kyopro::put(bbst.fold(l, r));\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\
    \n#include <iostream>\n#include \"../../../src/data-structure/bbst/reversible_bbst.hpp\"\
    \n#include \"../../../src/stream.hpp\"\nusing ll = long long;\ninline ll op(ll\
    \ x, ll y) { return x + y; }\ninline ll e() { return 0; }\nint main() {\n    int\
    \ n, q;\n    kyopro::read(n, q);\n    kyopro::reversible_bbst<ll, op, e> bbst;\n\
    \    for (int i = 0; i < n; i++) {\n        int a;\n        kyopro::read(a);\n\
    \        bbst.insert(i, a);\n    }\n\n    while (q--) {\n        int t, l, r;\n\
    \        kyopro::read(t, l, r);\n        if (!t) {\n            bbst.reverse(l,\
    \ r);\n        } else {\n            kyopro::put(bbst.fold(l, r));\n        }\n\
    \    }\n}"
  dependsOn:
  - src/data-structure/bbst/reversible_bbst.hpp
  - src/random/xor_shift.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:51:47+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
- /verify/test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp.html
title: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
---
