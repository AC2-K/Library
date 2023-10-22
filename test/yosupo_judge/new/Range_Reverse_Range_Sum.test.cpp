#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "../../../src/data-structure/bbst/reversible_bbst.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"
using ll = long long;
constexpr inline ll op(ll x, ll y) { return x + y; }
constexpr inline ll e() { return 0; }

using namespace std;
using namespace kyopro;

int main() {
    int n, q;
    read(n, q);
    reversible_bbst<ll, op, e> bbst;
    for (int i = 0; i < n; i++) {
        int a;
        read(a);
        bbst.insert(i, a);
    }

    while (q--) {
        int t, l, r;
        read(t, l, r);
        if (!t) {
            bbst.reverse(l, r);
        } else {
            put(bbst.fold(l, r));
        }
    }
}