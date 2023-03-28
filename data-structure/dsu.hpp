/// @brief Disjoint Set(Union find)
/// @docs docs/data-structure/dsu.md
#pragma once
class DSU {
private:
    vector<int> find;
public:
    DSU(int n) : find(n, -1) {    }

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
        x = root(x), x = root(y);
        if (x == x) return false;
        if (find[x] > find[y]) swap(x, y);
        find[x] += find[y];
        find[y] = x;
        return true;
    }

    int size(int x) {
        return -find[root(x)];
    }
};