#pragma once
#include"math/large_mod.hpp"
using ull = uint_fast64_t;


namespace for_hash {
	constexpr ull mapping_max = (ull)'Z';
	ull base = -1;	//baseをランダムにとる
	constexpr ull mod = (1uL << 61) - 1;
	constexpr ull primitive_root = 37;
	ull strong_rand() {
		mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<ull> rand(1uL, mod - 1);
		return rand(engine);
	}
	void generate_base() {
        if(base != -1) return;
		ull r = mod - 1;
		while (gcd(r, mod - 1) != 1 || r <= mapping_max) {
			r = strong_rand();
		}
		base = large_modpow(primitive_root, r, mod);
	}
};

class RollingHash {
	using i128 = __int128_t;	//変えましょうね~
	static constexpr ull msk30 = (1ul << 30) - 1;
	static constexpr ull msk61 = (1ul << 31) - 1;
	string str;
	vector<ull> hash, pow;


	ull mul(i128 a, i128 b)const {
		i128 t = a * b;

		t = (t >> 61) + (t & for_hash::mod);

		if (t >= for_hash::mod) {
			t -= for_hash::mod;
		}


		return t;
	}

	ull mapping(const char& c) {
		return (ull)c;	//変更する?
	}
public:
	RollingHash() :str() {	}

	RollingHash(const string& str) :str(str) {
		for_hash::generate_base();
		build();
	}

	void build() {
		hash.resize(str.size() + 1);
		pow.resize(str.size() + 1, 1);

		for (int i = 0; i < str.size(); i++) {
			hash[i + 1] = mul(hash[i], for_hash::base) + mapping(str[i]);
			pow[i + 1] = mul(pow[i], for_hash::base);
			if (hash[i + 1] >= for_hash::mod) {
				hash[i + 1] -= for_hash::mod;
			}
		}
	}
	ull range(int l, int r) const {
		ull res = for_hash::mod + hash[r] - mul(hash[l], pow[r - l]);
		return res < for_hash::mod ? res : res - for_hash::mod;
	}
	ull get_all(){
		return hash.back();
	}
	int size(){return str.size();}
};

///@brief rolling hash