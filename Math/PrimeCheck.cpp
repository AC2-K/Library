#include"template.hpp"
/// @brief エラトステネスの篩
/// @param N N以下の自然数に対して~
/// @return 判定結果を表にして渡す
vector<bool> prime_checker(int N) {
    vector<bool> primes(N + 1, true);

    primes[0] = false;
    primes[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        if (!primes[p]) continue;
        for (int i = 2; p * i <= N; i++) {
            primes[p * i] = false;
        }
    }

    return primes;
}