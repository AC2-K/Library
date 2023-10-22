---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/1_A.test.cpp
    title: test/AOJ/DSL/1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Disjoint Set Union
    links: []
  bundledCode: "#line 2 \"src/data-structure/dsu.hpp\"\n#include <utility>\n#include\
    \ <vector>\nnamespace kyopro {\n\nclass dsu {\nprivate:\n    std::vector<int>\
    \ find;\n\npublic:\n    dsu() : dsu(0) {}\n    dsu(int n) : find(n, -1) {}\n\n\
    \    int root(int x) {\n        if (find[x] < 0) {\n            return x;\n  \
    \      } else {\n            return find[x] = root(find[x]);\n        }\n    }\n\
    \    bool same(int x, int y) { return root(x) == root(y); }\n    int merge(int\
    \ x, int y) {\n        x = root(x), y = root(y);\n        if (x == y) return x;\n\
    \        if (find[x] > find[y]) std::swap(x, y);\n        find[x] += find[y];\n\
    \        find[y] = x;\n        return x;\n    }\n    int size(int x) { return\
    \ -find[root(x)]; }\n};\n\n};  // namespace kyopro\n\n/**\n * @brief Disjoint\
    \ Set Union\n */\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\nnamespace kyopro {\n\
    \nclass dsu {\nprivate:\n    std::vector<int> find;\n\npublic:\n    dsu() : dsu(0)\
    \ {}\n    dsu(int n) : find(n, -1) {}\n\n    int root(int x) {\n        if (find[x]\
    \ < 0) {\n            return x;\n        } else {\n            return find[x]\
    \ = root(find[x]);\n        }\n    }\n    bool same(int x, int y) { return root(x)\
    \ == root(y); }\n    int merge(int x, int y) {\n        x = root(x), y = root(y);\n\
    \        if (x == y) return x;\n        if (find[x] > find[y]) std::swap(x, y);\n\
    \        find[x] += find[y];\n        find[y] = x;\n        return x;\n    }\n\
    \    int size(int x) { return -find[root(x)]; }\n};\n\n};  // namespace kyopro\n\
    \n/**\n * @brief Disjoint Set Union\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/dsu.hpp
  requiredBy: []
  timestamp: '2023-10-22 17:06:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/1_A.test.cpp
documentation_of: src/data-structure/dsu.hpp
layout: document
redirect_from:
- /library/src/data-structure/dsu.hpp
- /library/src/data-structure/dsu.hpp.html
title: Disjoint Set Union
---
