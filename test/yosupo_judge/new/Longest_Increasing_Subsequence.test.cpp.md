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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\nusing S =\
    \ P;\nS op(S x, S y) { return max(x,y); }\nS e() { return P(0,0); }\nint main()\
    \ {\n    int n;\n    scanf(\"%d\", &n);\n    vector<int> a(n);\n    for (auto&\
    \ aa : a) {\n        scanf(\"%d\", &aa);\n    }\n    {\n        vector<int> tmp\
    \ = a;\n        sort(all(tmp));\n        tmp.erase(unique(all(tmp)), tmp.end());\n\
    \        for (auto& aa : a) {\n            aa = lower_bound(all(tmp), aa) - tmp.begin();\n\
    \        }\n    }\n    vector<int> prv(n, -1);\n    iota(all(prv), 0);\n    segtree<S,\
    \ op, e> dp(n + 1);\n    rep(i, n) {\n        auto [mx, p] = dp.prod(0, a[i]);\n\
    \        if (mx + 1 >= dp[a[i]].first) {\n            prv[i] = p;\n          \
    \  dp.update(a[i], P(mx + 1, i));\n        }\n    }\n    auto [res, cur] = dp.prod(0,\
    \ n + 1);\n    vector<int> idx;\n    idx.reserve((size_t)res);\n    rep(i, res)\
    \ {\n        idx.emplace_back(cur);\n        cur = prv[cur];\n    }\n    printf(\"\
    %lld\\n\", idx.size());\n    reverse(all(idx));\n    for (auto& i : idx) {\n \
    \       printf(\"%d \", i);\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/new/Longest_Increasing_Subsequence.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/new/Longest_Increasing_Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/new/Longest_Increasing_Subsequence.test.cpp
- /verify/test/yosupo_judge/new/Longest_Increasing_Subsequence.test.cpp.html
title: test/yosupo_judge/new/Longest_Increasing_Subsequence.test.cpp
---
