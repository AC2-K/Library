#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "../../../src/math/gcd.hpp"
#include "../../../src/stream.hpp"

using namespace kyopro;

int main() {
    long long a, b;
    read(a, b);
    long long x, y;
    ext_gcd(a, b, x, y);
    write(x, y);
}