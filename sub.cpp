#pragma once
#include <memory>
#include "random/xor_shift.hpp"

/// @ref
/// https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_reverse_range_sum/sol/correct.cpp

namespace kyopro {
/// @brief なんかすごい木
template <typename S,
          class F,
          S (*op)(S, S),
          S (*e)(),
          F (*composition)(F, F),
          F (*id)(),
          S (*mapping)(S, F, int)>
class Tree {
    using u32 = uint32_t;
    xor_shift32 rng;
    struct Node {
        std::unique_ptr<Node> l, r;
        u32 priority;
        S value, prod;

        F lazy;
        int size;
        // 反転するような要請が来ているか?(すでに来た分を処理していたらfalse)
        bool rev;

        Node(const S& v, u32 prio)
            : l(),
              r(),
              priority(prio),
              value(v),
              prod(e()),
              lazy(id()),
              size(1),
              rev(false) {}
    };

    using ptr = std::unique_ptr<Node>;
    int size(const ptr& p) const { return p ? p->size : 0; }
    S fold(const ptr& p) { return p ? p->prod : e(); }

    void reverse(const ptr& p) {
        if (p) {
            p->rev ^= 1;
        }
    }

    void update(const ptr& p) {
        p->size = size(p->l) + size(p->r) + 1;
        p->prod = op(p->value, op(fold(p->l), fold(p->r)));
    }
    void push(const ptr& p) {
        if (p && p->rev) {
            p->rev = false;
            std::swap(p->l, p->r);
            reverse(p->l), reverse(p->r);
        }

        if (p && p->lazy != id()) {
            if (p->l) {
                p->l->lazy = composition(p->l->lazy, p->lazy);
                p->l->prod = mapping(p->l->prod, p->lazy, size(p->l));
            }
            if (p->r) {
                p->r->lazy = composition(p->r->lazy, p->lazy);
                p->r->prod = mapping(p->r->prod, p->lazy, size(p->r));
            }
        }

        update(p);
    }

    std::pair<ptr, ptr> split(ptr p, int k) {
        if (!p) return {nullptr, nullptr};

        push(p);
        int s = size(p->l);
        if (s >= k) {
            auto [l, r] = split(std::move(p->l), k);
            p->l = std::move(r);
            update(p);

            return {std::move(l), std::move(p)};
        } else {
            auto [l, r] = split(std::move(p->r), k - s - 1);

            p->r = std::move(l);
            update(p);

            return {std::move(p), std::move(r)};
        }
    }

    ptr merge(ptr l, ptr r) {
        if (!l) return r;
        if (!r) return l;

        if (l->priority < r->priority) {
            push(r);
            r->l = merge(std::move(l), std::move(r->l));
            update(r);
            return r;
        } else {
            push(l);
            l->r = merge(std::move(l->r), std::move(r));
            update(l);

            return l;
        }
    }

    ptr root = nullptr;

public:
    void insert(int i, S a) {
        auto [l, r] = split(std::move(root), i);
        ptr item = std::make_unique<Node>(a, rng());
        root = merge(std::move(l), std::move(item));
        root = merge(std::move(root), std::move(r));
    }

    void erase(int i) {
        auto [xy, z] = split(std::move(root), i + 1);
        auto [x, y] = split(std::move(xy), i);
        root = merge(std::move(x), std::move(z));
    }
    S fold(int l, int r) {
        auto [xy, z] = split(std::move(root), r);
        auto [x, y] = split(std::move(xy), l);
        auto res = fold(y);
        xy = merge(std::move(x), std::move(y));
        root = merge(std::move(xy), std::move(z));
        return res;
    }
    
    void apply(int l, int r, const F& f) {
        auto [xy, z] = split(std::move(root), r);
        auto [x, y] = split(std::move(xy), l);

        y->lazy = composition(y->lazy, f);
        y->prod = mapping(y->prod, f, size(y));

        xy = merge(std::move(x), std::move(y));
        root = merge(std::move(xy), std::move(z));
    }
    
    void reverse(int l, int r) {
        auto [xy, z] = split(std::move(root), r);
        auto [x, y] = split(std::move(xy), l);
        reverse(y);
        xy = merge(std::move(x), std::move(y));
        root = merge(std::move(xy), std::move(z));
    }
};
};  // namespace kyopro

#include "math/static_modint.hpp"
#include "template.hpp"
using namespace std;
using mint = kyopro::static_modint32<MOD2>;
using S = mint;
inline S op(S a, S b) { return a + b; }
inline S e() { return mint(0); }
using Affine = pair<mint, mint>;
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
    return a * d + b * length;
};
int main() {
    kyopro::Tree<S, Affine, op, e, composition, id, mapping> stree;
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        mint ai = mint::raw(tmp);
        stree.insert(i, ai);
    }
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int i, x;
            scanf("%d%d", &i, &x);
            stree.insert(i, mint::raw(x));
        } else if (t == 1) {
            int i;
            scanf("%d", &i);
            stree.erase(i);
        } else if (t == 2) {
            int l, r;
            scanf("%d%d", &l, &r);
            stree.reverse(l, r);
        } else if (t == 3) {
            int l, r, a, b;
            scanf("%d%d%d%d", &l, &r, &a, &b);
            stree.apply(l, r, Affine(mint::raw(a), mint::raw(b)));
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", stree.fold(l, r).val());
        }
    }
}