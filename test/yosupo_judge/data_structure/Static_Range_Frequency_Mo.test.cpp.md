---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/algorithm/mo.hpp
    title: Mo's algorithm
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/stream.hpp
    title: fastIO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\
    #include <iostream>\n#line 2 \"src/algorithm/mo.hpp\"\n#include <algorithm>\n\
    #include <numeric>\n#include <utility>\n#include <vector>\nnamespace kyopro {\n\
    /**\n * @brief Mo's algorithm\n */\nclass Mo {\n    int n;\n    std::vector<std::pair<int,\
    \ int>> lr;\n    const int logn;\n    const long long maxn;\n    std::vector<int>\
    \ ord;\n\npublic:\n    explicit Mo(int n) : n(n), logn(20), maxn(1ll << logn)\
    \ { lr.reserve(n); }\n    void add(int l, int r) { lr.emplace_back(l, r); }\n\n\
    private:\n    long long hilbertorder(int x, int y) {\n        long long d = 0;\n\
    \        for (int s = 1 << (logn - 1); s; s >>= 1) {\n            bool rx = x\
    \ & s, ry = y & s;\n            d = d << 2 | rx * 3 ^ static_cast<int>(ry);\n\
    \            if (!ry) {\n                if (rx) {\n                    x = maxn\
    \ - x;\n                    y = maxn - y;\n                }\n               \
    \ std::swap(x, y);\n            }\n        }\n        return d;\n    }\n    void\
    \ line_up() {\n        int q = lr.size();\n        ord.resize(q);\n        std::iota(std::begin(ord),\
    \ std::end(ord), 0);\n        std::vector<long long> tmp(q);\n        for (int\
    \ i = 0; i < q; i++) {\n            tmp[i] = hilbertorder(lr[i].first, lr[i].second);\n\
    \        }\n        std::sort(std::begin(ord), std::end(ord),\n              \
    \    [&](int a, int b) { return tmp[a] < tmp[b]; });\n    }\n\npublic:\n    template\
    \ <typename AL, typename AR, typename EL, typename ER, typename O>\n    void build(const\
    \ AL& add_left,\n               const AR& add_right,\n               const EL&\
    \ erase_left,\n               const ER& erase_right,\n               const O&\
    \ out) {\n        line_up();\n        int l = 0, r = 0;\n        for (auto idx\
    \ : ord) {\n            while (l > lr[idx].first) add_left(--l);\n           \
    \ while (r < lr[idx].second) add_right(r++);\n            while (l < lr[idx].first)\
    \ erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            out(idx);\n        }\n    }\n\n    template <typename A, typename\
    \ E, typename O>\n    void build(const A& add, const E& erase, const O& out) {\n\
    \        build(add, add, erase, erase, out);\n    }\n};\n};  // namespace kyopro\n\
    \n/**\n * @docs docs/other/mo.md\n * @ref https://ei1333.hateblo.jp/entry/2017/09/11/211011\n\
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\n#line 3 \"src/internal/type_traits.hpp\"\n#include <limits>\n#line\
    \ 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\nnamespace kyopro {\n\
    namespace internal {\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
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
    };  // namespace internal\n};  // namespace kyopro\n#line 6 \"src/stream.hpp\"\
    \n\nnamespace kyopro {\n// read\nvoid single_read(char& c) {\n    c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n}\ntemplate <typename T,\n  \
    \        std::enable_if_t<std::is_integral<T>::value ||\n                    \
    \       std::is_same<T, __int128_t>::value ||\n                           std::is_same<T,\
    \ __uint128_t>::value>* = nullptr>\nvoid single_read(T& a) {\n    a = 0;\n   \
    \ bool is_negative = false;\n    char c = getchar_unlocked();\n    while (isspace(c))\
    \ {\n        c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true,\
    \ c = getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 * a + (c -\
    \ '0');\n        c = getchar_unlocked();\n    }\n    if (is_negative) a *= -1;\n\
    }\nvoid single_read(std::string& str) {\n    char c = getchar_unlocked();\n  \
    \  while (isspace(c)) c = getchar_unlocked();\n    while (!isspace(c)) {\n   \
    \     str += c;\n        c = getchar_unlocked();\n    }\n}\n\nvoid read() {}\n\
    template <typename Head, typename... Tail>\nvoid read(Head& head, Tail&... tail)\
    \ {\n    single_read(head), read(tail...);\n}\n\n// write\nvoid single_write(char\
    \ c) { putchar_unlocked(c); }\ntemplate <typename T,\n          std::enable_if_t<std::is_integral<T>::value\
    \ ||\n                           std::is_same<T, __int128_t>::value ||\n     \
    \                      std::is_same<T, __uint128_t>::value>* = nullptr>\nvoid\
    \ single_write(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n       \
    \ putchar_unlocked('\\n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now]\
    \ = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    }\nvoid single_write(const std::string& str) {\n    for (auto c : str) {\n   \
    \     putchar_unlocked(c);\n    }\n}\nvoid write() {}\ntemplate <typename Head,\
    \ typename... Tail> void write(Head head, Tail... tail) {\n    single_write(head);\n\
    \    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate <typename... Args>\
    \ void put(Args... x) {\n    write(x...);\n    putchar_unlocked('\\n');\n}\n};\
    \  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 5 \"test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    kyopro::read(n, q);\n\n    std::vector<int>\
    \ a(n);\n    for (auto& aa : a) {\n        kyopro::read(aa);\n    }\n    auto\
    \ pressed = a;\n    std::sort(pressed.begin(), pressed.end());\n    pressed.erase(unique(pressed.begin(),\
    \ pressed.end()), pressed.end());\n    for (auto& ai : a) {\n        ai = std::lower_bound(pressed.begin(),\
    \ pressed.end(), ai) -\n             pressed.begin();\n    }\n    kyopro::Mo mo(q);\n\
    \    std::vector<int> x(q);\n    for (int i = 0; i < q; i++) {\n        int l,\
    \ r;\n        kyopro::read(l, r, x[i]);\n        mo.add(l, r);\n    }\n\n    std::vector<int>\
    \ cnt(pressed.size() + 1);\n    std::vector<int> ans(q);\n    auto add = [&](int\
    \ v) -> void { cnt[a[v]]++; };\n    auto del = [&](int v) -> void { cnt[a[v]]--;\
    \ };\n    auto out = [&](int v) -> void {\n        auto it = std::lower_bound(pressed.begin(),\
    \ pressed.end(), x[v]);\n        if (it == pressed.end() || (*it) != x[v]) {\n\
    \            ans[v] = 0;\n        } else {\n            int xi = it - pressed.begin();\n\
    \            ans[v] = cnt[xi];\n        }\n    };\n    mo.build(add, del, out);\n\
    \    for (auto& aa : ans) {\n        kyopro::put(aa);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n#include <iostream>\n#include \"../../../src/algorithm/mo.hpp\"\n#include\"\
    ../../../src/stream.hpp\"\n\nint main() {\n    int n, q;\n    kyopro::read(n,\
    \ q);\n\n    std::vector<int> a(n);\n    for (auto& aa : a) {\n        kyopro::read(aa);\n\
    \    }\n    auto pressed = a;\n    std::sort(pressed.begin(), pressed.end());\n\
    \    pressed.erase(unique(pressed.begin(), pressed.end()), pressed.end());\n \
    \   for (auto& ai : a) {\n        ai = std::lower_bound(pressed.begin(), pressed.end(),\
    \ ai) -\n             pressed.begin();\n    }\n    kyopro::Mo mo(q);\n    std::vector<int>\
    \ x(q);\n    for (int i = 0; i < q; i++) {\n        int l, r;\n        kyopro::read(l,\
    \ r, x[i]);\n        mo.add(l, r);\n    }\n\n    std::vector<int> cnt(pressed.size()\
    \ + 1);\n    std::vector<int> ans(q);\n    auto add = [&](int v) -> void { cnt[a[v]]++;\
    \ };\n    auto del = [&](int v) -> void { cnt[a[v]]--; };\n    auto out = [&](int\
    \ v) -> void {\n        auto it = std::lower_bound(pressed.begin(), pressed.end(),\
    \ x[v]);\n        if (it == pressed.end() || (*it) != x[v]) {\n            ans[v]\
    \ = 0;\n        } else {\n            int xi = it - pressed.begin();\n       \
    \     ans[v] = cnt[xi];\n        }\n    };\n    mo.build(add, del, out);\n   \
    \ for (auto& aa : ans) {\n        kyopro::put(aa);\n    }\n}"
  dependsOn:
  - src/algorithm/mo.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
  requiredBy: []
  timestamp: '2023-07-29 13:52:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp.html
title: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
---
