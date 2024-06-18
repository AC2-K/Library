#pragma once
#include"../../src/FormalPowerSeries/FPS.hpp"
#include"../../src/internal/type_traits.hpp"

namespace kyopro {

template <typename T,
          internal::is_integral_t<T>* = nullptr,
          typename mint,
          atcoder::internal::is_modint_t<mint>* = nullptr>
mint BostanMori(T n,
                const FormalPowerSeries<mint>& P,
                const FormalPowerSeries<mint>& Q) {
    assert(n >= 0);
    assert(!P.empty() && !Q.empty());

    if (n == 0) return P[0] / Q[0];

    FormalPowerSeries Q2(Q);
    for (int i = 1; i < (int)Q2.size(); i += 2) Q2[i] = -Q2[i];

    FormalPowerSeries V = Q * Q2;
    for (int i = 0; 2 * i < (int)V.size(); ++i) {
        V[i] = V[2 * i];
    }
    V.resize(V.size() / 2 + 1);

    FormalPowerSeries PQ = P * Q2;

    if (n % 2 == 0) {
        FormalPowerSeries<mint> E((PQ.size() + 1) / 2);
        
        for (int i = 0; i < (int)E.size(); ++i) {
            E[i] = PQ[2 * i];
        }

        if(E.empty()) return mint();

        return BostanMori(n / 2, E, V);
    } else {
        FormalPowerSeries<mint> O(PQ.size() / 2);

        for (int i = 0; i < (int)O.size(); ++i) {
            O[i] = PQ[2 * i + 1];
        }
        
        if(O.empty()) return mint();

        return BostanMori(n / 2, O, V);
    }
}

template <typename T,
          internal::is_integral_t<T>* = nullptr,
          typename mint,
          atcoder::internal::is_modint_t<mint>* = nullptr>
mint NthTermOfLinearlyRecurrentSequence(T n,
                                const std::vector<mint>& ainit,
                                const std::vector<mint>& c) {
    FormalPowerSeries<mint> a =
        FormalPowerSeries<mint>(ainit) * FormalPowerSeries<mint>(c);
    
    a.resize(ainit.size());
    return BostanMori(n, a, FormalPowerSeries<mint>(c));
}
};

/**
 * @brief Bostan-Mori法(線形漸化式の高速計算)
 * @docs docs/FormalPowerSeries/BostanMori.md
 */