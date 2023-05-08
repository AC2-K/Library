#define PROBLEM "https://yukicoder.me/problems/no/3030"
#include<iostream>
#include"../../src/math/miller.hpp"
#include"../../src/stream.hpp"
int main(){
    int n;
    kyopro::readint(n);
    for (int i = 0; i < n; ++i){
        long long x;
        kyopro::readint(x);
        puts(kyopro::miller::is_prime(x) ? "1" : "0");
    }
}