---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy_segtree.hpp
    title: "Segment Tree with Lazy Propagation(\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
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
    \ data-structure/lazy_segtree.hpp: line 4: #pragma once found in a non-first line\n"
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
  dependsOn:
  - template.hpp
  - data-structure/lazy_segtree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2/D.test.cpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2/D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2/D.test.cpp
- /verify/test/AOJ/DSL/2/D.test.cpp.html
title: test/AOJ/DSL/2/D.test.cpp
---
