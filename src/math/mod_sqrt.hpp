#pragma once
#include "math/mod_log.hpp"
#include "math/primitive_root.hpp"

namespace kyopro {
/**
 * @brief 平方剰余(O(√p))
 * @note 遅い
 */
constexpr int mod_sqrt_lazy(int x, int p) {
    if (x == 0) return 0;
    if (p == 2) return x;
    int g = primitive_root(p);
    int e = mod_log(g, x, p);
    if (e % 2 != 0) {
        return -1;
    } else {
        return mod_pow(g, e / 2, p);
    }
}
};  // namespace kyopro