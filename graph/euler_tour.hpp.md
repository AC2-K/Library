---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Vertex Add Subtree Sum.test.cpp
    title: test/Library-Checker/Vertex Add Subtree Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: EulerTour
    links: []
  bundledCode: "#line 1 \"graph/euler_tour.hpp\"\nclass EulerTour {\n\tusing graph\
    \ = vector<vector<int>>;\n\tgraph g;\npublic:\n\tvector<int> in, out, depth,tour;\n\
    \    EulerTour(int n) :g(n), depth(n), in(n), out(n) {}\n\tvoid add_edge(int a,\
    \ int b) {\n\t\tg[a].emplace_back(b);\n\t\tg[b].emplace_back(a);\n\t}\n\n\tvoid\
    \ build(int root){\n\t\tdepth[root] = 0;\n\t\tfunction<void(int, int)> dfs = [&](int\
    \ v, int par = -1)-> void {\n\t\t\tin[v] = tour.size();\n\t\t\ttour.emplace_back(v);\n\
    \t\t\tfor (const auto& c : g[v])if (c != par) {\n\t\t\t\tdepth[c] = depth[v] +\
    \ 1;\n\t\t\t\tdfs(c, v);\n\t\t\t\ttour.emplace_back(v);\n\t\t\t}\n\t\t\tout[v]\
    \ = tour.size() - 1;\n\t\t};\n\t\tdfs(root, -1);\n\t}\n};\n///@brief EulerTour\n"
  code: "class EulerTour {\n\tusing graph = vector<vector<int>>;\n\tgraph g;\npublic:\n\
    \tvector<int> in, out, depth,tour;\n    EulerTour(int n) :g(n), depth(n), in(n),\
    \ out(n) {}\n\tvoid add_edge(int a, int b) {\n\t\tg[a].emplace_back(b);\n\t\t\
    g[b].emplace_back(a);\n\t}\n\n\tvoid build(int root){\n\t\tdepth[root] = 0;\n\t\
    \tfunction<void(int, int)> dfs = [&](int v, int par = -1)-> void {\n\t\t\tin[v]\
    \ = tour.size();\n\t\t\ttour.emplace_back(v);\n\t\t\tfor (const auto& c : g[v])if\
    \ (c != par) {\n\t\t\t\tdepth[c] = depth[v] + 1;\n\t\t\t\tdfs(c, v);\n\t\t\t\t\
    tour.emplace_back(v);\n\t\t\t}\n\t\t\tout[v] = tour.size() - 1;\n\t\t};\n\t\t\
    dfs(root, -1);\n\t}\n};\n///@brief EulerTour"
  dependsOn: []
  isVerificationFile: false
  path: graph/euler_tour.hpp
  requiredBy: []
  timestamp: '2023-02-21 13:24:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Library-Checker/Vertex Add Subtree Sum.test.cpp
documentation_of: graph/euler_tour.hpp
layout: document
redirect_from:
- /library/graph/euler_tour.hpp
- /library/graph/euler_tour.hpp.html
title: EulerTour
---
