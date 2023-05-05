#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"
#include<iostream>
#include"../../../src/math/sieve.hpp"
int main(){
    constexpr int INPUT_MAX = 100000000;
    kyopro::sieve<INPUT_MAX> solver;

    int n;
    scanf("%d",&n);
    int ans = 0;
    while(n--){
        int p;
        scanf("%d",&p);
        if(solver.is_prime(p)){
            ans++;
        }
    }
    printf("%d\n",ans);
}
