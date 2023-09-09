#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"
#include "../../../src/FormalPowerSeries/FPS.hpp"

using namespace std;
using namespace kyopro;

using mint = atcoder::modint998244353;
using fps = FormalPowerSeries<mint>;

int main() {
    int n;
    read(n);
    fps f(n);
    rep(i, n) {
        int v;
        read(v);
        f[i] = mint::raw(v);
    }
    f = f.inv();
    rep(i, n) put(f[i].val());
}