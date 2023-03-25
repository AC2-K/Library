#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"template.hpp"
#include"data-structure/BIT.hpp"
int main() {
    int n, q;
    cin >> n >> q;
    BIT<ll, ll> seg(n);
    rep(i,n){
        int a;
        scanf("%d", &a);
        seg.add(i, a);
    }

    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int p, x;
            scanf("%d%d", &p, &x);
            seg.add(p, x);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld", seg.sum(l, r));
        }
    }
}