#include"template.hpp"

/// @brief modint構造体
/// @tparam mod  
template<ll mod>class modint {
private:
	using mint = modint<mod>;
	ll value = 0;
public:
	modint(ll v = 0) {
		v %= mod;
		v = (v + mod) % mod;
		value = v;
	}
	ll val() {
		return value;
	}
	mint operator+(mint fp) {
		return mint(value + fp.val());
	}
	mint operator-(mint fp) {
		return mint(value - fp.val());
	}
	mint operator*(mint fp) {
		return mint(value * fp.val());
	}
	void operator=(mint fp) {
		val = fp.val();
	}
	void operator=(ll val) {
		value = val;
	}
	void operator+=(mint fp) {
		value = ((value + fp.val() + mod) % mod + mod) % mod;
	}
	void operator-=(mint fp) {
		value = value - fp.val();
		value %= mod;
		value += mod;
		value %= mod;
	}
	void operator*=(mint fp) {
		value = value * fp.val();
		value = (value % mod + mod) % mod;
	}
	bool operator==(mint fp) {
		return value == fp.val();
	}
	bool operator<(mint fp) {
		return value < fp.val();
	}
	bool operator>(mint fp) {
		return value > fp.val();
	}
	bool operator<=(mint fp) {
		return value <= fp.val();
	}
	bool operator>=(mint fp) {
		return value >= fp.val();
	}

	mint inv() {
		return mod_pow(mod - 2);
	}
	mint mod_pow(ll exp) {
		ll base = value;
		ll ans = 1;
		base %= mod;
		while (exp > 0) {
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
	mint operator/(mint a) {
		return mint(a.inv()*value);
	}
	void operator/=(mint a) {
		value = value * a.inv();
		value %= mod;
	}
	//入出力
};
template<ll T>istream& operator>>(istream& is, modint<T>& mt) {
	ll v;
	is >> v;
	mt = v;
	return is;
}
template<ll T>ostream& operator << (ostream& os, modint<T>& mt) {
	return os << mt.val() % T;
}
