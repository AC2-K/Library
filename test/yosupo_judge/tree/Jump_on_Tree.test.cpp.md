---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: stream.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n#include\
    \ \"stream.hpp\"\n#include \"tree/doubling.hpp\"\nint main() {\n    int n, q;\n\
    \    kyopro::readint(n, q);\n    kyopro::doubling_on_tree g(n);\n    for (int\
    \ i = 0; i < n - 1; ++i) {\n        int a, b;\n        kyopro::readint(a, b);\n\
    \        g.add_edge(a, b);\n    }\n    g.build();\n\n    while (q--) {\n     \
    \   int s, t, i;\n        kyopro::readint(s, t, i);\n        kyopro::putint(g.jump(s,\
    \ t, i));\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Jump_on_Tree.test.cpp
- /verify/test/yosupo_judge/tree/Jump_on_Tree.test.cpp.html
title: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
---
