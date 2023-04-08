---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
    title: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
    title: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/other/mo.md
    document_title: mo's algorithm
    links: []
  bundledCode: "#line 2 \"misc/mo.hpp\"\n#include <algorithm>\n#include <numeric>\n\
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
    \ kyopro\n\n/// @docs docs/other/mo.md\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    namespace kyopro {\n/// @brief mo's algorithm\nclass Mo {\n    int n;\n    std::vector<std::pair<int,\
    \ int>> lr;\n    const int logn;\n    const long long maxn;\n    std::vector<int>\
    \ ord;\n\n  public:\n    explicit Mo(int n) : n(n), logn(20), maxn(1ll << logn)\
    \ { lr.reserve(n); }\n    inline void add(int l, int r) { lr.emplace_back(l, r);\
    \ }\n    long long hilbertorder(int x, int y) {\n        long long d = 0;\n  \
    \      for (int s = 1 << (logn - 1); s; s >>= 1) {\n            bool rx = x &\
    \ s, ry = y & s;\n            d = d << 2 | rx * 3 ^ static_cast<int>(ry);\n  \
    \          if (!ry) {\n                if (rx) {\n                    x = maxn\
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
    \ O& out) {\n        build(add, add, erase, erase, out);\n    }\n};\n};  // namespace\
    \ kyopro\n\n/// @docs docs/other/mo.md"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '2023-04-08 03:34:55+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
  - test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
documentation_of: misc/mo.hpp
layout: document
redirect_from:
- /library/misc/mo.hpp
- /library/misc/mo.hpp.html
title: mo's algorithm
---
