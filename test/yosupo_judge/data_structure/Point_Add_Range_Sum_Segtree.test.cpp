#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"template.hpp"
#include"../../../data-structure/segtree.hpp"

long long op(long long x, long long y) { return x + y; }
long long e() { return 0; }
int main() {
    int n, q;
    scanf("%d%d",&n,&q);
    std::vector<long long> a(n);
    for (auto& aa : a) {
        scanf("%lld",&aa);
    }

    kyopro::segtree<long long, op, e> seg(a);
    while (q--) {
        int t;
        scanf("%d",&t);
        if (!t) {
            int p, x;
            scanf("%d%d",&p,&x);
            seg.apply(p, x);
        }
        else {
            int l, r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",seg.prod(l, r));
        }
    }
}