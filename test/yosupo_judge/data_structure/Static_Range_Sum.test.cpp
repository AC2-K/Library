#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <iostream>
#include "../../../src/data-structure/segtree.hpp"

namespace for_segtree {
using S = long long;
S op(S x, S y) { return x + y; }
S e() { return 0; }
};  // namespace for_segtree
int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    kyopro::segtree<for_segtree::S, for_segtree::op, for_segtree::e> seg(n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        seg.set(i, a);
    }
    seg.build();
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", seg.prod(l, r));
    }
}