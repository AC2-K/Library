---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dsu.hpp
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
    \ data-structure/dsu.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#include\"data-structure/dsu.hpp\"\n\n\n///@brief Minimum Spannning Tree(\u6700\
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
  - data-structure/dsu.hpp
  isVerificationFile: false
  path: graph/mst.hpp
  requiredBy: []
  timestamp: '2023-03-28 11:28:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/2/A.test.cpp
documentation_of: graph/mst.hpp
layout: document
redirect_from:
- /library/graph/mst.hpp
- /library/graph/mst.hpp.html
title: "Minimum Spannning Tree(\u6700\u5C0F\u5168\u57DF\u6728)"
---
