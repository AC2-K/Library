#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"
#include "../../../src/data-structure-2d/cumulative-sum.hpp"
#include "../../../src/stream.hpp"
int main() {
    constexpr int h = 1000;
    constexpr int w = 1000;

    int n;
    kyopro::readint(n);
    kyopro::imos_2d<int> c(h, w);
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        kyopro::readint(x1, y1, x2, y2);

        c.add(x1, y1, x2, y2, 1);
    }
    c.build();
    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            ans = std::max(ans, c.at(i, j));
        }
    kyopro::putint(ans);
}