---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6C38\u7D9Astack"
    links: []
  bundledCode: "#line 1 \"persistent/stack.hpp\"\n\nnamespace library {\n/// @brief\
    \ \u6C38\u7D9Astack \ntemplate<class T>\nclass persistent_stack {\n\tclass Node\
    \ {\n\tpublic:\n\t\tT val;\n\t\tNode* prev;\n\t};\n\n\n\tNode* head;\n\tint sz;\n\
    \n\tpersistent_stack(Node* head, int sz) :head(head), sz(sz) {}\npublic:\n\tpersistent_stack()\
    \ :head(nullptr) {}\n\n\n\tT top() const { assert(head); return head->val; }\n\
    \tpersistent_stack pop() const { assert(head); return persistent_stack(head->prev,\
    \ sz - 1); }\n\tpersistent_stack push(const T& v) const { return persistent_stack(new\
    \ Node{ v,head }, sz + 1); }\n\tint size()const { return sz; }\n    bool empty()\
    \ const { return (head == nullptr); }\n};\n};  // namespace library\n"
  code: "\nnamespace library {\n/// @brief \u6C38\u7D9Astack \ntemplate<class T>\n\
    class persistent_stack {\n\tclass Node {\n\tpublic:\n\t\tT val;\n\t\tNode* prev;\n\
    \t};\n\n\n\tNode* head;\n\tint sz;\n\n\tpersistent_stack(Node* head, int sz) :head(head),\
    \ sz(sz) {}\npublic:\n\tpersistent_stack() :head(nullptr) {}\n\n\n\tT top() const\
    \ { assert(head); return head->val; }\n\tpersistent_stack pop() const { assert(head);\
    \ return persistent_stack(head->prev, sz - 1); }\n\tpersistent_stack push(const\
    \ T& v) const { return persistent_stack(new Node{ v,head }, sz + 1); }\n\tint\
    \ size()const { return sz; }\n    bool empty() const { return (head == nullptr);\
    \ }\n};\n};  // namespace library"
  dependsOn: []
  isVerificationFile: false
  path: persistent/stack.hpp
  requiredBy: []
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: persistent/stack.hpp
layout: document
redirect_from:
- /library/persistent/stack.hpp
- /library/persistent/stack.hpp.html
title: "\u6C38\u7D9Astack"
---
