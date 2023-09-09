#pragma once
#include <vector>
#include "../../atcoder/convolution.hpp"
namespace kyopro{


/**
 * @brief 形式的べき級数
 * @note mintはACLの方で渡すこと
*/
template <typename mint, atcoder::internal::is_modint_t<mint>* = nullptr>
struct FormalPowerSeries : public std::vector<mint> {
    using std::vector<mint>::vector;
    using FPS = FormalPowerSeries<mint>;

    void expand(size_t sz) {
        if (this->size() < sz) this->resize(sz);
    }
    
    void shrink() {
        while (!(*this).empty() && (*this).back() == mint()) (*this).pop_back();
    }
    
    FPS& operator+=(const FPS& rhs) {
        expand(rhs.size());
        for (int i = 0; i < (int)rhs.size(); ++i) (*this)[i] += rhs[i];
        return (*this);
    }
    
    FPS& operator-=(const FPS& rhs) {
        expand(rhs.size());
        for (int i = 0; i < (int)rhs.size(); ++i) (*this)[i] -= rhs[i];
        return (*this);
    }
    FPS& operator*=(const FPS& rhs) {
        shrink();
        std::vector res = atcoder::convolution<mint>(*this, rhs);
        (*this) = {res.begin(), res.end()};
        return (*this);
    }

    FPS& operator+=(const mint& rhs) {
        expand(1);
        (*this)[0] += rhs;
        return (*this);
    }
    FPS& operator-=(const mint& rhs) {
        expand(1);
        (*this)[0] -= rhs;
        return (*this);
    }
    FPS& operator*=(const mint& rhs) {
        for (int i = 0; i < (int)this->size(); ++i) {
            (*this)[i] *= rhs;
        }
    }
    FPS& operator/=(const mint& rhs) {
        for (int i = 0; i < (int)this->size(); ++i) {
            (*this)[i] /= rhs;
        }
    }

    FPS operator+(const FPS& rhs) const { return FPS(*this) += rhs; }
    FPS operator-(const FPS& rhs) const { return FPS(*this) -= rhs; }
    FPS operator*(const FPS& rhs) const { return FPS(*this) *= rhs; }
    FPS operator+(const mint& rhs) const { return FPS(*this) += rhs; }
    FPS operator-(const mint& rhs) const { return FPS(*this) -= rhs; }
    FPS operator*(const mint& rhs) const { return FPS(*this) *= rhs; }
    FPS operator/(const mint& rhs) const { return FPS(*this) /= rhs; }

    friend FPS operator*(const mint& lhs, const FPS& rhs) {
        return FPS(rhs) *= lhs;
    }
};

};  // namespace kyopro