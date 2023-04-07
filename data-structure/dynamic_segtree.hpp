#pragma once
#include <cassert>
/// @brief Dynamic Segment Tree(動的セグメント木)
template <class S, S (*op)(S, S), S (*e)()> class dynamic_segtree {
  public:
    dynamic_segtree(const size_t& n) : n(n), root(nullptr) {}

  private:
    struct node {
        S val;
        node* left;
        node* right;

        node(const S& v) : val(v), left(nullptr), right(nullptr) {}
    };
    node* root;
    size_t n;

  public:
    void update(const size_t& p, const S& x) {
        assert(0 <= p && p < n);
        internal_update(root, 0, n, p, x);
    }
    void add(const size_t& p, const S& x) {
        assert(0 <= p && p < n);
        internal_add(root, 0, n, p, x);
    }
    S operator[](const size_t& p) {
        assert(0 <= p && p < n);
        return internal_access(root, 0, n, p);
    }
    S prod(const size_t& l, const size_t& r) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) {
            return e();
        }

        return internal_prod(root, 0, n, l, r);
    }

  private:
    void internal_update(node*& p,
                         const size_t& l,
                         const size_t& r,
                         const size_t& idx,
                         const S& new_val) {
        if (p == nullptr) {
            p = new node(e());
        }

        if (r - l == 1) {
            p->val = new_val;
            return;
        }

        size_t mid = (l + r) >> 1;
        if (idx < mid)
            internal_update(p->left, l, mid, idx, new_val);
        else
            internal_update(p->right, mid, r, idx, new_val);
        p->val = e();
        if (p->left != nullptr) p->val = op(p->left->val, p->val);
        if (p->right != nullptr) p->val = op(p->val, p->right->val);
    }
    void internal_add(node*& p,
                      const size_t& l,
                      const size_t& r,
                      const size_t& idx,
                      const S& new_val) {
        if (p == nullptr) {
            p = new node(e());
        }

        if (r - l == 1) {
            p->val = op(p->val, new_val);
            return;
        }

        size_t mid = (l + r) >> 1;
        if (idx < mid)
            internal_add(p->left, l, mid, idx, new_val);
        else
            internal_add(p->right, mid, r, idx, new_val);
        p->val = e();
        if (p->left != nullptr) p->val = op(p->left->val, p->val);
        if (p->right != nullptr) p->val = op(p->val, p->right->val);
    }

    S internal_access(node*& p,
                      const size_t& l,
                      const size_t& r,
                      const size_t& idx) {
        if (p == nullptr) {
            return e();
        }
        if (r - l == 1) {
            return p->val;
        }

        size_t mid = (l + r) >> 1;
        if (idx < mid)
            return internal_access(p->left, l, mid, idx);
        else
            return internal_access(p->right, mid, r, idx);
    }

    S internal_prod(node*& p,
                    const size_t& l,
                    const size_t& r,
                    const size_t& L,
                    const size_t& R) {
        if (p == nullptr || r <= L || R <= l) {
            return e();
        }
        if (L <= l && r <= R) {
            return p->val;
        }

        size_t mid = (l + r) >> 1;
        return op(internal_prod(p->left, l, mid, L, R),
                  internal_prod(p->right, mid, r, L, R));
    }
};

/// @docs docs/data-structure/dynamic_segtree.md