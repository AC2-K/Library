---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.hpp
    title: "segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.hpp
    title: sparse table
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/segtree.hpp\"\
    \ntemplate<class S, S(*op)(S, S), S(*e)()>\nclass segtree {\n    int n;\n    vector<S>\
    \ dat;\n    void Init(int n_) {\n        int x = 1;\n        while (n_ > x) {\n\
    \            x <<= 1;\n        }\n        n = x;\n    }\npublic:\n    segtree(int\
    \ n_) : segtree(vector<S>(n_, e())) {   }\n    segtree(const vector<S>& v) :dat(4\
    \ * v.size()) {\n        Init(v.size());\n        for (int i = 0; i < v.size();\
    \ i++) {\n            set(i, v[i]);\n        }\n        build();\n    }\n    inline\
    \ void set(int pos, S val) {\n        assert(0 <= pos && pos < n);\n        dat[pos\
    \ + n - 1] = val;\n    }\n    void build() {\n        for (int k = n - 2; k >=\
    \ 0; k--) {\n            dat[k] = op(dat[(k << 1) + 1], dat[(k << 1) + 2]);\n\
    \        }\n    }\n\n    void update(int pos, S val) {\n        assert(0 <= pos\
    \ && pos < n);\n        pos += n - 1;\n        dat[pos] = val;\n        while\
    \ (pos > 0) {\n            pos = (pos - 1) >> 1;\n            dat[pos] = op(dat[(pos\
    \ << 1) + 1], dat[(pos << 1) + 2]);\n        }\n    }\n    inline S prod(int a,\
    \ int b) {\n        assert(0 <= a && b <= n);\n        assert(a <= b);\n     \
    \   if (a == 0 && b == n)return dat[0];\n        return prod(a, b, 0, 0, n);\n\
    \    }\n\nprivate:\n    S prod(int a, int b, int id, int l, int r) {\n       \
    \ if (r <= a || b <= l) {\n            return e();\n        }\n        else if\
    \ (a <= l && r <= b) {\n            return dat[id];\n        }\n        else {\n\
    \            int mid = (l + r) >> 1;\n            S vl = prod(a, b, (id << 1)\
    \ + 1, l, mid);\n            S vr = prod(a, b, (id << 1) + 2, mid, r);\n     \
    \       return op(vl, vr);\n        }\n    }\n\npublic:\n    //a[pos] <- a[pos]\u30FB\
    x\n    void add(int pos, S x) {\n        update(pos, op(dat[n + pos - 1], x));\n\
    \    }\n\n    S operator [](int pos) {\n        return dat[n + pos - 1];\n   \
    \ }\n};\n/// @brief segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n///@docs\
    \ docs/data-structure/segtree.md\n#line 1 \"data-structure/sparse_table.hpp\"\n\
    template<class T>\nclass sparse_table {\n    vector<T> vec;\n    vector<vector<T>>\
    \ table;\n    vector<int> look_up;\npublic:\n    sparse_table(int n) :vec(n) {}\n\
    \    sparse_table(const vector<T>& vec = {}) :vec(vec) {}\n    void set(int p,\
    \ const T& v) {\n        vec[p] = v;\n    }\n    void build() {\n        int sz\
    \ = vec.size();\n        int log = 0;\n        while ((1 << log) <= sz) {\n  \
    \          log++;\n        }\n        table.assign(log, vector<T>(1 << log));\n\
    \        for (int i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n \
    \       }\n        for (int i = 1; i < log; i++) {\n            for (int j = 0;\
    \ j + (1 << i) <= (1 << log); j++) {\n                table[i][j] = min(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    \
    \    look_up.resize(sz + 1);\n        for (int i = 2; i < look_up.size(); i++)\
    \ {\n            look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n    T\
    \ prod(int l, int r) {\n        int b = look_up[r - l];\n        return min(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n///@brief sparse table\n#line 2 \"graph/euler_tour.hpp\"\
    \nclass EulerTour {\n\tint n;\n\tgraph g;\n\tvector<int> tour;\n\tvector<int>\
    \ in, out, depth;\n    sparse_table<pair<int, int>> rmq;\npublic:\n    EulerTour(int\
    \ n) :n(n), g(n), in(n, -1), out(n, -1), depth(n, -1), rmq(2 * n - 1) { tour.reserve(2\
    \ * n - 1); }\n\tvoid add_edge(int u, int v) {\n\t\tg[u].emplace_back(v);\n\t\t\
    g[v].emplace_back(u);\n\t}\n    graph get_graph(){return g;}\nprivate:\n    void\
    \ dfs(int v, int p = -1) {\n        in[v] = tour.size();\n        tour.emplace_back(v);\n\
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
    \ <= out[par]);}\n};\n///@brief EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
    \u30FC)\n#line 5 \"test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp\"\
    \nll op(ll x, ll y) { return x + y; }\n\nll e() { return 0; }\nint main() {\n\
    \    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n);\n    for (auto& aa :\
    \ a) {\n        cin >> aa;\n    }\n\n    EulerTour g(n);\n    for (int i = 1;\
    \ i < n; i++) {\n        int p;\n        cin >> p;\n        g.add_edge(i, p);\n\
    \    }\n    g.build();\n\n    segtree<ll, op, e> seg(2 * n);\n    for (int v =\
    \ 0; v < n; v++) {\n        int in = g.idx(v).first;\n        seg.set(in, a[v]);\n\
    \    }\n    seg.build();\n    while (q--) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int v;\n            cin >> v;\n          \
    \  int x;\n            cin >> x;\n            int in = g.idx(v).first;\n     \
    \       seg.add(in, x);\n        }\n        else {\n            int v;\n     \
    \       cin >> v;\n            int in, out;\n            tie(in, out) = g.idx(v);\n\
    \            cout << seg.prod(in,out + 1) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\n#include\"\
    graph/euler_tour.hpp\"\nll op(ll x, ll y) { return x + y; }\n\nll e() { return\
    \ 0; }\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n);\n\
    \    for (auto& aa : a) {\n        cin >> aa;\n    }\n\n    EulerTour g(n);\n\
    \    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n      \
    \  g.add_edge(i, p);\n    }\n    g.build();\n\n    segtree<ll, op, e> seg(2 *\
    \ n);\n    for (int v = 0; v < n; v++) {\n        int in = g.idx(v).first;\n \
    \       seg.set(in, a[v]);\n    }\n    seg.build();\n    while (q--) {\n     \
    \   int t;\n        cin >> t;\n        if (t == 0) {\n            int v;\n   \
    \         cin >> v;\n            int x;\n            cin >> x;\n            int\
    \ in = g.idx(v).first;\n            seg.add(in, x);\n        }\n        else {\n\
    \            int v;\n            cin >> v;\n            int in, out;\n       \
    \     tie(in, out) = g.idx(v);\n            cout << seg.prod(in,out + 1) << '\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  - graph/euler_tour.hpp
  - data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
  requiredBy: []
  timestamp: '2023-03-20 21:23:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
- /verify/test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp.html
title: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
---
