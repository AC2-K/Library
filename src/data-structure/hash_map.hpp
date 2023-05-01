#pragma once
#include <bits/stl_algobase.h>
#include <chrono>
namespace kyopro {
/// @brief HashMap
template <typename Key,
          typename Val,
          uint32_t n = 1 << 20,
          Val default_val = Val()>
class hash_map {
    using u32 = uint32_t;
    using u64 = uint64_t;

public:
    struct data {
        Key key;
        Val val;
    };
private:
    u64 flag[n >> 6];
    data dat[n];

    static constexpr u32 shift = 64 - std::__lg(n);

    u64 r;
    u32 get_hash(const Key& k) const { return ((u64)k * r) >> shift; }

    static constexpr uint8_t mod_msk = (1 << 6) - 1;

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
                dat[hash].key = k;
                flag[hash >> 6] |= (static_cast<u64>(1) << (hash & mod_msk));

                return dat[hash].val = default_val;
            }

            if (dat[hash].key == k) return dat[hash].val;
            if (++hash == n) hash = 0;
        }
    }
    Val* find(const Key& k) {
        u32 hash = get_hash(k);
        while (1) {
            if (!(flag[hash >> 6] & (static_cast<u64>(1) << (hash & mod_msk)))){
                return nullptr;
            }
            if (dat[hash].key == k) return &(dat[hash].val);
            if (++hash == n) hash = 0;

        }
    }
};
};  // namespace kyopro