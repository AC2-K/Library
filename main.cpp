#line 1 "main.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"

#line 1 "template.hpp"
#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
//using i128=__int128_t;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = 1e-6;
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
#line 1 "math/fast_prime_check.hpp"
class MillerRabin {
    using i128 = __int128_t;
    const vector<ll> bases = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };    //intだと、2,7,61で十分
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
public:
    bool is_prime(ll n) {
        if (n < 2) {
            return false;
        }
        ll d = n - 1;
        ll q = 0;
        while ((d & 1) == 0) {
            d >>= 1;
            q++;
        }

        for (const auto&a : bases) {
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
#line 3 "math/fast_fact.hpp"
class Rho{
    using i128=__int128_t;
    mt19937 mt;
    MillerRabin mr;
    long long c;
    ll f(i128 x,ll n){
        x%=n;
        return (x*x%n+c)%n;
    }
public:
    Rho(){
        mt.seed(clock());
    }
private:
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
            return -1;
        }
        return d;
    }


    vector<ll> rho_fact(const ll&n){
        if(n<2){
            return {};
        }
        if(mr.is_prime(n)){
            return{n};
        }
        ll d=-1;
        while(d==-1){
            d=find_factor(n);
        }
        vector<ll> v1=fact(d);
        vector<ll> v2=fact(n/d);
        v1.insert(v1.end(),v2.begin(),v2.end());
        return v1;
    }
    vector<ll> naive_fact(ll n){
        vector<ll> ret;
        for (ll div = 2; div * div <= n; div++) {
            if (n % div != 0)continue;
            ll exp = 0;
            while (n % div == 0) {
                ret.push_back(div);
                n /= div;
            }
        }
        if (n != 1)ret.push_back(n);
        return ret;
    }

public:
    vector<ll> fact(const ll n){
        vector<ll> res;
        if(n<=1000){
            res=naive_fact(n);
        }else{
            res=rho_fact(n);
        }
        sort(all(res));
        return res;
    }
};
#line 3 "math/phi_function.hpp"
ll phi_func(ll n){
    ll res=n;
    Rho rho;
    auto pf=rho.fact(n);
    pf.erase(unique(all(pf)),pf.end());     
    for(auto&d:pf){
        res=res/d*(d-1);
    }
    return res;
}
#line 5 "main.cpp"
int main(){
    int n;
    cin>>n;
    cout<<phi_func(n)<<'\n';
}
