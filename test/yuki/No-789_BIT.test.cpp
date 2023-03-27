#define PROBLEM "https://yukicoder.me/problems/no/789"

#include"template.hpp"
#include"data-structure/BIT.hpp"
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll s = 0;
    vector<int> idx;
    idx.reserve(2 * n);
    vector<tuple<int, int, int>> query(n);
    for (auto& [t, a, b] : query) {
        cin >> t >> a >> b;
        idx.emplace_back(a);
        if (t == 1) idx.emplace_back(b);
    }
    sort(all(idx));
    idx.erase(unique(all(idx)), idx.end());
    BIT<ll> sg(2 * n + 1);
    for (auto& [t, a, b] : query) {
        if (t == 0) {
            a = lower_bound(all(idx), a) - idx.begin();
            sg.add(a, b);
        } else {
            a = lower_bound(all(idx), a) - idx.begin();
            b = lower_bound(all(idx), b) - idx.begin();
            s += sg.sum(a, b + 1);
        }
    }
    cout << s << '\n';
}
