---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/CHT.hpp
    title: Convex Hull Trick
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
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
    \ data-structure/CHT.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include\"template.hpp\"\n#include\"data-structure/CHT.hpp\"\n\nint main(){\n\
    \    int n,q;\n    cin>>n>>q;\n\n    CHT cht;    \n    for(int i=0;i<n;i++){\n\
    \        ll a,b;\n        cin>>a>>b;\n        cht.add(a,b);\n    }\n    while(q--){\n\
    \        int t;\n        cin>>t;\n        if(t==0){\n            ll a,b;\n   \
    \         cin>>a>>b;\n            cht.add(a,b);\n        }else{\n            ll\
    \ x;\n            cin>>x;\n            cout<<cht(x)<<'\\n';\n        }\n    }\n\
    }"
  dependsOn:
  - template.hpp
  - data-structure/CHT.hpp
  isVerificationFile: true
  path: test/yosupo judge/data structure/Line Add Get Min.test.cpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/data structure/Line Add Get Min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/data structure/Line Add Get Min.test.cpp
- /verify/test/yosupo judge/data structure/Line Add Get Min.test.cpp.html
title: test/yosupo judge/data structure/Line Add Get Min.test.cpp
---
