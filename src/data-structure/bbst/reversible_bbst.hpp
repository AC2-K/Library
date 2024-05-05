#pragma once
#include <cassert>
#include <memory>
#include <utility>
#include "../../random/xor_shift.hpp"

namespace kyopro {
template <class S, auto op, auto e> class reversible_bbst {
    using u32 = uint32_t;
    xor_shift32 rng;
    struct Node {
        Node *l, *r;
        u32 priority;
        S value, prod;
        int size;
        bool rev;
        
        Node(const S& v, u32 prio)
            : l(nullptr),
              r(nullptr),
              priority(prio),
              value(v),
              prod(v),
              size(1),
              rev(false) {}
    };

    using uptr = std::unique_ptr<Node>;
    std::vector<uptr> nodes;
    Node* make_ptr(const S& v, u32 prio) {
        nodes.emplace_back(std::make_unique<Node>(v, prio));
        return nodes.back().get();
    }
    int size(Node* p) const { return p ? p->size : 0; }
    S fold(Node* p) { return p ? p->prod : e(); }
    
    void reverse(Node*& p) {
        if (p) {
            p->rev ^= 1;
        }
    }
    void push_down(Node*& p) {
        if (p->rev) {
            p->rev = false;
            std::swap(p->l, p->r);
            reverse(p->l), reverse(p->r);
        }
    }
    void push_up(Node*& p) {
        p->size = size(p->l) + size(p->r) + 1;
        p->prod = op(p->value, op(fold(p->l), fold(p->r)));
    }

    std::pair<Node*, Node*> split(Node* p, int k) {
        if (!p) return {nullptr, nullptr};

        push_down(p);
        int s = size(p->l);
        if (s >= k) {
            auto [l, r] = split(p->l, k);
            p->l = r;
            push_up(p);

            return {std::move(l), std::move(p)};
        } else {
            auto [l, r] = split(p->r, k - s - 1);

            p->r = l;
            push_up(p);

            return {std::move(p), std::move(r)};
        }
    }

    Node* merge(Node* l, Node* r) {
        if (!l) return std::move(r);
        if (!r) return std::move(l);

        if (l->priority < r->priority) {
            push_down(r);
            r->l = merge(l, r->l);
            push_up(r);
            return std::move(r);
        } else {
            push_down(l);
            l->r = merge(l->r, r);
            push_up(l);

            return std::move(l);
        }
    }

    Node* root;

public:
    reversible_bbst() : rng(2023), root(nullptr) {}
    void insert(int i, const S& a) {
        Node* item = make_ptr(a, rng());
        auto [l, r] = split(root, i);
        root = merge(l, item);
        root = merge(root, r);
    }
    S fold(int l, int r) {
        assert(0 <= l && l <= r && r <= size(root));
        auto [xy, z] = split(root, r);
        auto [x, y] = split(xy, l);
        S res = fold(y);
        xy = merge(x, y);
        root = merge(xy, z);
        return res;
    }
    void reverse(int l, int r) {
        assert(0 <= l && l <= r && r <= size(root));
        auto [xy, z] = split(root, r);
        auto [x, y] = split(xy, l);
        reverse(y);
        xy = merge(x, y);
        root = merge(xy, z);
    }
};
};  // namespace kyopro

/**
 * @brief 反転可能平衡二分木
 * @see https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_reverse_range_sum/sol/correct.cpp
 */