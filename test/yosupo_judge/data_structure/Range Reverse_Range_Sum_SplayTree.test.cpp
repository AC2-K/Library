#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "../../../src/data-structure/bbst/SplayTree.hpp"
#include "../../../src/debug.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

using ll = long long;

constexpr inline ll op(ll x, ll y) noexcept { return x + y; }
constexpr inline ll e() noexcept { return 0; }

int main() {
    int n, q;
    read(n, q);
    vector<ll> a(n);
    rep(i, n) read(a[i]);

    SplayTree<ll, op, e> sg(a);

    while (q--) {
        int t, l, r;
        read(t, l, r);
        if (!t) {
            sg.reverse(l, r);
        } else {
            put(sg.fold(l, r));
        }
    }
}
