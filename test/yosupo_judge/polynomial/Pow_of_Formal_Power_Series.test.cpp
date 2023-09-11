#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"
#include "../../../src/FormalPowerSeries/FPS.hpp"

using namespace std;
using namespace kyopro;

using mint = atcoder::modint998244353;
using FPS = FormalPowerSeries<mint>;

int main() {
    int n, m;
    read(n, m);
    FPS f(n);
    rep(i, n) {
        int v;
        read(v);
        f[i] = mint::raw(v);
    }

    f = f.pow(m);
    rep(i, n) put(f[i].val());
}