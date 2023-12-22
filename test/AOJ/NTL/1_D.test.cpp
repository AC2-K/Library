#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"
#include "../../../src/math/phi_function.hpp"
#include "../../../src/stream.hpp"

using namespace kyopro;

int main() {
    int n;
    read(n);
    put(phi_func(n));
}