#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"

#include"template.hpp"
#include"data-structure/dual_segtree.hpp"

using ull = unsigned long long;
ull op(ull x, ull y) {
	return y;	
}
ull e() {
	return (1ll << 31) - 1;
}
int main() {
	int n, q;
	cin >> n >> q;
	dual_segtree<ull,op, e> seg(n);
	while (q--) {
		int ty;
		cin >> ty;
		if (ty == 0) {
			int l, r;
			ull x;
			cin >> l >> r >> x;
			seg.apply(l, r + 1, x);
		}
		else {
			int i;
			cin >> i;
			cout << seg[i] << '\n';
		}
		//seg.print();
	}
}
