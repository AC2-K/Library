#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"

#include "../../../src/math/mod_pow.hpp"
#include "../../../src/stream.hpp"
using namespace kyopro;

int main() {
    int n, m;
    read(n, m);
    put(mod_pow<int>(n, m, (int)1e9 + 7));
}