---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/mo.hpp
    title: Mo's algorithm
  - icon: ':heavy_check_mark:'
    path: src/data-structure/BIT.hpp
    title: Binary Index Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
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
    #line 2 \"src/algorithm/mo.hpp\"\n#include <algorithm>\n#include <numeric>\n#include\
    \ <utility>\n#include <vector>\nnamespace kyopro {\n/**\n * @brief Mo's algorithm\n\
    \ */\nclass Mo {\n    int n;\n    std::vector<std::pair<int, int>> lr;\n    const\
    \ int logn;\n    const long long maxn;\n    std::vector<int> ord;\n\npublic:\n\
    \    explicit Mo(int n) : n(n), logn(20), maxn(1ll << logn) { lr.reserve(n); }\n\
    \    void add(int l, int r) { lr.emplace_back(l, r); }\n\nprivate:\n    long long\
    \ hilbertorder(int x, int y) {\n        long long d = 0;\n        for (int s =\
    \ 1 << (logn - 1); s; s >>= 1) {\n            bool rx = x & s, ry = y & s;\n \
    \           d = d << 2 | rx * 3 ^ static_cast<int>(ry);\n            if (!ry)\
    \ {\n                if (rx) {\n                    x = maxn - x;\n          \
    \          y = maxn - y;\n                }\n                std::swap(x, y);\n\
    \            }\n        }\n        return d;\n    }\n    void line_up() {\n  \
    \      int q = lr.size();\n        ord.resize(q);\n        std::iota(std::begin(ord),\
    \ std::end(ord), 0);\n        std::vector<long long> tmp(q);\n        for (int\
    \ i = 0; i < q; i++) {\n            tmp[i] = hilbertorder(lr[i].first, lr[i].second);\n\
    \        }\n        std::sort(std::begin(ord), std::end(ord),\n              \
    \    [&](int a, int b) { return tmp[a] < tmp[b]; });\n    }\n\npublic:\n    template\
    \ <typename AL, typename AR, typename EL, typename ER, typename O>\n    void build(const\
    \ AL& add_left,\n               const AR& add_right,\n               const EL&\
    \ erase_left,\n               const ER& erase_right,\n               const O&\
    \ out) {\n        line_up();\n        int l = 0, r = 0;\n        for (auto idx\
    \ : ord) {\n            while (l > lr[idx].first) add_left(--l);\n           \
    \ while (r < lr[idx].second) add_right(r++);\n            while (l < lr[idx].first)\
    \ erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            out(idx);\n        }\n    }\n\n    template <typename A, typename\
    \ E, typename O>\n    void build(const A& add, const E& erase, const O& out) {\n\
    \        build(add, add, erase, erase, out);\n    }\n};\n};  // namespace kyopro\n\
    \n/**\n * @docs docs/other/mo.md\n * @ref https://ei1333.hateblo.jp/entry/2017/09/11/211011\n\
    \ */\n#line 3 \"src/data-structure/BIT.hpp\"\nnamespace kyopro {\n/**\n * @brief\
    \ Binary Index Tree\n */\ntemplate <typename T> class BIT {\n    std::vector<T>\
    \ bit;\n    int n;\n\npublic:\n    explicit BIT() {}\n    explicit BIT(int n)\
    \ : n(n), bit(n + 1, T()) {}\n    void add(int p, T w) {\n        p++;\n     \
    \   for (int x = p; x <= n; x += x & -x) {\n            bit[x] += w;\n       \
    \ }\n    }\n\n    T sum(int p) const {\n        T s = 0;\n\n        for (int x\
    \ = p; x > 0; x -= x & -x) {\n            s += bit[x];\n        }\n        return\
    \ s;\n    }\n\n    T sum(int l, int r) const { return sum(r) - sum(l); }\n\n \
    \   int lower_bound(T w) const {\n        if (w <= 0) return 0;\n\n        int\
    \ x = 0;\n        int k = 1;\n        while (k < n) k <<= 1;\n        for (; k\
    \ > 0; k >>= 1) {\n            if (x + k <= n && bit[x + k] < w) {\n         \
    \       w -= bit[x + k];\n                x += k;\n            }\n        }\n\n\
    \        return x + 1;\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/BIT.md\n\
    \ */\n#line 6 \"test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp\"\
    \nint main() {\n    int n, q;\n    kyopro::readint(n, q);\n    kyopro::Mo mo(q);\n\
    \    std::vector<int> a(n);\n    for (auto& aa : a) {\n        kyopro::readint(aa);\n\
    \    }\n    std::vector<int> k(q);\n    for (int i = 0; i < q; i++) {\n      \
    \  int l, r;\n        scanf(\"%d%d%d\", &l, &r, &k[i]);\n        k[i]++;\n   \
    \     mo.add(l, r);\n    }\n    std::vector<int> pressed = a;\n    auto tmp =\
    \ a;\n    {\n        std::sort(tmp.begin(), tmp.end());\n        tmp.erase(std::unique(tmp.begin(),\
    \ tmp.end()), tmp.end());\n        for (auto& ai : pressed) {\n            ai\
    \ = lower_bound(tmp.begin(), tmp.end(), ai) - tmp.begin();\n        }\n    }\n\
    \n    int sz = tmp.size();\n    kyopro::BIT<int> st(sz);\n    auto add = [&](int\
    \ x) -> void { st.add(pressed[x], 1); };\n    auto del = [&](int x) -> void {\
    \ st.add(pressed[x], -1); };\n    std::vector<int> ans(q);\n    auto out = [&](int\
    \ x) -> void {\n        int ok = st.lower_bound(k[x]);\n        ans[x] = tmp[ok\
    \ - 1];\n    };\n\n    mo.build(add, del, out);\n    for (auto r : ans) {\n  \
    \      kyopro::putint(r);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../../src/stream.hpp\"\n#include \"../../../src/algorithm/mo.hpp\"\
    \n#include \"../../../src/data-structure/BIT.hpp\"\nint main() {\n    int n, q;\n\
    \    kyopro::readint(n, q);\n    kyopro::Mo mo(q);\n    std::vector<int> a(n);\n\
    \    for (auto& aa : a) {\n        kyopro::readint(aa);\n    }\n    std::vector<int>\
    \ k(q);\n    for (int i = 0; i < q; i++) {\n        int l, r;\n        scanf(\"\
    %d%d%d\", &l, &r, &k[i]);\n        k[i]++;\n        mo.add(l, r);\n    }\n   \
    \ std::vector<int> pressed = a;\n    auto tmp = a;\n    {\n        std::sort(tmp.begin(),\
    \ tmp.end());\n        tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());\n\
    \        for (auto& ai : pressed) {\n            ai = lower_bound(tmp.begin(),\
    \ tmp.end(), ai) - tmp.begin();\n        }\n    }\n\n    int sz = tmp.size();\n\
    \    kyopro::BIT<int> st(sz);\n    auto add = [&](int x) -> void { st.add(pressed[x],\
    \ 1); };\n    auto del = [&](int x) -> void { st.add(pressed[x], -1); };\n   \
    \ std::vector<int> ans(q);\n    auto out = [&](int x) -> void {\n        int ok\
    \ = st.lower_bound(k[x]);\n        ans[x] = tmp[ok - 1];\n    };\n\n    mo.build(add,\
    \ del, out);\n    for (auto r : ans) {\n        kyopro::putint(r);\n    }\n}\n"
  dependsOn:
  - src/stream.hpp
  - src/algorithm/mo.hpp
  - src/data-structure/BIT.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
  requiredBy: []
  timestamp: '2023-07-05 22:01:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
---
