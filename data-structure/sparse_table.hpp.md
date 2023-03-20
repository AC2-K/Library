---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/euler_tour.hpp
    title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/5/C.test.cpp
    title: test/AOJ/GRL/5/C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Static RMQ.test.cpp
    title: test/yosupo judge/data structure/Static RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
    title: test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
    title: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
    title: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: sparse table
    links: []
  bundledCode: "#line 1 \"data-structure/sparse_table.hpp\"\ntemplate<class T>\nclass\
    \ sparse_table {\n    vector<T> vec;\n    vector<vector<T>> table;\n    vector<int>\
    \ look_up;\npublic:\n    sparse_table(int n) :vec(n) {}\n    sparse_table(const\
    \ vector<T>& vec = {}) :vec(vec) {}\n    void set(int p, const T& v) {\n     \
    \   vec[p] = v;\n    }\n    void build() {\n        int sz = vec.size();\n   \
    \     int log = 0;\n        while ((1 << log) <= sz) {\n            log++;\n \
    \       }\n        table.assign(log, vector<T>(1 << log));\n        for (int i\
    \ = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n        }\n        for\
    \ (int i = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <= (1\
    \ << log); j++) {\n                table[i][j] = min(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\n            }\n        }\n        look_up.resize(sz\
    \ + 1);\n        for (int i = 2; i < look_up.size(); i++) {\n            look_up[i]\
    \ = look_up[i >> 1] + 1;\n        }\n    }\n\n    T prod(int l, int r) {\n   \
    \     int b = look_up[r - l];\n        return min(table[b][l], table[b][r - (1\
    \ << b)]);\n    }\n};\n///@brief sparse table\n"
  code: "template<class T>\nclass sparse_table {\n    vector<T> vec;\n    vector<vector<T>>\
    \ table;\n    vector<int> look_up;\npublic:\n    sparse_table(int n) :vec(n) {}\n\
    \    sparse_table(const vector<T>& vec = {}) :vec(vec) {}\n    void set(int p,\
    \ const T& v) {\n        vec[p] = v;\n    }\n    void build() {\n        int sz\
    \ = vec.size();\n        int log = 0;\n        while ((1 << log) <= sz) {\n  \
    \          log++;\n        }\n        table.assign(log, vector<T>(1 << log));\n\
    \        for (int i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n \
    \       }\n        for (int i = 1; i < log; i++) {\n            for (int j = 0;\
    \ j + (1 << i) <= (1 << log); j++) {\n                table[i][j] = min(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    \
    \    look_up.resize(sz + 1);\n        for (int i = 2; i < look_up.size(); i++)\
    \ {\n            look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n    T\
    \ prod(int l, int r) {\n        int b = look_up[r - l];\n        return min(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n///@brief sparse table"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.hpp
  requiredBy:
  - graph/euler_tour.hpp
  timestamp: '2023-03-20 07:27:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
  - test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
  - test/yosupo judge/data structure/Static RMQ.test.cpp
  - test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  - test/AOJ/GRL/5/C.test.cpp
documentation_of: data-structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse_table.hpp
- /library/data-structure/sparse_table.hpp.html
title: sparse table
---
