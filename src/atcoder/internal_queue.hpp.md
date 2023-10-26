---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/atcoder/maxflow.hpp
    title: src/atcoder/maxflow.hpp
  - icon: ':warning:'
    path: src/atcoder/mincostflow.hpp
    title: src/atcoder/mincostflow.hpp
  - icon: ':warning:'
    path: src/graph/flow/BipartiteMatching.hpp
    title: "\u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/atcoder/internal_queue.hpp\"\n\n\n\n#include <vector>\n\
    \nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class T> struct simple_queue\
    \ {\n    std::vector<T> payload;\n    int pos = 0;\n    void reserve(int n) {\
    \ payload.reserve(n); }\n    int size() const { return int(payload.size()) - pos;\
    \ }\n    bool empty() const { return pos == int(payload.size()); }\n    void push(const\
    \ T& t) { payload.push_back(t); }\n    T& front() { return payload[pos]; }\n \
    \   void clear() {\n        payload.clear();\n        pos = 0;\n    }\n    void\
    \ pop() { pos++; }\n};\n\n}  // namespace internal\n\n}  // namespace atcoder\n\
    \n\n"
  code: "#ifndef ATCODER_INTERNAL_QUEUE_HPP\n#define ATCODER_INTERNAL_QUEUE_HPP 1\n\
    \n#include <vector>\n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate\
    \ <class T> struct simple_queue {\n    std::vector<T> payload;\n    int pos =\
    \ 0;\n    void reserve(int n) { payload.reserve(n); }\n    int size() const {\
    \ return int(payload.size()) - pos; }\n    bool empty() const { return pos ==\
    \ int(payload.size()); }\n    void push(const T& t) { payload.push_back(t); }\n\
    \    T& front() { return payload[pos]; }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\n}  // namespace internal\n\
    \n}  // namespace atcoder\n\n#endif  // ATCODER_INTERNAL_QUEUE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/atcoder/internal_queue.hpp
  requiredBy:
  - src/graph/flow/BipartiteMatching.hpp
  - src/atcoder/mincostflow.hpp
  - src/atcoder/maxflow.hpp
  timestamp: '2023-08-02 13:39:21+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/atcoder/internal_queue.hpp
layout: document
redirect_from:
- /library/src/atcoder/internal_queue.hpp
- /library/src/atcoder/internal_queue.hpp.html
title: src/atcoder/internal_queue.hpp
---
