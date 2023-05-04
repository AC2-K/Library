#define PROBLEM "https://yukicoder.me/problems/no/789"
#include <iostream>
#include "../../src/data-structure/dynamic_segtree.hpp"
constexpr inline int op(int x, int y) { return x + y; }
constexpr inline int e() { return 0; }
int main() {
    const size_t n = 1000000001;
    kyopro::dynamic_segtree<int, op, e> seg(n);

    int q;
    std::cin >> q;
    long long ans = 0;
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 0) {
            size_t x;
            long long y;
            std::cin >> x >> y;
            seg.apply(x, y);
        } else {
            size_t l, r;
            std::cin >> l >> r;
            ans += seg.prod(l, r + 1);
        }
    }
    std::cout << ans << '\n';
}