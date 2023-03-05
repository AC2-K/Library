---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/lca.hpp
    title: "Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':warning:'
    path: test/AOJ/GRL/5/C.cpp
    title: test/AOJ/GRL/5/C.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo judge/data structure/Static RMQ.test.cpp
    title: test/yosupo judge/data structure/Static RMQ.test.cpp
  - icon: ':x:'
    path: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
    title: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: sparse table
    links: []
  bundledCode: "#line 1 \"data-structure/sparse_table.hpp\"\ntemplate<class T>\nclass\
    \ sparse_table {\n    vector<vector<T>> table;\n    vector<int> look_up;\npublic:\n\
    \    sparse_table(const vector<T>& vec = {}) {\n        int sz = vec.size();\n\
    \        int log = 0;\n        while ((1 << log) <= sz) {\n            log++;\n\
    \        }\n        table.assign(log, vector<T>(1 << log));\n        for (int\
    \ i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n        }\n      \
    \  for (int i = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <=\
    \ (1 << log); j++) {\n                table[i][j] = min(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\n            }\n        }\n        look_up.resize(sz\
    \ + 1);\n        for (int i = 2; i < look_up.size(); i++) {\n            look_up[i]\
    \ = look_up[i >> 1] + 1;\n        }\n    }\n\n    T prod(int l, int r) {\n   \
    \     int b = look_up[r - l];\n        return min(table[b][l], table[b][r - (1\
    \ << b)]);\n    }\n};\n///@brief sparse table\n"
  code: "template<class T>\nclass sparse_table {\n    vector<vector<T>> table;\n \
    \   vector<int> look_up;\npublic:\n    sparse_table(const vector<T>& vec = {})\
    \ {\n        int sz = vec.size();\n        int log = 0;\n        while ((1 <<\
    \ log) <= sz) {\n            log++;\n        }\n        table.assign(log, vector<T>(1\
    \ << log));\n        for (int i = 0; i < sz; i++) {\n            table[0][i] =\
    \ vec[i];\n        }\n        for (int i = 1; i < log; i++) {\n            for\
    \ (int j = 0; j + (1 << i) <= (1 << log); j++) {\n                table[i][j]\
    \ = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n \
    \       }\n        look_up.resize(sz + 1);\n        for (int i = 2; i < look_up.size();\
    \ i++) {\n            look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n\
    \    T prod(int l, int r) {\n        int b = look_up[r - l];\n        return min(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n///@brief sparse table"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.hpp
  requiredBy:
  - graph/lca.hpp
  - test/AOJ/GRL/5/C.cpp
  timestamp: '2023-02-23 13:41:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  - test/yosupo judge/data structure/Static RMQ.test.cpp
documentation_of: data-structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse_table.hpp
- /library/data-structure/sparse_table.hpp.html
title: sparse table
---
