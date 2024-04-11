---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/data-structure-2d/merge-sort-tree.hpp
    title: MergeSortTree
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 2\
    \ \"src/data-structure/data-structure-2d/merge-sort-tree.hpp\"\n#include <algorithm>\n\
    #include <iterator>\n#include <utility>\n#include <vector>\n\nnamespace kyopro\
    \ {\ntemplate <typename Key_x, typename Key_y, typename Value>\nclass merge_sort_tree\
    \ {\n    int lg, sz;\n\n    struct point {\n        Key_x x;\n        Key_y y;\n\
    \        Value v;\n        point(Key_x x, Key_y y, Value v) : x(x), y(y), v(v)\
    \ {}\n    };\n\n    std::vector<Key_x> xs;\n    std::vector<std::vector<Key_y>>\
    \ ys;  // x \u56FA\u5B9A\u3057\u305F\u3068\u304D\u306E (y, value)\n    std::vector<std::vector<Value>>\
    \ s;   // \u7D2F\u7A4D\u548C\n\n    std::vector<point> points;\n\npublic:\n  \
    \  merge_sort_tree() = default;\n\n    void add_point(Key_x x, Key_y y, Value\
    \ v) { points.emplace_back(x, y, v); }\n\n    void build() {\n        xs.resize(points.size());\n\
    \        for (int i = 0; i < (int)points.size(); ++i) xs[i] = points[i].x;\n\n\
    \        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n\n        sz = 1, lg = 0;\n        while (sz <= (int)xs.size())\
    \ {\n            sz <<= 1;\n            lg++;\n        }\n\n        std::vector<std::vector<std::pair<Key_y,\
    \ Value>>> d(sz << 1);\n        s.resize(sz << 1), ys.resize(sz << 1);\n\n   \
    \     for (int i = 0; i < (int)points.size(); i++) {\n            int p = std::lower_bound(xs.begin(),\
    \ xs.end(), points[i].x) -\n                    xs.begin();\n            d[sz\
    \ + p].emplace_back(points[i].y, points[i].v);\n        }\n\n        for (int\
    \ i = 0; i < sz; ++i) {\n            std::sort(d[i + sz].begin(), d[i + sz].end());\n\
    \        }\n\n        for (int i = sz - 1; i; --i) {\n            int l = (i <<\
    \ 1 | 0), r = (i << 1 | 1);\n\n            std::merge(d[l].begin(), d[l].end(),\
    \ d[r].begin(), d[r].end(),\n                       std::back_inserter(d[i]));\n\
    \        }\n\n        for (int i = 1; i < (int)2 * sz; ++i) {\n            ys[i].resize(d[i].size());\n\
    \            s[i].resize(d[i].size() + 1);\n\n            for (int j = 0; j <\
    \ (int)d[i].size(); ++j) {\n                ys[i][j] = d[i][j].first;\n      \
    \          s[i][j + 1] = s[i][j] + d[i][j].second;\n            }\n        }\n\
    \    }\n\nprivate:\n    Value get(int i, Key_y lower, Key_y upper) {\n       \
    \ int l =\n            std::lower_bound(ys[i].begin(), ys[i].end(), lower) - ys[i].begin();\n\
    \        int r =\n            std::lower_bound(ys[i].begin(), ys[i].end(), upper)\
    \ - ys[i].begin();\n\n        return s[i][r] - s[i][l];\n    }\n\npublic:\n  \
    \  Value fold(Key_x l, Key_y r, Key_y lower, Key_y upper) {\n        l = std::lower_bound(xs.begin(),\
    \ xs.end(), l) - xs.begin();\n        r = std::lower_bound(xs.begin(), xs.end(),\
    \ r) - xs.begin();\n\n        l += sz, r += sz;\n\n        Value sum = 0;\n\n\
    \        while (l != r) {\n            if (l & 1) {\n                sum += get(l++,\
    \ lower, upper);\n            }\n            if (r & 1) {\n                sum\
    \ += get(--r, lower, upper);\n            }\n            l >>= 1, r >>= 1;\n \
    \       }\n\n        return sum;\n    }\n};\n};  // namespace kyopro\n\n/**\n\
    \ * @brief MergeSortTree\n*/\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n\
    #include <stdio.h>\n#include <string>\n#line 2 \"src/internal/type_traits.hpp\"\
    \n#include <iostream>\n#include <limits>\n#include <numeric>\n#include <typeinfo>\n\
    #include <cstdint>\n\nnamespace kyopro {\nnamespace internal {\ntemplate <typename...\
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
    \ bool chmin(T1& a, T2 b) {\n    return a > b && (a = b, true);\n}\n#line 6 \"\
    test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp\"\nusing namespace std;\n\
    using namespace kyopro;\n\nint main() {\n    int n, q;\n    read(n, q);\n\n  \
    \  merge_sort_tree<int, int, ll> mgst;\n    rep(i, n) {\n        int x, y, w;\n\
    \        read(x, y, w);\n        mgst.add_point(x, y, w);\n    }\n    mgst.build();\n\
    \    while (q--) {\n        int l, d, r, u;\n        read(l, d, r, u);\n     \
    \   put(mgst.fold(l, r, d, u));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../../../src/data-structure/data-structure-2d/merge-sort-tree.hpp\"\n#include\
    \ \"../../../src/stream.hpp\"\n#include \"../../../src/template.hpp\"\nusing namespace\
    \ std;\nusing namespace kyopro;\n\nint main() {\n    int n, q;\n    read(n, q);\n\
    \n    merge_sort_tree<int, int, ll> mgst;\n    rep(i, n) {\n        int x, y,\
    \ w;\n        read(x, y, w);\n        mgst.add_point(x, y, w);\n    }\n    mgst.build();\n\
    \    while (q--) {\n        int l, d, r, u;\n        read(l, d, r, u);\n     \
    \   put(mgst.fold(l, r, d, u));\n    }\n}"
  dependsOn:
  - src/data-structure/data-structure-2d/merge-sort-tree.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  - src/template.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp
  requiredBy: []
  timestamp: '2024-02-04 11:34:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp
---
