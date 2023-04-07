#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "template.hpp"
#include "data-structure/dsu.hpp"
using namespace std;
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    DSU dsu(n);
    while (q--) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (t == 0) {
            dsu.merge(x, y);
        }
        else {
            if (dsu.same(x, y))puts("1");
            else puts("0");
        }
    }
}