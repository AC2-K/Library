#pragma once
#include <cassert>
#include <iostream>
#include "../internal/type_traits.hpp"
#include "../math/gcd.hpp"
namespace kyopro {
template <__uint32_t _mod> class modint : internal::modint_base {
private:
    using mint = modint<_mod>;
    using i32 = __int32_t;
    using u32 = __uint32_t;
    using i64 = __int64_t;
    using u64 = __uint64_t;

    u32 v;
    constexpr u32 normalize(i64 v_) const {
        v_ %= _mod;
        if (v_ < 0) {
            v_ += _mod;
        }
        return v_;
    }

public:
    static constexpr u32 mod() { return _mod; }
    constexpr modint() : v(0) {}
    constexpr modint(i64 v_) : v(normalize(v_)) {}

    static mint raw(u32 a) {
        mint m;
        m.v = a;
        return m;
    }
    constexpr u32 val() const { return v; }
    constexpr mint& operator+=(const mint& rhs) {
        v += rhs.val();
        if (v >= _mod) {
            v -= _mod;
        }
        return (*this);
    }
    constexpr mint& operator-=(const mint& rhs) {
        v += _mod - rhs.val();
        if (v >= _mod) {
            v -= _mod;
        }
        return (*this);
    }
    constexpr mint& operator*=(const mint& rhs) {
        v = (u64)v * rhs.val() % _mod;
        return (*this);
    }

    constexpr mint operator+(const mint& r) const { return mint(*this) += r; }
    constexpr mint operator-(const mint& r) const { return mint(*this) -= r; }
    constexpr mint operator*(const mint& r) const { return mint(*this) *= r; }

    constexpr mint& operator+=(i64 rhs) {
        (*this) += mint(rhs);
        return (*this);
    }
    constexpr mint& operator-=(i64 rhs) {
        (*this) -= mint(rhs);
        return (*this);
    }
    constexpr mint& operator*=(i64 rhs) {
        (*this) *= mint(rhs);
        return (*this);
    }
    constexpr friend mint operator+(i64 l, const mint& r) {
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

    constexpr mint inv() const {
        long long x, y;
        auto d = ext_gcd((long long)_mod, (long long)v, x, y);
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

    // stream
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

/**
 * @brief 静的modint
 * @docs docs/math/static_modint.md
 */