template<class T>
class sparse_table {
    vector<vector<T>> table;
    vector<int> look_up;
public:
    sparse_table(const vector<T>& vec = {}) {
        int sz = vec.size();
        int log = 0;
        while ((1 << log) <= sz) {
            log++;
        }
        table.assign(log, vector<T>(1 << log));
        for (int i = 0; i < sz; i++) {
            table[0][i] = vec[i];
        }
        for (int i = 1; i < log; i++) {
            for (int j = 0; j + (1 << i) <= (1 << log); j++) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
        look_up.resize(sz + 1);
        for (int i = 2; i < look_up.size(); i++) {
            look_up[i] = look_up[i >> 1] + 1;
        }
    }

    T prod(int l, int r) {
        int b = look_up[r - l];
        return min(table[b][l], table[b][r - (1 << b)]);
    }
};
///@brief sparse table