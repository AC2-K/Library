#define PROBLEM \
    "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "../../../src/data-structure/bbst/lazy_reversible_bbst.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

using mint = modint<998244353>;
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
    lazy_reversible_bbst<S, Affine, op, e, composition, id, mapping> stree;
    int n, q;
    read(n, q);
    for (int i = 0; i < n; ++i) {
        mint ai;
        read(ai);
        stree.insert(i, ai);
    }
    while (q--) {
        int t;
        read(t);
        if (t == 0) {
            int i, x;
            read(i, x);
            stree.insert(i, mint::raw(x));
        } else if (t == 1) {
            int i;
            read(i);
            stree.erase(i);
        } else if (t == 2) {
            int l, r;
            read(l, r);
            stree.reverse(l, r);
        } else if (t == 3) {
            int l, r, a, b;
            read(l, r, a, b);
            stree.apply(l, r, Affine(mint::raw(a), mint::raw(b)));
        } else {
            int l, r;
            read(l, r);
            put(stree.fold(l, r).val());
        }
    }
}