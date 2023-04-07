#pragma once
#include <queue>
#include <vector>

struct edge {
	int to;
	long long cost;
	edge(int to, long long cost) : to(to), cost(cost) {}
};
/// @brief Dijkstra (ダイクストラ法)
std::pair<std::vector<long long>, std::vector<int>> dijkstra(int s,
	const std::vector<std::vector<edge>>& g) {
	std::vector<long long> dist(g.size(), infl);
	std::vector<int> pre(g.size(), -1);
	std::priority_queue<std::pair<long long, int>,std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> que;
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
