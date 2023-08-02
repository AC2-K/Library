#pragma once
#include "../atcoder/convolution"
#include "../atcoder/modint"
#include <string>
#include <vector>
#include<algorithm>
#include "../random/xor_shift.hpp"

namespace kyopro {
std::vector<bool> wildcard_pattern_matching(const std::string& s,
                                            const std::string& t,
                                            char wild_card) {
    assert(s.size() >= t.size());
    using mint = atcoder::modint998244353;
    
    // 各文字にハッシュを割り当てる(ワイルドカードにのみ0を割り当てる
    
    static xor_shift32 rng;
    static int d = rng();
    
    auto to_integer = [&](char v) -> mint {
        return (v == wild_card ? mint() : mint(v + d));
    };

    std::vector<mint> sv(s.size()), tv(t.size());
    for (int i = 0; i < (int)s.size(); ++i) sv[i] = to_integer(s[i]);
    for (int i = 0; i < (int)t.size(); ++i) tv[i] = to_integer(t[i]);

    // 畳み込みでマッチを計算する
    std::reverse(tv.begin(), tv.end());

    std::vector<mint> conv1;
    {
        std::vector<mint> s3 = sv;
        for (auto& s3i : s3) s3i = s3i * s3i * s3i;
        conv1 = atcoder::convolution(s3, tv);
    }
    std::vector<mint> conv2;
    {
        std::vector<mint> t3 = tv;
        for (auto& t3i : t3) t3i = t3i * t3i * t3i;
        conv2 = atcoder::convolution(sv, t3);
    }

    std::vector<mint> conv3;
    {
        std::vector<mint> s2 = sv, t2 = tv;
        for (auto& s2i : s2) s2i *= s2i;
        for (auto& t2i : t2) t2i *= t2i;

        conv3 = atcoder::convolution(s2, t2);
    }
    std::vector<bool> ans(s.size() - t.size() + 1);
    for (int i = 0; i < (int)ans.size(); ++i) {
        ans[i] = (conv1[i + t.size() - 1] + conv2[i + t.size() - 1] -
                      2 * conv3[i + t.size() - 1] ==
                  mint(0));
    }
    return ans;
}

};  // namespace kyopro

/**
 * @brief WildCard Pattern Matching
 * @docs docs/string/wildcard_pattern_matching.md
 */
