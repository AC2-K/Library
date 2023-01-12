#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
class RollingHash {
    static const ll mod = 1e9 + 7;
    const ll base;
    vector<ll> powers;	//base^i
    static inline ll generate_base() {
        mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<ll> rand((ll)1, (ll)mod - 1);
        return rand(engine);
    }
    //idの振り方
    ll id(char c) {
        return (c - 'a');
    }
    void expand(int siz) {
        if (powers.size() < siz + 1) {
            int pre_siz = powers.size();
            powers.resize(siz + 1);
            for (int i = pre_siz; i <= siz; i++) {
                powers[i] = (powers[i - 1] * base) % mod;
            }
        }
    }

public:
    RollingHash(ll base = generate_base()) :base(generate_base()), powers{ 1 } {	} 
    vector<ll> build(string& s) {
        vector<ll> hash(s.size() + 1);
        for (int i = 0; i < s.size(); i++) {
            hash[i + 1] = (hash[i] * base % mod + mapping(s[i])) % mod;
        }
        return hash;
    }
    ll range(vector<ll>&hash,int l, int r) {
        expand(r - l);
        return ((hash[r] + mod - hash[l] * powers[r - l]) % mod + mod) % mod;
    }
};
int main() {

}