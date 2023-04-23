#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"
#include <iostream>
#include "../../../src/data-structure/dual_segtree.hpp"
using ull = unsigned long long;
inline ull op(ull x, ull y) { return y; }
inline ull e() { return (1ll << 31) - 1; }
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    kyopro::dual_segtree<ull, op, e> seg(n);
    while (q--) {
        int ty;
        scanf("%d", &ty);
        if (!ty) {
            int l, r;
            ull x;
            scanf("%d%d%lld", &l, &r, &x);
            seg.apply(l, r + 1, x);
        } else {
            int i;
            scanf("%d", &i);
            printf("%lld\n", seg[i]);
        }
    }
}
