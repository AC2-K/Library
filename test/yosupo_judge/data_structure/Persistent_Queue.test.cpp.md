---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: persistent/queue.hpp
    title: persistent/queue.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
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
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N) for (int i =\
    \ 0; i < (N); i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 3 \"persistent/queue.hpp\"\ntemplate <typename T, int lg = 20> class persistent_queue\
    \ {\n    struct Node {\n        Node() = default;\n        uint32_t index;\n \
    \       T val;\n        Node* prev[20];\n    };\n\n    Node *front_ptr = nullptr,\
    \ *back_ptr = nullptr;\n    int siz;\n\n  public:\n    persistent_queue(Node*\
    \ front_ptr = nullptr,\n                     Node* back_ptr = nullptr,\n     \
    \                int siz = 0)\n        : front_ptr(front_ptr), back_ptr(back_ptr),\
    \ siz(siz) {}\n    bool empty() { return siz; }\n    persistent_queue push(const\
    \ T& x) {\n        Node* ptr = new Node();\n        ptr->val = x;\n        ptr->prev[0]\
    \ = back_ptr;\n        for (int i = 1; i < lg; i++) {\n            Node* c = ptr->prev[i\
    \ - 1];\n            if (c)\n                ptr->prev[i] = c->prev[i - 1];\n\
    \            else\n                break;\n        }\n\n        // \u7A7A\u3060\
    \u3063\u305F\u6642\u306B\u6CE8\u610F\u3059\u308B\n        if (siz) {\n       \
    \     return persistent_queue(front_ptr, ptr, siz + 1);\n        } else {\n  \
    \          return persistent_queue(ptr, ptr, siz + 1);\n        }\n    }\n   \
    \ persistent_queue pop() {\n        if (!front_ptr || !back_ptr || siz == 1) {\n\
    \            return persistent_queue();\n        }\n        int d = siz - 2;\n\
    \        Node* cur = back_ptr;\n        while (d) {\n            int jump = 31\
    \ - __builtin_clz(d);\n            d -= (1 << jump);\n            cur = cur->prev[jump];\n\
    \        }\n\n        return persistent_queue(cur, back_ptr, siz - 1);\n    }\n\
    \n    T front() {\n        assert(siz);\n        return front_ptr->val;\n    }\n\
    \    T back() {\n        assert(siz);\n        return back_ptr->val;\n    }\n\
    };\n#line 5 \"test/yosupo_judge/data_structure/Persistent_Queue.test.cpp\"\n\n\
    int main() {\n\tint q;\n\tscanf(\"%d\", &q);\n\tstd::vector<persistent_queue<int>>\
    \ v(q + 1);\n\tfor (int i = 1; i <= q; i++) {\n\t\tint t, idx;\n\t\tscanf(\"%d%d\"\
    , &t, &idx);\n\t\tidx++;\n\n\t\tif (t == 0) {\n\t\t\tint s;\n\t\t\tscanf(\"%d\"\
    , &s);\n\t\t\tv[i] = v[idx].push(s);\n\t\t}\n\t\telse {\n\t\t\tprintf(\"%d\\n\"\
    , v[idx].front());\n\t\t\tv[i] = v[idx].pop();\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n\
    #include\"template.hpp\"\n#include\"persistent/queue.hpp\"\n\nint main() {\n\t\
    int q;\n\tscanf(\"%d\", &q);\n\tstd::vector<persistent_queue<int>> v(q + 1);\n\
    \tfor (int i = 1; i <= q; i++) {\n\t\tint t, idx;\n\t\tscanf(\"%d%d\", &t, &idx);\n\
    \t\tidx++;\n\n\t\tif (t == 0) {\n\t\t\tint s;\n\t\t\tscanf(\"%d\", &s);\n\t\t\t\
    v[i] = v[idx].push(s);\n\t\t}\n\t\telse {\n\t\t\tprintf(\"%d\\n\", v[idx].front());\n\
    \t\t\tv[i] = v[idx].pop();\n\t\t}\n\t}\n}"
  dependsOn:
  - template.hpp
  - persistent/queue.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 14:59:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
- /verify/test/yosupo_judge/data_structure/Persistent_Queue.test.cpp.html
title: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
---
