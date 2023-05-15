---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/persistent/queue.hpp
    title: persistent queue
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Persistent_Queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"src/persistent/queue.hpp\"\n#include\
    \ <cassert>\nnamespace kyopro {\n/**\n * @brief persistent queue\n */\ntemplate\
    \ <typename T, int lg = 20> class persistent_queue {\n    struct Node {\n    \
    \    Node() = default;\n        uint32_t index;\n        T val;\n        Node*\
    \ prev[20];\n    };\n\n    Node *front_ptr = nullptr, *back_ptr = nullptr;\n \
    \   int siz;\n\npublic:\n    persistent_queue(Node* front_ptr = nullptr,\n   \
    \                  Node* back_ptr = nullptr,\n                     int siz = 0)\n\
    \        : front_ptr(front_ptr), back_ptr(back_ptr), siz(siz) {}\n    bool empty()\
    \ { return siz; }\n    persistent_queue push(const T& x) {\n        Node* ptr\
    \ = new Node();\n        ptr->val = x;\n        ptr->prev[0] = back_ptr;\n   \
    \     for (int i = 1; i < lg; i++) {\n            Node* c = ptr->prev[i - 1];\n\
    \            if (c)\n                ptr->prev[i] = c->prev[i - 1];\n        \
    \    else\n                break;\n        }\n\n        if (siz) {\n         \
    \   return persistent_queue(front_ptr, ptr, siz + 1);\n        } else {\n    \
    \        return persistent_queue(ptr, ptr, siz + 1);\n        }\n    }\n    persistent_queue\
    \ pop() {\n        if (!front_ptr || !back_ptr || siz == 1) {\n            return\
    \ persistent_queue();\n        }\n        int d = siz - 2;\n        Node* cur\
    \ = back_ptr;\n        while (d) {\n            int jump = 31 - __builtin_clz(d);\n\
    \            d -= (1 << jump);\n            cur = cur->prev[jump];\n        }\n\
    \n        return persistent_queue(cur, back_ptr, siz - 1);\n    }\n\n    T front()\
    \ {\n        assert(siz);\n        return front_ptr->val;\n    }\n    T back()\
    \ {\n        assert(siz);\n        return back_ptr->val;\n    }\n};\n};  // namespace\
    \ kyopro\n#line 5 \"test/yosupo_judge/data_structure/Persistent_Queue.test.cpp\"\
    \n\nint main() {\n    int q;\n    scanf(\"%d\", &q);\n    std::vector<kyopro::persistent_queue<int>>\
    \ v(q + 1);\n    for (int i = 1; i <= q; i++) {\n        int t, idx;\n       \
    \ scanf(\"%d%d\", &t, &idx);\n        idx++;\n\n        if (!t) {\n          \
    \  int s;\n            scanf(\"%d\", &s);\n            v[i] = v[idx].push(s);\n\
    \        } else {\n            printf(\"%d\\n\", v[idx].front());\n          \
    \  v[i] = v[idx].pop();\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"../../../src/persistent/queue.hpp\"\
    \n\nint main() {\n    int q;\n    scanf(\"%d\", &q);\n    std::vector<kyopro::persistent_queue<int>>\
    \ v(q + 1);\n    for (int i = 1; i <= q; i++) {\n        int t, idx;\n       \
    \ scanf(\"%d%d\", &t, &idx);\n        idx++;\n\n        if (!t) {\n          \
    \  int s;\n            scanf(\"%d\", &s);\n            v[i] = v[idx].push(s);\n\
    \        } else {\n            printf(\"%d\\n\", v[idx].front());\n          \
    \  v[i] = v[idx].pop();\n        }\n    }\n}"
  dependsOn:
  - src/persistent/queue.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 08:00:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
- /verify/test/yosupo_judge/data_structure/Persistent_Queue.test.cpp.html
title: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
---
