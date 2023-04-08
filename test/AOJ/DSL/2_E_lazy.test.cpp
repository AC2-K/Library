#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"
#include<iostream>
#include "../../../src/data-structure/lazy_segtree.hpp"

int op(int x, int y) { return x + y; }
int comp(int x, int y) { return x + y; }
int mapping(int x, int y) { return x + y; }
int e() { return 0; }
int id() { return 0; }

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    kyopro::lazy_segtree<int, int, op, e, comp, id, mapping> seg(n);
    while (q--) {
        int t;
        scanf("%d", &t);
        if (!t) {
            int l, r, val;
            scanf("%d%d%d", &l, &r, &val);
            l--, r--;
            seg.apply(l, r + 1, val);
        } else {
            int i;
            scanf("%d", &i);
            i--;
            printf("%d\n", seg[i]);
        }
    }
}