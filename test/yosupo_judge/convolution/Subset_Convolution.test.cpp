#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"
#include "../../../src/convolution/subset_convolution.hpp"

using namespace std;
using namespace kyopro;

using mint = modint<998244353>;

int main() {
    int n;
    read(n);
    vector<mint> a(1 << n), b(1 << n);
    rep(i, (int)a.size()) read(a[i]);
    rep(i, (int)b.size()) read(b[i]);

    vector c = subset_convolution(n, a, b);

    rep(i, (int)c.size()) put(c[i]);
}