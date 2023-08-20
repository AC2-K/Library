#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <iostream>
#include "../../../src/data-structure/segtree.hpp"
#include "../../../src/math/static_modint.hpp"

using mint = kyopro::modint<998244353>;

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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    kyopro::segtree<F, op, e> seg(n);
    for (int i = 0; i < n; i++) {
        mint a, b;
        std::cin >> a >> b;
        seg.set(i, F{a, b});
    }
    seg.build();
    while (q--) {
        int t;
        std::cin >> t;
        if (!t) {
            int p;
            mint c, d;
            std::cin >> p >> c >> d;
            seg.update(p, F{c, d});
        } else {
            int l, r;
            mint x;
            std::cin >> l >> r >> x;
            F res = seg.fold(l, r);
            mint ans = res.a * x + res.b;
            std::cout << ans << '\n';
        }
    }
}