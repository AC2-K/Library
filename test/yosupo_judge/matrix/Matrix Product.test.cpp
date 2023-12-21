#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include <iostream>
#include "../../../src/math/matrix.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
#pragma GCC optimize("unroll-loops")

using namespace std;
using namespace kyopro;

using mint = modint<998244353>;
int main() {
    int n, m, k;
    read(n, m, k);
    Matrix<mint> a(n, m), b(m, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            read(a[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            read(b[i][j]);
        }
    }
    auto res = a * b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            put(res[i][j].val());
        }
    }
}
