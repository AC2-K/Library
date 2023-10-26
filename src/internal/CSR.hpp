#pragma once

#include <cassert>
#include <utility>
#include <vector>
#include <iterator>

namespace kyopro {
namespace internal {

template <typename T> class CSR {
    using usize = std::size_t;

    const usize n;
    std::vector<std::vector<T>> mat;
    std::vector<T> csr;
    std::vector<usize> ssum;

public:
    class range {
        const typename std::vector<T>::iterator l, r;

    public:
        range(const typename std::vector<T>::iterator& l,
              const typename std::vector<T>::iterator& r)
            : l(l), r(r){}
        typename std::vector<T>::iterator begin() { return l; }
        typename std::vector<T>::iterator end() { return r; }
    };

    CSR(usize n) : n(n), mat(n), csr(), ssum(n + 1) {}
    CSR(const std::vector<std::vector<T>>& mat) : mat(mat) {}
    
    void add(usize a, T b) {
        assert(0 <= a && a < n);
        mat[a].emplace_back(b);
    }
    void build() {
        for (int i = 0; i < n; ++i) ssum[i + 1] += ssum[i] + mat[i].size();
        csr.reserve(ssum.back());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)mat[i].size(); ++j) {
                csr.emplace_back(mat[i][j]);
            }
        }
        mat.clear();
    }

    const range operator[](usize x) const {
        assert(0 <= x && x < n);
        return range(csr.begin() + ssum[x], csr.begin() + ssum[x + 1]);
    }
};
};  // namespace internal
};  // namespace kyopro


/**
 * @brief CSR形式
 */