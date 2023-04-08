#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include <iostream>
#include "../../../data-structure/segtree.hpp"
using S = long long;
S op(S x, S y) { return x + y; }
S e() { return 0; }

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
            printf("%lld\n", seg.prod(l, r + 1));
        }

    }
}
