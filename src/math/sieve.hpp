#include <bitset>
#include <vector>
namespace kyopro {

/**
 * @brief エラトステネスの篩
 * @tparam ALLOC 確保しておくサイズ
 */
template <int ALLOC> class sieve {
    std::bitset<ALLOC + 1> isp;
    std::vector<int> prime_v;

public:
    constexpr sieve() : sieve(ALLOC) {}
    constexpr sieve(int n) {
        isp.flip();
        isp[0] = isp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            if (!isp[i]) continue;
            prime_v.emplace_back(i);
            if ((long long)i * i > n) continue;
            for (int j = i * 2; j <= n; j += i) {
                isp[j] = 0;
            }
        }
    }
    const std::vector<int>& primes() const { return prime_v; }
    constexpr int num_of_primes() const { return prime_v.size(); }
    constexpr int kth_prime(int i) const { return prime_v[i]; }
    constexpr bool is_prime(int p) { return isp[p]; }
};

};  // namespace kyopro