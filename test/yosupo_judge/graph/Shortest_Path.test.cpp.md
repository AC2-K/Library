---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo_judge/graph/Shortest_Path.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include <algorithm>\n\
    #include <iostream>\n#line 2 \"src/graph/dijkstra.hpp\"\n#include <queue>\n#include\
    \ <vector>\nnamespace kyopro {\nstruct edge {\n    int to;\n    long long cost;\n\
    \    edge(int to, long long cost) : to(to), cost(cost) {}\n};\n/// @brief \u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\nstd::pair<std::vector<long long>, std::vector<int>>\
    \ dijkstra(\n    int s,\n    const std::vector<std::vector<edge>>& g) {\n    std::vector<long\
    \ long> dist(g.size(), (long long)1e18);\n    std::vector<int> pre(g.size(), -1);\n\
    \    std::priority_queue<std::pair<long long, int>,\n                        std::vector<std::pair<long\
    \ long, int>>,\n                        std::greater<std::pair<long long, int>>>\n\
    \        que;\n    que.emplace(0, s);\n    dist[s] = 0;\n    pre[s] = s;\n   \
    \ while (!que.empty()) {\n        auto [d, v] = que.top();\n        que.pop();\n\
    \        if (dist[v] != d) {\n            continue;\n        }\n\n        for\
    \ (const auto& [nv, c] : g[v]) {\n            if (dist[v] + c < dist[nv]) {\n\
    \                dist[nv] = dist[v] + c;\n                pre[nv] = v;\n     \
    \           que.emplace(dist[nv], nv);\n            }\n        }\n    }\n    return\
    \ {dist, pre};\n}\n};  // namespace kyopro\n#line 5 \"test/yosupo_judge/graph/Shortest_Path.test.cpp\"\
    \nint main() {\n    int n, m, s, t;\n    scanf(\"%d%d%d%d\", &n, &m, &s, &t);\n\
    \    std::vector<std::vector<kyopro::edge>> g(n);\n    for (int i = 0; i < m;\
    \ i++) {\n        int a, b, c;\n        scanf(\"%d%d%d\", &a, &b, &c);\n     \
    \   g[a].emplace_back(b, c);\n    }\n    auto [dist, trace] = dijkstra(s, g);\n\
    \    if (dist[t] >= (long long)1e18) {\n        puts(\"-1\");\n        return\
    \ 0;\n    }\n\n    int cur = t;\n    std::vector<int> path;\n    while (cur !=\
    \ trace[cur]) {\n        path.emplace_back(cur);\n        cur = trace[cur];\n\
    \    }\n\n    path.emplace_back(cur);\n    printf(\"%lld %lld\\n\", dist[t], path.size()\
    \ - 1);\n    std::reverse(path.begin(), path.end());\n    for (int i = 1; i <\
    \ (int)path.size(); i++) {\n        printf(\"%d %d\\n\", path[i - 1], path[i]);\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ <algorithm>\n#include <iostream>\n#include \"../../../src/graph/dijkstra.hpp\"\
    \nint main() {\n    int n, m, s, t;\n    scanf(\"%d%d%d%d\", &n, &m, &s, &t);\n\
    \    std::vector<std::vector<kyopro::edge>> g(n);\n    for (int i = 0; i < m;\
    \ i++) {\n        int a, b, c;\n        scanf(\"%d%d%d\", &a, &b, &c);\n     \
    \   g[a].emplace_back(b, c);\n    }\n    auto [dist, trace] = dijkstra(s, g);\n\
    \    if (dist[t] >= (long long)1e18) {\n        puts(\"-1\");\n        return\
    \ 0;\n    }\n\n    int cur = t;\n    std::vector<int> path;\n    while (cur !=\
    \ trace[cur]) {\n        path.emplace_back(cur);\n        cur = trace[cur];\n\
    \    }\n\n    path.emplace_back(cur);\n    printf(\"%lld %lld\\n\", dist[t], path.size()\
    \ - 1);\n    std::reverse(path.begin(), path.end());\n    for (int i = 1; i <\
    \ (int)path.size(); i++) {\n        printf(\"%d %d\\n\", path[i - 1], path[i]);\n\
    \    }\n}"
  dependsOn:
  - src/graph/dijkstra.hpp
  isVerificationFile: true
  path: test/yosupo_judge/graph/Shortest_Path.test.cpp
  requiredBy: []
  timestamp: '2023-05-03 22:08:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/graph/Shortest_Path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp.html
title: test/yosupo_judge/graph/Shortest_Path.test.cpp
---
