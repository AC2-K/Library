#define PROBLEM "https://yukicoder.me/problems/no/789"
#include <iostream>
#include "../../src/data-structure/dynamic_segtree.hpp"
#include "../../src/stream.hpp"
constexpr inline int op(int x, int y) { return x + y; }
constexpr inline int e() { return 0; }

using namespace std;
using namespace kyopro;

int main() {
    const size_t n = 1000000001;
    dynamic_segtree<int, op, e> seg(n);

    int q;
    read(q);
    long long ans = 0;
    while (q--) {
        int type;
        read(type);
        if (!type) {
            size_t x;
            long long y;
            read(x, y);
            seg.apply(x, y);
        } else {
            size_t l, r;
            read(l, r);
            ans += seg.fold(l, r + 1);
        }
    }
    put(ans);
}