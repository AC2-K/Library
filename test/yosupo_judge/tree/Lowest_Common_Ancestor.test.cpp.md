---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/sparse_table.hpp
    title: Sparse Table(RangeMin)
  - icon: ':question:'
    path: src/graph/euler_tour.hpp
    title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include<iostream>\n\
    #line 2 \"src/graph/euler_tour.hpp\"\n#include <utility>\n#line 2 \"src/data-structure/sparse_table.hpp\"\
    \n#include <numeric>\n#include <vector>\nnamespace kyopro {\n/// @brief Sparse\
    \ Table(RangeMin)\ntemplate <class T>\nclass sparse_table {\n    std::vector<T>\
    \ vec;\n    std::vector<std::vector<T>> table;\n    std::vector<int> look_up;\n\
    \npublic:\n    sparse_table(int n) : vec(n) {}\n    sparse_table(const std::vector<T>&\
    \ vec) : vec(vec) { build(); }\n    inline void set(int p, const T& v) { vec[p]\
    \ = v; }\n    void build() {\n        int sz = vec.size();\n        int log =\
    \ 0;\n        while ((1 << log) <= sz) {\n            log++;\n        }\n    \
    \    table.assign(log, std::vector<T>(1 << log));\n        for (int i = 0; i <\
    \ sz; i++) {\n            table[0][i] = vec[i];\n        }\n        for (int i\
    \ = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <= (1 << log);\
    \ j++) {\n                table[i][j] =\n                    std::min(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    \
    \    look_up.resize(sz + 1);\n        for (int i = 2; i < (int)look_up.size();\
    \ i++) {\n            look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n\
    \    inline T prod(int l, int r) {\n        int b = look_up[r - l];\n        return\
    \ std::min(table[b][l], table[b][r - (1 << b)]);\n    }\n};\n};  // namespace\
    \ kyopro\n\n/// @docs docs/data-structure/sparse_table.md\n#line 4 \"src/graph/euler_tour.hpp\"\
    \nnamespace kyopro {\n/// @brief EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
    \u30FC)\nclass EulerTour {\n    int n;\n    std::vector<std::vector<int>> g;\n\
    \    std::vector<int> tour;\n    std::vector<int> in, out, depth;\n    sparse_table<std::pair<int,\
    \ int>> rmq;\n\npublic:\n    EulerTour(int n)\n        : n(n), g(n), in(n, -1),\
    \ out(n, -1), depth(n, -1), rmq(2 * n - 1) {\n        tour.reserve(2 * n - 1);\n\
    \    }\n    inline void add_edge(int u, int v) {\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n    }\n    inline std::vector<std::vector<int>>\
    \ get_graph() { return g; }\n    inline std::vector<int> get_tour() { return tour;\
    \ }\n    inline int get_depth(int v) const { return depth[v]; }\n\npublic:\n \
    \   void build(int r = 0) {\n        auto dfs = [&](auto self, int v, int p) ->\
    \ void {\n            in[v] = tour.size();\n            tour.emplace_back(v);\n\
    \            for (const auto& nv : g[v])\n                if (nv != p) {\n   \
    \                 depth[nv] = depth[v] + 1;\n                    self(self, nv,\
    \ v);\n                    tour.emplace_back(v);\n                }\n        \
    \    out[v] = tour.size() - 1;\n        };\n        dfs(dfs, r, -1);\n       \
    \ for (int i = 0; i < (int)tour.size(); i++) {\n            rmq.set(i, {depth[tour[i]],\
    \ tour[i]});\n        }\n        rmq.build();\n    }\n\n    inline std::pair<int,\
    \ int> idx(int v) { return {in[v], out[v]}; }\n    inline int lca(int v, int u)\
    \ {\n        if (in[v] > in[u] + 1) {\n            std::swap(u, v);\n        }\n\
    \        return rmq.prod(in[v], in[u] + 1).second;\n    }\n\n    inline int dist(int\
    \ v, int u) {\n        int p = lca(v, u);\n        return depth[v] + depth[u]\
    \ - 2 * depth[p];\n    }\n\n    inline bool is_in_subtree(int par, int v) {\n\
    \        return (in[par] <= in[v] && out[v] <= out[par]);\n    }\n};\n};  // namespace\
    \ kyopro\n#line 5 \"test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp\"\n\
    using namespace std;\nint main(){\n    int n, q;\n    scanf(\"%d%d\",&n,&q);\n\
    \    kyopro::EulerTour g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n\
    \        cin >> p;\n        g.add_edge(p, i);\n    }\n    g.build();\n    while\
    \ (q--) {\n        int u, v;\n        scanf(\"%d%d\",&u,&v);\n        printf(\"\
    %d\\n\",g.lca(u, v));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include<iostream>\n\
    #include\"../../../src/graph/euler_tour.hpp\"\nusing namespace std;\nint main(){\n\
    \    int n, q;\n    scanf(\"%d%d\",&n,&q);\n    kyopro::EulerTour g(n);\n    for\
    \ (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n        g.add_edge(p,\
    \ i);\n    }\n    g.build();\n    while (q--) {\n        int u, v;\n        scanf(\"\
    %d%d\",&u,&v);\n        printf(\"%d\\n\",g.lca(u, v));\n    }\n}"
  dependsOn:
  - src/graph/euler_tour.hpp
  - src/data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
  requiredBy: []
  timestamp: '2023-04-23 12:26:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
- /verify/test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp.html
title: test/yosupo_judge/tree/Lowest_Common_Ancestor.test.cpp
---
