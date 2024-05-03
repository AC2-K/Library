---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/segtree.hpp
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include <algorithm>\n#include <iostream>\n#include <numeric>\n#line 2 \"src/data-structure/segtree.hpp\"\
    \n#include <cassert>\n#include <vector>\nnamespace kyopro {\n\n\ntemplate <class\
    \ S, auto op, auto e> class segtree {\n    int lg, sz, n;\n    std::vector<S>\
    \ dat;\n\npublic:\n    segtree() = default;\n    segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    segtree(const std::vector<S>& vec) : n((int)vec.size()) {\n  \
    \      sz = 1, lg = 0;\n        while (sz <= n) {\n            sz <<= 1;\n   \
    \         lg++;\n        }\n\n        dat = std::vector<S>(sz << 1, e());\n\n\
    \        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n        }\n\
    \        build();\n    }\n\n    void set(int p, const S& v) {\n        assert(0\
    \ <= p && p < sz);\n        dat[sz + p] = v;\n    }\n    void build() {\n    \
    \    for (int i = sz - 1; i > 0; i--) {\n            dat[i] = op(dat[i << 1 |\
    \ 0], dat[i << 1 | 1]);\n        }\n    }\n\n    S operator[](int p) const { return\
    \ dat[sz + p]; }\n\n    void update(int p, const S& v) {\n        assert(0 <=\
    \ p && p < sz);\n        p += sz;\n        dat[p] = v;\n        while (p >>= 1)\
    \ {\n            dat[p] = op(dat[(p << 1) | 0], dat[(p << 1) | 1]);\n        }\n\
    \    }\n\n    S fold(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= sz);\n        if (l == 0 && r == n) {\n            return dat[1];\n   \
    \     }\n        l += sz, r += sz;\n        S sml = e(), smr = e();\n        while\
    \ (l != r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n            if\
    \ (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n    void apply(int p, const S& v) {\n  \
    \      assert(0 <= p && p < sz);\n        update(p, op(dat[sz + p], v));\n   \
    \ }\n};\n};  // namespace kyopro\n\n/**\n * @brief Segment Tree\n */\n#line 2\
    \ \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n\
    #line 3 \"src/internal/type_traits.hpp\"\n#include <limits>\n#line 5 \"src/internal/type_traits.hpp\"\
    \n#include <typeinfo>\n#include <cstdint>\n\nnamespace kyopro {\nnamespace internal\
    \ {\ntemplate <typename... Args> struct first_enabled {};\n\ntemplate <typename\
    \ T, typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...>\
    \ {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct\
    \ first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
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
    \ kyopro\n\n/**\n * @brief \u9AD8\u901F\u5165\u51FA\u529B\n */\n#line 7 \"test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp\"\
    \nusing S = std::pair<int, int>;\ninline S op(S x, S y) { return max(x, y); }\n\
    inline S e() { return S{0, 0}; }\n\nint main() {\n    int n;\n    kyopro::read(n);\n\
    \    std::vector<int> a(n);\n    for (auto& aa : a) {\n        kyopro::read(aa);\n\
    \    }\n    {\n        std::vector<int> tmp = a;\n        std::sort(tmp.begin(),\
    \ tmp.end());\n        tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());\n\
    \        for (auto& aa : a) {\n            aa = lower_bound(tmp.begin(), tmp.end(),\
    \ aa) - tmp.begin();\n        }\n    }\n    std::vector<int> prv(n, -1);\n   \
    \ std::iota(prv.begin(), prv.end(), 0);\n    kyopro::segtree<S, op, e> dp(n +\
    \ 1);\n    for (int i = 0; i < n; i++) {\n        auto [mx, p] = dp.fold(0, a[i]);\n\
    \        if (mx + 1 >= dp[a[i]].first) {\n            prv[i] = p;\n          \
    \  dp.update(a[i], S{mx + 1, i});\n        }\n    }\n    auto [res, cur] = dp.fold(0,\
    \ n + 1);\n    std::vector<int> idx;\n    idx.reserve((size_t)res);\n    for (int\
    \ i = 0; i < res; i++) {\n        idx.emplace_back(cur);\n        cur = prv[cur];\n\
    \    }\n    kyopro::put(idx.size());\n    std::reverse(idx.begin(), idx.end());\n\
    \    for (auto i : idx) {\n        kyopro::put(i);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include \"../../../src/data-structure/segtree.hpp\"\
    \n#include \"../../../src/stream.hpp\"\nusing S = std::pair<int, int>;\ninline\
    \ S op(S x, S y) { return max(x, y); }\ninline S e() { return S{0, 0}; }\n\nint\
    \ main() {\n    int n;\n    kyopro::read(n);\n    std::vector<int> a(n);\n   \
    \ for (auto& aa : a) {\n        kyopro::read(aa);\n    }\n    {\n        std::vector<int>\
    \ tmp = a;\n        std::sort(tmp.begin(), tmp.end());\n        tmp.erase(std::unique(tmp.begin(),\
    \ tmp.end()), tmp.end());\n        for (auto& aa : a) {\n            aa = lower_bound(tmp.begin(),\
    \ tmp.end(), aa) - tmp.begin();\n        }\n    }\n    std::vector<int> prv(n,\
    \ -1);\n    std::iota(prv.begin(), prv.end(), 0);\n    kyopro::segtree<S, op,\
    \ e> dp(n + 1);\n    for (int i = 0; i < n; i++) {\n        auto [mx, p] = dp.fold(0,\
    \ a[i]);\n        if (mx + 1 >= dp[a[i]].first) {\n            prv[i] = p;\n \
    \           dp.update(a[i], S{mx + 1, i});\n        }\n    }\n    auto [res, cur]\
    \ = dp.fold(0, n + 1);\n    std::vector<int> idx;\n    idx.reserve((size_t)res);\n\
    \    for (int i = 0; i < res; i++) {\n        idx.emplace_back(cur);\n       \
    \ cur = prv[cur];\n    }\n    kyopro::put(idx.size());\n    std::reverse(idx.begin(),\
    \ idx.end());\n    for (auto i : idx) {\n        kyopro::put(i);\n    }\n}"
  dependsOn:
  - src/data-structure/segtree.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-10-22 17:20:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
- /verify/test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp.html
title: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
---
