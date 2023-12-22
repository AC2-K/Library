#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../../../src/math/divisor-multiple-transform.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;
int main() {
    int n;
    read(n);

    vector<modint<998244353>> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) read(a[i]);
    for (int i = 1; i <= n; ++i) read(b[i]);

    fast_zeta(a), fast_zeta(b);
    for (int i = 1; i <= n; ++i) a[i] *= b[i];
    fast_mobius(a);
    for (int i = 1; i <= n; ++i) put(a[i].val());
}