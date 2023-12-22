#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include <algorithm>
#include <iostream>
#include <numeric>
#include "../../../src/data-structure/segtree.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

using S = pair<int, int>;
inline S op(S x, S y) { return max(x, y); }
inline S e() { return S{0, 0}; }

int main() {
    int n;
    read(n);
    vector<int> a(n);
    for (auto& aa : a) {
        read(aa);
    }
    {
        vector<int> tmp = a;
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for (auto& aa : a) {
            aa = lower_bound(tmp.begin(), tmp.end(), aa) - tmp.begin();
        }
    }
    vector<int> prv(n, -1);
    iota(prv.begin(), prv.end(), 0);
    segtree<S, op, e> dp(n + 1);
    for (int i = 0; i < n; i++) {
        auto [mx, p] = dp.fold(0, a[i]);
        if (mx + 1 >= dp[a[i]].first) {
            prv[i] = p;
            dp.update(a[i], S{mx + 1, i});
        }
    }
    auto [res, cur] = dp.fold(0, n + 1);
    vector<int> idx;
    idx.reserve((size_t)res);
    for (int i = 0; i < res; i++) {
        idx.emplace_back(cur);
        cur = prv[cur];
    }
    put(idx.size());
    reverse(idx.begin(), idx.end());
    for (auto i : idx) {
        put(i);
    }
}