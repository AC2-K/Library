#pragma once
#include <cassert>
#include <cstdint>

namespace kyopro {
template <typename T, std::uint32_t lg> class BinaryTrie {
    using u32 = std::uint32_t;
    using usize = std::size_t;

    struct Node {
        usize cnt;
        Node* par;
        Node* ch[2]{nullptr, nullptr};

        Node() : cnt(0), par(nullptr) {}
    };

public:
    Node* root = new Node();

    BinaryTrie() : root(new Node()){}

    usize size() const { return root->cnt; }
    bool empty() const { return size() == 0; }
    
    usize count(T x) const {
        Node* cur = root;
        for (int i = lg - 1; i >= 0; --i) {
            T b = (x >> i & T(1));

            if (cur->ch[b] == nullptr || cur->ch[b] == 0) {
                return 0;
            } else {
                cur = cur->ch[b];
            }
        }

        return cur->cnt;
    }

    void insert(T x) {
        Node* cur = root;

        for (int i = lg - 1; i >= 0; --i) {
            T b = (x >> i & T(1));

            if (cur->ch[b] == nullptr) {
                cur->ch[b] = new Node();
                cur->ch[b]->par = cur;
            }

            cur = cur->ch[b];
        }

        ++cur->cnt;

        while (cur->par != nullptr) {
            cur = cur->par;

            cur->cnt = 0;

            if (cur->ch[0] != nullptr) cur->cnt += cur->ch[0]->cnt;
            if (cur->ch[1] != nullptr) cur->cnt += cur->ch[1]->cnt;
        }
    }

    void erase(T x) {
        Node* cur = root;
        for (int i = lg - 1; i >= 0; --i) {
            T b = (x >> i & T(1));
            cur = cur->ch[b];
            assert(cur);
        }

        --cur->cnt;

        while (cur->par != nullptr) {
            cur = cur->par;

            cur->cnt = 0;

            if (cur->ch[0] != nullptr) {
                cur->cnt += cur->ch[0]->cnt;
            }
            if (cur->ch[1] != nullptr) {
                cur->cnt += cur->ch[1]->cnt;
            }
        }
    }

    T max() const {
        assert(size() > 0);

        Node* cur = root;

        T res = 0;
        for (int i = lg - 1; i >= 0; --i) {
            if (cur->ch[1] != nullptr && cur->ch[1]->cnt != 0) {
                cur = cur->ch[1];
                res |= (T(1) << i);
            } else {
                cur = cur->ch[0];
            }
        }

        return res;
    }

    T min() const {
        assert(size() > 0);

        Node* cur = root;

        T res = 0;

        for (int i = lg - 1; i >= 0; --i) {
            if (cur->ch[0] != nullptr && cur->ch[0]->cnt != 0) {
                cur = cur->ch[0];
            } else {
                cur = cur->ch[1];
                res |= (T(1) << i);
            }
        }

        return res;
    }

    T kth_smallest(usize k) const {
        assert(k < this->size());

        Node* cur = root;
        T res = 0;

        for (int i = lg - 1; i >= 0; --i) {
            if (cur->ch[0] != nullptr && k < cur->ch[0]->cnt) {
                cur = cur->ch[0];
            } else {
                if (cur->ch[0] != nullptr) k -= cur->ch[0]->cnt;

                cur = cur->ch[1];
                res |= (T(1) << i);
            }
        }

        return res;
    }

    T kth_largest(usize k) const {
        assert(k < this->size());

        Node* cur = root;
        T res = 0;

        for (int i = lg - 1; i >= 0; --i) {
            if (cur->ch[1] != nullptr && k < cur->ch[1]->cnt) {
                cur = cur->ch[1];
                res |= (T(1) << i);
            } else {
                if (cur->ch[1] != nullptr) k -= cur->ch[1]->cnt;
                cur = cur->ch[0];
            }
        }

        return res;
    }
};

};  // namespace kyopro