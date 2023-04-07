#pragma once
#include <vector>
/// @brief Binary Index Tree
/// @docs docs/data-structure/BIT.md
template<typename T,typename SumT = T>
class BIT {
	std::vector<SumT> bit;
	int n;
public:
    BIT(int n) :n(n), bit(n + 1, T()) {}
	void add(int p, const T& w) {
		p++;
		for (int x = p; x <= n; x += x & -x) {
			bit[x] += w;
		}
	}

	SumT sum(int p)const {
		T s = 0;

		for (int x = p; x > 0; x -= x & -x) {
			s += bit[x];
		}
		return s;
	}

	SumT sum(int l, int r)const {
		return sum(r) - sum(l);
	}

    
    int lower_bound(SumT w)const {
        if (w <= 0)return 0;

        int x = 0;
        int k = 1;
        while (k < n)k <<= 1;
        for (; k > 0; k >>= 1) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }

        return x + 1;
    }
}; 