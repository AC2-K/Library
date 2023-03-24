---
data:
  _extendedDependsOn:
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/sparse_table.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include\"template.hpp\"\
    \n#include\"graph/euler_tour.hpp\"\nint main(){\n    int n, q;\n    cin >> n >>\
    \ q;\n    EulerTour g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n\
    \        cin >> p;\n        g.add_edge(p, i);\n    }\n    g.build();\n    while\
    \ (q--) {\n        int u, v;\n        cin >> u >> v;\n        cout << g.lca(u,\
    \ v) << '\\n';\n    }\n}"
  dependsOn:
  - template.hpp
  - graph/euler_tour.hpp
  - data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
- /verify/test/yosupo judge/tree/Lowest Common Ancestor.test.cpp.html
title: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
---
