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
template<
    class X, class M,
    X(*fx)(X, X), const X& ex,
    M(*fm)(M, M), const M& em,
    X(*fxm)(X, M)
>
class lazy_segtree {
    int sz;
    vector<X> dat;
    vector<M> lz;
    void Init(int n) {
        dat.assign(4 * n, ex);
        lz.assign(4 * n, em);
        int x = 1;
        while (n > x) {
            x <<= 1;
        }
        sz = x;
    }
public:
    lazy_segtree(int n) {
        lazy_segtree(n, vector<X>(n, ex));
    }
    lazy_segtree(int n, const vector<X>& a) {
        Init(n);
        for (int i = 0; i < n; i++) {
            set(i, a[i]);
        }
        build();
    }
public:
    void set(int pos, X x) {
        assert(0 <= pos && pos < sz);
        dat[pos + sz - 1] = x;
    }
    void build() {
        for (int i = sz - 2; i >= 0; i--) {
            dat[i] = fx(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

private:
    void eval(int pos) {
        if (lz[pos] == em) return;
        if (pos < sz - 1) {
            lz[2 * pos + 1] = fm(lz[2 * pos + 1], lz[pos]);
            lz[2 * pos + 2] = fm(lz[2 * pos + 2], lz[pos]);
        }
        dat[pos] = fxm(dat[pos], lz[pos]);
        lz[pos] = em;
    }

private:
    void update(int L, int R, int l, int r, M x, int k) {
        eval(k);
        if (L <= l && r <= R) {
            lz[k] = fm(lz[k], x);
            eval(k);
        }
        else if (L < r && l < R) {
            int mid = (l + r) >> 1;
            update(L, R, l, mid, x, 2 * k + 1);
            update(L, R, mid, r, x, 2 * k + 2);
            dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
public:
    void update(int l, int r, M x) {
        assert(0 <= l && l <= r && r <= sz);
        update(l, r, 0, sz, x, 0);
    }

private:
    X prod(int L, int R, int l, int r, int k) {
        eval(k);
        if (r <= L || R <= l) {
            return ex;
        }
        else if (L <= l && r <= R) {
            return dat[k];
        }
        else {
            int mid = (l + r) >> 1;
            X vl = prod(L, R, l, mid, 2 * k + 1);
            X vr = prod(L, R, mid, r, 2 * k + 2);
            return fx(vl, vr);
        }
    }

public:
    X prod(int l, int r) {
        assert(0 <= l && l <= r && r <= sz);
        return prod(l, r, 0, sz, 0);
    }

    X operator[](int pos) {
        return prod(pos,pos+1);
    }
};
//@brief 遅延評価セグメント木
//X:datのほうのモノイド,M:作用素の集合
//fx:X × X -> X 
//fm:M × M -> M
//fxm:X × M -> X
using X = int;
using M = int;
constexpr int e=(1ll<<31)-1;
constexpr X ex = e;
constexpr M em = e;
X fx(X x, X y) { return x; }
M fm(M x,M y) { return y; }
X fmx(X x, M y) { return y; }
int main() {
    int n,q;
    cin>>n>>q;
    lazy_segtree<X,M,fx,ex,fm,em,fmx> seg(n,vector<int>(n,e));
    while(q--){
        int t;
        cin>>t;
        if(t==0){
            int l,r;
            cin>>l>>r;
            int new_val;
            cin>>new_val;
            seg.update(l,r+1,new_val);
        }else{
            int i;
            cin>>i;
            cout<<seg[i]<<'\n';
        }
        cout<<"[";
        rep(i,n)cout<<seg[i]<<',';
        cout<<"]\n";
    }
}