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
    \ <vector>\n\nnamespace kyopro {\n\n/**\n * @brief Topologial Sort\n * @param\
    \ has_cycle\n * \u6709\u5411\u30B5\u30A4\u30AF\u30EB\u3092\u542B\u3080\u5834\u5408\
    \u306F\u3001has_cycle\u3092true\u306B\u3057\u3066\u304B\u3089\u7D42\u4E86\u3059\
    \u308B\u3002\n */\nvoid topological_sort(const std::vector<std::vector<int>>&\
    \ g,\n                      std::vector<int>& res,\n                      bool&\
    \ has_cycle) {\n    has_cycle = false;\n    int n = g.size();\n    std::vector<bool>\
    \ vis(n, false), finished(n, false);\n\n    auto dfs = [&](auto f, int v) -> bool\
    \ {\n        vis[v] = true;\n        for (auto nex : g[v]) {\n            if (vis[nex])\
    \ {\n                if (!finished[nex]) {\n                    return false;\n\
    \                }\n                continue;\n            }\n            if (!f(f,\
    \ nex)) {\n                return false;\n            }\n        }\n\n       \
    \ finished[v] = true;\n        res.push_back(v);\n\n        return true;\n   \
    \ };\n    for (int v = 0; v < n; v++) {\n        if (vis[v]) continue;\n     \
    \   if (!dfs(dfs, v)) {\n            has_cycle = true;\n            return;\n\
    \        }\n    }\n    std::reverse(res.begin(), res.end());\n}\n\n};  // namespace\
    \ kyopro\n\n/**\n * @docs docs/graph/TopologialSort.md\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace kyopro\
    \ {\n\n/**\n * @brief Topologial Sort\n * @param has_cycle\n * \u6709\u5411\u30B5\
    \u30A4\u30AF\u30EB\u3092\u542B\u3080\u5834\u5408\u306F\u3001has_cycle\u3092true\u306B\
    \u3057\u3066\u304B\u3089\u7D42\u4E86\u3059\u308B\u3002\n */\nvoid topological_sort(const\
    \ std::vector<std::vector<int>>& g,\n                      std::vector<int>& res,\n\
    \                      bool& has_cycle) {\n    has_cycle = false;\n    int n =\
    \ g.size();\n    std::vector<bool> vis(n, false), finished(n, false);\n\n    auto\
    \ dfs = [&](auto f, int v) -> bool {\n        vis[v] = true;\n        for (auto\
    \ nex : g[v]) {\n            if (vis[nex]) {\n                if (!finished[nex])\
    \ {\n                    return false;\n                }\n                continue;\n\
    \            }\n            if (!f(f, nex)) {\n                return false;\n\
    \            }\n        }\n\n        finished[v] = true;\n        res.push_back(v);\n\
    \n        return true;\n    };\n    for (int v = 0; v < n; v++) {\n        if\
    \ (vis[v]) continue;\n        if (!dfs(dfs, v)) {\n            has_cycle = true;\n\
    \            return;\n        }\n    }\n    std::reverse(res.begin(), res.end());\n\
    }\n\n};  // namespace kyopro\n\n/**\n * @docs docs/graph/TopologialSort.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/TopologialSort.hpp
  requiredBy: []
  timestamp: '2023-05-15 08:00:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/TopologialSort.hpp
layout: document
redirect_from:
- /library/src/graph/TopologialSort.hpp
- /library/src/graph/TopologialSort.hpp.html
title: Topologial Sort
---
