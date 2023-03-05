#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include"template.hpp"
#include"math/fast_fact.hpp"
int main(){
    int q;
    cin >> q;
    while (q--){
        __uint64_t x;
        cin >> x;
        const auto pf = fact(x);
        printf("%d ", (int)pf.size());
        for(auto&p:pf){
            printf("%lld ", p);
        }
        puts("\n");
    }
}