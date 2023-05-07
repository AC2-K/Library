#pragma once
#include <chrono>
#include <cstdint>
#include <random>

namespace kyopro {
struct xor_shift32 {
    uint32_t rng;
    constexpr explicit xor_shift32(uint32_t seed) : rng(seed) {}
    explicit xor_shift32()
        : rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    constexpr uint32_t operator()() {
        rng ^= rng << 13;
        rng ^= rng >> 17;
        rng ^= rng << 5;
        return rng;
    }
};

struct xor_shift {
    uint64_t rng;
    constexpr xor_shift(uint64_t seed) : rng(seed) {}
    explicit xor_shift()
        : rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    constexpr uint64_t operator()() {
        rng ^= rng << 13;
        rng ^= rng >> 7;
        rng ^= rng << 17;
        return rng;
    }
};

};  // namespace kyopro

/**
 * @brief xor shift
*/
