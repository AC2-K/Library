---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/xor_shift.hpp
    title: src/random/xor_shift.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
    title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/BST/Treap.hpp\"\n#include <cassert>\n#include <memory>\n\
    #line 2 \"src/random/xor_shift.hpp\"\n#include <cstdint>\n#include <random>\n\n\
    namespace kyopro {\nstruct xor_shift32 {\n    uint32_t rng;\n    xor_shift32()\
    \ : rng(std::rand()) {}\n    uint32_t operator()() {\n        rng ^= rng << 13;\n\
    \        rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n  \
    \  }\n};\n};  // namespace kyopro\n#line 5 \"src/BST/Treap.hpp\"\n\nnamespace\
    \ kyopro {\n\ntemplate <class T>\nclass Treap {\n    using u32 = uint32_t;\n \
    \   xor_shift32 rng;\n    struct Node {\n        const T key;\n        const u32\
    \ priority;\n        std::shared_ptr<Node> l, r;\n        Node(const T& key, u32\
    \ priority)\n            : key(key), priority(priority), l(nullptr), r(nullptr)\
    \ {}\n    };\n    using sptr = std::shared_ptr<Node>;\n    sptr root = nullptr;\n\
    \    void split(const sptr t,const T& key, sptr& l, sptr& r) {\n        if (!t)\
    \ {\n            l = r = nullptr;\n        } else if (key < t->key) {\n      \
    \      split(t->l, key, l, t->l);\n            r = t;\n        } else {\n    \
    \        split(t->r, key, t->r, r), l = t;\n        }\n    }\n\n    void merge(sptr&\
    \ t, const sptr& l, const sptr& r) {\n        if (!l || !r) {\n            t =\
    \ l ? l : r;\n        } else if (l->priority > r->priority) {\n            merge(l->r,\
    \ l->r, r), t = l;\n        } else {\n            merge(r->l, l, r->l), t = r;\n\
    \        }\n    }\n\n    void insert(sptr& t, const sptr& item) {\n        if\
    \ (!t) {\n            t = item;\n        } else if (item->priority > t->priority)\
    \ {\n            split(t, item->key, item->l, item->r);\n            t = item;\n\
    \        } else {\n            insert(item->key < t->key ? t->l : t->r, item);\n\
    \        }\n    }\n\n    void erase(sptr& t,const T& key) {\n        if (!t) return;\n\
    \        if (t->key == key) {\n            merge(t, t->l, t->r);\n        } else\
    \ {\n            erase(key < t->key ? t->l : t->r, key);\n        }\n    }\n\n\
    \    const sptr find(const sptr& t,const T& key) const {\n        if (!t) {\n\
    \            return nullptr;\n        } else if (t->key == key) {\n          \
    \  return t;\n        } else {\n            return find(key < t->key ? t->l :\
    \ t->r, key);\n        }\n    }\n\npublic:\n    void insert(const T& key) { insert(root,\
    \ std::make_shared<Node>(key, rng())); }\n\n    void erase(const T& key) { erase(root,\
    \ key); }\n\n    const Node* find(const T& key) const { return find(root, key).get();\
    \ }\n    T min_element() const {\n        assert(root);\n        sptr cur = root;\n\
    \        while (cur->l) {\n            cur = cur->l;\n        }\n        T ans\
    \ = cur->key;\n        return ans;\n    }\n    T max_element(){\n        assert(root);\n\
    \        sptr cur = root;\n        while (cur->r) {\n            cur = cur->r;\
    \ \n        }\n        T ans = cur->key;\n        return ans;\n    }\n    T pop_front()\
    \ {\n        assert(root);\n        sptr cur = root;\n        while (cur->l) {\n\
    \            cur = cur->l;\n        }\n        T ans = cur->key;\n        merge(cur,\
    \ cur->l, cur->r);\n        return ans;\n    }\n    T pop_back() {\n        assert(root);\n\
    \        sptr cur = root;\n        while (cur->r) {\n            cur = cur->r;\
    \ \n        }\n        T ans = cur->key;\n        merge(cur, cur->l, cur->r);\n\
    \        return ans;\n    }\n};\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include \"../random/xor_shift.hpp\"\
    \n\nnamespace kyopro {\n\ntemplate <class T>\nclass Treap {\n    using u32 = uint32_t;\n\
    \    xor_shift32 rng;\n    struct Node {\n        const T key;\n        const\
    \ u32 priority;\n        std::shared_ptr<Node> l, r;\n        Node(const T& key,\
    \ u32 priority)\n            : key(key), priority(priority), l(nullptr), r(nullptr)\
    \ {}\n    };\n    using sptr = std::shared_ptr<Node>;\n    sptr root = nullptr;\n\
    \    void split(const sptr t,const T& key, sptr& l, sptr& r) {\n        if (!t)\
    \ {\n            l = r = nullptr;\n        } else if (key < t->key) {\n      \
    \      split(t->l, key, l, t->l);\n            r = t;\n        } else {\n    \
    \        split(t->r, key, t->r, r), l = t;\n        }\n    }\n\n    void merge(sptr&\
    \ t, const sptr& l, const sptr& r) {\n        if (!l || !r) {\n            t =\
    \ l ? l : r;\n        } else if (l->priority > r->priority) {\n            merge(l->r,\
    \ l->r, r), t = l;\n        } else {\n            merge(r->l, l, r->l), t = r;\n\
    \        }\n    }\n\n    void insert(sptr& t, const sptr& item) {\n        if\
    \ (!t) {\n            t = item;\n        } else if (item->priority > t->priority)\
    \ {\n            split(t, item->key, item->l, item->r);\n            t = item;\n\
    \        } else {\n            insert(item->key < t->key ? t->l : t->r, item);\n\
    \        }\n    }\n\n    void erase(sptr& t,const T& key) {\n        if (!t) return;\n\
    \        if (t->key == key) {\n            merge(t, t->l, t->r);\n        } else\
    \ {\n            erase(key < t->key ? t->l : t->r, key);\n        }\n    }\n\n\
    \    const sptr find(const sptr& t,const T& key) const {\n        if (!t) {\n\
    \            return nullptr;\n        } else if (t->key == key) {\n          \
    \  return t;\n        } else {\n            return find(key < t->key ? t->l :\
    \ t->r, key);\n        }\n    }\n\npublic:\n    void insert(const T& key) { insert(root,\
    \ std::make_shared<Node>(key, rng())); }\n\n    void erase(const T& key) { erase(root,\
    \ key); }\n\n    const Node* find(const T& key) const { return find(root, key).get();\
    \ }\n    T min_element() const {\n        assert(root);\n        sptr cur = root;\n\
    \        while (cur->l) {\n            cur = cur->l;\n        }\n        T ans\
    \ = cur->key;\n        return ans;\n    }\n    T max_element(){\n        assert(root);\n\
    \        sptr cur = root;\n        while (cur->r) {\n            cur = cur->r;\
    \ \n        }\n        T ans = cur->key;\n        return ans;\n    }\n    T pop_front()\
    \ {\n        assert(root);\n        sptr cur = root;\n        while (cur->l) {\n\
    \            cur = cur->l;\n        }\n        T ans = cur->key;\n        merge(cur,\
    \ cur->l, cur->r);\n        return ans;\n    }\n    T pop_back() {\n        assert(root);\n\
    \        sptr cur = root;\n        while (cur->r) {\n            cur = cur->r;\
    \ \n        }\n        T ans = cur->key;\n        merge(cur, cur->l, cur->r);\n\
    \        return ans;\n    }\n};\n};  // namespace kyopro"
  dependsOn:
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/BST/Treap.hpp
  requiredBy: []
  timestamp: '2023-05-03 09:49:54+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
documentation_of: src/BST/Treap.hpp
layout: document
redirect_from:
- /library/src/BST/Treap.hpp
- /library/src/BST/Treap.hpp.html
title: src/BST/Treap.hpp
---
