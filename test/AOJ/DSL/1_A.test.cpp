#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include "../../../src/data-structure/dsu.hpp"
#include "../../../src/stream.hpp"
int main() {
    int n, q;
    kyopro::readint(n, q);
    kyopro::dsu uf(n);
    while (q--) {
        int t, x, y;
        kyopro::readint(t, x, y);
        if (!t) {
            uf.merge(x, y);
        } else {
            kyopro::putint(uf.same(x, y) ? 1 : 0);
        }
    }
}