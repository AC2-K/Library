---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/dsu.hpp
    title: Disjoint Set(Union find)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL/2_A.test.cpp
    title: test/AOJ/GRL/2_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)"
    links: []
  bundledCode: "#line 2 \"graph/mst.hpp\"\n#include<algorithm>\n#line 1 \"data-structure/dsu.hpp\"\
    \n#include<vector>\nnamespace library{\n/// @brief Disjoint Set(Union find)\n\
    /// @docs docs/data-structure/dsu.md\nclass DSU {\nprivate:\n  std::vector<int>\
    \ find, rank;\n\npublic:\n  DSU(int n) : find(n, -1), rank(n, 1) {}\n\n    int\
    \ leader(int x) {\n        if (find[x] < 0) {\n            return x;\n       \
    \ } else {\n            return find[x] = leader(find[x]);\n        }\n    }\n\
    \    bool same(int x, int y) {\n        return leader(x) == leader(y);\n    }\n\
    \n    int merge(int x, int y) {\n        x = leader(x), y = leader(y);\n     \
    \   if (x == y) return x;\n        if (rank[x] < rank[y]) std::swap(x, y);\n \
    \       if (rank[x] == rank[y]) rank[x]++; \n        find[x] += find[y];\n   \
    \     find[y] = x;\n        return x;\n    }\n\n    int size(int x) {\n      \
    \  return -find[leader(x)];\n    }\n};\n};  // namespace library\n#line 4 \"graph/mst.hpp\"\
    \nnamespace library {\n///@brief Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\
    \u6728)\nclass MST {\n    DSU dsu;\n    struct Edge {\n        int v1, v2;\n \
    \       int cost;\n        int id;\n        Edge(int v1, int v2, int cost, int\
    \ id) :v1(v1), v2(v2), cost(cost), id(id) {  }\n    };\n    std::vector<Edge>\
    \ E;\n    std::vector<int> V1, V2;\npublic:\n    MST(int V) :dsu(V) {E.reserve(V);}\n\
    \    void add_edge(int a, int b, long long cost) {\n        int sz = E.size();\n\
    \        E.emplace_back(a, b, cost, sz);\n        V1.emplace_back(a), V2.emplace_back(b);\n\
    \    }\n    long long result() {\n        std::sort(E.begin(), E.end(), [&](Edge\
    \ e1, Edge e2) {\n            return e1.cost < e2.cost;\n        });\n       \
    \ long long ans = 0;\n        for (int i = 0; (int)E.size(); i++) {\n        \
    \    int len = E[i].cost;\n            int id = E[i].id;\n            int a =\
    \ V1[id], b = V2[id];\n            if (dsu.same(a, b)) continue;\n           \
    \ dsu.merge(a, b);\n            ans += len;\n        }\n        return ans;\n\
    \    }\n};\n\n};  // namespace library\n"
  code: "#pragma once\n#include<algorithm>\n#include\"data-structure/dsu.hpp\"\nnamespace\
    \ library {\n///@brief Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)\n\
    class MST {\n    DSU dsu;\n    struct Edge {\n        int v1, v2;\n        int\
    \ cost;\n        int id;\n        Edge(int v1, int v2, int cost, int id) :v1(v1),\
    \ v2(v2), cost(cost), id(id) {  }\n    };\n    std::vector<Edge> E;\n    std::vector<int>\
    \ V1, V2;\npublic:\n    MST(int V) :dsu(V) {E.reserve(V);}\n    void add_edge(int\
    \ a, int b, long long cost) {\n        int sz = E.size();\n        E.emplace_back(a,\
    \ b, cost, sz);\n        V1.emplace_back(a), V2.emplace_back(b);\n    }\n    long\
    \ long result() {\n        std::sort(E.begin(), E.end(), [&](Edge e1, Edge e2)\
    \ {\n            return e1.cost < e2.cost;\n        });\n        long long ans\
    \ = 0;\n        for (int i = 0; (int)E.size(); i++) {\n            int len = E[i].cost;\n\
    \            int id = E[i].id;\n            int a = V1[id], b = V2[id];\n    \
    \        if (dsu.same(a, b)) continue;\n            dsu.merge(a, b);\n       \
    \     ans += len;\n        }\n        return ans;\n    }\n};\n\n};  // namespace\
    \ library"
  dependsOn:
  - data-structure/dsu.hpp
  isVerificationFile: false
  path: graph/mst.hpp
  requiredBy: []
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/GRL/2_A.test.cpp
documentation_of: graph/mst.hpp
layout: document
redirect_from:
- /library/graph/mst.hpp
- /library/graph/mst.hpp.html
title: "Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)"
---
