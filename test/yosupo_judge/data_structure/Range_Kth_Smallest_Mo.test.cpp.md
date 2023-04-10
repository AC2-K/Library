---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/mo.hpp
    title: mo's algorithm
  - icon: ':heavy_check_mark:'
    path: src/data-structure/BIT.hpp
    title: Binary Index Tree
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
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#include<iostream>\n\
    #line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\nnamespace kyopro {\n\
    /// @brief Binary Index Tree\ntemplate <typename T, typename SumT = T> class BIT\
    \ {\n    std::vector<SumT> bit;\n    int n;\n\n  public:\n    explicit BIT(int\
    \ n) : n(n), bit(n + 1, T()) {}\n    void add(int p, const T& w) {\n        p++;\n\
    \        for (int x = p; x <= n; x += x & -x) {\n            bit[x] += w;\n  \
    \      }\n    }\n\n    SumT sum(int p) const {\n        T s = 0;\n\n        for\
    \ (int x = p; x > 0; x -= x & -x) {\n            s += bit[x];\n        }\n   \
    \     return s;\n    }\n\n    inline SumT sum(int l, int r) const { return sum(r)\
    \ - sum(l); }\n\n    int lower_bound(SumT w) const {\n        if (w <= 0) return\
    \ 0;\n\n        int x = 0;\n        int k = 1;\n        while (k < n) k <<= 1;\n\
    \        for (; k > 0; k >>= 1) {\n            if (x + k <= n && bit[x + k] <\
    \ w) {\n                w -= bit[x + k];\n                x += k;\n          \
    \  }\n        }\n\n        return x + 1;\n    }\n};\n};  // namespace kyopro\n\
    \n/// @docs docs/data-structure/BIT.md\n#line 2 \"src/algorithm/mo.hpp\"\n#include\
    \ <algorithm>\n#include <numeric>\n#line 5 \"src/algorithm/mo.hpp\"\n#include\
    \ <utility>\nnamespace kyopro {\n/// @brief mo's algorithm\nclass Mo {\n    int\
    \ n;\n    std::vector<std::pair<int, int>> lr;\n    const int logn;\n    const\
    \ long long maxn;\n    std::vector<int> ord;\n\n  public:\n    explicit Mo(int\
    \ n) : n(n), logn(20), maxn(1ll << logn) { lr.reserve(n); }\n    inline void add(int\
    \ l, int r) { lr.emplace_back(l, r); }\n    long long hilbertorder(int x, int\
    \ y) {\n        long long d = 0;\n        for (int s = 1 << (logn - 1); s; s >>=\
    \ 1) {\n            bool rx = x & s, ry = y & s;\n            d = d << 2 | rx\
    \ * 3 ^ static_cast<int>(ry);\n            if (!ry) {\n                if (rx)\
    \ {\n                    x = maxn - x;\n                    y = maxn - y;\n  \
    \              }\n                std::swap(x, y);\n            }\n        }\n\
    \        return d;\n    }\n\n  private:\n    inline void line_up() {\n       \
    \ int q = lr.size();\n        ord.resize(q);\n        std::iota(std::begin(ord),\
    \ std::end(ord), 0);\n        std::vector<long long> tmp(q);\n        for (int\
    \ i = 0; i < q; i++) {\n            tmp[i] = hilbertorder(lr[i].first, lr[i].second);\n\
    \        }\n        std::sort(std::begin(ord), std::end(ord),\n              \
    \    [&](int a, int b) { return tmp[a] < tmp[b]; });\n\n    }\n\n  public:\n \
    \   template <typename AL, typename AR, typename EL, typename ER, typename O>\n\
    \    void build(const AL& add_left,\n               const AR& add_right,\n   \
    \            const EL& erase_left,\n               const ER& erase_right,\n  \
    \             const O& out) {\n        line_up();\n        int l = 0, r = 0;\n\
    \        for (const auto& idx : ord) {\n            while (l > lr[idx].first)\
    \ add_left(--l);\n            while (r < lr[idx].second) add_right(r++);\n   \
    \         while (l < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second)\
    \ erase_right(--r);\n            out(idx);\n        }\n    }\n\n    template <typename\
    \ A, typename E, typename O>\n    void build(const A& add, const E& erase, const\
    \ O& out) {\n        build(add, add, erase, erase, out);\n    }\n};\n};  // namespace\
    \ kyopro\n\n/// @docs docs/other/mo.md\n#line 6 \"test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp\"\
    \nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n    kyopro::Mo mo(q);\n\
    \    std::vector<int> a(n);\n    for (auto& aa : a) {\n        scanf(\"%d\", &aa);\n\
    \    }\n    std::vector<int> k(q);\n    for(int i=0;i<q;i++) {\n        int l,\
    \ r;\n        scanf(\"%d%d%d\", &l, &r, &k[i]);\n        k[i]++;\n        mo.add(l,\
    \ r);\n    }\n    std::vector<int> pressed = a;\n    auto tmp = a;\n    {\n  \
    \      std::sort(tmp.begin(), tmp.end());\n        tmp.erase(std::unique(tmp.begin(),tmp.end()),\
    \ tmp.end());\n        for (auto& ai : pressed) {\n            ai = lower_bound(tmp.begin(),tmp.end(),\
    \ ai) - tmp.begin();\n        }\n    }\n\n    int sz = tmp.size();\n    kyopro::BIT<int>\
    \ st(sz);\n    auto add = [&](int x) -> void { st.add(pressed[x], 1); };\n   \
    \ auto del = [&](int x) -> void { st.add(pressed[x], -1); };\n    std::vector<int>\
    \ ans(q);\n    auto out = [&](int x) -> void {\n        int ok = st.lower_bound(k[x]);\n\
    \        ans[x] = tmp[ok - 1];\n    };\n\n    mo.build(add, del, out);\n    for\
    \ (auto& as : ans) {\n        printf(\"%d\\n\", as);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include<iostream>\n#include\"../../../src/data-structure/BIT.hpp\"\n#include\"\
    ../../../src/algorithm/mo.hpp\"\nint main() {\n    int n, q;\n    scanf(\"%d%d\"\
    , &n, &q);\n    kyopro::Mo mo(q);\n    std::vector<int> a(n);\n    for (auto&\
    \ aa : a) {\n        scanf(\"%d\", &aa);\n    }\n    std::vector<int> k(q);\n\
    \    for(int i=0;i<q;i++) {\n        int l, r;\n        scanf(\"%d%d%d\", &l,\
    \ &r, &k[i]);\n        k[i]++;\n        mo.add(l, r);\n    }\n    std::vector<int>\
    \ pressed = a;\n    auto tmp = a;\n    {\n        std::sort(tmp.begin(), tmp.end());\n\
    \        tmp.erase(std::unique(tmp.begin(),tmp.end()), tmp.end());\n        for\
    \ (auto& ai : pressed) {\n            ai = lower_bound(tmp.begin(),tmp.end(),\
    \ ai) - tmp.begin();\n        }\n    }\n\n    int sz = tmp.size();\n    kyopro::BIT<int>\
    \ st(sz);\n    auto add = [&](int x) -> void { st.add(pressed[x], 1); };\n   \
    \ auto del = [&](int x) -> void { st.add(pressed[x], -1); };\n    std::vector<int>\
    \ ans(q);\n    auto out = [&](int x) -> void {\n        int ok = st.lower_bound(k[x]);\n\
    \        ans[x] = tmp[ok - 1];\n    };\n\n    mo.build(add, del, out);\n    for\
    \ (auto& as : ans) {\n        printf(\"%d\\n\", as);\n    }\n}\n"
  dependsOn:
  - src/data-structure/BIT.hpp
  - src/algorithm/mo.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
  requiredBy: []
  timestamp: '2023-04-09 21:30:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
---
