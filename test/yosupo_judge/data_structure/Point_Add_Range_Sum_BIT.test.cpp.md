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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include\"template.hpp\"\n#include\"data-structure/BIT.hpp\"\nint main() {\n \
    \   int n, q;\n    cin >> n >> q;\n    BIT<ll, ll> seg(n);\n    rep(i,n){\n  \
    \      int a;\n        scanf(\"%d\", &a);\n        seg.add(i, a);\n    }\n\n \
    \   while (q--) {\n        int t;\n        scanf(\"%d\", &t);\n        if (t ==\
    \ 0) {\n            int p, x;\n            scanf(\"%d%d\", &p, &x);\n        \
    \    seg.add(p, x);\n        } else {\n            int l, r;\n            scanf(\"\
    %d%d\", &l, &r);\n            printf(\"%lld\\n\", seg.sum(l, r));\n        }\n\
    \    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp.html
title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
---
