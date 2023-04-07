#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"


#include"template.hpp"
#include"math/sieve.hpp"

int main(){
    constexpr int INPUT_MAX = 100000000;
    const auto res = sieve(INPUT_MAX);

    int n;
    scanf("%d",&n);
    int ans = 0;
    while(n--){
        int p;
        scanf("%d",&p);
        if(res[p]){
            ans++;
        }
    }
    printf("%d\n",ans);
}
