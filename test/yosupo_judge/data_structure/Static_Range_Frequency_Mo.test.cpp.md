---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/mo.hpp
    title: mo's algorithm
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\
    #line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N) for (int\
    \ i = 0; i < (N); i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 5 \"misc/mo.hpp\"\n\n/// @brief mo's algorithm\nclass Mo {\n    int n;\n\
    \    std::vector<std::pair<int, int>> lr;\n    const int logn;\n    const long\
    \ long maxn;\n    std::vector<int> ord;\n\n  public:\n    explicit Mo(int n) :\
    \ n(n), logn(20), maxn(1ll << logn) { lr.reserve(n); }\n    void add(int l, int\
    \ r) { lr.emplace_back(l, r); }\n    long long hilbertorder(int x, int y) {\n\
    \        long long d = 0;\n        for (int s = 1 << (logn - 1); s; s >>= 1) {\n\
    \            bool rx = x & s, ry = y & s;\n            d = d << 2 | rx * 3 ^ static_cast<int>(ry);\n\
    \            if (!ry) {\n                if (rx) {\n                    x = maxn\
    \ - x;\n                    y = maxn - y;\n                }\n               \
    \ std::swap(x, y);\n            }\n        }\n        return d;\n    }\n\n  private:\n\
    \    inline void line_up() {\n        int q = lr.size();\n        ord.resize(q);\n\
    \        std::iota(std::begin(ord), std::end(ord), 0);\n        std::vector<long\
    \ long> tmp(q);\n        for (int i = 0; i < q; i++) {\n            tmp[i] = hilbertorder(lr[i].first,\
    \ lr[i].second);\n        }\n        std::sort(std::begin(ord), std::end(ord),\n\
    \                  [&](int a, int b) { return tmp[a] < tmp[b]; });\n    }\n\n\
    \  public:\n    template <typename AL, typename AR, typename EL, typename ER,\
    \ typename O>\n    void build(const AL& add_left,\n               const AR& add_right,\n\
    \               const EL& erase_left,\n               const ER& erase_right,\n\
    \               const O& out) {\n        line_up();\n        int l = 0, r = 0;\n\
    \        for (const auto& idx : ord) {\n            while (l > lr[idx].first)\
    \ add_left(--l);\n            while (r < lr[idx].second) add_right(r++);\n   \
    \         while (l < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second)\
    \ erase_right(--r);\n            out(idx);\n        }\n    }\n\n    template <typename\
    \ A, typename E, typename O>\n    void build(const A& add, const E& erase, const\
    \ O& out) {\n        build(add, add, erase, erase, out);\n    }\n};\n/// @docs\
    \ docs/other/mo.md\n#line 4 \"test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp\"\
    \nusing namespace std;\nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n\
    \n    vector<int> a(n);\n    for (auto& aa : a) {\n        scanf(\"%d\", &aa);\n\
    \    }\n    auto pressed = a;\n    sort(pressed.begin(), pressed.end());\n   \
    \ pressed.erase(unique(pressed.begin(), pressed.end()), pressed.end());\n    for\
    \ (auto& ai : a) {\n        ai = lower_bound(pressed.begin(), pressed.end(), ai)\
    \ - pressed.begin();\n    }\n    Mo mo(q);\n    vector<int> x(q);\n    for (int\
    \ i = 0; i < q; i++) {\n        int l, r;\n        scanf(\"%d%d%d\\n\", &l, &r,\
    \ &x[i]);\n        mo.add(l, r);\n    }\n\n    vector<int> cnt(pressed.size()\
    \ + 1);\n    vector<int> ans(q);\n    auto add = [&](int v) -> void {\n      \
    \  cnt[a[v]]++;\n    };\n    auto del = [&](int v) -> void {\n        cnt[a[v]]--;\n\
    \    };\n    auto out = [&](int v) -> void {\n        auto it = lower_bound(all(pressed),\
    \ x[v]);\n        if (it == pressed.end() || (*it) != x[v]) {\n            ans[v]\
    \ = 0;\n        } else {\n            int xi = it - pressed.begin();\n       \
    \     ans[v] = cnt[xi];\n        }\n    };\n    mo.build(add, del, out);\n   \
    \ for (auto& aa : ans) {\n        printf(\"%d\\n\", aa);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n#include\"template.hpp\"\n#include\"misc/mo.hpp\"\nusing namespace std;\nint\
    \ main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n\n    vector<int> a(n);\n\
    \    for (auto& aa : a) {\n        scanf(\"%d\", &aa);\n    }\n    auto pressed\
    \ = a;\n    sort(pressed.begin(), pressed.end());\n    pressed.erase(unique(pressed.begin(),\
    \ pressed.end()), pressed.end());\n    for (auto& ai : a) {\n        ai = lower_bound(pressed.begin(),\
    \ pressed.end(), ai) - pressed.begin();\n    }\n    Mo mo(q);\n    vector<int>\
    \ x(q);\n    for (int i = 0; i < q; i++) {\n        int l, r;\n        scanf(\"\
    %d%d%d\\n\", &l, &r, &x[i]);\n        mo.add(l, r);\n    }\n\n    vector<int>\
    \ cnt(pressed.size() + 1);\n    vector<int> ans(q);\n    auto add = [&](int v)\
    \ -> void {\n        cnt[a[v]]++;\n    };\n    auto del = [&](int v) -> void {\n\
    \        cnt[a[v]]--;\n    };\n    auto out = [&](int v) -> void {\n        auto\
    \ it = lower_bound(all(pressed), x[v]);\n        if (it == pressed.end() || (*it)\
    \ != x[v]) {\n            ans[v] = 0;\n        } else {\n            int xi =\
    \ it - pressed.begin();\n            ans[v] = cnt[xi];\n        }\n    };\n  \
    \  mo.build(add, del, out);\n    for (auto& aa : ans) {\n        printf(\"%d\\\
    n\", aa);\n    }\n}"
  dependsOn:
  - template.hpp
  - misc/mo.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 14:59:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp.html
title: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
---
