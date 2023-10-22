#define PROBLEM "https://yukicoder.me/problems/no/430"
#include <iostream>
#include "../../src/data-structure/hash_map.hpp"
#include "../../src/stream.hpp"
#include "../../src/string/rolling_hash.hpp"

using namespace std;
using namespace kyopro;

int main() {
    string s;
    int m;
    read(s, m);
    RollingHash S(s);
    hash_map<uint64_t, int> hash_count;
    for (int i = 0; i < (int)s.size(); i++) {
        for (int length = 1; length <= 10 && i + length <= (int)s.size();
             length++) {
            int j = i + length;
            ++hash_count[S.hash(i, j)];
        }
    }
    long long ans = 0;

    for (int i = 0; i < m; ++i) {
        string c;
        read(c);
        ans += hash_count[kyopro::RollingHash(c).get_all()];
    }
    put(ans);
}
