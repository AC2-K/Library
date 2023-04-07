#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include"template.hpp"
#include"math/primitive_root.hpp"
using namespace std;
int main(){
    int q;
    scanf("%d", &q);
    while (q--) {
        ll p;
        scanf("%lld", &p);
        ll ans = primitive_root(p);
        printf("%lld\n", ans);
    }
}
