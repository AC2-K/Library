#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include "../../../src/data-structure/lazy_segtree.hpp"
#include "../../../src/stream.hpp"

inline int op(int x, int y) { return x + y; }
inline int comp(int x, int y) { return x + y; }
inline int mapping(int x, int y) { return x + y; }
inline int e() { return 0; }
inline int id() { return 0; }

int main() {
    int n, q;
    kyopro::readint(n, q);
    kyopro::lazy_segtree<int, int, op, e, comp, id, mapping> seg(n);
    while (q--) {
        int t;
        kyopro::readint(t);
        if (!t) {
            int l, r, val;
            kyopro::readint(l, r, val);
            l--, r--;
            seg.apply(l, r + 1, val);
        } else {
            int i;
            kyopro::readint(i);
            i--;
            kyopro::putint(seg[i]);
        }
    }
}