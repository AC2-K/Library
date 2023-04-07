#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include"template.hpp"
#include"math/mod_log.hpp"

using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y, p;
        scanf("%d%d%d", &x, &y, &p);
        printf("%lld\n", mod_log<long long>(x, y, p));
    }
}