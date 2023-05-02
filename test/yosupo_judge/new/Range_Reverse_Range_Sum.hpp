#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"
#include "../../src/BST/Reversible.hpp"
#include <iostream>
using ll = long long;
inline ll op(ll x, ll y) { return x + y; }
inline ll e() { return 0; }
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    kyopro::ReversibleBST<ll, op, e> bst;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        bst.insert(i, a);
    }

    while (q--) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if (!t) {
            bst.reverse(l, r);
        } else {
            printf("%lld\n", bst.fold(l, r));
        }
    }
}