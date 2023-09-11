

#include "math/static_modint.hpp"
#include "stream.hpp"
#include "template.hpp"

using namespace std;
using namespace kyopro;

using mint = atcoder::modint998244353;
int main() {
    int n, _c;
    read(n, _c);
    mint c = mint::raw(_c);
    vector<mint> poly(n);
    rep(i, n) {
        int v;
        read(v);
        poly[i] = mint::raw(v);
    }

    poly = taylor_shift<mint, 524290>(poly, c);
    rep(i, n) put(poly[i].val());
}