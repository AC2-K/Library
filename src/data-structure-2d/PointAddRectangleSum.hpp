#include "../data-structure/BIT.hpp"
namespace kyopro {
template <typename T, typename S>
class PointAddRectangleSum {
    std::vector<BIT<S>> dat;
    std::vector<std::vector<T>> ys;

    T n;
    std::vector<std::pair<T, T>> ps;

public:
    void add_point(T x, T y) { ps.emplace_back(x, y); }

    void build() {
        std::sort(ps.begin(), ps.end());
        ps.erase(std::unique(ps.begin(), ps.end()), ps.end());

        n = ps.size();
        dat.resize(2 * n);

        ys.resize(2 * n);
        for (int i = 0; i < n; ++i) {
            ys[i + n].emplace_back(ps[i].second);
            dat[i + n] = BIT<S>(1);
        }

        for (int i = n - 1; i > 0; --i) {
            ys[i].resize(ys[i << 1 | 0].size() + ys[i << 1 | 1].size());
            std::merge(ys[i << 1 | 0].begin(), ys[i << 1 | 0].end(),
                       ys[i << 1 | 1].begin(), ys[i << 1 | 1].end(),
                       ys[i].begin());

            ys[i].erase(std::unique(ys[i].begin(), ys[i].end()), ys[i].end());
            dat[i] = BIT<S>(ys[i].size());
        }
    }

    inline int id(T x) const {
        return std::lower_bound(
                   ps.begin(), ps.end(), std::make_pair(x, T()),
                   [](const std::pair<T, T>& a, const std::pair<T, T>& b) {
                       return a.first < b.first;
                   }) -
               ps.begin();
    }

    inline int id(int i, T y) const {
        return std::lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
    }

    void add(T x, T y, S w) {
        int i = std::lower_bound(ps.begin(), ps.end(), std::make_pair(x, y)) -
                ps.begin();

        for (i += n; i; i >>= 1) {
            dat[i].add(id(i, y), w);
        }
    }

    S sum(T xl, T yl, T xr, T yr) {
        S sum = 0;

        int a = id(xl), b = id(xr);
        a += n, b += n;
        while (a < b) {
            if (a & 1) {
                sum += dat[a].sum(id(a, yl), id(a, yr));
                ++a;
            }
            if (b & 1) {
                --b;
                sum += dat[b].sum(id(b, yl), id(b, yr));
            }

            a >>= 1, b >>= 1;
        }

        return sum;
    }
};
};  // namespace kyopro