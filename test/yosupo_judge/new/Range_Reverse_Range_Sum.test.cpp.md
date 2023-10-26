---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/bbst/reversible_bbst.hpp
    title: "\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728"
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: src/random/xor_shift.hpp
    title: Xor Shift
  - icon: ':question:'
    path: src/stream.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B"
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_reverse_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_reverse_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\n\
    \n#line 2 \"src/data-structure/bbst/reversible_bbst.hpp\"\n#include <cassert>\n\
    #include <memory>\n#include <utility>\n#line 2 \"src/random/xor_shift.hpp\"\n\
    #include <chrono>\n#include <cstdint>\n#include <random>\n\nnamespace kyopro {\n\
    struct xor_shift32 {\n    uint32_t rng;\n    constexpr explicit xor_shift32(uint32_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr explicit xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief Xor Shift\n */\n#line 6 \"src/data-structure/bbst/reversible_bbst.hpp\"\
    \n\nnamespace kyopro {\ntemplate <class S, auto op, auto e> class reversible_bbst\
    \ {\n    using u32 = uint32_t;\n    xor_shift32 rng;\n    struct Node {\n    \
    \    Node *l, *r;\n        u32 priority;\n        S value, prod;\n        int\
    \ size;\n        bool rev;\n        \n        explicit Node(const S& v, u32 prio)\n\
    \            : l(),\n              r(),\n              priority(prio),\n     \
    \         value(v),\n              prod(v),\n              size(1),\n        \
    \      rev(false) {}\n    };\n\n    using uptr = std::unique_ptr<Node>;\n    std::vector<uptr>\
    \ nodes;\n    Node* make_ptr(const S& v, u32 prio) {\n        nodes.emplace_back(std::make_unique<Node>(v,\
    \ prio));\n        return nodes.back().get();\n    }\n    int size(Node* p) const\
    \ { return p ? p->size : 0; }\n    S fold(Node* p) { return p ? p->prod : e();\
    \ }\n    void reverse(Node*& p) {\n        if (p) {\n            p->rev ^= 1;\n\
    \        }\n    }\n    void push_down(Node*& p) {\n        if (p->rev) {\n   \
    \         p->rev = false;\n            std::swap(p->l, p->r);\n            reverse(p->l),\
    \ reverse(p->r);\n        }\n    }\n    void push_up(Node*& p) {\n        p->size\
    \ = size(p->l) + size(p->r) + 1;\n        p->prod = op(p->value, op(fold(p->l),\
    \ fold(p->r)));\n    }\n\n    std::pair<Node*, Node*> split(Node* p, int k) {\n\
    \        if (!p) return {nullptr, nullptr};\n\n        push_down(p);\n       \
    \ int s = size(p->l);\n        if (s >= k) {\n            auto [l, r] = split(p->l,\
    \ k);\n            p->l = r;\n            push_up(p);\n\n            return {std::move(l),\
    \ std::move(p)};\n        } else {\n            auto [l, r] = split(p->r, k -\
    \ s - 1);\n\n            p->r = l;\n            push_up(p);\n\n            return\
    \ {std::move(p), std::move(r)};\n        }\n    }\n\n    Node* merge(Node* l,\
    \ Node* r) {\n        if (!l) return std::move(r);\n        if (!r) return std::move(l);\n\
    \n        if (l->priority < r->priority) {\n            push_down(r);\n      \
    \      r->l = merge(l, r->l);\n            push_up(r);\n            return std::move(r);\n\
    \        } else {\n            push_down(l);\n            l->r = merge(l->r, r);\n\
    \            push_up(l);\n\n            return std::move(l);\n        }\n    }\n\
    \n    Node* root;\n\npublic:\n    explicit reversible_bbst() : rng(2023), root(nullptr)\
    \ {}\n    void insert(int i, const S& a) {\n        Node* item = make_ptr(a, rng());\n\
    \        auto [l, r] = split(root, i);\n        root = merge(l, item);\n     \
    \   root = merge(root, r);\n    }\n    S fold(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= size(root));\n        auto [xy, z] = split(root, r);\n\
    \        auto [x, y] = split(xy, l);\n        S res = fold(y);\n        xy = merge(x,\
    \ y);\n        root = merge(xy, z);\n        return res;\n    }\n    void reverse(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= size(root));\n        auto\
    \ [xy, z] = split(root, r);\n        auto [x, y] = split(xy, l);\n        reverse(y);\n\
    \        xy = merge(x, y);\n        root = merge(xy, z);\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728\
    \n * @see https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_reverse_range_sum/sol/correct.cpp\n\
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\n#line 2 \"src/internal/type_traits.hpp\"\n#include <iostream>\n#include\
    \ <limits>\n#include <numeric>\n#include <typeinfo>\n#line 7 \"src/internal/type_traits.hpp\"\
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
    \ kyopro\n\n/**\n * @brief \u9AD8\u901F\u5165\u51FA\u529B\n */\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\n#define rep(i, N) for (int i = 0; i < (N); i++)\n\
    #define all(x) std::begin(x), std::end(x)\n#define popcount(x) __builtin_popcountll(x)\n\
    using i128 = __int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = std::numeric_limits<int>::max() / 2;\nconstexpr ll infl = std::numeric_limits<ll>::max()\
    \ / 2;\nconstexpr ld eps = 1e-12;\nconst long double pi = acosl(-1);\nconstexpr\
    \ uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int\
    \ dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr int dy[] = {0, 1, 0, -1, 1,\
    \ 1, -1, -1, 0};\ntemplate <typename T1, typename T2> constexpr inline bool chmax(T1&\
    \ a, T2 b) {\n    return a < b && (a = b, true);\n}\ntemplate <typename T1, typename\
    \ T2> constexpr inline bool chmin(T1& a, T2 b) {\n    return a > b && (a = b,\
    \ true);\n}\n#line 6 \"test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp\"\
    \nusing ll = long long;\nconstexpr inline ll op(ll x, ll y) { return x + y; }\n\
    constexpr inline ll e() { return 0; }\n\nusing namespace std;\nusing namespace\
    \ kyopro;\n\nint main() {\n    int n, q;\n    read(n, q);\n    reversible_bbst<ll,\
    \ op, e> bbst;\n    for (int i = 0; i < n; i++) {\n        int a;\n        read(a);\n\
    \        bbst.insert(i, a);\n    }\n\n    while (q--) {\n        int t, l, r;\n\
    \        read(t, l, r);\n        if (!t) {\n            bbst.reverse(l, r);\n\
    \        } else {\n            put(bbst.fold(l, r));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\
    \n\n#include \"../../../src/data-structure/bbst/reversible_bbst.hpp\"\n#include\
    \ \"../../../src/stream.hpp\"\n#include \"../../../src/template.hpp\"\nusing ll\
    \ = long long;\nconstexpr inline ll op(ll x, ll y) { return x + y; }\nconstexpr\
    \ inline ll e() { return 0; }\n\nusing namespace std;\nusing namespace kyopro;\n\
    \nint main() {\n    int n, q;\n    read(n, q);\n    reversible_bbst<ll, op, e>\
    \ bbst;\n    for (int i = 0; i < n; i++) {\n        int a;\n        read(a);\n\
    \        bbst.insert(i, a);\n    }\n\n    while (q--) {\n        int t, l, r;\n\
    \        read(t, l, r);\n        if (!t) {\n            bbst.reverse(l, r);\n\
    \        } else {\n            put(bbst.fold(l, r));\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/bbst/reversible_bbst.hpp
  - src/random/xor_shift.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  - src/template.hpp
  isVerificationFile: true
  path: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-10-22 21:54:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
- /verify/test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp.html
title: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
---
