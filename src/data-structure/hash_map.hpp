#pragma once
#include <chrono>
#include <utility>
#include <cmath>
#include <bits/stl_algobase.h>

namespace kyopro {
template <typename Key,
          typename Val,
          std::size_t n = 1 << 20,
          Val default_val = Val()>
class hash_map {
    using u32 = uint32_t;
    using u64 = uint64_t;

    u64* flag = new u64[n / 64];
    Key* keys = new Key[n];
    Val* vals = new Val[n];

    static constexpr u32 shift = 64 - std::__lg(n);

    u64 r;
    u32 get_hash(Key k) const { return ((u64)k * r) >> shift; }

    static constexpr int block = 64;

public:
    explicit hash_map() {
        r = std::chrono::steady_clock::now().time_since_epoch().count();
        r ^= r >> 16;
        r ^= r << 32;
    }
    Val& operator[](Key k) {
        u32 hash = get_hash(k);

        while (1) {
            if (~flag[hash / block] >> (hash % block) & static_cast<u64>(1)) {
                keys[hash] = k;
                flag[hash / block] |= (static_cast<u64>(1) << (hash % block));
                return vals[hash] = default_val;
            }

            if (keys[hash] == k) return vals[hash];
            hash = (hash + 1) & (n - 1);
        }
    }

    Val* find(Key k) const {
        u32 hash = get_hash(k);
        while (1) {
            if (~flag[hash / block] >> (hash % block) & static_cast<u64>(1)) {
                return nullptr;
            }
            if (keys[hash] == k) return &(vals[hash]);
            hash = (hash + 1) & (n - 1);
        }
    }
};
};  // namespace kyopro

/**
 * @brief Hash Map
 */