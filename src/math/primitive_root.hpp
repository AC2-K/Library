#pragma once
#include "../math/dynamic_modint.hpp"
#include "../math/rho.hpp"
#include "../random/xor_shift.hpp"
namespace kyopro {

/**
 * @brief 原始根
 */
template<typename T>
T primitive_root(T p) {
    if (p == 2) return 1;

    auto pf = kyopro::rho::factorize(p - 1);
    pf.erase(std::unique(pf.begin(), pf.end()), pf.end());
    for (auto& q : pf) {
        q = (p - 1) / q;
    }
    
    if (dynamic_modint<uint64_t>::mod() != p) {
        dynamic_modint<uint64_t>::set_mod(p);
    }

    for (int g_ = 1; ; ++g_) {
        dynamic_modint<uint64_t> g(g_);
        if (g.val() == 0) continue;
        bool is_ok = true;

        for (auto q : pf) {
            if (g.pow(q).val() == 1) {
                is_ok = false;
                break;
            }
        }

        if (is_ok) {
            return g_;
        }
    }
}
};  // namespace kyopro