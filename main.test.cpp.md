---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: persistent/queue.hpp
    title: persistent/queue.hpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"main.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline\
    \ void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void\
    \ chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"persistent/queue.hpp\"\ntemplate<typename\
    \ T, int lg = 20>\nclass persistent_queue {\n\tstruct Node {\n\t\tNode() = default;\n\
    \t\tuint32_t index;\n\t\tT val;\n\t\tNode* prev[20];\n\t};\n\n\tNode* front_ptr\
    \ = nullptr, * back_ptr = nullptr;\n\tint siz;\n\npublic:\n\tpersistent_queue(Node*\
    \ front_ptr = nullptr, Node* back_ptr = nullptr, int siz = 0) :front_ptr(front_ptr),\
    \ back_ptr(back_ptr), siz(siz) {}\n\tbool empty() { return siz; }\n\tpersistent_queue\
    \ push(const T& x) {\n\t\tNode* ptr = new Node();\n\t\tptr->val = x;\n\t\tptr->prev[0]\
    \ = back_ptr;\n\t\tfor (int i = 1; i < lg; i++) {\n\t\t\tNode* c = ptr->prev[i\
    \ - 1];\n\t\t\tif (c)ptr->prev[i] = c->prev[i-1];\n\t\t\telse break;\n\t\t}\n\n\
    \t\t//\u7A7A\u3060\u3063\u305F\u6642\u306B\u6CE8\u610F\u3059\u308B\n\t\tif (siz)\
    \ {\n\t\t\treturn persistent_queue(front_ptr, ptr, siz + 1);\n\t\t}\n\t\telse\
    \ {\n\t\t\treturn persistent_queue(ptr, ptr, siz + 1);\n\t\t}\n\t}\n\tpersistent_queue\
    \ pop() {\n\t\tif (!front_ptr || !back_ptr || siz == 1) {\n\t\t\treturn persistent_queue();\n\
    \t\t}\n\t\tint d = siz - 2;\n\t\tNode* cur = back_ptr;\n\t\twhile (d) {\n\t\t\t\
    int jump = 31 - __builtin_clz(d);\n\t\t\td -= (1 << jump);\n\t\t\tcur = cur->prev[jump];\n\
    \t\t}\n\n\t\treturn persistent_queue(cur, back_ptr, siz - 1);\n\t}\n\n\tT front()\
    \ { assert(siz); return front_ptr->val; }\n\tT back() { assert(siz); return back_ptr->val;\
    \ }\n};\n#line 5 \"main.test.cpp\"\n\nint main() {\n\tint q;\n\tcin >> q;\n\t\
    vector<persistent_queue<int>> v(q + 1);\n\tfor (int i = 1; i <= q; i++) {\n\t\t\
    int t, idx;\n\t\tscanf(\"%d%d\", &t, &idx);\n\t\tidx++;\n\n\t\tif (t == 0) {\n\
    \t\t\tint s;\n\t\t\tscanf(\"%d\", &s);\n\t\t\tv[i] = v[idx].push(s);\n\t\t}\n\t\
    \telse {\n\t\t\tprintf(\"%d\\n\", v[idx].front());\n\t\t\tv[i] = v[idx].pop();\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n\
    #include\"template.hpp\"\n#include\"persistent/queue.hpp\"\n\nint main() {\n\t\
    int q;\n\tcin >> q;\n\tvector<persistent_queue<int>> v(q + 1);\n\tfor (int i =\
    \ 1; i <= q; i++) {\n\t\tint t, idx;\n\t\tscanf(\"%d%d\", &t, &idx);\n\t\tidx++;\n\
    \n\t\tif (t == 0) {\n\t\t\tint s;\n\t\t\tscanf(\"%d\", &s);\n\t\t\tv[i] = v[idx].push(s);\n\
    \t\t}\n\t\telse {\n\t\t\tprintf(\"%d\\n\", v[idx].front());\n\t\t\tv[i] = v[idx].pop();\n\
    \t\t}\n\t}\n}"
  dependsOn:
  - template.hpp
  - persistent/queue.hpp
  isVerificationFile: true
  path: main.test.cpp
  requiredBy: []
  timestamp: '2023-03-29 01:57:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: main.test.cpp
layout: document
redirect_from:
- /verify/main.test.cpp
- /verify/main.test.cpp.html
title: main.test.cpp
---
