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
  bundledCode: "#line 2 \"persistent/stack.hpp\"\n#include <cassert>\ntemplate <class\
    \ T> class persistent_stack {\n    class Node {\n      public:\n        T val;\n\
    \        Node* prev;\n    };\n\n    Node* head;\n    int sz;\n\n    persistent_stack(Node*\
    \ head, int sz) : head(head), sz(sz) {}\n\n  public:\n    persistent_stack() :\
    \ head(nullptr) {}\n\n    T top() const {\n        assert(head);\n        return\
    \ head->val;\n    }\n    persistent_stack pop() const {\n        assert(head);\n\
    \        return persistent_stack(head->prev, sz - 1);\n    }\n    persistent_stack\
    \ push(const T& v) const {\n        return persistent_stack(new Node{v, head},\
    \ sz + 1);\n    }\n    int size() const { return sz; }\n    bool empty() const\
    \ { return (head == nullptr); }\n};\n"
  code: "#pragma once\n#include <cassert>\ntemplate <class T> class persistent_stack\
    \ {\n    class Node {\n      public:\n        T val;\n        Node* prev;\n  \
    \  };\n\n    Node* head;\n    int sz;\n\n    persistent_stack(Node* head, int\
    \ sz) : head(head), sz(sz) {}\n\n  public:\n    persistent_stack() : head(nullptr)\
    \ {}\n\n    T top() const {\n        assert(head);\n        return head->val;\n\
    \    }\n    persistent_stack pop() const {\n        assert(head);\n        return\
    \ persistent_stack(head->prev, sz - 1);\n    }\n    persistent_stack push(const\
    \ T& v) const {\n        return persistent_stack(new Node{v, head}, sz + 1);\n\
    \    }\n    int size() const { return sz; }\n    bool empty() const { return (head\
    \ == nullptr); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: persistent/stack.hpp
  requiredBy: []
  timestamp: '2023-04-07 18:51:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: persistent/stack.hpp
layout: document
redirect_from:
- /library/persistent/stack.hpp
- /library/persistent/stack.hpp.html
title: persistent/stack.hpp
---
