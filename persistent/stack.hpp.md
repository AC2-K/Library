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
  bundledCode: "#line 1 \"persistent/stack.hpp\"\ntemplate<class T>\nclass persistent_stack\
    \ {\n\tclass Node {\n\tpublic:\n\t\tT val;\n\t\tNode* prev;\n\t};\n\n\n\tNode*\
    \ head;\n\tint sz;\n\n\tpersistent_stack(Node* head, int sz) :head(head), sz(sz)\
    \ {}\npublic:\n\tpersistent_stack() :head(nullptr) {}\n\n\n\tT top() const { assert(sz);\
    \ return head->val; }\n\tpersistent_stack pop() const { assert(sz); return persistent_stack(head->prev,\
    \ sz - 1); }\n\tpersistent_stack push(const T& v) const { return persistent_stack(new\
    \ Node{ v,head }, sz + 1); }\n\tint size()const { return sz; }\n};\n"
  code: "template<class T>\nclass persistent_stack {\n\tclass Node {\n\tpublic:\n\t\
    \tT val;\n\t\tNode* prev;\n\t};\n\n\n\tNode* head;\n\tint sz;\n\n\tpersistent_stack(Node*\
    \ head, int sz) :head(head), sz(sz) {}\npublic:\n\tpersistent_stack() :head(nullptr)\
    \ {}\n\n\n\tT top() const { assert(sz); return head->val; }\n\tpersistent_stack\
    \ pop() const { assert(sz); return persistent_stack(head->prev, sz - 1); }\n\t\
    persistent_stack push(const T& v) const { return persistent_stack(new Node{ v,head\
    \ }, sz + 1); }\n\tint size()const { return sz; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: persistent/stack.hpp
  requiredBy: []
  timestamp: '2023-03-29 11:45:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: persistent/stack.hpp
layout: document
redirect_from:
- /library/persistent/stack.hpp
- /library/persistent/stack.hpp.html
title: persistent/stack.hpp
---
