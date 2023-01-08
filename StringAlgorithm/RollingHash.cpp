#include"template.hpp"

/// @brief ローリングハッシュ

//verify:https://atcoder.jp/contests/tessoku-book/submissions/37885756

class RollingHash {
    ll mod = 998244353;
    ll base = 32;
    string s;
    vector<ll> hash;
    ll mod_pow(ll base, ll exp) {
        ll ans = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) {
                ans *= base;
                ans %= mod;
            }
            base *= base;
            base %= mod;
            exp >>= 1;
        }
        return ans;
    }
    int id(char c) { return c - 'a' + 1; }
public:
    /// @brief コンストラクタ
    /// @param _s s
    /// @param _mod mod 
    /// @param _base 基数
    RollingHash(string _s, ll _mod = 998244353, ll _base = 100) :s(_s), mod(_mod), base(_base), hash(_s.size() + 1) {    }
    /// @brief 構築
    void build() {
        hash[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            hash[i + 1] = (hash[i] * base % mod + id(s[i]) % mod) % mod;
        }
    }
    /// @brief 区間[l,r]のハッシュを求める
    /// @param l 1-index
    /// @param r 1-index
    /// @return 
    ll Range(int l, int r) {
        ////hash[l,r]=hash[r]-base^(r-l+1)*hash[l-1]
        return (hash[r] - mod_pow(base, r - l + 1) * hash[l - 1] % mod + mod) % mod;
    }
    /// @brief 区間[l,r]と区間[L,R]が一致するか調べる
    /// @param l 
    /// @param r 
    /// @param L 
    /// @param R 
    /// @return 
    bool same(int l, int r, int L, int R) {     //一致判定
        bool check = (Range(l, r) == Range(L, R));
        return check;
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    RollingHash S(s,MOD);
    S.build();
    while(q--){
        int r,l,L,R;
        cin>>l>>r>>L>>R;
        if(S.same(l,r,L,R))cout<<"Yes\n";
        else cout<<"No\n";
    }
}