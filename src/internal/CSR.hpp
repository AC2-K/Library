#pragma once

#include <cassert>
#include <utility>
#include <vector>
#include <iterator>

namespace kyopro {
namespace internal {

template <typename T> class CSR {
    using usize = std::size_t;

    const usize _size;
    std::vector<T> csr;
    std::vector<usize> ssum;

public:
    class range {
        const typename std::vector<T>::iterator l, r;

    public:
        range(const typename std::vector<T>::iterator& l,
              const typename std::vector<T>::iterator& r)
            : l(l), r(r){}
        typename std::vector<T>::iterator begin() const noexcept { return l; }
        typename std::vector<T>::iterator end() const noexcept { return r; }
    };
    
    CSR(const std::vector<std::vector<T>>& mat) : _size(mat.size()) {
        for (int i = 0; i < _size; ++i) ssum[i + 1] = ssum[i] + mat[i].size();
        csr.reserve(ssum.back());
        for (int i = 0; i < (int)_size; ++i) {
            for (int j = 0; j < (int)mat[i].size(); ++j) {
                csr.emplace_back(std::move(mat[i][j]));
            }
        }
        mat.clear();
    }
    usize size() const noexcept { return _size; }

    range operator[](usize x) {
        assert(0 <= x && x < _size);
        return range(csr.begin() + ssum[x], csr.begin() + ssum[x + 1]);
    }
};
};  // namespace internal
};  // namespace kyopro


/**
 * @brief CSR形式
 */