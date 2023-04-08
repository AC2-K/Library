#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include<iostream>
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
        }
        else {
            if (uf.same(x, y))puts("1");
            else puts("0");
        }
    }
}