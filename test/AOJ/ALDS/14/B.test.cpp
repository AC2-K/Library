#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"

#include "template.hpp"
#include"string/rolling_hash.hpp"
int main() {
	string T, P;
	cin >> T >> P;
	if (T.size() < P.size())exit(0);
	RollingHash rh;
	auto t = rh.build(T);
	auto p = rh.build(P);
	ll hash = rh.range(p,0, P.size());
	for (int i = 0; i < T.size() - P.size() + 1; i++) {
		if (rh.range(t, i, i + P.size()) == hash) {

			cout << i << '\n';
		}
	}
}
