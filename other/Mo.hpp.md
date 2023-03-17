---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: mo's algorithm
    links: []
  bundledCode: "#line 1 \"other/Mo.hpp\"\nclass Mo {\n    int n;\n    vector<pair<int,\
    \ int>> lr;\n    vector<int> ord;\npublic:\n  explicit Mo(int n) : n(n) { lr.reserve(n);\
    \ }\n  void add(int l, int r) { lr.emplace_back(l, r); }\n\nprivate:\n    inline\
    \ void line_up() {\n        int q = lr.size();\n        int bs = n / min<int>(n,\
    \ (int)sqrt(q));\n        ord.resize(q);\n        iota(begin(ord), end(ord), 0);\n\
    \        sort(begin(ord), end(ord), [&](int a, int b) {\n            int ablock\
    \ = lr[a].first / bs, bblock = lr[b].first / bs;\n            if (ablock != bblock)\
    \ return ablock < bblock;\n            return (ablock & 1) ? lr[a].second > lr[b].second\
    \ : lr[a].second < lr[b].second;\n            });\n    }\npublic:\n    template<\
    \ typename AL, typename AR, typename EL, typename ER, typename O >\n    void build(const\
    \ AL& add_left, const AR& add_right, const EL& erase_left, const ER& erase_right,\
    \ const O& out) {\n        line_up();\n        int l = 0, r = 0;\n        for\
    \ (const auto& idx : ord) {\n            while (l > lr[idx].first) add_left(--l);\n\
    \            while (r < lr[idx].second) add_right(r++);\n            while (l\
    \ < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            out(idx);\n        }\n    }\n\n    template< typename A, typename\
    \ E, typename O >\n    void build(const A& add, const E& erase, const O& out)\
    \ {\n        build(add, add, erase, erase, out);\n    }\n};\n/// @brief mo's algorithm\n"
  code: "class Mo {\n    int n;\n    vector<pair<int, int>> lr;\n    vector<int> ord;\n\
    public:\n  explicit Mo(int n) : n(n) { lr.reserve(n); }\n  void add(int l, int\
    \ r) { lr.emplace_back(l, r); }\n\nprivate:\n    inline void line_up() {\n   \
    \     int q = lr.size();\n        int bs = n / min<int>(n, (int)sqrt(q));\n  \
    \      ord.resize(q);\n        iota(begin(ord), end(ord), 0);\n        sort(begin(ord),\
    \ end(ord), [&](int a, int b) {\n            int ablock = lr[a].first / bs, bblock\
    \ = lr[b].first / bs;\n            if (ablock != bblock) return ablock < bblock;\n\
    \            return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second\
    \ < lr[b].second;\n            });\n    }\npublic:\n    template< typename AL,\
    \ typename AR, typename EL, typename ER, typename O >\n    void build(const AL&\
    \ add_left, const AR& add_right, const EL& erase_left, const ER& erase_right,\
    \ const O& out) {\n        line_up();\n        int l = 0, r = 0;\n        for\
    \ (const auto& idx : ord) {\n            while (l > lr[idx].first) add_left(--l);\n\
    \            while (r < lr[idx].second) add_right(r++);\n            while (l\
    \ < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            out(idx);\n        }\n    }\n\n    template< typename A, typename\
    \ E, typename O >\n    void build(const A& add, const E& erase, const O& out)\
    \ {\n        build(add, add, erase, erase, out);\n    }\n};\n/// @brief mo's algorithm"
  dependsOn: []
  isVerificationFile: false
  path: other/Mo.hpp
  requiredBy: []
  timestamp: '2023-03-18 02:09:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/Mo.hpp
layout: document
redirect_from:
- /library/other/Mo.hpp
- /library/other/Mo.hpp.html
title: mo's algorithm
---
