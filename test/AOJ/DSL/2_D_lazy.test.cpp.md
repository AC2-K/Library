---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/lazy_segtree.hpp
    title: LazySegmentTree
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"test/AOJ/DSL/2_D_lazy.test.cpp\"\n#define PROBLEM \\\n \
    \   \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\n\n#line\
    \ 2 \"src/data-structure/lazy_segtree.hpp\"\n#include <cassert>\n#include <vector>\n\
    namespace kyopro {\n/**\n * @brief LazySegmentTree\n */\ntemplate <class S,\n\
    \          class F,\n          auto op,\n          auto e,\n          auto composition,\n\
    \          auto id,\n          auto mapping>\nclass lazy_segtree {\n    int lg,\
    \ sz, n;\n    std::vector<S> dat;\n    std::vector<F> lazy;\n\npublic:\n    lazy_segtree()\
    \ {}\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}\n    lazy_segtree(const\
    \ std::vector<S>& a) : n((int)a.size()) {\n        sz = 1, lg = 0;\n        while\
    \ (sz <= n) {\n            sz <<= 1;\n            lg++;\n        }\n\n       \
    \ dat = std::vector<S>(sz << 1, e());\n        lazy = std::vector<F>(sz, id());\n\
    \        for (int i = 0; i < n; ++i) {\n            set(i, a[i]);\n        }\n\
    \        build();\n    }\n\npublic:\n    void set(int i, const S& v) {\n     \
    \   assert(0 <= i && i < sz);\n        dat[i + sz] = v;\n    }\n    void build()\
    \ {\n        for (int i = sz - 1; i > 0; --i) {\n            push_up(i);\n   \
    \     }\n    }\n\nprivate:\n    void all_apply(int p, const F& f) {\n        dat[p]\
    \ = mapping(dat[p], f);\n        if (p < sz) lazy[p] = composition(lazy[p], f);\n\
    \    }\n    void push_up(int k) { dat[k] = op(dat[k << 1 | 0], dat[k << 1 | 1]);\
    \ }\n    void push_down(int p) {\n        if (lazy[p] == id()) {\n           \
    \ return;\n        }\n        all_apply(p << 1 | 0, lazy[p]);\n        all_apply(p\
    \ << 1 | 1, lazy[p]);\n        lazy[p] = id();\n    }\n\npublic:\n    S operator[](int\
    \ p) {\n        assert(0 <= p && p < n);\n        p += sz;\n        for (int i\
    \ = lg; i > 0; --i) push_down(p >> i);\n        return dat[p];\n    }\n    S fold(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r)\
    \ return e();\n\n        l += sz, r += sz;\n        for (int i = lg; i > 0; --i)\
    \ {\n            if (((l >> i) << i) != l) {\n                push_down(l >> i);\n\
    \            }\n            if (((r >> i) << i) != r) {\n                push_down((r\
    \ - 1) >> i);\n            }\n        }\n\n        S sml = e(), smr = e();\n \
    \       while (l < r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n   \
    \         if (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n\
    \        }\n\n        return op(sml, smr);\n    }\n    void apply(int l, int r,\
    \ const F& v) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l ==\
    \ r) return;\n        l += sz, r += sz;\n        for (int i = lg; i > 0; --i)\
    \ {\n            if (((l >> i) << i) != l) {\n                push_down(l >> i);\n\
    \            }\n            if (((r >> i) << i) != r) {\n                push_down((r\
    \ - 1) >> i);\n            }\n        }\n        {\n            int l2 = l, r2\
    \ = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ v);\n                if (r & 1) all_apply(--r, v);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = l2;\n            r =\
    \ r2;\n        }\n\n        for (int i = 1; i <= lg; ++i) {\n            if (((l\
    \ >> i) << i) != l) push_up(l >> i);\n            if (((r >> i) << i) != r) push_up((r\
    \ - 1) >> i);\n        }\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs\
    \ docs/data-structure/lazy_segtree.md\n */\n#line 2 \"src/stream.hpp\"\n#include\
    \ <ctype.h>\n#include <stdio.h>\n#include <string>\nnamespace kyopro {\n\n/**\n\
    \ *  \u6574\u6570\u306E\u5165\u51FA\u529B\n */\ntemplate <typename T> constexpr\
    \ inline void readint(T& a) {\n    a = 0;\n    bool is_negative = false;\n   \
    \ char c = getchar_unlocked();\n    while (isspace(c)) {\n        c = getchar_unlocked();\n\
    \    }\n    if (c == '-') is_negative = true, c = getchar_unlocked();\n    while\
    \ (isdigit(c)) {\n        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n\
    \    }\n    if (is_negative) a *= -1;\n}\ntemplate <typename Head, typename...\
    \ Tail>\nconstexpr inline void readint(Head& head, Tail&... tail) {\n    readint(head);\n\
    \    readint(tail...);\n}\n\ntemplate <typename T> void write_int(T a) {\n   \
    \ if (!a) {\n        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n\
    \        return;\n    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char\
    \ s[37];\n    int now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a\
    \ % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
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
    \    }\n}\nvoid putstr(const std::string& str) {\n    for (auto c : str) {\n \
    \       putchar_unlocked(c);\n    }\n    putchar_unlocked('\\n');\n}\n\n};  //\
    \ namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 6 \"test/AOJ/DSL/2_D_lazy.test.cpp\"\
    \ninline int op(int x, int y) { return std::min(x, y); }\ninline int comp(int\
    \ x, int y) { return y; }\ninline int mapping(int x, int y) { return y; }\ninline\
    \ int e() { return (1ll << 31) - 1; }\ninline int id() { return (1ll << 31) -\
    \ 1; }\n\nint main() {\n    int n, q;\n    kyopro::readint(n, q);\n    kyopro::lazy_segtree<int,\
    \ int, op, e, comp, id, mapping> seg(n);\n    while (q--) {\n        int t;\n\
    \        kyopro::readint(t);\n        if (!t) {\n            int l, r, add;\n\
    \            kyopro::readint(l, r, add);\n            seg.apply(l, r + 1, add);\n\
    \        } else {\n            int i;\n            kyopro::readint(i);\n     \
    \       kyopro::putint(seg[i]);\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#include \"../../../src/data-structure/lazy_segtree.hpp\"\n#include \"../../../src/stream.hpp\"\
    \ninline int op(int x, int y) { return std::min(x, y); }\ninline int comp(int\
    \ x, int y) { return y; }\ninline int mapping(int x, int y) { return y; }\ninline\
    \ int e() { return (1ll << 31) - 1; }\ninline int id() { return (1ll << 31) -\
    \ 1; }\n\nint main() {\n    int n, q;\n    kyopro::readint(n, q);\n    kyopro::lazy_segtree<int,\
    \ int, op, e, comp, id, mapping> seg(n);\n    while (q--) {\n        int t;\n\
    \        kyopro::readint(t);\n        if (!t) {\n            int l, r, add;\n\
    \            kyopro::readint(l, r, add);\n            seg.apply(l, r + 1, add);\n\
    \        } else {\n            int i;\n            kyopro::readint(i);\n     \
    \       kyopro::putint(seg[i]);\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/lazy_segtree.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2_D_lazy.test.cpp
  requiredBy: []
  timestamp: '2023-06-02 22:21:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2_D_lazy.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2_D_lazy.test.cpp
- /verify/test/AOJ/DSL/2_D_lazy.test.cpp.html
title: test/AOJ/DSL/2_D_lazy.test.cpp
---
