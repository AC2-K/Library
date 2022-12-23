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
	//getter
	ll val() {
		return value;
	}
	/*演算子*/
	mint operator+(mint fp) {
		return mint(value + fp.val());
	}
	mint operator-(mint fp) {
		return mint(value - fp.val());
	}
	mint operator*(mint fp) {
		return mint(value * fp.val());
	}

	/*代入+演算*/
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
	/*比較演算子*/
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

	/*inv*/
	ll inv() {
		return mod_pow(mod - 2);
	}
	ll mod_pow(ll exp) {
		if (exp < 0)exp += (mod - 1);
		if (exp == 0)return 1;
		if (exp == 1)return value;
		ll ret = mod_pow(exp / 2);
		return ret * ret % mod * mod_pow(exp % 2)%mod;
	}
	mint operator/(mint a) {
		return mint(value * a.inv());
	}
	void operator/=(mint a) {
		value = value * a.inv();
		value%=mod;
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
	return os << mt.val()%T;
}
