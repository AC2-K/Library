#pragma once
#include <cassert>
#include <vector>
namespace kyopro {


template <class S, auto op, auto e> class segtree {
    int lg, sz, n;
    std::vector<S> dat;

public:
    segtree() = default;
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& vec) : n((int)vec.size()) {
        sz = 1, lg = 0;
        while (sz <= n) {
            sz <<= 1;
            lg++;
        }

        dat = std::vector<S>(sz << 1, e());

        for (int i = 0; i < n; i++) {
            set(i, vec[i]);
        }
        build();
    }

    void set(int p, const S& v) {
        assert(0 <= p && p < sz);
        dat[sz + p] = v;
    }
    void build() {
        for (int i = sz - 1; i > 0; i--) {
            dat[i] = op(dat[i << 1 | 0], dat[i << 1 | 1]);
        }
    }

    S operator[](int p) const { return dat[sz + p]; }

    void update(int p, const S& v) {
        assert(0 <= p && p < sz);
        p += sz;
        dat[p] = v;
        while (p >>= 1) {
            dat[p] = op(dat[(p << 1) | 0], dat[(p << 1) | 1]);
        }
    }

    S fold(int l, int r) const {
        assert(0 <= l && l <= r && r <= sz);
        if (l == 0 && r == n) {
            return dat[1];
        }
        l += sz, r += sz;
        S sml = e(), smr = e();
        while (l != r) {
            if (l & 1) sml = op(sml, dat[l++]);
            if (r & 1) smr = op(dat[--r], smr);
            l >>= 1, r >>= 1;
        }
        return op(sml, smr);
    }
    void apply(int p, const S& v) {
        assert(0 <= p && p < sz);
        update(p, op(dat[sz + p], v));
    }
};
};  // namespace kyopro

/**
 * @brief Segment Tree
 */