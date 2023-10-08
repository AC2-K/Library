---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u9759\u7684\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: internal/CSR.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"internal/CSR.hpp\"\n\nnamespace kyopro {\n/**\n\
    \ * @brief \u9759\u7684\u30B0\u30E9\u30D5\n */\ntemplate <bool is_directed> class\
    \ UnweightedStaticGraph {\n    internal::CSR<int> g;\n\npublic:\n    UnweightedStaticGraph(std::size_t\
    \ n) : g(n) {}\n    void add_edge(int a, int b) {\n        assert(0 <= a && a\
    \ < g.n);\n        assert(0 <= b && b < g.n);\n\n        g.add(a, b);\n      \
    \  if constexpr (!is_directed) g.add(b, a);\n    }\n    void build() { g.build();\
    \ }\n    const internal::CSR<int>::range operator[](std::size_t i) const {\n \
    \       return g[i];\n    }\n};\ntemplate <typename weight, bool is_directed>\
    \ class WeightedStaticGraph {\n    internal::CSR<std::pair<int, weight>> g;\n\n\
    public:\n    WeightedStaticGraph(std::size_t n) : g(n){}\n    void add_edge(int\
    \ a, int b, weight w) {\n        assert(0 <= a && a < g.n);\n        assert(0\
    \ <= a && a < g.n);\n\n        g.add(a, std::pair<int, weight>(b, w));\n     \
    \   if constexpr (!is_directed) g.add(a, std::pair<int, weight>(b, w));\n    }\n\
    \    void build() { g.build(); }\n    const internal::CSR<std::pair<int, weight>>::range\
    \ operator[](\n        std::size_t i) const {\n        return g[i];\n    }\n};\n\
    \n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/StaticGraph.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/StaticGraph.hpp
layout: document
redirect_from:
- /library/src/graph/StaticGraph.hpp
- /library/src/graph/StaticGraph.hpp.html
title: "\u9759\u7684\u30B0\u30E9\u30D5"
---
