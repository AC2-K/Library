#include<bits/stdc++.h>
using namespace std;

class scc_graph {

	vector<vector<int>> g={ },rg={  };
	int sz=0;
public:
	scc_graph(int n) : sz(n), g(n),rg(n) {	}

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
			return;
		};
		for(int v = 0;v < sz ;v++){
            if(vis[v])continue;
            dfs1(dfs1, 0);
        }

		reverse(ord.begin(), ord.end());

		for (int v = 0; v < sz; v++) {
			vis[v] = false;
		}

		for (int i = 0; i < sz; i++) {
			int vi = ord[i];
			if (vis[vi])continue;
			vector<int> res;

			auto dfs2 = [&](auto f, int v)-> void {
				res.emplace_back(v);
				vis[v] = true;
				for (auto nv : rg[v]) {
					if (vis[nv])continue;
					f(f,nv);
				}
			};

			dfs2(dfs2, vi);

			vec.emplace_back(res);
		}
		return vec;
	}

};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	scc_graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g.add_edge(a, b);
	}

	auto res = g.scc();
    cout<<res.size()<<'\n';
	for (auto &vec : res) {
        cout<<vec.size()<<' ';
		for (auto &v : vec) {
			cout << v << ' ';
		}
        cout<<'\n';
	}
}