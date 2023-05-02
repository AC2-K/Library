#pragma once
#include <cstdint>
#include <random>

namespace kyopro {
struct xor_shift32 {
    uint32_t rng;
    xor_shift32() : rng(std::rand()) {}
    uint32_t operator()() {
        rng ^= rng << 13;
        rng ^= rng >> 17;
        rng ^= rng << 5;
        return rng;
    }
};
};  // namespace kyopro
