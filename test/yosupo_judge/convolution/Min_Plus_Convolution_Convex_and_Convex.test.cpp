#define PROBLEM \
    "https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex"

#include "../../../src/convolution/min_plus_convolution_convex_convex.hpp"
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
    vector c = min_plus_convolution_convex_convex(a, b);
    rep(i, n + m - 1) put(c[i]);
}