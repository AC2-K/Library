#line 2 "template.hpp"
#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using i128=__int128_t;
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
constexpr int inf = 1e9;
constexpr ll infl = 1e18;
constexpr ld eps = 1e-6;
const long double pi = acos(-1);
constexpr uint64_t MOD = 1e9 + 7;
constexpr uint64_t MOD2 = 998244353;
constexpr int dx[] = { 1,0,-1,0 };
constexpr int dy[] = { 0,1,0,-1 };
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
#line 1 "other/mo.hpp"
class Mo {
    int n;
    vector<pair<int, int>> lr;
    vector<int> ord;
public:
  explicit Mo(int n) : n(n) { lr.reserve(n); }
  void add(int l, int r) { lr.emplace_back(l, r); }

private:
    inline void line_up() {
        int q = lr.size();
        int bs = n / min<int>(n, (int)sqrt(q));
        ord.resize(q);
        iota(begin(ord), end(ord), 0);
        sort(begin(ord), end(ord), [&](int a, int b) {
            int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
            if (ablock != bblock) return ablock < bblock;
            return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
            });
    }
public:
    template< typename AL, typename AR, typename EL, typename ER, typename O >
    void build(const AL& add_left, const AR& add_right, const EL& erase_left, const ER& erase_right, const O& out) {
        line_up();
        int l = 0, r = 0;
        for (const auto& idx : ord) {
            while (l > lr[idx].first) add_left(--l);
            while (r < lr[idx].second) add_right(r++);
            while (l < lr[idx].first) erase_left(l++);
            while (r > lr[idx].second) erase_right(--r);
            out(idx);
        }
    }

    template< typename A, typename E, typename O >
    void build(const A& add, const E& erase, const O& out) {
        build(add, add, erase, erase, out);
    }
};
/// @brief mo's algorithm
/// @docs docs/other/mo.md
#line 3 "main.cpp"
#include<atcoder/all>
int op(int x,int y) { return x + y; }
int e() { return 0; }
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> a(n);
    for (auto& aa : a) {
        scanf("%d", &aa);
    }
    auto press = a;
    sort(all(press));
    press.erase(unique(all(press)), press.end());
    for(auto&aa:a){
        aa = lower_bound(all(press), aa) - press.begin();
    }
    Mo mo(q);
    vector<int> k(q);
    rep(i, q) {
        int l, r;
        scanf("%d%d%d", &l, &r, &k[i]);
        mo.add(l, r);
    }

    atcoder::segtree<int, op, e> sg(n);
    auto add = [&](int x) -> void { sg.add(a[x], 1); };
    auto del = [&](int x) -> void { sg.add(a[x], -1); };
    vector<int> ans(q);
    auto out = [&](int x) -> void {
        auto is_ok = [&](int sum) -> bool { return sum <= k[x]; };
        ans[x] = sg.max_left(0, is_ok);
    };
    mo.build(add, del, out);
    for(auto&ai:ans){
        printf("%d\n", ai);
    }
}
