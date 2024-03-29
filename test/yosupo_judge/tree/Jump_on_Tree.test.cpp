#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "../../../src/stream.hpp"
#include "../../../src/tree/doubling.hpp"
int main() {
    int n, q;
    kyopro::read(n, q);
    kyopro::doubling g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        kyopro::read(a, b);
        g.add_edge(a, b);
    }
    g.build();

    while (q--) {
        int s, t, i;
        kyopro::read(s, t, i);
        kyopro::put(g.jump(s, t, i));
    }
}