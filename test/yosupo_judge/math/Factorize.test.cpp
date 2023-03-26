#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include"template.hpp"
#include"math/rho.hpp"
int main(){
    int q;
    cin >> q;
    while (q--){
        __uint64_t x;
        cin >> x;
        const auto pf = prime::rho::factorize(x);
        printf("%d ", (int)pf.size());
        for (auto &p : pf){
            printf("%lld ", p);
        }
        puts("\n");
    }
}