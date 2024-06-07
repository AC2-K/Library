---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Trie.test.cpp
    title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/BinaryTrie.hpp\"\n#include <cassert>\n\
    #include <cstdint>\n\nnamespace kyopro {\ntemplate <typename T, std::uint32_t\
    \ lg> class BinaryTrie {\n    using u32 = std::uint32_t;\n    using usize = std::size_t;\n\
    \n    struct Node {\n        usize cnt;\n        Node* par;\n        Node* ch[2]{nullptr,\
    \ nullptr};\n\n        Node() : cnt(0), par(nullptr) {}\n    };\n\npublic:\n \
    \   Node* root = new Node();\n\n    BinaryTrie() : root(new Node()){}\n\n    usize\
    \ size() const { return root->cnt; }\n    bool empty() const { return size() ==\
    \ 0; }\n    \n    usize count(T x) const {\n        Node* cur = root;\n      \
    \  for (int i = lg - 1; i >= 0; --i) {\n            T b = (x >> i & T(1));\n\n\
    \            if (cur->ch[b] == nullptr || cur->ch[b] == 0) {\n               \
    \ return 0;\n            } else {\n                cur = cur->ch[b];\n       \
    \     }\n        }\n\n        return cur->cnt;\n    }\n\n    void insert(T x)\
    \ {\n        Node* cur = root;\n\n        for (int i = lg - 1; i >= 0; --i) {\n\
    \            T b = (x >> i & T(1));\n\n            if (cur->ch[b] == nullptr)\
    \ {\n                cur->ch[b] = new Node();\n                cur->ch[b]->par\
    \ = cur;\n            }\n\n            cur = cur->ch[b];\n        }\n\n      \
    \  ++cur->cnt;\n\n        while (cur->par != nullptr) {\n            cur = cur->par;\n\
    \n            cur->cnt = 0;\n\n            if (cur->ch[0] != nullptr) cur->cnt\
    \ += cur->ch[0]->cnt;\n            if (cur->ch[1] != nullptr) cur->cnt += cur->ch[1]->cnt;\n\
    \        }\n    }\n\n    void erase(T x) {\n        Node* cur = root;\n      \
    \  for (int i = lg - 1; i >= 0; --i) {\n            T b = (x >> i & T(1));\n \
    \           cur = cur->ch[b];\n            assert(cur);\n        }\n\n       \
    \ --cur->cnt;\n\n        while (cur->par != nullptr) {\n            cur = cur->par;\n\
    \n            cur->cnt = 0;\n\n            if (cur->ch[0] != nullptr) {\n    \
    \            cur->cnt += cur->ch[0]->cnt;\n            }\n            if (cur->ch[1]\
    \ != nullptr) {\n                cur->cnt += cur->ch[1]->cnt;\n            }\n\
    \        }\n    }\n\n    T max() const {\n        assert(size() > 0);\n\n    \
    \    Node* cur = root;\n\n        T res = 0;\n        for (int i = lg - 1; i >=\
    \ 0; --i) {\n            if (cur->ch[1] != nullptr && cur->ch[1]->cnt != 0) {\n\
    \                cur = cur->ch[1];\n                res |= (T(1) << i);\n    \
    \        } else {\n                cur = cur->ch[0];\n            }\n        }\n\
    \n        return res;\n    }\n\n    T min() const {\n        assert(size() > 0);\n\
    \n        Node* cur = root;\n\n        T res = 0;\n\n        for (int i = lg -\
    \ 1; i >= 0; --i) {\n            if (cur->ch[0] != nullptr && cur->ch[0]->cnt\
    \ != 0) {\n                cur = cur->ch[0];\n            } else {\n         \
    \       cur = cur->ch[1];\n                res |= (T(1) << i);\n            }\n\
    \        }\n\n        return res;\n    }\n\n    T kth_smallest(usize k) const\
    \ {\n        assert(k < this->size());\n\n        Node* cur = root;\n        T\
    \ res = 0;\n\n        for (int i = lg - 1; i >= 0; --i) {\n            if (cur->ch[0]\
    \ != nullptr && k < cur->ch[0]->cnt) {\n                cur = cur->ch[0];\n  \
    \          } else {\n                if (cur->ch[0] != nullptr) k -= cur->ch[0]->cnt;\n\
    \n                cur = cur->ch[1];\n                res |= (T(1) << i);\n   \
    \         }\n        }\n\n        return res;\n    }\n\n    T kth_largest(usize\
    \ k) const {\n        assert(k < this->size());\n\n        Node* cur = root;\n\
    \        T res = 0;\n\n        for (int i = lg - 1; i >= 0; --i) {\n         \
    \   if (cur->ch[1] != nullptr && k < cur->ch[1]->cnt) {\n                cur =\
    \ cur->ch[1];\n                res |= (T(1) << i);\n            } else {\n   \
    \             if (cur->ch[1] != nullptr) k -= cur->ch[1]->cnt;\n             \
    \   cur = cur->ch[0];\n            }\n        }\n\n        return res;\n    }\n\
    };\n\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n\nnamespace kyopro\
    \ {\ntemplate <typename T, std::uint32_t lg> class BinaryTrie {\n    using u32\
    \ = std::uint32_t;\n    using usize = std::size_t;\n\n    struct Node {\n    \
    \    usize cnt;\n        Node* par;\n        Node* ch[2]{nullptr, nullptr};\n\n\
    \        Node() : cnt(0), par(nullptr) {}\n    };\n\npublic:\n    Node* root =\
    \ new Node();\n\n    BinaryTrie() : root(new Node()){}\n\n    usize size() const\
    \ { return root->cnt; }\n    bool empty() const { return size() == 0; }\n    \n\
    \    usize count(T x) const {\n        Node* cur = root;\n        for (int i =\
    \ lg - 1; i >= 0; --i) {\n            T b = (x >> i & T(1));\n\n            if\
    \ (cur->ch[b] == nullptr || cur->ch[b] == 0) {\n                return 0;\n  \
    \          } else {\n                cur = cur->ch[b];\n            }\n      \
    \  }\n\n        return cur->cnt;\n    }\n\n    void insert(T x) {\n        Node*\
    \ cur = root;\n\n        for (int i = lg - 1; i >= 0; --i) {\n            T b\
    \ = (x >> i & T(1));\n\n            if (cur->ch[b] == nullptr) {\n           \
    \     cur->ch[b] = new Node();\n                cur->ch[b]->par = cur;\n     \
    \       }\n\n            cur = cur->ch[b];\n        }\n\n        ++cur->cnt;\n\
    \n        while (cur->par != nullptr) {\n            cur = cur->par;\n\n     \
    \       cur->cnt = 0;\n\n            if (cur->ch[0] != nullptr) cur->cnt += cur->ch[0]->cnt;\n\
    \            if (cur->ch[1] != nullptr) cur->cnt += cur->ch[1]->cnt;\n       \
    \ }\n    }\n\n    void erase(T x) {\n        Node* cur = root;\n        for (int\
    \ i = lg - 1; i >= 0; --i) {\n            T b = (x >> i & T(1));\n           \
    \ cur = cur->ch[b];\n            assert(cur);\n        }\n\n        --cur->cnt;\n\
    \n        while (cur->par != nullptr) {\n            cur = cur->par;\n\n     \
    \       cur->cnt = 0;\n\n            if (cur->ch[0] != nullptr) {\n          \
    \      cur->cnt += cur->ch[0]->cnt;\n            }\n            if (cur->ch[1]\
    \ != nullptr) {\n                cur->cnt += cur->ch[1]->cnt;\n            }\n\
    \        }\n    }\n\n    T max() const {\n        assert(size() > 0);\n\n    \
    \    Node* cur = root;\n\n        T res = 0;\n        for (int i = lg - 1; i >=\
    \ 0; --i) {\n            if (cur->ch[1] != nullptr && cur->ch[1]->cnt != 0) {\n\
    \                cur = cur->ch[1];\n                res |= (T(1) << i);\n    \
    \        } else {\n                cur = cur->ch[0];\n            }\n        }\n\
    \n        return res;\n    }\n\n    T min() const {\n        assert(size() > 0);\n\
    \n        Node* cur = root;\n\n        T res = 0;\n\n        for (int i = lg -\
    \ 1; i >= 0; --i) {\n            if (cur->ch[0] != nullptr && cur->ch[0]->cnt\
    \ != 0) {\n                cur = cur->ch[0];\n            } else {\n         \
    \       cur = cur->ch[1];\n                res |= (T(1) << i);\n            }\n\
    \        }\n\n        return res;\n    }\n\n    T kth_smallest(usize k) const\
    \ {\n        assert(k < this->size());\n\n        Node* cur = root;\n        T\
    \ res = 0;\n\n        for (int i = lg - 1; i >= 0; --i) {\n            if (cur->ch[0]\
    \ != nullptr && k < cur->ch[0]->cnt) {\n                cur = cur->ch[0];\n  \
    \          } else {\n                if (cur->ch[0] != nullptr) k -= cur->ch[0]->cnt;\n\
    \n                cur = cur->ch[1];\n                res |= (T(1) << i);\n   \
    \         }\n        }\n\n        return res;\n    }\n\n    T kth_largest(usize\
    \ k) const {\n        assert(k < this->size());\n\n        Node* cur = root;\n\
    \        T res = 0;\n\n        for (int i = lg - 1; i >= 0; --i) {\n         \
    \   if (cur->ch[1] != nullptr && k < cur->ch[1]->cnt) {\n                cur =\
    \ cur->ch[1];\n                res |= (T(1) << i);\n            } else {\n   \
    \             if (cur->ch[1] != nullptr) k -= cur->ch[1]->cnt;\n             \
    \   cur = cur->ch[0];\n            }\n        }\n\n        return res;\n    }\n\
    };\n\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2024-06-07 23:12:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Trie.test.cpp
documentation_of: src/data-structure/BinaryTrie.hpp
layout: document
redirect_from:
- /library/src/data-structure/BinaryTrie.hpp
- /library/src/data-structure/BinaryTrie.hpp.html
title: src/data-structure/BinaryTrie.hpp
---
