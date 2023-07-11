---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/segtree.hpp
    title: SegmentTree
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include <algorithm>\n#include <iostream>\n#include <numeric>\n#line 2 \"src/data-structure/segtree.hpp\"\
    \n#include <cassert>\n#include <vector>\nnamespace kyopro {\n\n/**\n * @brief\
    \ SegmentTree\n */\ntemplate <class S, S (*op)(S, S), S (*e)()> class segtree\
    \ {\n    int lg, sz, n;\n    std::vector<S> dat;\n\npublic:\n    segtree() {}\n\
    \    segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const std::vector<S>&\
    \ vec) : n((int)vec.size()) {\n        sz = 1, lg = 0;\n        while (sz <= n)\
    \ {\n            sz <<= 1;\n            lg++;\n        }\n\n        dat = std::vector<S>(sz\
    \ << 1, e());\n\n        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n\
    \        }\n        build();\n    }\n\n    void set(int p, const S& v) {\n   \
    \     assert(0 <= p && p < sz);\n        dat[sz + p] = v;\n    }\n    void build()\
    \ {\n        for (int i = sz - 1; i > 0; i--) {\n            dat[i] = op(dat[i\
    \ << 1 | 0], dat[i << 1 | 1]);\n        }\n    }\n\n    S operator[](int p) const\
    \ { return dat[sz + p]; }\n\n    void update(int p, const S& v) {\n        assert(0\
    \ <= p && p < sz);\n        p += sz;\n        dat[p] = v;\n        while (p >>=\
    \ 1) {\n            dat[p] = op(dat[(p << 1) | 0], dat[(p << 1) | 1]);\n     \
    \   }\n    }\n\n    S fold(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= sz);\n        if (l == 0 && r == n) {\n            return dat[1];\n\
    \        }\n        l += sz, r += sz;\n        S sml = e(), smr = e();\n     \
    \   while (l != r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n      \
    \      if (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n  \
    \      }\n        return op(sml, smr);\n    }\n    void apply(int p, const S&\
    \ v) {\n        assert(0 <= p && p < sz);\n        update(p, op(dat[sz + p], v));\n\
    \    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/segtree.md\n\
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\nnamespace kyopro {\n/**\n * \u6587\u5B57\u30921\u500B\u8AAD\u307F\u8FBC\
    \u3080\n */\ninline char readchar() {\n    char c = getchar_unlocked();\n    while\
    \ (isspace(c)) c = getchar_unlocked();\n    return c;\n}\n/**\n *  \u6574\u6570\
    \u306E\u5165\u51FA\u529B\n */\ntemplate <typename T> constexpr inline void readint(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void readint(Head& head, Tail&... tail) {\n    readint(head);\n    readint(tail...);\n\
    }\n\ntemplate <typename T> void write_int(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n\
    \        putchar_unlocked('\\n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now]\
    \ = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T> constexpr inline void putint(T a) {\n    if (!a) {\n\
    \        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n        return;\n\
    \    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int\
    \ now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n       \
    \ a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n    putchar_unlocked('\\\
    n');\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void putint(Head\
    \ head, Tail... tail) {\n    putint(head);\n    putint(tail...);\n}\n\n/**\n *\
    \ \u6587\u5B57\u5217\u306E\u5165\u51FA\u529B\n */\n\ninline void readstr(std::string&\
    \ str) {\n    char c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    \    while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\n\ninline void readstr(std::string& str,std::string& tail...) {\n  \
    \  readstr(str);\n    readstr(tail);\n}\ninline void putstr(const std::string&\
    \ str) {\n    for (auto c : str) {\n        putchar_unlocked(c);\n    }\n    putchar_unlocked('\\\
    n');\n}\ninline void putstr(const std::string& str, const std::string& tail...)\
    \ {\n    putstr(str);\n    putstr(tail);\n}\n};  // namespace kyopro\n\n/**\n\
    \ * @brief fastIO\n */\n#line 7 \"test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp\"\
    \nusing S = std::pair<int, int>;\ninline S op(S x, S y) { return max(x, y); }\n\
    inline S e() { return S{0, 0}; }\n\nint main() {\n    int n;\n    kyopro::readint(n);\n\
    \    std::vector<int> a(n);\n    for (auto& aa : a) {\n        kyopro::readint(aa);\n\
    \    }\n    {\n        std::vector<int> tmp = a;\n        std::sort(tmp.begin(),\
    \ tmp.end());\n        tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());\n\
    \        for (auto& aa : a) {\n            aa = lower_bound(tmp.begin(), tmp.end(),\
    \ aa) - tmp.begin();\n        }\n    }\n    std::vector<int> prv(n, -1);\n   \
    \ std::iota(prv.begin(), prv.end(), 0);\n    kyopro::segtree<S, op, e> dp(n +\
    \ 1);\n    for (int i = 0; i < n; i++) {\n        auto [mx, p] = dp.fold(0, a[i]);\n\
    \        if (mx + 1 >= dp[a[i]].first) {\n            prv[i] = p;\n          \
    \  dp.update(a[i], S{mx + 1, i});\n        }\n    }\n    auto [res, cur] = dp.fold(0,\
    \ n + 1);\n    std::vector<int> idx;\n    idx.reserve((size_t)res);\n    for (int\
    \ i = 0; i < res; i++) {\n        idx.emplace_back(cur);\n        cur = prv[cur];\n\
    \    }\n    kyopro::putint(idx.size());\n    std::reverse(idx.begin(), idx.end());\n\
    \    for (auto i : idx) {\n        kyopro::putint(i);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include \"../../../src/data-structure/segtree.hpp\"\
    \n#include \"../../../src/stream.hpp\"\nusing S = std::pair<int, int>;\ninline\
    \ S op(S x, S y) { return max(x, y); }\ninline S e() { return S{0, 0}; }\n\nint\
    \ main() {\n    int n;\n    kyopro::readint(n);\n    std::vector<int> a(n);\n\
    \    for (auto& aa : a) {\n        kyopro::readint(aa);\n    }\n    {\n      \
    \  std::vector<int> tmp = a;\n        std::sort(tmp.begin(), tmp.end());\n   \
    \     tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());\n        for\
    \ (auto& aa : a) {\n            aa = lower_bound(tmp.begin(), tmp.end(), aa) -\
    \ tmp.begin();\n        }\n    }\n    std::vector<int> prv(n, -1);\n    std::iota(prv.begin(),\
    \ prv.end(), 0);\n    kyopro::segtree<S, op, e> dp(n + 1);\n    for (int i = 0;\
    \ i < n; i++) {\n        auto [mx, p] = dp.fold(0, a[i]);\n        if (mx + 1\
    \ >= dp[a[i]].first) {\n            prv[i] = p;\n            dp.update(a[i], S{mx\
    \ + 1, i});\n        }\n    }\n    auto [res, cur] = dp.fold(0, n + 1);\n    std::vector<int>\
    \ idx;\n    idx.reserve((size_t)res);\n    for (int i = 0; i < res; i++) {\n \
    \       idx.emplace_back(cur);\n        cur = prv[cur];\n    }\n    kyopro::putint(idx.size());\n\
    \    std::reverse(idx.begin(), idx.end());\n    for (auto i : idx) {\n       \
    \ kyopro::putint(i);\n    }\n}"
  dependsOn:
  - src/data-structure/segtree.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 14:41:52+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
- /verify/test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp.html
title: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
---
