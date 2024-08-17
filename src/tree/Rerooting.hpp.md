---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: internal/CSR.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"internal/CSR.hpp\"\n\nnamespace kyopro {\ntemplate\
    \ <typename V, typename OP, typename PUT_EV, typename LEAF>\nclass Rerooting {\n\
    \    const V identity;\n    const OP op;\n    const PUT_EV put_edge_vertex;\n\
    \    const LEAF leaf;\n\n    const int n;\n\n    std::vector<std::pair<int, std::pair<int,\
    \ int>>> es;\n\npublic:\n    Rerooting(int n,\n              const V& identity,\n\
    \              const OP& op,\n              const PUT_EV& put_edge_vertex,\n \
    \             const LEAF& leaf)\n        : n(n),\n          identity(identity),\n\
    \          op(op),\n          put_edge_vertex(put_edge_vertex),\n          leaf(leaf)\
    \ {\n        es.reserve(2 * n - 2);\n    }\n    void add_edge(int u, int v, int\
    \ i) {\n        es.emplace_back(u, std::pair(v, i));\n        es.emplace_back(v,\
    \ std::pair(u, i));\n    }\n\n    std::vector<V> run() {\n        assert(es.size()\
    \ == 2 * n - 2);\n\n        internal::csr g(n, es);\n\n        std::vector<V>\
    \ dp1(n);\n        {\n            auto push_up = [&](const auto& push_up, int\
    \ v, int p = -1) -> V {\n                dp1[v] = leaf(v);\n                for\
    \ (auto [nv, e_idx] : g[v]) {\n                    if (nv == p) continue;\n  \
    \                  dp1[v] = op(dp1[v], put_edge_vertex(push_up(push_up, nv, v),\n\
    \                                                        e_idx, v));\n       \
    \             // \u9802\u70B9, \u8FBA\u306E\u60C5\u5831\u3092\u6DFB\u52A0\n  \
    \              }\n                return dp1[v];\n            };\n           \
    \ push_up(push_up, 0, -1);\n        }\n\n        std::vector<V> dp(n);\n\n   \
    \     {\n            // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\u3057\u3066\
    \u3044\u304F\n            auto push_down = [&](const auto& push_down, int v, int\
    \ p = -1,\n                                 V agg) -> void {\n               \
    \ dp[v] = agg;\n                std::vector<std::pair<int, int>> children;\n \
    \               std::vector<V> pref, suff;\n                for (auto [nv, e_idx]\
    \ : g[v]) {\n                    if (nv == p) continue;\n                    children.emplace_back(nv,\
    \ e_idx);\n                    pref.emplace_back(put_edge_vertex(dp1[nv], e_idx,\
    \ v));\n                    suff.emplace_back(put_edge_vertex(dp1[nv], e_idx,\
    \ v));\n                }\n\n                if (children.empty()) return;\n \
    \               for (int i = 0; i < (int)pref.size() - 1; ++i) {\n           \
    \         pref[i + 1] = op(pref[i + 1], pref[i]);\n                }\n       \
    \         for (int i = (int)suff.size() - 1; i > 0; --i) {\n                 \
    \   suff[i - 1] = op(suff[i - 1], suff[i]);\n                }\n             \
    \   dp[v] = op(dp[v], pref.back());\n\n                for (int i = 0; i < (int)children.size();\
    \ ++i) {\n                    V next_agg = op(leaf(v), agg);\n               \
    \     if (i > 0) {\n                        next_agg = op(next_agg, pref[i - 1]);\n\
    \                    }\n                    if (i < (int)suff.size() - 1) {\n\
    \                        next_agg = op(next_agg, suff[i + 1]);\n             \
    \       }\n\n                    next_agg = put_edge_vertex(next_agg, children[i].second,\n\
    \                                               children[i].first);\n\n      \
    \              push_down(push_down, children[i].first, v, next_agg);\n       \
    \         }\n                return;\n            };\n            push_down(push_down,\
    \ 0, -1, identity);\n        }\n\n        return dp;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * Rerooting(\u5168\u65B9\u4F4D\u6728DP)\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/Rerooting.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/tree/Rerooting.hpp
layout: document
redirect_from:
- /library/src/tree/Rerooting.hpp
- /library/src/tree/Rerooting.hpp.html
title: src/tree/Rerooting.hpp
---
