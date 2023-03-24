---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/segtree.hpp: line 7: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\nusing S =\
    \ P;\nS op(S x, S y) { return max(x,y); }\nS e() { return P(0,0); }\nvector<int>\
    \ press(const vector<int>&A){\n    vector<int> B;\n    vector<int> T;\n    rep(i,A.size())T.push_back(A[i]);\n\
    \    sort(all(T));\n    T.erase(unique(all(T)),T.end());\n    rep(i,A.size()){\n\
    \        int pos=lower_bound(all(T),A[i])-T.begin();\n        B.push_back(pos);\n\
    \    }\n    return B;\n}\nint main() {\n    int n;\n    cin>>n;\n    vector<int>\
    \ a(n);\n    for(auto&aa:a){\n        cin>>aa;\n    }   \n    a=press(a);\n  \
    \  vector<int> prv(n,-1);\n    iota(all(prv),0);\n    segtree<S,op,e> dp(n+1);\n\
    \    rep(i,n){\n        auto[mx,p]=dp.prod(0,a[i]);\n        if(mx+1>=dp[a[i]].first){\n\
    \            prv[i]=p;\n            dp.update(a[i],P(mx+1,i));\n        }\n  \
    \  }\n    auto[res,cur]=dp.prod(0,n+1);\n    vector<int> idx;\n    rep(i,res){\n\
    \        idx.push_back(cur);\n        cur=prv[cur];\n    }\n    cout<<idx.size()<<'\\\
    n';\n    reverse(all(idx));\n    for(auto&i:idx){\n        cout<<i<<' ';\n   \
    \ }\n    cout<<'\\n';\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  isVerificationFile: true
  path: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
- /verify/test/yosupo judge/new/Longest Increasing Subsequence.test.cpp.html
title: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
---
