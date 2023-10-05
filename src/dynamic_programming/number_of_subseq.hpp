#pragma once
#include <algorithm>
#include <vector>

namespace kyopro {
namespace number_of_subseq_impl {

template <typename T> void comp(std::vector<T>& a) {
    std::vector<T> tmp(a);
    std::sort(tmp.begin(), tmp.end());
    tmp.erase(std::unique(tmp.begin(),tmp.end()), tmp.end());
    for (int i = 0; i < (int)a.size(); ++i) {
        a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
    }
}

};  // namespace number_of_subseq_impl
 
/// @return Number of subsequence of a  (including empty sequence)
template <typename mint, typename T>
mint num_of_subseq(std::vector<T> a) {
    number_of_subseq_impl::comp(a);
    std::vector<mint> dp(a.size() + 1), sum(a.size() + 1);
    sum[0] = mint(1);
    for (int i = 0; i < (int)a.size(); ++i) {
        sum[i + 1] = 2 * sum[i] - dp[a[i]];
        dp[a[i]] += sum[i] - dp[a[i]];
    }
    return sum[a.size()];
}
};

/**
 * @brief 部分列の個数
 * @reference https://noshi91.hatenablog.com/entry/2023/02/26/135340
*/