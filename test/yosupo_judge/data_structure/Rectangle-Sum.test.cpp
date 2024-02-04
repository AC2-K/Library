#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../../src/data-structure/data-structure-2d/merge-sort-tree.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"
using namespace std;
using namespace kyopro;

int main() {
    int n, q;
    read(n, q);

    merge_sort_tree<int, int, ll> mgst;
    rep(i, n) {
        int x, y, w;
        read(x, y, w);
        mgst.add_point(x, y, w);
    }
    mgst.build();
    while (q--) {
        int l, d, r, u;
        read(l, d, r, u);
        put(mgst.fold(l, r, d, u));
    }
}