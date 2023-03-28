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
  bundledCode: "#line 1 \"persistent/queue.hpp\"\ntemplate<typename T, int lg = 20>\n\
    class persistent_queue {\n\tstruct Node {\n\t\tNode() = default;\n\t\tuint32_t\
    \ index;\n\t\tT val;\n\t\tNode* prev[20];\n\t};\n\n\tNode* front_ptr = nullptr,\
    \ * back_ptr = nullptr;\n\tint siz;\n\npublic:\n\tpersistent_queue(Node* front_ptr\
    \ = nullptr, Node* back_ptr = nullptr, int siz = 0) :front_ptr(front_ptr), back_ptr(back_ptr),\
    \ siz(siz) {}\n\tbool empty() { return siz; }\n\tpersistent_queue push(const T&\
    \ x) {\n\t\tNode* ptr = new Node();\n\t\tptr->val = x;\n\t\tptr->prev[0] = back_ptr;\n\
    \t\tfor (int i = 1; i < lg; i++) {\n\t\t\tNode* c = ptr->prev[i - 1];\n\t\t\t\
    if (c)ptr->prev[i] = c->prev[i-1];\n\t\t\telse break;\n\t\t}\n\n\t\t//\u7A7A\u3060\
    \u3063\u305F\u6642\u306B\u6CE8\u610F\u3059\u308B\n\t\tif (siz) {\n\t\t\treturn\
    \ persistent_queue(front_ptr, ptr, siz + 1);\n\t\t}\n\t\telse {\n\t\t\treturn\
    \ persistent_queue(ptr, ptr, siz + 1);\n\t\t}\n\t}\n\tpersistent_queue pop() {\n\
    \t\tif (!front_ptr || !back_ptr || siz == 1) {\n\t\t\treturn persistent_queue();\n\
    \t\t}\n\t\tint d = siz - 2;\n\t\tNode* cur = back_ptr;\n\t\twhile (d) {\n\t\t\t\
    int jump = 31 - __builtin_clz(d);\n\t\t\td -= (1 << jump);\n\t\t\tcur = cur->prev[jump];\n\
    \t\t}\n\n\t\treturn persistent_queue(cur, back_ptr, siz - 1);\n\t}\n\n\tT front()\
    \ { assert(siz); return front_ptr->val; }\n\tT back() { assert(siz); return back_ptr->val;\
    \ }\n};\n"
  code: "template<typename T, int lg = 20>\nclass persistent_queue {\n\tstruct Node\
    \ {\n\t\tNode() = default;\n\t\tuint32_t index;\n\t\tT val;\n\t\tNode* prev[20];\n\
    \t};\n\n\tNode* front_ptr = nullptr, * back_ptr = nullptr;\n\tint siz;\n\npublic:\n\
    \tpersistent_queue(Node* front_ptr = nullptr, Node* back_ptr = nullptr, int siz\
    \ = 0) :front_ptr(front_ptr), back_ptr(back_ptr), siz(siz) {}\n\tbool empty()\
    \ { return siz; }\n\tpersistent_queue push(const T& x) {\n\t\tNode* ptr = new\
    \ Node();\n\t\tptr->val = x;\n\t\tptr->prev[0] = back_ptr;\n\t\tfor (int i = 1;\
    \ i < lg; i++) {\n\t\t\tNode* c = ptr->prev[i - 1];\n\t\t\tif (c)ptr->prev[i]\
    \ = c->prev[i-1];\n\t\t\telse break;\n\t\t}\n\n\t\t//\u7A7A\u3060\u3063\u305F\u6642\
    \u306B\u6CE8\u610F\u3059\u308B\n\t\tif (siz) {\n\t\t\treturn persistent_queue(front_ptr,\
    \ ptr, siz + 1);\n\t\t}\n\t\telse {\n\t\t\treturn persistent_queue(ptr, ptr, siz\
    \ + 1);\n\t\t}\n\t}\n\tpersistent_queue pop() {\n\t\tif (!front_ptr || !back_ptr\
    \ || siz == 1) {\n\t\t\treturn persistent_queue();\n\t\t}\n\t\tint d = siz - 2;\n\
    \t\tNode* cur = back_ptr;\n\t\twhile (d) {\n\t\t\tint jump = 31 - __builtin_clz(d);\n\
    \t\t\td -= (1 << jump);\n\t\t\tcur = cur->prev[jump];\n\t\t}\n\n\t\treturn persistent_queue(cur,\
    \ back_ptr, siz - 1);\n\t}\n\n\tT front() { assert(siz); return front_ptr->val;\
    \ }\n\tT back() { assert(siz); return back_ptr->val; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: persistent/queue.hpp
  requiredBy: []
  timestamp: '2023-03-29 01:52:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: persistent/queue.hpp
layout: document
redirect_from:
- /library/persistent/queue.hpp
- /library/persistent/queue.hpp.html
title: persistent/queue.hpp
---
