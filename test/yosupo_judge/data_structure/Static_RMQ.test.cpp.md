---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data-structure/sparse_table.hpp
    title: SparseTable
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Static_RMQ.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n\
    #line 2 \"src/data-structure/sparse_table.hpp\"\n#include <numeric>\n#include\
    \ <vector>\nnamespace kyopro {\n\n/**\n * @brief SparseTable\n */\ntemplate <class\
    \ T, auto op> class sparse_table {\n    std::vector<T> vec;\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<int> look_up;\n\npublic:\n    constexpr explicit sparse_table(int\
    \ n) : vec(n) {}\n    constexpr explicit sparse_table(const std::vector<T>& vec)\
    \ : vec(vec) {\n        build();\n    }\n    void set(int p, const T& v) { vec[p]\
    \ = v; }\n    void build() {\n        int sz = vec.size();\n        int log =\
    \ 0;\n        while ((1 << log) <= sz) {\n            log++;\n        }\n    \
    \    table.assign(log, std::vector<T>(1 << log));\n        for (int i = 0; i <\
    \ sz; i++) {\n            table[0][i] = vec[i];\n        }\n        for (int i\
    \ = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <= (1 << log);\
    \ j++) {\n                table[i][j] =\n                    op(table[i - 1][j],\
    \ table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n        look_up.resize(sz\
    \ + 1);\n        for (int i = 2; i < (int)look_up.size(); i++) {\n           \
    \ look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n    T fold(int l, int\
    \ r) const {\n        int b = look_up[r - l];\n        return op(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs\
    \ docs/data-structure/sparse_table.md\n */\n#line 2 \"src/stream.hpp\"\n#include\
    \ <ctype.h>\n#include <stdio.h>\n#include <string>\n#line 3 \"src/internal/type_traits.hpp\"\
    \n#include <limits>\n#line 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\n\
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
    \  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 5 \"test/yosupo_judge/data_structure/Static_RMQ.test.cpp\"\
    \n\ninline int op(int x, int y) { return std::min(x, y); }\nint main() {\n   \
    \ int n, q;\n    kyopro::read(n, q);\n    kyopro::sparse_table<int, op> rmq(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int ai;\n        kyopro::read(ai);\n\
    \        rmq.set(i, ai);\n    }\n    rmq.build();\n    while (q--) {\n       \
    \ int l, r;\n        kyopro::read(l, r);\n        kyopro::put(rmq.fold(l, r));\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n\
    #include \"../../../src/data-structure/sparse_table.hpp\"\n#include\"../../../src/stream.hpp\"\
    \n\ninline int op(int x, int y) { return std::min(x, y); }\nint main() {\n   \
    \ int n, q;\n    kyopro::read(n, q);\n    kyopro::sparse_table<int, op> rmq(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int ai;\n        kyopro::read(ai);\n\
    \        rmq.set(i, ai);\n    }\n    rmq.build();\n    while (q--) {\n       \
    \ int l, r;\n        kyopro::read(l, r);\n        kyopro::put(rmq.fold(l, r));\n\
    \    }\n}"
  dependsOn:
  - src/data-structure/sparse_table.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2023-07-29 13:52:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp.html
title: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
---
