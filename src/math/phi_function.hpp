#pragma once
#include <algorithm>
#include "../math/rho.hpp"
namespace kyopro {

/**
 * @brief Eulerの $\phi$ 関数
*/
inline long long phi_func(long long n) {
    long long res = n;
    auto pf = kyopro::rho::factorize(n);
    pf.erase(std::unique(pf.begin(), pf.end()), pf.end());
    for (auto d : pf) {
        res = res / d * (d - 1);
    }
    return res;
}
};  // namespace kyopro