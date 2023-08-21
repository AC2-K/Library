#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <iostream>
#include "../../../src/data-structure/BIT.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n, q;
    read(n, q);
    BIT<long long> seg(n);
    for (int i = 0; i < n; i++) {
        int a;
        read(a);
        seg.add(i, a);
    }

    while (q--) {
        int t;
        read(t);
        if (t == 0) {
            int p, x;
            read(p, x);
            seg.add(p, x);
        } else {
            int l, r;
            read(l, r);
            put(seg.sum(l, r));
        }
    }
}