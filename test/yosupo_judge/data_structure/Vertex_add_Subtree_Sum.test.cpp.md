---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include\"template.hpp\"\n#include\"data-structure/BIT.hpp\"\n#include\"graph/euler_tour.hpp\"\
    \nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n);\n    for\
    \ (auto& aa : a) {\n        cin >> aa;\n    }\n\n    EulerTour g(n);\n    for\
    \ (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n        g.add_edge(i,\
    \ p);\n    }\n    g.build();\n\n    BIT<ll> seg(2 * n);\n    for (int v = 0; v\
    \ < n; v++) {\n        int in = g.idx(v).first;\n        seg.add(in, a[v]);\n\
    \    }\n    while (q--) {\n        int t;\n        cin >> t;\n        if (t ==\
    \ 0) {\n            int v;\n            cin >> v;\n            int x;\n      \
    \      cin >> x;\n            int in = g.idx(v).first;\n            seg.add(in,\
    \ x);\n        }\n        else {\n            int v;\n            cin >> v;\n\
    \            int in, out;\n            tie(in, out) = g.idx(v);\n            cout\
    \ << seg.sum(in,out + 1) << '\\n';\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
---
