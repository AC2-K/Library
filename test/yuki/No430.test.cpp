#define PROBLEM "https://yukicoder.me/problems/no/430"
#include <iostream>
#include "../../src/data-structure/hash_map.hpp"
#include "../../src/string/rolling_hash.hpp"

int main() {
    std::string s;
    int m;
    std::cin >> s >> m;
    kyopro::RollingHash S(s);
    kyopro::hash_map<uint64_t, int> hash_count;
    for (int i = 0; i < (int)s.size(); i++) {
        for (int length = 1; length <= 10 && i + length <= (int)s.size();
             length++) {
            int j = i + length;
            ++hash_count[S.range(i, j)];
        }
    }
    long long ans = 0;

    for (int i = 0; i < m; ++i) {
        std::string c;
        std::cin >> c;
        ans += hash_count[kyopro::RollingHash(c).get_all()];
    }
    std::cout << ans << '\n';
}
