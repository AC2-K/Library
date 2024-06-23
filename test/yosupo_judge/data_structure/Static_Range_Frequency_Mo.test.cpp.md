---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/mo.hpp
    title: Mo's algorithm
  - icon: ':heavy_check_mark:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: "Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\
    #include <iostream>\n#line 2 \"src/algorithm/mo.hpp\"\n#include <algorithm>\n\
    #include <numeric>\n#include <utility>\n#include <vector>\nnamespace kyopro {\n\
    class Mo {\n    int n;\n    std::vector<std::pair<int, int>> lr;\n    const int\
    \ logn;\n    const long long maxn;\n    std::vector<int> ord;\n\npublic:\n   \
    \ Mo(int n) : n(n), logn(20), maxn(1ll << logn) { lr.reserve(n); }\n    void add(int\
    \ l, int r) { lr.emplace_back(l, r); }\n\nprivate:\n    long long hilbertorder(int\
    \ x, int y) {\n        long long d = 0;\n        for (int s = 1 << (logn - 1);\
    \ s; s >>= 1) {\n            bool rx = x & s, ry = y & s;\n            d = d <<\
    \ 2 | rx * 3 ^ static_cast<int>(ry);\n            if (!ry) {\n               \
    \ if (rx) {\n                    x = maxn - x;\n                    y = maxn -\
    \ y;\n                }\n                std::swap(x, y);\n            }\n   \
    \     }\n        return d;\n    }\n    void _sort() {\n        int q = lr.size();\n\
    \        ord.resize(q);\n        std::iota(std::begin(ord), std::end(ord), 0);\n\
    \        std::vector<long long> tmp(q);\n        for (int i = 0; i < q; i++) {\n\
    \            tmp[i] = hilbertorder(lr[i].first, lr[i].second);\n        }\n  \
    \      std::sort(std::begin(ord), std::end(ord),\n                  [&](int a,\
    \ int b) { return tmp[a] < tmp[b]; });\n    }\n\npublic:\n    template <typename\
    \ AL, typename AR, typename EL, typename ER, typename O>\n    void build(const\
    \ AL& add_left,\n               const AR& add_right,\n               const EL&\
    \ erase_left,\n               const ER& erase_right,\n               const O&\
    \ out) {\n        _sort();\n        int l = 0, r = 0;\n        for (auto idx :\
    \ ord) {\n            while (l > lr[idx].first) add_left(--l);\n            while\
    \ (r < lr[idx].second) add_right(r++);\n            while (l < lr[idx].first)\
    \ erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            out(idx);\n        }\n    }\n\n    template <typename A, typename\
    \ E, typename O>\n    void build(const A& add, const E& erase, const O& out) {\n\
    \        build(add, add, erase, erase, out);\n    }\n};\n};  // namespace kyopro\n\
    \n/**\n * @brief Mo's algorithm\n * @see https://ei1333.hateblo.jp/entry/2017/09/11/211011\n\
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\n#line 3 \"src/internal/type_traits.hpp\"\n#include <limits>\n#line\
    \ 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\n#include <cstdint>\n\
    \nnamespace kyopro {\nnamespace internal {\ntemplate <typename... Args> struct\
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
    \ * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\n#line 6\
    \ \"src/stream.hpp\"\n\nnamespace kyopro {\n\ninline void single_read(char& c)\
    \ {\n    c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
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
    \ kyopro\n\n/**\n * @brief Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)\n */\n#line\
    \ 5 \"test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp\"\n\n\
    using namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n, q;\n\
    \    read(n, q);\n\n    vector<int> a(n);\n    for (auto& aa : a) read(aa);\n\
    \    auto pressed = a;\n    std::sort(pressed.begin(), pressed.end());\n    pressed.erase(unique(pressed.begin(),\
    \ pressed.end()), pressed.end());\n    for (auto& ai : a) {\n        ai = std::lower_bound(pressed.begin(),\
    \ pressed.end(), ai) -\n             pressed.begin();\n    }\n\n    Mo mo(q);\n\
    \    vector<int> x(q);\n    for (int i = 0; i < q; i++) {\n        int l, r;\n\
    \        read(l, r, x[i]);\n        mo.add(l, r);\n    }\n\n    vector<int> cnt(pressed.size()\
    \ + 1);\n    vector<int> ans(q);\n    auto add = [&](int v) -> void { cnt[a[v]]++;\
    \ };\n    auto del = [&](int v) -> void { cnt[a[v]]--; };\n    auto out = [&](int\
    \ v) -> void {\n        auto it = std::lower_bound(pressed.begin(), pressed.end(),\
    \ x[v]);\n        if (it == pressed.end() || (*it) != x[v]) {\n            ans[v]\
    \ = 0;\n        } else {\n            int xi = it - pressed.begin();\n       \
    \     ans[v] = cnt[xi];\n        }\n    };\n    mo.build(add, del, out);\n   \
    \ for (auto& aa : ans) put(aa);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n#include <iostream>\n#include \"../../../src/algorithm/mo.hpp\"\n#include \"\
    ../../../src/stream.hpp\"\n\nusing namespace std;\nusing namespace kyopro;\n\n\
    int main() {\n    int n, q;\n    read(n, q);\n\n    vector<int> a(n);\n    for\
    \ (auto& aa : a) read(aa);\n    auto pressed = a;\n    std::sort(pressed.begin(),\
    \ pressed.end());\n    pressed.erase(unique(pressed.begin(), pressed.end()), pressed.end());\n\
    \    for (auto& ai : a) {\n        ai = std::lower_bound(pressed.begin(), pressed.end(),\
    \ ai) -\n             pressed.begin();\n    }\n\n    Mo mo(q);\n    vector<int>\
    \ x(q);\n    for (int i = 0; i < q; i++) {\n        int l, r;\n        read(l,\
    \ r, x[i]);\n        mo.add(l, r);\n    }\n\n    vector<int> cnt(pressed.size()\
    \ + 1);\n    vector<int> ans(q);\n    auto add = [&](int v) -> void { cnt[a[v]]++;\
    \ };\n    auto del = [&](int v) -> void { cnt[a[v]]--; };\n    auto out = [&](int\
    \ v) -> void {\n        auto it = std::lower_bound(pressed.begin(), pressed.end(),\
    \ x[v]);\n        if (it == pressed.end() || (*it) != x[v]) {\n            ans[v]\
    \ = 0;\n        } else {\n            int xi = it - pressed.begin();\n       \
    \     ans[v] = cnt[xi];\n        }\n    };\n    mo.build(add, del, out);\n   \
    \ for (auto& aa : ans) put(aa);\n}"
  dependsOn:
  - src/algorithm/mo.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp.html
title: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
---
