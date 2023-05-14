#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "../../../src/stream.hpp"
#include "../../../src/tree/doubling.hpp"
int main() {
    int n, q;
    kyopro::readint(n, q);
    kyopro::doubling_on_tree g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        kyopro::readint(a, b);
        g.add_edge(a, b);
    }
    g.build();

    while (q--) {
        int s, t, i;
        kyopro::readint(s, t, i);
        kyopro::putint(g.jump(s, t, i));
    }
}