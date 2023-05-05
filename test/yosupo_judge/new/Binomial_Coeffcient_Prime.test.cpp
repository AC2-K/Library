#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include <iostream>
#include "../../../src/math/combination.hpp"
int main() {
    int t, m;
    scanf("%d%d", &t, &m);

    kyopro::dynamic_combination<(int)1e7> solver(m);
    while (t--) {
        int n, r;
        scanf("%d%d", &n, &r);
        if (n < r) {
            puts("0");
        } else {
            printf("%d\n", solver.binom(n, r));
        }
    }
}