---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: internal/CSR.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n#include \"../../../src/math/static_modint.hpp\"\n#include \"../../../src/stream.hpp\"\
    \n#include \"../../../src/template.hpp\"\n#include \"../../../src/tree/Rerooting.hpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nusing mint = modint<998244353>;\n\
    \nint main() {\n    int n;\n    read(n);\n    vector<mint> a(n), b(n - 1), c(n\
    \ - 1);\n    rep(i, n) read(a[i]);\n\n    auto op = [&](pair<mint, mint> x, pair<mint,\
    \ mint> y) {\n        return pair(x.first + y.first, x.second + y.second);\n \
    \   };\n    auto put_edge_vertex = [&](pair<mint, mint> x, int e, int) {\n   \
    \     return pair(b[e] * x.first + c[e] * x.second, x.second);\n    };\n    auto\
    \ leaf = [&](int v) { return pair(a[v], mint::raw(1)); };\n\n    Rerooting<pair<mint,\
    \ mint>, decltype(op), decltype(put_edge_vertex),\n              decltype(leaf)>\n\
    \        t(n, pair<mint, mint>(), op, put_edge_vertex, leaf);\n\n    rep(i, n\
    \ - 1) {\n        int u, v;\n        read(u, v, b[i], c[i]);\n        t.add_edge(u,\
    \ v, i);\n    }\n    vector answer = t.run();\n    rep(i, n) put(answer[i].first\
    \ + a[i]);\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp
- /verify/test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp.html
title: test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp
---
