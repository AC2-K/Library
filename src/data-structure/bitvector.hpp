#pragma once

#include <cassert>
#include <cstdint>
#include <limits>
#include <numeric>
#include <vector>

namespace std {
template <typename bits = __uint128_t> class bitvec {
    using usize = std::size_t;

    const int dgt = std::numeric_limits<bits>::digits;

    usize size_;

    std::vector<bits> arr;

public:
    bitvec(usize size_) : size_(size_), arr((size_ + dgt - 1) / dgt) {}

    usize size() const { return size_; }

    void resize(usize size_) { this->size_ = size_; }

    bool at(usize p) const {
        assert(0 <= p && p < size());
        return arr[p / dgt] >> (p % dgt) & 1;
    }

    bool operator[](usize p) const { return at(p); }

    void set(usize p, bool f) {
        assert(0 <= p && p < size());

        if (f) {
            arr[p / dgt] |= (bits(1) << (p % dgt));
        } else {
            arr[p / dgt] &= ~(bits(1) << (p % dgt));
        }
    }

    bitvec& operator^=(const bitvec<bits>& rhs) {
        assert((*this).size() == rhs.size());
        assert((*this).arr.size() == rhs.arr.size());
        for (int i = 0; i < (int)(this->arr).size(); ++i) {
            this->arr[i] ^= rhs.arr[i];
        }
        return (*this);
    }
    bitvec& operator&=(const bitvec<bits>& rhs) {
        assert((*this).size() == rhs.size());
        assert((*this).arr.size() == rhs.arr.size());
        for (int i = 0; i < (int)(this->arr).size(); ++i) {
            this->arr[i] &= rhs.arr[i];
        }
        return (*this);
    }
    bitvec& operator|=(const bitvec<bits>& rhs) {
        assert((*this).size() == rhs.size());
        assert((*this).arr.size() == rhs.arr.size());

        for (int i = 0; i < (int)(this->arr).size(); ++i) {
            this->arr[i] |= rhs.arr[i];
        }
        return (*this);
    }

    void swap(bitvec<bits>& rhs) {
        std::swap(this->size_, rhs.size_);
        std::swap(this->arr, rhs.arr);
    }
};
};  // namespace std

/**
 * @brief bitvector
 */