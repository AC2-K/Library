#include"template.hpp"
class MillerRabin {
	//底
	using ll = long long;
	using i128 = __int128_t;
	const vector<ll> bases = { 2 , 7 , 61 };
	unordered_map<ll, bool> memo;
	i128 mod_pow(i128 base, i128 exp, ll mod) {
		i128 ans = 1;
		base %= mod;
		while (exp) {
			if (exp & 1) {
				ans *= base;
				ans %= mod;
			}
			base *= base;
			base %= mod;
			exp >>= 1;
		}
		return ans;
	}

	//CHECK!!!
public:
	bool is_prime(ll n) {
		if (memo.find(n) != memo.end())return memo[n];
		if (n < 2) {
			return false;
		}
		//2^q*d==n-1となるように分解する
		ll d = n - 1;
		ll q = 0;
		while ((d & 1) == 0) {
			d >>= 1;
			q++;
		}

		for (ll a : bases) {
			if (a == n) {
				return memo[n] = true;
			}

			if (mod_pow(a, d, n) != 1) {
				bool flag = true;
				for (ll r = 0; r < q; r++) {
					ll pow = mod_pow(a, d * (1ll << r), n);
					if (pow == n - 1) {
						flag = false;
						break;
					}
				}

				if (flag) {
					return memo[n] = false;
				}
			}
		}
		return memo[n] = true;
	}
};