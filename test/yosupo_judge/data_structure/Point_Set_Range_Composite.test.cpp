#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <iostream>
#include "../../../src/data-structure/segtree.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

using mint = modint<998244353>;

struct F {
    mint a, b;
};

inline F op(F l, F r) {
    mint na = l.a * r.a;
    mint nb = (l.b * r.a + r.b);
    return F{na, nb};
}
inline F e() { return F{1, 0}; }
int main() {
    int n, q;
    read(n, q);
    segtree<F, op, e> seg(n);
    for (int i = 0; i < n; i++) {
        mint a, b;
        read(a, b);
        seg.set(i, F{a, b});
    }
    seg.build();
    while (q--) {
        int t;
        read(t);
        if (!t) {
            int p;
            mint c, d;
            read(p, c, d);
            seg.update(p, F{c, d});
        } else {
            int l, r;
            mint x;
            read(l, r, x);
            F res = seg.fold(l, r);
            mint ans = res.a * x + res.b;
            put(ans);
        }
    }
}