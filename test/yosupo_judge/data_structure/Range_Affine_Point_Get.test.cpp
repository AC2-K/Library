#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include <iostream>
#include "../../../src/data-structure/dual_segtree.hpp"
#include "../../../src/math/static_modint.hpp"

using mint = kyopro::static_modint32<998244353>;
using Affine = std::pair<mint, mint>;
inline Affine op(Affine g, Affine f) {
    auto a = f.first, b = f.second;
    auto c = g.first, d = g.second;
    return Affine(a * c, a * d + b);
}
inline Affine e() { return Affine(1, 0); }
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    kyopro::dual_segtree<Affine, op, e> sg(n);
    std::vector<mint> a(n);
    for (auto& aa : a) {
        std::cin >> aa;
    }
    while (q--) {
        int t;
        std::cin >> t;
        
        if (t == 0) {
            int l, r;
            mint b, c;
            std::cin >> l >> r >> b >> c;
            sg.apply(l, r, std::pair<mint,mint>(b, c));
        }
        else {
            int i;
            std::cin >> i;
            auto f = sg[i];
            mint ans = f.first * a[i] + f.second;
            std::cout << ans << '\n';
        }
        
    }
}
