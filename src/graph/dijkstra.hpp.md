---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/dijkstra.md
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../src/graph/StaticGraph.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n#include \"../src/graph/StaticGraph.hpp\"\
    \n\nnamespace kyopro {\n\n/**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
    \n */\ntemplate <typename weight> class dijkstra {\n    std::vector<weight> _dist;\n\
    \    const int n;\n    using Graph = WeightedStaticGraph<long long, false>;\n\n\
    private:\n    Graph g;\n\npublic:\n    dijkstra(int n)\n        : n(n), g(n),\
    \ dist(n, std::numeric_limits<weight>::max() / 2) {}\n    dijkstra(const Graph&\
    \ g) : n(g.size()), g(g) {}\n    void add_edge(int from, int to, long long cost)\
    \ {\n        assert(0 <= from && from < n);\n        assert(0 <= to && to < n);\n\
    \        assert(cost >= 0);\n\n        g.add_edge(from, to, cost);\n    }\n  \
    \  void build(int s) {\n        dist.assign(n, );\n        std::priority_queue<std::pair<weight,\
    \ int>,\n                            std::vector<std::pair<weight, int>>, std::greater<>>\n\
    \            q;\n        q.emplace(0, s);\n        dist[s] = 0;\n        while\
    \ (!q.empty()) {\n            auto [d, v] = q.top();\n            q.pop();\n \
    \           if (dist[v] != d) {\n                continue;\n            }\n\n\
    \            for (auto [nv, c] : g[v]) {\n                if (dist[v] + c < dist[nv])\
    \ {\n                    dist[nv] = dist[v] + c;\n                    q.emplace(dist[nv],\
    \ nv);\n                }\n            }\n        }\n    }\n    weight dist(int\
    \ v) const {\n        assert(0 <= v && v < n);\n        return _dist[v];\n   \
    \ }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/graph/dijkstra.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---
