template<class S> bsgs(S s, S g, ll n, ll m, const function<S(S)>& f, const function<S(S)>& fm) {
    if(s == g){
        return 0;
    }
    map<S, ll> mp;
    for (int j = 1; j <= m; j++) {
        g = f(g);
        mp[g] = j;
    }
    for (int i = 1;; i++) {
        s = fm(s);

        if (mp.find(s) != mp.end()) {
            return m * i - mp[s];
        }

        if (n <= m * i)break;
    }
    return -1;
}
