---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"src/graph/topological_sort.hpp\"\n#include <algorithm>\n\
    #include <vector>\n\nnamespace kyopro {\n/// @brief \u30C8\u30DD\u30ED\u30B8\u30AB\
    \u30EB\u30BD\u30FC\u30C8\n/// @param g \u30BD\u30FC\u30C8\u3057\u305F\u3044\u30B0\
    \u30E9\u30D5(\u96A3\u63A5\u30EA\u30B9\u30C8\u5F62\u5F0F)\n/// @param res \u7D50\
    \u679C\u3092\u683C\u7D0D\u3059\u308Bvector\n/// @param has_cycle \u30B5\u30A4\u30AF\
    \u30EB\u3092\u542B\u3093\u3067\u3044\u305F\u3089\u3001true\u306B\u3057\u3066\u7D42\
    \u4E86\u3059\u308B\nvoid topological_sort(const std::vector<std::vector<int>>&\
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
    \ kyopro\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace kyopro\
    \ {\n/// @brief \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n/// @param\
    \ g \u30BD\u30FC\u30C8\u3057\u305F\u3044\u30B0\u30E9\u30D5(\u96A3\u63A5\u30EA\u30B9\
    \u30C8\u5F62\u5F0F)\n/// @param res \u7D50\u679C\u3092\u683C\u7D0D\u3059\u308B\
    vector\n/// @param has_cycle \u30B5\u30A4\u30AF\u30EB\u3092\u542B\u3093\u3067\u3044\
    \u305F\u3089\u3001true\u306B\u3057\u3066\u7D42\u4E86\u3059\u308B\nvoid topological_sort(const\
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
    }\n\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2023-05-01 12:49:55+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/src/graph/topological_sort.hpp
- /library/src/graph/topological_sort.hpp.html
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---
