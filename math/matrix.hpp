#pragma once
template<typename T>
class Matrix {
    vector<vector<T>> dat;
    int h = 0, w = 0;

  public:
    Matrix(const vector<vector<T>>& dat)
        : dat(dat), h(dat.size()), w(dat.front().size()) {}

    Matrix(int h_, int w_, const T& v = T())
        : dat(h_, vector<T>(w_, v)){}
        
    using mat = Matrix<T>;
    //access
    vector<T>& operator[](int i) { return dat[i]; }

    //operator
    mat& operator+=(const mat& r) {
        assert(r.h == this->h);
        assert(r.w == this->w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dat[i][j] += r.dat[i][j];
            }
        }
        return (*this);
    }
    mat& operator-=(const mat&r){
        assert(r.h == this->h);
        assert(r.w == this->w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dat[i][j] -= r.dat[i][j];
            }
        }
        return (*this);
    }
    mat& operator*=(const mat& r) {
        int ha = dat.size(), wa = dat.front().size();
        int hb = r.dat.size(), wb = r.dat.front().size();
        assert(wa == hb);
     
        vector<vector<T>> res(ha, vector<T>(wb));
        rep(i, ha) rep(j, wb) rep(k, wa) { res[i][j] += dat[i][k] * r.dat[k][j]; }
     
        swap(res, dat);
        return (*this);
    }

    mat operator+(const mat& r) { return mat(*this) += r; }
    mat operator-(const mat& r) { return mat(*this) -= r; }
    mat operator*(const mat& r) { return mat(*this) *= r; }

    mat pow(__int64_t e) const {
        assert(e >= 0);
        int n = dat.size();
        mat res(n, n, 0);
        mat pr(*this);
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (e) {
            if (e & 1) res *= pr;
            pr *= pr;
            
            e >>= 1;
        }
        
        return res;
    }
};
/// @brief maxtirx(行列)
/// @docs