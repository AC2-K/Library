---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/P1508.test.cpp
    title: test/AOJ/P1508.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Splay Tree
    links: []
  bundledCode: "#line 2 \"src/data-structure/bbst/SplayTree.hpp\"\n#include <memory>\n\
    #include <vector>\n\nnamespace kyopro {\ntemplate <typename S, auto op, auto e>\
    \ struct SplayTree {\n    using usize = std::size_t;\n\n    struct Node {\n  \
    \      Node *lch, *rch, *par;\n        usize sz;\n        S value, agg;\n\n  \
    \      Node()\n            : lch(nullptr),\n              rch(nullptr),\n    \
    \          par(nullptr),\n              sz(1),\n              value(e()),\n  \
    \            agg(e()) {}\n        Node(const S& v)\n            : lch(nullptr),\n\
    \              rch(nullptr),\n              par(nullptr),\n              sz(1),\n\
    \              value(v),\n              agg(v) {}\n\n        static usize size(Node*\
    \ x) { return x ? x->sz : 0; }\n        static S fold(Node* x) { return x ? x->agg\
    \ : e(); }\n\n        void update() {\n            this->sz = 1 + size(this->lch)\
    \ + size(this->rch);\n            this->agg = op(op(fold(this->lch), this->value),\
    \ fold(this->rch));\n        }\n\n        void rotate() {\n            Node *pp,\
    \ *p, *c;\n            p = this->par;\n            pp = p->par;\n\n          \
    \  if (p->lch == this) {\n                c = this->rch;\n                this->rch\
    \ = p;\n                p->lch = c;\n            } else {\n                c =\
    \ this->lch;\n                this->lch = p;\n                p->rch = c;\n  \
    \          }\n\n            if (pp != nullptr) {\n                (pp->lch ==\
    \ p ? pp->lch : pp->rch) = this;\n            }\n\n            this->par = pp;\n\
    \            p->par = this;\n\n            if (c != nullptr) {\n             \
    \   c->par = p;\n            }\n\n            p->update();\n            this->update();\n\
    \        }\n\n        int state() {\n            if (!this->par) {\n         \
    \       return 0;\n            } else if (this->par->lch == this) {\n        \
    \        return -1;\n            } else if (this->par->rch == this) {\n      \
    \          return 1;\n            }\n            return 0;\n        }\n\n    \
    \    void splay() {\n            while (this->state() != 0) {\n              \
    \  if (this->par->state() == 0) {\n                    this->rotate();\n     \
    \           } else if (this->state() == this->par->state()) {\n              \
    \      this->par->rotate();\n                    this->rotate();\n           \
    \     } else {\n                    this->rotate();\n                    this->rotate();\n\
    \                }\n            }\n        }\n    };\n\n    Node* access(usize\
    \ k, Node* t) {\n        Node* now = t;\n\n        while (1) {\n            usize\
    \ lsize = Node::size(now->lch);\n            if (k < lsize) {\n              \
    \  now = now->lch;\n            } else if (k == lsize) {\n                now->splay();\n\
    \                return now;\n            } else {\n                now = now->rch;\n\
    \                k = k - lsize - 1;\n            }\n        }\n    }\n\n    Node*\
    \ merge(Node* l, Node* r) {\n        if (!l) return r;\n        if (!r) return\
    \ l;\n        l = access(Node::size(l) - 1, l);\n        l->rch = r;\n       \
    \ r->par = l;\n        l->update();\n        return l;\n    }\n\n    std::pair<Node*,\
    \ Node*> split(usize k, Node* t) {\n        if (!t) return {nullptr, nullptr};\n\
    \        if (k == 0) return {nullptr, t};\n        if (k == t->sz) return {t,\
    \ nullptr};\n\n        t = access(k, t);\n\n        Node *l, *r;\n        l =\
    \ t->lch;\n        r = t;\n        r->lch = nullptr;\n        l->par = nullptr;\n\
    \        r->update();\n        return {l, r};\n    }\n\npublic:\n    Node* root;\n\
    \    SplayTree(int n = 0) : SplayTree(std::vector<S>(n)) {}\n    SplayTree(const\
    \ std::vector<S>& a) : root(nullptr) {\n        if (a.size() == 0) return;\n\n\
    \        auto nodes = new Node*[a.size()];\n        for (int i = 0; i < (int)a.size();\
    \ ++i) nodes[i] = new Node(a[i]);\n        for (int i = 0; i < (int)a.size() -\
    \ 1; ++i) {\n            nodes[i + 1]->lch = nodes[i];\n            nodes[i]->par\
    \ = nodes[i + 1];\n            nodes[i + 1]->update();\n        }\n\n        root\
    \ = nodes[a.size() - 1];\n    }\n\n    S access(usize k) {\n        root = access(k,\
    \ root);\n        return root->value;\n    }\n\n    void update(int i, const S&\
    \ v) {\n        root = access(i, root);\n        root->value = v;\n        root->update();\n\
    \    }\n\n    void insert(int i, const S& v) {\n        auto [l, r] = split(i,\
    \ root);\n        Node* tmp = new Node(v);\n        root = merge(merge(l, tmp),\
    \ r);\n    }\n\n    void erase(int i) {\n        root = access(i, root);\n   \
    \     Node *l = root->lch, *r = root->rch;\n        if (l) l->par = nullptr;\n\
    \        if (r) r->par = nullptr;\n        root->lch = nullptr, root->rch = nullptr;\n\
    \        root = merge(l, r);\n        root->update();\n    }\n\n    S fold(int\
    \ l, int r) {\n        auto [xy, z] = split(r, root);\n        auto [x, y] = split(l,\
    \ xy);\n        S ans = y->agg;\n        root = merge(merge(x, y), z);\n     \
    \   return ans;\n    }\n};\n};  // namespace kyopro\n\n/**\n * @brief Splay Tree\n\
    \ */\n"
  code: "#pragma once\n#include <memory>\n#include <vector>\n\nnamespace kyopro {\n\
    template <typename S, auto op, auto e> struct SplayTree {\n    using usize = std::size_t;\n\
    \n    struct Node {\n        Node *lch, *rch, *par;\n        usize sz;\n     \
    \   S value, agg;\n\n        Node()\n            : lch(nullptr),\n           \
    \   rch(nullptr),\n              par(nullptr),\n              sz(1),\n       \
    \       value(e()),\n              agg(e()) {}\n        Node(const S& v)\n   \
    \         : lch(nullptr),\n              rch(nullptr),\n              par(nullptr),\n\
    \              sz(1),\n              value(v),\n              agg(v) {}\n\n  \
    \      static usize size(Node* x) { return x ? x->sz : 0; }\n        static S\
    \ fold(Node* x) { return x ? x->agg : e(); }\n\n        void update() {\n    \
    \        this->sz = 1 + size(this->lch) + size(this->rch);\n            this->agg\
    \ = op(op(fold(this->lch), this->value), fold(this->rch));\n        }\n\n    \
    \    void rotate() {\n            Node *pp, *p, *c;\n            p = this->par;\n\
    \            pp = p->par;\n\n            if (p->lch == this) {\n             \
    \   c = this->rch;\n                this->rch = p;\n                p->lch = c;\n\
    \            } else {\n                c = this->lch;\n                this->lch\
    \ = p;\n                p->rch = c;\n            }\n\n            if (pp != nullptr)\
    \ {\n                (pp->lch == p ? pp->lch : pp->rch) = this;\n            }\n\
    \n            this->par = pp;\n            p->par = this;\n\n            if (c\
    \ != nullptr) {\n                c->par = p;\n            }\n\n            p->update();\n\
    \            this->update();\n        }\n\n        int state() {\n           \
    \ if (!this->par) {\n                return 0;\n            } else if (this->par->lch\
    \ == this) {\n                return -1;\n            } else if (this->par->rch\
    \ == this) {\n                return 1;\n            }\n            return 0;\n\
    \        }\n\n        void splay() {\n            while (this->state() != 0) {\n\
    \                if (this->par->state() == 0) {\n                    this->rotate();\n\
    \                } else if (this->state() == this->par->state()) {\n         \
    \           this->par->rotate();\n                    this->rotate();\n      \
    \          } else {\n                    this->rotate();\n                   \
    \ this->rotate();\n                }\n            }\n        }\n    };\n\n   \
    \ Node* access(usize k, Node* t) {\n        Node* now = t;\n\n        while (1)\
    \ {\n            usize lsize = Node::size(now->lch);\n            if (k < lsize)\
    \ {\n                now = now->lch;\n            } else if (k == lsize) {\n \
    \               now->splay();\n                return now;\n            } else\
    \ {\n                now = now->rch;\n                k = k - lsize - 1;\n   \
    \         }\n        }\n    }\n\n    Node* merge(Node* l, Node* r) {\n       \
    \ if (!l) return r;\n        if (!r) return l;\n        l = access(Node::size(l)\
    \ - 1, l);\n        l->rch = r;\n        r->par = l;\n        l->update();\n \
    \       return l;\n    }\n\n    std::pair<Node*, Node*> split(usize k, Node* t)\
    \ {\n        if (!t) return {nullptr, nullptr};\n        if (k == 0) return {nullptr,\
    \ t};\n        if (k == t->sz) return {t, nullptr};\n\n        t = access(k, t);\n\
    \n        Node *l, *r;\n        l = t->lch;\n        r = t;\n        r->lch =\
    \ nullptr;\n        l->par = nullptr;\n        r->update();\n        return {l,\
    \ r};\n    }\n\npublic:\n    Node* root;\n    SplayTree(int n = 0) : SplayTree(std::vector<S>(n))\
    \ {}\n    SplayTree(const std::vector<S>& a) : root(nullptr) {\n        if (a.size()\
    \ == 0) return;\n\n        auto nodes = new Node*[a.size()];\n        for (int\
    \ i = 0; i < (int)a.size(); ++i) nodes[i] = new Node(a[i]);\n        for (int\
    \ i = 0; i < (int)a.size() - 1; ++i) {\n            nodes[i + 1]->lch = nodes[i];\n\
    \            nodes[i]->par = nodes[i + 1];\n            nodes[i + 1]->update();\n\
    \        }\n\n        root = nodes[a.size() - 1];\n    }\n\n    S access(usize\
    \ k) {\n        root = access(k, root);\n        return root->value;\n    }\n\n\
    \    void update(int i, const S& v) {\n        root = access(i, root);\n     \
    \   root->value = v;\n        root->update();\n    }\n\n    void insert(int i,\
    \ const S& v) {\n        auto [l, r] = split(i, root);\n        Node* tmp = new\
    \ Node(v);\n        root = merge(merge(l, tmp), r);\n    }\n\n    void erase(int\
    \ i) {\n        root = access(i, root);\n        Node *l = root->lch, *r = root->rch;\n\
    \        if (l) l->par = nullptr;\n        if (r) r->par = nullptr;\n        root->lch\
    \ = nullptr, root->rch = nullptr;\n        root = merge(l, r);\n        root->update();\n\
    \    }\n\n    S fold(int l, int r) {\n        auto [xy, z] = split(r, root);\n\
    \        auto [x, y] = split(l, xy);\n        S ans = y->agg;\n        root =\
    \ merge(merge(x, y), z);\n        return ans;\n    }\n};\n};  // namespace kyopro\n\
    \n/**\n * @brief Splay Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/bbst/SplayTree.hpp
  requiredBy: []
  timestamp: '2024-05-05 16:24:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/P1508.test.cpp
documentation_of: src/data-structure/bbst/SplayTree.hpp
layout: document
redirect_from:
- /library/src/data-structure/bbst/SplayTree.hpp
- /library/src/data-structure/bbst/SplayTree.hpp.html
title: Splay Tree
---
