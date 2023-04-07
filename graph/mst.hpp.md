---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dsu.hpp
    title: Disjoint Set(Union find)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/2_A.test.cpp
    title: test/AOJ/GRL/2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)"
    links: []
  bundledCode: "#line 2 \"data-structure/dsu.hpp\"\n#include <vector>\n/// @brief\
    \ Disjoint Set(Union find)\nclass dsu {\n  private:\n    std::vector<int> find,\
    \ rank;\n\n  public:\n    dsu(int n) : find(n, -1), rank(n, 1) {}\n    int root(int\
    \ x) {\n        if (find[x] < 0) {\n            return x;\n        } else {\n\
    \            return find[x] = root(find[x]);\n        }\n    }\n    bool same(int\
    \ x, int y) { return root(x) == root(y); }\n    int merge(int x, int y) {\n  \
    \      x = root(x), y = root(y);\n        if (x == y) return x;\n        if (rank[x]\
    \ < rank[y]) std::swap(x, y);\n        if (rank[x] == rank[y]) rank[x]++;\n  \
    \      find[x] += find[y];\n        find[y] = x;\n        return x;\n    }\n \
    \   int size(int x) { return -find[root(x)]; }\n};\n\n\n\n/// @docs docs/data-structure/dsu.md\n\
    #line 4 \"graph/mst.hpp\"\n#include <algorithm>\n///@brief Minimum Spannning Tree(\u6700\
    \u5C0F\u5168\u57DF\u6728)\nclass MST {\n    dsu uf;\n    struct Edge {\n     \
    \   int v1, v2;\n        int cost;\n        Edge(int v1, int v2, int cost) : v1(v1),\
    \ v2(v2), cost(cost){}\n    };\n    std::vector<Edge> E;\n  public:\n    MST(int\
    \ V) : uf(V){}\n    void add_edge(int a, int b, int cost) {\n        E.emplace_back(a,\
    \ b, cost);\n    }\n    long long calc() {\n        std::sort(E.begin(), E.end(),\
    \ [&](const Edge& e1, const Edge& e2) {\n            return e1.cost < e2.cost;\n\
    \        });\n        long long ans = 0;\n        for (int i = 0; i < (int)E.size();\
    \ i++) {\n            int w = E[i].cost;\n            int a = E[i].v1, b = E[i].v2;\n\
    \            if (uf.same(a, b)) continue;\n            uf.merge(a, b);\n     \
    \       ans += w;\n        }\n        return ans;\n    }\n};\n"
  code: "#pragma once\n#include\"data-structure/dsu.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n///@brief Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728\
    )\nclass MST {\n    dsu uf;\n    struct Edge {\n        int v1, v2;\n        int\
    \ cost;\n        Edge(int v1, int v2, int cost) : v1(v1), v2(v2), cost(cost){}\n\
    \    };\n    std::vector<Edge> E;\n  public:\n    MST(int V) : uf(V){}\n    void\
    \ add_edge(int a, int b, int cost) {\n        E.emplace_back(a, b, cost);\n  \
    \  }\n    long long calc() {\n        std::sort(E.begin(), E.end(), [&](const\
    \ Edge& e1, const Edge& e2) {\n            return e1.cost < e2.cost;\n       \
    \ });\n        long long ans = 0;\n        for (int i = 0; i < (int)E.size();\
    \ i++) {\n            int w = E[i].cost;\n            int a = E[i].v1, b = E[i].v2;\n\
    \            if (uf.same(a, b)) continue;\n            uf.merge(a, b);\n     \
    \       ans += w;\n        }\n        return ans;\n    }\n};"
  dependsOn:
  - data-structure/dsu.hpp
  isVerificationFile: false
  path: graph/mst.hpp
  requiredBy: []
  timestamp: '2023-04-07 13:28:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/2_A.test.cpp
documentation_of: graph/mst.hpp
layout: document
redirect_from:
- /library/graph/mst.hpp
- /library/graph/mst.hpp.html
title: "Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)"
---
