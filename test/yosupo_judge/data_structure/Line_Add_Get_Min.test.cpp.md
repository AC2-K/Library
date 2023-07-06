---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/CHT.hpp
    title: Convex Hull Trick
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: fastIO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line\
    \ 2 \"src/data-structure/CHT.hpp\"\n#include <set>\nnamespace kyopro {\n\n/**\n\
    \ * @brief Convex Hull Trick\n * @tparam query_type true\u306B\u3059\u308B\u3068\
    \u30AF\u30A8\u30EA\u3067\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\u3088\u3046\
    \u306B\u5909\u66F4\u3059\u308B\n */\ntemplate <class T = long long, bool query_type\
    \ = false> class CHT {\n    class line {\n    public:\n        T a, b;\n     \
    \   bool is_query;\n        mutable T nxt_a, nxt_b;\n        mutable bool has_nxt;\n\
    \        T get(T x) const { return a * x + b; }\n        T get_nxt(T x) const\
    \ { return nxt_a * x + nxt_b; }\n        line(T a, T b, bool q = false)\n    \
    \        : a(a), b(b), is_query(q), has_nxt(false) {}\n        friend bool operator<(const\
    \ line& l, const line& r) {\n            if (l.is_query) {\n                if\
    \ (!r.has_nxt) return true;\n                return r.get(l.a) < r.get_nxt(l.a);\n\
    \            }\n            if (r.is_query) {\n                if (!l.has_nxt)\
    \ return false;\n                return l.get(r.a) > l.get_nxt(r.a);\n       \
    \     }\n            return l.a == r.a ? l.b < r.b : l.a < r.a;\n        }\n \
    \   };\n\n    std::set<line> ls;\n    bool is_needed(const typename std::set<line>::iterator&\
    \ it) {\n        if (it != ls.begin() && it->a == prev(it)->a) {\n           \
    \ return it->b < prev(it)->b;\n        }\n        if (next(it) != ls.end() &&\
    \ it->a == next(it)->a) {\n            return it->b < next(it)->b;\n        }\n\
    \        if (it == ls.begin() || next(it) == ls.end()) {\n            return true;\n\
    \        }\n        return 1. * (it->b - prev(it)->b) * (next(it)->a - it->a)\
    \ <\n               1. * (it->b - next(it)->b) * (prev(it)->a - it->a);\n    }\n\
    \npublic:\n    void insert(T a, T b) {\n        if (query_type) {\n          \
    \  ls.emplace(-a, -b);\n        } else {\n            ls.emplace(a, b);\n    \
    \    }\n\n        const line& ln = (query_type ? line{-a, -b} : line{a, b});\n\
    \        auto it = ls.find(ln);\n        if (!is_needed(it)) {\n            ls.erase(it);\n\
    \            return;\n        }\n        while (it != ls.begin() && !is_needed(prev(it)))\
    \ {\n            ls.erase(prev(it));\n        }\n        while (next(it) != ls.end()\
    \ && !is_needed(next(it))) {\n            ls.erase(next(it));\n        }\n   \
    \     if (it != ls.begin()) {\n            prev(it)->has_nxt = true;\n       \
    \     prev(it)->nxt_a = it->a;\n            prev(it)->nxt_b = it->b;\n       \
    \ }\n        if (next(it) != ls.end()) {\n            it->has_nxt = true;\n  \
    \          it->nxt_a = next(it)->a;\n            it->nxt_b = next(it)->b;\n  \
    \      }\n    }\n    T operator()(T x) const {\n        const auto& it = ls.lower_bound(line(x,\
    \ 0, true));\n\n        if (query_type) {\n            return -it->a * x - it->b;\n\
    \        } else {\n            return it->a * x + it->b;\n        }\n    }\n};\n\
    \n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/CHT.md\n */\n#line\
    \ 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n\
    namespace kyopro {\n\n/**\n *  \u6574\u6570\u306E\u5165\u51FA\u529B\n */\ntemplate\
    \ <typename T> constexpr inline void readint(T& a) {\n    a = 0;\n    bool is_negative\
    \ = false;\n    char c = getchar_unlocked();\n    while (isspace(c)) {\n     \
    \   c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true, c =\
    \ getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 * a + (c - '0');\n\
    \        c = getchar_unlocked();\n    }\n    if (is_negative) a *= -1;\n}\ntemplate\
    \ <typename Head, typename... Tail>\nconstexpr inline void readint(Head& head,\
    \ Tail&... tail) {\n    readint(head);\n    readint(tail...);\n}\n\ntemplate <typename\
    \ T> void write_int(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n  \
    \      putchar_unlocked('\\n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now]\
    \ = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T> constexpr inline void putint(T a) {\n    if (!a) {\n\
    \        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n        return;\n\
    \    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int\
    \ now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n       \
    \ a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n    putchar_unlocked('\\\
    n');\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void putint(Head\
    \ head, Tail... tail) {\n    putint(head);\n    putint(tail...);\n}\n\n/**\n *\
    \ \u6587\u5B57\u5217\u306E\u5165\u51FA\u529B\n */\n\nvoid readstr(std::string&\
    \ str) {\n    char c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    \    while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\n\nvoid readstr(std::string& str,std::string& tail...) {\n    readstr(str);\n\
    \    readstr(tail);\n}\nvoid putstr(const std::string& str) {\n    for (auto c\
    \ : str) {\n        putchar_unlocked(c);\n    }\n    putchar_unlocked('\\n');\n\
    }\nvoid putstr(const std::string& str, const std::string& tail...) {\n    putstr(str);\n\
    \    putstr(tail);\n}\n};  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n\
    #line 4 \"test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp\"\nusing\
    \ namespace std;\nint main() {\n    int n, q;\n    kyopro::readint(n, q);\n\n\
    \    kyopro::CHT<long long> cht;\n    for (int i = 0; i < n; i++) {\n        long\
    \ long a, b;\n        kyopro::readint(a, b);\n        cht.insert(a, b);\n    }\n\
    \    while (q--) {\n        int t;\n        kyopro::readint(t);\n        if (!t)\
    \ {\n            long long a, b;\n            kyopro::readint(a, b);\n       \
    \     cht.insert(a, b);\n        } else {\n            long long x;\n        \
    \    kyopro::readint(x);\n            kyopro::putint(cht(x));\n        }\n   \
    \ }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"../../../src/data-structure/CHT.hpp\"\n#include \"../../../src/stream.hpp\"\
    \nusing namespace std;\nint main() {\n    int n, q;\n    kyopro::readint(n, q);\n\
    \n    kyopro::CHT<long long> cht;\n    for (int i = 0; i < n; i++) {\n       \
    \ long long a, b;\n        kyopro::readint(a, b);\n        cht.insert(a, b);\n\
    \    }\n    while (q--) {\n        int t;\n        kyopro::readint(t);\n     \
    \   if (!t) {\n            long long a, b;\n            kyopro::readint(a, b);\n\
    \            cht.insert(a, b);\n        } else {\n            long long x;\n \
    \           kyopro::readint(x);\n            kyopro::putint(cht(x));\n       \
    \ }\n    }\n}"
  dependsOn:
  - src/data-structure/CHT.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
  requiredBy: []
  timestamp: '2023-07-05 22:01:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
- /verify/test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp.html
title: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
---
