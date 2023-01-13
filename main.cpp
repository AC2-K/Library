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
ll phi_func(ll n){
    ll res=n;
    for(ll d=2;d*d<=n;d++){
        if(n%d==0){
            res=res/d*(d-1);

            for(;n%d==0;n/=d){  }
        }
    }
    if(n!=1)res=res/n*(n-1);
    return res;
}

int main(){
    ll n;
    cin>>n;
    cout<<phi_func(n)<<'\n';
}