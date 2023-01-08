#include"template.hpp"

/// @brief disjoint set
class DSU {
private:
    vector<int> par, rank, siz;
    int N;
public:
    DSU(int n) : par(n, -1), rank(n, 0), siz(n, 1), N(n) {}

    int root(int x) {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return false;

        if (rank[rx] < rank[ry])
            swap(rx, ry);
        par[ry] = rx;

        siz[rx] += siz[ry];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
    int connect() {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (root(i) == i)
                cnt++;
        return cnt;
    }
};

/// @brief 最小全域木
/// @param N グラフの頂点数 
/// @param M 辺の本数
/// @param E 辺 firstに重み,secondにidを突っ込む
/// @param A 辺Eの頂点
/// @param B ;;
/// @return 最小全域木を求める
ll MST(int N, int M, vector<pair<ll,ll>> E, vector<int> A, vector<int> B) {
    if (M == 0)return 0;
    sort(E.begin(), E.end());
    DSU UF(N);
    ll ans = 0;
    rep(i, M) {
        int len = E[i].first;
        int id = E[i].second;
        int a = A[id], b = B[id];
        if (UF.same(a, b))continue;
        UF.merge(a, b);
        ans += len;
    }
    return ans;
}