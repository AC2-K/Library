---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure-2d/PointAddRectangleSum.hpp
    title: src/data-structure-2d/PointAddRectangleSum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
    title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_BIT.test.cpp
    title: test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
    title: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/BIT.md
    document_title: Binary Index Tree
    links: []
  bundledCode: "#line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\nnamespace\
    \ kyopro {\n/// @brief Binary Index Tree\ntemplate <typename T, typename SumT\
    \ = T>\nclass BIT {\n    std::vector<SumT> bit;\n    int n;\n\npublic:\n    explicit\
    \ BIT() {}\n    explicit BIT(int n) : n(n), bit(n + 1, T()) {}\n    void add(int\
    \ p,T w) {\n        p++;\n        for (int x = p; x <= n; x += x & -x) {\n   \
    \         bit[x] += w;\n        }\n    }\n\n    SumT sum(int p) const {\n    \
    \    T s = 0;\n\n        for (int x = p; x > 0; x -= x & -x) {\n            s\
    \ += bit[x];\n        }\n        return s;\n    }\n\n    SumT sum(int l, int r)\
    \ const { return sum(r) - sum(l); }\n\n    int lower_bound(SumT w) const {\n \
    \       if (w <= 0) return 0;\n\n        int x = 0;\n        int k = 1;\n    \
    \    while (k < n) k <<= 1;\n        for (; k > 0; k >>= 1) {\n            if\
    \ (x + k <= n && bit[x + k] < w) {\n                w -= bit[x + k];\n       \
    \         x += k;\n            }\n        }\n\n        return x + 1;\n    }\n\
    };\n};  // namespace kyopro\n\n/// @docs docs/data-structure/BIT.md\n"
  code: "#pragma once\n#include <vector>\nnamespace kyopro {\n/// @brief Binary Index\
    \ Tree\ntemplate <typename T, typename SumT = T>\nclass BIT {\n    std::vector<SumT>\
    \ bit;\n    int n;\n\npublic:\n    explicit BIT() {}\n    explicit BIT(int n)\
    \ : n(n), bit(n + 1, T()) {}\n    void add(int p,T w) {\n        p++;\n      \
    \  for (int x = p; x <= n; x += x & -x) {\n            bit[x] += w;\n        }\n\
    \    }\n\n    SumT sum(int p) const {\n        T s = 0;\n\n        for (int x\
    \ = p; x > 0; x -= x & -x) {\n            s += bit[x];\n        }\n        return\
    \ s;\n    }\n\n    SumT sum(int l, int r) const { return sum(r) - sum(l); }\n\n\
    \    int lower_bound(SumT w) const {\n        if (w <= 0) return 0;\n\n      \
    \  int x = 0;\n        int k = 1;\n        while (k < n) k <<= 1;\n        for\
    \ (; k > 0; k >>= 1) {\n            if (x + k <= n && bit[x + k] < w) {\n    \
    \            w -= bit[x + k];\n                x += k;\n            }\n      \
    \  }\n\n        return x + 1;\n    }\n};\n};  // namespace kyopro\n\n/// @docs\
    \ docs/data-structure/BIT.md"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/BIT.hpp
  requiredBy:
  - src/data-structure-2d/PointAddRectangleSum.hpp
  timestamp: '2023-05-01 12:49:55+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_BIT.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
  - test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
documentation_of: src/data-structure/BIT.hpp
layout: document
redirect_from:
- /library/src/data-structure/BIT.hpp
- /library/src/data-structure/BIT.hpp.html
title: Binary Index Tree
---
