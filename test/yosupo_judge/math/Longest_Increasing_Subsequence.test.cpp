#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include"template.hpp"
#include"data-structure/segtree.hpp"
using S = P;
S op(S x, S y) { return max(x,y); }
S e() { return P(0,0); }

using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (auto& aa : a) {
        scanf("%d", &aa);
    }
    {
        vector<int> tmp = a;
        sort(all(tmp));
        tmp.erase(unique(all(tmp)), tmp.end());
        for (auto& aa : a) {
            aa = lower_bound(all(tmp), aa) - tmp.begin();
        }
    }
    vector<int> prv(n, -1);
    iota(all(prv), 0);
    segtree<S, op, e> dp(n + 1);
    rep(i, n) {
        auto [mx, p] = dp.prod(0, a[i]);
        if (mx + 1 >= dp[a[i]].first) {
            prv[i] = p;
            dp.update(a[i], P(mx + 1, i));
        }
    }
    auto [res, cur] = dp.prod(0, n + 1);
    vector<int> idx;
    idx.reserve((size_t)res);
    rep(i, res) {
        idx.emplace_back(cur);
        cur = prv[cur];
    }
    printf("%lld\n", idx.size());
    reverse(all(idx));
    for (auto& i : idx) {
        printf("%d ", i);
    }
}