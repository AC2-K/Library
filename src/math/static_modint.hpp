#pragma once
#include <cassert>
#include <cstdint>
#include <iostream>

#include "../internal/type_traits.hpp"
#include "../math/gcd.hpp"
namespace kyopro {
template <int _mod, std::enable_if_t<_mod >= 0>* = nullptr>
class modint : internal::modint_base {
    using mint = modint<_mod>;
    using i32 = std::int32_t;
    using u32 = std::uint32_t;
    using i64 = std::int64_t;
    using u64 = std::uint64_t;

    u32 v;
    constexpr u32 normalize(i64 v_) const noexcept {
        v_ %= _mod;
        if (v_ < 0) {
            v_ += _mod;
        }
        return v_;
    }

public:
    static constexpr u32 mod() noexcept { return _mod; }
    constexpr modint() noexcept : v(0) {}
    constexpr modint(i64 v_) noexcept : v(normalize(v_)) {}

    static mint raw(u32 a) {
        mint m;
        m.v = a;
        return m;
    }
    constexpr u32 val() const noexcept { return v; }
    constexpr mint& operator+=(const mint& rhs) noexcept {
        v += rhs.val();
        if (v >= _mod) {
            v -= _mod;
        }
        return (*this);
    }
    constexpr mint& operator-=(const mint& rhs) noexcept {
        v += _mod - rhs.val();
        if (v >= _mod) {
            v -= _mod;
        }
        return (*this);
    }
    constexpr mint& operator*=(const mint& rhs) noexcept {
        v = (u64)v * rhs.val() % _mod;
        return (*this);
    }

    constexpr mint operator+(const mint& r) const noexcept {
        return mint(*this) += r;
    }
    constexpr mint operator-(const mint& r) const noexcept {
        return mint(*this) -= r;
    }
    constexpr mint operator*(const mint& r) const noexcept {
        return mint(*this) *= r;
    }

    constexpr mint& operator+=(i64 rhs) noexcept {
        (*this) += mint(rhs);
        return (*this);
    }
    constexpr mint& operator-=(i64 rhs) noexcept {
        (*this) -= mint(rhs);
        return (*this);
    }
    constexpr mint& operator*=(i64 rhs) noexcept {
        (*this) *= mint(rhs);
        return (*this);
    }
    constexpr friend mint operator+(i64 l, const mint& r) noexcept {
        return mint(l) += r;
    }
    constexpr friend mint operator-(i64 l, const mint& r) noexcept {
        return mint(l) -= r;
    }
    constexpr friend mint operator*(i64 l, const mint& r) noexcept {
        return mint(l) *= r;
    }

    constexpr mint operator+(i64 r) const noexcept { return mint(*this) += r; }
    constexpr mint operator-(i64 r) const noexcept { return mint(*this) -= r; }
    constexpr mint operator*(i64 r) const noexcept { return mint(*this) *= r; }

    constexpr mint& operator=(i64 r) noexcept { return (*this) = mint(r); }

    constexpr bool operator==(const mint& r) const noexcept {
        return (*this).val() == r.val();
    }

    template <typename T, internal::is_integral_t<T>* = nullptr>
    constexpr mint pow(T e) const noexcept {
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

    constexpr mint inv() const noexcept {
        long long x, y;
        auto d = ext_gcd((long long)_mod, (long long)v, x, y);
        assert(d == 1);
        return mint(y);
    }

    constexpr mint& operator/=(const mint& r) noexcept {
        return (*this) *= r.inv();
    }
    constexpr mint operator/(const mint& r) const noexcept {
        return mint(*this) *= r.inv();
    }
    constexpr friend mint operator/(const mint& l, i64 r) noexcept {
        return mint(l) /= mint(r);
    }
    constexpr friend mint operator/(i64 l, const mint& r) noexcept {
        return mint(l) /= mint(r);
    }
};
};  // namespace kyopro

/**
 * @brief static modint
 */