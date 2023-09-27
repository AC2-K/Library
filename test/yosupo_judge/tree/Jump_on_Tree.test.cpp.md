---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/stream.hpp
    title: fastIO
  - icon: ':x:'
    path: src/tree/doubling.hpp
    title: "\u6728\u306E\u30C0\u30D6\u30EA\u30F3\u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"test/yosupo_judge/tree/Jump_on_Tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n#line 2 \"src/stream.hpp\"\
    \n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n#line 2 \"src/internal/type_traits.hpp\"\
    \n#include <iostream>\n#include <limits>\n#include <numeric>\n#include <typeinfo>\n\
    \nnamespace kyopro {\nnamespace internal {\ntemplate <typename... Args> struct\
    \ first_enabled {};\n\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
    \ T>, Args...> {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt> struct int_least\
    \ {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, std::int8_t>,\n                                 std::enable_if<dgt <=\
    \ 16, std::int16_t>,\n                                 std::enable_if<dgt <= 32,\
    \ std::int32_t>,\n                                 std::enable_if<dgt <= 64, std::int64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __int128_t> >;\n\
    };\ntemplate <int dgt> struct uint_least {\n    static_assert(dgt <= 128);\n \
    \   using type = first_enabled_t<std::enable_if<dgt <= 8, std::uint8_t>,\n   \
    \                              std::enable_if<dgt <= 16, std::uint16_t>,\n   \
    \                              std::enable_if<dgt <= 32, std::uint32_t>,\n   \
    \                              std::enable_if<dgt <= 64, std::uint64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\
    \ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\ntemplate\
    \ <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename\
    \ T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\n#line 6 \"src/stream.hpp\"\n\nnamespace kyopro {\n// read\nvoid single_read(char&\
    \ c) {\n    c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\nvoid single_read(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_read(T& a) {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\nvoid single_read(std::string& str) {\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n    while (!isspace(c)) {\n \
    \       str += c;\n        c = getchar_unlocked();\n    }\n}\ntemplate<typename\
    \ T>\nvoid read(T& x) {single_read(x);}\ntemplate <typename Head, typename...\
    \ Tail>\nvoid read(Head& head, Tail&... tail) {\n    single_read(head), read(tail...);\n\
    }\n\n// write\nvoid single_write(char c) { putchar_unlocked(c); }\ntemplate <typename\
    \ T, internal::is_integral_t<T>* = nullptr>\nvoid single_write(T a) {\n    if\
    \ (!a) {\n        putchar_unlocked('0');\n        return;\n    }\n    if (a <\
    \ 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int now = 37;\n   \
    \ while (a) {\n        s[--now] = (char)'0' + a % 10;\n        a /= 10;\n    }\n\
    \    while (now < 37) putchar_unlocked(s[now++]);\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_write(T a) {\n    single_write(a.val());\n}\n\nvoid\
    \ single_write(const std::string& str) {\n    for (auto c : str) {\n        putchar_unlocked(c);\n\
    \    }\n}\n\ntemplate<typename T>\nvoid write(T x) { single_write(x); }\ntemplate\
    \ <typename Head, typename... Tail> void write(Head head, Tail... tail) {\n  \
    \  single_write(head);\n    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate\
    \ <typename... Args> void put(Args... x) {\n    write(x...);\n    putchar_unlocked('\\\
    n');\n}\n};  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 2 \"src/tree/doubling.hpp\"\
    \n#include <cassert>\n#include <vector>\n\n/**\n * @brief \u6728\u306E\u30C0\u30D6\
    \u30EA\u30F3\u30B0\n */\nnamespace kyopro {\nclass doubling {\n    struct edge\
    \ {\n        int to;\n        int cost;\n\n        constexpr explicit edge() :\
    \ to(0), cost(0) {}\n        constexpr explicit edge(int to, int cost) : to(to),\
    \ cost(cost) {}\n    };\n    const int n;\n    static constexpr int lg = 21;\n\
    \    std::vector<std::vector<edge>> g;\n    std::vector<int> parent[lg];\n   \
    \ std::vector<long long> _dist;\n    std::vector<int> _depth;\n\npublic:\n   \
    \ explicit doubling(int n) : n(n), g(n), _dist(n, -1), _depth(n) {\n        std::fill(parent,\
    \ parent + lg, std::vector<int>(n));\n    }\n    const std::vector<edge>& to(int\
    \ v) const { return g[v]; }\n    void add_edge(int a, int b, int c = 1) {\n  \
    \      g[a].emplace_back(b, c);\n        g[b].emplace_back(a, c);\n    }\n   \
    \ void build(int root = 0) {\n        std::vector<int> st;\n        st.reserve(n);\n\
    \n        st.emplace_back(root);\n        _dist[root] = 0, _depth[root] = 0, parent[0][root]\
    \ = root;\n        while (!st.empty()) {\n            int v = st.back();\n   \
    \         st.pop_back();\n\n            for (auto [nv, c] : g[v]) {\n        \
    \        if (_dist[nv] != -1) continue;\n                _dist[nv] = _dist[v]\
    \ + c;\n                _depth[nv] = _depth[v] + 1;\n                parent[0][nv]\
    \ = v;\n\n                st.emplace_back(nv);\n            }\n        }\n\n \
    \       for (int i = 0; i < lg; ++i) {\n            for (int v = 0; v < n; ++v)\
    \ {\n                parent[i + 1][v] = parent[i][parent[i][v]];\n           \
    \ }\n        }\n    }\n    \n    int level_ancestor(int v, const int k) const\
    \ {\n        if (_depth[v] < k) return -1;\n\n        for (int i = 0; i < lg;\
    \ ++i) {\n            if (k >> i & 1) {\n                v = parent[i][v];\n \
    \           }\n        }\n        return v;\n    }\n\n    long long dist(int v)\
    \ const { return _dist[v]; }\n    long long dist(int u, int v) const {\n     \
    \   return dist(u) + dist(v) - 2 * dist(lca(u, v));\n    }\n    int depth(int\
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
    \ */\n#line 4 \"test/yosupo_judge/tree/Jump_on_Tree.test.cpp\"\nint main() {\n\
    \    int n, q;\n    kyopro::read(n, q);\n    kyopro::doubling g(n);\n    for (int\
    \ i = 0; i < n - 1; ++i) {\n        int a, b;\n        kyopro::read(a, b);\n \
    \       g.add_edge(a, b);\n    }\n    g.build();\n\n    while (q--) {\n      \
    \  int s, t, i;\n        kyopro::read(s, t, i);\n        kyopro::put(g.jump(s,\
    \ t, i));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n#include\
    \ \"../../../src/stream.hpp\"\n#include \"../../../src/tree/doubling.hpp\"\nint\
    \ main() {\n    int n, q;\n    kyopro::read(n, q);\n    kyopro::doubling g(n);\n\
    \    for (int i = 0; i < n - 1; ++i) {\n        int a, b;\n        kyopro::read(a,\
    \ b);\n        g.add_edge(a, b);\n    }\n    g.build();\n\n    while (q--) {\n\
    \        int s, t, i;\n        kyopro::read(s, t, i);\n        kyopro::put(g.jump(s,\
    \ t, i));\n    }\n}"
  dependsOn:
  - src/stream.hpp
  - src/internal/type_traits.hpp
  - src/tree/doubling.hpp
  isVerificationFile: true
  path: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
  requiredBy: []
  timestamp: '2023-09-27 10:21:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Jump_on_Tree.test.cpp
- /verify/test/yosupo_judge/tree/Jump_on_Tree.test.cpp.html
title: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
---
