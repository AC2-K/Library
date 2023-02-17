class EulerTour {
	using graph = vector<vector<int>>;
	graph g;
public:
	vector<int> in, out, depth,tour;
    EulerTour(int n) :g(n), depth(n), in(n), out(n) {}
	void add_edge(int a, int b) {
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	void build(int root){
		depth[root] = 0;
		function<void(int, int)> dfs = [&](int v, int par = -1)-> void {
			in[v] = tour.size();
			tour.emplace_back(v);
			for (const auto& c : g[v])if (c != par) {
				depth[c] = depth[v] + 1;
				dfs(c, v);
				tour.emplace_back(v);
			}
			out[v] = tour.size() - 1;
		};
		dfs(root, -1);
	}
};