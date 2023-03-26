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
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n#include\"\
    template.hpp\"\n#include\"data-structure/segtree.hpp\"\nusing S=ll;\nS op(S x,S\
    \ y){return x+y;}\nS e(){return 0;}\nint main() {\n    int n,q;\n    cin>>n>>q;\n\
    \    segtree<S,op,e> seg(n);\n    while(q--){\n        int t;\n        cin>>t;\n\
    \        if(t==0){\n            ll i,x;\n            cin>>i>>x;\n            i--;\n\
    \            seg.apply(i,x);\n        }else{\n            int l,r;\n         \
    \   cin>>l>>r;\n            l--,r--;\n            cout<<seg.prod(l,r+1)<<'\\n';\n\
    \        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/AOJ/DSL/2/B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/DSL/2/B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2/B.test.cpp
- /verify/test/AOJ/DSL/2/B.test.cpp.html
title: test/AOJ/DSL/2/B.test.cpp
---
