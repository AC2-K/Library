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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n#include\"template.hpp\"\n#include\"other/mo.hpp\"\nint main() {\n    int n,\
    \ q;\n    scanf(\"%d%d\", &n, &q);\n\n    vector<int> a(n);\n    for (auto& aa\
    \ : a) {\n        scanf(\"%d\", &aa);\n    }\n    auto pressed = a;\n    sort(pressed.begin(),\
    \ pressed.end());\n    pressed.erase(unique(pressed.begin(), pressed.end()), pressed.end());\n\
    \    for (auto& ai : a) {\n        ai = lower_bound(pressed.begin(), pressed.end(),\
    \ ai) - pressed.begin();\n    }\n    Mo mo(q);\n    vector<int> x(q);\n    for\
    \ (int i = 0; i < q; i++) {\n        int l, r;\n        scanf(\"%d%d%d\\n\", &l,\
    \ &r, &x[i]);\n        mo.add(l, r);\n    }\n\n    vector<int> cnt(pressed.size()\
    \ + 1);\n    vector<int> ans(q);\n    auto add = [&](int v) -> void {\n      \
    \  cnt[a[v]]++;\n    };\n    auto del = [&](int v) -> void {\n        cnt[a[v]]--;\n\
    \    };\n    auto out = [&](int v) -> void {\n        auto it = lower_bound(all(pressed),\
    \ x[v]);\n        if (it == pressed.end() || (*it) != x[v]) {\n            ans[v]\
    \ = 0;\n        } else {\n            int xi = it - pressed.begin();\n       \
    \     ans[v] = cnt[xi];\n        }\n    };\n    mo.build(add, del, out);\n   \
    \ for (auto& aa : ans) {\n        printf(\"%d\\n\", aa);\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp.html
title: test/yosupo_judge/data_structure/Static_Range_Frequency_Mo.test.cpp
---
