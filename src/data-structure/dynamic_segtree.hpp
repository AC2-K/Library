#pragma once
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

namespace kyopro {
template <class S, class Op> class dynamic_segtree {
    const std::size_t n;
    const Op op;
    const S e;

    struct Node {
        S val;
        Node *l, *r, *parent;
        
        constexpr Node(S v, Node* pt)
            : val(), l(nullptr), r(nullptr), parent(pt) {}
    };

    using uptr = std::unique_ptr<Node>;
    std::vector<uptr> nodes;
    Node* root;
    Node* make_ptr(S v, Node* pt = nullptr) {
        nodes.emplace_back(std::make_unique<Node>(v, pt));
        return nodes.back().get();
    };


    Node* find(std::size_t i) {
        assert(0 <= i && i < n);

        std::size_t l = 0, r = n;

        Node* p = root;

        while (r - l > 1) {
            std::size_t md = (r + l) >> 1;
            if (i < md) {
                if (!p->l) {
                    p->l = make_ptr(e, p);
                }
                p = p->l;
                r = md;
            } else {
                if (!p->r) {
                    p->r = make_ptr(e, p);
                }
                p = p->r;
                l = md;
            }
        }
        return p;
    }
    void push(Node* p) {
        while (p = p->parent) {
            p->val = op((p->l ? p->l->val : e), (p->r ? p->r->val : e));
        }
    }

public:
    dynamic_segtree() = default;
    dynamic_segtree(std::size_t n, Op op, S e)
        : n(n), op(op), e(e), root(nullptr) {
        root = make_ptr(e, nullptr);
    }

    void apply(std::size_t i, S x) {
        assert(0 <= i && i < n);
        auto p = find(i);
        p->val = op(p->val, x);
        push(p);
    }
    void update(std::size_t i, S x) {
        assert(0 <= i && i < n);
        auto p = find(i);
        p->val = x;
        push(p);
    }
    S at(std::size_t i) {
        assert(0 <= i && i < n);
        return find(i)->val;
    }
    S fold(std::size_t l, std::size_t r) const {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) {
            return e;
        }
        return internal_fold(root, 0, n, l, r);
    }

private:
    S internal_fold(const Node* p,
                    std::size_t l,
                    std::size_t r,
                    std::size_t L,
                    std::size_t R) const {
        if (!p || r <= L || R <= l) {
            return e;
        }
        if (L <= l && r <= R) {
            return p->val;
        }

        std::size_t mid = (l + r) >> 1;
        return op(internal_fold(p->l, l, mid, L, R),
                  internal_fold(p->r, mid, r, L, R));
    }
};
};  // namespace kyopro

/**
 * @brief Dynamic Segment Tree
 * @see https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
 */