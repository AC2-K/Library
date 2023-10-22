---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6C38\u7D9AStack"
    links: []
  bundledCode: "#line 2 \"src/data-structure/persistent/stack.hpp\"\n#include <cassert>\n\
    namespace kyopro {\ntemplate <class T> class persistent_stack {\n    class Node\
    \ {\n    public:\n        T val;\n        Node* prev;\n    };\n\n    Node* head;\n\
    \    int sz;\n\n    persistent_stack(Node* head, int sz) : head(head), sz(sz)\
    \ {}\n\npublic:\n    persistent_stack() : head(nullptr) {}\n\n    T top() const\
    \ {\n        assert(head);\n        return head->val;\n    }\n    persistent_stack\
    \ pop() const {\n        assert(head);\n        return persistent_stack(head->prev,\
    \ sz - 1);\n    }\n    persistent_stack push(const T& v) const {\n        return\
    \ persistent_stack(new Node{v, head}, sz + 1);\n    }\n    int size() const {\
    \ return sz; }\n    bool empty() const { return (head == nullptr); }\n};\n}; \
    \ // namespace kyopro\n\n/**\n * @brief \u6C38\u7D9AStack\n */\n"
  code: "#pragma once\n#include <cassert>\nnamespace kyopro {\ntemplate <class T>\
    \ class persistent_stack {\n    class Node {\n    public:\n        T val;\n  \
    \      Node* prev;\n    };\n\n    Node* head;\n    int sz;\n\n    persistent_stack(Node*\
    \ head, int sz) : head(head), sz(sz) {}\n\npublic:\n    persistent_stack() : head(nullptr)\
    \ {}\n\n    T top() const {\n        assert(head);\n        return head->val;\n\
    \    }\n    persistent_stack pop() const {\n        assert(head);\n        return\
    \ persistent_stack(head->prev, sz - 1);\n    }\n    persistent_stack push(const\
    \ T& v) const {\n        return persistent_stack(new Node{v, head}, sz + 1);\n\
    \    }\n    int size() const { return sz; }\n    bool empty() const { return (head\
    \ == nullptr); }\n};\n};  // namespace kyopro\n\n/**\n * @brief \u6C38\u7D9AStack\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/persistent/stack.hpp
  requiredBy: []
  timestamp: '2023-10-22 17:06:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/persistent/stack.hpp
layout: document
redirect_from:
- /library/src/data-structure/persistent/stack.hpp
- /library/src/data-structure/persistent/stack.hpp.html
title: "\u6C38\u7D9AStack"
---
