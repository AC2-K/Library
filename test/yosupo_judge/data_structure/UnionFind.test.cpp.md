---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/dsu.hpp
    title: Disjoint Set(Union Find)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/UnionFind.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<iostream>\n\
    #line 2 \"src/data-structure/dsu.hpp\"\n#include <utility>\n#include <vector>\n\
    namespace kyopro {\n\n/**\n * @brief Disjoint Set(Union Find)\n */\nclass dsu\
    \ {\nprivate:\n    std::vector<int> find, rank;\n\npublic:\n    dsu(int n) : find(n,\
    \ -1), rank(n, 1) {}\n\n    int root(int x) {\n        if (find[x] < 0) {\n  \
    \          return x;\n        } else {\n            return find[x] = root(find[x]);\n\
    \        }\n    }\n    bool same(int x, int y) { return root(x) == root(y); }\n\
    \    int merge(int x, int y) {\n        x = root(x), y = root(y);\n        if\
    \ (x == y) return x;\n        if (rank[x] < rank[y]) std::swap(x, y);\n      \
    \  if (rank[x] == rank[y]) rank[x]++;\n        find[x] += find[y];\n        find[y]\
    \ = x;\n        return x;\n    }\n    int size(int x) { return -find[root(x)];\
    \ }\n};\n\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/dsu.md\n\
    \ */\n#line 5 \"test/yosupo_judge/data_structure/UnionFind.test.cpp\"\nint main()\
    \ {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n    kyopro::dsu uf(n);\n   \
    \ while (q--) {\n        int t, x, y;\n        scanf(\"%d%d%d\", &t, &x, &y);\n\
    \        if (!t) {\n            uf.merge(x, y);\n        }\n        else {\n \
    \           if (uf.same(x, y))puts(\"1\");\n            else puts(\"0\");\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<iostream>\n\
    #include \"../../../src/data-structure/dsu.hpp\"\nint main() {\n    int n, q;\n\
    \    scanf(\"%d%d\", &n, &q);\n    kyopro::dsu uf(n);\n    while (q--) {\n   \
    \     int t, x, y;\n        scanf(\"%d%d%d\", &t, &x, &y);\n        if (!t) {\n\
    \            uf.merge(x, y);\n        }\n        else {\n            if (uf.same(x,\
    \ y))puts(\"1\");\n            else puts(\"0\");\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/dsu.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2023-05-07 23:12:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/UnionFind.test.cpp
- /verify/test/yosupo_judge/data_structure/UnionFind.test.cpp.html
title: test/yosupo_judge/data_structure/UnionFind.test.cpp
---
