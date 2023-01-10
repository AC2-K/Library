#include"template.hpp"

/// @brief modint構造体
/// @tparam mod  
/// @brief modint構造体
	/// @tparam mod  
	template<const ll mod>
	class modint {
	private:

	using mint = modint<mod>;
	ll value = 0;

	ll mod_inv(ll a, ll m) {
		a %= m;
		ll b = m, u = 1, v = 0;
		while (b>0) {
			ll t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		u %= m;
		if (u < 0) u += m;
		return u;
	}
	ll mod_pow(ll base, ll exp, ll M) {
		ll ans = 1;
		base %= M;
		while (exp > 0) {
			if (exp & 1) {
				ans *= base;
				ans %= M;
			}
			base *= base;
			base %= M;
			exp >>= 1;
		}
		return ans;
	}
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
	mint operator/(mint a) {
		return mint(a.inv() * value);
	}
	void operator/=(mint a) {
		value = value * a.inv();
		value %= mod;
	}
		mint inv() {
		return mod_inv(val, mod);
	}
	mint pow(ll exp) {
		return mod_pow(value, exp, mod);
	}
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
