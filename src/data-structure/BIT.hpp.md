---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
    title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
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
    document_title: Binary Index Tree
    links: []
  bundledCode: "#line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\nnamespace\
    \ kyopro {\n\ntemplate <typename T> class BIT {\n    std::vector<T> bit;\n   \
    \ int n;\n\npublic:\n    BIT() : BIT(0) {}\n    BIT(int n) : n(n), bit(n + 1,\
    \ T()) {}\n    void add(int p, T w) {\n        p++;\n        for (int x = p; x\
    \ <= n; x += x & -x) {\n            bit[x] += w;\n        }\n    }\n\n    T sum(int\
    \ p) const {\n        T s = 0;\n\n        for (int x = p; x > 0; x -= x & -x)\
    \ {\n            s += bit[x];\n        }\n        return s;\n    }\n\n    T sum(int\
    \ l, int r) const { return sum(r) - sum(l); }\n\n    int lower_bound(T w) const\
    \ {\n        if (w <= 0) return 0;\n\n        int x = 0;\n        int k = 1;\n\
    \        while (k < n) k <<= 1;\n        for (; k > 0; k >>= 1) {\n          \
    \  if (x + k <= n && bit[x + k] < w) {\n                w -= bit[x + k];\n   \
    \             x += k;\n            }\n        }\n\n        return x + 1;\n   \
    \ }\n\n    T operator[](int i) { return sum(i + 1) - sum(i); }\n    void update(int\
    \ i, T v) { add(i, -sum(i + 1) + sum(i) + v); }\n};\n};  // namespace kyopro\n\
    \n/**\n * @brief Binary Index Tree\n */\n"
  code: "#pragma once\n#include <vector>\nnamespace kyopro {\n\ntemplate <typename\
    \ T> class BIT {\n    std::vector<T> bit;\n    int n;\n\npublic:\n    BIT() :\
    \ BIT(0) {}\n    BIT(int n) : n(n), bit(n + 1, T()) {}\n    void add(int p, T\
    \ w) {\n        p++;\n        for (int x = p; x <= n; x += x & -x) {\n       \
    \     bit[x] += w;\n        }\n    }\n\n    T sum(int p) const {\n        T s\
    \ = 0;\n\n        for (int x = p; x > 0; x -= x & -x) {\n            s += bit[x];\n\
    \        }\n        return s;\n    }\n\n    T sum(int l, int r) const { return\
    \ sum(r) - sum(l); }\n\n    int lower_bound(T w) const {\n        if (w <= 0)\
    \ return 0;\n\n        int x = 0;\n        int k = 1;\n        while (k < n) k\
    \ <<= 1;\n        for (; k > 0; k >>= 1) {\n            if (x + k <= n && bit[x\
    \ + k] < w) {\n                w -= bit[x + k];\n                x += k;\n   \
    \         }\n        }\n\n        return x + 1;\n    }\n\n    T operator[](int\
    \ i) { return sum(i + 1) - sum(i); }\n    void update(int i, T v) { add(i, -sum(i\
    \ + 1) + sum(i) + v); }\n};\n};  // namespace kyopro\n\n/**\n * @brief Binary\
    \ Index Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/BIT.hpp
  requiredBy: []
  timestamp: '2023-10-22 17:06:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
documentation_of: src/data-structure/BIT.hpp
layout: document
redirect_from:
- /library/src/data-structure/BIT.hpp
- /library/src/data-structure/BIT.hpp.html
title: Binary Index Tree
---
