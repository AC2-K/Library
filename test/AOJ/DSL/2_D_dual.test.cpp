#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"
#include "../../../src/data-structure/dual_segtree.hpp"
#include "../../../src/stream.hpp"
using ull = unsigned long long;
inline ull op(ull x, ull y) { return y; }
inline ull e() { return (1ll << 31) - 1; }
int main() {
    int n, q;
    kyopro::readint(n, q);
    kyopro::dual_segtree<ull, op, e> seg(n);
    while (q--) {
        int ty;
        kyopro::readint(ty);
        if (!ty) {
            int l, r;
            ull x;
            kyopro::readint(l, r, x);
            seg.apply(l, r + 1, x);
        } else {
            int i;
            kyopro::readint(i);
            kyopro::putint(seg[i]);
        }
    }
}
