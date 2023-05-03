#pragma once
#include <cassert>
#include <iostream>
#include "../math/gcd.hpp"
namespace kyopro {
template <__uint64_t mod> class static_modint {
private:
    using mint = static_modint<mod>;
    using i64 = long long;
    using u64 = unsigned long long;
    using u128 = __uint128_t;
    using i128 = __int128_t;

    u64 v;
    constexpr inline u64 normalize(i64 v_) const {
        v_ %= mod;
        if (v_ < 0) {
            v_ += mod;
        }
        return v_;
    }

public:
    constexpr static_modint() : v(0) {}
    constexpr static_modint(i64 v_) : v(normalize(v_)) {}

    // operator
    constexpr u64 val() const { return v; }
    constexpr mint& operator+=(const mint& rhs) {
        v += rhs.val();
        if (v >= mod) {
            v -= mod;
        }
        return (*this);
    }
    constexpr mint& operator-=(const mint& rhs) {
        v += mod - rhs.val();
        if (v >= mod) {
            v -= mod;
        }
        return (*this);
    }
    constexpr mint& operator*=(const mint& rhs) {
        v = (u128)v * rhs.val() % mod;
        return (*this);
    }

    constexpr mint operator+(const mint& r) const { return mint(*this) += r; }
    constexpr mint operator-(const mint& r) const { return mint(*this) -= r; }
    constexpr mint operator*(const mint& r) const { return mint(*this) *= r; }

    constexpr mint& operator+=(const i64& rhs) {
        (*this) += mint(rhs);
        return (*this);
    }
    constexpr mint& operator-=(const i64& rhs) {
        (*this) -= mint(rhs);
        return (*this);
    }
    constexpr mint& operator*=(const i64& rhs) {
        (*this) *= mint(rhs);
        return (*this);
    }
    constexpr friend mint operator+(const i64& l, const mint& r) {
        return mint(l) += r;
    }
    constexpr friend mint operator-(const i64& l, const mint& r) {
        return mint(l) -= r;
    }
    constexpr friend mint operator*(const i64& l, const mint& r) {
        return mint(l) *= r;
    }

    constexpr mint operator+(i64 r) { return mint(*this) += r; }
    constexpr mint operator-(i64 r) { return mint(*this) -= r; }
    constexpr mint operator*(i64 r) { return mint(*this) *= r; }

    constexpr mint& operator=(i64 r) { return (*this) = mint(r); }

    constexpr bool operator==(const mint& r) const {
        return (*this).val() == r.val();
    }

    template <typename T> constexpr mint pow(T e) const {
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
    constexpr inline mint inv() const {
        long long x, y;
        auto d = ext_gcd((long long)mod, (long long)v, x, y);
        assert(d == 1);
        return mint(y);
    }

    constexpr mint& operator/=(const mint& r) { return (*this) *= r.inv(); }
    constexpr mint inv(const mint& r) const { return mint(*this) *= r.inv(); }
    constexpr friend mint operator/(const mint& l, i64 r) {
        return mint(l) /= mint(r);
    }
    constexpr friend mint operator/(i64 l, const mint& r) {
        return mint(l) /= mint(r);
    }

    // iostream
    constexpr friend std::ostream& operator<<(std::ostream& os,
                                              const mint& mt) {
        os << mt.val();
        return os;
    }
    constexpr friend std::istream& operator>>(std::istream& is, mint& mt) {
        i64 v_;
        is >> v_;
        mt = v_;
        return is;
    }
};
template <__uint32_t mod> class static_modint32 {
private:
    using mint = static_modint32<mod>;
    using i32 = __int32_t;
    using u32 = __uint32_t;
    using i64 = __int64_t;
    using u64 = __uint64_t;

    u32 v;
    constexpr inline u32 normalize(i64 v_) const {
        v_ %= mod;
        if (v_ < 0) {
            v_ += mod;
        }
        return v_;
    }
    
public:
    constexpr static_modint32() : v(0) {}
    constexpr static_modint32(const i64& v_) : v(normalize(v_)) {}

    // operator
    static mint raw(u32 a){
        mint m;
        m.v = a;
        return m;
    }
    constexpr u32 val() const { return v; }
    constexpr mint& operator+=(const mint& rhs) {
        v += rhs.val();
        if (v >= mod) {
            v -= mod;
        }
        return (*this);
    }
    constexpr mint& operator-=(const mint& rhs) {
        v += mod - rhs.val();
        if (v >= mod) {
            v -= mod;
        }
        return (*this);
    }
    constexpr mint& operator*=(const mint& rhs) {
        v = (u64)v * rhs.val() % mod;
        return (*this);
    }

    constexpr mint operator+(const mint& r) const { return mint(*this) += r; }
    constexpr mint operator-(const mint& r) const { return mint(*this) -= r; }
    constexpr mint operator*(const mint& r) const { return mint(*this) *= r; }

    constexpr mint& operator+=(const i64& rhs) {
        (*this) += mint(rhs);
        return (*this);
    }
    constexpr mint& operator-=(const i64& rhs) {
        (*this) -= mint(rhs);
        return (*this);
    }
    constexpr mint& operator*=(const i64& rhs) {
        (*this) *= mint(rhs);
        return (*this);
    }
    constexpr friend mint operator+(const i64& l, const mint& r) {
        return mint(l) += r;
    }
    constexpr friend mint operator-(i64 l, const mint& r) {
        return mint(l) -= r;
    }
    constexpr friend mint operator*(i64 l, const mint& r) {
        return mint(l) *= r;
    }

    constexpr mint operator+(i64 r) { return mint(*this) += r; }
    constexpr mint operator-(i64 r) { return mint(*this) -= r; }
    constexpr mint operator*(i64 r) { return mint(*this) *= r; }

    constexpr mint& operator=(i64 r) { return (*this) = mint(r); }

    constexpr bool operator==(const mint& r) const {
        return (*this).val() == r.val();
    }
    template <typename T> constexpr mint pow(T e) const {
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

    constexpr inline mint inv() const {
        long long x, y;
        auto d = ext_gcd((long long)mod, (long long)v, x, y);
        assert(d == 1);
        return mint(y);
    }

    constexpr mint& operator/=(const mint& r) { return (*this) *= r.inv(); }
    constexpr mint operator/(const mint& r) const {
        return mint(*this) *= r.inv();
    }
    constexpr friend mint operator/(const mint& l, i64 r) {
        return mint(l) /= mint(r);
    }
    constexpr friend mint operator/(i64 l, const mint& r) {
        return mint(l) /= mint(r);
    }

    // iostream
    constexpr friend std::ostream& operator<<(std::ostream& os,
                                              const mint& mt) {
        os << mt.val();
        return os;
    }
    constexpr friend std::istream& operator>>(std::istream& is, mint& mt) {
        i64 v_;
        is >> v_;
        mt = v_;
        return is;
    }
};
};  // namespace kyopro

/// @brief static modint(静的modint)
/// @docs docs/math/static_modint.md