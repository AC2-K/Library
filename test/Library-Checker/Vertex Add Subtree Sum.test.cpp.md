---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.hpp
    title: segmenttree
  - icon: ':heavy_check_mark:'
    path: graph/euler_tour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
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
  bundledCode: "#line 1 \"test/Library-Checker/Vertex Add Subtree Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#line 1 \"graph/euler_tour.hpp\"\nclass EulerTour {\n\t\
    //\u3055\u3059\u304C\u306B\u6A5F\u80FD\u5C11\u306A\u3059\u304E\u308B?\n\tusing\
    \ graph = vector<vector<int>>;\n\tgraph g;\npublic:\n\tvector<int> in, out, depth,tour;\n\
    \    EulerTour(int n) :g(n), depth(n), in(n), out(n) {}\n\tvoid add_edge(int a,\
    \ int b) {\n\t\tg[a].emplace_back(b);\n\t\tg[b].emplace_back(a);\n\t}\n\n\tvoid\
    \ build(int root){\n\t\tdepth[root] = 0;\n\t\tfunction<void(int, int)> dfs = [&](int\
    \ v, int par = -1)-> void {\n\t\t\tin[v] = tour.size();\n\t\t\ttour.emplace_back(v);\n\
    \t\t\tfor (const auto& c : g[v])if (c != par) {\n\t\t\t\tdepth[c] = depth[v] +\
    \ 1;\n\t\t\t\tdfs(c, v);\n\t\t\t\ttour.emplace_back(v);\n\t\t\t}\n\t\t\tout[v]\
    \ = tour.size() - 1;\n\t\t};\n\t\tdfs(root, -1);\n\t}\n};\n///@brief \u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC\n#line 1 \"data-structure/segtree.hpp\"\ntemplate<class\
    \ S, S(*op)(S, S), S(*e)()>\nclass segtree {\n    int n;\n    vector<S> dat;\n\
    \    void Init(int n_) {\n        int x = 1;\n        while (n_ > x) {\n     \
    \       x <<= 1;\n        }\n        n = x;\n    }\npublic:\n    segtree(int n_)\
    \ : segtree(vector<S>(n_, e())) {   }\n    segtree(const vector<S>& v) :dat(4\
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
    \ }\n};\n/// @brief segmenttree\n#line 6 \"test/Library-Checker/Vertex Add Subtree\
    \ Sum.test.cpp\"\nusing S = long long;\nS op(S x, S y) { return x+y; }\nS e()\
    \ { return 0; }\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int>\
    \ a(n);\n    for (auto& aa : a) {\n        cin >> aa;\n    }\n    EulerTour et(n);\n\
    \    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n      \
    \  et.add_edge(p, i);\n    }\n    et.build(0);\n\n    segtree<S, op, e> seg(et.tour.size());\n\
    \    for (int v = 0; v < n; v++) {\n        seg.set(et.in[v], a[v]);\n    }\n\
    \    seg.build();\n    while (q--) {\n        int t;\n        cin >> t;\n    \
    \    if (t == 0) {\n            int v;\n            cin >> v;\n            int\
    \ x;\n            cin >> x;\n            seg.add(et.in[v], x);\n        }\n  \
    \      else {\n            int v;\n            cin >> v;\n            cout <<\
    \ seg.prod(et.in[v], et.out[v] + 1) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#include\"graph/euler_tour.hpp\"\
    \n#include\"data-structure/segtree.hpp\"\nusing S = long long;\nS op(S x, S y)\
    \ { return x+y; }\nS e() { return 0; }\nint main() {\n    int n, q;\n    cin >>\
    \ n >> q;\n    vector<int> a(n);\n    for (auto& aa : a) {\n        cin >> aa;\n\
    \    }\n    EulerTour et(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n\
    \        cin >> p;\n        et.add_edge(p, i);\n    }\n    et.build(0);\n\n  \
    \  segtree<S, op, e> seg(et.tour.size());\n    for (int v = 0; v < n; v++) {\n\
    \        seg.set(et.in[v], a[v]);\n    }\n    seg.build();\n    while (q--) {\n\
    \        int t;\n        cin >> t;\n        if (t == 0) {\n            int v;\n\
    \            cin >> v;\n            int x;\n            cin >> x;\n          \
    \  seg.add(et.in[v], x);\n        }\n        else {\n            int v;\n    \
    \        cin >> v;\n            cout << seg.prod(et.in[v], et.out[v] + 1) << '\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - graph/euler_tour.hpp
  - data-structure/segtree.hpp
  isVerificationFile: true
  path: test/Library-Checker/Vertex Add Subtree Sum.test.cpp
  requiredBy: []
  timestamp: '2023-02-21 12:21:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Library-Checker/Vertex Add Subtree Sum.test.cpp
layout: document
redirect_from:
- /verify/test/Library-Checker/Vertex Add Subtree Sum.test.cpp
- /verify/test/Library-Checker/Vertex Add Subtree Sum.test.cpp.html
title: test/Library-Checker/Vertex Add Subtree Sum.test.cpp
---
