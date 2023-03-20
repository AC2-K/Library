#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include"template.hpp"
#include"data-structure/segtree.hpp"
#include"graph/euler_tour.hpp"
ll op(ll x, ll y) { return x + y; }

ll e() { return 0; }
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

    segtree<ll, op, e> seg(2 * n);
    for (int v = 0; v < n; v++) {
        int in = g.idx(v).first;
        seg.set(in, a[v]);
    }
    seg.build();
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
            cout << seg.prod(in,out + 1) << '\n';
        }
    }
}