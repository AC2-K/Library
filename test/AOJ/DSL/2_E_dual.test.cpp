#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E"

#include <iostream>
#include "../../../data-structure/dual_segtree.hpp"

using ull = unsigned long long;
ull op(ull x, ull y) { return x + y; }
ull e() { return 0; }
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    kyopro::dual_segtree<ull, op, e> seg(n);
    while (q--) {
        int ty;
        scanf("%d", &ty);
        if (ty == 0) {
            int l, r;
            ull x;
            scanf("%d%d%d", &l, &r, &x);
            l--, r--;
            seg.apply(l, r + 1, x);
        } else {
            int i;
            scanf("%d", &i);
            i--;
            printf("%lld\n", seg[i]);
        }
    }
}
