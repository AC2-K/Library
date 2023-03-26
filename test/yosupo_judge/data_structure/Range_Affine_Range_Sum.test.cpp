#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include"template.hpp"
#include"data-structure/lazy_segtree.hpp"
#include"math/static_modint.hpp"
using mint = static_modint32<MOD2>;
struct S {
    mint s;
    int len;
};
S op(S a, S b) { return S{a.s + b.s, a.len + b.len}; }
S e() { return S{0, 0}; }
using Affine = pair<mint, mint>;
Affine composition(Affine g, Affine f) {
	//f(g)
	//a(cx+d)+b
	auto a = f.first, b = f.second;
	auto c = g.first, d = g.second;
	return Affine(a * c, a * d + b);
}
Affine id() { return Affine(1, 0); }
S mapping(S d, Affine f) {
    mint a = f.first, b = f.second;
    d.s *= a, d.s += b * d.len;
    return d;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    lazy_segtree<S, Affine, op, e, composition, id, mapping> sg(n);
    rep(i,n){
        mint a;
        cin >> a;
        sg.set(i, {a, 1});
    }
    sg.build();
    while(q--){
        int t;
        cin >> t;
        if (t == 0) {
            int l, r;
            mint b, c;
            cin >> l >> r >> b >> c;
            sg.apply(l, r, Affine(b, c));
        } else {
            int l, r;
            cin >> l >> r;
            auto res = sg.prod(l, r);
            cout << res.s << '\n';
        }
    }
}