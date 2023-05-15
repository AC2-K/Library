---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: persistent stack
    links: []
  bundledCode: "#line 2 \"src/persistent/stack.hpp\"\n#include <cassert>\nnamespace\
    \ kyopro {\n\n/**\n * @brief persistent stack\n */\ntemplate <class T> class persistent_stack\
    \ {\n    class Node {\n    public:\n        T val;\n        Node* prev;\n    };\n\
    \n    Node* head;\n    int sz;\n\n    persistent_stack(Node* head, int sz) : head(head),\
    \ sz(sz) {}\n\npublic:\n    persistent_stack() : head(nullptr) {}\n\n    T top()\
    \ const {\n        assert(head);\n        return head->val;\n    }\n    persistent_stack\
    \ pop() const {\n        assert(head);\n        return persistent_stack(head->prev,\
    \ sz - 1);\n    }\n    persistent_stack push(const T& v) const {\n        return\
    \ persistent_stack(new Node{v, head}, sz + 1);\n    }\n    int size() const {\
    \ return sz; }\n    bool empty() const { return (head == nullptr); }\n};\n}; \
    \ // namespace kyopro\n"
  code: "#pragma once\n#include <cassert>\nnamespace kyopro {\n\n/**\n * @brief persistent\
    \ stack\n */\ntemplate <class T> class persistent_stack {\n    class Node {\n\
    \    public:\n        T val;\n        Node* prev;\n    };\n\n    Node* head;\n\
    \    int sz;\n\n    persistent_stack(Node* head, int sz) : head(head), sz(sz)\
    \ {}\n\npublic:\n    persistent_stack() : head(nullptr) {}\n\n    T top() const\
    \ {\n        assert(head);\n        return head->val;\n    }\n    persistent_stack\
    \ pop() const {\n        assert(head);\n        return persistent_stack(head->prev,\
    \ sz - 1);\n    }\n    persistent_stack push(const T& v) const {\n        return\
    \ persistent_stack(new Node{v, head}, sz + 1);\n    }\n    int size() const {\
    \ return sz; }\n    bool empty() const { return (head == nullptr); }\n};\n}; \
    \ // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/persistent/stack.hpp
  requiredBy: []
  timestamp: '2023-05-15 08:00:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/persistent/stack.hpp
layout: document
redirect_from:
- /library/src/persistent/stack.hpp
- /library/src/persistent/stack.hpp.html
title: persistent stack
---
