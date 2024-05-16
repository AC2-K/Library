#pragma once
#include <vector>

namespace kyopro {
namespace internal {

template <typename T> void add(std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() < b.size()) a.resize(b.size());
    for (int i = 0; i < (int)b.size(); ++i) a[i] += b[i];
}
template <typename T> void sub(std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() < b.size()) a.resize(b.size());
    for (int i = 0; i < (int)b.size(); ++i) a[i] -= b[i];
}

template <typename T> void ranked_zeta(int n, std::vector<std::vector<T>>& a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)a.size(); ++j) {
            if (j >> i & 1) add(a[j], a[j & ~(1 << i)]);
        }
    }
}
template <typename T>
void ranked_mobius(int n, std::vector<std::vector<T>>& a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)a.size(); ++j) {
            if (j >> i & 1) sub(a[j], a[j & ~(1 << i)]);
        }
    }
}
};  // namespace internal


/**
 * @brief Subset Convolution
 */
template <typename T>
std::vector<T> subset_convolution(int n, std::vector<T> a, std::vector<T> b) {
    std::vector<std::vector<T>> ranked_a(a.size()), ranked_b(b.size());
    for (int i = 0; i < (1 << n); ++i) {
        ranked_a[i].resize(__builtin_popcount(i) + 1);
        ranked_b[i].resize(__builtin_popcount(i) + 1);

        ranked_a[i][__builtin_popcount(i)] = a[i];
        ranked_b[i][__builtin_popcount(i)] = b[i];
    }

    internal::ranked_zeta(n, ranked_a), internal::ranked_zeta(n, ranked_b);
    for (int i = 0; i < (1 << n); ++i) {
        std::vector<T> c(ranked_a[i].size() + ranked_b[i].size());
        for (int j = 0; j < (int)ranked_b[i].size(); ++j) {
            for (int k = 0; k < (int)ranked_b[i].size(); ++k) {
                c[j + k] += ranked_a[i][j] * ranked_b[i][k];
            }
        }
        swap(ranked_a[i], c);
    }

    internal::ranked_mobius(n, ranked_a);
    std::vector<T> answer(a.size());
    for (int i = 0; i < (int)a.size(); ++i) {
        answer[i] = ranked_a[i][__builtin_popcount(i)];
    }
    return answer;
}
};  // namespace kyopro
