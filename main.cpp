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
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
//離散対数
//x^n=y mod (mod)なる最小の非負整数
ll DLP(ll x,ll y,const ll&mod){
    //memo
    /*
    x^n=yなるnを愚直に求めると、O(mod)かかる。
    BSGSを使ってO(\sqrt mod)まで落とす.
    定数Qをsq=sqrt(mod)と定める。この時、n=Qi+jなるi,j(i\leq Q,j<Q)が存在する
        x^(Qi+j)=y
    <=> x^j=y*X^(Qi) (X=xの逆元)
    左辺は列挙可能.iを全探索して、対応するjが存在すればnは復元できる。したがってO(Q)で解ける
    */
    x%=mod;
    y%=mod;
    auto mod_pow=[&](ll base, ll exp)-> ll {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = res * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return res;
    };

    auto mod_inv=[&](ll v)-> ll {return mod_pow(v,mod-2);};
    //OK
    ll ok=mod;
    ll ng=0;
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(mid*mid>=mod)ok=mid;
        else ng=mid;
    }
    ll sqrt_mod=ok;
    return sqrt_mod;


    map<ll,ll> mp;    //mp[s]=s=x^jなる最小のjを復元する(j<sqrt_mod)
    ll cur=1;
    for(int i=0;i<sqrt_mod;i++){
        if(mp.find(cur)==mp.end())mp[cur]=i;    //もし何も入ってなかったら突っ込む
        cur*=x;
        cur%=mod;
    }

    ll X=mod_pow(mod_inv(x),sqrt_mod);
    ll val=y;
    for(int i=0;i<sqrt_mod;i++){
        if(mp.find(val)!=mp.end()){
            ll j=mp[val];
            return sqrt_mod*i+j;
        }
        val*=X;
    }
    return -1;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        ll x,y,p;
        cin>>x>>y>>p;
        cout<<DLP(x,y,p)<<'\n';
    }
}