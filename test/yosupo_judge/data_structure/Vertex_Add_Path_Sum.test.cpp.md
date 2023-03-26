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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include\"template.hpp\"\n#include\"data-structure/BIT.hpp\"\n#include\"graph/euler_tour.hpp\"\
    \nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n);\n    for\
    \ (auto& aa : a) {\n        scanf(\"%lld\", &aa);\n    }\n\n    EulerTour g(n);\n\
    \    for (int i = 0; i < n - 1; i++) {\n        int v, u;\n        scanf(\"%d%d\"\
    , &v, &u);\n        g.add_edge(v, u);\n    }\n    g.build();\n\n    BIT<ll> seg(2\
    \ * n);\n    for (int v = 0; v < n; v++) {\n        auto [in, out] = g.idx(v);\n\
    \        seg.add(in, a[v]);\n        seg.add(out + 1, -a[v]);\n    }\n    while\
    \ (q--) {\n        int t;\n        scanf(\"%d\", &t);\n        if (t == 0) {\n\
    \            int v, x;\n            scanf(\"%d%d\", &v, &x);\n            auto\
    \ [in, out] = g.idx(v);\n            seg.add(in, x);\n            seg.add(out\
    \ + 1, -x);\n        } else {\n            int v, u;\n            scanf(\"%d%d\"\
    , &v, &u);\n            ll ans = 0;\n            int p_in = g.idx(g.lca(v, u)).first;\n\
    \            {\n                ans += seg.sum(p_in, g.idx(v).first + 1);\n  \
    \          }\n            {\n                ans += seg.sum(p_in + 1, g.idx(u).first\
    \ + 1);\n            }\n\n            printf(\"%lld\\n\", ans);\n        }\n \
    \   }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
---
