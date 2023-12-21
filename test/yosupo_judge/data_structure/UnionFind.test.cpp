#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../../src/data-structure/dsu.hpp"
#include "../../../src/stream.hpp"

using namespace kyopro;

int main() {
    int n, q;
    read(n, q);
    dsu uf(n);
    while (q--) {
        int t, x, y;
        read(t, x, y);
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