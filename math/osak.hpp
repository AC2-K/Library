#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
namespace kyopro {
/// @brief Osak法
namespace Osak {
using u32 = uint32_t;
u32 limit;
std::vector<u32> factor;
void init(u32 lim) {
    limit = lim;
    factor.resize(lim + 1);
    std::iota(factor.begin(), factor.end(), 0);
    for (u32 i = 2; i * i <= limit; i++) {
        if (factor[i] != i) {
            continue;
        }
        for (int j = i; j <= limit; j += i) {
            factor[j] = i;
        }
    }
}
u32 find_factor(u32 n) {
    assert(1 <= n && n <= limit);
    return factor[n];
}
u32 is_prime(u32 n) {
    assert(1 <= n && n <= limit);
    return factor[n] == n;
}
std::vector<u32> factorize(u32 n) {
    assert(1 <= n && n <= limit);
    std::vector<u32> st;
    st.emplace_back(n);
    st.reserve((size_t)__builtin_clz(n) + 1);
    std::vector<u32> ans;
    ans.reserve((size_t)__builtin_clz(n) + 1);
    while (st.size()) {
        u32 m = st.back();
        if (m == 1) {
            st.pop_back();
            continue;
        }
        u32 d = find_factor(m);
        if (m == d) {
            ans.emplace_back(m);
            st.pop_back();
        } else {
            st.back() /= d;
            st.emplace_back(d);
        }
    }
    std::sort(ans.begin(), ans.end());
    return ans;
}
std::vector<std::pair<u32, u32>> exp_factorize(u32 n) {
    if (n < 2) {
        return {};
    }
    std::vector<std::pair<u32, u32>> res;
    auto pf = factorize(n);
    res.emplace_back(pf.front(), 1);
    for (int i = 1; i < pf.size(); i++) {
        if (res.back().first == pf[i]) {
            res.back().second++;
        } else {
            res.emplace_back(pf[i], 1);
        }
    }
    return res;
}
};  // namespace Osak
};  // namespace kyopro
