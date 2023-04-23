#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "../../../src/math/primitive_root.hpp"
#include <iostream>
int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        long long p;
        scanf("%lld", &p);
        long long ans = kyopro::primitive_root(p);
        printf("%lld\n", ans);
    }
}
