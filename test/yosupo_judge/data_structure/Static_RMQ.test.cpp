#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <iostream>
#include "../../../src/data-structure/sparse_table.hpp"
inline int op(int x, int y) { return std::min(x, y); }

using namespace kyopro;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    sparse_table<int, decltype(op)> rmq(n, op);
    for (int i = 0; i < n; i++) {
        int ai;
        scanf("%d", &ai);
        rmq.set(i, ai);
    }
    rmq.build();
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", rmq.fold(l, r));
    }
}