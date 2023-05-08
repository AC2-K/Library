#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"
#include <iostream>
#include "../../../src/BST/reversible_bst.hpp"
#include "../../../src/stream.hpp"
using ll = long long;
inline ll op(ll x, ll y) { return x + y; }
inline ll e() { return 0; }
int main() {
    int n, q;
    kyopro::readint(n, q);
    kyopro::reversible_bst<ll, op, e> bst;
    for (int i = 0; i < n; i++) {
        int a;
        kyopro::readint(a);
        bst.insert(i, a);
    }

    while (q--) {
        int t, l, r;
        kyopro::readint(t, l, r);
        if (!t) {
            bst.reverse(l, r);
        } else {
            kyopro::putint(bst.fold(l, r));
        }
    }
}