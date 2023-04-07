#define PROBLEM "https://yukicoder.me/problems/no/430"
#include"template.hpp"
#include"string/rolling_hash.hpp"

using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
int main(){
    string s;
    int m;
    cin >> s >> m;
    RollingHash S(s);
    map<uint64_t, int> hash_count;
    rep(i, s.size()) {
        for (int length = 1; length <= 10 && i + length <= s.size(); length++) {
            int j = i + length;
            hash_count[S.range(i, j)]++;
        }
    }
    long long ans = 0;

    for (int i = 0; i < m; i++) {
        string c;
        cin >> c;
        ans += hash_count[RollingHash(c).get_all()];
    }
    cout << ans << '\n';
}