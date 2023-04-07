#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include"template.hpp"
#include"graph/euler_tour.hpp"
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    EulerTour g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g.add_edge(p, i);
    }
    g.build();
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << g.lca(u, v) << '\n';
    }
}