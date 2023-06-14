#include <bitset>
#include <cassert>
#include <vector>
namespace kyopro {

/**
 * @brief エラトステネスの篩
 */
class eratosthenes_sieve {
    std::vector<int> mpf;  // minimum prime factor

    std::vector<int> mobius;

public:
    eratosthenes_sieve(int n) : mpf(n + 1, -1), mobius(n + 1, 1) {
        for (int i = 2; i <= n; ++i) {
            if (!is_prime(i)) continue;
            mpf[i] = i;

            mobius[i] = -1;
            if ((long long)i * i > n) continue;
            for (int j = i * 2; j <= n; j += i) {
                if (mpf[j] == -1) mpf[j] = i;

                if (j / i % i == 0) {
                    mobius[i] = 0;
                } else {
                    mobius[j] = -mobius[j];
                }
            }
        }
    }

    bool is_prime(int p) const { return mpf[p] == p; }

    std::vector<int> enumerate_primes() const {
        std::vector<int> res;
        for (int i = 2; i < (int)mpf.size(); ++i) {
            if (is_prime(i)) res.emplace_back(i);
        }
        return res;
    }

    std::vector<int> enumerate_mobius() const { return mobius; }
    
    std::vector<int> factorize(int a) const {
        assert(1 <= a && a < (int)mpf.size());
        if (a <= 1) return {};
        std::vector<int> res;
        while (a > 1) {
            res.emplace_back(mpf[a]), a /= mpf[a];
        }
        return res;
    }

    std::vector<std::pair<int, int>> exp_factorize(int n) {
        std::vector<int> pf = factorize(n);

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

    std::vector<int> enumerate_divisor(int n) {
        std::vector<std::pair<int,int>> pf = exp_factorize(n);
        std::vector<int> divisor{1};
        for (auto [p, e] : pf) {
            int pow = p;
            int sz = divisor.size();
            for (int i = 0; i < e; ++i) {
                for (int j = 0; j < sz; ++j)
                    divisor.emplace_back(divisor[j] * pow);
                pow *= p;
            }
        }

        return divisor;
    }
};

};  // namespace kyopro


