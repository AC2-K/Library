#pragma once
#include "../math/dynamic_modint.hpp"
#include "../math/rho.hpp"
namespace kyopro {

/**
 * @brief 原始根
 */
template <typename T> constexpr T primitive_root(T p) noexcept {
    if (p == 2) return 1;

    auto pf = kyopro::rho::factorize(p - 1);
    pf.erase(std::unique(pf.begin(), pf.end()), pf.end());
    for (auto& q : pf) {
        q = (p - 1) / q;
    }

    using mint =
        std::conditional_t<std::numeric_limits<T>::digits <= 32,
                           barrett_modint<-1>, montgomery_modint<uint64_t>>;
    if (mint::mod() != p) {
        mint::set_mod(p);
    }

    for (int _g = 1;; ++_g) {
        mint g(_g);
        if (g.val() == 0) continue;
        bool is_ok = true;

        for (auto q : pf) {
            if (g.pow(q).val() == 1) {
                is_ok = false;
                break;
            }
        }

        if (is_ok) {
            return g.val();
        }
    }
    return -1;
}
};  // namespace kyopro