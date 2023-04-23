#pragma once
#include <cassert>
#include <vector>
namespace kyopro {
/// @brief Segment Tree with Lazy Propagation(遅延評価セグメント木)
template <class S,
          class F,
          S (*op)(S, S),
          S (*e)(),
          F (*comp)(F, F),
          F (*id)(),
          S (*mapping)(S, F)>
class lazy_segtree {
    int sz;
    std::vector<S> dat;
    std::vector<F> lz;

public:
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& a)
        : dat(4 * a.size(), e()), lz(4 * a.size(), id()) {
        int x = 1;
        while (a.size() > x) {
            x <<= 1;
        }
        sz = x;
        for (int i = 0; i < a.size(); i++) {
            set(i, a[i]);
        }
        build();
    }

public:
    inline void set(int pos, S x) {
        assert(0 <= pos && pos < sz);
        dat[pos + sz - 1] = x;
    }
    inline void build() {
        for (int i = sz - 2; i >= 0; i--) {
            dat[i] = op(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

private:
    void eval(int pos) {
        if (lz[pos] == id()) return;
        if (pos < sz - 1) {
            lz[2 * pos + 1] = comp(lz[2 * pos + 1], lz[pos]);
            lz[2 * pos + 2] = comp(lz[2 * pos + 2], lz[pos]);
        }
        dat[pos] = mapping(dat[pos], lz[pos]);
        lz[pos] = id();
    }

private:
    void internal_apply(int L, int R, int l, int r, const F& x, int k) {
        eval(k);
        if (L <= l && r <= R) {
            lz[k] = comp(lz[k], x);
            eval(k);
        } else if (L < r && l < R) {
            int mid = (l + r) >> 1;
            internal_apply(L, R, l, mid, x, 2 * k + 1);
            internal_apply(L, R, mid, r, x, 2 * k + 2);
            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }

public:
    inline void apply(int l, int r, const F& x) {
        assert(0 <= l && l <= r && r <= sz);
        internal_apply(l, r, 0, sz, x, 0);
    }

private:
    S internal_prod(int L, int R, int l, int r, int k) {
        eval(k);
        if (r <= L || R <= l) {
            return e();
        } else if (L <= l && r <= R) {
            return dat[k];
        } else {
            int mid = (l + r) >> 1;
            S vl = internal_prod(L, R, l, mid, 2 * k + 1);
            S vr = internal_prod(L, R, mid, r, 2 * k + 2);
            return op(vl, vr);
        }
    }

public:
    inline S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= sz);
        return internal_prod(l, r, 0, sz, 0);
    }

    inline S operator[](int pos) { return prod(pos, pos + 1); }
};
};  // namespace kyopro

/// @docs docs/data-structure/lazy_segtree.md