---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/atcoder/internal_scc.hpp
    title: src/atcoder/internal_scc.hpp
  - icon: ':warning:'
    path: src/atcoder/mincostflow.hpp
    title: src/atcoder/mincostflow.hpp
  - icon: ':warning:'
    path: src/atcoder/scc.hpp
    title: src/atcoder/scc.hpp
  - icon: ':warning:'
    path: src/atcoder/twosat.hpp
    title: src/atcoder/twosat.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/atcoder/internal_csr.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n\nnamespace atcoder {\nnamespace internal\
    \ {\n\ntemplate <class E> struct csr {\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)\n\
    \        : start(n + 1), elist(edges.size()) {\n        for (auto e : edges) {\n\
    \            start[e.first + 1]++;\n        }\n        for (int i = 1; i <= n;\
    \ i++) {\n            start[i] += start[i - 1];\n        }\n        auto counter\
    \ = start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_CSR_HPP\n#define ATCODER_INTERNAL_CSR_HPP 1\n\n\
    #include <algorithm>\n#include <utility>\n#include <vector>\n\nnamespace atcoder\
    \ {\nnamespace internal {\n\ntemplate <class E> struct csr {\n    std::vector<int>\
    \ start;\n    std::vector<E> elist;\n    explicit csr(int n, const std::vector<std::pair<int,\
    \ E>>& edges)\n        : start(n + 1), elist(edges.size()) {\n        for (auto\
    \ e : edges) {\n            start[e.first + 1]++;\n        }\n        for (int\
    \ i = 1; i <= n; i++) {\n            start[i] += start[i - 1];\n        }\n  \
    \      auto counter = start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_INTERNAL_CSR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/atcoder/internal_csr.hpp
  requiredBy:
  - src/atcoder/mincostflow.hpp
  - src/atcoder/scc.hpp
  - src/atcoder/twosat.hpp
  - src/atcoder/internal_scc.hpp
  timestamp: '2023-08-02 13:39:21+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/atcoder/internal_csr.hpp
layout: document
redirect_from:
- /library/src/atcoder/internal_csr.hpp
- /library/src/atcoder/internal_csr.hpp.html
title: src/atcoder/internal_csr.hpp
---
