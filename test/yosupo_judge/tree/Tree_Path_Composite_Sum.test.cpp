#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"
#include "../../../src/tree/Rerooting.hpp"

using namespace std;
using namespace kyopro;

using mint = modint<998244353>;

int main() {
    int n;
    read(n);
    vector<mint> a(n), b(n - 1), c(n - 1);
    rep(i, n) read(a[i]);

    auto op = [&](pair<mint, mint> x, pair<mint, mint> y) {
        return pair(x.first + y.first, x.second + y.second);
    };
    auto put_edge_vertex = [&](pair<mint, mint> x, int e, int) {
        return pair(b[e] * x.first + c[e] * x.second, x.second);
    };
    auto leaf = [&](int v) { return pair(a[v], mint::raw(1)); };

    Rerooting<pair<mint, mint>, decltype(op), decltype(put_edge_vertex),
              decltype(leaf)>
        t(n, pair<mint, mint>(), op, put_edge_vertex, leaf);

    rep(i, n - 1) {
        int u, v;
        read(u, v, b[i], c[i]);
        t.add_edge(u, v, i);
    }
    vector answer = t.run();
    rep(i, n) put(answer[i].first + a[i]);
}