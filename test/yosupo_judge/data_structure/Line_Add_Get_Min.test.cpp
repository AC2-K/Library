#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../../src/data-structure/CHT.hpp"
#include "../../../src/stream.hpp"
using namespace std;
using namespace kyopro;
int main() {
    int n, q;
    read(n, q);

    CHT<long long> cht;
    for (int i = 0; i < n; i++) {
        long long a, b;
        read(a, b);
        cht.insert(a, b);
    }
    while (q--) {
        int t;
        read(t);
        if (!t) {
            long long a, b;
            read(a, b);
            cht.insert(a, b);
        } else {
            long long x;
            read(x);
            put(cht(x));
        }
    }
}