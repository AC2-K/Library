#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include"template.hpp"
#include"misc/mo.hpp"
int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    vector<int> a(n);
    for (auto& aa : a) {
        scanf("%d", &aa);
    }
    auto pressed = a;
    sort(pressed.begin(), pressed.end());
    pressed.erase(unique(pressed.begin(), pressed.end()), pressed.end());
    for (auto& ai : a) {
        ai = lower_bound(pressed.begin(), pressed.end(), ai) - pressed.begin();
    }
    Mo mo(q);
    vector<int> x(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d%d\n", &l, &r, &x[i]);
        mo.add(l, r);
    }

    vector<int> cnt(pressed.size() + 1);
    vector<int> ans(q);
    auto add = [&](int v) -> void {
        cnt[a[v]]++;
    };
    auto del = [&](int v) -> void {
        cnt[a[v]]--;
    };
    auto out = [&](int v) -> void {
        auto it = lower_bound(all(pressed), x[v]);
        if (it == pressed.end() || (*it) != x[v]) {
            ans[v] = 0;
        } else {
            int xi = it - pressed.begin();
            ans[v] = cnt[xi];
        }
    };
    mo.build(add, del, out);
    for (auto& aa : ans) {
        printf("%d\n", aa);
    }
}