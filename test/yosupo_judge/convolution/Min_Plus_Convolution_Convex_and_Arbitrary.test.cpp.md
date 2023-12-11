---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/monotone_minima.hpp
    title: src/algorithm/monotone_minima.hpp
  - icon: ':heavy_check_mark:'
    path: src/convolution/min_plus_convolution_convex_arbitrary.hpp
    title: src/convolution/min_plus_convolution_convex_arbitrary.hpp
  - icon: ':heavy_check_mark:'
    path: src/debug.hpp
    title: src/debug.hpp
  - icon: ':heavy_check_mark:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
  bundledCode: "#line 1 \"test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n#line 2 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\n#include\
    \ <limits>\n#line 2 \"src/algorithm/monotone_minima.hpp\"\n#include <utility>\n\
    #include <vector>\nnamespace kyopro {\ntemplate <typename T, typename F>\nstd::vector<std::pair<std::size_t,\
    \ T>> monotone_minima(std::size_t h,\n                                       \
    \                std::size_t w,\n                                            \
    \           const F& f) {\n    using usize = std::size_t;\n    std::vector<std::pair<usize,\
    \ T>> res(h);\n\n    const auto calc = [&](const auto& calc, usize top, usize\
    \ bottom, usize l,\n                          usize r) -> void {\n        if (top\
    \ >= bottom) return;\n\n        usize mid = (top + bottom) / 2;\n\n        T mn\
    \ = f(mid, l);\n        usize idx = l;\n        for (usize i = l + 1; i < r; ++i)\
    \ {\n            T val = f(mid, i);\n            if (mn > val) {\n           \
    \     mn = val;\n                idx = i;\n            }\n        }\n\n      \
    \  res[mid] = std::pair(idx, mn);\n        calc(calc, top, mid, l, idx + 1);\n\
    \        calc(calc, mid + 1, bottom, idx, r);\n    };\n    calc(calc, 0, h, 0,\
    \ w);\n\n    return res;\n}\n};  // namespace kyopro\n#line 4 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\
    \nnamespace kyopro {\n\n/// @note a \u306F\u4E0B\u306B\u51F8\u3067\u3042\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\n/// @note \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u304C\u3061\u3063\u307D\u3044\u306E\u3067\u6C17\u3092\u4ED8\u3051\
    \u308B \ntemplate <typename T>\nstd::vector<T> min_plus_convolution_convex_arbitrary(const\
    \ std::vector<T>& a,\n                                                     const\
    \ std::vector<T>& b) {\n    const int n = a.size();\n    const int m = b.size();\n\
    \    \n    const auto f = [&](int i, int j) {\n        if (i - j < 0 || i - j\
    \ >= n) {\n            return std::numeric_limits<T>::max() / 2 + b[j];\n    \
    \    }\n        return a[i - j] + b[j];\n    };\n\n    std::vector res = monotone_minima<T>(n\
    \ + m - 1, m, f);\n    std::vector<T> c(n + m - 1);\n    for (int i = 0; i < (int)c.size();\
    \ ++i) c[i] = res[i].second;\n    return c;\n}\n};  // namespace kyopro\n#line\
    \ 1 \"src/debug.hpp\"\n#ifdef ONLINE_JUDGE\n#define debug(x) void(0)\n#else\n\
    #define _GLIBCXX_DEBUG\n#define debug(x) std::cerr << __LINE__ << \" : \" << #x\
    \ << \" = \" << (x) << std::endl\n#endif\n#line 2 \"src/stream.hpp\"\n#include\
    \ <ctype.h>\n#include <stdio.h>\n#include <string>\n#line 2 \"src/internal/type_traits.hpp\"\
    \n#include <iostream>\n#line 4 \"src/internal/type_traits.hpp\"\n#include <numeric>\n\
    #include <typeinfo>\n#include <cstdint>\n\nnamespace kyopro {\nnamespace internal\
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
    \ kyopro\n\n/**\n * @brief \u9AD8\u901F\u5165\u51FA\u529B\n */\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\n#define rep(i, n) for (int i = 0; i < (n); i++)\n\
    #define all(x) std::begin(x), std::end(x)\n#define popcount(x) __builtin_popcountll(x)\n\
    using i128 = __int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = std::numeric_limits<int>::max() / 2;\nconstexpr ll infl = std::numeric_limits<ll>::max()\
    \ / 2;\nconst long double pi = acosl(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1,\
    \ -1, 1, 0};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\ntemplate <typename\
    \ T1, typename T2> constexpr inline bool chmax(T1& a, T2 b) {\n    return a <\
    \ b && (a = b, true);\n}\ntemplate <typename T1, typename T2> constexpr inline\
    \ bool chmin(T1& a, T2 b) {\n    return a > b && (a = b, true);\n}\n#line 7 \"\
    test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n,\
    \ m;\n    read(n, m);\n    vector a(n, 0LL), b(m, 0LL);\n    rep(i, n) read(a[i]);\n\
    \    rep(i, m) read(b[i]);\n    vector c = min_plus_convolution_convex_arbitrary(a,\
    \ b);\n    rep(i, (int)c.size()) put(c[i]);\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n#include \"../../../src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\
    \n#include \"../../../src/debug.hpp\"\n#include \"../../../src/stream.hpp\"\n\
    #include \"../../../src/template.hpp\"\n\nusing namespace std;\nusing namespace\
    \ kyopro;\n\nint main() {\n    int n, m;\n    read(n, m);\n    vector a(n, 0LL),\
    \ b(m, 0LL);\n    rep(i, n) read(a[i]);\n    rep(i, m) read(b[i]);\n    vector\
    \ c = min_plus_convolution_convex_arbitrary(a, b);\n    rep(i, (int)c.size())\
    \ put(c[i]);\n}\n"
  dependsOn:
  - src/convolution/min_plus_convolution_convex_arbitrary.hpp
  - src/algorithm/monotone_minima.hpp
  - src/debug.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  - src/template.hpp
  isVerificationFile: true
  path: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
  requiredBy: []
  timestamp: '2023-12-11 11:51:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
- /verify/test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp.html
title: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
---
