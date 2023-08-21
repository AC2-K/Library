#pragma once
#include <cassert>
#include <iostream>
#include "../internal/barrett.hpp"
#include "../internal/montgomery.hpp"
namespace kyopro {
template <int id = -1> class barrett_modint : internal::modint_base {
    using mint = barrett_modint<id>;
    using u32 = uint32_t;
    using u64 = uint64_t;

    using i32 = int32_t;
    using i64 = int64_t;
    using br = internal::barrett;

    static br brt;
    u32 v;

public:
    static void set_mod(u32 mod_) { brt = br(mod_); }

public:
    explicit constexpr barrett_modint() noexcept : v(0) { assert(mod()); }
    explicit constexpr barrett_modint(i64 v_) noexcept : v() {
        assert(mod());
        if (v_ < 0) v_ = (i64)mod() - v_;
        v = brt.reduce(v_);
    }

    u32 val() const noexcept { return v; }
    static u32 mod() { return brt.get_mod(); }
    static mint raw(u32 v) {
        mint x;
        x.v = v;
        return x;
    }

    constexpr mint& operator++() noexcept {
        ++v;
        if (v == mod()) v = 0;
        return (*this);
    }
    constexpr mint& operator--() noexcept {
        if (v == 0) v = mod();
        --v;
        return (*this);
    }
    constexpr mint operator++(int) noexcept {
        mint res(*this);
        ++(*this);
        return res;
    }
    constexpr mint operator--(int) noexcept {
        mint res(*this);
        --(*this);
        return res;
    }

    constexpr mint& operator+=(const mint& r) noexcept {
        v += r.v;
        if (v >= mod()) v -= mod();
        return (*this);
    }
    constexpr mint& operator-=(const mint& r) noexcept {
        v += mod() - r.v;
        if (v >= mod()) {
            v -= mod();
        }

        return (*this);
    }
    constexpr mint& operator*=(const mint& r) noexcept {
        v = brt.mul(v, r.v);
        return (*this);
    }
    constexpr mint& operator/=(const mint& r) noexcept { return (*this) *= r.inv(); }

    friend mint operator+(const mint& lhs, const mint& rhs) noexcept {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) noexcept {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) noexcept {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) noexcept {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) noexcept {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) noexcept {
        return lhs._v != rhs._v;
    }

    constexpr mint& operator+=(i64 r) noexcept { return (*this) += mint(r); }
    constexpr mint& operator-=(i64 r) noexcept { return (*this) -= mint(r); }
    constexpr mint& operator*=(i64 r) noexcept { return (*this) *= mint(r); }

    friend mint operator+(i64 l, const mint& r) noexcept { return mint(l) += r; }
    friend mint operator+(const mint& l, i64 r) noexcept { return mint(l) += r; }
    friend mint operator-(i64 l, const mint& r) noexcept { return mint(l) -= r; }
    friend mint operator-(const mint& l, i64 r) noexcept { return mint(l) -= r; }
    friend mint operator*(i64 l, const mint& r) noexcept { return mint(l) *= r; }
    friend mint operator*(const mint& l, i64 r) noexcept { return mint(l) *= r; }

    constexpr mint operator+() const noexcept { return *this; }
    constexpr mint operator-() const noexcept { return mint() - *this; }
    
    template <typename T> mint pow(T e) const noexcept {
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
    constexpr mint inv() const noexcept { return pow(mod() - 2); }
};
};  // namespace kyopro
template <int id>
typename kyopro::barrett_modint<id>::br kyopro::barrett_modint<id>::brt;

namespace kyopro {
template <typename T, int id = -1>
class montgomery_modint : internal::modint_base {
    using LargeT = internal::double_size_uint_t<T>;
    static T _mod;
    static internal::Montgomery<T> mr;

public:
    static void set_mod(T mod_) {
        mr.set_mod(mod_);
        _mod = mod_;
    }

    static T mod() { return _mod; }

private:
    T v;

public:
    montgomery_modint(T v_ = 0) {
        assert(_mod);
        v = mr.generate(v_);
    }
    T val() const { return mr.reduce(v); }

    using mint = montgomery_modint<T, id>;
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
        v = mr.mul(v, r.v);
        return (*this);
    }

    mint operator+(const mint& r) { return mint(*this) += r; }
    mint operator-(const mint& r) { return mint(*this) -= r; }
    mint operator*(const mint& r) { return mint(*this) *= r; }

    mint& operator=(const T& v_) {
        (*this) = mint(v_);
        return (*this);
    }

    friend std::ostream& operator<<(std::ostream& os, const mint& mt) {
        os << mt.val();
        return os;
    }
    friend std::istream& operator>>(std::istream& is, mint& mt) {
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
    mint inv() const { return pow(mod() - 2); }

    mint& operator/=(const mint& r) { return (*this) *= r.inv(); }
    mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }
    mint& operator/=(T r) { return (*this) /= mint(r); }
    friend mint operator/(const mint& l, T r) { return mint(l) /= r; }
    friend mint operator/(T l, const mint& r) { return mint(l) /= r; }
};
};  // namespace kyopro
template <typename T, int id> T kyopro::montgomery_modint<T, id>::_mod;
template <typename T, int id>
kyopro::internal::Montgomery<T> kyopro::montgomery_modint<T, id>::mr;

/**
 * @brief 動的modint
 * @docs docs/math/dynamic_modint.md
 */