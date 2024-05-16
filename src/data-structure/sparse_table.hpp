#pragma once
#include <numeric>
#include <vector>
namespace kyopro {

template <class T, auto op> class sparse_table {
    std::vector<T> vec;
    std::vector<std::vector<T>> table;
    std::vector<int> lg;

public:
    constexpr sparse_table(int n) : vec(n) {}
    constexpr sparse_table(const std::vector<T>& vec) : vec(vec) { build(); }

    void set(int p, const T& v) { vec[p] = v; }
    void build() {
        int sz = vec.size();
        int log = 0;
        while ((1 << log) <= sz) {
            log++;
        }
        table.assign(log, std::vector<T>(1 << log));
        for (int i = 0; i < sz; i++) {
            table[0][i] = vec[i];
        }
        for (int i = 1; i < log; i++) {
            for (int j = 0; j + (1 << i) <= (1 << log); j++) {
                table[i][j] =
                    op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
        lg.resize(sz + 1);
        for (int i = 2; i < (int)lg.size(); i++) {
            lg[i] = lg[i >> 1] + 1;
        }
    }

    T fold(int l, int r) const {
        int b = lg[r - l];
        return op(table[b][l], table[b][r - (1 << b)]);
    }
};
};  // namespace kyopro

/**
 * @brief Sparse Table
 */