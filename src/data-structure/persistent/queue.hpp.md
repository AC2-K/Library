---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
    title: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: persistent queue
    links: []
  bundledCode: "#line 2 \"src/data-structure/persistent/queue.hpp\"\n#include <cassert>\n\
    namespace kyopro {\n/**\n * @brief persistent queue\n */\ntemplate <typename T,\
    \ int lg = 20> class persistent_queue {\n    struct Node {\n        Node() = default;\n\
    \        uint32_t index;\n        T val;\n        Node* prev[20];\n    };\n\n\
    \    Node *front_ptr = nullptr, *back_ptr = nullptr;\n    int siz;\n\npublic:\n\
    \    persistent_queue(Node* front_ptr = nullptr,\n                     Node* back_ptr\
    \ = nullptr,\n                     int siz = 0)\n        : front_ptr(front_ptr),\
    \ back_ptr(back_ptr), siz(siz) {}\n    bool empty() { return siz; }\n    persistent_queue\
    \ push(const T& x) {\n        Node* ptr = new Node();\n        ptr->val = x;\n\
    \        ptr->prev[0] = back_ptr;\n        for (int i = 1; i < lg; i++) {\n  \
    \          Node* c = ptr->prev[i - 1];\n            if (c)\n                ptr->prev[i]\
    \ = c->prev[i - 1];\n            else\n                break;\n        }\n\n \
    \       if (siz) {\n            return persistent_queue(front_ptr, ptr, siz +\
    \ 1);\n        } else {\n            return persistent_queue(ptr, ptr, siz + 1);\n\
    \        }\n    }\n    persistent_queue pop() {\n        if (!front_ptr || !back_ptr\
    \ || siz == 1) {\n            return persistent_queue();\n        }\n        int\
    \ d = siz - 2;\n        Node* cur = back_ptr;\n        while (d) {\n         \
    \   int jump = 31 - __builtin_clz(d);\n            d -= (1 << jump);\n       \
    \     cur = cur->prev[jump];\n        }\n\n        return persistent_queue(cur,\
    \ back_ptr, siz - 1);\n    }\n\n    T front() {\n        assert(siz);\n      \
    \  return front_ptr->val;\n    }\n    T back() {\n        assert(siz);\n     \
    \   return back_ptr->val;\n    }\n};\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <cassert>\nnamespace kyopro {\n/**\n * @brief persistent\
    \ queue\n */\ntemplate <typename T, int lg = 20> class persistent_queue {\n  \
    \  struct Node {\n        Node() = default;\n        uint32_t index;\n       \
    \ T val;\n        Node* prev[20];\n    };\n\n    Node *front_ptr = nullptr, *back_ptr\
    \ = nullptr;\n    int siz;\n\npublic:\n    persistent_queue(Node* front_ptr =\
    \ nullptr,\n                     Node* back_ptr = nullptr,\n                 \
    \    int siz = 0)\n        : front_ptr(front_ptr), back_ptr(back_ptr), siz(siz)\
    \ {}\n    bool empty() { return siz; }\n    persistent_queue push(const T& x)\
    \ {\n        Node* ptr = new Node();\n        ptr->val = x;\n        ptr->prev[0]\
    \ = back_ptr;\n        for (int i = 1; i < lg; i++) {\n            Node* c = ptr->prev[i\
    \ - 1];\n            if (c)\n                ptr->prev[i] = c->prev[i - 1];\n\
    \            else\n                break;\n        }\n\n        if (siz) {\n \
    \           return persistent_queue(front_ptr, ptr, siz + 1);\n        } else\
    \ {\n            return persistent_queue(ptr, ptr, siz + 1);\n        }\n    }\n\
    \    persistent_queue pop() {\n        if (!front_ptr || !back_ptr || siz == 1)\
    \ {\n            return persistent_queue();\n        }\n        int d = siz -\
    \ 2;\n        Node* cur = back_ptr;\n        while (d) {\n            int jump\
    \ = 31 - __builtin_clz(d);\n            d -= (1 << jump);\n            cur = cur->prev[jump];\n\
    \        }\n\n        return persistent_queue(cur, back_ptr, siz - 1);\n    }\n\
    \n    T front() {\n        assert(siz);\n        return front_ptr->val;\n    }\n\
    \    T back() {\n        assert(siz);\n        return back_ptr->val;\n    }\n\
    };\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/persistent/queue.hpp
  requiredBy: []
  timestamp: '2023-06-25 06:07:51+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
documentation_of: src/data-structure/persistent/queue.hpp
layout: document
redirect_from:
- /library/src/data-structure/persistent/queue.hpp
- /library/src/data-structure/persistent/queue.hpp.html
title: persistent queue
---
