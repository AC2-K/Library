#include<iostream>
#include<vector>
#include<functional>
#include<cassert>
using namespace std;
using graph = vector<vector<int>>;
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
    LCA(const graph& g) :g(g), n(g.size()),in(n) { }
    void setup() {
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
        dfs(0, -1, 0);
        seg = SparseTable<pair<int, int>>(vec);
    }

    int query(int u, int v) {
        if (in[u] >= in[v])swap(u, v);
        return seg.prod(in[u], in[v] + 1).second;
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].emplace_back(i);
        g[i].emplace_back(p);
    }
    LCA lca(g);
    lca.setup();
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << '\n';
    }
}