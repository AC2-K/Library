#pragma once
#include "../algorithm/subset_zeta.hpp"
#include "../algorithm/subset_mobius.hpp"

namespace kyopro {

/**
 * @brief or plus convolution
 * @param n a,b : 2^[n] → T, |a| = |b| = 2^n
 * @return convolution
 */
template <typename T>
std::vector<T> or_plus_convolution(int n, std::vector<T> a, std::vector<T> b) {
    zeta(n, a), zeta(n, b);
    for (int i = 0; i < (int)a.size(); ++i) a[i] *= b[i];
    mobius(n, a);
    return a;
}
};