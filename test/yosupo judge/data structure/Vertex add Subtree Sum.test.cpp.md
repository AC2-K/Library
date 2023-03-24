---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: data-structure/sparse_table.hpp
    title: Sparse Table
  - icon: ':question:'
    path: graph/euler_tour.hpp
    title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
  - icon: ':question:'
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/segtree.hpp: line 7: #pragma once found in a non-first line\n"
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
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
- /verify/test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp.html
title: test/yosupo judge/data structure/Vertex add Subtree Sum.test.cpp
---
