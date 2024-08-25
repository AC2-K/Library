#pragma once
#include <vector>
#include <cassert>

namespace kyopro {

template <typename T> class BIT {
    std::vector<T> bit;
    int n;

public:
    BIT() : BIT(0) {}
    BIT(int n) : n(n), bit(n + 1, T()) {}
    
    void add(int p, T w) {
        assert(0 <= p && p < n);
        p++;
        for (int x = p; x <= n; x += x & -x) {
            bit[x] += w;
        }
    }

    T sum(int p) const {
        assert(0 <= p && p <= n);
        T s = 0;

        for (int x = p; x > 0; x -= x & -x) {
            s += bit[x];
        }
        return s;
    }

    T sum(int l, int r) const { return sum(r) - sum(l); }

    int lower_bound(T w) const {
        if (w <= 0) return 0;

        int x = 0;
        int k = 1;
        while (k < n) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }

        return x + 1;
    }

    T operator[](int i) { return sum(i + 1) - sum(i); }
    void update(int i, T v) { add(i, -sum(i + 1) + sum(i) + v); }
};
};  // namespace kyopro

/**
 * @brief Binary Index Tree
 */