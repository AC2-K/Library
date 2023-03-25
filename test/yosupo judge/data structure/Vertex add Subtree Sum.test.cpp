#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include"template.hpp"
#include"data-structure/BIT.hpp"
#include"graph/euler_tour.hpp"
int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto& aa : a) {
        cin >> aa;
    }

    EulerTour g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g.add_edge(i, p);
    }
    g.build();

    BIT<ll> seg(2 * n);
    for (int v = 0; v < n; v++) {
        int in = g.idx(v).first;
        seg.add(in, a[v]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int v;
            cin >> v;
            int x;
            cin >> x;
            int in = g.idx(v).first;
            seg.add(in, x);
        }
        else {
            int v;
            cin >> v;
            int in, out;
            tie(in, out) = g.idx(v);
            cout << seg.sum(in,out + 1) << '\n';
        }
    }
}