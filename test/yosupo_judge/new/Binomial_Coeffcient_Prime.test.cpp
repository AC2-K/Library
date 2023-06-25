#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include <iostream>
#include "../../../src/math/combination.hpp"
#include "../../../src/math/dynamic_modint.hpp"
#include "../../../src/stream.hpp"
using mint = kyopro::barrett_modint<10>;
using namespace std;
int main() {
    int t, m;
    kyopro::readint(t, m);
    mint::set_mod(m);
    kyopro::combination<mint, (int)1e7> solver;
    while (t--) {
        int n, r;
        kyopro::readint(n, r);
        if (n < r) {
            kyopro::putint(0);
        } else {
            kyopro::putint(solver.binom(n, r).val());
        }
    }
}