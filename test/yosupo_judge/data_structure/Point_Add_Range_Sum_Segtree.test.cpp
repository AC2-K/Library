#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <iostream>
#include "../../../src/data-structure/segtree.hpp"
#include "../../../src/stream.hpp"

inline long long op(long long x, long long y) { return x + y; }
inline long long e() { return 0; }

using namespace std;
using namespace kyopro;

int main() {
    int n, q;
    read(n, q);
    vector<long long> a(n);
    for (auto& aa : a) read(aa);

    segtree<long long, op, e> seg(a);
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