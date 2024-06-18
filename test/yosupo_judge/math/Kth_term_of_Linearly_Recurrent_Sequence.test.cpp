#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../../../src/debug.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"
#include "../../../src/FormalPowerSeries/BostanMori.hpp"

using namespace std;
using namespace kyopro;

using mint = atcoder::modint998244353;

int main() {
    ll d, k;
    read(d, k);
    vector<mint> a(d), c(d + 1);
    rep(i, d) {
        unsigned x;
        read(x);
        a[i] = mint::raw(x);
    }

    c[0] = mint::raw(1);
    rep(i, d) {
        unsigned x;
        read(x);
        c[i + 1] = -mint::raw(x);
    }

    put(linear_reccurence_sequence(k, a, c).val());
}