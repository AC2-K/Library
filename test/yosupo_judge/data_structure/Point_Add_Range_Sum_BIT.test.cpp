#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <iostream>
#include "../../../src/data-structure/BIT.hpp"
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    kyopro::BIT<long long> seg(n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        seg.add(i, a);
    }

    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int p, x;
            scanf("%d%d", &p, &x);
            seg.add(p, x);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", seg.sum(l, r));
        }
    }
}