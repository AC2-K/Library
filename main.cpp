#pragma once
#include <cassert>
#include <string>
#include <vector>
namespace kyopro {
/// @brief Z algorithm
/// @return LCP(S,S[i:]) (i=0,1,...,|str|-1)
std::vector<int> Z(const std::string& str) {
    assert(str.size());
    std::vector<int> res(str.size());
    res.front() = (int)str.size();

    int i = 1, j = 0;

    while (i < (int)str.size()) {
        while (i + j < (int)str.size() && str[j] == str[i + j]) {
            j++;
        }

        res[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (i + k < (int)str.size() && k + res[k] < j) {
            res[i + k] = res[k];
            k++;
        }
        i += k, j -= k;
    }
    return res;
}
};  // namespace kyopro