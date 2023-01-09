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
//ミラーラビン法
class MillerRabin {
    //底
    using ll = long long;
    using i128 = __int128_t;
    const vector<ll> bases = { 2 , 7 , 61 };
    i128 mod_pow(i128 base, i128 exp, ll mod) {
        i128 ans = 1;
        base %= mod;
        while (exp) {
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

    //CHECK!!!
public:
    bool is_prime(ll n) {
        if (n < 2) {
            return false;
        }
        //2^q*d==n-1となるように分解する
        ll d = n - 1;
        ll q = 0;
        while ((d & 1) == 0) {
            d >>= 1;
            q++;
        }

        for (ll a : bases) {
            if (a == n) {
                return true;
            }

            if (mod_pow(a, d, n) != 1) {
                bool flag = true;
                for (ll r = 0; r < q; r++) {
                    ll pow = mod_pow(a, d * (1ll << r), n);
                    if (pow == n - 1) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    return false;
                }
            }
        }
        return true;
    }
};
//ポラード・ロー
class Rho{
    //using ll=long long:
    using i128=__int128_t;
    mt19937 mt; //メルセンヌツイスタ~
    MillerRabin MR;
    long long c;
    ll f(i128 x,ll n){
        x%=n;
        return (x*x%n+c)%n;
    }
public:
    Rho(){
        mt.seed(clock());
    }

    ll find_factor(ll n){
        if(n==4){
            return 2;
        }
        c=mt()%n;
        ll x=mt()%n;
        ll y=x;
        ll d=1;

        while(d==1){
            x=f(x,n);
            y=f(f(y,n),n);
            d=__gcd(abs(x-y),n);
        }

        if(d==n){
            return -1;  //失敗!!!
        }
        return d;   //見つかってる
    }


    vector<ll> fact(const ll n,bool sorting=true){
        if(n<2){
            return {};
        }
        if(MR.is_prime(n)){
            return{n};
        }
        ll res=-1;
        while(res==-1){
            res=find_factor(n);
        }
        vector<ll> V1=fact(res,false);
        vector<ll> V2=fact(n/res,false);
        V1.insert(V1.end(),V2.begin(),V2.end());
        if(sorting)sort(V1.begin(),V1.end());
        return V1;
    }
};
int main(){
    Rho rho;

    int n;
    cin>>n;
    rep(i,n){
        ll ai;
        cin>>ai;

        auto res=rho.fact(ai);
        for(auto r:res){
            cout<<r<<' ';
        }
        cout<<endl;
    }
}