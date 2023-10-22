#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../../../src/data-structure/SWAG.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"
using mint = kyopro::modint<MOD2>;
using Affine = std::pair<mint, mint>;
constexpr inline Affine op(const Affine& g, const Affine& f) {
    auto a = f.first, b = f.second;
    auto c = g.first, d = g.second;
    return Affine(a * c, a * d + b);
}
constexpr inline Affine e() { return Affine(1, 0); }
int main() {
    kyopro::SWAG<Affine, op, e> que;
    int q;
    kyopro::read(q);
    while (q--) {
        int t;
        kyopro::read(t);

        if (t == 0) {
            mint a, b;
            kyopro::read(a, b);
            que.push(Affine(a, b));
        } else if (t == 1) {
            que.pop_front();
        } else {
            mint x;
            kyopro::read(x);
            Affine res = que.fold();
            kyopro::put((res.first * x + res.second).val());
        }
    }
}