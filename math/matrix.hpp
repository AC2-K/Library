#pragma once
template<typename T>
class Matrix {
    vector<vector<T>> dat;
    int h, w;
public:
    Matrix(const vector<vector<T>>& dat)
        : dat(dat), h(dat.size()), w(dat.front().size()) {}

    Matrix(int h_, int w_, const T& v = T())
        : dat(h_, vector<T>(w_, v)){}
    static Matrix<T> I(int sz) {
        Matrix<T> ans(sz);
        rep(i, sz) { ans[i][i] = 1; }
        return ans;
    }
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
        rep(i, ha) rep(j, wb) rep(k, wa) {
            res[i][j] += dat[i][k] * r.dat[k][j];
        }
        swap(res, dat);
        return (*this);
    }

    mat operator+(const mat& r) { return mat(*this) += r; }
    mat operator-(const mat& r) { return mat(*this) -= r; }
    mat operator*(const mat& r) { return mat(*this) *= r; }

    mat pow(__uint64_t e) const {
        mat pr=I(this->h);
        mat pw(*this);

        while(e){
            if(e&1){
                pw *= pw;
            }
            pw *= pw;
            e >>= 1;
        }
        return pr;
    }
};
