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
//const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}

ll modlog(ll x, ll y,const int&MOD) {
    if(x==0){
        if(y==0)return 0;
        else return -1;
    }
    ll H = sqrt(MOD) + 1;
    static pair<ll, ll> baby[100010];
    for (ll b = 0, xby = y; b < H; b++, xby = (xby * x) % MOD) {
        baby[b] = std::make_pair(xby, b);
    }
    sort(baby, baby + H);
    ll xH = 1;
    for (int i = 0; i < H; ++i) {
        xH = (xH * x) % MOD;
    }
    for (ll a = 1, xaH = xH; a <= H; a++, xaH = (xaH * xH) % MOD) {
        auto it = std::lower_bound(baby, baby + H, std::make_pair(xaH + 1, 0LL));
        if (it == baby) continue;
        it--;
        if (it->first == xaH) return a * H - it->second;
    }
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        ll x,y,p;
        cin>>x>>y>>p;
        x%=p;
        y%=p;
        cout<<modlog(x,y,p)<<endl;
    }
}
