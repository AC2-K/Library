#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank_mod_2"
#include "../../../src/math/gauss_jordan.hpp"
#include "../../../src/math/mod_pow.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n, m;
    read(n, m);

    if (n < m) {
        vector a(n, bitvec(m));
        rep(i, n) rep(j, m) {
            char x;
            read(x);
            a[i].set(j, x - '0');
        }
        put(gauss_jordan(n, m, a));
    } else {
        vector a(m, bitvec(n));
        rep(i, n) rep(j, m) {
            char x;
            read(x);
            a[j].set(i, x - '0');
        }
        put(gauss_jordan(m, n, a));
    }
}