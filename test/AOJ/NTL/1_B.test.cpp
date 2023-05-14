#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"

#include "../../../src/stream.hpp"
#include "../../../src/math/mod_pow.hpp"
int main() {
    int n, m;
    kyopro::readint(n,m);
    kyopro::putint(kyopro::mod_pow<int>(n, m, (int)1e9+7));
}