#pragma once
#include "../math/dynamic_modint.hpp"
#include "../math/rho.hpp"
#include "../random/xor_shift.hpp"
namespace kyopro {

/**
 * @brief 原始根
 */
inline uint64_t primitive_root(uint64_t p) {
    if (p == 2) return 1;
    auto pf = kyopro::rho::factorize(p - 1);
    pf.erase(std::unique(pf.begin(), pf.end()), pf.end());
    for (auto& q : pf) {
        q = (p - 1) / q;
    }
    using ull = unsigned long long;
    if (dynamic_modint<uint64_t>::get_mod() != p) {
        dynamic_modint<uint64_t>::set_mod(p);
    }
    xor_shift rng(2023);
    while (1) {
        dynamic_modint<uint64_t> g(rng());
        if (g.val() == 0) continue;
        bool is_ok = true;

        for (const auto& q : pf) {
            if (dynamic_modint<uint64_t>(g).pow(q).val() == 1) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) {
            return g.val();
        }
    }
}
};  // namespace kyopro