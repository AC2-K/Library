#pragma once
#include "../algorithm/subset_transform.hpp"

namespace kyopro {

/**
 * @brief Bitwise Or Convolution
 */
template <typename T>
std::vector<T> bitwise_or_convolution(int n, std::vector<T> a, std::vector<T> b) {
    zeta(n, a), zeta(n, b);
    for (int i = 0; i < (int)a.size(); ++i) a[i] *= b[i];
    mobius(n, a);
    return a;
}

};