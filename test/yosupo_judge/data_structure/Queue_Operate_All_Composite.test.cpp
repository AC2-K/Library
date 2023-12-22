#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../../../src/data-structure/SWAG.hpp"
#include "../../../src/math/static_modint.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

using mint = modint<MOD2>;
using Affine = pair<mint, mint>;

int main() {
    SWAG que([](Affine g,Affine f) {
        auto a = f.first, b = f.second;
        auto c = g.first, d = g.second;
        return Affine(a * c, a * d + b);
    }, Affine(1, 0));
    int q;
    read(q);
    while (q--) {
        int t;
        read(t);

        if (t == 0) {
            mint a, b;
            read(a, b);
            que.push(Affine(a, b));
        } else if (t == 1) {
            que.pop_front();
        } else {
            mint x;
            read(x);
            Affine res = que.fold();
            put((res.first * x + res.second).val());
        }
    }
}