#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../../../src/math/matrix.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

using mint = modint<998244353>;

int main() {
    int n;
    ll k;
    read(n, k);
    Matrix<mint> A(n, n);
    rep(i, n) rep(j, n) read(A[i][j]);
    A = A.pow(k);
    rep(i, n) rep(j, n) put(A[i][j]);
}