#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"
#include<iostream>
#include"../../../src/math/phi_function.hpp"
int main(){
    int n;
    scanf("%d",&n);
    printf("%lld\n",kyopro::phi_func(n));
}