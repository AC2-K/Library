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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\"\
    template.hpp\"\n#include\"graph/dijkstra.hpp\"\nint main() {\n    int n;\n   \
    \ cin>>n;\n    vector<vector<edge>> g(n);\n    rep(i,n-1){\n        int a,b,c;\n\
    \        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n        g[b].emplace_back(a,c);\n\
    \    }\n\n    auto dist=dijkstra(0,g).first;\n    ll dist_max=*max_element(all(dist));\n\
    \    int v=find(all(dist),dist_max)-dist.begin();\n    dist=dijkstra(v,g).first;\n\
    \    dist_max=*max_element(all(dist));\n    int u=find(all(dist),dist_max)-dist.begin();\n\
    \    cout<<dist_max<<' ';\n\n    int cur=u;\n    vector<int> ans;\n    while(cur!=v){\n\
    \        ans.emplace_back(cur);\n        for(auto&[p,c]:g[cur]){\n           \
    \ if(dist[p]+c==dist[cur]){\n                cur=p;\n                break;\n\
    \            }\n        }\n    }\n    ans.emplace_back(v);\n    cout<<ans.size()<<'\\\
    n';\n    for(auto&k:ans)cout<<k<<' ';\n    cout<<'\\n';\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/tree/Tree_Diameter.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/tree/Tree_Diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/tree/Tree_Diameter.test.cpp
- /verify/test/yosupo_judge/tree/Tree_Diameter.test.cpp.html
title: test/yosupo_judge/tree/Tree_Diameter.test.cpp
---
