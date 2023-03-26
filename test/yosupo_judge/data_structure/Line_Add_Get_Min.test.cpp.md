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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include\"template.hpp\"\n#include\"data-structure/CHT.hpp\"\n\nint main(){\n\
    \    int n,q;\n    cin>>n>>q;\n\n    CHT cht;    \n    for(int i=0;i<n;i++){\n\
    \        ll a,b;\n        cin>>a>>b;\n        cht.add(a,b);\n    }\n    while(q--){\n\
    \        int t;\n        cin>>t;\n        if(t==0){\n            ll a,b;\n   \
    \         cin>>a>>b;\n            cht.add(a,b);\n        }else{\n            ll\
    \ x;\n            cin>>x;\n            cout<<cht(x)<<'\\n';\n        }\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
- /verify/test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp.html
title: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
---
