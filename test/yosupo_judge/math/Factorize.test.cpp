#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include"template.hpp"
#include"math/rho.hpp"
int main(){
    int q;
    scanf("%d", &q);
    while (q--) {
        uint64_t x;
        scanf("%lld", &x);
        const auto pf = prime::rho::factorize(x);
        printf("%d ", (int)pf.size());
        for (auto &p : pf){
            printf("%lld ", p);
        }
        puts("");
    }
}