#pragma once
#include "../math/dynamic_modint.hpp"
#include "../math/rho.hpp"
#include "../random/xor_shift.hpp"
namespace kyopro {

/**
 * @brief 原始根
 */
template<typename T>
long long primitive_root(T p) {
    if (p == 2) return 1;

    auto pf = kyopro::rho::factorize(p - 1);
    pf.erase(std::unique(pf.begin(), pf.end()), pf.end());
    for (auto& q : pf) {
        q = (p - 1) / q;
    }
    
    if (montgomery_modint<uint64_t>::mod() != p) {
        montgomery_modint<uint64_t>::set_mod(p);
    }

    xor_shift32 rng(619);
    while(1) {
        montgomery_modint<uint64_t> g(rng());
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
}
};  // namespace kyopro