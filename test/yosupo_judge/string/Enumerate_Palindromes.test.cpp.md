---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/stream.hpp
    title: fastIO
  - icon: ':x:'
    path: src/string/manacher.hpp
    title: Manacher's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/yosupo_judge/string/Enumerate_Palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\
    #include <iostream>\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include\
    \ <stdio.h>\n#include <string>\nnamespace kyopro {\n/**\n * \u6587\u5B57\u3092\
    1\u500B\u8AAD\u307F\u8FBC\u3080\n */\ninline char readchar() {\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n    return c;\n}\n\n/**\n * \
    \ \u6574\u6570\u306E\u5165\u51FA\u529B\n */\ntemplate <typename T> constexpr inline\
    \ void readint(T& a) {\n    a = 0;\n    bool is_negative = false;\n    char c\
    \ = readchar();\n    if (c == '-') is_negative = true, c = getchar_unlocked();\n\
    \    while (isdigit(c)) {\n        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n\
    \    }\n    if (is_negative) a *= -1;\n}\ntemplate <typename Head, typename...\
    \ Tail>\nconstexpr inline void readint(Head& head, Tail&... tail) {\n    readint(head);\n\
    \    readint(tail...);\n}\n\ntemplate <typename T> constexpr inline void putint(T\
    \ a) {\n    if (!a) {\n        putchar_unlocked('0');\n        putchar_unlocked('\\\
    n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n\
    \    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now] = (char)'0'\
    \ + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    \    putchar_unlocked('\\n');\n}\ntemplate <typename Head, typename... Tail>\n\
    constexpr inline void putint(Head head, Tail... tail) {\n    putint(head);\n \
    \   putchar_unlocked('\\n');\n    putint(tail...);\n}\n\n/**\n * \u6587\u5B57\u5217\
    \u306E\u5165\u51FA\u529B\n */\ninline void readstr(std::string& str) {\n    char\
    \ c = readchar();\n    while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\ninline void readstr(std::string& str, std::string& tail...) {\n   \
    \ readstr(str);\n    readstr(tail);\n}\ninline void putstr(const std::string&\
    \ str) {\n    for (auto c : str) {\n        putchar_unlocked(c);\n    }\n    putchar_unlocked('\\\
    n');\n}\ninline void putstr(const std::string& str, const std::string& tail...)\
    \ {\n    putstr(str);\n    putstr(tail);\n}\n\n};  // namespace kyopro\n\n/**\n\
    \ * @brief fastIO\n */\n#line 2 \"src/string/manacher.hpp\"\n#include <cassert>\n\
    #line 4 \"src/string/manacher.hpp\"\n#include <utility>\n#include <vector>\nnamespace\
    \ kyopro {\n\n/**\n * @brief Manacher's algorithm\n */\nstd::vector<int> manacher(std::string\
    \ s, bool even = true) {\n    assert(s.size());\n    if (even) {\n        std::string\
    \ t;\n        t.resize(2 * (int)s.size() - 1);\n        for (int i = 0; i < (int)s.size();\
    \ i++) {\n            t[2 * i] = s[i];\n        }\n        for (int i = 0; i <\
    \ (int)s.size(); i++) {\n            t[2 * i + 1] = '$';\n        }\n        std::swap(t,\
    \ s);\n    }\n    std::vector<int> res(s.size());\n\n    int i = 0, j = 0;\n\n\
    \    while (i < (int)s.size()) {\n        while (i - j >= 0 && i + j < (int)s.size()\
    \ && s[i - j] == s[i + j]) {\n            j++;\n        }\n        res[i] = j;\n\
    \n        int k = 1;\n        while (i - k >= 0 && i + k < (int)s.size() && k\
    \ + res[i - k] < j) {\n            res[i + k] = res[i - k], k++;\n        }\n\
    \        i += k, j -= k;\n    }\n\n    if (even) {\n        for (int i = 0; i\
    \ < (int)res.size(); i++) {\n            if (~(i ^ res[i]) & 1) {\n          \
    \      res[i]--;\n            }\n        }\n    } else {\n        for (auto& r\
    \ : res) {\n            r = 2 * r - 1;\n        }\n    }\n    return res;\n}\n\
    };  // namespace kyopro\n#line 5 \"test/yosupo_judge/string/Enumerate_Palindromes.test.cpp\"\
    \nint main() {\n    std::string s;\n    {\n        char c;\n        while (!isspace(c\
    \ = getchar_unlocked())) s += c;\n    }\n    auto res = kyopro::manacher(s);\n\
    \    for (auto r : res) {\n        kyopro::putint(r);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include <iostream>\n#include \"../../../src/stream.hpp\"\n#include \"../../../src/string/manacher.hpp\"\
    \nint main() {\n    std::string s;\n    {\n        char c;\n        while (!isspace(c\
    \ = getchar_unlocked())) s += c;\n    }\n    auto res = kyopro::manacher(s);\n\
    \    for (auto r : res) {\n        kyopro::putint(r);\n    }\n}"
  dependsOn:
  - src/stream.hpp
  - src/string/manacher.hpp
  isVerificationFile: true
  path: test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 14:15:58+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
- /verify/test/yosupo_judge/string/Enumerate_Palindromes.test.cpp.html
title: test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
---
