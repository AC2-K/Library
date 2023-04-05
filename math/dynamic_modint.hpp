#pragma once
#include"math/barrett.hpp"
#include"math/montgomery.hpp"
template<int id=-1>
class barrett_modint {
	using u32 = uint32_t;
	using u64 = uint64_t;

	using i32 = int32_t;
	using i64 = int64_t;
	using br = internal::barrett;

	static br brt;
	static u32 mod;
	u32 v;	//value
public:
	static void set_mod(u32 mod_) {
		brt = br(mod_);
		mod = mod_;
	}
public:
	explicit constexpr barrett_modint() :v(0) { assert(mod); }	//modが決定済みである必要がある
	explicit constexpr barrett_modint(i64 v_) :v(brt.reduce(v_)) { assert(mod); }	

	u32 val() const { return v; }
    static u32 get_mod() { return mod; }
    using mint = barrett_modint;

	//operators
	constexpr mint& operator=(i64 r) {
		v = brt.reduce(r); 
		return (*this);
	}
	constexpr mint& operator+=(const mint& r) {
		v += r.v;
		if (v >= mod) {
			v -= mod;
		}
		return (*this);
	}
	constexpr mint& operator-=(const mint&r) {
		v += mod - r.v;
		if (v >= mod) {
			v -= mod;
		}

		return (*this);
	}
	constexpr mint& operator*=(const mint& r) {
		v = brt.mul(v, r.v);
		return (*this);
	}

	constexpr mint operator+(const mint& r) const { return mint(*this) += r; }
	constexpr mint operator-(const mint& r) const { return mint(*this) -= r; }
	constexpr mint operator*(const mint& r) const { return mint(*this) *= r; }



	constexpr mint& operator+= (i64 r) { return (*this) += mint(r); }
	constexpr mint& operator-= (i64 r) { return (*this) -= mint(r); }
	constexpr mint& operator*= (i64 r) { return (*this) *= mint(r); }

	friend mint operator+(i64 l, const mint& r) { return mint(l) += r; }
	friend mint operator+(const mint& l, i64 r) { return mint(l) += r; }
	friend mint operator-(i64 l, const mint& r) { return mint(l) -= r; }
	friend mint operator-(const mint& l, i64 r) { return mint(l) -= r; }
	friend mint operator*(i64 l, const mint& r) { return mint(l) *= r; }
	friend mint operator*(const mint& l, i64 r) { return mint(l) += r; }


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
	constexpr mint pow(u64 e) const {
		mint res(1), base(*this);

		while (e) {
			if (e & 1) {
				res *= base;
			}
			e >>= 1;
			base *= base;
		}
		return res;
	}
	constexpr mint inv() const {
		return pow(mod - 2);
	}

	mint& operator/=(const mint& r) { return (*this) *= r.inv(); }
	mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }
	mint& operator/=(i64 r) { return (*this) /= mint(r); }
	friend mint operator/(const mint& l, i64 r) { return mint(l) /= r; }
	friend mint operator/(i64 l, const mint& r) { return mint(l) /= r; }
};
template<int id>typename barrett_modint<id>::u32 barrett_modint<id>::mod;
template<int id>typename barrett_modint<id>::br barrett_modint<id>::brt;


/// @brief dynamic_modint(64bit)
/// @tparam T 型(64bit,32bitなど)
/// @tparam LargeT 積が収まってくれる型
/// @note T,LargeTのいずれもunsignedで渡す
template <typename T = uint32_t, typename LargeT = uint64_t, int id = -1>
class dynamic_modint {
        static T mod;
        static internal::MontgomeryReduction64<T, LargeT> mr;

      public:
        static void set_mod(T mod_) {
                mr.set_mod(mod_);
                mod = mod_;
        }

        static T get_mod() { return mod; }

      private:
        T v;
      public:
        dynamic_modint(T v_ = 0) {
                assert(mod);
                v = mr.generate(v_);
        }
        T val() const { return mr.reduce(v); }

        using mint = dynamic_modint<T, LargeT>;
        mint& operator+=(const mint& r) {
                v += r.v;
                if (v >= mr.get_mod()) {
                        v -= mr.get_mod();
                }

                return (*this);
        }

        mint& operator-=(const mint& r) {
                v += mr.get_mod() - r.v;
                if (v >= mr.get_mod) {
                        v -= mr.get_mod();
                }

                return (*this);
        }

        mint& operator*=(const mint& r) {
                v = mr.mult(v, r.v);
                return (*this);
        }

        mint operator+(const mint& r) { return mint(*this) += r; }
        mint operator-(const mint& r) { return mint(*this) -= r; }
        mint operator*(const mint& r) { return mint(*this) *= r; }

        mint& operator=(const T& v_) {
                (*this) = mint(v_);
                return (*this);
        }

        friend ostream& operator<<(ostream& os, const mint& mt) {
                os << mt.val();
                return os;
        }
        friend istream& operator>>(istream& is, mint& mt) {
                T v_;
                is >> v_;
                mt = v_;
                return is;
        }
        template <typename P> mint pow(P e) const {
                assert(e >= 0);
                mint res(1), base(*this);

                while (e) {
                        if (e & 1) {
                                res *= base;
                        }
                        e >>= 1;
                        base *= base;
                }
                return res;
        }
        mint inv() const { return pow(mod - 2); }

        mint& operator/=(const mint& r) { return (*this) *= r.inv(); }
        mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }
        mint& operator/=(T r) { return (*this) /= mint(r); }
        friend mint operator/(const mint& l, T r) {
                return mint(l) /= r;
        }
        friend mint operator/(T l, const mint& r) {
                return mint(l) /= r;
        }
};
template<typename T, typename LargeT,int id>T dynamic_modint<T, LargeT,id>::mod;
template<typename T,typename LargeT,int id>internal::MontgomeryReduction64<T,LargeT> dynamic_modint<T,LargeT,id>::mr;


///@brief dynamic modint(動的modint)
///@docs docs/math/dynamic_modint.md