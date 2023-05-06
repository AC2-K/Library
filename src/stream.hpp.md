---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5165\u51FA\u529B"
    links: []
  bundledCode: "#line 2 \"src/stream.hpp\"\n#include <stdio.h>\nnamespace kyopro {\n\
    /// @brief \u5165\u51FA\u529B\n\ntemplate <typename T>\ninline void readint(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_un - locked();\n    }\n    if (c\
    \ == '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c))\
    \ {\n        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n\
    \    if (is_negative) a *= -1;\n}\ntemplate <typename Head, typename... Tail>\n\
    inline void readint(Head& head, Tail&... tail) {\n    readint(head);\n    readint(tail...);\n\
    }\ntemplate <typename T>\ninline void putint(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n\
    \        putchar_unlocked(' ');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    static char s[37];\n    int now = 37;\n    while (a) {\n     \
    \   s[--now] = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now <\
    \ 37) putchar_unlocked(s[now++]);\n    putchar_unlocked(' ');\n}\ntemplate <typename\
    \ Head, typename... Tail>\ninline void putint(Head& head, Tail&... tail) {\n \
    \   putint(head);\n    putint(tail...);\n}\n\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <stdio.h>\nnamespace kyopro {\n/// @brief \u5165\u51FA\
    \u529B\n\ntemplate <typename T>\ninline void readint(T& a) {\n    a = 0;\n   \
    \ bool is_negative = false;\n    char c = getchar_unlocked();\n    while (isspace(c))\
    \ {\n        c = getchar_un - locked();\n    }\n    if (c == '-') is_negative\
    \ = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 *\
    \ a + (c - '0');\n        c = getchar_unlocked();\n    }\n    if (is_negative)\
    \ a *= -1;\n}\ntemplate <typename Head, typename... Tail>\ninline void readint(Head&\
    \ head, Tail&... tail) {\n    readint(head);\n    readint(tail...);\n}\ntemplate\
    \ <typename T>\ninline void putint(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n\
    \        putchar_unlocked(' ');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    static char s[37];\n    int now = 37;\n    while (a) {\n     \
    \   s[--now] = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now <\
    \ 37) putchar_unlocked(s[now++]);\n    putchar_unlocked(' ');\n}\ntemplate <typename\
    \ Head, typename... Tail>\ninline void putint(Head& head, Tail&... tail) {\n \
    \   putint(head);\n    putint(tail...);\n}\n\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/stream.hpp
  requiredBy: []
  timestamp: '2023-05-06 08:48:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/stream.hpp
layout: document
redirect_from:
- /library/src/stream.hpp
- /library/src/stream.hpp.html
title: "\u5165\u51FA\u529B"
---
