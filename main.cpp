#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include"template.hpp"
#include"math/gcd.hpp"
#include"math/dynamic_modint.hpp"
#include"math/DLP.hpp"
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        uint32_t x,y,p;
        scanf("%d%d%d", &x, &y, &p);
        printf("%lld\n", dlp32(x, y, p));
    }
}  