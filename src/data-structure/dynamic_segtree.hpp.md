---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki/No789.test.cpp
    title: test/yuki/No789.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links:
    - https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
  bundledCode: "#line 2 \"src/data-structure/dynamic_segtree.hpp\"\n#include <cassert>\n\
    #include <cstddef>\n#include <cstdint>\nnamespace kyopro {\n/**\n * @brief \u52D5\
    \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> class dynamic_segtree {\npublic:\n    explicit dynamic_segtree(std::size_t\
    \ n = 0) : n(n), root(nullptr) {\n        root = new Node();\n    }\n    ~dynamic_segtree()\
    \ { delete root; }\n\nprivate:\n    struct Node {\n        S val;\n        Node\
    \ *l, *r, *parent;\n\n        constexpr explicit Node(const S& v = e(), Node*\
    \ pt = nullptr)\n            : val(v), l(nullptr), r(nullptr), parent(pt) {}\n\
    \        ~Node() { delete l, delete r; }\n    };\n    using ptr = Node*;\n\n \
    \   Node* root;\n    const std::size_t n;\n\nprivate:\n    Node* find(const std::size_t\
    \ i) {\n        assert(0 <= i && i < n);\n\n        std::size_t l = 0, r = n;\n\
    \n        Node* p = root;\n\n        while (r - l > 1) {\n            std::size_t\
    \ md = (r + l) >> 1;\n            if (i < md) {\n                if (!p->l) {\n\
    \                    p->l = new Node(e(), p);\n                }\n           \
    \     p = p->l;\n                r = md;\n            } else {\n             \
    \   if (!p->r) {\n                    p->r = new Node(e(), p);\n             \
    \   }\n                p = p->r;\n                l = md;\n            }\n   \
    \     }\n        return p;\n    }\n    void push(Node* p) {\n        while (p\
    \ = p->parent) {\n            p->val = op((p->l ? p->l->val : e()), (p->r ? p->r->val\
    \ : e()));\n        }\n    }\n\npublic:\n    void apply(std::size_t i, const S&\
    \ x) {\n        assert(0 <= i && i < n);\n        auto p = find(i);\n        p->val\
    \ = op(p->val, x);\n        push(p);\n    }\n    void update(std::size_t i, const\
    \ S& x) {\n        assert(0 <= i && i < n);\n        auto p = find(i);\n     \
    \   p->val = x;\n        push(p);\n    }\n    S at(std::size_t i) {\n        assert(0\
    \ <= i && i < n);\n        return find(i)->val;\n    }\n    S fold(std::size_t\
    \ l, std::size_t r) const {\n        assert(0 <= l && l <= r && r <= n);\n   \
    \     if (l == r) {\n            return e();\n        }\n        return internal_fold(root,\
    \ 0, n, l, r);\n    }\n\nprivate:\n    S internal_fold(const Node* p,\n      \
    \              std::size_t l,\n                    std::size_t r,\n          \
    \          std::size_t L,\n                    std::size_t R) const {\n      \
    \  if (!p || r <= L || R <= l) {\n            return e();\n        }\n       \
    \ if (L <= l && r <= R) {\n            return p->val;\n        }\n\n        std::size_t\
    \ mid = (l + r) >> 1;\n        return op(internal_fold(p->l, l, mid, L, R),\n\
    \                  internal_fold(p->r, mid, r, L, R));\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @see https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <cstddef>\n#include <cstdint>\n\
    namespace kyopro {\n/**\n * @brief \u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n */\ntemplate <class S, S (*op)(S, S), S (*e)()> class dynamic_segtree {\npublic:\n\
    \    explicit dynamic_segtree(std::size_t n = 0) : n(n), root(nullptr) {\n   \
    \     root = new Node();\n    }\n    ~dynamic_segtree() { delete root; }\n\nprivate:\n\
    \    struct Node {\n        S val;\n        Node *l, *r, *parent;\n\n        constexpr\
    \ explicit Node(const S& v = e(), Node* pt = nullptr)\n            : val(v), l(nullptr),\
    \ r(nullptr), parent(pt) {}\n        ~Node() { delete l, delete r; }\n    };\n\
    \    using ptr = Node*;\n\n    Node* root;\n    const std::size_t n;\n\nprivate:\n\
    \    Node* find(const std::size_t i) {\n        assert(0 <= i && i < n);\n\n \
    \       std::size_t l = 0, r = n;\n\n        Node* p = root;\n\n        while\
    \ (r - l > 1) {\n            std::size_t md = (r + l) >> 1;\n            if (i\
    \ < md) {\n                if (!p->l) {\n                    p->l = new Node(e(),\
    \ p);\n                }\n                p = p->l;\n                r = md;\n\
    \            } else {\n                if (!p->r) {\n                    p->r\
    \ = new Node(e(), p);\n                }\n                p = p->r;\n        \
    \        l = md;\n            }\n        }\n        return p;\n    }\n    void\
    \ push(Node* p) {\n        while (p = p->parent) {\n            p->val = op((p->l\
    \ ? p->l->val : e()), (p->r ? p->r->val : e()));\n        }\n    }\n\npublic:\n\
    \    void apply(std::size_t i, const S& x) {\n        assert(0 <= i && i < n);\n\
    \        auto p = find(i);\n        p->val = op(p->val, x);\n        push(p);\n\
    \    }\n    void update(std::size_t i, const S& x) {\n        assert(0 <= i &&\
    \ i < n);\n        auto p = find(i);\n        p->val = x;\n        push(p);\n\
    \    }\n    S at(std::size_t i) {\n        assert(0 <= i && i < n);\n        return\
    \ find(i)->val;\n    }\n    S fold(std::size_t l, std::size_t r) const {\n   \
    \     assert(0 <= l && l <= r && r <= n);\n        if (l == r) {\n           \
    \ return e();\n        }\n        return internal_fold(root, 0, n, l, r);\n  \
    \  }\n\nprivate:\n    S internal_fold(const Node* p,\n                    std::size_t\
    \ l,\n                    std::size_t r,\n                    std::size_t L,\n\
    \                    std::size_t R) const {\n        if (!p || r <= L || R <=\
    \ l) {\n            return e();\n        }\n        if (L <= l && r <= R) {\n\
    \            return p->val;\n        }\n\n        std::size_t mid = (l + r) >>\
    \ 1;\n        return op(internal_fold(p->l, l, mid, L, R),\n                 \
    \ internal_fold(p->r, mid, r, L, R));\n    }\n};\n};  // namespace kyopro\n\n\
    /**\n * @see https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2023-10-22 17:06:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/No789.test.cpp
documentation_of: src/data-structure/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/dynamic_segtree.hpp
- /library/src/data-structure/dynamic_segtree.hpp.html
title: "\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
