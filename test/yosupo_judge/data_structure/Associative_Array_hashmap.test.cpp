#include"template.hpp"
#include"data-structure/hash_map.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
using namespace std;
int main() {
    uint32_t q;
    scanf("%d", &q);
    hash_map<__uint64_t, __uint64_t> mp;
    while (q--) {
        int t;
        scanf("%d",&t);
        if(!t){
            __uint64_t k, v;
            scanf("%lld%lld", &k, &v);
            mp[k] = v;
        }else{
            __uint64_t k;
            scanf("%lld", &k);
            printf("%lld\n", mp[k]);
        }
    }
}
