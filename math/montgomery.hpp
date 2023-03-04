#pragma once
class montgomery64 {
    using mint = montgomery64;
    using i64 = int64_t;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    static u64 mod;
    static u64 r;
    static u64 n2;

    static u64 get_r() {
        u64 ret = mod;
        for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;
        return ret;
    }
public:
    static void set_mod(const u128& m) {
        assert(m < (i128(1) << 64));
        assert((m & 1) == 1);
        mod = m;
        n2 = -u128(m) % m;
        r = get_r();
        assert(r * mod == 1);
    }

protected:
    u128 a;

public:
    montgomery64() : a(0) {}
    template<typename T>
    montgomery64(const T& b) : a(reduce((u128(b) + mod)* n2)) {};
private:
    template<class T>
    static u64 reduce(const T& b) {
        return (b + u128(u64(b) * u64(-r)) * mod) >> 64;
    }
public:
    template<class T>
    mint& operator=(const T& rhs) {
        return (*this) = mint(rhs);
    }

    mint& operator+=(const mint& b) {
        if (i64(a += b.a - 2 * mod) < 0) a += 2 * mod;
        return *this;
    }

    mint& operator-=(const mint& b) {
        if (i64(a -= b.a) < 0) a += 2 * mod;
        return *this;
    }

    mint& operator*=(const mint& b) {
        a = reduce(u128(a) * b.a);
        return *this;
    }

    mint& operator/=(const mint& b) {
        *this *= b.inv();
        return *this;
    }

    mint operator+(const mint& b) const { return mint(*this) += b; }
    mint operator-(const mint& b) const { return mint(*this) -= b; }
    mint operator*(const mint& b) const { return mint(*this) *= b; }
    mint operator/(const mint& b) const { return mint(*this) /= b; }
    bool operator==(const mint& b) const {
        return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
    }
    bool operator!=(const mint& b) const {
        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
    }
    mint operator-() const { return mint() - mint(*this); }

    mint pow(u128 n) const {
        mint ret(1), mul(*this);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const mint& b) {
        return os << b.val();
    }

    friend istream& operator>>(istream& is, mint& b) {
        int64_t t;
        is >> t;
        b = montgomery64(t);
        return (is);
    }

    mint inv() const { return pow(mod - 2); }

    u64 val() const {
        u64 ret = reduce(a);
        return ret >= mod ? ret - mod : ret;
    }

    static u64 get_mod() { return mod; }
};
typename montgomery64::u64 montgomery64::mod, montgomery64::r, montgomery64::n2;

class ArbitraryModInt {
    using mint = ArbitraryModInt;
    using i32 = int32_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    static u32 mod;
    static u32 r;
    static u32 n2;

    static u32 get_r() {
        u32 ret = mod;
        for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
        return ret;
    }
public:
    static void set_mod(u32 m) {
        assert(m < (1ll << 31));
        assert((m & 1) == 1);
        mod = m;
        n2 = -u64(m) % m;
        r = get_r();
        assert(r * mod == 1);
    }
protected:
    i128 a;
public:
    ArbitraryModInt() : a(0) {}
    ArbitraryModInt(const int64_t& b)
        : a(reduce(u64(b% mod + mod)* n2)) {};

    static u32 reduce(const u64& b) {
        return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
    }

    mint& operator+=(const mint& b) {
        if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
        return *this;
    }

    mint& operator-=(const mint& b) {
        if (i32(a -= b.a) < 0) a += 2 * mod;
        return *this;
    }

    mint& operator*=(const mint& b) {
        a = reduce(u64(a) * b.a);
        return *this;
    }

    mint& operator/=(const mint& b) {
        *this *= b.inverse();
        return *this;
    }

    mint operator+(const mint& b) const { return mint(*this) += b; }
    mint operator-(const mint& b) const { return mint(*this) -= b; }
    mint operator*(const mint& b) const { return mint(*this) *= b; }
    mint operator/(const mint& b) const { return mint(*this) /= b; }
    bool operator==(const mint& b) const {
        return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
    }
    bool operator!=(const mint& b) const {
        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
    }
    mint operator-() const { return mint() - mint(*this); }

    mint pow(u64 n) const {
        mint ret(1), mul(*this);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const mint& b) {
        return os << b.get();
    }

    friend istream& operator>>(istream& is, mint& b) {
        int64_t t;
        is >> t;
        b = ArbitraryModInt(t);
        return (is);
    }

    mint inverse() const { return pow(mod - 2); }

    u32 get() const {
        u32 ret = reduce(a);
        return ret >= mod ? ret - mod : ret;
    }

    static u32 get_mod() { return mod; }
};
typename ArbitraryModInt::u32 ArbitraryModInt::mod;
typename ArbitraryModInt::u32 ArbitraryModInt::r;
typename ArbitraryModInt::u32 ArbitraryModInt::n2;
/// @brief Montgomery
///by https://nyaannyaan.github.io/library/modint/modint-montgomery64.hpp,https://nyaannyaan.github.io/library/modint/arbitrary-prime-modint.hpp