#pragma once
#include <cassert>
#include <vector>
namespace kyopro {

/// @brief Dual Segmenttree(双対セグメント木)
template <class F, F (*comp)(F, F), F (*id)(), bool is_commutative = true>
class dual_segtree {
    std::vector<F> dat;
    int _n, sz, lg;

public:
    dual_segtree() : {}
    dual_segtree(int _n) : _n(_n) {
        sz = 1, lg = 0;
        while (sz < _n) {
            lg++;
            sz <<= 1;
        }
        dat.assign(sz << 1, id());
    }

private:
    void all_apply(int p, const F& v) { dat[p] = comp(dat[p], v); }
    void push(int p) {
        if (dat[p] == id()) {
            return;
        }
        all_apply(p << 1 | 0, dat[p]);
        all_apply(p << 1 | 1, dat[p]);
        dat[p] = id();
    }

public:
    F operator[](int p) {
        assert(0 <= p && p < _n);

        F res = id();

        p += sz;
        for (int i = lg; i > 0; i--) {
            push(p >> i);
        }
        return dat[p];
    }

    void apply(int l, int r, const F& v) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
        l += sz, r += sz;
        if (is_commutative) {
            for (int i = lg; i > 0; i--) {
                if (((l >> i) << i) != l) {
                    push(l >> i);
                }
                if (((r >> i) << i) != r) {
                    push((r - 1) >> i);
                }
            }
        }
        while (l < r) {
            if (l & 1) {
                all_apply(l++, v);
            }
            if (r & 1) {
                all_apply(--r, v);
            }
            l >>= 1, r >>= 1;
        }
    }
};

};  // namespace kyopro

/// @docs docs/data-structure/dual_segtree.md