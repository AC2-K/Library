#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <iostream>
#include "../../../src/data-structure/segtree.hpp"

using namespace std;
using namespace kyopro;

inline long long op(long long x, long long y) { return x + y; }
inline long long e() { return 0; }

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    segtree seg(n, op, e());
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        seg.set(i, a);
    }
    seg.build();
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", seg.fold(l, r));
    }
}