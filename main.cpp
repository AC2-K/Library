#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

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
            if (uf.same(x, y))
                puts("1");
            else
                puts("0");
        }
    }
}