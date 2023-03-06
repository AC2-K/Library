#define PROBLEM "https://yukicoder.me/problems/no/789"

#include"template.hpp"
#include"data-structure/dynamic_segtree.hpp"

int op(int x, int y) { return x + y; }
int e() { return 0; }
int main() {
	const size_t n = 1000000001;
	dynamic_segtree<int, op, e> seg(n);

	int q;
	cin >> q;
	long long ans = 0;
	while (q--) {
		int type;
		cin >> type;
		if (type == 0) {
			size_t x;
			long long y;
			cin >> x >> y;
			seg.add(x, y);
		}
		else {
			size_t l, r;
			cin >> l >> r;
			ans += seg.prod(l, r + 1);
		}
	}
	cout << ans << '\n';
}