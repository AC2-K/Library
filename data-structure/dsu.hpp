#pragma once
#include <vector>

/// @brief Disjoint Set(Union find)
class DSU {
  private:
    std::vector<int> find, rank;

  public:
    DSU(int n) : find(n, -1), rank(n, 1) {}

    int root(int x) {
        if (find[x] < 0) {
            return x;
        } else {
            return find[x] = root(find[x]);
        }
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return x;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++; 
        find[x] += find[y];
        find[y] = x;
        return x;
    }
    int size(int x) { return -find[root(x)]; }
};

/// @docs docs/data-structure/dsu.md