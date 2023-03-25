#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include"template.hpp"
#include"data-structure/dual_segtree.hpp"
#include"math/static_modint.hpp"
using mint = static_modint32<MOD2>;
using Affine = pair<mint, mint>;
Affine op(Affine g, Affine f) {
	auto a = f.first, b = f.second;
	auto c = g.first, d = g.second;
	return Affine(a * c, a * d + b);
}
Affine e() { return Affine(1, 0); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	dual_segtree<Affine, op, e> sg(n);
	vector<mint> a(n);
	for (auto& aa : a) {
		cin >> aa;
	}
	while (q--) {
		int t;
		cin >> t;   
		if (t == 0) {
			int l, r;
			mint b, c;
			cin >> l >> r >> b >> c;
			sg.apply(l, r, Affine(b, c));
		}
		else {
			int i;
			cin >> i;
			auto f = sg[i];
			mint ans = f.first * a[i] + f.second;
			cout << ans << '\n';
		}
	}
}
