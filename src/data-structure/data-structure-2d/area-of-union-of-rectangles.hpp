#pragma once
#include <algorithm>
#include <tuple>
#include <utility>
#include "data-structure/lazy_segtree.hpp"
namespace kyopro {
template <typename T> class area_of_union_of_rectangles {
    struct dat {
        int min_val;
        T min_width;

        dat() = default;
        dat(int min_val, T min_width)
            : min_val(min_val), min_width(min_width) {}
    };

    static constexpr dat op(dat x, dat y) {
        if (x.min_val < y.min_val) {
            return x;
        } else if (x.min_val > y.min_val) {
            return y;
        } else {
            return dat(x.min_val, x.min_width + y.min_width);
        }
    }
    static constexpr dat e() { return dat(int(1e9), 0); }

    static constexpr int composition(int x, int y) { return x + y; }
    static constexpr int id() { return 0; }

    static constexpr dat mapping(dat x, int y) {
        return dat(x.min_val + y, x.min_width);
    }

    std::vector<T> xs, ys;
    std::vector<std::tuple<T, T, T, int>> qs;

public:
    void add(T xl, T xr, T yl, T yr) {
        xs.emplace_back(xl), xs.emplace_back(xr);
        ys.emplace_back(yl), ys.emplace_back(yr);
        qs.emplace_back(xl, yl, yr, 1);
        qs.emplace_back(xr, yl, yr, -1);
    }

    T calc() {
        std::sort(xs.begin(), xs.end()),
            xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        std::sort(ys.begin(), ys.end()),
            ys.erase(std::unique(ys.begin(), ys.end()), ys.end());

        std::sort(qs.begin(), qs.end());

        for (auto& [x, yl, yr, v] : qs) {
            yl = std::lower_bound(ys.begin(), ys.end(), yl) - ys.begin();
            yr = std::lower_bound(ys.begin(), ys.end(), yr) - ys.begin();
        }

        lazy_segtree<dat, int, area_of_union_of_rectangles::op,
                     area_of_union_of_rectangles::e,
                     area_of_union_of_rectangles::composition,
                     area_of_union_of_rectangles::id,
                     area_of_union_of_rectangles::mapping>
            sg((int)ys.size());
        for (int i = 0; i < (int)ys.size() - 1; ++i) {
            sg.set(i, dat{0, ys[i + 1] - ys[i]});
        }
        sg.build();

        T ans = 0;
        for (int i = 0, j = 0; i < (int)xs.size() - 1; ++i) {
            while (j < (int)qs.size() && std::get<0>(qs[j]) <= xs[i]) {
                auto [x, yl, yr, v] = qs[j];
                sg.apply(yl, yr, v);
                ++j;
            }

            ans += T(xs[i + 1] - xs[i]) * (ys.back() - ys[0]);

            auto [v, w] = sg.fold(0, (int)ys.size() - 1);
            if (v == 0) {
                ans -= T(xs[i + 1] - xs[i]) * w;
            }
        }
        return ans;
    }
};
};  // namespace kyopro