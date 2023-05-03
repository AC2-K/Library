#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "../../../src/BST/lazy_reversible_rbst.hpp"
#include "../../../src/math/static_modint.hpp"
#include <iostream>
using mint = kyopro::static_modint32<998244353>;
using S = mint;
inline S op(S a, S b) { return a + b; }
inline S e() { return mint(0); }
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
    return a * d + b * length;
};
int main() {
    kyopro::lazy_reversible_rbst<S, Affine, op, e, composition, id, mapping>stree;
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