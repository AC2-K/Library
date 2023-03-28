#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"template.hpp"
#include"data-structure/sparse_table.hpp"
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	sparse_table<int> rmq(n);
	rep(i, n) {
		int ai;
		scanf("%d", &ai);
		rmq.set(i, ai);
	}
	rmq.build();
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", &rmq);
	}
}