#pragma once
#include <memory>
#include <utility>
#include <cassert>
#include "../random/xor_shift.hpp"

namespace kyopro {
/// @brief 遅延評価つき・反転可能 平衡二分探索木
/// @tparam S モノイド
/// @tparam F 作用素モノイド
/// @tparam op S上の二項演算
/// @tparam e Sの単位元
/// @tparam composition F上の二項演算
/// @tparam id Fの単位元
/// @tparam mapping 
/// @ref https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
template <typename S,
          class F,
          S (*op)(S, S),
          S (*e)(),
          F (*composition)(F, F),
          F (*id)(),
          S (*mapping)(S, F, int)>
class lazy_reversible_rbst {
    using u32 = uint32_t;
    xor_shift32 rng;
    struct Node {
        std::unique_ptr<Node> l, r;
        u32 priority;
        S value, prod;

        F lazy;
        int size;
        bool rev;

        Node(const S& v, u32 prio)
            : l(),
              r(),
              priority(prio),
              value(v),
              prod(e()),
              lazy(id()),
              size(1),
              rev(false) {}
    };

    using ptr = std::unique_ptr<Node>;
    int size(const ptr& p) const { return p ? p->size : 0; }
    S fold(const ptr& p) { return p ? p->prod : e(); }


    void update(const ptr& p) {
        if(!p)return;
        p->size = size(p->l) + size(p->r) + 1;
        p->prod = op(p->value, op(fold(p->l), fold(p->r)));
    }
    void push(const ptr& p) {
        if(!p)return;
        if (p->rev) {
            p->rev = false;
            std::swap(p->l, p->r);
            reverse(p->l), reverse(p->r);
        }

        if (p->lazy != id()) {
            if (p->l) {
                p->l->lazy = composition(p->l->lazy, p->lazy);
                p->l->prod = mapping(p->l->prod, p->lazy, size(p->l));
            }
            if (p->r) {
                p->r->lazy = composition(p->r->lazy, p->lazy);
                p->r->prod = mapping(p->r->prod, p->lazy, size(p->r));
            }


            p->value=mapping(p->value,p->lazy,1);
            p->lazy=id();
        }

        update(p);
    }

    std::pair<ptr, ptr> split(ptr p, int k) {
        if (!p) return {nullptr, nullptr};

        push(p);
        int s = size(p->l);
        if (s >= k) {
            auto [l, r] = split(std::move(p->l), k);
            p->l = std::move(r);
            update(p);

            return {std::move(l), std::move(p)};
        } else {
            auto [l, r] = split(std::move(p->r), k - s - 1);

            p->r = std::move(l);
            update(p);

            return {std::move(p), std::move(r)};
        }
        
    }

    ptr merge(ptr l, ptr r) {
        if (!l) return r;
        if (!r) return l;
        push(l),push(r);
        if (l->priority < r->priority) {
            r->l = merge(std::move(l), std::move(r->l));
            update(r);
            return r;
        } else {
            l->r = merge(std::move(l->r), std::move(r));
            update(l);
            return l;
        }
    }
    
    void reverse(const ptr& p) {
        if (p) {
            p->rev ^= 1;
        }
    }
    ptr root = nullptr;

public:
    constexpr explicit lazy_reversible_rbst():rng(2023){}
    void insert(int i, S a) {
        auto [l, r] = split(std::move(root), i);
        ptr item = std::make_unique<Node>(a, rng());
        root = merge(std::move(l), std::move(item));
        root = merge(std::move(root), std::move(r));
    }

    void erase(int i) {
        auto [xy, z] = split(std::move(root), i + 1);
        auto [x, y] = split(std::move(xy), i);
        root = merge(std::move(x), std::move(z));
    }
    
    S fold(int l, int r) {
        auto [xy, z] = split(std::move(root), r);
        auto [x, y] = split(std::move(xy), l);
        auto res = fold(y);
        xy = merge(std::move(x), std::move(y));
        root = merge(std::move(xy), std::move(z));
        return res;
    }
    
    void apply(int l, int r, const F& f) {
        auto [xy, z] = split(std::move(root), r);
        auto [x, y] = split(std::move(xy), l);

        y->lazy = composition(y->lazy, f);
        y->prod = mapping(y->prod, f, size(y));

        xy = merge(std::move(x), std::move(y));
        root = merge(std::move(xy), std::move(z));
    }
    
    void reverse(int l, int r) {
        auto [xy, z] = split(std::move(root), r);
        auto [x, y] = split(std::move(xy), l);
        reverse(y);
        xy = merge(std::move(x), std::move(y));
        root = merge(std::move(xy), std::move(z));
    }
};
};  // namespace kyopro