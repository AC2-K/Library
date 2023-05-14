#pragma once
#include <chrono>
#include <random>
#include <string>
#include <vector>
#include "../math/gcd.hpp"
#include "../math/mod_pow.hpp"
namespace kyopro {

/**
 * @brief Rolling Hash
 */
class RollingHash {
    using ull = uint_fast64_t;
    using i128 = __int128_t;
    using u128 = __uint128_t;
    // mod
    static constexpr ull msk30 = (1ul << 30) - 1;
    static constexpr ull msk61 = (1ul << 31) - 1;
    const std::string str;
    std::vector<ull> hash, pow;

    static constexpr ull mod = (1uL << 61) - 1;
    static constexpr ull primitive_root = 37;

public:
    static constexpr uint mapping_max = (uint)'Z' + 2;
    static ull base;

private:
    constexpr ull mul(const u128& a, const u128& b) const {
        u128 t = a * b;

        t = (t >> 61) + (t & mod);

        if (t >= mod) {
            t -= mod;
        }

        return t;
    }

    constexpr ull mapping(char c) const {
        return (ull)c;  // 変更する?
    }

    static ull generate() {
        std::mt19937_64 engine(
            std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<ull> rand(1uL, mod - 1);
        return rand(engine);
    }
    static void generate_base() {
        if (base != 0) {
            return;
        }
        ull r = mod - 1;

        while (_gcd(r, mod - 1) != 1 || r <= mapping_max) {
            r = generate();
        }
        base = mod_pow(primitive_root, r, mod);
    }

public:
    RollingHash() : str() {}

    RollingHash(const std::string& str) : str(str) {
        generate_base();
        build();
    }

    void build() {
        hash.resize(str.size() + 1);
        pow.resize(str.size() + 1, 1);

        for (int i = 0; i < (int)str.size(); i++) {
            hash[i + 1] = mul(hash[i], base) + mapping(str[i]);
            pow[i + 1] = mul(pow[i], base);
            if (hash[i + 1] >= mod) {
                hash[i + 1] -= mod;
            }
        }
    }
    ull range(int l, int r) const {
        assert(0 <= l && l <= r && r <= str.size());

        ull res = mod + hash[r] - mul(hash[l], pow[r - l]);
        return res < mod ? res : res - mod;
    }
    ull get_all() const { return hash.back(); }
    int size() const { return str.size(); }

    static int lcp(const RollingHash& a,
                   const RollingHash& b,
                   int start_a,
                   int start_b) {
        int ok = 0;
        int ng = std::min(a.size() - start_a, b.size() - start_b) + 1;
        while (ng - ok > 1) {
            int md = (ok + ng) >> 1;
            if (a.range(start_a, start_a + md) ==
                b.range(start_b, start_b + md)) {
                ok = md;
            } else {
                ng = md;
            }
        }

        return ok;
    }
};
}  // namespace kyopro
typename kyopro::RollingHash::ull kyopro::RollingHash::base;
