vector<pair<ll, ll>> prime_factarization(ll n) {
    vector<pair<ll, ll>> ret;
    for (ll div = 2; div * div <= n; div++) {
        if (n % div != 0)continue;
        ll exp = 0;
        while (n % div == 0) {
            exp++;
            n /= div;
        }
        ret.push_back(make_pair(div, exp));
    }
    if (n != 1)ret.push_back(make_pair(n, 1));
    return ret;
}
