#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include<iostream>
#include"../../../src/data-structure/BIT.hpp"
#include"../../../src/algorithm/mo.hpp"
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    kyopro::Mo mo(q);
    std::vector<int> a(n);
    for (auto& aa : a) {
        scanf("%d", &aa);
    }
    std::vector<int> k(q);
    for(int i=0;i<q;i++) {
        int l, r;
        scanf("%d%d%d", &l, &r, &k[i]);
        k[i]++;
        mo.add(l, r);
    }
    std::vector<int> pressed = a;
    auto tmp = a;
    {
        std::sort(tmp.begin(), tmp.end());
        tmp.erase(std::unique(tmp.begin(),tmp.end()), tmp.end());
        for (auto& ai : pressed) {
            ai = lower_bound(tmp.begin(),tmp.end(), ai) - tmp.begin();
        }
    }

    int sz = tmp.size();
    kyopro::BIT<int> st(sz);
    auto add = [&](int x) -> void { st.add(pressed[x], 1); };
    auto del = [&](int x) -> void { st.add(pressed[x], -1); };
    std::vector<int> ans(q);
    auto out = [&](int x) -> void {
        int ok = st.lower_bound(k[x]);
        ans[x] = tmp[ok - 1];
    };

    mo.build(add, del, out);
    for (auto& as : ans) {
        printf("%d\n", as);
    }
}
