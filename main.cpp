#pragma once
#include "random/xor_shift.hpp"

namespace kyopro {
/// @brief 反転可能抽象化遅延評価付き平衡二分探索木
/// @tparam S モノイド
/// @tparam op 演算
/// @tparam e 単位元

template <class S,
          class F,
          S (*op)(S, S),
          S (*e)(),
          F (*composition)(F, F),
          F (*id)(),
          S (*mapping)(S, F, int)>
class ImplicitTreap {
    xor_shift32 rng;

    using u32 = uint32_t;
    struct Node {
        S value, prod;
        F lz;
        u32 priority;
        int size;
        bool rev;
        Node *l, *r;
        Node(const S& value, u32 prio)
            : l(nullptr),
              r(nullptr),
              value(value),
              prod(e()),
              lz(id()),
              size(1),
              priority(prio),
              rev(false) {}
    };
    Node* r = nullptr;
    int size(Node* t) const { return t ? t->size : 0; }
    S fold(Node* t) const { return t ? t->prod : e(); }

    void eval_size(Node* t) {
        if (t) {
            t->size = size(t->l) + size(t->r) + 1;
        }
    }
    void eval_prod(Node* t) {
        if (t) {
            t->prod = op(fold(t->l), fold(t->r));
        }
    }

    void push_up(Node* t) {
        eval_prod(t);
        eval_size(t);
    }
    void push_down(Node* t) {
        if (t && t->rev) {
            std::swap(t->l, t->r);
            if (t->l) t->l->rev ^= 1;
            if (t->r) t->r->rev ^= 1;
            t->rev = false;
        }

        if (t && t->lz != id()) {
            if (t->l) {
                t->l->lz = composition(t->l->lz, t->lz);
                t->l->prod = mapping(t->l->prod, t->lazy, size(t->l));
            }
            if (t->r) {
                t->r->lz = composition(t->r->lz, t->lz);
                t->r->prod = mapping(t->r->prod, t->lazy, size(t->r));
            }

            t->value = mapping(t->value, t->lz, 1);
            t->lz = id();
        }
        push_up();
    }

    void split(Node* t, int key, Node*& l, Node*& r) {
        if (!t) {
            l = nullptr;
            r = nullptr;
            return;
        }

        push_down(t);
        int implicit_key = size(t->l) + 1;
        if (key < implicit_key) {
            split(t->l, key, l, t->l), r = t;
        } else {
            split(t->r, key - implicit_key, t->r, r), l = t;
        }
        push_up(t);
    }


    void merge(Node*&t,Node*l,Node*r){
        push_down(l);
        push_down(r);
        if (!l) {
            t = r;
            return;
        }
        if(!r){
            t = l;
            return;
        }
    }
};
};  // namespace kyopro

using mint = int;
using S = int;
inline S op(S a, S b) { return a + b; }
inline S e() { return 0; }
using Affine = std::pair<mint, mint>;
inline Affine composition(Affine g, Affine f) {
    // f(g)
    // a(cx+d)+b
    auto a = f.first, b = f.second;
    auto c = g.first, d = g.second;
    return Affine(a * c, a * d + b);
}
inline Affine id() { return Affine(1, 0); }
inline S mapping(S d, Affine f, int length) {
    auto [a, b] = f;
    return a* d + b* length;
};

int main() {
    kyopro::ImplicitTreap<S, Affine, op, e, composition, id, mapping> treap;
}