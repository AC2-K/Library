#include"template.hpp"
#include"data-structure/BIT.hpp"
#include"misc/mo.hpp"
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    Mo mo(q);
    vector<int> a(n);
    for (auto& aa : a) {
        scanf("%d", &aa);
    }
    vector<int> k(q);
    for(int i=0;i<q;i++) {
        int l, r;
        scanf("%d%d%d", &l, &r, &k[i]);
        k[i]++;
        mo.add(l, r);
    }
    vector<int> pressed = a;
    auto tmp = a;
    {
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()), tmp.end());
        for (auto& ai : pressed) {
            ai = lower_bound(tmp.begin(),tmp.end(), ai) - tmp.begin();
        }
    }

    int sz = tmp.size();
    BIT<int> st(sz);
    auto add = [&](int x) -> void { st.add(pressed[x], 1); };
    auto del = [&](int x) -> void { st.add(pressed[x], -1); };
    vector<int> ans(q);
    auto out = [&](int x) -> void {
        int ok = st.lower_bound(k[x]);
        ans[x] = tmp[ok - 1];
    };

    mo.build(add, del, out);
    for (auto& as : ans) {
        printf("%d\n", as);
    }
}
