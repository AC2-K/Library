#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include<iostream>
#include"../../../math/gcd.hpp"

using namespace std;
int main(){
    long long a, b;
    cin >> a >> b;
    long long x, y;
    kyopro::ext_gcd(a, b, x, y);
    std::cout << x << ' ' << y << '\n';
}