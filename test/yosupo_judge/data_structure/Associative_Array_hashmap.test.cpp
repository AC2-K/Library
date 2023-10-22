#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../../../src/data-structure/hash_map.hpp"
#include "../../../src/stream.hpp"
int main() {
    uint32_t q;
    kyopro::read(q);
    kyopro::hash_map<__uint64_t, __uint64_t> mp;
    while (q--) {
        int t;
        kyopro::read(t);
        if (!t) {
            __uint64_t k, v;
            kyopro::read(k, v);
            mp[k] = v;
        } else {
            __uint64_t k;
            kyopro::read(k);
            kyopro::put(mp[k]);
        }
    }
}
