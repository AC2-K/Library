#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../../src/data-structure/segtree.hpp"
#include "../../../src/stream.hpp"
using S = long long;
inline S op(S x, S y) { return x + y; }
inline S e() { return 0; }

int main() {
    int n, q;
    kyopro::read(n, q);
    kyopro::segtree<S, op, e> seg(n);
    while (q--) {
        int t;
        kyopro::read(t);
        if (!t) {
            int i, x;
            kyopro::read(i, x);
            i--;
            seg.apply(i, x);
        } else {
            int l, r;
            kyopro::read(l, r);
            l--, r--;
            kyopro::put(seg.fold(l, r + 1));
        }
    }
}
