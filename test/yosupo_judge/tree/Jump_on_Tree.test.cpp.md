---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/CSR.hpp
    title: "CSR\u5F62\u5F0F(\u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u306E\u5727\
      \u7E2E)"
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  - icon: ':question:'
    path: src/stream.hpp
    title: "Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)"
  - icon: ':x:'
    path: src/tree/doubling.hpp
    title: "Binary Lifting(\u6728\u4E0A\u306E\u30C0\u30D6\u30EA\u30F3\u30B0)"
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
    #include <cstdint>\n\nnamespace kyopro {\nnamespace internal {\ntemplate <typename...\
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
    \ 2 \"src/tree/doubling.hpp\"\n#include <cassert>\n#include <vector>\n#line 2\
    \ \"src/internal/CSR.hpp\"\n\n#line 4 \"src/internal/CSR.hpp\"\n#include <iterator>\n\
    #include <utility>\n#line 7 \"src/internal/CSR.hpp\"\n\nnamespace kyopro {\nnamespace\
    \ internal {\n\ntemplate <typename T, typename _size_t> class csr {\n    _size_t\
    \ n;\n    std::vector<T> d;\n    std::vector<_size_t> ssum;\n\npublic:\n    csr()\
    \ = default;\n    csr(_size_t n, const std::vector<std::pair<_size_t, T>>& v)\n\
    \        : n(n), ssum(n + 1), d(v.size()) {\n        for (int i = 0; i < (int)v.size();\
    \ ++i) {\n            ++ssum[v[i].first + 1];\n        }\n        for (int i =\
    \ 0; i < n; ++i) {\n            ssum[i + 1] += ssum[i];\n        }\n\n       \
    \ std::vector cnt = ssum;\n        for (auto e : v) d[cnt[e.first]++] = e.second;\n\
    \    }\n\n    struct vector_range {\n        using iterator = typename std::vector<T>::iterator;\n\
    \        iterator l, r;\n\n        iterator begin() const { return l; }\n    \
    \    iterator end() const { return r; }\n        _size_t size() { return std::distance(l,\
    \ r); }\n        T& operator[](_size_t i) const { return l[i]; }\n    };\n   \
    \ struct const_vector_range {\n        using const_iterator = typename std::vector<T>::const_iterator;\n\
    \        const_iterator l, r;\n\n        const_iterator begin() const { return\
    \ l; }\n        const_iterator end() const { return r; }\n        _size_t size()\
    \ { return (_size_t)std::distance(l, r); }\n        const T& operator[](_size_t\
    \ i) const { return l[i]; }\n    };\n\n    vector_range operator[](_size_t i)\
    \ {\n        return vector_range{d.begin() + ssum[i], d.begin() + ssum[i + 1]};\n\
    \    }\n    const_vector_range operator[](_size_t i) const {\n        return const_vector_range{d.begin()\
    \ + ssum[i], d.begin() + ssum[i + 1]};\n    }\n\n    _size_t size() const { return\
    \ (_size_t)n; }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n\
    \ * @brief CSR\u5F62\u5F0F(\u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u306E\u5727\
    \u7E2E)\n */\n#line 5 \"src/tree/doubling.hpp\"\n\nnamespace kyopro {\n\ntemplate\
    \ <typename Cost, int lg> class doubling {\n    struct edge {\n        int to;\n\
    \        Cost cost;\n\n        edge() : to(0), cost(0) {}\n        edge(int to,\
    \ Cost cost) : to(to), cost(cost) {}\n    };\n\n    const int n;\n\n    std::vector<std::pair<int,\
    \ edge>> es;\n    std::vector<int> parent[lg];\n    std::vector<Cost> _dist;\n\
    \    std::vector<int> _depth;\n\npublic:\n    doubling(int n) : n(n), _dist(n,\
    \ -1), _depth(n) {\n        std::fill(parent, parent + lg, std::vector<int>(n));\n\
    \        es.reserve(2 * (n - 1));\n    }\n\n    void add_edge(int a, int b, Cost\
    \ c = 1) {\n        es.emplace_back(a, edge{b, c});\n        es.emplace_back(b,\
    \ edge{a, c});\n    }\n    \n    void build(int root = 0) {\n        internal::csr\
    \ g(n, es);\n\n        std::vector<int> st;\n        st.reserve(n);\n\n      \
    \  st.emplace_back(root);\n        _dist[root] = 0, _depth[root] = 0, parent[0][root]\
    \ = root;\n        while (!st.empty()) {\n            int v = st.back();\n   \
    \         st.pop_back();\n\n            for (auto [nv, c] : g[v]) {\n        \
    \        if (_dist[nv] != -1) continue;\n                _dist[nv] = _dist[v]\
    \ + c;\n                _depth[nv] = _depth[v] + 1;\n                parent[0][nv]\
    \ = v;\n\n                st.emplace_back(nv);\n            }\n        }\n\n \
    \       for (int i = 0; i < lg; ++i) {\n            for (int v = 0; v < n; ++v)\
    \ {\n                parent[i + 1][v] = parent[i][parent[i][v]];\n           \
    \ }\n        }\n    }\n\n    int level_ancestor(int v, const int k) const {\n\
    \        if (_depth[v] < k) return -1;\n\n        for (int i = 0; i < lg; ++i)\
    \ {\n            if (k >> i & 1) {\n                v = parent[i][v];\n      \
    \      }\n        }\n        return v;\n    }\n\n    long long dist(int v) const\
    \ { return _dist[v]; }\n    long long dist(int u, int v) const {\n        return\
    \ dist(u) + dist(v) - 2 * dist(lca(u, v));\n    }\n    int depth(int v) const\
    \ { return _depth[v]; }\n    int unweighted_dist(int u, int v) const {\n     \
    \   return _depth[u] + _depth[v] - 2 * _depth[lca(u, v)];\n    }\n    int lca(int\
    \ a, int b) const {\n        if (_depth[a] > _depth[b]) {\n            std::swap(a,\
    \ b);\n        }\n        if (_depth[a] != _depth[b]) {\n            b = level_ancestor(b,\
    \ _depth[b] - _depth[a]);\n        }\n        if (a == b) return a;\n        for\
    \ (int k = lg - 1; k >= 0; --k) {\n            if (parent[k][a] != parent[k][b])\
    \ {\n                a = parent[k][a];\n                b = parent[k][b];\n  \
    \          }\n        }\n        return parent[0][a];\n    }\n\n    int jump(const\
    \ int from, const int to, const int k) const {\n        int p = lca(from, to);\n\
    \        int d1 = _depth[from] - _depth[p];\n        int d2 = _depth[to] - _depth[p];\n\
    \n        if (d1 + d2 < k) {\n            return -1;\n        }\n\n        if\
    \ (d1 >= k) {\n            return level_ancestor(from, k);\n        } else {\n\
    \            return level_ancestor(to, d1 + d2 - k);\n        }\n    }\n};\n};\
    \  // namespace kyopro\n\n/**\n *\n * @brief Binary Lifting(\u6728\u4E0A\u306E\
    \u30C0\u30D6\u30EA\u30F3\u30B0)\n * @docs docs/tree/doubling.md\n */\n#line 4\
    \ \"test/yosupo_judge/tree/Jump_on_Tree.test.cpp\"\n\nusing namespace std;\nusing\
    \ namespace kyopro;\n\nint main() {\n    int n, q;\n    read(n, q);\n    doubling<int,\
    \ 19> g(n);\n    for (int i = 0; i < n - 1; ++i) {\n        int a, b;\n      \
    \  read(a, b);\n        g.add_edge(a, b);\n    }\n    g.build();\n\n    while\
    \ (q--) {\n        int s, t, i;\n        read(s, t, i);\n        put(g.jump(s,\
    \ t, i));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n#include\
    \ \"../../../src/stream.hpp\"\n#include \"../../../src/tree/doubling.hpp\"\n\n\
    using namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n, q;\n\
    \    read(n, q);\n    doubling<int, 19> g(n);\n    for (int i = 0; i < n - 1;\
    \ ++i) {\n        int a, b;\n        read(a, b);\n        g.add_edge(a, b);\n\
    \    }\n    g.build();\n\n    while (q--) {\n        int s, t, i;\n        read(s,\
    \ t, i);\n        put(g.jump(s, t, i));\n    }\n}"
  dependsOn:
  - src/stream.hpp
  - src/internal/type_traits.hpp
  - src/tree/doubling.hpp
  - src/internal/CSR.hpp
  isVerificationFile: true
  path: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Jump_on_Tree.test.cpp
- /verify/test/yosupo_judge/tree/Jump_on_Tree.test.cpp.html
title: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
---
