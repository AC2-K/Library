/// @brief Disjoint Set(Union find)
/// @docs docs/data-structure/dsu.md
#pragma once
class DSU {
private:
    vector<int> find, rank;
public:
    DSU(int n) : find(n, -1), rank(n, 1) {}

    int root(int x) {
        if (find[x] < 0) {
            return x;
        }
        else {
            return find[x] = root(find[x]);
        }
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++; 
        find[x] += find[y];
        find[y] = x;
        return true;
    }

    int size(int x) {
        return -find[root(x)];
    }

    inline int group_size() {
        int c = 0;
        for (int v = 0; v < find.size(); v++) {
            if (find[v] < 0) {
                c++;
            }
        }
        return c;
    }
};