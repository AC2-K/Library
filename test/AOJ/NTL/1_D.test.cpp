#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"
#include "../../../src/math/phi_function.hpp"
#include "../../../src/stream.hpp"
int main() {
    int n;
    kyopro::readint(n);
    kyopro::putint(kyopro::phi_func(n));
}