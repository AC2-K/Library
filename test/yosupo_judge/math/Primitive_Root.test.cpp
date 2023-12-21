#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "../../../src/math/primitive_root.hpp"
#include <iostream>
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int q;
    read(q);
    while (q--) {
        long long p;
        read(p);
        put(primitive_root(p));
    }
}
