#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include <iostream>
#include "../../../src/math/combination.hpp"
#include "../../../src/math/dynamic_modint.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;
using mint = barrett_modint<>;
int main() {
    int t, m;
    read(t, m);
    mint::set_mod(m);
    combination<mint, (int)1e7> solver;
    while (t--) {
        int n, r;
        read(n, r);
        if (n < r) {
            put(0);
        } else {
            put(solver.binom(n, r).val());
        }
    }
}