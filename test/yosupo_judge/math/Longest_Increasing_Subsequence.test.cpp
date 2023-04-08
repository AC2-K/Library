#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include<iostream>
#include<algorithm>
#include<numeric>
#include"../../../src/data-structure/segtree.hpp"
using S = std::pair<int,int>;
S op(S x, S y) { return max(x,y); }
S e() { return S{0,0}; }

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
        std::sort(tmp.begin(),tmp.end());
        tmp.erase(std::unique(tmp.begin(),tmp.end()), tmp.end());
        for (auto& aa : a) {
            aa = lower_bound(tmp.begin(),tmp.end(), aa) - tmp.begin();
        }
    }
    vector<int> prv(n, -1);
    std::iota(prv.begin(),prv.end(), 0);
    kyopro::segtree<S, op, e> dp(n + 1);
    for(int i=0;i<n;i++) {
        auto [mx, p] = dp.prod(0, a[i]);
        if (mx + 1 >= dp[a[i]].first) {
            prv[i] = p;
            dp.update(a[i], S{mx + 1, i});
        }
    }
    auto [res, cur] = dp.prod(0, n + 1);
    std::vector<int> idx;
    idx.reserve((size_t)res);
    for(int i=0;i<res;i++) {
        idx.emplace_back(cur);
        cur = prv[cur];
    }
    printf("%d\n", (int)idx.size());
    std::reverse(idx.begin(),idx.end());
    for (auto& i : idx) {
        printf("%d ", i);
    }
}