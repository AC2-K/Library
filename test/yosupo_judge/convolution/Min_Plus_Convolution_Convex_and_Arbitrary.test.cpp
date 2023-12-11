#define PROBLEM \
    "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"
#include "../../../src/convolution/min_plus_convolution_convex_arbitrary.hpp"
#include "../../../src/debug.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n, m;
    read(n, m);
    vector a(n, 0LL), b(m, 0LL);
    rep(i, n) read(a[i]);
    rep(i, m) read(b[i]);
    vector c = min_plus_convolution_convex_arbitrary(a, b);
    rep(i, (int)c.size()) put(c[i]);
}
