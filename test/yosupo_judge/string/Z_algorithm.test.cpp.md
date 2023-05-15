---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/stream.hpp
    title: "\u5165\u51FA\u529B"
  - icon: ':x:'
    path: src/string/Z.hpp
    title: Z algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo_judge/string/Z_algorithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include <iostream>\n\
    #include <string>\n\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include\
    \ <stdio.h>\nnamespace kyopro {\ntemplate <typename T> constexpr inline void readint(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void readint(Head& head, Tail&... tail) {\n    readint(head);\n    readint(tail...);\n\
    }\ntemplate <typename T> constexpr inline void putint(T a) {\n    if (!a) {\n\
    \        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n        return;\n\
    \    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int\
    \ now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n       \
    \ a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n    putchar_unlocked('\\\
    n');\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void putint(Head\
    \ head, Tail... tail) {\n    putint(head);\n    putint(tail...);\n}\n\n};  //\
    \ namespace kyopro\n\n/**\n * @brief \u5165\u51FA\u529B\n */\n#line 2 \"src/string/Z.hpp\"\
    \n#include <cassert>\n#line 4 \"src/string/Z.hpp\"\n#include <vector>\nnamespace\
    \ kyopro {\n/**\n * @brief Z algorithm\n * @return LCP(S,S[i:]) (i=0,1,...,|str|-1)\n\
    \ */\nstd::vector<int> Z(const std::string& str) {\n    assert(str.size());\n\
    \    std::vector<int> res(str.size());\n    res.front() = (int)str.size();\n\n\
    \    int i = 1, j = 0;\n\n    while (i < (int)str.size()) {\n        while (i\
    \ + j < (int)str.size() && str[j] == str[i + j]) {\n            ++j;\n       \
    \ }\n\n        res[i] = j;\n        if (j == 0) {\n            ++i;\n        \
    \    continue;\n        }\n        int k = 1;\n        while (i + k < (int)str.size()\
    \ && k + res[k] < j) {\n            res[i + k] = res[k];\n            ++k;\n \
    \       }\n        i += k, j -= k;\n    }\n    return res;\n}\n};  // namespace\
    \ kyopro\n#line 7 \"test/yosupo_judge/string/Z_algorithm.test.cpp\"\n\nint main()\
    \ {\n    std::string s;\n    {\n        char c;\n        while (!isspace(c = getchar_unlocked()))\
    \ s += c;\n    }\n    auto res = kyopro::Z(s);\n    for (auto r : res) {\n   \
    \     kyopro::putint(r);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ <iostream>\n#include <string>\n\n#include \"../../../src/stream.hpp\"\n#include\
    \ \"../../../src/string/Z.hpp\"\n\nint main() {\n    std::string s;\n    {\n \
    \       char c;\n        while (!isspace(c = getchar_unlocked())) s += c;\n  \
    \  }\n    auto res = kyopro::Z(s);\n    for (auto r : res) {\n        kyopro::putint(r);\n\
    \    }\n}"
  dependsOn:
  - src/stream.hpp
  - src/string/Z.hpp
  isVerificationFile: true
  path: test/yosupo_judge/string/Z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 08:00:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/string/Z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/string/Z_algorithm.test.cpp
- /verify/test/yosupo_judge/string/Z_algorithm.test.cpp.html
title: test/yosupo_judge/string/Z_algorithm.test.cpp
---
