---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/BIT.hpp
    title: Binary Index Tree
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/stream.hpp
    title: fastIO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <iostream>\n#line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\nnamespace\
    \ kyopro {\n/**\n * @brief Binary Index Tree\n */\ntemplate <typename T> class\
    \ BIT {\n    std::vector<T> bit;\n    int n;\n\npublic:\n    explicit BIT() {}\n\
    \    explicit BIT(int n) : n(n), bit(n + 1, T()) {}\n    void add(int p, T w)\
    \ {\n        p++;\n        for (int x = p; x <= n; x += x & -x) {\n          \
    \  bit[x] += w;\n        }\n    }\n\n    T sum(int p) const {\n        T s = 0;\n\
    \n        for (int x = p; x > 0; x -= x & -x) {\n            s += bit[x];\n  \
    \      }\n        return s;\n    }\n\n    T sum(int l, int r) const { return sum(r)\
    \ - sum(l); }\n\n    int lower_bound(T w) const {\n        if (w <= 0) return\
    \ 0;\n\n        int x = 0;\n        int k = 1;\n        while (k < n) k <<= 1;\n\
    \        for (; k > 0; k >>= 1) {\n            if (x + k <= n && bit[x + k] <\
    \ w) {\n                w -= bit[x + k];\n                x += k;\n          \
    \  }\n        }\n\n        return x + 1;\n    }\n};\n};  // namespace kyopro\n\
    \n/**\n * @docs docs/data-structure/BIT.md\n */\n#line 2 \"src/stream.hpp\"\n\
    #include <ctype.h>\n#include <stdio.h>\n#include <string>\n#line 3 \"src/internal/type_traits.hpp\"\
    \n#include <limits>\n#include <numeric>\n#include <typeinfo>\nnamespace kyopro\
    \ {\nnamespace internal {\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
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
    \  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 5 \"test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp\"\
    \nint main() {\n    int n, q;\n    kyopro::read(n, q);\n    kyopro::BIT<long long>\
    \ seg(n);\n    for (int i = 0; i < n; i++) {\n        int a;\n        kyopro::read(a);\n\
    \        seg.add(i, a);\n    }\n\n    while (q--) {\n        int t;\n        kyopro::read(t);\n\
    \        if (t == 0) {\n            int p, x;\n            kyopro::read(p, x);\n\
    \            seg.add(p, x);\n        } else {\n            int l, r;\n       \
    \     kyopro::read(l, r);\n            kyopro::put(seg.sum(l, r));\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include \"../../../src/data-structure/BIT.hpp\"\n#include\
    \ \"../../../src/stream.hpp\"\nint main() {\n    int n, q;\n    kyopro::read(n,\
    \ q);\n    kyopro::BIT<long long> seg(n);\n    for (int i = 0; i < n; i++) {\n\
    \        int a;\n        kyopro::read(a);\n        seg.add(i, a);\n    }\n\n \
    \   while (q--) {\n        int t;\n        kyopro::read(t);\n        if (t ==\
    \ 0) {\n            int p, x;\n            kyopro::read(p, x);\n            seg.add(p,\
    \ x);\n        } else {\n            int l, r;\n            kyopro::read(l, r);\n\
    \            kyopro::put(seg.sum(l, r));\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/BIT.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  requiredBy: []
  timestamp: '2023-07-29 13:52:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp.html
title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
---
