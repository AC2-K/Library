#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../../../src/data-structure/segtree.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"
#include "../../../src/tree/HeavyLightDecomposition.hpp"

using namespace std;
using namespace kyopro;

using mint = modint<998244353>;
using affine = pair<mint, mint>;

affine composite(affine x, affine y) noexcept {
    return affine(x.first * y.first, x.second * y.first + y.second);
}
affine id() noexcept { return affine(mint::raw(1), mint()); }

affine op1(affine x, affine y) { return composite(x, y); }
affine op2(affine x, affine y) { return composite(y, x); }

int main() {
    int n, q;
    read(n, q);
    vector<mint> a(n), b(n);
    rep(i, n) read(a[i], b[i]);

    HeavyLightDecomposition g(n);
    rep(i, n - 1) {
        int u, v;
        read(u, v);
        g.add_edge(u, v);
    }
    g.build(0);

    segtree<affine, op1, id> sg1(n);
    segtree<affine, op2, id> sg2(n);

    rep(i, n) {
        int j = g.idx(i).first;
        sg1.set(j, affine(a[i], b[i]));
        sg2.set(j, affine(a[i], b[i]));
    }
    sg1.build(), sg2.build();

    while (q--) {
        int c, x, y, z;
        read(c, x, y, z);

        if (c == 0) {
            int j = g.idx(x).first;
            sg1.update(j, affine(mint(y), mint(z)));
            sg2.update(j, affine(mint(y), mint(z)));
        } else {
            mint ans = mint::raw(z);

            auto f = [&](int l, int r) {
                if (l <= r) {
                    auto [s, t] = sg1.fold(l, r);
                    ans = s * ans + t;
                } else {
                    auto [s, t] = sg2.fold(r, l);
                    ans = s * ans + t;
                }
            };

            g.path_noncommutative_query(x, y, f);
            put(ans);
        }
    }
}
