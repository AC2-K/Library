#include <bitset>
#include <cassert>
#include <numeric>
#include <vector>
namespace kyopro {

/**
 * @brief エラトステネスの篩
 */

template <int n> class eratosthenes_sieve {
    std::vector<int> mpf;  // minimum prime factor

public:
    eratosthenes_sieve() : mpf(n, -1) {
        for (int i = 2; i <= n; ++i) {
            if (mpf[i] != -1) continue;
            mpf[i] = i;

            if ((long long)i * i > n) continue;
            for (int j = i * 2; j <= n; j += i) {
                if (mpf[j] == -1) mpf[j] = i;
            }
        }
    }

    bool is_prime(int p) const { return mpf[p] == -1; }

    std::vector<int> enumerate_primes() const {
        std::vector<int> res;
        for (int i = 2; i < (int)mpf.size(); ++i) {
            if (is_prime(i)) res.emplace_back(i);
        }
        return res;
    }

    std::vector<int> factorize(int a) const {
        assert(1 <= a && a < (int)mpf.size());
        if (a <= 1) return {};
        std::vector<int> res;
        while (a > 1) {
            res.emplace_back(mpf[a]), a /= mpf[a];
        }
        return res;
    }

    std::vector<std::pair<int, int>> exp_factorize(int a) const {
        std::vector<int> pf = factorize(a);

        if (pf.empty()) {
            return {};
        }

        std::vector<std::pair<int, int>> res;
        res.emplace_back(pf.front(), 1);
        for (int i = 1; i < (int)pf.size(); i++) {
            if (res.back().first == pf[i]) {
                res.back().second++;
            } else {
                res.emplace_back(pf[i], 1);
            }
        }

        return res;
    }

    std::vector<int> enumerate_divisor(int a) const {
        std::vector<std::pair<int, int>> pf = exp_factorize(a);
        std::vector<int> divisor{1};
        for (auto [p, e] : pf) {
            int pow = p;
            int sz = divisor.size();
            for (int i = 0; i < e; ++i) {
                for (int j = 0; j < sz; ++j) {
                    divisor.emplace_back(divisor[j] * pow);
                }
                pow *= p;
            }
        }

        return divisor;
    }
};

};  // namespace kyopro
