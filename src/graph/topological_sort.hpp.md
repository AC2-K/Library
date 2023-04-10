---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/topological_sort.hpp\"\n#include <algorithm>\n\
    #include <vector>\n\nnamespace kyopro {\nvoid topological_sort(const std::vector<std::vector<int>>&\
    \ g,\n                      std::vector<int>& res,\n                      bool&\
    \ has_cycle) {\n    has_cycle = false;\n    int n = g.size();\n    std::vector<bool>\
    \ vis(n, false), finished(n, false);\n\n    auto dfs = [&](auto f, int v) -> bool\
    \ {\n        vis[v] = true;\n        for (const auto& nex : g[v]) {\n        \
    \    if (vis[nex]) {\n                if (!finished[nex]) {\n                \
    \    return false;\n                }\n                continue;\n           \
    \ }\n            if (!f(f, nex)) {\n                return false;\n          \
    \  }\n        }\n\n        finished[v] = true;\n        res.push_back(v);\n\n\
    \        return true;\n    };\n    for (int v = 0; v < n; v++) {\n        if (vis[v])\
    \ continue;\n        if (!dfs(dfs, v)) {\n            has_cycle = true;\n    \
    \        return;\n        }\n    }\n    std::reverse(res.begin(), res.end());\n\
    }\n\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace kyopro\
    \ {\nvoid topological_sort(const std::vector<std::vector<int>>& g,\n         \
    \             std::vector<int>& res,\n                      bool& has_cycle) {\n\
    \    has_cycle = false;\n    int n = g.size();\n    std::vector<bool> vis(n, false),\
    \ finished(n, false);\n\n    auto dfs = [&](auto f, int v) -> bool {\n       \
    \ vis[v] = true;\n        for (const auto& nex : g[v]) {\n            if (vis[nex])\
    \ {\n                if (!finished[nex]) {\n                    return false;\n\
    \                }\n                continue;\n            }\n            if (!f(f,\
    \ nex)) {\n                return false;\n            }\n        }\n\n       \
    \ finished[v] = true;\n        res.push_back(v);\n\n        return true;\n   \
    \ };\n    for (int v = 0; v < n; v++) {\n        if (vis[v]) continue;\n     \
    \   if (!dfs(dfs, v)) {\n            has_cycle = true;\n            return;\n\
    \        }\n    }\n    std::reverse(res.begin(), res.end());\n}\n\n};  // namespace\
    \ kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2023-04-09 21:22:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/src/graph/topological_sort.hpp
- /library/src/graph/topological_sort.hpp.html
title: src/graph/topological_sort.hpp
---
