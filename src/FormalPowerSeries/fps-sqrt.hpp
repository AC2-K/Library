#pragma once
#include "../FormalPowerSeries/FPS.hpp"
#include "../math/mod_sqrt.hpp"

namespace kyopro {
/**
 * @brief Sqrt of FPS
 */
template <typename mint>
FormalPowerSeries<mint> fps_sqrt(const FormalPowerSeries<mint>& f,
                                 int deg = -1LL) {
    if (f.empty()) return FormalPowerSeries<mint>{};

    if (deg == -1) deg = f.size();

    int g0 = mod_sqrt_lazy(f[0].val(), mint::mod());

    if (g0 == 0) {
        for (int i = 1; i < (int)f.size(); ++i) {
            if (f[i] == mint()) continue;

            if (i & 1) return FormalPowerSeries<mint>{};

            FormalPowerSeries<mint> g = fps_sqrt(
                FormalPowerSeries<mint>{f.begin() + i, f.end()}, deg - i / 2);
            if (g.empty()) return FormalPowerSeries<mint>{};
            g.resize(g.size() + i / 2);
            for (int j = g.size() - 1; j >= i / 2; --j) g[j] = g[j - i / 2];
            for (int j = 0; j < i / 2; ++j) g[j] = 0;
            if (g.size() < deg) g.resize(deg);

            return g;
        }
        return f;
    }
    if (g0 == -1) return FormalPowerSeries<mint>{};

    const mint inv2 = mint::raw(2).inv();

    FormalPowerSeries<mint> g{mint::raw(g0)};

    for (long long n = 1; n < deg; n <<= 1) {
        g = g + f.pref(2 * n) * g.inv(2 * n);
        for (int j = 0; j < (int)g.size(); ++j) g[j] *= inv2;
    }

    return g.pref(deg);
}
};  // namespace kyopro