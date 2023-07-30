#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E"

#include "../../../src/data-structure/dual_segtree.hpp"
#include "../../../src/stream.hpp"

using ull = unsigned long long;
inline ull op(ull x, ull y) { return x + y; }
inline ull e() { return 0; }
int main() {
    int n, q;
    kyopro::read(n, q);
    kyopro::dual_segtree<ull, op, e> seg(n);
    while (q--) {
        int ty;
        kyopro::read(ty);
        if (!ty) {
            int l, r;
            ull x;
            kyopro::read(l, r, x);
            l--, r--;
            seg.apply(l, r + 1, x);
        } else {
            int i;
            kyopro::read(i);
            i--;
            kyopro::put(seg[i]);
        }
    }
}
