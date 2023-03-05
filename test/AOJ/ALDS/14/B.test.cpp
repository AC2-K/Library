#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"

#include"template.hpp"
#include"string/rolling_hash.hpp"
int main() {
	string t, p;
	cin >> t >> p;
	RollingHash hasht(t), hashp(p);
	for (int i = 0; i + p.size() <= t.size(); i++) {
		if (hasht.range(i, i + p.size()) == hashp.range(0,p.size())) {
			cout << i << '\n';
		}
	}
}
