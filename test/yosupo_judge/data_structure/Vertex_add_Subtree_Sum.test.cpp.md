---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/BIT.hpp
    title: Binary Index Tree
  - icon: ':question:'
    path: src/data-structure/sparse_table.hpp
    title: Sparse Table
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
  - icon: ':question:'
    path: src/tree/EulerTour.hpp
    title: Euler Tour
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #include <iostream>\n#line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace kyopro {\n\ntemplate <typename T> class BIT {\n\
    \    std::vector<T> bit;\n    int n;\n\npublic:\n    BIT() : BIT(0) {}\n    BIT(int\
    \ n) : n(n), bit(n + 1, T()) {}\n    \n    void add(int p, T w) {\n        assert(0\
    \ <= p && p < n);\n        p++;\n        for (int x = p; x <= n; x += x & -x)\
    \ {\n            bit[x] += w;\n        }\n    }\n\n    T sum(int p) const {\n\
    \        assert(0 <= p && p <= n);\n        T s = 0;\n\n        for (int x = p;\
    \ x > 0; x -= x & -x) {\n            s += bit[x];\n        }\n        return s;\n\
    \    }\n\n    T sum(int l, int r) const { return sum(r) - sum(l); }\n\n    int\
    \ lower_bound(T w) const {\n        if (w <= 0) return 0;\n\n        int x = 0;\n\
    \        int k = 1;\n        while (k < n) k <<= 1;\n        for (; k > 0; k >>=\
    \ 1) {\n            if (x + k <= n && bit[x + k] < w) {\n                w -=\
    \ bit[x + k];\n                x += k;\n            }\n        }\n\n        return\
    \ x + 1;\n    }\n\n    T operator[](int i) { return sum(i + 1) - sum(i); }\n \
    \   void update(int i, T v) { add(i, -sum(i + 1) + sum(i) + v); }\n};\n};  //\
    \ namespace kyopro\n\n/**\n * @brief Binary Index Tree\n */\n#line 2 \"src/stream.hpp\"\
    \n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n#line 3 \"src/internal/type_traits.hpp\"\
    \n#include <limits>\n#include <numeric>\n#include <typeinfo>\n#include <cstdint>\n\
    \nnamespace kyopro {\nnamespace internal {\ntemplate <typename... Args> struct\
    \ first_enabled {};\n\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
    \ T>, Args...> {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt, std::enable_if_t<dgt\
    \ <= 128>* = nullptr> struct int_least {\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, std::int8_t>,\n                                 std::enable_if<dgt <=\
    \ 16, std::int16_t>,\n                                 std::enable_if<dgt <= 32,\
    \ std::int32_t>,\n                                 std::enable_if<dgt <= 64, std::int64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __int128_t>>;\n};\n\
    \ntemplate <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct uint_least\
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
    \ 3 \"src/tree/EulerTour.hpp\"\n#include <utility>\n#line 5 \"src/data-structure/sparse_table.hpp\"\
    \n\nnamespace kyopro {\n\ntemplate <class T, auto op> class sparse_table {\n \
    \   std::vector<T> vec;\n    std::vector<std::vector<T>> table;\n    std::vector<int>\
    \ lg;\n\npublic:\n    constexpr sparse_table(int n) : vec(n) {}\n    constexpr\
    \ sparse_table(const std::vector<T>& vec) : vec(vec) { build(); }\n\n    void\
    \ set(int p, const T& v) { vec[p] = v; }\n    void build() {\n        int sz =\
    \ vec.size();\n        int log = 0;\n        while ((1 << log) <= sz) {\n    \
    \        log++;\n        }\n        table.assign(log, std::vector<T>(1 << log));\n\
    \        for (int i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n \
    \       }\n        for (int i = 1; i < log; i++) {\n            for (int j = 0;\
    \ j + (1 << i) <= (1 << log); j++) {\n                table[i][j] =\n        \
    \            op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n        \
    \    }\n        }\n        lg.resize(sz + 1);\n        for (int i = 2; i < (int)lg.size();\
    \ i++) {\n            lg[i] = lg[i >> 1] + 1;\n        }\n    }\n\n    T fold(int\
    \ l, int r) const {\n        assert(l < r);\n        int b = lg[r - l];\n    \
    \    return op(table[b][l], table[b][r - (1 << b)]);\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Sparse Table\n */\n#line 2 \"src/internal/CSR.hpp\"\
    \n\n#line 4 \"src/internal/CSR.hpp\"\n#include <iterator>\n#line 7 \"src/internal/CSR.hpp\"\
    \n\nnamespace kyopro {\nnamespace internal {\n\ntemplate <typename T, typename\
    \ _size_t> class csr {\n    _size_t n;\n    std::vector<T> d;\n    std::vector<_size_t>\
    \ ssum;\n\npublic:\n    csr() = default;\n    csr(_size_t n, const std::vector<std::pair<_size_t,\
    \ T>>& v)\n        : n(n), ssum(n + 1), d(v.size()) {\n        for (int i = 0;\
    \ i < (int)v.size(); ++i) {\n            ++ssum[v[i].first + 1];\n        }\n\
    \        for (int i = 0; i < n; ++i) {\n            ssum[i + 1] += ssum[i];\n\
    \        }\n\n        std::vector cnt = ssum;\n        for (auto e : v) d[cnt[e.first]++]\
    \ = e.second;\n    }\n\n    struct vector_range {\n        using iterator = typename\
    \ std::vector<T>::iterator;\n        iterator l, r;\n\n        iterator begin()\
    \ const { return l; }\n        iterator end() const { return r; }\n        _size_t\
    \ size() { return std::distance(l, r); }\n        T& operator[](_size_t i) const\
    \ { return l[i]; }\n    };\n    struct const_vector_range {\n        using const_iterator\
    \ = typename std::vector<T>::const_iterator;\n        const_iterator l, r;\n\n\
    \        const_iterator begin() const { return l; }\n        const_iterator end()\
    \ const { return r; }\n        _size_t size() { return (_size_t)std::distance(l,\
    \ r); }\n        const T& operator[](_size_t i) const { return l[i]; }\n    };\n\
    \n    vector_range operator[](_size_t i) {\n        return vector_range{d.begin()\
    \ + ssum[i], d.begin() + ssum[i + 1]};\n    }\n    const_vector_range operator[](_size_t\
    \ i) const {\n        return const_vector_range{d.begin() + ssum[i], d.begin()\
    \ + ssum[i + 1]};\n    }\n\n    _size_t size() const { return (_size_t)n; }\n\
    };\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n * @brief CSR\u5F62\
    \u5F0F(\u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u306E\u5727\u7E2E)\n */\n#line\
    \ 6 \"src/tree/EulerTour.hpp\"\n\nnamespace kyopro {\n\nclass EulerTour {\n  \
    \  int n;\n\n    std::vector<std::pair<int, int>> es;\n    std::vector<int> tour;\n\
    \    std::vector<int> in, out, depth;\n\n    struct get_min_pair {\n        using\
    \ value_t = std::pair<int, int>;\n        static value_t op(value_t x, value_t\
    \ y) { return std::min(x, y); }\n    };\n\n    sparse_table<get_min_pair::value_t,\
    \ get_min_pair::op> rmq;\n\npublic:\n    explicit EulerTour(int n)\n        :\
    \ n(n), in(n, -1), out(n, -1), depth(n, -1), rmq(2 * n - 1) {\n        tour.reserve(2\
    \ * n);\n        es.reserve(2 * n);\n    }\n\n    void add_edge(int u, int v)\
    \ {\n        assert(0 <= v && v < n);\n        assert(0 <= u && u < n);\n    \
    \    es.emplace_back(u, v);\n        es.emplace_back(v, u);\n    }\n\n    int\
    \ get_depth(int v) const {\n        assert(0 <= v && v < n);\n        return depth[v];\n\
    \    }\n\n    void build(int r = 0) {\n        internal::csr g(n, es);\n     \
    \   auto dfs = [&](const auto& self, int v, int p) -> void {\n            in[v]\
    \ = tour.size();\n            tour.emplace_back(v);\n            for (auto nv\
    \ : g[v]) {\n                if (nv != p) {\n                    depth[nv] = depth[v]\
    \ + 1;\n                    self(self, nv, v);\n                    tour.emplace_back(v);\n\
    \                }\n            }\n            out[v] = tour.size() - 1;\n   \
    \     };\n        dfs(dfs, r, -1);\n        for (int i = 0; i < (int)tour.size();\
    \ i++) {\n            rmq.set(i, {depth[tour[i]], tour[i]});\n        }\n    \
    \    rmq.build();\n    }\n\n    std::pair<int, int> idx(int v) const {\n     \
    \   assert(0 <= v && v < n);\n        return {in[v], out[v]};\n    }\n    \n \
    \   int lca(int v, int u) const {\n        assert(0 <= v && v < n);\n        assert(0\
    \ <= u && u < n);\n        if (in[v] > in[u] + 1) {\n            std::swap(u,\
    \ v);\n        }\n        return rmq.fold(in[v], in[u] + 1).second;\n    }\n\n\
    \    int dist(int v, int u) const {\n        assert(0 <= v && v < n);\n      \
    \  assert(0 <= u && u < n);\n        int p = lca(v, u);\n        return depth[v]\
    \ + depth[u] - 2 * depth[p];\n    }\n\n    bool is_in_subtree(int par, int v)\
    \ const {\n        assert(0 <= par && par < n);\n        assert(0 <= v && v <\
    \ n);\n\n        return (in[par] <= in[v] && out[v] <= out[par]);\n    }\n};\n\
    };  // namespace kyopro\n\n/**\n * @brief Euler Tour\n * @docs docs/tree/EulerTour.md\n\
    \ */\n#line 6 \"test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n,\
    \ q;\n    read(n, q);\n    vector<long long> a(n);\n    for (int i = 0; i < n;\
    \ ++i) read(a[i]);\n\n    EulerTour g(n);\n    for (int i = 1; i < n; i++) {\n\
    \        int p;\n        read(p);\n        g.add_edge(i, p);\n    }\n    g.build();\n\
    \n    BIT<long long> seg(2 * n);\n    for (int v = 0; v < n; v++) {\n        int\
    \ in = g.idx(v).first;\n        seg.add(in, a[v]);\n    }\n    while (q--) {\n\
    \        int t;\n        read(t);\n        if (!t) {\n            int v, x;\n\
    \            read(v, x);\n            int in = g.idx(v).first;\n            seg.add(in,\
    \ x);\n        } else {\n            int v;\n            read(v);\n          \
    \  auto [in, out] = g.idx(v);\n            put(seg.sum(in, out + 1));\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include <iostream>\n#include \"../../../src/data-structure/BIT.hpp\"\n#include\
    \ \"../../../src/stream.hpp\"\n#include \"../../../src/tree/EulerTour.hpp\"\n\n\
    using namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n, q;\n\
    \    read(n, q);\n    vector<long long> a(n);\n    for (int i = 0; i < n; ++i)\
    \ read(a[i]);\n\n    EulerTour g(n);\n    for (int i = 1; i < n; i++) {\n    \
    \    int p;\n        read(p);\n        g.add_edge(i, p);\n    }\n    g.build();\n\
    \n    BIT<long long> seg(2 * n);\n    for (int v = 0; v < n; v++) {\n        int\
    \ in = g.idx(v).first;\n        seg.add(in, a[v]);\n    }\n    while (q--) {\n\
    \        int t;\n        read(t);\n        if (!t) {\n            int v, x;\n\
    \            read(v, x);\n            int in = g.idx(v).first;\n            seg.add(in,\
    \ x);\n        } else {\n            int v;\n            read(v);\n          \
    \  auto [in, out] = g.idx(v);\n            put(seg.sum(in, out + 1));\n      \
    \  }\n    }\n}"
  dependsOn:
  - src/data-structure/BIT.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  - src/tree/EulerTour.hpp
  - src/data-structure/sparse_table.hpp
  - src/internal/CSR.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  requiredBy: []
  timestamp: '2024-12-05 21:13:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
---
