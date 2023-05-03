#include<iostream>
#include"../../src/math/miller.hpp"
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        long long x;
        scanf("%lld", &x);
        printf("%lld %c\n", x, kyopro::miller::is_prime(x) ? '1' : '0');
    }
}