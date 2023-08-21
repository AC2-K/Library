#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include <iostream>
#include "../../../src/math/mod_log.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int t;
    read(t);
    while (t--) {
        int x, y, p;
        read(x, y, p);
        put(mod_log(x, y, p));
    }
}