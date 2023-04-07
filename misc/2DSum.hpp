#pragma once
#include<vector>
/// @brief 2次元累積和
/// @tparam T 重みの型
template<typename T>
class Sum2D {
	std::vector<std::vector<T>> dat;
	std::vector<std::vector<T>> s;
public:
	const int h;
	const int w;
	
	Sum2D(int h, int w) :h(h), w(w), dat(h, std::vector<T>(w, T())), s(h + 1, std::vector<T>(w + 1, T())) {}
	inline void build() {
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + dat[i][j];
			}
		}
	}
	inline T sum(int i1, int j1, int i2, int j2) {
		return s[i2][j2] - s[i1][j2] - s[i2][j1] + s[i1][j1];
	}

	inline std::vector<T>& operator[](int i) { return dat[i]; }
};

/// @brief 二次元imos法
/// @tparam T 重みの型
template<typename T>
class Imos2D {
	Sum2D<T> d;
public:
	const int h;
	const int w;

	Imos2D(int h, int w) :h(h), w(w), d(h + 1, w + 1) {}
	inline void add(int i1, int j1, int i2, int j2, const T& v) {
		d[i1][j1] += v, d[i2][j2] += v;
		d[i1][j2] -= v, d[i2][j1] -= v;
	}
	inline T at(int i, int j) { return d.sum(0, 0, i + 1, j + 1); }

	inline void build() { d.build(); }
};