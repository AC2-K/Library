#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "../../../src/data-structure/dual_segtree.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

using mint = modint<998244353>;
using Affine = std::pair<mint, mint>;
inline Affine op(Affine g, Affine f) {
    auto a = f.first, b = f.second;
    auto c = g.first, d = g.second;
    return Affine(a * c, a * d + b);
}
inline Affine e() { return Affine(1, 0); }
int main() {
    int n, q;
    read(n, q);
    dual_segtree<Affine, op, e> sg(n);
    std::vector<mint> a(n);
    for (auto& aa : a) {
        read(aa);
    }
    while (q--) {
        int t;
        read(t);

        if (!t) {
            int l, r;
            mint b, c;
            read(l, r, b, c);
            sg.apply(l, r, std::pair<mint, mint>(b, c));
        } else {
            int i;
            read(i);
            auto f = sg[i];
            mint ans = f.first * a[i] + f.second;
            put(ans.val());
        }
    }
}
