#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include<iostream>
#include"../../../math/primitive_root.hpp"
int main(){
    int q;
    scanf("%d", &q);
    while (q--) {
        long long p;
        scanf("%lld", &p);
        long long ans = kyopro::primitive_root(p);
        printf("%lld\n", ans);
    }
}
