#pragma once
#include <memory>
#include <vector>

namespace kyopro {
template <typename S, auto op, auto e> struct SplayTree {
    using usize = std::size_t;

    struct Node {
        Node *lch, *rch, *par;
        usize sz;
        S value, agg;
        bool rev;

        Node()
            : lch(nullptr),
              rch(nullptr),
              par(nullptr),
              sz(1),
              value(e()),
              agg(e()),
              rev(false) {}
        Node(const S& v)
            : lch(nullptr),
              rch(nullptr),
              par(nullptr),
              sz(1),
              value(v),
              agg(v),
              rev(false) {}

        static usize size(Node* x) { return x ? x->sz : 0; }
        static S fold(Node* x) { return x ? x->agg : e(); }
        static void reverse(Node*& x) {
            if (x) {
                x->rev ^= 1;
            }
        }

        void push() {
            if (this->rev) {
                std::swap(this->lch, this->rch);
                this->rev = false;
                Node::reverse(this->lch);
                Node::reverse(this->rch);
            }
        }

        void update() {
            this->sz = 1 + size(this->lch) + size(this->rch);
            this->agg = op(op(fold(this->lch), this->value), fold(this->rch));
        }

        void rotate() {
            Node *pp, *p, *c;
            p = this->par;
            pp = p->par;

            if (p->lch == this) {
                c = this->rch;
                this->rch = p;
                p->lch = c;
            } else {
                c = this->lch;
                this->lch = p;
                p->rch = c;
            }

            if (pp != nullptr) {
                (pp->lch == p ? pp->lch : pp->rch) = this;
            }

            this->par = pp;
            p->par = this;

            if (c != nullptr) {
                c->par = p;
            }

            p->update();
            this->update();
        }

        int state() {
            if (!this->par) {
                return 0;
            } else if (this->par->lch == this) {
                return -1;
            } else if (this->par->rch == this) {
                return 1;
            }
            return 0;
        }

        void splay() {
            this->push();
            while (this->state()) {
                Node* p = this->par;
                Node* pp = p->par;

                if (pp) pp->push();
                if (p) p->push();
                this->push();

                if (p->state() == 0) {
                    this->rotate();
                } else if (this->state() == p->state()) {
                    p->rotate();
                    this->rotate();
                } else {
                    this->rotate();
                    this->rotate();
                }

                if (pp) pp->update();
                if (p) p->update();
                this->update();
            }
        }
    };

    Node* access(usize k, Node* t) {
        Node* now = t;
        while (1) {
            now->push();
            usize lsize = Node::size(now->lch);
            if (k < lsize) {
                now = now->lch;
            } else if (k == lsize) {
                now->splay();
                return now;
            } else {
                now = now->rch;
                k = k - lsize - 1;
            }
        }
    }

    Node* merge(Node* l, Node* r) {
        if (!l) return r;
        if (!r) return l;
        l->push();
        r->push();
        l = access(Node::size(l) - 1, l);
        l->rch = r;
        r->par = l;
        l->update();

        return l;
    }

    std::pair<Node*, Node*> split(usize k, Node* t) {
        if (!t) return {nullptr, nullptr};
        if (k == 0) return {nullptr, t};
        if (k == t->sz) return {t, nullptr};
        t->push();
        t = access(k, t);
        Node *l, *r;
        l = t->lch;
        r = t;
        r->lch = nullptr;
        l->par = nullptr;
        r->update();
        return {l, r};
    }

public:
    Node* root;
    SplayTree(int n = 0) : SplayTree(std::vector<S>(n)) {}
    SplayTree(const std::vector<S>& a) : root(nullptr) {
        if (a.size() == 0) return;

        auto nodes = new Node*[a.size()];
        for (int i = 0; i < (int)a.size(); ++i) nodes[i] = new Node(a[i]);
        for (int i = 0; i < (int)a.size() - 1; ++i) {
            nodes[i + 1]->lch = nodes[i];
            nodes[i]->par = nodes[i + 1];
            nodes[i + 1]->update();
        }

        root = nodes[a.size() - 1];
    }

    S access(usize k) {
        root = access(k, root);
        return root->value;
    }

    void update(int i, const S& v) {
        root = access(i, root);
        root->value = v;
        root->update();
    }

    void insert(int i, const S& v) {
        auto [l, r] = split(i, root);
        Node* tmp = new Node(v);
        root = merge(merge(l, tmp), r);
    }

    void erase(int i) {
        root = access(i, root);
        Node *l = root->lch, *r = root->rch;
        if (l) l->par = nullptr;
        if (r) r->par = nullptr;
        root->lch = nullptr, root->rch = nullptr;
        root = merge(l, r);
        root->update();
    }

    S fold(int l, int r) {
        auto [xy, z] = split(r, root);
        auto [x, y] = split(l, xy);
        S ans = Node::fold(y);
        root = merge(merge(x, y), z);
        return ans;
    }

    void reverse(int l, int r) {
        auto [xy, z] = split(r, root);
        auto [x, y] = split(l, xy);
        Node::reverse(y);
        root = merge(merge(x, y), z);
    }
};
};  // namespace kyopro

/**
 * @brief Splay Tree
 */