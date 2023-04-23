---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/euler_tour.hpp
    title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/5_C.test.cpp
    title: test/AOJ/GRL/5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
    title: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
    title: test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/sparse_table.md
    document_title: Sparse Table(RangeMin)
    links: []
  bundledCode: "#line 2 \"src/data-structure/sparse_table.hpp\"\n#include <numeric>\n\
    #include <vector>\nnamespace kyopro {\n/// @brief Sparse Table(RangeMin)\ntemplate\
    \ <class T>\nclass sparse_table {\n    std::vector<T> vec;\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<int> look_up;\n\npublic:\n    sparse_table(int n) :\
    \ vec(n) {}\n    sparse_table(const std::vector<T>& vec) : vec(vec) { build();\
    \ }\n    inline void set(int p, const T& v) { vec[p] = v; }\n    void build()\
    \ {\n        int sz = vec.size();\n        int log = 0;\n        while ((1 <<\
    \ log) <= sz) {\n            log++;\n        }\n        table.assign(log, std::vector<T>(1\
    \ << log));\n        for (int i = 0; i < sz; i++) {\n            table[0][i] =\
    \ vec[i];\n        }\n        for (int i = 1; i < log; i++) {\n            for\
    \ (int j = 0; j + (1 << i) <= (1 << log); j++) {\n                table[i][j]\
    \ =\n                    std::min(table[i - 1][j], table[i - 1][j + (1 << (i -\
    \ 1))]);\n            }\n        }\n        look_up.resize(sz + 1);\n        for\
    \ (int i = 2; i < (int)look_up.size(); i++) {\n            look_up[i] = look_up[i\
    \ >> 1] + 1;\n        }\n    }\n\n    inline T prod(int l, int r) {\n        int\
    \ b = look_up[r - l];\n        return std::min(table[b][l], table[b][r - (1 <<\
    \ b)]);\n    }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/sparse_table.md\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\nnamespace kyopro {\n\
    /// @brief Sparse Table(RangeMin)\ntemplate <class T>\nclass sparse_table {\n\
    \    std::vector<T> vec;\n    std::vector<std::vector<T>> table;\n    std::vector<int>\
    \ look_up;\n\npublic:\n    sparse_table(int n) : vec(n) {}\n    sparse_table(const\
    \ std::vector<T>& vec) : vec(vec) { build(); }\n    inline void set(int p, const\
    \ T& v) { vec[p] = v; }\n    void build() {\n        int sz = vec.size();\n  \
    \      int log = 0;\n        while ((1 << log) <= sz) {\n            log++;\n\
    \        }\n        table.assign(log, std::vector<T>(1 << log));\n        for\
    \ (int i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n        }\n \
    \       for (int i = 1; i < log; i++) {\n            for (int j = 0; j + (1 <<\
    \ i) <= (1 << log); j++) {\n                table[i][j] =\n                  \
    \  std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n\
    \        }\n        look_up.resize(sz + 1);\n        for (int i = 2; i < (int)look_up.size();\
    \ i++) {\n            look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n\
    \    inline T prod(int l, int r) {\n        int b = look_up[r - l];\n        return\
    \ std::min(table[b][l], table[b][r - (1 << b)]);\n    }\n};\n};  // namespace\
    \ kyopro\n\n/// @docs docs/data-structure/sparse_table.md"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/sparse_table.hpp
  requiredBy:
  - src/graph/euler_tour.hpp
  timestamp: '2023-04-23 12:26:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  - test/AOJ/GRL/5_C.test.cpp
documentation_of: src/data-structure/sparse_table.hpp
layout: document
redirect_from:
- /library/src/data-structure/sparse_table.hpp
- /library/src/data-structure/sparse_table.hpp.html
title: Sparse Table(RangeMin)
---
