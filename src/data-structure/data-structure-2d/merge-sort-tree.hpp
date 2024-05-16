#pragma once
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>

namespace kyopro {
template <typename Key_x, typename Key_y, typename Value>
class merge_sort_tree {
    int lg, sz;

    struct point {
        Key_x x;
        Key_y y;
        Value v;
        point(Key_x x, Key_y y, Value v) : x(x), y(y), v(v) {}
    };

    std::vector<Key_x> xs;
    std::vector<std::vector<Key_y>> ys;  // x 固定したときの (y, value)
    std::vector<std::vector<Value>> s;   // 累積和

    std::vector<point> points;

public:
    merge_sort_tree() = default;

    void add_point(Key_x x, Key_y y, Value v) { points.emplace_back(x, y, v); }

    void build() {
        xs.resize(points.size());
        for (int i = 0; i < (int)points.size(); ++i) xs[i] = points[i].x;

        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

        sz = 1, lg = 0;
        while (sz <= (int)xs.size()) {
            sz <<= 1;
            lg++;
        }

        std::vector<std::vector<std::pair<Key_y, Value>>> d(sz << 1);
        s.resize(sz << 1), ys.resize(sz << 1);

        for (int i = 0; i < (int)points.size(); i++) {
            int p = std::lower_bound(xs.begin(), xs.end(), points[i].x) -
                    xs.begin();
            d[sz + p].emplace_back(points[i].y, points[i].v);
        }

        for (int i = 0; i < sz; ++i) {
            std::sort(d[i + sz].begin(), d[i + sz].end());
        }

        for (int i = sz - 1; i; --i) {
            int l = (i << 1 | 0), r = (i << 1 | 1);

            std::merge(d[l].begin(), d[l].end(), d[r].begin(), d[r].end(),
                       std::back_inserter(d[i]));
        }

        for (int i = 1; i < (int)2 * sz; ++i) {
            ys[i].resize(d[i].size());
            s[i].resize(d[i].size() + 1);

            for (int j = 0; j < (int)d[i].size(); ++j) {
                ys[i][j] = d[i][j].first;
                s[i][j + 1] = s[i][j] + d[i][j].second;
            }
        }
    }

private:
    Value get(int i, Key_y lower, Key_y upper) {
        int l =
            std::lower_bound(ys[i].begin(), ys[i].end(), lower) - ys[i].begin();
        int r =
            std::lower_bound(ys[i].begin(), ys[i].end(), upper) - ys[i].begin();

        return s[i][r] - s[i][l];
    }

public:
    Value fold(Key_x l, Key_y r, Key_y lower, Key_y upper) {
        l = std::lower_bound(xs.begin(), xs.end(), l) - xs.begin();
        r = std::lower_bound(xs.begin(), xs.end(), r) - xs.begin();

        l += sz, r += sz;

        Value sum = 0;

        while (l != r) {
            if (l & 1) {
                sum += get(l++, lower, upper);
            }
            if (r & 1) {
                sum += get(--r, lower, upper);
            }
            l >>= 1, r >>= 1;
        }

        return sum;
    }
};
};  // namespace kyopro

/**
 * @brief Merge Sort Tree
*/