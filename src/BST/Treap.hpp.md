---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: xor shift
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
    title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/BST/Treap.md
    document_title: Treap
    links: []
  bundledCode: "#line 2 \"src/BST/Treap.hpp\"\n#include <cassert>\n#include <memory>\n\
    #line 2 \"src/random/xor_shift.hpp\"\n#include <chrono>\n#include <cstdint>\n\
    #include <random>\n\nnamespace kyopro {\nstruct xor_shift32 {\n    uint32_t rng;\n\
    \    constexpr explicit xor_shift32(uint32_t seed) : rng(seed) {}\n    explicit\
    \ xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief xor shift\n*/\n#line 5 \"src/BST/Treap.hpp\"\
    \n\nnamespace kyopro {\n\n/**\n * @brief Treap\n * @tparam T \u4E57\u305B\u308B\
    \u30C7\u30FC\u30BF\u578B\n */\ntemplate <class T>\nclass Treap {\n    using u32\
    \ = uint32_t;\n    xor_shift32 rng;\n    struct Node {\n        const T key;\n\
    \        const u32 priority;\n        std::shared_ptr<Node> l, r;\n        Node(const\
    \ T& key, u32 priority)\n            : key(key), priority(priority), l(nullptr),\
    \ r(nullptr) {}\n    };\n    using sptr = std::shared_ptr<Node>;\n    sptr root\
    \ = nullptr;\n    void split(const sptr t, const T& key, sptr& l, sptr& r) {\n\
    \        if (!t) {\n            l = r = nullptr;\n        } else if (key < t->key)\
    \ {\n            split(t->l, key, l, t->l);\n            r = t;\n        } else\
    \ {\n            split(t->r, key, t->r, r), l = t;\n        }\n    }\n\n    void\
    \ merge(sptr& t, const sptr& l, const sptr& r) {\n        if (!l || !r) {\n  \
    \          t = l ? l : r;\n        } else if (l->priority > r->priority) {\n \
    \           merge(l->r, l->r, r), t = l;\n        } else {\n            merge(r->l,\
    \ l, r->l), t = r;\n        }\n    }\n\n    void insert(sptr& t, const sptr& item)\
    \ {\n        if (!t) {\n            t = item;\n        } else if (item->priority\
    \ > t->priority) {\n            split(t, item->key, item->l, item->r);\n     \
    \       t = item;\n        } else {\n            insert(item->key < t->key ? t->l\
    \ : t->r, item);\n        }\n    }\n\n    void erase(sptr& t, const T& key) {\n\
    \        if (!t) return;\n        if (t->key == key) {\n            merge(t, t->l,\
    \ t->r);\n        } else {\n            erase(key < t->key ? t->l : t->r, key);\n\
    \        }\n    }\n\n    const sptr find(const sptr& t, const T& key) const {\n\
    \        if (!t) {\n            return nullptr;\n        } else if (t->key ==\
    \ key) {\n            return t;\n        } else {\n            return find(key\
    \ < t->key ? t->l : t->r, key);\n        }\n    }\n\npublic:\n    constexpr explicit\
    \ Treap() : rng(2023) {}\n    void insert(const T& key) {\n        insert(root,\
    \ std::make_shared<Node>(key, rng()));\n    }\n\n    void erase(const T& key)\
    \ { erase(root, key); }\n\n    const Node* find(const T& key) const { return find(root,\
    \ key).get(); }\n    T min_element() const {\n        assert(root);\n        sptr\
    \ cur = root;\n        while (cur->l) {\n            cur = cur->l;\n        }\n\
    \        T ans = cur->key;\n        return ans;\n    }\n    T max_element() {\n\
    \        assert(root);\n        sptr cur = root;\n        while (cur->r) {\n \
    \           cur = cur->r;\n        }\n        T ans = cur->key;\n        return\
    \ ans;\n    }\n    T pop_front() {\n        assert(root);\n        sptr cur =\
    \ root;\n        while (cur->l) {\n            cur = cur->l;\n        }\n    \
    \    T ans = cur->key;\n        merge(cur, cur->l, cur->r);\n        return ans;\n\
    \    }\n    T pop_back() {\n        assert(root);\n        sptr cur = root;\n\
    \        while (cur->r) {\n            cur = cur->r;\n        }\n        T ans\
    \ = cur->key;\n        merge(cur, cur->l, cur->r);\n        return ans;\n    }\n\
    };\n};  // namespace kyopro\n\n/**\n * @docs docs/BST/Treap.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include \"../random/xor_shift.hpp\"\
    \n\nnamespace kyopro {\n\n/**\n * @brief Treap\n * @tparam T \u4E57\u305B\u308B\
    \u30C7\u30FC\u30BF\u578B\n */\ntemplate <class T>\nclass Treap {\n    using u32\
    \ = uint32_t;\n    xor_shift32 rng;\n    struct Node {\n        const T key;\n\
    \        const u32 priority;\n        std::shared_ptr<Node> l, r;\n        Node(const\
    \ T& key, u32 priority)\n            : key(key), priority(priority), l(nullptr),\
    \ r(nullptr) {}\n    };\n    using sptr = std::shared_ptr<Node>;\n    sptr root\
    \ = nullptr;\n    void split(const sptr t, const T& key, sptr& l, sptr& r) {\n\
    \        if (!t) {\n            l = r = nullptr;\n        } else if (key < t->key)\
    \ {\n            split(t->l, key, l, t->l);\n            r = t;\n        } else\
    \ {\n            split(t->r, key, t->r, r), l = t;\n        }\n    }\n\n    void\
    \ merge(sptr& t, const sptr& l, const sptr& r) {\n        if (!l || !r) {\n  \
    \          t = l ? l : r;\n        } else if (l->priority > r->priority) {\n \
    \           merge(l->r, l->r, r), t = l;\n        } else {\n            merge(r->l,\
    \ l, r->l), t = r;\n        }\n    }\n\n    void insert(sptr& t, const sptr& item)\
    \ {\n        if (!t) {\n            t = item;\n        } else if (item->priority\
    \ > t->priority) {\n            split(t, item->key, item->l, item->r);\n     \
    \       t = item;\n        } else {\n            insert(item->key < t->key ? t->l\
    \ : t->r, item);\n        }\n    }\n\n    void erase(sptr& t, const T& key) {\n\
    \        if (!t) return;\n        if (t->key == key) {\n            merge(t, t->l,\
    \ t->r);\n        } else {\n            erase(key < t->key ? t->l : t->r, key);\n\
    \        }\n    }\n\n    const sptr find(const sptr& t, const T& key) const {\n\
    \        if (!t) {\n            return nullptr;\n        } else if (t->key ==\
    \ key) {\n            return t;\n        } else {\n            return find(key\
    \ < t->key ? t->l : t->r, key);\n        }\n    }\n\npublic:\n    constexpr explicit\
    \ Treap() : rng(2023) {}\n    void insert(const T& key) {\n        insert(root,\
    \ std::make_shared<Node>(key, rng()));\n    }\n\n    void erase(const T& key)\
    \ { erase(root, key); }\n\n    const Node* find(const T& key) const { return find(root,\
    \ key).get(); }\n    T min_element() const {\n        assert(root);\n        sptr\
    \ cur = root;\n        while (cur->l) {\n            cur = cur->l;\n        }\n\
    \        T ans = cur->key;\n        return ans;\n    }\n    T max_element() {\n\
    \        assert(root);\n        sptr cur = root;\n        while (cur->r) {\n \
    \           cur = cur->r;\n        }\n        T ans = cur->key;\n        return\
    \ ans;\n    }\n    T pop_front() {\n        assert(root);\n        sptr cur =\
    \ root;\n        while (cur->l) {\n            cur = cur->l;\n        }\n    \
    \    T ans = cur->key;\n        merge(cur, cur->l, cur->r);\n        return ans;\n\
    \    }\n    T pop_back() {\n        assert(root);\n        sptr cur = root;\n\
    \        while (cur->r) {\n            cur = cur->r;\n        }\n        T ans\
    \ = cur->key;\n        merge(cur, cur->l, cur->r);\n        return ans;\n    }\n\
    };\n};  // namespace kyopro\n\n/**\n * @docs docs/BST/Treap.md\n */"
  dependsOn:
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/BST/Treap.hpp
  requiredBy: []
  timestamp: '2023-05-07 23:12:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
documentation_of: src/BST/Treap.hpp
layout: document
redirect_from:
- /library/src/BST/Treap.hpp
- /library/src/BST/Treap.hpp.html
title: Treap
---
