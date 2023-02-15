vector<bool> prime_checker(int N) {
    vector<bool> primes(N + 1, true);

    primes[0] = false;
    primes[1] = false;

    for (int p = 2; p <= N; ++p) {
        if (!primes[p]) continue;
        for (int i = 2; p * i <= N; i++) {
            primes[p * i] = false;
        }
    }

    return primes;
}