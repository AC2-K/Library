---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.hpp
    title: data-structure/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: graph/euler_tour.hpp
    title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i,\
    \ N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int, int>;\n\
    constexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\n\
    const long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr\
    \ uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int\
    \ dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/segtree.hpp\"\
    \ntemplate<class S, S(*op)(S, S), S(*e)()>\nclass segtree {\n\tint lg, sz, n;\n\
    \tvector<S> dat;\n\npublic:\n\tsegtree() :segtree(0) {}\n\tsegtree(int n) : segtree(vector<S>(n,\
    \ e())) {}\n\tsegtree(const vector<S>& vec) : n((int)vec.size()) {\n\t\tsz = 1,\
    \ lg = 0;\n\t\twhile (sz <= n) {\n\t\t\tsz <<= 1;\n\t\t\tlg++;\n\t\t}\n\n\t\t\
    dat = vector<S>(sz << 1, e());\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tset(i,\
    \ vec[i]);\n\t\t}\n\t\tbuild();\n\t}\n\n\tinline void set(const int p, const S&\
    \ v) {\n\t\tdat[sz + p] = v;\n\t}\n\tinline void build() {\n\t\tfor (int i = sz\
    \ - 1; i > 0; i--) {\n\t\t\tdat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n\t\t\
    }\n\t}\n\tS operator[](const int p) const { return dat[sz + p]; }\n\n\tinline\
    \ void update(int p, const S& v) {\n\t\tp += sz;\n\t\tdat[p] = v;\n\t\twhile (p\
    \ >>= 1) {\n\t\t\tdat[p] = op(dat[(p << 1)], dat[(p << 1) ^ 1]);\n\t\t}\n\t}\n\
    \n\tinline S prod(int l, int r) const {\n\t\tl += sz, r += sz;\n\t\tS sml = e(),\
    \ smr = e();\n\t\twhile (l != r) {\n\t\t\tif (l & 1)sml = op(sml, dat[l++]);\n\
    \t\t\tif (r & 1)smr = op(dat[--r], smr);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\t\
    return op(sml, smr);\n\t}\n\tinline void apply(int p, const S& v) {\n\t\tupdate(p,\
    \ op(dat[sz + p], v));\n\t}\n};\n#line 1 \"data-structure/sparse_table.hpp\"\n\
    /// @brief Sparse Table\n/// @tparam T \u8981\u7D20\u306E\u578B\n/// @docs docs/data-structure/sparse_table.md\n\
    \ntemplate<class T>\nclass sparse_table {\n    vector<T> vec;\n    vector<vector<T>>\
    \ table;\n    vector<int> look_up;\npublic:\n    sparse_table(int n) : vec(n)\
    \ {}\n    sparse_table(const vector<T>& vec) : vec(vec) {}\n    void set(int p,\
    \ const T& v) { vec[p] = v; }\n    void build() {\n        int sz = vec.size();\n\
    \        int log = 0;\n        while ((1 << log) <= sz) {\n            log++;\n\
    \        }\n        table.assign(log, vector<T>(1 << log));\n        for (int\
    \ i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n        }\n      \
    \  for (int i = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <=\
    \ (1 << log); j++) {\n                table[i][j] =\n                    min(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    \
    \    look_up.resize(sz + 1);\n        for (int i = 2; i < look_up.size(); i++)\
    \ {\n            look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n    T\
    \ prod(int l, int r) {\n        int b = look_up[r - l];\n        return min(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n#line 2 \"graph/euler_tour.hpp\"\n\n///@brief\
    \ EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)\nclass EulerTour {\n\t\
    int n;\n\tgraph g;\n\tvector<int> tour;\n\tvector<int> in, out, depth;\n    sparse_table<pair<int,\
    \ int>> rmq;\npublic:\n    EulerTour(int n) :n(n), g(n), in(n, -1), out(n, -1),\
    \ depth(n, -1), rmq(2 * n - 1) { tour.reserve(2 * n - 1); }\n\tvoid add_edge(int\
    \ u, int v) {\n\t\tg[u].emplace_back(v);\n\t\tg[v].emplace_back(u);\n\t}\n   \
    \ graph get_graph(){return g;}\n    vector<int> get_tour(){return tour;}\nprivate:\n\
    \    void dfs(int v, int p = -1) {\n        in[v] = tour.size();\n        tour.emplace_back(v);\n\
    \        for (const auto& nv : g[v])if (nv != p) {\n            depth[nv] = depth[v]\
    \ + 1;\n            dfs(nv, v);\n            tour.emplace_back(v);\n        }\n\
    \        out[v] = tour.size() - 1;\n    }\npublic:\n    void build(int r = 0)\
    \ {\n        dfs(r);\n        for (int i = 0; i < tour.size(); i++) {\n      \
    \      rmq.set(i, { depth[tour[i]],tour[i] });\n        }\n        rmq.build();\n\
    \    }\n\n    pair<int, int> idx(int v) { return {in[v], out[v]}; }\n    int lca(int\
    \ v, int u) {\n        if (in[v] > in[u] + 1) { swap(u, v); }\n        return\
    \ rmq.prod(in[v], in[u] + 1).second;\n    }\n\n    int dist(int v,int u){\n  \
    \      int p = lca(v, u);\n        return depth[v] + depth[u] - 2 * depth[p];\n\
    \    }\n\n    bool is_in_subtree(int par,int v){return (in[par] <= in[v] && out[v]\
    \ <= out[par]);}\n};\n#line 5 \"test/yosupo judge/data structure/Vertex Add Path\
    \ Sum.test.cpp\"\nll op(ll x, ll y) { return x + y; }\n\nll e() { return 0; }\n\
    int main() {\n    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n);\n    for\
    \ (auto& aa : a) {\n        cin >> aa;\n    }\n\n    EulerTour g(n);\n    for\
    \ (int i = 0; i < n - 1; i++) {\n        int v, u;\n        cin >> v >> u;\n \
    \       g.add_edge(v, u);\n    }\n    g.build();\n\n    segtree<ll, op, e> seg(2\
    \ * n);\n    for (int v = 0; v < n; v++) {\n        auto [in, out] = g.idx(v);\n\
    \        seg.set(in, a[v]);\n        seg.set(out + 1, -a[v]);\n    }\n    seg.build();\n\
    \    while (q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n\
    \            int v, x;\n            cin >> v >> x;\n            auto [in, out]\
    \ = g.idx(v);\n            seg.apply(in, x);\n            seg.apply(out + 1, -x);\n\
    \        }\n        else {\n            int v, u;\n            cin >> v >> u;\n\
    \            ll ans = 0;\n            int p_in = g.idx(g.lca(v, u)).first;\n \
    \           {\n                ans += seg.prod(p_in, g.idx(v).first + 1);\n  \
    \          }\n            {\n                ans += seg.prod(p_in + 1, g.idx(u).first\
    \ + 1);\n            }\n\n            cout << ans << '\\n';\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\n#include\"graph/euler_tour.hpp\"\
    \nll op(ll x, ll y) { return x + y; }\n\nll e() { return 0; }\nint main() {\n\
    \    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n);\n    for (auto& aa :\
    \ a) {\n        cin >> aa;\n    }\n\n    EulerTour g(n);\n    for (int i = 0;\
    \ i < n - 1; i++) {\n        int v, u;\n        cin >> v >> u;\n        g.add_edge(v,\
    \ u);\n    }\n    g.build();\n\n    segtree<ll, op, e> seg(2 * n);\n    for (int\
    \ v = 0; v < n; v++) {\n        auto [in, out] = g.idx(v);\n        seg.set(in,\
    \ a[v]);\n        seg.set(out + 1, -a[v]);\n    }\n    seg.build();\n    while\
    \ (q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n        \
    \    int v, x;\n            cin >> v >> x;\n            auto [in, out] = g.idx(v);\n\
    \            seg.apply(in, x);\n            seg.apply(out + 1, -x);\n        }\n\
    \        else {\n            int v, u;\n            cin >> v >> u;\n         \
    \   ll ans = 0;\n            int p_in = g.idx(g.lca(v, u)).first;\n          \
    \  {\n                ans += seg.prod(p_in, g.idx(v).first + 1);\n           \
    \ }\n            {\n                ans += seg.prod(p_in + 1, g.idx(u).first +\
    \ 1);\n            }\n\n            cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  - graph/euler_tour.hpp
  - data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
  requiredBy: []
  timestamp: '2023-03-25 19:44:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
- /verify/test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp.html
title: test/yosupo judge/data structure/Vertex Add Path Sum.test.cpp
---
