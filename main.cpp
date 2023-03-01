#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include"template.hpp"
#include"math/fast_fact.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    scanf("%d",&q);

    while(q--){
        ll a;
        scanf("%lld", &a);
        auto pf = prime::fact(a);
        cout << pf.size() << ' ';
        for (auto &p : pf){
            cout << p << ' ';
        }
        cout << '\n';
    }
}