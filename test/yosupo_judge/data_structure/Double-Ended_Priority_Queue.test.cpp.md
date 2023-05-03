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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: BST/Treap.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include <iostream>\n#include \"BST/Treap.hpp\"\nusing namespace std;\nint\
    \ main() {\n    kyopro::Treap<int> st;\n    int n, q;\n    scanf(\"%d%d\", &n,\
    \ &q);\n    for (int i = 0; i < n; ++i) {\n        int a;\n        scanf(\"%d\"\
    , &a);\n        st.insert(a);\n    }\n    while (q--) {\n        int t;\n    \
    \    scanf(\"%d\", &t);\n        if (!t) {\n            int x;\n            scanf(\"\
    %d\", &x);\n            st.insert(x);\n        } else if (t == 1) {\n        \
    \    int mn = st.pop_front();\n            printf(\"%d\\n\", mn);\n          \
    \  st.erase(mn);\n\n        } else {\n            int mx = st.pop_back();\n  \
    \          printf(\"%d\\n\", mx);\n            st.erase(mx);\n        }\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
- /verify/test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp.html
title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
---
