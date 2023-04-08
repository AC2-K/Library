---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/mo.hpp
    title: mo's algorithm
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
    #include<iostream>\n#line 2 \"misc/mo.hpp\"\n#include <algorithm>\n#include <numeric>\n\
    #include <vector>\nnamespace kyopro {\n/// @brief mo's algorithm\nclass Mo {\n\
    \    int n;\n    std::vector<std::pair<int, int>> lr;\n    const int logn;\n \
    \   const long long maxn;\n    std::vector<int> ord;\n\n  public:\n    explicit\
    \ Mo(int n) : n(n), logn(20), maxn(1ll << logn) { lr.reserve(n); }\n    inline\
    \ void add(int l, int r) { lr.emplace_back(l, r); }\n    long long hilbertorder(int\
    \ x, int y) {\n        long long d = 0;\n        for (int s = 1 << (logn - 1);\
    \ s; s >>= 1) {\n            bool rx = x & s, ry = y & s;\n            d = d <<\
    \ 2 | rx * 3 ^ static_cast<int>(ry);\n            if (!ry) {\n               \
    \ if (rx) {\n                    x = maxn - x;\n                    y = maxn -\
    \ y;\n                }\n                std::swap(x, y);\n            }\n   \
    \     }\n        return d;\n    }\n\n  private:\n    inline void line_up() {\n\
    \        int q = lr.size();\n        ord.resize(q);\n        std::iota(std::begin(ord),\
    \ std::end(ord), 0);\n        std::vector<long long> tmp(q);\n        for (int\
    \ i = 0; i < q; i++) {\n            tmp[i] = hilbertorder(lr[i].first, lr[i].second);\n\
    \        }\n        std::sort(std::begin(ord), std::end(ord),\n              \
    \    [&](int a, int b) { return tmp[a] < tmp[b]; });\n    }\n\n  public:\n   \
    \ template <typename AL, typename AR, typename EL, typename ER, typename O>\n\
    \    void build(const AL& add_left,\n               const AR& add_right,\n   \
    \            const EL& erase_left,\n               const ER& erase_right,\n  \
    \             const O& out) {\n        line_up();\n        int l = 0, r = 0;\n\
    \        for (const auto& idx : ord) {\n            while (l > lr[idx].first)\
    \ add_left(--l);\n            while (r < lr[idx].second) add_right(r++);\n   \
    \         while (l < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second)\
    \ erase_right(--r);\n            out(idx);\n        }\n    }\n\n    template <typename\
    \ A, typename E, typename O>\n    void build(const A& add, const E& erase, const\
    \ O& out) {\n        build(add, add, erase, erase, out);\n    }\n};\n};  // namespace\
    \ kyopro\n\n/// @docs docs/other/mo.md\n#line 4 \"test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp\"\
    \nusing namespace std;\nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n\
    \n    std::vector<int> a(n);\n    for (auto& aa : a) {\n        scanf(\"%d\",\
    \ &aa);\n    }\n    auto pressed = a;\n    std::sort(pressed.begin(), pressed.end());\n\
    \    pressed.erase(unique(pressed.begin(), pressed.end()), pressed.end());\n \
    \   for (auto& ai : a) {\n        ai = lower_bound(pressed.begin(), pressed.end(),\
    \ ai) - pressed.begin();\n    }\n    kyopro::Mo mo(q);\n    std::vector<int> x(q);\n\
    \    for (int i = 0; i < q; i++) {\n        int l, r;\n        scanf(\"%d%d%d\\\
    n\", &l, &r, &x[i]);\n        mo.add(l, r);\n    }\n\n    std::vector<int> cnt(pressed.size()\
    \ + 1);\n    std::vector<int> ans(q);\n    auto add = [&](int v) -> void {\n \
    \       cnt[a[v]]++;\n    };\n    auto del = [&](int v) -> void {\n        cnt[a[v]]--;\n\
    \    };\n    auto out = [&](int v) -> void {\n        auto it = std::lower_bound(pressed.begin(),pressed.end(),\
    \ x[v]);\n        if (it == pressed.end() || (*it) != x[v]) {\n            ans[v]\
    \ = 0;\n        } else {\n            int xi = it - pressed.begin();\n       \
    \     ans[v] = cnt[xi];\n        }\n    };\n    mo.build(add, del, out);\n   \
    \ for (auto& aa : ans) {\n        printf(\"%d\\n\", aa);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n#include<iostream>\n#include\"../../../misc/mo.hpp\"\nusing namespace std;\n\
    int main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n\n    std::vector<int>\
    \ a(n);\n    for (auto& aa : a) {\n        scanf(\"%d\", &aa);\n    }\n    auto\
    \ pressed = a;\n    std::sort(pressed.begin(), pressed.end());\n    pressed.erase(unique(pressed.begin(),\
    \ pressed.end()), pressed.end());\n    for (auto& ai : a) {\n        ai = lower_bound(pressed.begin(),\
    \ pressed.end(), ai) - pressed.begin();\n    }\n    kyopro::Mo mo(q);\n    std::vector<int>\
    \ x(q);\n    for (int i = 0; i < q; i++) {\n        int l, r;\n        scanf(\"\
    %d%d%d\\n\", &l, &r, &x[i]);\n        mo.add(l, r);\n    }\n\n    std::vector<int>\
    \ cnt(pressed.size() + 1);\n    std::vector<int> ans(q);\n    auto add = [&](int\
    \ v) -> void {\n        cnt[a[v]]++;\n    };\n    auto del = [&](int v) -> void\
    \ {\n        cnt[a[v]]--;\n    };\n    auto out = [&](int v) -> void {\n     \
    \   auto it = std::lower_bound(pressed.begin(),pressed.end(), x[v]);\n       \
    \ if (it == pressed.end() || (*it) != x[v]) {\n            ans[v] = 0;\n     \
    \   } else {\n            int xi = it - pressed.begin();\n            ans[v] =\
    \ cnt[xi];\n        }\n    };\n    mo.build(add, del, out);\n    for (auto& aa\
    \ : ans) {\n        printf(\"%d\\n\", aa);\n    }\n}"
  dependsOn:
  - misc/mo.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 03:34:55+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp.html
title: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
---
