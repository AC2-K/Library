#pragma once

#include"math/mod_pow.hpp"
class RollingHash {
	
	static const ll mod = 998244343;
	static const ll g = 3;	//原始根
	ll base;
	vector<ll> powers;
	static inline ll generate_base() {
		mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<ll> rand((ll)1, (ll)mod - 1);
		return rand(engine);
	}
	//idの振り方
	ll mapping(char c) {
		return (c - 'a' + 1);
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
	RollingHash() :base(), powers{ 1 } {
		ll r = mod - 1;
		while(gcd(r,mod-1) != 1){
			r = generate_base();
		}

		base = mod_pow(g,r,mod);
	} 

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

///@brief rolling hash