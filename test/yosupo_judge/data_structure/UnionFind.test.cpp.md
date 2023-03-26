---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dsu.hpp
    title: Disjoint Set(Union find)
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
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
    \ data-structure/dsu.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include\"\
    template.hpp\"\n#include\"data-structure/dsu.hpp\"\nint main() {\n    int n,q;\n\
    \    cin>>n>>q;\n    DSU dsu(n);\n    while(q--){\n        int t,x,y;\n      \
    \  cin>>t>>x>>y;\n        if(t==0){\n            dsu.merge(x,y);\n        }else{\n\
    \            if(dsu.same(x,y))cout<<\"1\\n\";\n            else cout<<\"0\\n\"\
    ;\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/dsu.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2023-03-26 20:22:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/UnionFind.test.cpp
- /verify/test/yosupo_judge/data_structure/UnionFind.test.cpp.html
title: test/yosupo_judge/data_structure/UnionFind.test.cpp
---