---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data-structure/dsu.hpp
    title: Disjoint Set(Union Find)
  - icon: ':x:'
    path: src/stream.hpp
    title: fastIO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/UnionFind.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"src/data-structure/dsu.hpp\"\
    \n#include <utility>\n#include <vector>\nnamespace kyopro {\n\n/**\n * @brief\
    \ Disjoint Set(Union Find)\n */\nclass dsu {\nprivate:\n    std::vector<int> find;\n\
    \npublic:\n    dsu(int n) : find(n, -1) {}\n\n    int root(int x) {\n        if\
    \ (find[x] < 0) {\n            return x;\n        } else {\n            return\
    \ find[x] = root(find[x]);\n        }\n    }\n    bool same(int x, int y) { return\
    \ root(x) == root(y); }\n    int merge(int x, int y) {\n        x = root(x), y\
    \ = root(y);\n        if (x == y) return x;\n        if (find[x] > find[y]) std::swap(x,\
    \ y);\n        find[x] += find[y];\n        find[y] = x;\n        return x;\n\
    \    }\n    int size(int x) { return -find[root(x)]; }\n};\n\n};  // namespace\
    \ kyopro\n\n/**\n * @docs docs/data-structure/dsu.md\n */\n#line 2 \"src/stream.hpp\"\
    \n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n#include <concepts>\n\
    \nnamespace kyopro {\n/**\n * \u6587\u5B57\u30921\u500B\u8AAD\u307F\u8FBC\u3080\
    \n */\n\ninline char readchar() {\n    char c = getchar_unlocked();\n    while\
    \ (isspace(c)) c = getchar_unlocked();\n    return c;\n}\n/**\n *  \u6574\u6570\
    \u306E\u5165\u51FA\u529B\n */\ntemplate <std::integral T> constexpr inline void\
    \ read(T& a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\n\ntemplate <std::integral T> constexpr inline\
    \ void put(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n        putchar_unlocked('\\\
    n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n\
    \    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now] = (char)'0'\
    \ + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    \    putchar_unlocked('\\n');\n}\n\n/**\n * \u6587\u5B57\u5217\n*/\ninline void\
    \ read(std::string& str) {\n    char c = getchar_unlocked();\n    while (isspace(c))\
    \ c = getchar_unlocked();\n    while (!isspace(c)) {\n        str += c;\n    \
    \    c = getchar_unlocked();\n    }\n}\ninline void put(const std::string& str)\
    \ {\n    for (auto c : str) {\n        putchar_unlocked(c);\n    }\n    putchar_unlocked('\\\
    n');\n}\n\n/**\n * \u591A\u5909\u6570\n*/\ntemplate <typename Head, typename...\
    \ Tail>\nconstexpr inline void read(Head& head, Tail&... tail) {\n    read(head);\n\
    \    read(tail...);\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void put(const Head& head,const Tail&... tail) {\n    put(head);\n  \
    \  put(tail...);\n}\n};  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line\
    \ 5 \"test/yosupo_judge/data_structure/UnionFind.test.cpp\"\nint main() {\n  \
    \  int n, q;\n    kyopro::read(n, q);\n    kyopro::dsu uf(n);\n    while (q--)\
    \ {\n        int t, x, y;\n        kyopro::read(t, x, y);\n        if (!t) {\n\
    \            uf.merge(x, y);\n        } else {\n            if (uf.same(x, y))\n\
    \                puts(\"1\");\n            else\n                puts(\"0\");\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../../src/data-structure/dsu.hpp\"\n#include \"../../../src/stream.hpp\"\
    \nint main() {\n    int n, q;\n    kyopro::read(n, q);\n    kyopro::dsu uf(n);\n\
    \    while (q--) {\n        int t, x, y;\n        kyopro::read(t, x, y);\n   \
    \     if (!t) {\n            uf.merge(x, y);\n        } else {\n            if\
    \ (uf.same(x, y))\n                puts(\"1\");\n            else\n          \
    \      puts(\"0\");\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/dsu.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2023-07-21 13:15:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/UnionFind.test.cpp
- /verify/test/yosupo_judge/data_structure/UnionFind.test.cpp.html
title: test/yosupo_judge/data_structure/UnionFind.test.cpp
---
