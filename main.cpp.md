---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/binary_trie.hpp
    title: data-structure/binary_trie.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline\
    \ void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void\
    \ chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/binary_trie.hpp\"\n\n\
    /// https://kazuma8128.hatenablog.com/entry/2018/05/06/022654\ntemplate <typename\
    \ T>\nclass binary_trie {\n    static_assert(is_unsigned<T>::value, \"T must be\
    \ unsigned!!!\");\n    static constexpr int w = numeric_limits<T>::digits;\n \
    \   struct node {\n\t\tint cnt;\n\t\tnode *ch[2];\n\t\tnode() : cnt(0), ch{ nullptr,\
    \ nullptr } {}\n\t};\n\tnode* add(node* t,const T& val, int b = w - 1) {\n\t\t\
    if (!t) t = new node;\n\t\tt->cnt += 1;\n\t\tif (b < 0) return t;\n\t\tbool f\
    \ = (val >> b) & static_cast<T>(1);\n\t\tt->ch[f] = add(t->ch[f], val, b - 1);\n\
    \t\treturn t;\n\t}\n\tnode* sub(node* t,const T& val, int b = w - 1) {\n\t\tassert(t);\n\
    \t\tt->cnt -= 1;\n\t\tif (t->cnt == 0) return nullptr;\n\t\tif (b < 0) return\
    \ t;\n\t\tbool f = (val >> b) & static_cast<T>(1);\n\t\tt->ch[f] = sub(t->ch[f],\
    \ val, b - 1);\n\t\treturn t;\n\t}\n\tnode* get_max(node* t, const T& val, int\
    \ b = w - 1) const {\n\t\tassert(t);\n\t\tif (b < 0) return 0;\n\t\tbool f = (val\
    \ >> b) & static_cast<T>(1);\n\t\tf ^= !t->ch[f];\n\t\treturn get_max(t->ch[f],\
    \ val, b - 1) | (static_cast<T>(f) << b);\n\t}\n\tT get(node* t, int k, int b\
    \ = w - 1) const {\n\t\tif (b < 0) return 0;\n\t\tint m = t->ch[0] ? t->ch[0]->cnt\
    \ : 0;\n\t\treturn k < m ? get(t->ch[0], k, b - 1) : get(t->ch[1], k - m, b -\
    \ 1) | (static_cast<T>(1) << b);\n\t}\n\tnode *root;\n\npublic:\n  \tbinary_trie()\
    \ : root(nullptr) {}\n\tint size() const {\n\t\treturn root ? root->cnt : 0;\n\
    \t}\n\tbool empty() const {\n\t\treturn size() == 0;\n\t}\n\tvoid insert(const\
    \ T& val) {\n\t\troot = add(root, val);\n\t}\n\tvoid erase(const T& val) {\n\t\
    \troot = sub(root, val);\n\t}\n\tint count(const T& val) const {\n\t\tif (!root)\
    \ return 0;\n\t\tnode *t = root;\n\t\tfor (int i = w - 1; i >= 0; i--) {\n\t\t\
    \tbool f = (val >> i) & static_cast<T>(1);\n\t\t\tt = t->ch[f];\n\t\t\tif (!t)\
    \ return 0;\n\t\t}\n\t\treturn t->cnt;\n\t}\n\tT max_element(T bias = 0) const\
    \ {\n\t\treturn get_max(root, bias);\n\t}\n\tT min_element(T bias = 0) const {\n\
    \t\treturn get_max(root, ~bias);\n\t}\n\tT operator[](int k) const {\n\t\tassert(0\
    \ <= k && k < size());\n\t\treturn get(root, k);\n\t}\n};\n#line 3 \"main.cpp\"\
    \nint main(){\n    binary_trie<uint32_t> st;\n    int q;\n    cin >> q;\n    while(q--){\n\
    \        int t, x;\n        cin >> t >> x;\n        if (t == 1) {\n          \
    \  st.insert(x);\n        }else{\n            x--;\n            auto v = st[x];\n\
    \            cout << v << '\\n';\n            st.erase(v);\n        }\n    }\n\
    }\n"
  code: "#include\"template.hpp\"\n#include\"data-structure/binary_trie.hpp\"\nint\
    \ main(){\n    binary_trie<uint32_t> st;\n    int q;\n    cin >> q;\n    while(q--){\n\
    \        int t, x;\n        cin >> t >> x;\n        if (t == 1) {\n          \
    \  st.insert(x);\n        }else{\n            x--;\n            auto v = st[x];\n\
    \            cout << v << '\\n';\n            st.erase(v);\n        }\n    }\n\
    }"
  dependsOn:
  - template.hpp
  - data-structure/binary_trie.hpp
  isVerificationFile: false
  path: main.cpp
  requiredBy: []
  timestamp: '2023-04-03 15:29:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: main.cpp
layout: document
redirect_from:
- /library/main.cpp
- /library/main.cpp.html
title: main.cpp
---
