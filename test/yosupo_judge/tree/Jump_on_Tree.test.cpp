#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "../../../src/stream.hpp"
#include "../../../src/tree/doubling.hpp"

using namespace kyopro;

int main() {
    int n, q;
    read(n, q);
    doubling g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        read(a, b);
        g.add_edge(a, b);
    }
    g.build();

    while (q--) {
        int s, t, i;
        read(s, t, i);
        put(g.jump(s, t, i));
    }
}