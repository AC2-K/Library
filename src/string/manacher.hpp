#pragma once
#include <cassert>
#include <string>
#include <utility>
#include <vector>
namespace kyopro {
std::vector<int> manacher(std::string s, bool even = true) {
    assert(s.size());
    if (even) {
        std::string t;
        t.resize(2 * (int)s.size() - 1);
        for (int i = 0; i < (int)s.size(); i++) {
            t[2 * i] = s[i];
        }
        for (int i = 0; i < (int)s.size(); i++) {
            t[2 * i + 1] = '$';
        }
        std::swap(t, s);
    }
    std::vector<int> res(s.size());

    int i = 0, j = 0;

    while (i < (int)s.size()) {
        while (i - j >= 0 && i + j < (int)s.size() && s[i - j] == s[i + j]) {
            j++;
        }
        res[i] = j;

        int k = 1;
        while (i - k >= 0 && i + k < (int)s.size() && k + res[i - k] < j) {
            res[i + k] = res[i - k], k++;
        }
        i += k, j -= k;
    }

    if (even) {
        for (int i = 0; i < (int)res.size(); i++) {
            if (~(i ^ res[i]) & 1) {
                res[i]--;
            }
        }
    } else {
        for (auto& r : res) {
            r = 2 * r - 1;
        }
    }
    return res;
}
};  // namespace kyopro


/**
 * @brief Manacher's algorithm
 */