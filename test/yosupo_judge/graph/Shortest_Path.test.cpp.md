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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\"\
    template.hpp\"\n#include\"graph/dijkstra.hpp\"\nint main() {\n    int n,m,s,t;\n\
    \    cin>>n>>m>>s>>t;\n    vector<vector<edge>> g(n);\n    rep(i,m){\n       \
    \ int a,b,c;\n        cin>>a>>b>>c;\n        g[a].emplace_back(b,c);\n    }\n\
    \    auto [dist,trace]=dijkstra(s,g);\n    if(dist[t]>=infl){\n        cout<<-1<<'\\\
    n';\n        return 0;\n    }\n\n    int cur=t;\n    vector<int> path;\n    while(cur!=trace[cur]){\n\
    \        path.emplace_back(cur);\n        cur=trace[cur];\n    }\n\n    path.emplace_back(cur);\n\
    \    cout<<dist[t]<<' '<<path.size()-1<<'\\n';\n    reverse(all(path));\n    for(int\
    \ i=1;i<path.size();i++){\n        cout<<path[i-1]<<' '<<path[i]<<'\\n';\n   \
    \ }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/graph/Shortest_Path.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/graph/Shortest_Path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp
- /verify/test/yosupo_judge/graph/Shortest_Path.test.cpp.html
title: test/yosupo_judge/graph/Shortest_Path.test.cpp
---
