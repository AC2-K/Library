#define PROBLEM "https://yukicoder.me/problems/no/3030"
#include <iostream>
#include "../../src/math/miller.hpp"
#include "../../src/stream.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n;
    read(n);
    for (int i = 0; i < n; ++i) {
        long long x;
        read(x);
        write(x, kyopro::miller::is_prime(x) ? '1' : '0');
        write('\n');
    }
}