---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/range_reverse_range_sum
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../src/BST/Reversible.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\
    \n#include \"../../src/BST/Reversible.hpp\"\n#include <iostream>\nusing ll = long\
    \ long;\ninline ll op(ll x, ll y) { return x + y; }\ninline ll e() { return 0;\
    \ }\nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n    kyopro::ReversibleBST<ll,\
    \ op, e> bst;\n    for (int i = 0; i < n; i++) {\n        int a;\n        scanf(\"\
    %d\", &a);\n        bst.insert(i, a);\n    }\n\n    while (q--) {\n        int\
    \ t, l, r;\n        scanf(\"%d%d%d\", &t, &l, &r);\n        if (!t) {\n      \
    \      bst.reverse(l, r);\n        } else {\n            printf(\"%lld\\n\", bst.fold(l,\
    \ r));\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/yosupo_judge/new/Range_Reverse_Range_Sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo_judge/new/Range_Reverse_Range_Sum.hpp
layout: document
redirect_from:
- /library/test/yosupo_judge/new/Range_Reverse_Range_Sum.hpp
- /library/test/yosupo_judge/new/Range_Reverse_Range_Sum.hpp.html
title: test/yosupo_judge/new/Range_Reverse_Range_Sum.hpp
---
