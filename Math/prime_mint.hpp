template<const ll mod>class modint {
private:
	using mint = modint<mod>;
	ll value = 0;
public:
	modint(ll v = 0) {
		v %= mod;
		if(v < 0)v += mod;
		value = v;
	}
	ll val() {
		return value % mod;
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
		value = fp.val();
	}
	void operator=(ll val) {
		value = val % mod;
		if(value < 0) {
			value += mod;
		}
	}
	void operator+=(mint fp) {
		(value += fp.val()) %= mod;
		if(value < 0) {
			value += mod;
		}
	}
	void operator-=(mint fp) {
		value = value - fp.val();
		value %= mod;
		if(value < 0) {
			value += mod;
		}
	}
	void operator*=(mint fp) {
		value = value * fp.val();
		value = value % mod;
		if(value < 0) {
			value += mod;
		}
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

	ll inv() {
		return mod_pow(mod - 2);
	}
	ll mod_pow(ll exp) {
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
	static ll mod_pow(ll base,ll exp){
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
	friend istream& operator>>(istream& is, mint& mt) {
		ll v;
		is >> v;
		mt = mint(v);
		return is;
	}
	friend ostream& operator << (ostream& os, mint& mt) {
		return os << mt.val();
	}
};