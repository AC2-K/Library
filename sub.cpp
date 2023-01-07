#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;

template<class X>class SegmentTree {
    using fx = function<X(X, X)>;
    int n;
    fx op;
    const X ex;
    vector<X> dat;

    X query(int a, int b, int id, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        }
        else if (a <= l && r <= b) {
            return dat[id];
        }
        else {
            X left = query(a, b, id * 2 + 1, l, (l + r) / 2);
            X right = query(a, b, id * 2 + 2, (l + r) / 2, r);
            return op(left, right);
        }
    }
public:
    SegmentTree(int n_, fx fx_, X ex_) : n(), op(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void set(int pos, X x) { 
        dat[pos + n - 1] = x;
    }
    void build() {
        for (int i = n - 2; i >= 0; i--) dat[i] = op(dat[2 * i + 1], dat[2 * i + 2]);
    }

    void update(int pos, X val) {
        pos += n - 1;
        dat[pos] = val;
        while (pos > 0) {
            pos = (pos - 1) / 2;
            dat[pos] = op(dat[pos * 2 + 1], dat[pos * 2 + 2]);
        }
    }
    void add(int pos,X val){
        update(pos,get(pos)+val);
    }

    X query(int a, int b) { 
        //if(a==0&&b==n)return dat[0];
        return query(a, b, 0, 0, n); 
    }

    X get(int pos){return dat[pos+n-1];}
};
int main() {
    ll n,d,a;
    cin>>n>>d>>a;
    vector<P> X(n);
    rep(i,n){
        cin>>X[i].first>>X[i].second;
    }
    //ソート
    sort(all(X));
    vector<int> x,h;
    rep(i,n){
        x.push_back(X[i].first);
        h.push_back(X[i].second);
    }
    //Sの差分
    //範囲外参照しないように、ちょっと多めにとる
    SegmentTree<ll> S_sub(n+10,[](ll a,ll b){return a+b;},0);   
    ll ans=0;
    rep(i,n){
        ll Si=S_sub.query(0,i+1);   //S_iを計算する
        h[i]-=Si;
        if(h[i]<0)h[i]=0;
        int cnt=(h[i]+a-1)/a;
        ans+=cnt;
        //二分探索で最大のjを求める
        int ok=i;
        int ng=n+1;
        while(ok+1!=ng){
            int mid=(ok+ng)/2;
            if(x[mid]<=2*d+x[i])ok=mid;
            else ng=mid;
        }
        int j=ok;
        S_sub.add(i,a*cnt);
        S_sub.add(j+1,-a*cnt);
    }
    cout<<ans<<endl;
}