---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/BIT.hpp
    title: Binary Index Tree
  - icon: ':question:'
    path: src/data-structure/sparse_table.hpp
    title: Sparse Table
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #include<iostream>\n#line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\n\
    namespace kyopro {\n/// @brief Binary Index Tree\ntemplate <typename T, typename\
    \ SumT = T> class BIT {\n    std::vector<SumT> bit;\n    int n;\n\n  public:\n\
    \    explicit BIT(int n) : n(n), bit(n + 1, T()) {}\n    void add(int p, const\
    \ T& w) {\n        p++;\n        for (int x = p; x <= n; x += x & -x) {\n    \
    \        bit[x] += w;\n        }\n    }\n\n    SumT sum(int p) const {\n     \
    \   T s = 0;\n\n        for (int x = p; x > 0; x -= x & -x) {\n            s +=\
    \ bit[x];\n        }\n        return s;\n    }\n\n    inline SumT sum(int l, int\
    \ r) const { return sum(r) - sum(l); }\n\n    int lower_bound(SumT w) const {\n\
    \        if (w <= 0) return 0;\n\n        int x = 0;\n        int k = 1;\n   \
    \     while (k < n) k <<= 1;\n        for (; k > 0; k >>= 1) {\n            if\
    \ (x + k <= n && bit[x + k] < w) {\n                w -= bit[x + k];\n       \
    \         x += k;\n            }\n        }\n\n        return x + 1;\n    }\n\
    };\n};  // namespace kyopro\n\n/// @docs docs/data-structure/BIT.md\n#line 2 \"\
    src/data-structure/sparse_table.hpp\"\n#include <numeric>\n#line 4 \"src/data-structure/sparse_table.hpp\"\
    \nnamespace kyopro {\n/// @brief Sparse Table\ntemplate <class T> class sparse_table\
    \ {\n    std::vector<T> vec;\n    std::vector<std::vector<T>> table;\n    std::vector<int>\
    \ look_up;\n\n  public:\n    sparse_table(int n) : vec(n) {}\n    sparse_table(const\
    \ std::vector<T>& vec) : vec(vec) { build(); }\n    inline void set(int p, const\
    \ T& v) { vec[p] = v; }\n    void build() {\n        int sz = vec.size();\n  \
    \      int log = 0;\n        while ((1 << log) <= sz) {\n            log++;\n\
    \        }\n        table.assign(log, std::vector<T>(1 << log));\n        for\
    \ (int i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n        }\n \
    \       for (int i = 1; i < log; i++) {\n            for (int j = 0; j + (1 <<\
    \ i) <= (1 << log); j++) {\n                table[i][j] =\n                  \
    \  std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n\
    \        }\n        look_up.resize(sz + 1);\n        for (int i = 2; i < (int)look_up.size();\
    \ i++) {\n            look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n\
    \    inline T prod(int l, int r) {\n        int b = look_up[r - l];\n        return\
    \ std::min(table[b][l], table[b][r - (1 << b)]);\n    }\n};\n};  // namespace\
    \ kyopro\n\n/// @docs docs/data-structure/sparse_table.md\n#line 3 \"src/graph/euler_tour.hpp\"\
    \nnamespace kyopro {\n///@brief EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
    \u30FC)\nclass EulerTour {\n    int n;\n    std::vector<std::vector<int>> g;\n\
    \    std::vector<int> tour;\n    std::vector<int> in, out, depth;\n    sparse_table<std::pair<int,\
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
    \ // namespace kyopro\n#line 5 \"test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    scanf(\"%d%d\",&n,&q);\n    std::vector<long\
    \ long> a(n);\n    for (auto& aa : a) {\n        scanf(\"%lld\",&aa);\n    }\n\
    \n    kyopro::EulerTour g(n);\n    for (int i = 1; i < n; i++) {\n        int\
    \ p;\n        scanf(\"%d\",&p);\n        g.add_edge(i, p);\n    }\n    g.build();\n\
    \n    kyopro::BIT<long long> seg(2 * n);\n    for (int v = 0; v < n; v++) {\n\
    \        int in = g.idx(v).first;\n        seg.add(in, a[v]);\n    }\n    while\
    \ (q--) {\n        int t;\n        scanf(\"%d\",&t);\n        if (!t) {\n    \
    \        int v,x;\n            scanf(\"%d%d\",&v,&x);\n            int in = g.idx(v).first;\n\
    \            seg.add(in, x);\n        }\n        else {\n            int v;\n\
    \            scanf(\"%d\",&v);\n            auto [in, out] = g.idx(v);\n     \
    \       printf(\"%lld\\n\",seg.sum(in,out + 1));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include<iostream>\n#include\"../../../src/data-structure/BIT.hpp\"\n#include\"\
    ../../../src/graph/euler_tour.hpp\"\n\nint main() {\n    int n, q;\n    scanf(\"\
    %d%d\",&n,&q);\n    std::vector<long long> a(n);\n    for (auto& aa : a) {\n \
    \       scanf(\"%lld\",&aa);\n    }\n\n    kyopro::EulerTour g(n);\n    for (int\
    \ i = 1; i < n; i++) {\n        int p;\n        scanf(\"%d\",&p);\n        g.add_edge(i,\
    \ p);\n    }\n    g.build();\n\n    kyopro::BIT<long long> seg(2 * n);\n    for\
    \ (int v = 0; v < n; v++) {\n        int in = g.idx(v).first;\n        seg.add(in,\
    \ a[v]);\n    }\n    while (q--) {\n        int t;\n        scanf(\"%d\",&t);\n\
    \        if (!t) {\n            int v,x;\n            scanf(\"%d%d\",&v,&x);\n\
    \            int in = g.idx(v).first;\n            seg.add(in, x);\n        }\n\
    \        else {\n            int v;\n            scanf(\"%d\",&v);\n         \
    \   auto [in, out] = g.idx(v);\n            printf(\"%lld\\n\",seg.sum(in,out\
    \ + 1));\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/BIT.hpp
  - src/graph/euler_tour.hpp
  - src/data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 13:07:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
---
