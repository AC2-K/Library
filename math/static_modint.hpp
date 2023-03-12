#pragma once
template<__uint64_t mod>
class static_modint {
private:
	using mint = static_modint<mod>;
	using i64 = long long;
	using u64 = unsigned long long;
	using u128 = __uint128_t;
	using i128 = __int128_t;

	u64 v;
	u64 normalize(i64 v_) const {
		v_ %= mod;
		if (v_ < 0) {
			v_ += mod;
		}
		return v_;
	}
public:
	static_modint() :v(0) {}
	static_modint(const i64& v_) :v(normalize(v_)) { }

	//operator
	u64 val() const {
		return v;
	}
	mint& operator+=(const mint& rhs) {
		v += rhs.val();
		if (v >= mod) {
			v -= mod;
		}
		return (*this);
	}
	mint& operator-=(const mint& rhs) {
		v += mod - rhs.val();
		if (v >= mod) {
			v -= mod;
		}
		return (*this);
	}
	mint& operator*=(const mint& rhs) {
		v = (u128)v * rhs.val() % mod;
		return (*this);
	}


	mint operator+(const mint& r) const {
		return mint(*this) += r;
	}
	mint operator-(const mint& r) const {
		return mint(*this) -= r;
	}
	mint operator*(const mint& r) const {
		return mint(*this) *= r;
	}

	mint& operator+=(const i64& rhs) {
		(*this) += mint(rhs);
		return (*this);
	}
	mint& operator-=(const i64& rhs) {
		(*this) -= mint(rhs);
		return (*this);
	}
	mint& operator*=(const i64& rhs) {
		(*this) *= mint(rhs);
		return (*this);
	}
	friend mint operator+(const i64& l, const mint& r) {
		return mint(l) += r;
	}
	friend mint operator-(const i64& l, const mint& r) {
		return mint(l) -= r;
	}
	friend mint operator*(const i64& l, const mint& r) {
		return mint(l) *= r;
	}

	mint operator+(const i64& r) {
		return mint(*this) += r;
	}
	mint operator-(const i64& r) {
		return mint(*this) -= r;
	}
	mint operator*(const i64& r) {
		return mint(*this) *= r;
	}


	mint& operator=(const i64& r) {
		return (*this) = mint(r);
	}

	bool operator==(const mint& r) {
		return (*this).val() == r.val();
	}
	mint pow(u128 e) const {
		mint ans(1), base(*this);
		while (e) {
			if (e & 1) {
				ans *= base;
			}
			base *= base;
			e >>= 1;
		}
		return ans;
	}

	mint inv() const {
		return pow(mod - 2);
	}

	mint& operator/=(const mint& r) {
		return (*this) *= r.inv();
	}
	friend mint operator/(const mint& l, const i64& r) {
		return mint(l) /= mint(r);
	}

	//iostream
	friend ostream& operator<<(ostream& os, const mint& mt) {
		os << mt.val();
		return os;
	}
	friend istream& operator>>(istream& is, mint& mt) {
		i64 v_;
		is >> v_;
		mt = v_;
		return is;
	}
};
template<__uint32_t mod>
class static_modint32 {
private:
	using mint = static_modint32<mod>;
	using i32 = __int32_t;
	using u32 = __uint32_t;
	using i64 = __int64_t;
	using u64 = unsigned long long;

	u32 v;
	u32 normalize(i64 v_) const {
		v_ %= mod;
		if (v_ < 0) {
			v_ += mod;
		}
		return v_;
	}
public:
	static_modint32() :v(0) {}
	static_modint32(const i64& v_) :v(normalize(v_)) { }

	//operator
	u64 val() const {
		return (u64)v;
	}
	mint& operator+=(const mint& rhs) {
		v += rhs.val();
		if (v >= mod) {
			v -= mod;
		}
		return (*this);
	}
	mint& operator-=(const mint& rhs) {
		v += mod - rhs.val();
		if (v >= mod) {
			v -= mod;
		}
		return (*this);
	}
	mint& operator*=(const mint& rhs) {
		v = (u64)v * rhs.val() % mod;
		return (*this);
	}

	mint operator+(const mint& r) const {
		return mint(*this) += r;
	}
	mint operator-(const mint& r) const {
		return mint(*this) -= r;
	}
	mint operator*(const mint& r) const {
		return mint(*this) *= r;
	}

	mint& operator+=(const i64& rhs) {
		(*this) += mint(rhs);
		return (*this);
	}
	mint& operator-=(const i64& rhs) {
		(*this) -= mint(rhs);
		return (*this);
	}
	mint& operator*=(const i64& rhs) {
		(*this) *= mint(rhs);
		return (*this);
	}
	friend mint operator+(const i64& l, const mint& r) {
		return mint(l) += r;
	}
	friend mint operator-(const i64& l, const mint& r) {
		return mint(l) -= r;
	}
	friend mint operator*(const i64& l, const mint& r) {
		return mint(l) *= r;
	}

	mint operator+(const i64& r) {
		return mint(*this) += r;
	}
	mint operator-(const i64& r) {
		return mint(*this) -= r;
	}
	mint operator*(const i64& r) {
		return mint(*this) *= r;
	}


	mint& operator=(const i64& r) {
		return (*this) = mint(r);
	}

	bool operator==(const mint& r) {
		return (*this).val() == r.val();
	}
	mint pow(u64 e) const {
		mint ans(1), base(*this);
		while (e) {
			if (e & 1) {
				ans *= base;
			}
			base *= base;
			e >>= 1;
		}
		return ans;
	}

	mint inv() const {
		return pow(mod - 2);
	}

	mint& operator/=(const mint& r) {
		return (*this) *= r.inv();
	}
	friend mint operator/(const mint& l, const i64& r) {
		return mint(l) /= mint(r);
	}

	//iostream
	friend ostream& operator<<(ostream& os, const mint& mt) {
		os << mt.val();
		return os;
	}
	friend istream& operator>>(istream& is, mint& mt) {
		i64 v_;
		is >> v_;
		mt = v_;
		return is;
	}
};
///@brief static modint(静的modint)
