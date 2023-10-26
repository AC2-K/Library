---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL/1_A.test.cpp
    title: test/AOJ/GRL/1_A.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/graph/Shortest_Path.test.cpp
    title: test/yosupo_judge/graph/Shortest_Path.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/tree/Tree_Diameter.test.cpp
    title: test/yosupo_judge/tree/Tree_Diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
    links: []
  bundledCode: "#line 2 \"src/graph/dijkstra.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <limits>\n#include <numeric>\n#include <queue>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace kyopro {\n\ntemplate<typename Cost>\n\
    class dijkstra {\n    std::vector<Cost> _dist;\n    std::vector<int> _trace;\n\
    \    const int n;\n    int s;\n\n    struct edge {\n        const int to;\n  \
    \      const Cost cost;\n        constexpr edge(int to, Cost cost) noexcept :\
    \ to(to), cost(cost) {}\n    };\n\n    std::vector<std::vector<edge>> g;\n\npublic:\n\
    \    static constexpr Cost COST_INF = std::numeric_limits<Cost>::max() / 2;\n\n\
    \    dijkstra(int n) : n(n), g(n), _trace(n, -1), _dist(n, COST_INF) {}\n    dijkstra(const\
    \ std::vector<std::vector<edge>>& g)\n        : n(g.size()), g(g), _trace(g.size(),\
    \ -1), _dist(g.size(), COST_INF){}\n\n    void add_edge(int from, int to, Cost\
    \ cost) {\n        assert(0 <= from && from < n);\n        assert(0 <= to && to\
    \ < n);\n        assert(cost >= 0);\n        g[from].emplace_back(to, cost);\n\
    \    }\n\n    void build(int _s) {\n        s = _s;\n        std::priority_queue<std::pair<Cost,\
    \ int>,\n                            std::vector<std::pair<Cost, int>>,\n    \
    \                        std::greater<std::pair<Cost, int>>>\n            q;\n\
    \        q.emplace(0, s);\n        _dist[s] = 0;\n        _trace[s] = s;\n   \
    \     while (!q.empty()) {\n            auto [d, v] = q.top();\n            q.pop();\n\
    \            if (_dist[v] != d) {\n                continue;\n            }\n\
    \            for (auto [nv, c] : g[v]) {\n                if (_dist[v] + c < _dist[nv])\
    \ {\n                    _dist[nv] = _dist[v] + c;\n                    _trace[nv]\
    \ = v;\n                    q.emplace(_dist[nv], nv);\n                }\n   \
    \         }\n        }\n    }\n\n    const Cost dist(int u) const { return _dist[u];\
    \ }\n    std::vector<Cost> dists() const { return _dist; }\n    std::vector<int>\
    \ traces() const { return _trace; }\n\n    std::vector<int> shortest_path(int\
    \ to) const {\n        assert(0 <= to && to < n);\n        assert(_dist[to] <\
    \ COST_INF);\n\n        int cur = to;\n        std::vector<int> path;\n      \
    \  while (cur != _trace[cur]) {\n            path.emplace_back(cur);\n       \
    \     cur = _trace[cur];\n        }\n        path.emplace_back(s);\n        std::reverse(path.begin(),\
    \ path.end());\n\n        return path;\n    }\n};\n};  // namespace kyopro\n\n\
    /**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @bug \u6700\u77ED\
    \u8DDD\u96E2\u304C10^18\u3092\u8D85\u3048\u305F\u308A\u3059\u308B\u5834\u5408\u306F\
    \u30D0\u30B0\u308B\n * @todo \u4E0A\u306E\u3084\u3064\u3092\u76F4\u3059\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <numeric>\n#include <queue>\n#include <utility>\n#include <vector>\n\n\
    namespace kyopro {\n\ntemplate<typename Cost>\nclass dijkstra {\n    std::vector<Cost>\
    \ _dist;\n    std::vector<int> _trace;\n    const int n;\n    int s;\n\n    struct\
    \ edge {\n        const int to;\n        const Cost cost;\n        constexpr edge(int\
    \ to, Cost cost) noexcept : to(to), cost(cost) {}\n    };\n\n    std::vector<std::vector<edge>>\
    \ g;\n\npublic:\n    static constexpr Cost COST_INF = std::numeric_limits<Cost>::max()\
    \ / 2;\n\n    dijkstra(int n) : n(n), g(n), _trace(n, -1), _dist(n, COST_INF)\
    \ {}\n    dijkstra(const std::vector<std::vector<edge>>& g)\n        : n(g.size()),\
    \ g(g), _trace(g.size(), -1), _dist(g.size(), COST_INF){}\n\n    void add_edge(int\
    \ from, int to, Cost cost) {\n        assert(0 <= from && from < n);\n       \
    \ assert(0 <= to && to < n);\n        assert(cost >= 0);\n        g[from].emplace_back(to,\
    \ cost);\n    }\n\n    void build(int _s) {\n        s = _s;\n        std::priority_queue<std::pair<Cost,\
    \ int>,\n                            std::vector<std::pair<Cost, int>>,\n    \
    \                        std::greater<std::pair<Cost, int>>>\n            q;\n\
    \        q.emplace(0, s);\n        _dist[s] = 0;\n        _trace[s] = s;\n   \
    \     while (!q.empty()) {\n            auto [d, v] = q.top();\n            q.pop();\n\
    \            if (_dist[v] != d) {\n                continue;\n            }\n\
    \            for (auto [nv, c] : g[v]) {\n                if (_dist[v] + c < _dist[nv])\
    \ {\n                    _dist[nv] = _dist[v] + c;\n                    _trace[nv]\
    \ = v;\n                    q.emplace(_dist[nv], nv);\n                }\n   \
    \         }\n        }\n    }\n\n    const Cost dist(int u) const { return _dist[u];\
    \ }\n    std::vector<Cost> dists() const { return _dist; }\n    std::vector<int>\
    \ traces() const { return _trace; }\n\n    std::vector<int> shortest_path(int\
    \ to) const {\n        assert(0 <= to && to < n);\n        assert(_dist[to] <\
    \ COST_INF);\n\n        int cur = to;\n        std::vector<int> path;\n      \
    \  while (cur != _trace[cur]) {\n            path.emplace_back(cur);\n       \
    \     cur = _trace[cur];\n        }\n        path.emplace_back(s);\n        std::reverse(path.begin(),\
    \ path.end());\n\n        return path;\n    }\n};\n};  // namespace kyopro\n\n\
    /**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @bug \u6700\u77ED\
    \u8DDD\u96E2\u304C10^18\u3092\u8D85\u3048\u305F\u308A\u3059\u308B\u5834\u5408\u306F\
    \u30D0\u30B0\u308B\n * @todo \u4E0A\u306E\u3084\u3064\u3092\u76F4\u3059\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-10-26 14:56:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/GRL/1_A.test.cpp
  - test/yosupo_judge/tree/Tree_Diameter.test.cpp
  - test/yosupo_judge/graph/Shortest_Path.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---
