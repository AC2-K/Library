#pragma once
#include <vector>
#include "../../src/atcoder/convolution.hpp"
namespace kyopro{

template <typename mint, atcoder::internal::is_modint_t<mint>* = nullptr>
struct FormalPowerSeries : public std::vector<mint> {
    using std::vector<mint>::vector;
    using FPS = FormalPowerSeries<mint>;

    void expand(size_t sz) {
        if (this->size() < sz) this->resize(sz);
    }

    void shrink() {
        while (!(*this).empty() && (*this).back().val() == 0) (*this).pop_back();
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
        const mint invr = rhs.inv();
        for (int i = 0; i < (int)this->size(); ++i) {
            (*this)[i] *= invr;
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
    FPS operator>>(int sz) const {
        if ((int)this->size() <= sz) return {};
        FPS ret(*this);
        ret.erase(ret.begin(), ret.begin() + sz);
        return ret;
    }
    FPS operator<<(int sz) const {
        FPS ret(*this);
        ret.insert(ret.begin(), sz, mint(0));
        return ret;
    }

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

    FPS pow(long long e, size_t sz = -1) const {
        if (sz == -1) sz = this->size();
        if (e == 0) {
            FPS res(sz);
            if (sz) res[0] = mint::raw(1);
            return res;
        }

        int p = 0;
        while (p < (int)this->size() && (*this)[p].val() == 0) ++p;

        if (__int128_t(p) * e >= sz) {
            return FPS(sz);
        }

        mint vp = (*this)[p];
        FPS f = (*this >> p);
        f /= vp;
        f = (f.log(sz) * e).exp(sz);
        f *= vp.pow(e);
        f = (f << (p * e)).pref(sz);
        f.expand(sz);
        return f;
    }
};

};  // namespace kyopro

/**
 * @brief Formal Power Series(形式的べき級数)
*/