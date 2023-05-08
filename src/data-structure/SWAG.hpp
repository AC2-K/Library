#pragma once
#include <vector>
#include <algorithm>
namespace kyopro {
/**
 * @brief Slide Window Aggrigation
 */
template <class S, auto op, auto e>
class SWAG {
    std::vector<S> front_stack, back_stack;
    std::vector<S> front_prod, back_prod;

public:
    constexpr explicit SWAG() {
        front_prod.emplace_back(e()), back_prod.emplace_back(e());
    }
    void reserve(size_t sz) {
        back_stack.reserve(sz), back_prod.reserve(sz + 1);
    }
    void push(const S& x) {
        back_stack.emplace_back(x);
        back_prod.emplace_back(op(back_prod.back(), x));
    }
    void pop_back() { back_stack.pop_back(), back_prod.pop_back(); }
    void pop_front() {
        if (front_stack.empty()) {
            std::reverse(back_stack.begin(), back_stack.end());
            std::swap(front_stack, back_stack);
            back_prod.clear(), front_prod.clear();
            back_prod.emplace_back(e());
            front_prod.resize(front_stack.size() + 1);
            front_prod[0] = e();
            for (int i = 0; i < (int)front_stack.size(); ++i) {
                front_prod[i + 1] = op(front_stack[i], front_prod[i]);
            }
        }
        front_prod.pop_back(), front_stack.pop_back();
    }

    S fold() const { return op(front_prod.back(), back_prod.back()); }
};
};  // namespace kyopro