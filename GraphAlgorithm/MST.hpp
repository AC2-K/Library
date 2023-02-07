class MST{
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
    }dsu;
    struct Edge
    {
        int v1,v2;
        int cost;
        int id;
        Edge(int v1,int v2,int cost,int id):v1(v1),v2(v2),cost(cost),id(id){  }
    };
    vector<Edge> E;
    vector<int> V1,V2;
public:
    MST(int V):dsu(V){}
    void add_edge(int a,int b,ll cost){
        int sz=E.size();
        E.emplace_back(a,b,cost,sz);
        V1.emplace_back(a),V2.emplace_back(b);
    }
    ll result() {
        sort(E.begin(), E.end(),[&](Edge e1,Edge e2){
            return e1.cost<e2.cost;
        });
        ll ans = 0;
        rep(i, E.size()) {
            int len = E[i].cost;
            int id = E[i].id;
            int a = V1[id], b = V2[id];
            if (dsu.same(a, b))continue;
            dsu.merge(a, b);
            ans += len;
        }
        return ans;
    }
};