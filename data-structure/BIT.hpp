/// @brief Binary Index Tree
/// @tparam Type 要素の型
/// @tparam SumType "和が" 収まるような型
/// @docs docs/data-structure/BIT.md
template <typename Type, typename SumType = Type>
class BIT {
    int _n;
    vector<SumType> _dat;
public:
    explicit BIT(int _n) : _n(_n), _dat(_n, SumType()) {}

    inline void add(int p, Type v) {
        p++;
        for (; p <= _n; p += p & (-p)) {
            _dat[p - 1] += SumType(v);
        }
    }

    inline SumType sum(int p) {
        SumType res = 0;
        for (; p > 0; p -= p & -p) {
            res += _dat[p - 1];
        }
        return res;
    }

    inline SumType sum(int l, int r) { return sum(r) - sum(l); }
};
