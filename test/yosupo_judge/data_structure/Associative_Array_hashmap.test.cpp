#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../../../src/data-structure/hash_map.hpp"
#include "../../../src/stream.hpp"
int main() {
    uint32_t q;
    kyopro::readint(q);
    kyopro::hash_map<__uint64_t, __uint64_t> mp;
    while (q--) {
        int t;
        kyopro::readint(t);
        if (!t) {
            __uint64_t k, v;
            kyopro::readint(k, v);
            mp[k] = v;
        } else {
            __uint64_t k;
            kyopro::readint(k);
            kyopro::putint(mp[k]);
        }
    }
}
