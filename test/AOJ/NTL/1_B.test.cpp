#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"

#include <iostream>
#include "../../../src/math/mod_pow.hpp"
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", kyopro::mod_pow<long long>(n, m, (int)1e9+7));
}