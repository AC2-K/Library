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
#include"DataStructure/segtree.hpp"
template<class T>int LIS(vector<T> &a,bool strict=true) {
    int n=(int)a.size();
    vector<T> aval;
    for(auto aa:a)aval.push_back(aa);
    sort(all(aval));
    aval.erase(unique(all(aval)),aval.end());
	int (*op)(int x,int y)=[&](int x,int y)-> int {return max(x,y);};
	int (*e)()=[&]()->int {return 0;};
    segtree<int,op,e> dp(n);       //dp[i]=最後尾がiとなるようなLISの最大値
    int res=0;
    for(int i=0;i<n;i++){
        int h=lower_bound(all(aval),a[i])-aval.begin();
        h++;
        int upper=h;
        if(!strict)upper++;
        int A=dp.prod(0,upper);
        if(dp[h]<A+1){
            dp.update(h,A+1);
            chmax(res,A+1);
        }
    }
    return res;
}
int main(){

}