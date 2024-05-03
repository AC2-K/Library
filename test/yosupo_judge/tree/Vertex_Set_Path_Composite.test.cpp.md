---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/segtree.hpp
    title: Segment Tree
  - icon: ':x:'
    path: src/internal/CSR.hpp
    title: "CSR\u5F62\u5F0F"
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':question:'
    path: src/math/static_modint.hpp
    title: static modint
  - icon: ':question:'
    path: src/stream.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B"
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  - icon: ':x:'
    path: src/tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#line 2 \"src/data-structure/segtree.hpp\"\n#include <cassert>\n#include <vector>\n\
    namespace kyopro {\n\n\ntemplate <class S, auto op, auto e> class segtree {\n\
    \    int lg, sz, n;\n    std::vector<S> dat;\n\npublic:\n    segtree() = default;\n\
    \    segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const std::vector<S>&\
    \ vec) : n((int)vec.size()) {\n        sz = 1, lg = 0;\n        while (sz <= n)\
    \ {\n            sz <<= 1;\n            lg++;\n        }\n\n        dat = std::vector<S>(sz\
    \ << 1, e());\n\n        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n\
    \        }\n        build();\n    }\n\n    void set(int p, const S& v) {\n   \
    \     assert(0 <= p && p < sz);\n        dat[sz + p] = v;\n    }\n    void build()\
    \ {\n        for (int i = sz - 1; i > 0; i--) {\n            dat[i] = op(dat[i\
    \ << 1 | 0], dat[i << 1 | 1]);\n        }\n    }\n\n    S operator[](int p) const\
    \ { return dat[sz + p]; }\n\n    void update(int p, const S& v) {\n        assert(0\
    \ <= p && p < sz);\n        p += sz;\n        dat[p] = v;\n        while (p >>=\
    \ 1) {\n            dat[p] = op(dat[(p << 1) | 0], dat[(p << 1) | 1]);\n     \
    \   }\n    }\n\n    S fold(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= sz);\n        if (l == 0 && r == n) {\n            return dat[1];\n\
    \        }\n        l += sz, r += sz;\n        S sml = e(), smr = e();\n     \
    \   while (l != r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n      \
    \      if (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n  \
    \      }\n        return op(sml, smr);\n    }\n    void apply(int p, const S&\
    \ v) {\n        assert(0 <= p && p < sz);\n        update(p, op(dat[sz + p], v));\n\
    \    }\n};\n};  // namespace kyopro\n\n/**\n * @brief Segment Tree\n */\n#line\
    \ 3 \"src/math/static_modint.hpp\"\n#include <cstdint>\n#include <iostream>\n\n\
    #line 3 \"src/internal/type_traits.hpp\"\n#include <limits>\n#include <numeric>\n\
    #include <typeinfo>\n#line 7 \"src/internal/type_traits.hpp\"\n\nnamespace kyopro\
    \ {\nnamespace internal {\ntemplate <typename... Args> struct first_enabled {};\n\
    \ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
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
    };  // namespace internal\n};  // namespace kyopro\n\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\n#line 3 \"src/math/gcd.hpp\"\n#include <cmath>\n#include <tuple>\nnamespace\
    \ kyopro {\ntemplate <typename T> constexpr inline T _gcd(T a, T b) noexcept {\n\
    \    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int\
    \ d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a),\
    \ b >>= __builtin_ctzll(b);\n    while (a != b) {\n        if (!a || !b) {\n \
    \           return a + b;\n        }\n        if (a >= b) {\n            a -=\
    \ b;\n            a >>= __builtin_ctzll(a);\n        } else {\n            b -=\
    \ a;\n            b >>= __builtin_ctzll(b);\n        }\n    }\n\n    return a\
    \ << d;\n}\n\ntemplate <typename T>\nconstexpr inline T ext_gcd(T a, T b, T& x,\
    \ T& y) noexcept {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while (b) {\n\
    \        T q = a / b;\n        std::tie(a, b) = std::pair<T, T>{b, a % b};\n \
    \       std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n        std::tie(y,\
    \ ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return a;\n}\n};  // namespace\
    \ kyopro\n#line 8 \"src/math/static_modint.hpp\"\nnamespace kyopro {\ntemplate\
    \ <int _mod, std::enable_if_t<_mod >= 0>* = nullptr>\nclass modint : internal::modint_base\
    \ {\n    using mint = modint<_mod>;\n    using i32 = std::int32_t;\n    using\
    \ u32 = std::uint32_t;\n    using i64 = std::int64_t;\n    using u64 = std::uint64_t;\n\
    \n    u32 v;\n    constexpr u32 normalize(i64 v_) const noexcept {\n        v_\
    \ %= _mod;\n        if (v_ < 0) {\n            v_ += _mod;\n        }\n      \
    \  return v_;\n    }\n\npublic:\n    static constexpr u32 mod() noexcept { return\
    \ _mod; }\n    constexpr modint() noexcept : v(0) {}\n    constexpr modint(i64\
    \ v_) noexcept : v(normalize(v_)) {}\n\n    static mint raw(u32 a) {\n       \
    \ mint m;\n        m.v = a;\n        return m;\n    }\n    constexpr u32 val()\
    \ const noexcept { return v; }\n    constexpr mint& operator+=(const mint& rhs)\
    \ noexcept {\n        v += rhs.val();\n        if (v >= _mod) {\n            v\
    \ -= _mod;\n        }\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ mint& rhs) noexcept {\n        v += _mod - rhs.val();\n        if (v >= _mod)\
    \ {\n            v -= _mod;\n        }\n        return (*this);\n    }\n    constexpr\
    \ mint& operator*=(const mint& rhs) noexcept {\n        v = (u64)v * rhs.val()\
    \ % _mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const noexcept {\n        return mint(*this) += r;\n    }\n    constexpr\
    \ mint operator-(const mint& r) const noexcept {\n        return mint(*this) -=\
    \ r;\n    }\n    constexpr mint operator*(const mint& r) const noexcept {\n  \
    \      return mint(*this) *= r;\n    }\n\n    constexpr mint& operator+=(i64 rhs)\
    \ noexcept {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n\
    \    constexpr mint& operator-=(i64 rhs) noexcept {\n        (*this) -= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator*=(i64 rhs) noexcept\
    \ {\n        (*this) *= mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ friend mint operator+(i64 l, const mint& r) noexcept {\n        return mint(l)\
    \ += r;\n    }\n    constexpr friend mint operator-(i64 l, const mint& r) noexcept\
    \ {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(i64\
    \ l, const mint& r) noexcept {\n        return mint(l) *= r;\n    }\n\n    constexpr\
    \ mint operator+(i64 r) const noexcept { return mint(*this) += r; }\n    constexpr\
    \ mint operator-(i64 r) const noexcept { return mint(*this) -= r; }\n    constexpr\
    \ mint operator*(i64 r) const noexcept { return mint(*this) *= r; }\n\n    constexpr\
    \ mint& operator=(i64 r) noexcept { return (*this) = mint(r); }\n\n    constexpr\
    \ bool operator==(const mint& r) const noexcept {\n        return (*this).val()\
    \ == r.val();\n    }\n\n    template <typename T, internal::is_integral_t<T>*\
    \ = nullptr>\n    constexpr mint pow(T e) const noexcept {\n        mint ans(1),\
    \ base(*this);\n        while (e) {\n            if (e & 1) {\n              \
    \  ans *= base;\n            }\n            base *= base;\n            e >>= 1;\n\
    \        }\n        return ans;\n    }\n\n    constexpr mint inv() const noexcept\
    \ {\n        long long x, y;\n        auto d = ext_gcd((long long)_mod, (long\
    \ long)v, x, y);\n        assert(d == 1);\n        return mint(y);\n    }\n\n\
    \    constexpr mint& operator/=(const mint& r) noexcept {\n        return (*this)\
    \ *= r.inv();\n    }\n    constexpr mint operator/(const mint& r) const noexcept\
    \ {\n        return mint(*this) *= r.inv();\n    }\n    constexpr friend mint\
    \ operator/(const mint& l, i64 r) noexcept {\n        return mint(l) /= mint(r);\n\
    \    }\n    constexpr friend mint operator/(i64 l, const mint& r) noexcept {\n\
    \        return mint(l) /= mint(r);\n    }\n};\n};  // namespace kyopro\n\n/**\n\
    \ * @brief static modint\n */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n\
    #include <stdio.h>\n#include <string>\n#line 6 \"src/stream.hpp\"\n\nnamespace\
    \ kyopro {\n\ninline void single_read(char& c) {\n    c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n}\ntemplate <typename T, internal::is_integral_t<T>*\
    \ = nullptr>\ninline void single_read(T& a) {\n    a = 0;\n    bool is_negative\
    \ = false;\n    char c = getchar_unlocked();\n    while (isspace(c)) {\n     \
    \   c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true, c =\
    \ getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 * a + (c - '0');\n\
    \        c = getchar_unlocked();\n    }\n    if (is_negative) a *= -1;\n}\ntemplate\
    \ <typename T, internal::is_modint_t<T>* = nullptr>\ninline void single_read(T&\
    \ a) {\n    long long x;\n    single_read(x);\n    a = T(x);\n}\ninline void single_read(std::string&\
    \ str) noexcept {\n    char c = getchar_unlocked();\n    while (isspace(c)) c\
    \ = getchar_unlocked();\n    while (!isspace(c)) {\n        str += c;\n      \
    \  c = getchar_unlocked();\n    }\n}\ntemplate<typename T>\ninline void read(T&\
    \ x) noexcept {single_read(x);}\ntemplate <typename Head, typename... Tail>\n\
    inline void read(Head& head, Tail&... tail) noexcept {\n    single_read(head),\
    \ read(tail...);\n}\n\ninline void single_write(char c) noexcept { putchar_unlocked(c);\
    \ }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\ninline void\
    \ single_write(T a) noexcept {\n    if (!a) {\n        putchar_unlocked('0');\n\
    \        return;\n    }\n    if constexpr (std::is_signed_v<T>) {\n        if\
    \ (a < 0) putchar_unlocked('-'), a *= -1;\n    }\n    constexpr int d = std::numeric_limits<T>::digits10;\n\
    \    char s[d + 1];\n    int now = d + 1;\n    while (a) {\n        s[--now] =\
    \ (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now <= d) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T, internal::is_modint_t<T>* = nullptr>\ninline void single_write(T\
    \ a) noexcept {\n    single_write(a.val());\n}\ninline void single_write(const\
    \ std::string& str) noexcept {\n    for (auto c : str) {\n        putchar_unlocked(c);\n\
    \    }\n}\ntemplate <typename T> inline void write(T x) noexcept { single_write(x);\
    \ }\ntemplate <typename Head, typename... Tail>\ninline void write(Head head,\
    \ Tail... tail) noexcept {\n    single_write(head);\n    putchar_unlocked(' ');\n\
    \    write(tail...);\n}\ntemplate <typename... Args> inline void put(Args... x)\
    \ noexcept {\n    write(x...);\n    putchar_unlocked('\\n');\n}\n};  // namespace\
    \ kyopro\n\n/**\n * @brief \u9AD8\u901F\u5165\u51FA\u529B\n */\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\n#define rep(i, n) for (int i = 0; i < (n); i++)\n\
    #define all(x) std::begin(x), std::end(x)\n#define popcount(x) __builtin_popcountll(x)\n\
    using i128 = __int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = std::numeric_limits<int>::max() / 2;\nconstexpr ll infl = std::numeric_limits<ll>::max()\
    \ / 2;\nconst long double pi = acosl(-1);\nconstexpr int dx[] = {1, 0, -1, 0,\
    \ 1, -1, -1, 1, 0};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\ntemplate\
    \ <typename T1, typename T2> constexpr inline bool chmax(T1& a, T2 b) {\n    return\
    \ a < b && (a = b, true);\n}\ntemplate <typename T1, typename T2> constexpr inline\
    \ bool chmin(T1& a, T2 b) {\n    return a > b && (a = b, true);\n}\n#line 2 \"\
    src/internal/CSR.hpp\"\n\n#line 7 \"src/internal/CSR.hpp\"\n\nnamespace kyopro\
    \ {\nnamespace internal {\n\ntemplate <typename T, typename _size_t> class csr\
    \ {\n    _size_t n;\n    std::vector<T> d;\n    std::vector<_size_t> ssum;\n\n\
    public:\n    csr() = default;\n    csr(_size_t n, const std::vector<std::pair<_size_t,\
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
    \u5F0F\n */\n#line 4 \"src/tree/HeavyLightDecomposition.hpp\"\n\nnamespace kyopro\
    \ {\n\nclass HeavyLightDecomposition {\n    int root, id;\n    int n;\n\n    std::vector<std::pair<int,\
    \ int>> es;\n    std::vector<int> sz, dep, in, out, nxt, par;\n\npublic:\n   \
    \ HeavyLightDecomposition(int n)\n        : n(n),\n          es(),\n         \
    \ sz(n),\n          dep(n),\n          in(n, -1),\n          out(n, -1),\n   \
    \       nxt(n, root),\n          par(n, root) {\n        es.reserve(2 * (n - 1));\n\
    \    }\n\n    void add_edge(int u, int v) {\n        es.emplace_back(u, v);\n\
    \        es.emplace_back(v, u);\n    }\n\n    std::pair<int, int> idx(int i) const\
    \ { return std::pair(in[i], out[i]); }\n\n    void build(int root) {\n       \
    \ internal::csr g(n, es);\n        {\n            auto dfs_sz = [&](auto f, int\
    \ cur) -> void {\n                sz[cur] = 1;\n\n                for (auto& dst\
    \ : g[cur]) {\n                    if (dst == par[cur]) {\n                  \
    \      if (g[cur].size() >= 2 && dst == g[cur][0]) {\n                       \
    \     std::swap(g[cur][0], g[cur][1]);\n                        } else {\n   \
    \                         continue;\n                        }\n             \
    \       }\n\n                    dep[dst] = dep[cur] + 1;\n                  \
    \  par[dst] = cur;\n                    f(f, dst);\n                    sz[cur]\
    \ += sz[dst];\n\n                    if (sz[dst] > sz[g[cur][0]]) {\n        \
    \                std::swap(dst, g[cur][0]);\n                    }\n         \
    \       }\n            };\n            dfs_sz(dfs_sz, root);\n        }\n    \
    \    {\n            auto dfs_hld = [&](auto f, int cur) -> void {\n          \
    \      in[cur] = id++;\n                for (auto dst : g[cur]) {\n          \
    \          if (dst == par[cur]) continue;\n\n                    nxt[dst] = (dst\
    \ == g[cur][0] ? nxt[cur] : dst);\n                    f(f, dst);\n          \
    \      }\n                out[cur] = id;\n            };\n            dfs_hld(dfs_hld,\
    \ root);\n        }\n    }\n\nprivate:\n    std::vector<std::pair<int, int>> ascend(int\
    \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u], in[nxt[u]]);\n   \
    \         u = par[nxt[u]];\n        }\n\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    std::vector<std::pair<int, int>>\
    \ descend(int u, int v) const {\n        if (u == v) return {};\n        if (nxt[u]\
    \ == nxt[v]) return {{in[u] + 1, in[v]}};\n        std::vector res = descend(u,\
    \ par[nxt[v]]);\n        res.emplace_back(in[nxt[v]], in[v]);\n        return\
    \ res;\n    }\n\npublic:\n    int lca(int a, int b) const {\n        while (nxt[a]\
    \ != nxt[b]) {\n            if (in[a] < in[b]) std::swap(a, b);\n            a\
    \ = par[nxt[a]];\n        }\n        return dep[a] < dep[b] ? a : b;\n    }\n\n\
    \    int dist(int a, int b) const {\n        return dep[a] + dep[b] - 2 * dep[lca(a,\
    \ b)];\n    }\n\n    template <typename F> void path_query(int u, int v, const\
    \ F& f) {\n        int l = lca(u, v);\n\n        for (const auto&& [a, b] : ascend(u,\
    \ l)) {\n            int s = a + 1, t = b;\n            if (s < t) {\n       \
    \         f(s, t);\n            } else {\n                f(t, s);\n         \
    \   }\n        }\n        f(in[l], in[l] + 1);\n        for (const auto&& [a,\
    \ b] : descend(l, v)) {\n            int s = a, t = b + 1;\n            if (s\
    \ < t) {\n                f(s, t);\n            } else {\n                f(t,\
    \ s);\n            }\n        }\n    }\n\n    template <typename F>\n    void\
    \ path_noncommutative_query(int u, int v, const F& f) {\n        int l = lca(u,\
    \ v);\n        for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);\n        f(in[l],\
    \ in[l] + 1);\n        for (auto&& [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\
    \n    template <typename F> void subtree_query(int u, const F& f) {\n        f(in[u],\
    \ out[u]);\n    }\n};\n};  // namespace kyopro\n\n/**\n * @brief Heavy Light Decomposition\n\
    \ * @see https://nyaannyaan.github.io/library/tree/heavy-light-decomposition.hpp\n\
    \ */\n#line 8 \"test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp\"\n\n\
    using namespace std;\nusing namespace kyopro;\n\nusing mint = modint<998244353>;\n\
    using affine = pair<mint, mint>;\n\naffine composite(affine x, affine y) noexcept\
    \ {\n    return affine(x.first * y.first, x.second * y.first + y.second);\n}\n\
    affine id() noexcept { return affine(mint::raw(1), mint()); }\n\naffine op1(affine\
    \ x, affine y) { return composite(x, y); }\naffine op2(affine x, affine y) { return\
    \ composite(y, x); }\n\nint main() {\n    int n, q;\n    read(n, q);\n    vector<mint>\
    \ a(n), b(n);\n    rep(i, n) read(a[i], b[i]);\n\n    HeavyLightDecomposition\
    \ g(n);\n    rep(i, n - 1) {\n        int u, v;\n        read(u, v);\n       \
    \ g.add_edge(u, v);\n    }\n    g.build(0);\n\n    segtree<affine, op1, id> sg1(n);\n\
    \    segtree<affine, op2, id> sg2(n);\n\n    rep(i, n) {\n        int j = g.idx(i).first;\n\
    \        sg1.set(j, affine(a[i], b[i]));\n        sg2.set(j, affine(a[i], b[i]));\n\
    \    }\n    sg1.build(), sg2.build();\n\n    while (q--) {\n        int c, x,\
    \ y, z;\n        read(c, x, y, z);\n\n        if (c == 0) {\n            int j\
    \ = g.idx(x).first;\n            sg1.update(j, affine(mint(y), mint(z)));\n  \
    \          sg2.update(j, affine(mint(y), mint(z)));\n        } else {\n      \
    \      mint ans = mint::raw(z);\n\n            auto f = [&](int l, int r) {\n\
    \                if (l <= r) {\n                    auto [s, t] = sg1.fold(l,\
    \ r);\n                    ans = s * ans + t;\n                } else {\n    \
    \                auto [s, t] = sg2.fold(r, l);\n                    ans = s *\
    \ ans + t;\n                }\n            };\n\n            g.path_noncommutative_query(x,\
    \ y, f);\n            put(ans);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../../../src/data-structure/segtree.hpp\"\n#include \"../../../src/math/static_modint.hpp\"\
    \n#include \"../../../src/stream.hpp\"\n#include \"../../../src/template.hpp\"\
    \n#include \"../../../src/tree/HeavyLightDecomposition.hpp\"\n\nusing namespace\
    \ std;\nusing namespace kyopro;\n\nusing mint = modint<998244353>;\nusing affine\
    \ = pair<mint, mint>;\n\naffine composite(affine x, affine y) noexcept {\n   \
    \ return affine(x.first * y.first, x.second * y.first + y.second);\n}\naffine\
    \ id() noexcept { return affine(mint::raw(1), mint()); }\n\naffine op1(affine\
    \ x, affine y) { return composite(x, y); }\naffine op2(affine x, affine y) { return\
    \ composite(y, x); }\n\nint main() {\n    int n, q;\n    read(n, q);\n    vector<mint>\
    \ a(n), b(n);\n    rep(i, n) read(a[i], b[i]);\n\n    HeavyLightDecomposition\
    \ g(n);\n    rep(i, n - 1) {\n        int u, v;\n        read(u, v);\n       \
    \ g.add_edge(u, v);\n    }\n    g.build(0);\n\n    segtree<affine, op1, id> sg1(n);\n\
    \    segtree<affine, op2, id> sg2(n);\n\n    rep(i, n) {\n        int j = g.idx(i).first;\n\
    \        sg1.set(j, affine(a[i], b[i]));\n        sg2.set(j, affine(a[i], b[i]));\n\
    \    }\n    sg1.build(), sg2.build();\n\n    while (q--) {\n        int c, x,\
    \ y, z;\n        read(c, x, y, z);\n\n        if (c == 0) {\n            int j\
    \ = g.idx(x).first;\n            sg1.update(j, affine(mint(y), mint(z)));\n  \
    \          sg2.update(j, affine(mint(y), mint(z)));\n        } else {\n      \
    \      mint ans = mint::raw(z);\n\n            auto f = [&](int l, int r) {\n\
    \                if (l <= r) {\n                    auto [s, t] = sg1.fold(l,\
    \ r);\n                    ans = s * ans + t;\n                } else {\n    \
    \                auto [s, t] = sg2.fold(r, l);\n                    ans = s *\
    \ ans + t;\n                }\n            };\n\n            g.path_noncommutative_query(x,\
    \ y, f);\n            put(ans);\n        }\n    }\n}\n"
  dependsOn:
  - src/data-structure/segtree.hpp
  - src/math/static_modint.hpp
  - src/internal/type_traits.hpp
  - src/math/gcd.hpp
  - src/stream.hpp
  - src/template.hpp
  - src/tree/HeavyLightDecomposition.hpp
  - src/internal/CSR.hpp
  isVerificationFile: true
  path: test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 17:11:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp
- /verify/test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp.html
title: test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp
---
