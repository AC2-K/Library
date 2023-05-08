#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include <iostream>
#include "../../../src/math/combination.hpp"
#include "../../../src/stream.hpp"
int main() {
    int t, m;
    kyopro::readint(t, m);
    kyopro::dynamic_combination<(int)1e7> solver(m);
    while (t--) {
        int n, r;
        kyopro::readint(n, r);
        if (n < r) {
            kyopro::putint(0);
        } else {
            kyopro::putint(solver.binom(n, r));
        }
    }
}