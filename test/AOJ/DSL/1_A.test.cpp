#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include <iostream>
#include "../../../data-structure/dsu.hpp"
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    kyopro::dsu uf(n);
    while (q--) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (!t) {
            uf.merge(x, y);
        } else {
            puts(uf.same(x, y) ? "1" : "0");
        }
    }
}