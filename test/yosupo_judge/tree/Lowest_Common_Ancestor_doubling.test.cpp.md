---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: fastIO
  - icon: ':heavy_check_mark:'
    path: src/tree/doubling.hpp
    title: "\u6728\u306E\u30C0\u30D6\u30EA\u30F3\u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#line 2 \"src/stream.hpp\"\
    \n#include <ctype.h>\n#include <stdio.h>\n#include <string>\nnamespace kyopro\
    \ {\n/**\n * \u6587\u5B57\u30921\u500B\u8AAD\u307F\u8FBC\u3080\n */\ninline char\
    \ readchar() {\n    char c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    \    return c;\n}\n/**\n *  \u6574\u6570\u306E\u5165\u51FA\u529B\n */\ntemplate\
    \ <typename T> constexpr inline void readint(T& a) {\n    a = 0;\n    bool is_negative\
    \ = false;\n    char c = getchar_unlocked();\n    while (isspace(c)) {\n     \
    \   c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true, c =\
    \ getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 * a + (c - '0');\n\
    \        c = getchar_unlocked();\n    }\n    if (is_negative) a *= -1;\n}\ntemplate\
    \ <typename Head, typename... Tail>\nconstexpr inline void readint(Head& head,\
    \ Tail&... tail) {\n    readint(head);\n    readint(tail...);\n}\n\ntemplate <typename\
    \ T> void write_int(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n  \
    \      putchar_unlocked('\\n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now]\
    \ = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T> constexpr inline void putint(T a) {\n    if (!a) {\n\
    \        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n        return;\n\
    \    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int\
    \ now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n       \
    \ a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n    putchar_unlocked('\\\
    n');\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void putint(Head\
    \ head, Tail... tail) {\n    putint(head);\n    putint(tail...);\n}\n\n/**\n *\
    \ \u6587\u5B57\u5217\u306E\u5165\u51FA\u529B\n */\n\ninline void readstr(std::string&\
    \ str) {\n    char c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    \    while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\n\ninline void readstr(std::string& str,std::string& tail...) {\n  \
    \  readstr(str);\n    readstr(tail);\n}\ninline void putstr(const std::string&\
    \ str) {\n    for (auto c : str) {\n        putchar_unlocked(c);\n    }\n    putchar_unlocked('\\\
    n');\n}\ninline void putstr(const std::string& str, const std::string& tail...)\
    \ {\n    putstr(str);\n    putstr(tail);\n}\n};  // namespace kyopro\n\n/**\n\
    \ * @brief fastIO\n */\n#line 2 \"src/tree/doubling.hpp\"\n#include <cassert>\n\
    #include <vector>\n\n/**\n * @brief \u6728\u306E\u30C0\u30D6\u30EA\u30F3\u30B0\
    \n */\nnamespace kyopro {\nclass doubling {\n    struct edge {\n        int to;\n\
    \        int cost;\n\n        constexpr explicit edge() : to(0), cost(0) {}\n\
    \        constexpr explicit edge(int to, int cost) : to(to), cost(cost) {}\n \
    \   };\n    const int n;\n    static constexpr int lg = 21;\n    std::vector<std::vector<edge>>\
    \ g;\n    std::vector<int> parent[lg];\n    std::vector<long long> _dist;\n  \
    \  std::vector<int> _depth;\n\npublic:\n    explicit doubling(int n) : n(n), g(n),\
    \ _dist(n, -1), _depth(n) {\n        std::fill(parent, parent + lg, std::vector<int>(n));\n\
    \    }\n    void add_edge(int a, int b, int c = 1) {\n        g[a].emplace_back(b,\
    \ 1);\n        g[b].emplace_back(a, 1);\n    }\n    void build(int root = 0) {\n\
    \        std::vector<int> st;\n        st.reserve(n);\n\n        st.emplace_back(root);\n\
    \        _dist[root] = 0, _depth[root] = 0, parent[0][root] = root;\n        while\
    \ (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \n            for (auto [nv, c] : g[v]) {\n                if (_dist[nv] != -1)\
    \ continue;\n                _dist[nv] = _dist[v] + c;\n                _depth[nv]\
    \ = _depth[v] + 1;\n                parent[0][nv] = v;\n\n                st.emplace_back(nv);\n\
    \            }\n        }\n\n        for (int i = 0; i < lg; ++i) {\n        \
    \    for (int v = 0; v < n; ++v) {\n                parent[i + 1][v] = parent[i][parent[i][v]];\n\
    \            }\n        }\n    }\n\n    int level_ancestor(int v, const int k)\
    \ const {\n        if (_depth[v] < k) return -1;\n\n        for (int i = 0; i\
    \ < lg; ++i) {\n            if (k >> i & 1) {\n                v = parent[i][v];\n\
    \            }\n        }\n        return v;\n    }\n\n    long long dist(int\
    \ v) const { return _dist[v]; }\n    long long dist(int u, int v) const {\n  \
    \      return _dist[u] + _dist[v] - 2 * _dist[lca(u, v)];\n    }\n    int depth(int\
    \ v) const { return _depth[v]; }\n    int unweighted_dist(int u, int v) const\
    \ {\n        return _depth[u] + _depth[v] - 2 * _depth[lca(u, v)];\n    }\n  \
    \  int lca(int a, int b) const {\n        if (_depth[a] > _depth[b]) {\n     \
    \       std::swap(a, b);\n        }\n        if (_depth[a] != _depth[b]) {\n \
    \           b = level_ancestor(b, _depth[b] - _depth[a]);\n        }\n       \
    \ if (a == b) return a;\n        for (int k = lg - 1; k >= 0; --k) {\n       \
    \     if (parent[k][a] != parent[k][b]) {\n                a = parent[k][a];\n\
    \                b = parent[k][b];\n            }\n        }\n        return parent[0][a];\n\
    \    }\n\n    int jump(const int from, const int to, const int k) const {\n  \
    \      int p = lca(from, to);\n        int d1 = _depth[from] - _depth[p];\n  \
    \      int d2 = _depth[to] - _depth[p];\n\n        if (d1 + d2 < k) {\n      \
    \      return -1;\n        }\n\n        if (d1 >= k) {\n            return level_ancestor(from,\
    \ k);\n        } else {\n            return level_ancestor(to, d1 + d2 - k);\n\
    \        }\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/tree/doubling.md\n\
    \ */\n#line 4 \"test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp\"\
    \nusing namespace std;\nint main() {\n    int n, q;\n    kyopro::readint(n, q);\n\
    \    kyopro::doubling g(n);\n    for (int i = 1; i < n; ++i) {\n        int p;\n\
    \        kyopro::readint(p);\n        g.add_edge(p, i);\n    }\n    g.build();\n\
    \    while (q--) {\n        int a, b;\n        kyopro::readint(a, b);\n      \
    \  kyopro::putint(g.lca(a, b));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../../../src/stream.hpp\"\
    \n#include \"../../../src/tree/doubling.hpp\"\nusing namespace std;\nint main()\
    \ {\n    int n, q;\n    kyopro::readint(n, q);\n    kyopro::doubling g(n);\n \
    \   for (int i = 1; i < n; ++i) {\n        int p;\n        kyopro::readint(p);\n\
    \        g.add_edge(p, i);\n    }\n    g.build();\n    while (q--) {\n       \
    \ int a, b;\n        kyopro::readint(a, b);\n        kyopro::putint(g.lca(a, b));\n\
    \    }\n}"
  dependsOn:
  - src/stream.hpp
  - src/tree/doubling.hpp
  isVerificationFile: true
  path: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 14:41:52+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
- /verify/test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp.html
title: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
---
