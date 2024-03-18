#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include "../../../src/FormalPowerSeries/fps-sqrt.hpp"
#include "../../../src/debug.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

using mint = atcoder::modint998244353;

int main() {
    int n;
    read(n);
    FormalPowerSeries<mint> f(n);

    rep(i, n) {
        int x;
        read(x);
        f[i] = mint::raw(x);
    }

    f = fps_sqrt<mint>(f);
    if (f.empty()) {
        put(-1);
    } else {
        rep(i, (int)f.size()) put(f[i].val());
    }
}