#pragma once
#include"math/barrett.hpp"
class dynamic_modint32 {
	using u32 = uint32_t;
	using u64 = uint64_t;

	using i32 = int32_t;
	using i64 = int64_t;
	using br = internal::barrett;

	static br brt;
	static u32 mod;
	u32 v;	//value
public:
	static void set_mod(const u32& mod_) {
		brt = br(mod_);
		mod = mod_;
	}
private:
	u32 normalize(const i64& x) const {
		i32 m = x % mod;
		if (m < 0) {
			m += mod;
		}
		return m;
	}
public:
	dynamic_modint32() :v(0) { assert(mod); }	//modが決定済みである必要がある
	dynamic_modint32(const i64& v_) :v(normalize(v_)) { assert(mod); }	

	u32 val() const { return v; }

	using mint = dynamic_modint32;

	//operators
	mint& operator=(const i64& r) {
		v = normalize(r); 
		return (*this);
	}
	mint& operator+=(const mint& r) {
		v += r.v;
		if (v >= mod) {
			v -= mod;
		}
		return (*this);
	}
	mint& operator-=(const mint&r) {
		v += mod - r.v;
		if (v >= mod) {
			v -= mod;
		}

		return (*this);
	}
	mint& operator*=(const mint& r) {
		v = brt.mul(v, r.v);
		return (*this);
	}

	mint operator+(const mint& r) const { return mint(*this) += r; }
	mint operator-(const mint& r) const { return mint(*this) -= r; }
	mint operator*(const mint& r) const { return mint(*this) *= r; }



	mint& operator+= (const i64& r) { return (*this) += mint(r); }
	mint& operator-= (const i64& r) { return (*this) -= mint(r); }
	mint& operator*= (const i64& r) { return (*this) *= mint(r); }

	friend mint operator+(const i64& l, const mint& r) { return mint(l) += r; }
	friend mint operator+(const mint& l, const i64& r) { return mint(l) += r; }
	friend mint operator-(const i64& l, const mint& r) { return mint(l) -= r; }
	friend mint operator-(const mint& l, const i64& r) { return mint(l) -= r; }
	friend mint operator*(const i64& l, const mint& r) { return mint(l) *= r; }
	friend mint operator*(const mint& l, const i64& r) { return mint(l) += r; }


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
	mint pow(u64 e) const {
		mint res(1), base(*this);

		while (e) {
			if (e & 1) {
				res *= base;
			}
			e >>= 1;
			base *= base;
		}
		return base;
	}
	mint inv() const {
		return pow(mod - 2);
	}

	mint& operator/=(const mint& r) { return (*this) *= r.inv(); }
	mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }
	mint& operator/=(const i64& r) { return (*this) /= mint(r); }
	friend mint operator/(const mint& l, const i64& r) { return mint(l) /= r; }
	friend mint operator/(const i64& l, const mint& r) { return mint(l) /= r; }
};
typename dynamic_modint32::u32 dynamic_modint32::mod;
typename dynamic_modint32::br dynamic_modint32::brt;

///@brief dynamic modint(動的modint)
///@docs docs/math/dynamic_modint.md