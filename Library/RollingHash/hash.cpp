class rollingHash {
    ll mod = 998244353;
    ll base = 32;
    string s;
    vector<ll> hash;
    ll mod_pow(ll base, ll exp)
    {
        if (exp == 0)
            return 1;
        if (exp == 1)
            return base % mod;
        ll half = mod_pow(base, exp / 2);
        ll ret = (half * half) % mod;
        if (exp % 2 == 1)ret = ret * base % mod;
        return ret;
    }
    int id(char c) { return c - 'a' + 1; }
public:
    rollingHash(string _s, ll _mod = 998244353, ll _base = 100) :s(_s), mod(_mod), base(_base), hash(_s.size() + 1) {    }

    void build() {
        hash[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            hash[i + 1] = (hash[i] * base % mod + id(s[i]) % mod) % mod;
        }
    }

    ll rangeHash(int l, int r) {    //S[l:r](l,r:1-index) のハッシュを求める
        return (hash[r] - mod_pow(base, r - l + 1) * hash[l - 1] % mod + mod) % mod;    //hash[l,r]=hash[r]-base^(r-l+1)*hash[l-1]
    }

    bool same(int l, int r, int L, int R) {     //一致判定
        bool check = (rangeHash(l, r) == rangeHash(L, R));
        return check;
    }
};