#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../../src/data-structure/CHT.hpp"
#include "../../../src/stream.hpp"
using namespace std;
int main() {
    int n, q;
    kyopro::readint(n, q);

    kyopro::CHT<long long> cht;
    for (int i = 0; i < n; i++) {
        long long a, b;
        kyopro::readint(a, b);
        cht.insert(a, b);
    }
    while (q--) {
        int t;
        kyopro::readint(t);
        if (!t) {
            long long a, b;
            kyopro::readint(a, b);
            cht.insert(a, b);
        } else {
            long long x;
            kyopro::readint(x);
            kyopro::putint(cht(x));
        }
    }
}