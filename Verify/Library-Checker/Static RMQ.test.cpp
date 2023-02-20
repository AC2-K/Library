#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"template.hpp"
#include"data-structure/sparse_table.hpp"
int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto& aa : a) {
		cin >> aa;
	}

	SparseTable<int> rmq(a);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << rmq.prod(l, r) << '\n';
	}
}