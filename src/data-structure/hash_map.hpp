#pragma once
#include <bits/stl_algobase.h>
#include <chrono>
namespace kyopro {
/**
 * @brief HashMap
 */
template <typename Key,
          typename Val,
          uint32_t n = 1 << 20,
          Val default_val = Val()>
class hash_map {
    using u32 = uint32_t;
    using u64 = uint64_t;

    u64* flag = new u64[n];
    Key* keys = new Key[n];
    Val* vals = new Val[n];

    static constexpr u32 shift = 64 - std::__lg(n);

    u64 r;
    u32 get_hash(const Key& k) const { return ((u64)k * r) >> shift; }

    static constexpr int mod_msk = (1 << 6) - 1;

public:
    explicit constexpr hash_map() {
        r = std::chrono::steady_clock::now().time_since_epoch().count();
        r ^= r >> 16;
        r ^= r << 32;
    }
    Val& operator[](const Key& k) {
        u32 hash = get_hash(k);

        while (1) {
            if (!(flag[hash >> 6] &
                  (static_cast<u64>(1) << (hash & mod_msk)))) {
                keys[hash] = k;
                flag[hash >> 6] |= static_cast<u64>(1) << (hash & mod_msk);
                return vals[hash] = default_val;
            }

            if (keys[hash] == k) return vals[hash];
            hash = (hash + 1) & (n - 1);
        }
    }

    Val* find(const Key& k) const {
        u32 hash = get_hash(k);
        while (1) {
            if (!(flag[hash >> 6] & (static_cast<u64>(1) << (hash & mod_msk))))
                return nullptr;
            if (keys[hash] == k) return &(vals[hash]);
            hash = (hash + 1) & (n - 1);
        }
    }
};
};  // namespace kyopro

/**
 * @docs docs/data-structure/hash_map.md
 */