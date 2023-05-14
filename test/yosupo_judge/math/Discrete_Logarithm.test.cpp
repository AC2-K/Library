#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include <iostream>
#include "../../../src/math/mod_log.hpp"

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y, p;
        scanf("%d%d%d", &x, &y, &p);
        printf("%d\n", kyopro::mod_log(x, y, p));
    }
}