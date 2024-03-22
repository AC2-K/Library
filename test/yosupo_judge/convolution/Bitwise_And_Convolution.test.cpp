#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../../src/convolution/or_plus_convolution.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

using mint = modint<998244353>;

int main() {
    int n;
    read(n);
    vector<mint> a(1 << n), b(1 << n);
    rep(i, 1 << n) read(a[i]);
    rep(i, 1 << n) read(b[i]);
    reverse(all(a)), reverse(all(b));
    vector c = or_plus_convolution(n, a, b);
    reverse(c.begin(), c.end());
    rep(i, 1 << n) put(c[i]);
}