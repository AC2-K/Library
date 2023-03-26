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
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#include\"template.hpp\"\n#include\"data-structure/lazy_segtree.hpp\"\n\n\
    int op(int x,int y){return min(x,y);}\nint comp(int x,int y){return y;}\nint mapping(int\
    \ x,int y){return y;}\nint e(){return (1ll<<31)-1;}\nint id(){return (1ll<<31)-1;}\n\
    \nint main(){\n    int n,q;\n    cin>>n>>q;\n    lazy_segtree<int,int,op,e,comp,id,mapping>\
    \ seg(n);\n    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n\
    \            int l,r;\n            cin>>l>>r;\n            int new_val;\n    \
    \        cin>>new_val;\n            seg.apply(l,r+1,new_val);\n        }else{\n\
    \            int i;\n            cin>>i;\n            cout<<seg[i]<<'\\n';\n \
    \       }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/AOJ/DSL/2/D.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/DSL/2/D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2/D.test.cpp
- /verify/test/AOJ/DSL/2/D.test.cpp.html
title: test/AOJ/DSL/2/D.test.cpp
---
