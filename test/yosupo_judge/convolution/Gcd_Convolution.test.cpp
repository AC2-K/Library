#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../../../src/math/divisor-multiple-transform.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"
#include"../../../src/math/static_modint.hpp"
int main() {
    int n;
    kyopro::readint(n);

    std::vector<kyopro::static_modint32<998244353>> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) kyopro::readint(a[i]);
    for (int i = 1; i <= n; ++i) kyopro::readint(b[i]);

    kyopro::fast_zeta(a),kyopro::fast_zeta(b);
    for (int i = 1; i <= n; ++i) a[i] *= b[i];
    kyopro::fast_mobius(a);
    for (int i = 1; i <= n; ++i) kyopro::putint(a[i].val());
}