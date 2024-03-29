#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <iostream>
#include "../../../src/data-structure/lazy_segtree.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
using mint = kyopro::modint<998244353>;
struct S {
    mint s;
    int len;
};
inline S op(S a, S b) { return S{a.s + b.s, a.len + b.len}; }
inline S e() { return S{0, 0}; }
using Affine = std::pair<mint, mint>;
inline Affine composition(Affine g, Affine f) {
    // f(g)
    // a(cx+d)+b
    auto a = f.first, b = f.second;
    auto c = g.first, d = g.second;
    return Affine(a * c, a * d + b);
}
inline Affine id() { return Affine(1, 0); }
inline S mapping(S d, Affine f) {
    mint a = f.first, b = f.second;
    d.s *= a, d.s += b * d.len;
    return d;
};

int main() {
    int n, q;
    kyopro::read(n, q);
    kyopro::lazy_segtree<S, Affine, op, e, composition, id, mapping> sg(n);
    for (int i = 0; i < n; i++) {
        mint a;
        kyopro::read(a);
        sg.set(i, {a, 1});
    }
    sg.build();
    while (q--) {
        int t;
        kyopro::read(t);
        if (t == 0) {
            int l, r;
            mint b, c;
            kyopro::read(l, r, b, c);
            sg.apply(l, r, Affine(b, c));
        } else {
            int l, r;
            kyopro::read(l, r);
            auto res = sg.fold(l, r);
            kyopro::put(res.s.val());
        }
    }
}