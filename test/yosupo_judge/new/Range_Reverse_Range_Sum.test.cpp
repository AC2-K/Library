#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"
#include <iostream>
#include "../../../src/data-structure/bbst/reversible_bbst.hpp"
#include "../../../src/stream.hpp"
using ll = long long;
inline ll op(ll x, ll y) { return x + y; }
inline ll e() { return 0; }
int main() {
    int n, q;
    kyopro::readint(n, q);
    kyopro::reversible_bbst<ll, op, e> bbst;
    for (int i = 0; i < n; i++) {
        int a;
        kyopro::readint(a);
        bbst.insert(i, a);
    }

    while (q--) {
        int t, l, r;
        kyopro::readint(t, l, r);
        if (!t) {
            bbst.reverse(l, r);
        } else {
            kyopro::putint(bbst.fold(l, r));
        }
    }
}