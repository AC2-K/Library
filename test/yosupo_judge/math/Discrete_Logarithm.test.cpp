#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include"template.hpp"
#include"math/DLP.hpp"
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y, p;
        scanf("%d%d%d", &x, &y, &p);
        printf("%lld\n", dlp(x, y, p));
    }
}