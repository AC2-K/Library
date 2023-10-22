#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../../../src/data-structure/hash_map.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int q;
    read(q);
    hash_map<__uint64_t, __uint64_t> mp;
    while (q--) {
        int t;
        read(t);
        if (!t) {
            __uint64_t k, v;
            read(k, v);
            mp[k] = v;
        } else {
            __uint64_t k;
            read(k);
            put(mp[k]);
        }
    }
}
