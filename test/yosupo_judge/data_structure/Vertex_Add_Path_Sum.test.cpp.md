---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data-structure/BIT.hpp
    title: Binary Index Tree
  - icon: ':x:'
    path: src/data-structure/sparse_table.hpp
    title: SparseTable
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/stream.hpp
    title: "\u5165\u51FA\u529B"
  - icon: ':x:'
    path: src/tree/EulerTour.hpp
    title: Euler Tour
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#include\
    \ <iostream>\n#line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\nnamespace\
    \ kyopro {\n/**\n * @brief Binary Index Tree\n */\ntemplate <typename T> class\
    \ BIT {\n    std::vector<T> bit;\n    int n;\n\npublic:\n    explicit BIT() {}\n\
    \    explicit BIT(int n) : n(n), bit(n + 1, T()) {}\n    void add(int p, T w)\
    \ {\n        p++;\n        for (int x = p; x <= n; x += x & -x) {\n          \
    \  bit[x] += w;\n        }\n    }\n\n    T sum(int p) const {\n        T s = 0;\n\
    \n        for (int x = p; x > 0; x -= x & -x) {\n            s += bit[x];\n  \
    \      }\n        return s;\n    }\n\n    T sum(int l, int r) const { return sum(r)\
    \ - sum(l); }\n\n    T operator()(int p) { return sum(p + 1) - sum(p); }\n   \
    \ void update(int p, T v) { add(p, -(*this)(p) + v); }\n    int lower_bound(T\
    \ w) const {\n        if (w <= 0) return 0;\n\n        int x = 0;\n        int\
    \ k = 1;\n        while (k < n) k <<= 1;\n        for (; k > 0; k >>= 1) {\n \
    \           if (x + k <= n && bit[x + k] < w) {\n                w -= bit[x +\
    \ k];\n                x += k;\n            }\n        }\n\n        return x +\
    \ 1;\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/BIT.md\n\
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\n#line 3 \"src/internal/type_traits.hpp\"\n#include <limits>\n#include\
    \ <numeric>\n#include <typeinfo>\nnamespace kyopro {\nnamespace internal {\n/*\n\
    \ * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\ntemplate\
    \ <typename... Args> struct first_enabled {};\n\ntemplate <typename T, typename...\
    \ Args>\nstruct first_enabled<std::enable_if<true, T>, Args...> {\n    using type\
    \ = T;\n};\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<false,\
    \ T>, Args...>\n    : first_enabled<Args...> {};\ntemplate <typename T, typename...\
    \ Args> struct first_enabled<T, Args...> {\n    using type = T;\n};\n\ntemplate\
    \ <typename... Args>\nusing first_enabled_t = typename first_enabled<Args...>::type;\n\
    \ntemplate <int dgt> struct int_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __int8_t>,\n               \
    \                  std::enable_if<dgt <= 16, __int16_t>,\n                   \
    \              std::enable_if<dgt <= 32, __int32_t>,\n                       \
    \          std::enable_if<dgt <= 64, __int64_t>,\n                           \
    \      std::enable_if<dgt <= 128, __int128_t> >;\n};\ntemplate <int dgt> struct\
    \ uint_least {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __uint8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __uint16_t>,\n                                 std::enable_if<dgt <= 32, __uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __uint64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\
    \ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\ntemplate\
    \ <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename\
    \ T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n#line 6 \"src/stream.hpp\"\
    \n\nnamespace kyopro {\n// read\nvoid single_read(char& c) noexcept {\n    c =\
    \ getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n}\ntemplate\
    \ <typename T, internal::is_integral_t<T>* = nullptr>\nconstexpr void single_read(T&\
    \ a) noexcept {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if constexpr\
    \ (std::is_signed<T>::value) {\n        if (c == '-') is_negative = true, c =\
    \ getchar_unlocked();\n    }\n    while (isdigit(c)) {\n        a = 10 * a + (c\
    \ - '0');\n        c = getchar_unlocked();\n    }\n    if constexpr (std::is_signed<T>::value)\
    \ {\n        if (is_negative) a *= -1;\n    }\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_read(T& a) noexcept {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\nvoid single_read(std::string& str) noexcept {\n    char c =\
    \ getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n    while\
    \ (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n    }\n\
    }\ntemplate <typename T> constexpr inline void read(T& x) noexcept {\n    single_read(x);\n\
    }\ntemplate <typename Head, typename... Tail>\nconstexpr inline void read(Head&\
    \ head, Tail&... tail) noexcept {\n    single_read(head), read(tail...);\n}\n\n\
    // write\nvoid single_write(char c) noexcept { putchar_unlocked(c); }\ntemplate\
    \ <typename T, internal::is_integral_t<T>* = nullptr>\nvoid single_write(T a)\
    \ noexcept {\n    if (!a) {\n        putchar_unlocked('0');\n        return;\n\
    \    }\n    if constexpr (std::is_signed<T>::value) {\n        if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    }\n    constexpr int d = std::numeric_limits<T>::digits10;\n \
    \   char s[d];\n    int now = d;\n    while (a) {\n        s[--now] = static_cast<char>('0'\
    \ + a % 10);\n        a /= 10;\n    }\n    while (now < d) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T, internal::is_modint_t<T>* = nullptr>\nvoid single_write(T\
    \ a) noexcept {\n    single_write(a.val());\n}\n\nvoid single_write(const std::string&\
    \ str) noexcept {\n    for (auto c : str) {\n        putchar_unlocked(c);\n  \
    \  }\n}\n\ntemplate <typename T> constexpr inline void write(T x) noexcept {\n\
    \    single_write(x);\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void write(Head head, Tail... tail) noexcept {\n    single_write(head);\n\
    \    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate <typename... Args>\
    \ constexpr inline void put(Args... x) noexcept {\n    write(x...);\n    putchar_unlocked('\\\
    n');\n}\n};  // namespace kyopro\n\n/**\n * @brief \u5165\u51FA\u529B\n */\n#line\
    \ 2 \"src/tree/EulerTour.hpp\"\n#include <cassert>\n#include <utility>\n#line\
    \ 4 \"src/data-structure/sparse_table.hpp\"\nnamespace kyopro {\n\n/**\n * @brief\
    \ SparseTable\n */\ntemplate <class T, auto op> class sparse_table {\n    std::vector<T>\
    \ vec;\n    std::vector<std::vector<T>> table;\n    std::vector<int> look_up;\n\
    \npublic:\n    constexpr explicit sparse_table(int n) : vec(n) {}\n    constexpr\
    \ explicit sparse_table(const std::vector<T>& vec) : vec(vec) {\n        build();\n\
    \    }\n    void set(int p, const T& v) { vec[p] = v; }\n    void build() {\n\
    \        int sz = vec.size();\n        int log = 0;\n        while ((1 << log)\
    \ <= sz) {\n            log++;\n        }\n        table.assign(log, std::vector<T>(1\
    \ << log));\n        for (int i = 0; i < sz; i++) {\n            table[0][i] =\
    \ vec[i];\n        }\n        for (int i = 1; i < log; i++) {\n            for\
    \ (int j = 0; j + (1 << i) <= (1 << log); j++) {\n                table[i][j]\
    \ =\n                    op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n\
    \            }\n        }\n        look_up.resize(sz + 1);\n        for (int i\
    \ = 2; i < (int)look_up.size(); i++) {\n            look_up[i] = look_up[i >>\
    \ 1] + 1;\n        }\n    }\n\n    T fold(int l, int r) const {\n        int b\
    \ = look_up[r - l];\n        return op(table[b][l], table[b][r - (1 << b)]);\n\
    \    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/sparse_table.md\n\
    \ */\n#line 5 \"src/tree/EulerTour.hpp\"\nnamespace kyopro {\n\n/**\n * @brief\
    \ Euler Tour\n */\nclass EulerTour {\n    int n;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> tour;\n    std::vector<int> in, out, depth;\n\n   \
    \ struct get_min_pair {\n        using value_t = std::pair<int, int>;\n      \
    \  static value_t op(value_t x, value_t y) { return std::min(x, y); }\n    };\n\
    \n    sparse_table<get_min_pair::value_t, get_min_pair::op> rmq;\n\npublic:\n\
    \    explicit EulerTour(int n)\n        : n(n), g(n), in(n, -1), out(n, -1), depth(n,\
    \ -1), rmq(2 * n - 1) {\n        tour.reserve(2 * n - 1);\n    }\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= v && v < n);\n        assert(0 <= u && u <\
    \ n);\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n    }\n \
    \   const std::vector<std::vector<int>>& get_graph() const { return g; }\n   \
    \ const std::vector<int>& get_tour() const { return tour; }\n    int get_depth(int\
    \ v) const {\n        assert(0 <= v && v < n);\n        return depth[v];\n   \
    \ }\n\n    void build(int r = 0) {\n        auto dfs = [&](const auto& self, int\
    \ v, int p) -> void {\n            in[v] = tour.size();\n            tour.emplace_back(v);\n\
    \            for (auto nv : g[v]) {\n                if (nv != p) {\n        \
    \            depth[nv] = depth[v] + 1;\n                    self(self, nv, v);\n\
    \                    tour.emplace_back(v);\n                }\n            }\n\
    \            out[v] = tour.size() - 1;\n        };\n        dfs(dfs, r, -1);\n\
    \        for (int i = 0; i < (int)tour.size(); i++) {\n            rmq.set(i,\
    \ {depth[tour[i]], tour[i]});\n        }\n        rmq.build();\n    }\n\n    std::pair<int,\
    \ int> idx(int v) const {\n        assert(0 <= v && v < n);\n        return std::pair(in[v],\
    \ out[v]);\n    }\n    int lca(int v, int u) const {\n        assert(0 <= v &&\
    \ v < n);\n        assert(0 <= u && u < n);\n        if (in[v] > in[u] + 1) {\n\
    \            std::swap(u, v);\n        }\n        return rmq.fold(in[v], in[u]\
    \ + 1).second;\n    }\n\n    int dist(int v, int u) const {\n        assert(0\
    \ <= v && v < n);\n        assert(0 <= u && u < n);\n        int p = lca(v, u);\n\
    \        return depth[v] + depth[u] - 2 * depth[p];\n    }\n\n    bool is_in_subtree(int\
    \ par, int v) const {\n        assert(0 <= par && par < n);\n        assert(0\
    \ <= v && v < n);\n\n        return (in[par] <= in[v] && out[v] <= out[par]);\n\
    \    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/tree/EulerTour.md\n\
    \ */\n#line 6 \"test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n,\
    \ q;\n    read(n, q);\n    vector<long long> a(n);\n    for (int i = 0; i < n;\
    \ ++i) read(a[i]);\n\n    EulerTour g(n);\n    for (int i = 0; i < n - 1; i++)\
    \ {\n        int v, u;\n        read(v, u);\n        g.add_edge(v, u);\n    }\n\
    \    g.build();\n\n    BIT<long long> seg(2 * n);\n    for (int v = 0; v < n;\
    \ v++) {\n        auto [in, out] = g.idx(v);\n        seg.add(in, a[v]);\n   \
    \     seg.add(out + 1, -a[v]);\n    }\n\n    while (q--) {\n        int t;\n \
    \       read(t);\n        if (t == 0) {\n            int v, x;\n            read(v,\
    \ x);\n            auto [in, out] = g.idx(v);\n            seg.add(in, x);\n \
    \           seg.add(out + 1, -x);\n        } else {\n            int v, u;\n \
    \           read(v, u);\n            long long ans = 0;\n            int p_in\
    \ = g.idx(g.lca(v, u)).first;\n            ans += seg.sum(p_in, g.idx(v).first\
    \ + 1);\n            ans += seg.sum(p_in + 1, g.idx(u).first + 1);\n\n       \
    \     put(ans);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include <iostream>\n#include \"../../../src/data-structure/BIT.hpp\"\n#include\
    \ \"../../../src/stream.hpp\"\n#include \"../../../src/tree/EulerTour.hpp\"\n\n\
    using namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n, q;\n\
    \    read(n, q);\n    vector<long long> a(n);\n    for (int i = 0; i < n; ++i)\
    \ read(a[i]);\n\n    EulerTour g(n);\n    for (int i = 0; i < n - 1; i++) {\n\
    \        int v, u;\n        read(v, u);\n        g.add_edge(v, u);\n    }\n  \
    \  g.build();\n\n    BIT<long long> seg(2 * n);\n    for (int v = 0; v < n; v++)\
    \ {\n        auto [in, out] = g.idx(v);\n        seg.add(in, a[v]);\n        seg.add(out\
    \ + 1, -a[v]);\n    }\n\n    while (q--) {\n        int t;\n        read(t);\n\
    \        if (t == 0) {\n            int v, x;\n            read(v, x);\n     \
    \       auto [in, out] = g.idx(v);\n            seg.add(in, x);\n            seg.add(out\
    \ + 1, -x);\n        } else {\n            int v, u;\n            read(v, u);\n\
    \            long long ans = 0;\n            int p_in = g.idx(g.lca(v, u)).first;\n\
    \            ans += seg.sum(p_in, g.idx(v).first + 1);\n            ans += seg.sum(p_in\
    \ + 1, g.idx(u).first + 1);\n\n            put(ans);\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/BIT.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  - src/tree/EulerTour.hpp
  - src/data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 07:26:53+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
---
