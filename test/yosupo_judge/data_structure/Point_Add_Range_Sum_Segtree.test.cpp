#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <iostream>
#include "../../../src/data-structure/segtree.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n, q;
    read(n, q);
    vector<ll> a(n);
    for (auto& aa : a) read(aa);
    
    segtree seg(
        a, [](ll a, ll b) { return a + b; }, 0LL);
    while (q--) {
        int t;
        read(t);
        if (!t) {
            int p, x;
            read(p, x);
            seg.apply(p, x);
        } else {
            int l, r;
            read(l, r);
            put(seg.fold(l, r));
        }
    }
}