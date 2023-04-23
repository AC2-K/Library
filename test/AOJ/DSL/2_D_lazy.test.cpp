#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"

#include <iostream>
#include "../../../src/data-structure/lazy_segtree.hpp"

inline int op(int x, int y) { return std::min(x, y); }
inline int comp(int x, int y) { return y; }
inline int mapping(int x, int y) { return y; }
inline int e() { return (1ll << 31) - 1; }
inline int id() { return (1ll << 31) - 1; }

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    kyopro::lazy_segtree<int, int, op, e, comp, id, mapping> seg(n);
    while (q--) {
        int t;
        scanf("%d", &t);
        if (!t) {
            int l, r, add;
            scanf("%d%d%d", &l, &r, &add);
            seg.apply(l, r + 1, add);
        } else {
            int i;
            scanf("%d", &i);
            printf("%lld\n", seg[i]);
        }
    }
}