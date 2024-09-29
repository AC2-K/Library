#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"

#include "../../../src/math/mod_pow.hpp"
#include "../../../src/stream.hpp"
int main() {
    int n, m;
    kyopro::read(n, m);
    kyopro::put(kyopro::mod_pow(n, m, (int)1e9 + 7));
}