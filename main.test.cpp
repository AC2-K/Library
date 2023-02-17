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
class LCA {
    using graph = vector<vector<int>>;
    int n;
    graph g;
    vector<int> vs, in;

    template<class T>
    class SparseTable {
        vector<vector<T>> table;
        vector<int> look_up;
    public:
        SparseTable(const vector<T>& vec = {}) {
            int sz = vec.size();
            int log = 0;
            while ((1 << log) <= sz) {
                log++;
            }
            table.assign(log, vector<T>(1 << log));
            for (int i = 0; i < sz; i++) {
                table[0][i] = vec[i];
            }
            for (int i = 1; i < log; i++) {
                for (int j = 0; j + (1 << i) <= (1 << log); j++) {
                    table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
                }
            }
            look_up.resize(sz + 1);
            for (int i = 2; i < look_up.size(); i++) {
                look_up[i] = look_up[i >> 1] + 1;
            }
        }

        T prod(int l, int r) {
            int b = look_up[r - l];
            return min(table[b][l], table[b][r - (1 << b)]);
        }
    };
    SparseTable<pair<int,int>> seg;
public:
    LCA(int n) :g(n), n(n),in(n) { }
    void add_edge(int u,int v){
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    void build(int root) {
        int p = 0;
        vector<pair<int,int>> vec(2 * n);
        function<void(int, int, int)> dfs = [&](int v, int par, int now_depth) -> void {
            in[v] = p;
            vec[p++]={now_depth,v};
            for (const auto& ch : g[v])if (ch != par) {
                dfs(ch, v, now_depth + 1);
                vec[p++] = { now_depth,v };
            }
        };
        dfs(root, -1, 0);
        seg = SparseTable<pair<int, int>>(vec);
    }

    int query(int u, int v) {
        if (in[u] >= in[v])swap(u, v);
        return seg.prod(in[u], in[v] + 1).second;
    }
};
class EulerTour {
    using graph = vector<vector<int>>;

    graph g;
public:
    vector<int> in, out, depth,tour;
    EulerTour(int n) :g(n), depth(n), in(n), out(n) {}
    void add_edge(int a, int b) {
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    void build(int root){
        depth[root] = 0;
        function<void(int, int)> dfs = [&](int v, int par = -1)-> void {
            in[v] = tour.size();
            tour.emplace_back(v);
            for (const auto& c : g[v])if (c != par) {
                depth[c] = depth[v] + 1;
                dfs(c, v);
                tour.emplace_back(v);
            }
            out[v] = tour.size() - 1;
        };
        dfs(root, -1);
    }
};

template<class S, S(*op)(S, S), S(*e)()>
class segtree {
    int n;
    vector<S> dat;
    void Init(int n_) {
        int x = 1;
        while (n_ > x) {
            x <<= 1;
        }
        n = x;
    }
public:
    segtree(int n_) : segtree(vector<S>(n_, e())) {   }
    segtree(const vector<S>& v) :dat(4 * v.size()) {
        Init(v.size());
        for (int i = 0; i < v.size(); i++) {
            set(i, v[i]);
        }
        build();
    }
    inline void set(int pos, S val) {
        assert(0 <= pos && pos < n);
        dat[pos + n - 1] = val;
    }
    void build() {
        for (int k = n - 2; k >= 0; k--) {
            dat[k] = op(dat[(k << 1) + 1], dat[(k << 1) + 2]);
        }
    }

    void update(int pos, S val) {
        assert(0 <= pos && pos < n);
        pos += n - 1;
        dat[pos] = val;
        while (pos > 0) {
            pos = (pos - 1) >> 1;
            dat[pos] = op(dat[(pos << 1) + 1], dat[(pos << 1) + 2]);
        }
    }
    inline S prod(int a, int b) {
        assert(0 <= a && b <= n);
        assert(a <= b);
        if (a == 0 && b == n)return dat[0];
        return prod(a, b, 0, 0, n);
    }

private:
    S prod(int a, int b, int id, int l, int r) {
        if (r <= a || b <= l) {
            return e();
        }
        else if (a <= l && r <= b) {
            return dat[id];
        }
        else {
            int mid = (l + r) >> 1;
            S vl = prod(a, b, (id << 1) + 1, l, mid);
            S vr = prod(a, b, (id << 1) + 2, mid, r);
            return op(vl, vr);
        }
    }

public:
    //a[pos] <- a[pos]・x
    void add(int pos, S x) {
        update(pos, op(dat[n + pos - 1], x));
    }

    S operator [](int pos) {
        return dat[n + pos - 1];
    }
};
using S = ll;
S op(S x, S y) { return x+y; }
S e() { return y; }
int main() {
    int n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(auto&aa:a){
        cin>>aa;
    }
    LCA lca(n);
    EulerTour et(n);
    rep(i,n-1){
        int u,v;
        cin>>u>>v;
        lca.add_edge(u,v);
        et.add_edge(u,v);
    }

    lca.build(0),et.build(0);    

    segtree<S,op,e> seg(et.tour.size());
    rep(v,n){
        seg.set(et.in[v],a[v]);
        seg.set(et.out[v],-a[v]);
    }
}