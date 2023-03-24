---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/5/C.test.cpp
    title: test/AOJ/GRL/5/C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
    title: test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
    title: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
    title: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/sparse_table.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#include\"data-structure/sparse_table.hpp\"\n\n///@brief EulerTour(\u30AA\
    \u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)\nclass EulerTour {\n\tint n;\n\tgraph g;\n\
    \tvector<int> tour;\n\tvector<int> in, out, depth;\n    sparse_table<pair<int,\
    \ int>> rmq;\npublic:\n    EulerTour(int n) :n(n), g(n), in(n, -1), out(n, -1),\
    \ depth(n, -1), rmq(2 * n - 1) { tour.reserve(2 * n - 1); }\n\tvoid add_edge(int\
    \ u, int v) {\n\t\tg[u].emplace_back(v);\n\t\tg[v].emplace_back(u);\n\t}\n   \
    \ graph get_graph(){return g;}\n    vector<int> get_tour(){return tour;}\nprivate:\n\
    \    void dfs(int v, int p = -1) {\n        in[v] = tour.size();\n        tour.emplace_back(v);\n\
    \        for (const auto& nv : g[v])if (nv != p) {\n            depth[nv] = depth[v]\
    \ + 1;\n            dfs(nv, v);\n            tour.emplace_back(v);\n        }\n\
    \        out[v] = tour.size() - 1;\n    }\npublic:\n    void build(int r = 0)\
    \ {\n        dfs(r);\n        for (int i = 0; i < tour.size(); i++) {\n      \
    \      rmq.set(i, { depth[tour[i]],tour[i] });\n        }\n        rmq.build();\n\
    \    }\n\n    pair<int, int> idx(int v) { return {in[v], out[v]}; }\n    int lca(int\
    \ v, int u) {\n        if (in[v] > in[u] + 1) { swap(u, v); }\n        return\
    \ rmq.prod(in[v], in[u] + 1).second;\n    }\n\n    int dist(int v,int u){\n  \
    \      int p = lca(v, u);\n        return depth[v] + depth[u] - 2 * depth[p];\n\
    \    }\n\n    bool is_in_subtree(int par,int v){return (in[par] <= in[v] && out[v]\
    \ <= out[par]);}\n};"
  dependsOn:
  - data-structure/sparse_table.hpp
  isVerificationFile: false
  path: graph/euler_tour.hpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
  - test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
  - test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  - test/AOJ/GRL/5/C.test.cpp
documentation_of: graph/euler_tour.hpp
layout: document
redirect_from:
- /library/graph/euler_tour.hpp
- /library/graph/euler_tour.hpp.html
title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
---
