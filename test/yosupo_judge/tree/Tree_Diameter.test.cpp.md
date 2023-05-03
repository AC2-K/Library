---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/yosupo_judge/tree/Tree_Diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n#line 2 \"src/graph/dijkstra.hpp\"\n#include\
    \ <queue>\n#line 4 \"src/graph/dijkstra.hpp\"\nnamespace kyopro {\nstruct edge\
    \ {\n    int to;\n    long long cost;\n    edge(int to, long long cost) : to(to),\
    \ cost(cost) {}\n};\n/// @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\nstd::pair<std::vector<long\
    \ long>, std::vector<int>> dijkstra(\n    int s,\n    const std::vector<std::vector<edge>>&\
    \ g) {\n    std::vector<long long> dist(g.size(), (long long)1e18);\n    std::vector<int>\
    \ pre(g.size(), -1);\n    std::priority_queue<std::pair<long long, int>,\n   \
    \                     std::vector<std::pair<long long, int>>,\n              \
    \          std::greater<std::pair<long long, int>>>\n        que;\n    que.emplace(0,\
    \ s);\n    dist[s] = 0;\n    pre[s] = s;\n    while (!que.empty()) {\n       \
    \ auto [d, v] = que.top();\n        que.pop();\n        if (dist[v] != d) {\n\
    \            continue;\n        }\n\n        for (const auto& [nv, c] : g[v])\
    \ {\n            if (dist[v] + c < dist[nv]) {\n                dist[nv] = dist[v]\
    \ + c;\n                pre[nv] = v;\n                que.emplace(dist[nv], nv);\n\
    \            }\n        }\n    }\n    return {dist, pre};\n}\n};  // namespace\
    \ kyopro\n#line 6 \"test/yosupo_judge/tree/Tree_Diameter.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    scanf(\"%d\", &n);\n    std::vector<std::vector<kyopro::edge>>\
    \ g(n);\n    for (int i = 0; i < n - 1; i++) {\n        int a, b, c;\n       \
    \ scanf(\"%d%d%d\", &a, &b, &c);\n        g[a].emplace_back(b, c);\n        g[b].emplace_back(a,\
    \ c);\n    }\n\n    auto dist = kyopro::dijkstra(0, g).first;\n    int v = std::max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n    dist = kyopro::dijkstra(v, g).first;\n    auto\
    \ it = std::max_element(dist.begin(), dist.end());\n    int u = it - dist.begin();\n\
    \    printf(\"%lld\\n\", *it);\n\n    int cur = u;\n    std::vector<int> ans;\n\
    \    while (cur != v) {\n        ans.emplace_back(cur);\n        for (auto& [p,\
    \ c] : g[cur]) {\n            if (dist[p] + c == dist[cur]) {\n              \
    \  cur = p;\n                break;\n            }\n        }\n    }\n    ans.emplace_back(v);\n\
    \    printf(\"%d\\n\", (int)ans.size());\n    for (auto& k : ans) printf(\"%d\
    \ \", k);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\
    \ <algorithm>\n#include <iostream>\n#include <vector>\n#include \"../../../src/graph/dijkstra.hpp\"\
    \n\nint main() {\n    int n;\n    scanf(\"%d\", &n);\n    std::vector<std::vector<kyopro::edge>>\
    \ g(n);\n    for (int i = 0; i < n - 1; i++) {\n        int a, b, c;\n       \
    \ scanf(\"%d%d%d\", &a, &b, &c);\n        g[a].emplace_back(b, c);\n        g[b].emplace_back(a,\
    \ c);\n    }\n\n    auto dist = kyopro::dijkstra(0, g).first;\n    int v = std::max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n    dist = kyopro::dijkstra(v, g).first;\n    auto\
    \ it = std::max_element(dist.begin(), dist.end());\n    int u = it - dist.begin();\n\
    \    printf(\"%lld\\n\", *it);\n\n    int cur = u;\n    std::vector<int> ans;\n\
    \    while (cur != v) {\n        ans.emplace_back(cur);\n        for (auto& [p,\
    \ c] : g[cur]) {\n            if (dist[p] + c == dist[cur]) {\n              \
    \  cur = p;\n                break;\n            }\n        }\n    }\n    ans.emplace_back(v);\n\
    \    printf(\"%d\\n\", (int)ans.size());\n    for (auto& k : ans) printf(\"%d\
    \ \", k);\n}"
  dependsOn:
  - src/graph/dijkstra.hpp
  isVerificationFile: true
  path: test/yosupo_judge/tree/Tree_Diameter.test.cpp
  requiredBy: []
  timestamp: '2023-05-03 22:08:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Tree_Diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Tree_Diameter.test.cpp
- /verify/test/yosupo_judge/tree/Tree_Diameter.test.cpp.html
title: test/yosupo_judge/tree/Tree_Diameter.test.cpp
---
