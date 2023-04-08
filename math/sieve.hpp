#pragma once
#include <vector>
namespace kyopro {
/// @brief エラトステネスの篩
std::vector<bool> sieve(int N) {
    std::vector<bool> primes(N + 1, true);

    primes[0] = false;
    primes[1] = false;

    for (int p = 2; p <= N; ++p) {
        if (!primes[p]) continue;
        for (int i = p * 2; i <= N; i += p) {
            primes[i] = false;
        }
    }

    return primes;
}
};  // namespace kyopro