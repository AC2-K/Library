#line 1 "main.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include"template.hpp"
#include"math/fast_prime_check.hpp"
namespace prime{
    namespace pollard{
        using i128 = __int128_t;
        using u128 = __uint128_t;
        using u64 = __uint64_t;
        u64 c;
        u64 xor_shift() { 
            static u64 v = 7001;
            v ^= v << 13;
            v ^= v >> 7;
            v ^= v << 17;

            return v;
        }
        i128 gcd(i128 x,i128 y){
            while(y!=0){
                i128 ny = x % y;
                i128 nx = y;
                x = nx, y = ny;
            }
            return x;
        }
        u64 find_factor(u64 n){
            if (~n & 1ul) {
                return 2;
            }
            if (is_prime(n)) {
                return n;
            }
            while(1){
                auto f = [&](i128 x) -> u64 {
                    x %= n;
                    return (x * x % n + c) % n;
                };
                c = xor_shift() % n;
                ll x = xor_shift() % n;
                ll y = x;
                ll d = 1;
                while (d == 1) {
                    x = f(x);
                    y = f(f(y));

                    d = gcd(abs(x - y), n);
                }
                if (d != n) {
                    return d;
                }
            }
            exit(0);
        }

        vector<u64> rho_fact(u64 n){
            vector<u64> v;
            while (n != 1) {
                u64 d = 0;
                d = find_factor(n);
                while (n % d == 0) {
                    n /= d;
                    v.emplace_back(d);
                }
            }
            return v;
        }
        vector<u64> naive(u64&n){
            static constexpr u64 basic_prime[] = {2, 3, 5, 7, 11, 13, 17, 1000000007, 998244353};
            vector<u64> res;
            for (const auto& p : basic_prime) {
                while (n % p == 0) {
                    n /= p;
                    res.emplace_back(p);
                }
            }

            return res;
        }
        vector<u64> fact(u64 n){
            if (n < 2) {
                return {};
            }
            if (is_prime(n)) {
                return {n};
            }

            vector<u64> v = naive(n);
            if (n != 1) {
                vector<u64> res = rho_fact(n);
                v.insert(v.end(), all(res));
            }
            sort(all(v));
            return v;
        }
    };  // namespace pollard
};  // namespace prime
using prime::pollard::fact;

int main(){
    int t;
    cin >> t;
    while (t--) {
        __uint64_t x;
        cin >> x;
        auto pf = fact(x);
        cout << pf.size() << ' ';
        for (const auto& p : pf) {
            cout << p << ' ';
        }
        cout << '\n';
    }
}