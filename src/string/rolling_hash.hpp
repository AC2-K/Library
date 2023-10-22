#pragma once
#include <chrono>
#include <random>
#include <string>
#include <vector>
#include "../math/gcd.hpp"
#include "../math/mod_pow.hpp"
namespace kyopro {

class RollingHash {
    using u64 = std::uint64_t;
    using i128 = __int128_t;
    using u128 = __uint128_t;

    static constexpr u64 msk30 = (static_cast<u64>(1) << 30) - 1;
    static constexpr u64 msk61 = (static_cast<u64>(1) << 31) - 1;
    const std::string str;
    std::vector<u64> _hash, _pow;
    
    static constexpr u64 mod = (static_cast<u64>(1) << 61) - 1;
    static constexpr u64 primitive_root = 37;
    static constexpr uint mapping_max = (uint)'Z' + 2;
    static u64 base;
    
private:
    constexpr u64 mul(u64 a, u64 b) const {
        u128 t = (u128)a * b;
        t = (t >> 61) + (t & mod);
        if (t >= mod) {
            t -= mod;
        }
        return t;
    }

    constexpr u64 mapping(char c) const { return (u64)c; }

    static u64 generate() {
        static std::mt19937_64 engine(
            std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<u64> rand(1, mod - 1);
        return rand(engine);
    }
    static void generate_base() {
        if (base != 0) {
            return;
        }
        u64 r = mod - 1;
        
        while (_gcd(r, mod - 1) != 1 || r <= mapping_max) r = generate();

        base = mod_pow(primitive_root, r, mod);
    }

public:
    RollingHash() : str() {}

    RollingHash(const std::string& str) : str(str) {
        generate_base();
        build();
    }

    void build() {
        _hash.resize(str.size() + 1);
        _pow.resize(str.size() + 1, 1);

        for (int i = 0; i < (int)str.size(); i++) {
            _hash[i + 1] = mul(_hash[i], base) + mapping(str[i]);
            _pow[i + 1] = mul(_pow[i], base);
            if (_hash[i + 1] >= mod) {
                _hash[i + 1] -= mod;
            }
        }
    }
    u64 hash(int l, int r) const {
        assert(0 <= l && l <= r && r <= str.size());

        u64 res = mod + _hash[r] - mul(_hash[l], _pow[r - l]);
        return res < mod ? res : res - mod;
    }
    u64 get_all() const { return _hash.back(); }
    int size() const { return str.size(); }

    static int lcp(const RollingHash& a,
                   const RollingHash& b,
                   int start_a,
                   int start_b) {
        int ok = 0;
        int ng = std::min(a.size() - start_a, b.size() - start_b) + 1;
        while (ng - ok > 1) {
            int md = (ok + ng) >> 1;
            if (a.hash(start_a, start_a + md) ==
                b.hash(start_b, start_b + md)) {
                ok = md;
            } else {
                ng = md;
            }
        }

        return ok;
    }
};
}  // namespace kyopro
typename kyopro::RollingHash::u64 kyopro::RollingHash::base;


/**
 * @brief Rolling Hash
 */