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
#line 2 "main.cpp"
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
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n), l(q), r(q), cnt(n), ans(q);
    int count = 0, now_l = 0, now_r = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        c[i]--;
    }
    Mo mo(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        mo.add(l, r);
    }
    auto add = [&](int x) {
        if (cnt[c[x]] == 0) count++;
        cnt[c[x]]++;
    };
    auto del = [&](int x) {
        cnt[c[x]]--;
        if (cnt[c[x]] == 0) count--;
    };
    auto out = [&](int x) { ans[x] = count; };
    mo.build(add, del, out);

    rep(i, q) {
        printf("%d\n", ans[i]);
    }
}
