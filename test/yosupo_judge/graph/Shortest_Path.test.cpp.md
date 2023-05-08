---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  - icon: ':question:'
    path: src/stream.hpp
    title: "\u5165\u51FA\u529B"
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
    #include <iostream>\n#line 3 \"src/graph/dijkstra.hpp\"\n#include <cassert>\n\
    #include <queue>\n#include <utility>\n#include <vector>\nnamespace kyopro {\n\n\
    /**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n*/\nclass dijkstra\
    \ {\n    std::vector<long long> dist;\n    std::vector<int> trace;\n    const\
    \ int n;\n    int s;\n    struct edge {\n        const int to;\n        const\
    \ long long cost;\n        constexpr edge(int to, long long cost) : to(to), cost(cost)\
    \ {}\n    };\n\npublic:\n    using graph = std::vector<std::vector<edge>>;\n\n\
    private:\n    graph g;\n\npublic:\n    dijkstra(int n) : n(n), g(n) {}\n    dijkstra(const\
    \ graph& g) : n(g.size()), g(g) {}\n    void add_edge(int from, int to, long long\
    \ cost) {\n        assert(0 <= from && from < n);\n        assert(0 <= to && to\
    \ < n);\n        assert(cost >= 0);\n        g[from].emplace_back(to, cost);\n\
    \    }\n    void build(int _s) {\n        assert(0 <= _s && _s < n);\n       \
    \ std::swap(s, _s);\n\n        trace.assign(n, -1), dist.assign(n, (long long)1e18);\n\
    \        std::priority_queue<std::pair<long long, int>,\n                    \
    \        std::vector<std::pair<long long, int>>,\n                           \
    \ std::greater<std::pair<long long, int>>>\n            que;\n        que.emplace(0,\
    \ s);\n        dist[s] = 0;\n        trace[s] = s;\n        while (!que.empty())\
    \ {\n            auto [d, v] = que.top();\n            que.pop();\n          \
    \  if (dist[v] != d) {\n                continue;\n            }\n\n         \
    \   for (auto [nv, c] : g[v]) {\n                if (dist[v] + c < dist[nv]) {\n\
    \                    dist[nv] = dist[v] + c;\n                    trace[nv] =\
    \ v;\n                    que.emplace(dist[nv], nv);\n                }\n    \
    \        }\n        }\n    }\n    \n    const std::vector<long long>& get_dist()\
    \ const { return dist; }\n    \n    std::pair<long long, std::vector<int>> shortest_path(int\
    \ to) {\n        assert(0 <= to && to < n);\n        if (dist[to] >= (long long)1e18)\
    \ return {};\n        int cur = to;\n        std::vector<int> path;\n        while\
    \ (cur != trace[cur]) {\n            path.emplace_back(cur);\n            cur\
    \ = trace[cur];\n        }\n        path.emplace_back(s);\n        std::reverse(path.begin(),\
    \ path.end());\n        return {dist[to], path};\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @docs docs/graph/dijkstra.md\n*/\n#line 2 \"src/stream.hpp\"\
    \n#include <stdio.h>\n#include <ctype.h>\nnamespace kyopro {\ntemplate <typename\
    \ T>\nconstexpr inline void readint(T& a) {\n    a = 0;\n    bool is_negative\
    \ = false;\n    char c = getchar_unlocked();\n    while (isspace(c)) {\n     \
    \   c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true, c =\
    \ getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 * a + (c - '0');\n\
    \        c = getchar_unlocked();\n    }\n    if (is_negative) a *= -1;\n}\ntemplate\
    \ <typename Head, typename... Tail>\nconstexpr inline void readint(Head& head,\
    \ Tail&... tail) {\n    readint(head);\n    readint(tail...);\n}\ntemplate <typename\
    \ T>\nconstexpr inline void putint(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n\
    \        putchar_unlocked('\\n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now]\
    \ = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    \    putchar_unlocked('\\n');\n}\ntemplate <typename Head, typename... Tail>\n\
    constexpr inline void putint(Head head, Tail... tail) {\n    putint(head);\n \
    \   putint(tail...);\n}\n\n};  // namespace kyopro\n\n\n/**\n * @brief \u5165\u51FA\
    \u529B\n*/\n#line 6 \"test/yosupo_judge/graph/Shortest_Path.test.cpp\"\nint main()\
    \ {\n    int n, m, s, t;\n    kyopro::readint(n, m, s, t);\n\n    kyopro::dijkstra\
    \ g(n);\n    for (int i = 0; i < m; i++) {\n        int a, b, c;\n        kyopro::readint(a,\
    \ b, c);\n        g.add_edge(a, b, c);\n    }\n\n    g.build(s);\n    auto [dist,\
    \ path] = g.shortest_path(t);\n    if (path.empty()) {\n        kyopro::putint(-1);\n\
    \        exit(0);\n    }\n    kyopro::putint(dist, path.size() - 1);\n    for\
    \ (int i = 1; i < (int)path.size(); i++) {\n        kyopro::putint(path[i - 1],\
    \ path[i]);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ <algorithm>\n#include <iostream>\n#include \"../../../src/graph/dijkstra.hpp\"\
    \n#include \"../../../src/stream.hpp\"\nint main() {\n    int n, m, s, t;\n  \
    \  kyopro::readint(n, m, s, t);\n\n    kyopro::dijkstra g(n);\n    for (int i\
    \ = 0; i < m; i++) {\n        int a, b, c;\n        kyopro::readint(a, b, c);\n\
    \        g.add_edge(a, b, c);\n    }\n\n    g.build(s);\n    auto [dist, path]\
    \ = g.shortest_path(t);\n    if (path.empty()) {\n        kyopro::putint(-1);\n\
    \        exit(0);\n    }\n    kyopro::putint(dist, path.size() - 1);\n    for\
    \ (int i = 1; i < (int)path.size(); i++) {\n        kyopro::putint(path[i - 1],\
    \ path[i]);\n    }\n}"
  dependsOn:
  - src/graph/dijkstra.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/graph/Shortest_Path.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 03:51:35+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/graph/Shortest_Path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp.html
title: test/yosupo_judge/graph/Shortest_Path.test.cpp
---
