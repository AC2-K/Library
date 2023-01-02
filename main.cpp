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
const int INF = 1e9;
const ll INFL = 1e18;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
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
//X:メインのノード,Y:遅延評価ノード
template<class X,class Y>class lazy_segtree{
    int n;
    vector<X> dat;
    vector<Y> lazy;    //評価
    using fxy=function<X(X,Y)>;
    using fx=function<X(X,X)>;
    using fy=function<Y(Y,Y)>;
    fy op_Y;    //eval_node上の演算子
    fxy op_XY;     //貰うときのやつ
    fx op_X;  //引き戻してくる
public:
    lazy_segtree(int n_,fx FX,fy FY,fxy FXY):n(n_),op_X(FX),op_Y(FY),op_XY(FXY){
        int siz=n_;
        int pow=1;
        while(n<siz)pow*=2;
        dat.resize(2*pow-1);
        lazy.resize(2*pos-1);
    }
};
int main() {
}