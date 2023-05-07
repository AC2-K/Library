---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_D_lazy.test.cpp
    title: test/AOJ/DSL/2_D_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/1_A.test.cpp
    title: test/AOJ/GRL/1_A.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/graph/Shortest_Path.test.cpp
    title: test/yosupo_judge/graph/Shortest_Path.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/tree/Tree_Diameter.test.cpp
    title: test/yosupo_judge/tree/Tree_Diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u5165\u51FA\u529B"
    links: []
  bundledCode: "#line 2 \"src/stream.hpp\"\n#include <stdio.h>\n#include <ctype.h>\n\
    namespace kyopro {\ntemplate <typename T>\nconstexpr inline void readint(T& a)\
    \ {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void readint(Head& head, Tail&... tail) {\n    readint(head);\n    readint(tail...);\n\
    }\ntemplate <typename T>\nconstexpr inline void putint(T a) {\n    if (!a) {\n\
    \        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n        return;\n\
    \    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int\
    \ now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n       \
    \ a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n    putchar_unlocked('\\\
    n');\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void putint(Head\
    \ head, Tail... tail) {\n    putint(head);\n    putint(tail...);\n}\n\n};  //\
    \ namespace kyopro\n\n\n/**\n * @brief \u5165\u51FA\u529B\n*/\n"
  code: "#pragma once\n#include <stdio.h>\n#include <ctype.h>\nnamespace kyopro {\n\
    template <typename T>\nconstexpr inline void readint(T& a) {\n    a = 0;\n   \
    \ bool is_negative = false;\n    char c = getchar_unlocked();\n    while (isspace(c))\
    \ {\n        c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true,\
    \ c = getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 * a + (c -\
    \ '0');\n        c = getchar_unlocked();\n    }\n    if (is_negative) a *= -1;\n\
    }\ntemplate <typename Head, typename... Tail>\nconstexpr inline void readint(Head&\
    \ head, Tail&... tail) {\n    readint(head);\n    readint(tail...);\n}\ntemplate\
    \ <typename T>\nconstexpr inline void putint(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n\
    \        putchar_unlocked('\\n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now]\
    \ = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    \    putchar_unlocked('\\n');\n}\ntemplate <typename Head, typename... Tail>\n\
    constexpr inline void putint(Head head, Tail... tail) {\n    putint(head);\n \
    \   putint(tail...);\n}\n\n};  // namespace kyopro\n\n\n/**\n * @brief \u5165\u51FA\
    \u529B\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/stream.hpp
  requiredBy: []
  timestamp: '2023-05-07 23:12:04+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/DSL/2_D_lazy.test.cpp
  - test/AOJ/GRL/1_A.test.cpp
  - test/yosupo_judge/graph/Shortest_Path.test.cpp
  - test/yosupo_judge/tree/Tree_Diameter.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
documentation_of: src/stream.hpp
layout: document
redirect_from:
- /library/src/stream.hpp
- /library/src/stream.hpp.html
title: "\u5165\u51FA\u529B"
---
