---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/5_C.test.cpp
    title: test/AOJ/GRL/5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
    title: test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
    links: []
  bundledCode: "#line 2 \"data-structure/sparse_table.hpp\"\n#include <numeric>\n\
    #include <vector>\nnamespace kyopro {\n/// @brief Sparse Table\ntemplate <class\
    \ T> class sparse_table {\n    std::vector<T> vec;\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<int> look_up;\n\n  public:\n    sparse_table(int n)\
    \ : vec(n) {}\n    sparse_table(const std::vector<T>& vec) : vec(vec) { build();\
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
    \ b)]);\n    }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/sparse_table.md\n\
    #line 3 \"graph/euler_tour.hpp\"\nnamespace kyopro {\n///@brief EulerTour(\u30AA\
    \u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)\nclass EulerTour {\n    int n;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> tour;\n    std::vector<int> in, out, depth;\n    sparse_table<std::pair<int,\
    \ int>> rmq;\n\n  public:\n    EulerTour(int n)\n        : n(n), g(n), in(n, -1),\
    \ out(n, -1), depth(n, -1), rmq(2 * n - 1) {\n        tour.reserve(2 * n - 1);\n\
    \    }\n    inline void add_edge(int u, int v) {\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n    }\n    inline std::vector<std::vector<int>>\
    \ get_graph() { return g; }\n    inline std::vector<int> get_tour() { return tour;\
    \ }\n\n  private:\n  public:\n    void build(int r = 0) {\n        auto dfs =\
    \ [&](auto self, int v, int p) -> void {\n            in[v] = tour.size();\n \
    \           tour.emplace_back(v);\n            for (const auto& nv : g[v])\n \
    \               if (nv != p) {\n                    depth[nv] = depth[v] + 1;\n\
    \                    self(self, nv, v);\n                    tour.emplace_back(v);\n\
    \                }\n            out[v] = tour.size() - 1;\n        };\n      \
    \  dfs(dfs, r, -1);\n        for (int i = 0; i < (int)tour.size(); i++) {\n  \
    \          rmq.set(i, {depth[tour[i]], tour[i]});\n        }\n        rmq.build();\n\
    \    }\n\n    std::pair<int, int> idx(int v) { return {in[v], out[v]}; }\n   \
    \ int lca(int v, int u) {\n        if (in[v] > in[u] + 1) {\n            std::swap(u,\
    \ v);\n        }\n        return rmq.prod(in[v], in[u] + 1).second;\n    }\n\n\
    \    int dist(int v, int u) {\n        int p = lca(v, u);\n        return depth[v]\
    \ + depth[u] - 2 * depth[p];\n    }\n\n    bool is_in_subtree(int par, int v)\
    \ {\n        return (in[par] <= in[v] && out[v] <= out[par]);\n    }\n};\n}; \
    \ // namespace kyopro\n"
  code: "#pragma once\n#include \"data-structure/sparse_table.hpp\"\nnamespace kyopro\
    \ {\n///@brief EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)\nclass EulerTour\
    \ {\n    int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> tour;\n\
    \    std::vector<int> in, out, depth;\n    sparse_table<std::pair<int, int>> rmq;\n\
    \n  public:\n    EulerTour(int n)\n        : n(n), g(n), in(n, -1), out(n, -1),\
    \ depth(n, -1), rmq(2 * n - 1) {\n        tour.reserve(2 * n - 1);\n    }\n  \
    \  inline void add_edge(int u, int v) {\n        g[u].emplace_back(v);\n     \
    \   g[v].emplace_back(u);\n    }\n    inline std::vector<std::vector<int>> get_graph()\
    \ { return g; }\n    inline std::vector<int> get_tour() { return tour; }\n\n \
    \ private:\n  public:\n    void build(int r = 0) {\n        auto dfs = [&](auto\
    \ self, int v, int p) -> void {\n            in[v] = tour.size();\n          \
    \  tour.emplace_back(v);\n            for (const auto& nv : g[v])\n          \
    \      if (nv != p) {\n                    depth[nv] = depth[v] + 1;\n       \
    \             self(self, nv, v);\n                    tour.emplace_back(v);\n\
    \                }\n            out[v] = tour.size() - 1;\n        };\n      \
    \  dfs(dfs, r, -1);\n        for (int i = 0; i < (int)tour.size(); i++) {\n  \
    \          rmq.set(i, {depth[tour[i]], tour[i]});\n        }\n        rmq.build();\n\
    \    }\n\n    std::pair<int, int> idx(int v) { return {in[v], out[v]}; }\n   \
    \ int lca(int v, int u) {\n        if (in[v] > in[u] + 1) {\n            std::swap(u,\
    \ v);\n        }\n        return rmq.prod(in[v], in[u] + 1).second;\n    }\n\n\
    \    int dist(int v, int u) {\n        int p = lca(v, u);\n        return depth[v]\
    \ + depth[u] - 2 * depth[p];\n    }\n\n    bool is_in_subtree(int par, int v)\
    \ {\n        return (in[par] <= in[v] && out[v] <= out[par]);\n    }\n};\n}; \
    \ // namespace kyopro"
  dependsOn:
  - data-structure/sparse_table.hpp
  isVerificationFile: false
  path: graph/euler_tour.hpp
  requiredBy: []
  timestamp: '2023-04-08 03:34:55+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/GRL/5_C.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
documentation_of: graph/euler_tour.hpp
layout: document
redirect_from:
- /library/graph/euler_tour.hpp
- /library/graph/euler_tour.hpp.html
title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
---
