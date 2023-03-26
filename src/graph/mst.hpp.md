---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/dsu.hpp
    title: Disjoint Set(Union find)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/2/A.test.cpp
    title: test/AOJ/GRL/2/A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)"
    links: []
  bundledCode: "#line 1 \"src/data-structure/dsu.hpp\"\n/// @brief Disjoint Set(Union\
    \ find)\n/// @docs docs/data-structure/dsu.md\nclass DSU {\nprivate:\n\tvector<int>\
    \ par, rank, siz;\n\tint N;\npublic:\n\tDSU(int n) : par(n, -1), rank(n, 0), siz(n,\
    \ 1), N(n) {}\n\n\tint root(int x) {\n\t\tif (par[x] == -1)\n\t\t\treturn x;\n\
    \t\telse\n\t\t\treturn par[x] = root(par[x]);\n\t}\n\tbool same(int x, int y)\
    \ {\n\t\treturn root(x) == root(y);\n\t}\n\n\tbool merge(int x, int y) {\n\t\t\
    int rx = root(x), ry = root(y);\n\t\tif (rx == ry)\n\t\t\treturn false;\n\n\t\t\
    if (rank[rx] < rank[ry])\n\t\t\tswap(rx, ry);\n\t\tpar[ry] = rx;\n\n\t\tsiz[rx]\
    \ += siz[ry];\n\t\treturn true;\n\t}\n\n\tint size(int x) {\n\t\treturn siz[root(x)];\n\
    \t}\n\tint group_size() {\n\t\tint cnt = 0;\n\t\tfor (int i = 0; i < N; i++)\n\
    \t\t\tif (root(i) == i)\n\t\t\t\tcnt++;\n\t\treturn cnt;\n\t}\n};\n#line 2 \"\
    src/graph/mst.hpp\"\n///@brief Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\
    \u6728)\nclass MST {\n    DSU dsu;\n    struct Edge {\n        int v1, v2;\n \
    \       int cost;\n        int id;\n        Edge(int v1, int v2, int cost, int\
    \ id) :v1(v1), v2(v2), cost(cost), id(id) {  }\n    };\n    vector<Edge> E;\n\
    \    vector<int> V1, V2;\npublic:\n    MST(int V) :dsu(V) {}\n    void add_edge(int\
    \ a, int b, ll cost) {\n        int sz = E.size();\n        E.emplace_back(a,\
    \ b, cost, sz);\n        V1.emplace_back(a), V2.emplace_back(b);\n    }\n    ll\
    \ result() {\n        sort(E.begin(), E.end(), [&](Edge e1, Edge e2) {\n     \
    \       return e1.cost < e2.cost;\n            });\n        ll ans = 0;\n    \
    \    rep(i, E.size()) {\n            int len = E[i].cost;\n            int id\
    \ = E[i].id;\n            int a = V1[id], b = V2[id];\n            if (dsu.same(a,\
    \ b))continue;\n            dsu.merge(a, b);\n            ans += len;\n      \
    \  }\n        return ans;\n    }\n};\n"
  code: "#include\"../data-structure/dsu.hpp\"\n///@brief Minimum Spannning Tree(\u6700\
    \u5C0F\u5168\u57DF\u6728)\nclass MST {\n    DSU dsu;\n    struct Edge {\n    \
    \    int v1, v2;\n        int cost;\n        int id;\n        Edge(int v1, int\
    \ v2, int cost, int id) :v1(v1), v2(v2), cost(cost), id(id) {  }\n    };\n   \
    \ vector<Edge> E;\n    vector<int> V1, V2;\npublic:\n    MST(int V) :dsu(V) {}\n\
    \    void add_edge(int a, int b, ll cost) {\n        int sz = E.size();\n    \
    \    E.emplace_back(a, b, cost, sz);\n        V1.emplace_back(a), V2.emplace_back(b);\n\
    \    }\n    ll result() {\n        sort(E.begin(), E.end(), [&](Edge e1, Edge\
    \ e2) {\n            return e1.cost < e2.cost;\n            });\n        ll ans\
    \ = 0;\n        rep(i, E.size()) {\n            int len = E[i].cost;\n       \
    \     int id = E[i].id;\n            int a = V1[id], b = V2[id];\n           \
    \ if (dsu.same(a, b))continue;\n            dsu.merge(a, b);\n            ans\
    \ += len;\n        }\n        return ans;\n    }\n};"
  dependsOn:
  - src/data-structure/dsu.hpp
  isVerificationFile: false
  path: src/graph/mst.hpp
  requiredBy: []
  timestamp: '2023-03-27 01:42:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/2/A.test.cpp
documentation_of: src/graph/mst.hpp
layout: document
redirect_from:
- /library/src/graph/mst.hpp
- /library/src/graph/mst.hpp.html
title: "Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)"
---
