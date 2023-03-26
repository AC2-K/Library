---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/other/mo.md
    document_title: mo's algorithm
    links: []
  bundledCode: "#line 1 \"src/other/mo.hpp\"\nclass Mo {\n    int n;\n    vector<pair<int,\
    \ int>> lr;\n    const int logn;\n    const long long maxn;\n    vector<int> ord;\n\
    public:\n    explicit Mo(int n) : n(n), logn(20), maxn(1ll << logn) { lr.reserve(n);\
    \ }\n    void add(int l, int r) { lr.emplace_back(l, r); }\n    long long hilbertorder(int\
    \ x, int y){\n        long long d = 0;\n        for (int s = 1 << (logn - 1);\
    \ s; s >>= 1) {\n            bool rx = x & s, ry = y & s;\n            d = d <<\
    \ 2 | rx * 3 ^ static_cast<int>(ry);\n            if (!ry){\n                if\
    \ (rx)\n                {\n                    x = maxn - x;\n               \
    \     y = maxn - y;\n                }\n                swap(x, y);\n        \
    \    }\n        }\n        return d;\n    }\n\nprivate:\n    inline void line_up()\
    \ {\n        int q = lr.size();\n        ord.resize(q);\n        iota(begin(ord),\
    \ end(ord), 0);\n        vector<long long> tmp(q);\n        for (int i = 0; i\
    \ < q; i++) {\n            tmp[i] = hilbertorder(lr[i].first, lr[i].second);\n\
    \        }\n        sort(begin(ord), end(ord), [&](int a, int b) {\n         \
    \   return tmp[a] < tmp[b];\n        });\n    }\npublic:\n    template< typename\
    \ AL, typename AR, typename EL, typename ER, typename O >\n    void build(const\
    \ AL& add_left, const AR& add_right, const EL& erase_left, const ER& erase_right,\
    \ const O& out) {\n        line_up();\n        int l = 0, r = 0;\n        for\
    \ (const auto& idx : ord) {\n            while (l > lr[idx].first) add_left(--l);\n\
    \            while (r < lr[idx].second) add_right(r++);\n            while (l\
    \ < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            out(idx);\n        }\n    }\n\n    template< typename A, typename\
    \ E, typename O >\n    void build(const A& add, const E& erase, const O& out)\
    \ {\n        build(add, add, erase, erase, out);\n    }\n};\n/// @brief mo's algorithm\n\
    /// @docs docs/other/mo.md\n"
  code: "class Mo {\n    int n;\n    vector<pair<int, int>> lr;\n    const int logn;\n\
    \    const long long maxn;\n    vector<int> ord;\npublic:\n    explicit Mo(int\
    \ n) : n(n), logn(20), maxn(1ll << logn) { lr.reserve(n); }\n    void add(int\
    \ l, int r) { lr.emplace_back(l, r); }\n    long long hilbertorder(int x, int\
    \ y){\n        long long d = 0;\n        for (int s = 1 << (logn - 1); s; s >>=\
    \ 1) {\n            bool rx = x & s, ry = y & s;\n            d = d << 2 | rx\
    \ * 3 ^ static_cast<int>(ry);\n            if (!ry){\n                if (rx)\n\
    \                {\n                    x = maxn - x;\n                    y =\
    \ maxn - y;\n                }\n                swap(x, y);\n            }\n \
    \       }\n        return d;\n    }\n\nprivate:\n    inline void line_up() {\n\
    \        int q = lr.size();\n        ord.resize(q);\n        iota(begin(ord),\
    \ end(ord), 0);\n        vector<long long> tmp(q);\n        for (int i = 0; i\
    \ < q; i++) {\n            tmp[i] = hilbertorder(lr[i].first, lr[i].second);\n\
    \        }\n        sort(begin(ord), end(ord), [&](int a, int b) {\n         \
    \   return tmp[a] < tmp[b];\n        });\n    }\npublic:\n    template< typename\
    \ AL, typename AR, typename EL, typename ER, typename O >\n    void build(const\
    \ AL& add_left, const AR& add_right, const EL& erase_left, const ER& erase_right,\
    \ const O& out) {\n        line_up();\n        int l = 0, r = 0;\n        for\
    \ (const auto& idx : ord) {\n            while (l > lr[idx].first) add_left(--l);\n\
    \            while (r < lr[idx].second) add_right(r++);\n            while (l\
    \ < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            out(idx);\n        }\n    }\n\n    template< typename A, typename\
    \ E, typename O >\n    void build(const A& add, const E& erase, const O& out)\
    \ {\n        build(add, add, erase, erase, out);\n    }\n};\n/// @brief mo's algorithm\n\
    /// @docs docs/other/mo.md"
  dependsOn: []
  isVerificationFile: false
  path: src/other/mo.hpp
  requiredBy: []
  timestamp: '2023-03-27 01:42:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/other/mo.hpp
layout: document
redirect_from:
- /library/src/other/mo.hpp
- /library/src/other/mo.hpp.html
title: mo's algorithm
---
