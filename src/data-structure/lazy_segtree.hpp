#pragma once
#include <cassert>
#include <vector>
namespace kyopro {

template <class S, class F, class Op, class Composition, class Mapping>
class lazy_segtree {
    int lg, sz, n;
    std::vector<S> dat;
    std::vector<F> lazy;

    const Op op;
    const S e;
    const Composition composition;
    const F id;
    const Mapping mapping;

public:
    lazy_segtree() = default;
    lazy_segtree(int n,
                 const Op& op,
                 const S& e,
                 const Composition& composition,
                 const F& id,
                 const Mapping& mapping)
        : lazy_segtree(n,
                       op,
                       e,
                       composition,
                       id,
                       mapping,
                       std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& a,
                 const Op& op,
                 const S& e,
                 const Composition& composition,
                 const F& id,
                 const Mapping& mapping)
        : n((int)a.size()),
          op(op),
          e(e),
          composition(composition),
          id(id),
          mapping(mapping) {}
    {
        sz = 1, lg = 0;
        while (sz <= n) {
            sz <<= 1;
            lg++;
        }

        dat.assign(sz << 1, e);
        lazy.assign(sz, id);
        for (int i = 0; i < n; ++i) {
            set(i, a[i]);
        }
        build();
    }

public:
    void set(int i, const S& v) {
        assert(0 <= i && i < sz);
        dat[i + sz] = v;
    }
    void build() {
        for (int i = sz - 1; i > 0; --i) {
            push_up(i);
        }
    }

private:
    void all_apply(int p, const F& f) {
        dat[p] = mapping(dat[p], f);
        if (p < sz) lazy[p] = composition(lazy[p], f);
    }
    void push_up(int k) { dat[k] = op(dat[k << 1 | 0], dat[k << 1 | 1]); }
    void push_down(int p) {
        if (lazy[p] == id) {
            return;
        }
        all_apply(p << 1 | 0, lazy[p]);
        all_apply(p << 1 | 1, lazy[p]);
        lazy[p] = id();
    }

public:
    S operator[](int p) {
        assert(0 <= p && p < n);
        p += sz;
        for (int i = lg; i > 0; --i) push_down(p >> i);
        return dat[p];
    }

    S fold(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return e;

        l += sz, r += sz;
        for (int i = lg; i > 0; --i) {
            if (((l >> i) << i) != l) {
                push_down(l >> i);
            }
            if (((r >> i) << i) != r) {
                push_down((r - 1) >> i);
            }
        }

        S sml = e, smr = e;
        while (l < r) {
            if (l & 1) sml = op(sml, dat[l++]);
            if (r & 1) smr = op(dat[--r], smr);
            l >>= 1, r >>= 1;
        }

        return op(sml, smr);
    }
    void apply(int l, int r, const F& v) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return;
        l += sz, r += sz;
        for (int i = lg; i > 0; --i) {
            if (((l >> i) << i) != l) {
                push_down(l >> i);
            }
            if (((r >> i) << i) != r) {
                push_down((r - 1) >> i);
            }
        }
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, v);
                if (r & 1) all_apply(--r, v);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= lg; ++i) {
            if (((l >> i) << i) != l) push_up(l >> i);
            if (((r >> i) << i) != r) push_up((r - 1) >> i);
        }
    }
};
};  // namespace kyopro

/**
 * @brief Lazy Segment Tree
 */