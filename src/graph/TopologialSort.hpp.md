---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/TopologialSort.md
    document_title: Topologial Sort
    links: []
  bundledCode: "#line 2 \"src/graph/TopologialSort.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace kyopro {\n\n/**\n * @brief Topologial Sort\n * @returns\
    \ (\u30BD\u30FC\u30C8\u6E08\u307F\u306E\u9802\u70B9\u5217, \u5143\u306E\u30B0\u30E9\
    \u30D5\u304CDAG\u3060\u3063\u305F\u304B?)\n */\nstd::pair<std::vector<int>, bool>\
    \ topological_sort(\n    const std::vector<std::vector<int>>& g) {\n    int n\
    \ = g.size();\n    std::vector<bool> vis(n, false), finished(n, false);\n    std::vector<int>\
    \ res;\n\n    auto dfs = [&](const auto& f, int v) -> bool {\n        vis[v] =\
    \ true;\n        for (auto nex : g[v]) {\n            if (vis[nex]) {\n      \
    \          if (!finished[nex]) {\n                    return false;\n        \
    \        }\n                continue;\n            }\n            if (!f(f, nex))\
    \ {\n                return false;\n            }\n        }\n\n        finished[v]\
    \ = true;\n        res.push_back(v);\n\n        return true;\n    };\n    for\
    \ (int v = 0; v < n; v++) {\n        if (vis[v]) continue;\n        if (!dfs(dfs,\
    \ v)) {\n            return std::pair(std::vector<int>(), false);\n        }\n\
    \    }\n    std::reverse(res.begin(), res.end());\n    return std::pair(res, true);\n\
    }\n\n};  // namespace kyopro\n\n/**\n * @docs docs/graph/TopologialSort.md\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace kyopro\
    \ {\n\n/**\n * @brief Topologial Sort\n * @returns (\u30BD\u30FC\u30C8\u6E08\u307F\
    \u306E\u9802\u70B9\u5217, \u5143\u306E\u30B0\u30E9\u30D5\u304CDAG\u3060\u3063\u305F\
    \u304B?)\n */\nstd::pair<std::vector<int>, bool> topological_sort(\n    const\
    \ std::vector<std::vector<int>>& g) {\n    int n = g.size();\n    std::vector<bool>\
    \ vis(n, false), finished(n, false);\n    std::vector<int> res;\n\n    auto dfs\
    \ = [&](const auto& f, int v) -> bool {\n        vis[v] = true;\n        for (auto\
    \ nex : g[v]) {\n            if (vis[nex]) {\n                if (!finished[nex])\
    \ {\n                    return false;\n                }\n                continue;\n\
    \            }\n            if (!f(f, nex)) {\n                return false;\n\
    \            }\n        }\n\n        finished[v] = true;\n        res.push_back(v);\n\
    \n        return true;\n    };\n    for (int v = 0; v < n; v++) {\n        if\
    \ (vis[v]) continue;\n        if (!dfs(dfs, v)) {\n            return std::pair(std::vector<int>(),\
    \ false);\n        }\n    }\n    std::reverse(res.begin(), res.end());\n    return\
    \ std::pair(res, true);\n}\n\n};  // namespace kyopro\n\n/**\n * @docs docs/graph/TopologialSort.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/TopologialSort.hpp
  requiredBy: []
  timestamp: '2023-09-06 15:12:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/TopologialSort.hpp
layout: document
redirect_from:
- /library/src/graph/TopologialSort.hpp
- /library/src/graph/TopologialSort.hpp.html
title: Topologial Sort
---
