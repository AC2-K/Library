---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.hpp
    title: Sparse Table(Range Min)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/5_C.test.cpp
    title: test/AOJ/GRL/5_C.test.cpp
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
    document_title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
    links: []
  bundledCode: "#line 1 \"data-structure/sparse_table.hpp\"\n#include<vector>\nnamespace\
    \ library{\n\n/// @brief Sparse Table(Range Min)\n/// @tparam T \u8981\u7D20\u306E\
    \u578B\n/// @docs docs/data-structure/sparse_table.md\ntemplate<class T>\nclass\
    \ sparse_table {\n    std::vector<T> vec;\n    std::vector<std::vector<T>> table;\n\
    \    std::vector<int> look_up;\npublic:\n    sparse_table(int n) : vec(n) {}\n\
    \    sparse_table(const std::vector<T>& vec) : vec(vec) { build(); }\n    void\
    \ set(int p, const T& v) { vec[p] = v; }\n    void build() {\n        int sz =\
    \ vec.size();\n        int log = 0;\n        while ((1 << log) <= sz) {\n    \
    \        log++;\n        }\n        table.assign(log, std::vector<T>(1 << log));\n\
    \        for (int i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n \
    \       }\n        for (int i = 1; i < log; i++) {\n            for (int j = 0;\
    \ j + (1 << i) <= (1 << log); j++) {\n                table[i][j] =\n        \
    \            std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n  \
    \          }\n        }\n        look_up.resize(sz + 1);\n        for (int i =\
    \ 2; i < (int)look_up.size(); i++) {\n            look_up[i] = look_up[i >> 1]\
    \ + 1;\n        }\n    }\n\n    T prod(int l, int r) {\n        int b = look_up[r\
    \ - l];\n        return std::min(table[b][l], table[b][r - (1 << b)]);\n    }\n\
    };\n};  // namespace library\n#line 3 \"graph/euler_tour.hpp\"\nnamespace library\
    \ {\n\n///@brief EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)\nclass\
    \ EulerTour {\n\tint n;\n\tstd::vector<std::vector<int>> g;\n\tstd::vector<int>\
    \ tour;\n\tstd::vector<int> in, out, depth;\n    sparse_table<std::pair<int, int>>\
    \ rmq;\npublic:\n    EulerTour(int n) :n(n), g(n), in(n, -1), out(n, -1), depth(n,\
    \ -1), rmq(2 * n - 1) { tour.reserve(2 * n - 1); }\n\tvoid add_edge(int u, int\
    \ v) {\n\t\tg[u].emplace_back(v);\n\t\tg[v].emplace_back(u);\n\t}\n    std::vector<std::vector<int>>\
    \ get_graph(){return g;}\n    std::vector<int> get_tour(){return tour;}\nprivate:\n\
    public:\n  \n  void build(int r = 0) {\n        auto dfs = [&](const auto& self,\
    \ int v, int p) -> void {\n            in[v] = tour.size();\n            tour.emplace_back(v);\n\
    \            for (const auto& nv : g[v]) {\n                if (nv != p) {\n \
    \                   depth[nv] = depth[v] + 1;\n                    self(self,\
    \ nv, v);\n                    tour.emplace_back(v);\n                }\n    \
    \            out[v] = tour.size() - 1;\n            }\n        };\n        dfs(dfs,\
    \ r, -1);\n        for (int i = 0; i < (int)tour.size(); i++) {\n            rmq.set(i,\
    \ {depth[tour[i]], tour[i]});\n        }\n        rmq.build();\n    }\n\n    std::pair<int,\
    \ int> idx(int v) { return {in[v], out[v]}; }\n    int lca(int v, int u) {\n \
    \       if (in[v] > in[u] + 1) { std::swap(u, v); }\n        return rmq.prod(in[v],\
    \ in[u] + 1).second;\n    }\n\n    int dist(int v,int u){\n        int p = lca(v,\
    \ u);\n        return depth[v] + depth[u] - 2 * depth[p];\n    }\n\n    bool is_in_subtree(int\
    \ par,int v){return (in[par] <= in[v] && out[v] <= out[par]);}\n};\n\n};  // namespace\
    \ library\n"
  code: "#pragma once\n#include \"data-structure/sparse_table.hpp\"\nnamespace library\
    \ {\n\n///@brief EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)\nclass\
    \ EulerTour {\n\tint n;\n\tstd::vector<std::vector<int>> g;\n\tstd::vector<int>\
    \ tour;\n\tstd::vector<int> in, out, depth;\n    sparse_table<std::pair<int, int>>\
    \ rmq;\npublic:\n    EulerTour(int n) :n(n), g(n), in(n, -1), out(n, -1), depth(n,\
    \ -1), rmq(2 * n - 1) { tour.reserve(2 * n - 1); }\n\tvoid add_edge(int u, int\
    \ v) {\n\t\tg[u].emplace_back(v);\n\t\tg[v].emplace_back(u);\n\t}\n    std::vector<std::vector<int>>\
    \ get_graph(){return g;}\n    std::vector<int> get_tour(){return tour;}\nprivate:\n\
    public:\n  \n  void build(int r = 0) {\n        auto dfs = [&](const auto& self,\
    \ int v, int p) -> void {\n            in[v] = tour.size();\n            tour.emplace_back(v);\n\
    \            for (const auto& nv : g[v]) {\n                if (nv != p) {\n \
    \                   depth[nv] = depth[v] + 1;\n                    self(self,\
    \ nv, v);\n                    tour.emplace_back(v);\n                }\n    \
    \            out[v] = tour.size() - 1;\n            }\n        };\n        dfs(dfs,\
    \ r, -1);\n        for (int i = 0; i < (int)tour.size(); i++) {\n            rmq.set(i,\
    \ {depth[tour[i]], tour[i]});\n        }\n        rmq.build();\n    }\n\n    std::pair<int,\
    \ int> idx(int v) { return {in[v], out[v]}; }\n    int lca(int v, int u) {\n \
    \       if (in[v] > in[u] + 1) { std::swap(u, v); }\n        return rmq.prod(in[v],\
    \ in[u] + 1).second;\n    }\n\n    int dist(int v,int u){\n        int p = lca(v,\
    \ u);\n        return depth[v] + depth[u] - 2 * depth[p];\n    }\n\n    bool is_in_subtree(int\
    \ par,int v){return (in[par] <= in[v] && out[v] <= out[par]);}\n};\n\n};  // namespace\
    \ library"
  dependsOn:
  - data-structure/sparse_table.hpp
  isVerificationFile: false
  path: graph/euler_tour.hpp
  requiredBy: []
  timestamp: '2023-04-06 21:43:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - test/AOJ/GRL/5_C.test.cpp
documentation_of: graph/euler_tour.hpp
layout: document
redirect_from:
- /library/graph/euler_tour.hpp
- /library/graph/euler_tour.hpp.html
title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
---
