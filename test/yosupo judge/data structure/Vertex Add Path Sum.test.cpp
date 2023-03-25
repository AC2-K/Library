#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
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
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g.add_edge(v, u);
    }
    g.build();

    segtree<ll, op, e> seg(2 * n);
    for (int v = 0; v < n; v++) {
        auto [in, out] = g.idx(v);
        seg.set(in, a[v]);
        seg.set(out + 1, -a[v]);
    }
    seg.build();
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int v, x;
            cin >> v >> x;
            auto [in, out] = g.idx(v);
            seg.apply(in, x);
            seg.apply(out + 1, -x);
        }
        else {
            int v, u;
            cin >> v >> u;
            ll ans = 0;
            int p_in = g.idx(g.lca(v, u)).first;
            {
                ans += seg.prod(p_in, g.idx(v).first + 1);
            }
            {
                ans += seg.prod(p_in + 1, g.idx(u).first + 1);
            }

            cout << ans << '\n';
        }
    }
}