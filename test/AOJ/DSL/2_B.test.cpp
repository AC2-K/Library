#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include <iostream>
#include "../../../src/data-structure/segtree.hpp"
using S = long long;
inline S op(S x, S y) { return x + y; }
inline S e() { return 0; }

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    kyopro::segtree<S, op, e> seg(n);
    while (q--) {
        int t;
        scanf("%d", &t);
        if (!t) {
            int i, x;
            scanf("%d%d", &i, &x);
            i--;
            seg.apply(i, x);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            printf("%lld\n", seg.fold(l, r + 1));
        }
    }
}
