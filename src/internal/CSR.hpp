#pragma once

#include <cassert>
#include <iterator>
#include <utility>
#include <vector>

namespace kyopro {
namespace internal {

template <typename T, typename _size_t> class csr {
    _size_t n;
    std::vector<T> d;
    std::vector<_size_t> ssum;

public:
    csr() = default;
    csr(_size_t n, const std::vector<std::pair<_size_t, T>>& v)
        : n(n), ssum(n + 1), d(v.size()) {
        for (int i = 0; i < (int)v.size(); ++i) {
            ++ssum[v[i].first + 1];
        }
        for (int i = 0; i < n; ++i) {
            ssum[i + 1] += ssum[i];
        }

        std::vector cnt = ssum;
        for (auto e : v) d[cnt[e.first]++] = e.second;
    }

    struct vector_range {
        using iterator = typename std::vector<T>::iterator;
        iterator l, r;

        iterator begin() const { return l; }
        iterator end() const { return r; }
        _size_t size() { return std::distance(l, r); }
        T& operator[](_size_t i) const { return l[i]; }
    };
    struct const_vector_range {
        using const_iterator = typename std::vector<T>::const_iterator;
        const_iterator l, r;

        const_iterator begin() const { return l; }
        const_iterator end() const { return r; }
        _size_t size() { return (_size_t)std::distance(l, r); }
        const T& operator[](_size_t i) const { return l[i]; }
    };

    vector_range operator[](_size_t i) {
        return vector_range{d.begin() + ssum[i], d.begin() + ssum[i + 1]};
    }
    const_vector_range operator[](_size_t i) const {
        return const_vector_range{d.begin() + ssum[i], d.begin() + ssum[i + 1]};
    }

    _size_t size() const { return (_size_t)n; }
};
};  // namespace internal
};  // namespace kyopro

/**
 * @brief CSR形式(二次元ベクトルの圧縮)
 */