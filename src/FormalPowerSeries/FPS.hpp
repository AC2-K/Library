#pragma once
#include <vector>
#include "../../src/atcoder/convolution.hpp"
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

    FPS pref(size_t sz) const {
        FPS g((*this).begin(), (*this).begin() + std::min(sz, this->size()));
        g.expand(sz);
        return g;
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
        return (*this);
    }
    FPS& operator/=(const mint& rhs) {
        for (int i = 0; i < (int)this->size(); ++i) {
            (*this)[i] /= rhs;
        }
        return (*this);
    }

    FPS operator+(const FPS& rhs) const { return FPS(*this) += rhs; }
    FPS operator-(const FPS& rhs) const { return FPS(*this) -= rhs; }
    FPS operator*(const FPS& rhs) const { return FPS(*this) *= rhs; }
    FPS operator+(const mint& rhs) const { return FPS(*this) += rhs; }
    FPS operator-(const mint& rhs) const { return FPS(*this) -= rhs; }
    FPS operator*(const mint& rhs) const { return FPS(*this) *= rhs; }
    FPS operator/(const mint& rhs) const { return FPS(*this) /= rhs; }

    // 積分
    FPS integral() const {
        FPS res(this->size() + 1);
        for (int i = 0; i < (int)this->size(); ++i) {
            res[i + 1] = (*this)[i] * mint(i + 1).inv();
        }
        return res;
    }

    // 微分
    FPS prime() const {
        FPS res(this->size() - 1);
        for (int i = 1; i < (int)this->size(); ++i) {
            res[i - 1] = (*this)[i] * mint::raw(i);
        }
        return res;
    }

    // 逆元
    FPS inv(size_t sz = -1) const {
        assert(!(*this).empty() && (*this)[0] != mint());
        if (sz == -1) sz = this->size();

        FPS g{mint(1) / (*this)[0]};
        for (int d = 1; d < sz; d <<= 1) {
            g = (g * 2 - g * g * (*this).pref(2 * d)).pref(2 * d);
        }

        return g.pref(sz);
    }

    FPS& operator/=(const FPS& rhs) { return (*this) *= rhs.inv(); }
    FPS operator/(const FPS& rhs) const { return FPS(*this) *= rhs.inv(); }

    FPS log(size_t sz = -1) const {
        assert(!(this->empty()) && (*this)[0].val() == 1);
        if (sz == -1) sz = this->size();
        return ((*this).prime() * (*this).inv(sz - 1)).pref(sz - 1).integral();
    };

    FPS exp(size_t sz = -1) const {
        assert(!(this->empty()) && (*this)[0].val() == 0);
        if (sz == -1) sz = this->size();

        FPS g{mint::raw(1)};
        for (int d = 1; d < sz; d <<= 1) {
            g = (g * (FPS{mint::raw(1)} - g.log(2 * d) + (*this).pref(2 * d)))
                    .pref(2 * d);
        }
        return g;
    }
};

};  // namespace kyopro