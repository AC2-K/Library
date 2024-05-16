---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Topologial Sort
    links: []
  bundledCode: "#line 2 \"src/graph/topological_sort.hpp\"\n#include <algorithm>\n\
    #include <vector>\n\nnamespace kyopro {\ntemplate <typename Graph>\nstd::pair<std::vector<int>,\
    \ bool> topological_sort(const Graph& g) {\n    int n = g.size();\n    std::vector<bool>\
    \ vis(n, false), finished(n, false);\n    std::vector<int> res;\n\n    auto dfs\
    \ = [&](const auto& f, int v) -> bool {\n        vis[v] = true;\n        for (auto\
    \ nex : g[v]) {\n            if (vis[nex]) {\n                if (!finished[nex])\
    \ {\n                    return false;\n                }\n                continue;\n\
    \            }\n            if (!f(f, nex)) {\n                return false;\n\
    \            }\n        }\n\n        finished[v] = true;\n        res.push_back(v);\n\
    \n        return true;\n    };\n    for (int v = 0; v < n; v++) {\n        if\
    \ (vis[v]) continue;\n        if (!dfs(dfs, v)) {\n            return std::pair(std::vector<int>(),\
    \ false);\n        }\n    }\n    std::reverse(res.begin(), res.end());\n    return\
    \ std::pair(res, true);\n}\n\n};  // namespace kyopro\n\n/**\n * @brief Topologial\
    \ Sort\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace kyopro\
    \ {\ntemplate <typename Graph>\nstd::pair<std::vector<int>, bool> topological_sort(const\
    \ Graph& g) {\n    int n = g.size();\n    std::vector<bool> vis(n, false), finished(n,\
    \ false);\n    std::vector<int> res;\n\n    auto dfs = [&](const auto& f, int\
    \ v) -> bool {\n        vis[v] = true;\n        for (auto nex : g[v]) {\n    \
    \        if (vis[nex]) {\n                if (!finished[nex]) {\n            \
    \        return false;\n                }\n                continue;\n       \
    \     }\n            if (!f(f, nex)) {\n                return false;\n      \
    \      }\n        }\n\n        finished[v] = true;\n        res.push_back(v);\n\
    \n        return true;\n    };\n    for (int v = 0; v < n; v++) {\n        if\
    \ (vis[v]) continue;\n        if (!dfs(dfs, v)) {\n            return std::pair(std::vector<int>(),\
    \ false);\n        }\n    }\n    std::reverse(res.begin(), res.end());\n    return\
    \ std::pair(res, true);\n}\n\n};  // namespace kyopro\n\n/**\n * @brief Topologial\
    \ Sort\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/src/graph/topological_sort.hpp
- /library/src/graph/topological_sort.hpp.html
title: Topologial Sort
---
