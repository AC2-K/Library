#include<vector>

namespace kyopro {
namespace number_of_subseq_impl {

template <typename T> void comp(vector<T>& a) {
    vector<T> tmp(a);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(all(tmp)), tmp.end());
    for (int i = 0; i < (int)a.size(); ++i) {
        a[i] = lower_bound(all(tmp), a[i]) - tmp.begin();
    }
}

};  // namespace number_of_subseq_impl
 
/// @return Number of subsequence of a  (including empty sequence)
template <typename mint, typename T>
mint num_of_subseq(std::vector<T> a) {
    number_of_subseq_impl::comp(a);
    sum[0] = mint::(1);
    rep(i, n) {
        sum[i + 1] = 2 * sum[i] - dp[a[i]];
        dp[a[i]] += sum[i] - dp[a[i]];
    }
    return sum[n];
}
};

/**
 * @brief 部分列の個数
 * @reference https://noshi91.hatenablog.com/entry/2023/02/26/135340
*/