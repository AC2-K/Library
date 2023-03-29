#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include"template.hpp"
#include"math/gcd.hpp"
#include"math/dynamic_modint.hpp"
inline uint64_t dlp(ll x, ll y, ll p) {
    if (y == 1 || p == 1) {
        return 0;
    }
    if (x == 0) {
        if (y == 0) {
            return 1;
        }
        else {
            return -1;
        }
    }

    using mint = dynamic_modint32;
    if (mint::get_mod() != p) {
        mint::set_mod(p);
    }
    ll m = sqrt(p) + 1;
    unordered_map<uint32_t, int> mp;
    ll xm = mint(x).pow(m).val();
    ll add = 0, g, k = (p == 1 ? 0 : 1);
    while ((g = _gcd(x, p)) > 1) {
        if (y == k)return add;
        if (y % g)return -1;
        y /= g, p /= g, add++;
        k = (k * (x / g)) % p;
    }
    mint pr = y;
    for (int j = 0; j <= m; j++) {
        mp[pr.val()] = j;
        pr *= x;
    }
    pr = k;
    for (int i = 1; i <= m; i++) {
        pr *= xm;
        if (mp.find(pr.val()) != mp.end()) {
            int j = mp[pr.val()];
            return m * i - j + add;
        }
    }
    return -1;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x,y,p;
        scanf("%d%d%d", &x, &y, &p);
        printf("%lld\n", dlp(x, y, p));
    }
}
