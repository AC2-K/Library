#pragma once
#include <cassert>
#include <vector>
namespace kyopro {
/**
 * @brief 双対セグメント木
 * @tparam F 作用素
 * @tparam id F の単位元
 */
template <class F, F (*composition)(F, F), F (*id)()>
class dual_segtree {
    std::vector<F> dat;
    int _n, sz, lg;

public:
    dual_segtree() {}
    dual_segtree(int _n) : _n(_n) {
        sz = 1, lg = 0;
        while (sz < _n) {
            ++lg;
            sz <<= 1;
        }
        dat.assign(sz << 1, id());
    }

private:
    void update(int p, const F& v) { dat[p] = composition(dat[p], v); }
    void push(int p) {
        if (dat[p] == id()) {
            return;
        }
        update(p << 1 | 0, dat[p]);
        update(p << 1 | 1, dat[p]);
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
        for (int i = lg; i > 0; i--) {
            if (((l >> i) << i) != l) {
                push(l >> i);
            }
            if (((r >> i) << i) != r) {
                push((r - 1) >> i);
            }
        }
        while (l < r) {
            if (l & 1) {
                update(l++, v);
            }
            if (r & 1) {
                update(--r, v);
            }
            l >>= 1, r >>= 1;
        }
    }
};

};  // namespace kyopro

/**
 * @docs docs/data-structure/dual_segtree.md
 */