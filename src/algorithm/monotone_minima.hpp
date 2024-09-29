#pragma once
#include <utility>
#include <vector>
namespace kyopro {

/// @note f must be monotone
/// @returns vector of (idx, minimum)
template <typename T, typename F>
std::vector<std::pair<std::size_t, T>> monotone_minima(std::size_t h,
                                                       std::size_t w,
                                                       const F& f) {
    using usize = std::size_t;
    std::vector<std::pair<usize, T>> res(h);

    const auto calc = [&](const auto& calc, usize top, usize bottom, usize l,
                          usize r) -> void {
        if (top >= bottom) return;

        usize mid = (top + bottom) / 2;

        T mn = f(mid, l);
        usize idx = l;
        for (usize i = l + 1; i < r; ++i) {
            T val = f(mid, i);
            if (mn > val) {
                mn = val;
                idx = i;
            }
        }

        res[mid] = std::pair(idx, mn);
        calc(calc, top, mid, l, idx + 1);
        calc(calc, mid + 1, bottom, idx, r);
    };
    calc(calc, 0, h, 0, w);

    return res;
}
};  // namespace kyopro

/**
 * @brief Monotone Minima
*/