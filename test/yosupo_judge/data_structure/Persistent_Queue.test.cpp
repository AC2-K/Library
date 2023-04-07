#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include"template.hpp"
#include"persistent/queue.hpp"

int main() {
	int q;
	scanf("%d", &q);
	std::vector<persistent_queue<int>> v(q + 1);
	for (int i = 1; i <= q; i++) {
		int t, idx;
		scanf("%d%d", &t, &idx);
		idx++;

		if (t == 0) {
			int s;
			scanf("%d", &s);
			v[i] = v[idx].push(s);
		}
		else {
			printf("%d\n", v[idx].front());
			v[i] = v[idx].pop();
		}
	}
}