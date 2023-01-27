#include<bits/stdc++.h>
using namespace std;

class scc_graph {

	vector<vector<int>> g,rg;
	int sz;
public:
	scc_graph(int n) : sz(n), g(n) {	}

	void add_edge(int from, int to) {
		g[from].emplace_back(to);
		rg[to].emplace_back(from);
	}

	vector<vector<int>> scc() {
		vector<vector<int>> vec;

		vector<int> ord;
		vector<bool> vis(sz,false);
		auto dfs1 = [&](auto f, int v)-> void {
			vis[v] = true;
			for (auto nv : g[v]) {
				if (vis[nv])continue;
				f(f, nv);
			}
			ord.emplace_back(v);
		};
		dfs1(dfs1, 0);

		reverse(ord.begin(), ord.end());


		for (auto& v : vis) {
			v = false;
		}
	}

};
int main() {
	scc_graph g(100);
}