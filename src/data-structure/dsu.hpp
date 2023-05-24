#pragma once
#include <utility>
#include <vector>
namespace kyopro {

/**
 * @brief Disjoint Set(Union Find)
 */
class dsu {
private:
    std::vector<int> find;

public:
    dsu(int n) : find(n, -1) {}

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
        if (find[x] > find[y]) std::swap(x, y);
        find[x] += find[y];
        find[y] = x;
        return x;
    }
    int size(int x) { return -find[root(x)]; }
};

};  // namespace kyopro

/**
 * @docs docs/data-structure/dsu.md
 */