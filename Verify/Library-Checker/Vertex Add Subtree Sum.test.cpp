#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include<bits/stdc++.h>
using namespace std;
#include"GraphAlgorithm/euler_tour.hpp"
#include"DataStructure/segtree.hpp"
using S = long long;
S op(S x, S y) { return x+y; }
S e() { return 0; }
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& aa : a) {
        cin >> aa;
    }
    EulerTour et(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        et.add_edge(p, i);
    }
    et.build(0);

    segtree<S, op, e> seg(et.tour.size());
    for (int v = 0; v < n; v++) {
        seg.set(et.in[v], a[v]);
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
            seg.add(et.in[v], x);
        }
        else {
            int v;
            cin >> v;
            cout << seg.prod(et.in[v], et.out[v] + 1) << '\n';
        }
    }
}