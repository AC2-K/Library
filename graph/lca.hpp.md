---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.hpp
    title: sparse table
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/AOJ/GRL/5/C.cpp
    title: test/AOJ/GRL/5/C.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
    title: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
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
    \ << b)]);\n    }\n};\n///@brief sparse table\n#line 3 \"graph/lca.hpp\"\nclass\
    \ LCA {\n    using graph = vector<vector<int>>;\n    int n;\n    graph g;\n  \
    \  vector<int> vs, in;\n    sparse_table<pair<int,int>> seg;\npublic:\n    LCA(const\
    \ graph& g) :g(g), n(g.size()),in(n) { }\n    void setup() {\n        int p =\
    \ 0;\n        vector<pair<int,int>> vec(2 * n);\n        function<void(int, int,\
    \ int)> dfs = [&](int v, int par, int now_depth) -> void {\n            in[v]\
    \ = p;\n            vec[p++]={now_depth,v};\n            for (const auto& ch :\
    \ g[v])if (ch != par) {\n                dfs(ch, v, now_depth + 1);\n        \
    \        vec[p++] = { now_depth,v };\n            }\n        };\n        dfs(0,\
    \ -1, 0);\n        seg = sparse_table<pair<int, int>>(vec);\n    }\n\n    int\
    \ query(int u, int v) {\n        if (in[u] >= in[v])swap(u, v);\n        return\
    \ seg.prod(in[u], in[v] + 1).second;\n    }\n};\n///@brief Lowest Common Ancestor(\u6700\
    \u5C0F\u5171\u901A\u7956\u5148)\n"
  code: "#pragma once\n#include\"data-structure/sparse_table.hpp\"\nclass LCA {\n\
    \    using graph = vector<vector<int>>;\n    int n;\n    graph g;\n    vector<int>\
    \ vs, in;\n    sparse_table<pair<int,int>> seg;\npublic:\n    LCA(const graph&\
    \ g) :g(g), n(g.size()),in(n) { }\n    void setup() {\n        int p = 0;\n  \
    \      vector<pair<int,int>> vec(2 * n);\n        function<void(int, int, int)>\
    \ dfs = [&](int v, int par, int now_depth) -> void {\n            in[v] = p;\n\
    \            vec[p++]={now_depth,v};\n            for (const auto& ch : g[v])if\
    \ (ch != par) {\n                dfs(ch, v, now_depth + 1);\n                vec[p++]\
    \ = { now_depth,v };\n            }\n        };\n        dfs(0, -1, 0);\n    \
    \    seg = sparse_table<pair<int, int>>(vec);\n    }\n\n    int query(int u, int\
    \ v) {\n        if (in[u] >= in[v])swap(u, v);\n        return seg.prod(in[u],\
    \ in[v] + 1).second;\n    }\n};\n///@brief Lowest Common Ancestor(\u6700\u5C0F\
    \u5171\u901A\u7956\u5148)"
  dependsOn:
  - data-structure/sparse_table.hpp
  isVerificationFile: false
  path: graph/lca.hpp
  requiredBy:
  - test/AOJ/GRL/5/C.cpp
  timestamp: '2023-02-23 13:41:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
documentation_of: graph/lca.hpp
layout: document
redirect_from:
- /library/graph/lca.hpp
- /library/graph/lca.hpp.html
title: "Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
---
