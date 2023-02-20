#define PROBLEM "https://judge.yosupo.jp/submission/126153"

#include"template.hpp"
#include"graph/lca.hpp"
int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].emplace_back(i);
        g[i].emplace_back(p);
    }
    LCA lca(g);
    lca.setup();
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << '\n';
    }
}