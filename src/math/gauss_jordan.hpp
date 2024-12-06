#pragma once

#include <bitset>
#include <cassert>
#include <utility>
#include <vector>

#include "../../src/data-structure/bitvector.hpp"

namespace kyopro {

/// @return rank of a
template <typename Container>
int gauss_jordan(int n, int m, std::vector<Container>& a) {
    int rank = 0;

    for (int j = 0; j < m && rank < n; ++j) {
        int pivot = -1;

        for (int i = rank; i < n; ++i) {
            if (a[i][j]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) continue;

        a[rank].swap(a[pivot]);

        for (int i = 0; i < n; ++i) {
            if (i != rank) {
                if (a[i][j]) {
                    a[i] ^= a[rank];
                }
            }
        }

        ++rank;
    }
    return rank;
}
};  // namespace kyopro

/**
 * @brief Gauss Jordanの掃き出し法
 */