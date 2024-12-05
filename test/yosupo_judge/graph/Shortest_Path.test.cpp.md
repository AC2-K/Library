---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: "Single Source Shortest Path(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
      )"
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  - icon: ':question:'
    path: src/stream.hpp
    title: "Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)"
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: Template
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
    #include <limits>\n#include <numeric>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\nnamespace kyopro {\n\ntemplate<typename Cost>\nclass dijkstra\
    \ {\n    std::vector<Cost> _dist;\n    std::vector<int> _trace;\n    const int\
    \ n;\n    int s;\n\n    struct edge {\n        const int to;\n        const Cost\
    \ cost;\n        constexpr edge(int to, Cost cost) noexcept : to(to), cost(cost)\
    \ {}\n    };\n\n    std::vector<std::vector<edge>> g;\n\npublic:\n    static constexpr\
    \ Cost COST_INF = std::numeric_limits<Cost>::max();\n\n    dijkstra(int n) : n(n),\
    \ g(n) {}\n    dijkstra(const std::vector<std::vector<edge>>& g) : g(g), n(g.size())\
    \ {}\n\n    void add_edge(int from, int to, Cost cost) {\n        assert(0 <=\
    \ from && from < n);\n        assert(0 <= to && to < n);\n        assert(cost\
    \ >= 0);\n\n        g[from].emplace_back(to, cost);\n    }\n\n    void build(int\
    \ _s) {\n        _trace.assign(n, -1);\n        _dist.assign(n, COST_INF);\n\n\
    \        s = _s;\n        std::priority_queue<std::pair<Cost, int>,\n        \
    \                    std::vector<std::pair<Cost, int>>,\n                    \
    \        std::greater<std::pair<Cost, int>>>\n            q;\n        q.emplace(0,\
    \ s);\n        _dist[s] = 0;\n        _trace[s] = s;\n        while (!q.empty())\
    \ {\n            auto [d, v] = q.top();\n            q.pop();\n            if\
    \ (_dist[v] != d) {\n                continue;\n            }\n            for\
    \ (auto [nv, c] : g[v]) {\n                if (_dist[v] + c < _dist[nv]) {\n \
    \                   _dist[nv] = _dist[v] + c;\n                    _trace[nv]\
    \ = v;\n                    q.emplace(_dist[nv], nv);\n                }\n   \
    \         }\n        }\n    }\n\n    Cost dist(int x) const { return _dist[x];\
    \ }\n    std::vector<Cost> dists() const { return _dist; }\n    std::vector<int>\
    \ traces() const { return _trace; }\n\n    std::vector<int> shortest_path(int\
    \ to) const {\n        assert(0 <= to && to < n);\n        assert(_dist[to] <\
    \ COST_INF);\n\n        int cur = to;\n        std::vector<int> path;\n      \
    \  while (cur != _trace[cur]) {\n            path.emplace_back(cur);\n       \
    \     cur = _trace[cur];\n        }\n        path.emplace_back(s);\n        std::reverse(path.begin(),\
    \ path.end());\n        return path;\n    }\n};\n};  // namespace kyopro\n\n/**\n\
    \ * @brief Single Source Shortest Path(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
    )\n */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\n#line 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\n#include\
    \ <cstdint>\n\nnamespace kyopro {\nnamespace internal {\ntemplate <typename...\
    \ Args> struct first_enabled {};\n\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<true, T>, Args...> {\n    using type = T;\n\
    };\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<false,\
    \ T>, Args...>\n    : first_enabled<Args...> {};\ntemplate <typename T, typename...\
    \ Args> struct first_enabled<T, Args...> {\n    using type = T;\n};\n\ntemplate\
    \ <typename... Args>\nusing first_enabled_t = typename first_enabled<Args...>::type;\n\
    \ntemplate <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct int_least\
    \ {\n    using type = first_enabled_t<std::enable_if<dgt <= 8, std::int8_t>,\n\
    \                                 std::enable_if<dgt <= 16, std::int16_t>,\n \
    \                                std::enable_if<dgt <= 32, std::int32_t>,\n  \
    \                               std::enable_if<dgt <= 64, std::int64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __int128_t>>;\n};\n\n\
    template <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct uint_least\
    \ {\n    using type = first_enabled_t<std::enable_if<dgt <= 8, std::uint8_t>,\n\
    \                                 std::enable_if<dgt <= 16, std::uint16_t>,\n\
    \                                 std::enable_if<dgt <= 32, std::uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, std::uint64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __uint128_t>>;\n\
    };\n\ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\n\
    template <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate\
    \ <typename T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n\n/**\n * @brief Type Traits\n\
    \ * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\n#line 6\
    \ \"src/stream.hpp\"\n\nnamespace kyopro {\n\ninline void single_read(char& c)\
    \ {\n    c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\ninline void single_read(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\ninline void single_read(T& a) {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\ninline void single_read(std::string& str) noexcept {\n    char\
    \ c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n  \
    \  while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\ntemplate<typename T>\ninline void read(T& x) noexcept {single_read(x);}\n\
    template <typename Head, typename... Tail>\ninline void read(Head& head, Tail&...\
    \ tail) noexcept {\n    single_read(head), read(tail...);\n}\n\ninline void single_write(char\
    \ c) noexcept { putchar_unlocked(c); }\ntemplate <typename T, internal::is_integral_t<T>*\
    \ = nullptr>\ninline void single_write(T a) noexcept {\n    if (!a) {\n      \
    \  putchar_unlocked('0');\n        return;\n    }\n    if constexpr (std::is_signed_v<T>)\
    \ {\n        if (a < 0) putchar_unlocked('-'), a *= -1;\n    }\n    constexpr\
    \ int d = std::numeric_limits<T>::digits10;\n    char s[d + 1];\n    int now =\
    \ d + 1;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n        a /=\
    \ 10;\n    }\n    while (now <= d) putchar_unlocked(s[now++]);\n}\ntemplate <typename\
    \ T, internal::is_modint_t<T>* = nullptr>\ninline void single_write(T a) noexcept\
    \ {\n    single_write(a.val());\n}\ninline void single_write(const std::string&\
    \ str) noexcept {\n    for (auto c : str) {\n        putchar_unlocked(c);\n  \
    \  }\n}\ntemplate <typename T> inline void write(T x) noexcept { single_write(x);\
    \ }\ntemplate <typename Head, typename... Tail>\ninline void write(Head head,\
    \ Tail... tail) noexcept {\n    single_write(head);\n    putchar_unlocked(' ');\n\
    \    write(tail...);\n}\ntemplate <typename... Args> inline void put(Args... x)\
    \ noexcept {\n    write(x...);\n    putchar_unlocked('\\n');\n}\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)\n */\n#line\
    \ 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i, n) for (int\
    \ i = 0; i < (n); i++)\n#define all(x) std::begin(x), std::end(x)\n#define popcount(x)\
    \ __builtin_popcountll(x)\nusing i128 = __int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = std::numeric_limits<int>::max() / 2;\nconstexpr ll\
    \ infl = std::numeric_limits<ll>::max() / 2;\nconst long double pi = acosl(-1);\n\
    constexpr int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr int dy[] = {0,\
    \ 1, 0, -1, 1, 1, -1, -1, 0};\ntemplate <typename T1, typename T2> constexpr inline\
    \ bool chmax(T1& a, T2 b) {\n    return a < b && (a = b, true);\n}\ntemplate <typename\
    \ T1, typename T2> constexpr inline bool chmin(T1& a, T2 b) {\n    return a >\
    \ b && (a = b, true);\n}\n\n/**\n * @brief Template\n*/\n#line 7 \"test/yosupo_judge/graph/Shortest_Path.test.cpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n,\
    \ m, s, t;\n    read(n, m, s, t);\n    dijkstra<long long> g(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        int a, b, c;\n        read(a, b, c);\n       \
    \ g.add_edge(a, b, c);\n    }\n\n    g.build(s);\n    \n    if (g.dist(t) >= dijkstra<long\
    \ long>::COST_INF) {\n        put(-1);\n        return 0;\n    }\n\n    vector\
    \ path = g.shortest_path(t);\n    kyopro::put(g.dist(t), path.size() - 1);\n \
    \   for (int i = 1; i < (int)path.size(); i++)\n        kyopro::put(path[i - 1],\
    \ path[i]);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ <algorithm>\n#include <iostream>\n#include \"../../../src/graph/dijkstra.hpp\"\
    \n#include \"../../../src/stream.hpp\"\n#include \"../../../src/template.hpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n,\
    \ m, s, t;\n    read(n, m, s, t);\n    dijkstra<long long> g(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        int a, b, c;\n        read(a, b, c);\n       \
    \ g.add_edge(a, b, c);\n    }\n\n    g.build(s);\n    \n    if (g.dist(t) >= dijkstra<long\
    \ long>::COST_INF) {\n        put(-1);\n        return 0;\n    }\n\n    vector\
    \ path = g.shortest_path(t);\n    kyopro::put(g.dist(t), path.size() - 1);\n \
    \   for (int i = 1; i < (int)path.size(); i++)\n        kyopro::put(path[i - 1],\
    \ path[i]);\n}"
  dependsOn:
  - src/graph/dijkstra.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  - src/template.hpp
  isVerificationFile: true
  path: test/yosupo_judge/graph/Shortest_Path.test.cpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/graph/Shortest_Path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp.html
title: test/yosupo_judge/graph/Shortest_Path.test.cpp
---
