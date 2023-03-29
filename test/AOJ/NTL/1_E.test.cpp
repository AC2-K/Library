#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include"template.hpp"
#include"math/gcd.hpp"

int main(){
    ll a, b;
    cin >> a >> b;
    ll x, y;
    ext_gcd(a, b, x, y);
    cout << x << ' ' << y << '\n';
}