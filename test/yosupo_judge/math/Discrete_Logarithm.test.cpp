#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include<iostream>
#include"../../../math/mod_log.hpp"

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y, p;
        scanf("%d%d%d", &x, &y, &p);
        printf("%lld\n", kyopro::mod_log<long long>(x, y, p));
    }
}