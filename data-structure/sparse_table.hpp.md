---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/euler_tour.hpp
    title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/5/C.test.cpp
    title: test/AOJ/GRL/5/C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
    title: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
    title: test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/data-structure/sparse_table.md
    document_title: Sparse Table
    links: []
  bundledCode: "#line 1 \"data-structure/sparse_table.hpp\"\n/// @brief Sparse Table\n\
    /// @tparam T \u8981\u7D20\u306E\u578B\n/// @docs docs/data-structure/sparse_table.md\n\
    \ntemplate<class T>\nclass sparse_table {\n    vector<T> vec;\n    vector<vector<T>>\
    \ table;\n    vector<int> look_up;\npublic:\n    sparse_table(int n) : vec(n)\
    \ {}\n    sparse_table(const vector<T>& vec) : vec(vec) {}\n    void set(int p,\
    \ const T& v) { vec[p] = v; }\n    void build() {\n        int sz = vec.size();\n\
    \        int log = 0;\n        while ((1 << log) <= sz) {\n            log++;\n\
    \        }\n        table.assign(log, vector<T>(1 << log));\n        for (int\
    \ i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n        }\n      \
    \  for (int i = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <=\
    \ (1 << log); j++) {\n                table[i][j] =\n                    min(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    \
    \    look_up.resize(sz + 1);\n        for (int i = 2; i < look_up.size(); i++)\
    \ {\n            look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n    T\
    \ prod(int l, int r) {\n        int b = look_up[r - l];\n        return min(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n"
  code: "/// @brief Sparse Table\n/// @tparam T \u8981\u7D20\u306E\u578B\n/// @docs\
    \ docs/data-structure/sparse_table.md\n\ntemplate<class T>\nclass sparse_table\
    \ {\n    vector<T> vec;\n    vector<vector<T>> table;\n    vector<int> look_up;\n\
    public:\n    sparse_table(int n) : vec(n) {}\n    sparse_table(const vector<T>&\
    \ vec) : vec(vec) {}\n    void set(int p, const T& v) { vec[p] = v; }\n    void\
    \ build() {\n        int sz = vec.size();\n        int log = 0;\n        while\
    \ ((1 << log) <= sz) {\n            log++;\n        }\n        table.assign(log,\
    \ vector<T>(1 << log));\n        for (int i = 0; i < sz; i++) {\n            table[0][i]\
    \ = vec[i];\n        }\n        for (int i = 1; i < log; i++) {\n            for\
    \ (int j = 0; j + (1 << i) <= (1 << log); j++) {\n                table[i][j]\
    \ =\n                    min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n\
    \            }\n        }\n        look_up.resize(sz + 1);\n        for (int i\
    \ = 2; i < look_up.size(); i++) {\n            look_up[i] = look_up[i >> 1] +\
    \ 1;\n        }\n    }\n\n    T prod(int l, int r) {\n        int b = look_up[r\
    \ - l];\n        return min(table[b][l], table[b][r - (1 << b)]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.hpp
  requiredBy:
  - graph/euler_tour.hpp
  timestamp: '2023-03-25 14:30:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
  - test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  - test/AOJ/GRL/5/C.test.cpp
documentation_of: data-structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse_table.hpp
- /library/data-structure/sparse_table.hpp.html
title: Sparse Table
---
