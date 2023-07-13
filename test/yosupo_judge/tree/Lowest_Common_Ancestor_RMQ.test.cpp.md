---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/sparse_table.hpp
    title: SparseTable
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: fastIO
  - icon: ':heavy_check_mark:'
    path: src/tree/EulerTour.hpp
    title: Euler Tour
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
  bundledCode: "#line 1 \"test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <iostream>\n\
    #line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n\
    namespace kyopro {\n/**\n * \u6587\u5B57\u30921\u500B\u8AAD\u307F\u8FBC\u3080\n\
    \ */\ninline char readchar() {\n    char c = getchar_unlocked();\n    while (isspace(c))\
    \ c = getchar_unlocked();\n    return c;\n}\n/**\n *  \u6574\u6570\u306E\u5165\
    \u51FA\u529B\n */\ntemplate <typename T> constexpr inline void readint(T& a) {\n\
    \    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void readint(Head& head, Tail&... tail) {\n    readint(head);\n    readint(tail...);\n\
    }\n\ntemplate <typename T> void write_int(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n\
    \        putchar_unlocked('\\n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
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
    \ * @brief fastIO\n */\n#line 2 \"src/tree/EulerTour.hpp\"\n#include <utility>\n\
    #line 2 \"src/data-structure/sparse_table.hpp\"\n#include <numeric>\n#include\
    \ <vector>\nnamespace kyopro {\n\n/**\n * @brief SparseTable\n */\ntemplate <class\
    \ T, auto op> class sparse_table {\n    std::vector<T> vec;\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<int> look_up;\n\npublic:\n    constexpr explicit sparse_table(int\
    \ n) : vec(n) {}\n    constexpr explicit sparse_table(const std::vector<T>& vec)\
    \ : vec(vec) {\n        build();\n    }\n    void set(int p, const T& v) { vec[p]\
    \ = v; }\n    void build() {\n        int sz = vec.size();\n        int log =\
    \ 0;\n        while ((1 << log) <= sz) {\n            log++;\n        }\n    \
    \    table.assign(log, std::vector<T>(1 << log));\n        for (int i = 0; i <\
    \ sz; i++) {\n            table[0][i] = vec[i];\n        }\n        for (int i\
    \ = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <= (1 << log);\
    \ j++) {\n                table[i][j] =\n                    op(table[i - 1][j],\
    \ table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n        look_up.resize(sz\
    \ + 1);\n        for (int i = 2; i < (int)look_up.size(); i++) {\n           \
    \ look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n    T fold(int l, int\
    \ r) const {\n        int b = look_up[r - l];\n        return op(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs\
    \ docs/data-structure/sparse_table.md\n */\n#line 4 \"src/tree/EulerTour.hpp\"\
    \nnamespace kyopro {\n\n/**\n * @brief Euler Tour\n */\nclass EulerTour {\n  \
    \  int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> tour;\n\
    \    std::vector<int> in, out, depth;\n\n    struct get_min_pair {\n        using\
    \ value_t = std::pair<int, int>;\n        static value_t op(value_t x, value_t\
    \ y) { return std::min(x, y); }\n    };\n\n    sparse_table<get_min_pair::value_t,\
    \ get_min_pair::op> rmq;\n\npublic:\n    explicit EulerTour(int n)\n        :\
    \ n(n), g(n), in(n, -1), out(n, -1), depth(n, -1), rmq(2 * n - 1) {\n        tour.reserve(2\
    \ * n - 1);\n    }\n    void add_edge(int u, int v) {\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n    }\n    const std::vector<std::vector<int>>&\
    \ get_graph() const { return g; }\n    const std::vector<int>& get_tour() const\
    \ { return tour; }\n    int get_depth(int v) const { return depth[v]; }\n\n  \
    \  void build(int r = 0) {\n        auto dfs = [&](const auto& self, int v, int\
    \ p) -> void {\n            in[v] = tour.size();\n            tour.emplace_back(v);\n\
    \            for (auto nv : g[v]) {\n                if (nv != p) {\n        \
    \            depth[nv] = depth[v] + 1;\n                    self(self, nv, v);\n\
    \                    tour.emplace_back(v);\n                }\n            }\n\
    \            out[v] = tour.size() - 1;\n        };\n        dfs(dfs, r, -1);\n\
    \        for (int i = 0; i < (int)tour.size(); i++) {\n            rmq.set(i,\
    \ {depth[tour[i]], tour[i]});\n        }\n        rmq.build();\n    }\n\n    std::pair<int,\
    \ int> idx(int v) const { return {in[v], out[v]}; }\n    int lca(int v, int u)\
    \ const {\n        if (in[v] > in[u] + 1) {\n            std::swap(u, v);\n  \
    \      }\n        return rmq.fold(in[v], in[u] + 1).second;\n    }\n\n    int\
    \ dist(int v, int u) const {\n        int p = lca(v, u);\n        return depth[v]\
    \ + depth[u] - 2 * depth[p];\n    }\n\n    bool is_in_subtree(int par, int v)\
    \ const {\n        return (in[par] <= in[v] && out[v] <= out[par]);\n    }\n};\n\
    };  // namespace kyopro\n\n/**\n * @docs docs/tree/EulerTour.md\n */\n#line 6\
    \ \"test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp\"\nint main() {\n\
    \    int n, q;\n    kyopro::readint(n, q);\n    kyopro::EulerTour g(n);\n    for\
    \ (int i = 1; i < n; i++) {\n        int p;\n        kyopro::readint(p);\n   \
    \     g.add_edge(p, i);\n    }\n    g.build();\n    while (q--) {\n        int\
    \ u, v;\n        kyopro::readint(u, v);\n        kyopro::putint(g.lca(u, v));\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <iostream>\n\
    #include \"../../../src/stream.hpp\"\n#include \"../../../src/tree/EulerTour.hpp\"\
    \nint main() {\n    int n, q;\n    kyopro::readint(n, q);\n    kyopro::EulerTour\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        kyopro::readint(p);\n\
    \        g.add_edge(p, i);\n    }\n    g.build();\n    while (q--) {\n       \
    \ int u, v;\n        kyopro::readint(u, v);\n        kyopro::putint(g.lca(u, v));\n\
    \    }\n}"
  dependsOn:
  - src/stream.hpp
  - src/tree/EulerTour.hpp
  - src/data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 14:41:52+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp
- /verify/test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp.html
title: test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp
---
