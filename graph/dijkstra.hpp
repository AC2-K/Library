#pragma once


struct edge {
	int to;
	ll cost;
	edge(int to, ll cost) : to(to), cost(cost) {}
};
/// @brief Dijkstra (ダイクストラ法)
/// @note edge構造体をさらに宣言しないこと!!!
pair<vector<uint64_t>, vector<int>> dijkstra(int s,
	const vector<vector<edge>>& g) {
	vector<uint64_t> dist(g.size(), infl);
	vector<int> pre(g.size(), -1);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
	que.emplace(0, s);
	dist[s] = 0;
	pre[s] = s;
	while (!que.empty()) {
		auto [d, v] = que.top();
		que.pop();
		if (dist[v] != d) {
			continue;
		}

		for (const auto& [nv, c] : g[v]) {
			if (dist[v] + c < dist[nv]) {
				dist[nv] = dist[v] + c;
				pre[nv] = v;
				que.emplace(dist[nv], nv);
			}
		}
	}
	return { dist, pre };
}
