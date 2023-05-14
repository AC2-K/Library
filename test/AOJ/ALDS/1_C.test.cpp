#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"
#include "../../../src/math/sieve.hpp"
#include "../../../src/stream.hpp"
int main() {
    constexpr int INPUT_MAX = 100000000;
    kyopro::sieve<INPUT_MAX> solver;

    int n;
    kyopro::readint(n);
    int ans = 0;
    while (n--) {
        int p;
        kyopro::readint(p);
        if (solver.is_prime(p)) {
            ans++;
        }
    }
    kyopro::putint(ans);
}
