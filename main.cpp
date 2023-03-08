#include"template.hpp"
#include"data-structure/sparse_table.hpp"
class EulerTour {
	sparse_table<P> rmq;   //find lca
	vector<int> in, out;
	graph g;
	int n;  //node size


public:
    EulerTour(const int &n) : n(n), g(n), in(n, -1), out(n, -1){}

    void add_edge(const int& u, const int& v) {
		g[v].emplace_back(u);
		g[u].emplace_back(v);
	}


	void build(int root = 0) {
		int now = 0;
		vector<P> vec(2 * n);
		function<void(int, int, int) > dfs = [&](int v, int from, int depth) -> void {
			in[v] = now;
			vec[now++] = { depth,v };
			for (const auto& nv : g[v]) {
				if (nv == from) {
					continue;
				}

                dfs(nv, v, depth + 1);
            }
            out[v] = now;
			//どうする...?
			if (from != -1) {
                vec[now++] = {depth, from};
            }
            return;
		};

		dfs(0, -1, 0);
        if (now < vec.size()){
            vec[now++] = {-1, -1};
        }

        for (int v = 0; v < n; v++){
            if (in[v] == -1){
                vec[now++] = {-1, -1};
                dfs(v, -1, 0);
                if(now<vec.size()){
                    vec[now++] = {-1, -1};
                }
            }
        }
        rmq = sparse_table<P>(vec);
    }



	P idx(const int& v) const {
		return { in[v],out[v] };
	}

	int lca(int u, int v)  {
		if (in[u] > in[v] + 1) {
			swap(u, v);
		}
		return rmq.prod(in[u], in[v] + 1).second;
	}
	template<class F>
	void node_query(int v, int u, const F& f) {
		int p = lca(v, u);
		f(in[p], in[v] + 1);
		f(in[p], in[u] + 1);
	}
};
#include"data-structure/segtree.hpp"
ll op(ll x, ll y) { return x + y; }
ll e() { return 0; }
int main() {
	int n, q;

	cin >> n >> q;
	vector<ll> a(n);
	for (auto& aa : a) {
		cin >> aa;
	}

	EulerTour et(n);
	rep(i, n - 1) {
		int u, v;
		cin >> u >> v;
		et.add_edge(u, v);
	}
    et.build();

    segtree<ll, op, e> seg(2 * n);
    rep(v, n){
        int p, q;
		tie(p, q) = et.idx(v);
		seg.set(p, a[v]);
		seg.set(q, -a[v]);
    }
    seg.build();

	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int p, x;
			cin >> p >> x;
			int s, t;
			tie(s, t) = et.idx(p);
			seg.add(s, a[p]);
			seg.add(t, -a[p]);
		}
		else {
			int u, v;
			cin >> u >> v;
			int ans = 0;
			auto f = [&](int x, int y)-> void {ans += seg.prod(x, y); };
			et.node_query(u, v, f);

			cout << ans << '\n';
		}
	}
}
