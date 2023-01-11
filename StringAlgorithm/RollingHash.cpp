#include"template.hpp"

class RollingHash {
	
	static const ll mod = 1e9 + 7;
	const ll base;
	vector<ll> powers;	//base^i
	static inline ll generate_base() {
		mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<ll> rand((ll)1, (ll)mod - 1);
		return rand(engine);
	}
	//idの振り方
	ll mapping(char c) {
		return (c - 'a');
	}
	void expand(int siz) {
		if (powers.size() < siz + 1) {
			int pre_siz = powers.size();
			powers.resize(siz + 1);
			for (int i = pre_siz; i <= siz; i++) {
				powers[i] = (powers[i - 1] * base) % mod;
			}
		}
	}

public:
	RollingHash(ll base = generate_base()) :base(generate_base()), powers{ 1 } {	} 
	vector<ll> build(string& s) {
		vector<ll> hash(s.size() + 1);
		for (int i = 0; i < s.size(); i++) {
			hash[i + 1] = (hash[i] * base % mod + mapping(s[i])) % mod;
		}
		return hash;
	}
	ll range(vector<ll>&hash,int l, int r) {
		expand(r - l);
		return ((hash.at(r) + mod - hash.at(l) * powers[r - l]) % mod + mod) % mod;
	}
};