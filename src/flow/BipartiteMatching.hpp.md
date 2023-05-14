---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0"
    links:
    - https://nyaannyaan.github.io/library/flow/flow-on-bipartite-graph.hpp
    - https://qiita.com/drken/items/e805e3f514acceb87602
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../ac-library/atcoder/maxflow.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../../../ac-library//atcoder/maxflow.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace kyopro {\n\n/**\n * @brief \u4E8C\u90E8\u30DE\u30C3\
    \u30C1\u30F3\u30B0\n */\ntemplate <typename Cap>\nclass BipartiteGraph {\n   \
    \ const int L, R;\n    const int s, t;  // \u8D85\u9802\u70B9\u3092\u4F5C\u308B\
    \n\n    atcoder::mf_graph<Cap> g;\n\n    // \u3059\u3067\u306B\u6D41\u3057\u305F\
    \u304B?\n    bool flowed_flag;\n\npublic:\n    explicit BipartiteGraph(int LV,\
    \ int RV)\n        : g(LV + RV + 2),\n          L(LV),\n          R(RV),\n   \
    \       s(LV + RV + 1),\n          t(LV + RV),\n          flowed_flag(false) {\n\
    \        for (int i = 0; i < LV; ++i) g.add_edge(s, i, 1);\n        for (int i\
    \ = LV; i < LV + RV; ++i) g.add_edge(i, t, 1);\n    }\n    int add_edge(int from,\
    \ int to, Cap cap = 1) {\n        assert(0 <= from && from < L);\n        assert(0\
    \ <= to && to < R);\n        return g.add_edge(from, to + L, cap);\n    }\n\n\
    public:\n    // \u6D41\u91CF\n    Cap flow() {\n        flowed_flag = true;\n\
    \        return g.flow(s, t);\n    }\n\n    // \u5FA9\u5143\n    std::vector<std::pair<int,\
    \ int>> Matching() {\n        if (!flowed_flag) flow();\n\n        auto E = g.edges();\n\
    \n        std::vector<std::pair<int, int>> res;\n        for (const auto& e :\
    \ E) {\n            if (e.flow > 0 && e.from != s && e.to != t) {\n          \
    \      res.emplace_back(e.from, e.to - L);\n            }\n        }\n       \
    \ return res;\n    }\n};\n};  // namespace kyopro\n\n/**\n * @ref\n * https://qiita.com/drken/items/e805e3f514acceb87602\n\
    \ * https://nyaannyaan.github.io/library/flow/flow-on-bipartite-graph.hpp\n *\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/BipartiteMatching.hpp
layout: document
redirect_from:
- /library/src/flow/BipartiteMatching.hpp
- /library/src/flow/BipartiteMatching.hpp.html
title: "\u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0"
---
