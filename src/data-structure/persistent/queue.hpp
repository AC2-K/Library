#pragma once
#include <cassert>
namespace kyopro {

template <typename T, int lg = 20> class persistent_queue {
    struct Node {
        Node() = default;
        std::size_t index;
        T val;
        Node* prev[20];
    };

    Node *front_ptr = nullptr, *back_ptr = nullptr;
    std::size_t siz;

public:
    persistent_queue(Node* front_ptr = nullptr,
                     Node* back_ptr = nullptr,
                     int siz = 0)
        : front_ptr(front_ptr), back_ptr(back_ptr), siz(siz) {}
    std::size_t size() const { return siz; }
    bool empty() const { return size() == 0; }

    persistent_queue push(const T& x) {
        Node* ptr = new Node();
        ptr->val = x;
        ptr->prev[0] = back_ptr;
        for (int i = 1; i < lg; i++) {
            Node* c = ptr->prev[i - 1];
            if (c)
                ptr->prev[i] = c->prev[i - 1];
            else
                break;
        }

        if (siz) {
            return persistent_queue(front_ptr, ptr, siz + 1);
        } else {
            return persistent_queue(ptr, ptr, siz + 1);
        }
    }
    persistent_queue pop() {
        if (!front_ptr || !back_ptr || siz == 1) {
            return persistent_queue();
        }
        int d = siz - 2;
        Node* cur = back_ptr;
        while (d) {
            int jump = 31 - __builtin_clz(d);
            d -= (1 << jump);
            cur = cur->prev[jump];
        }

        return persistent_queue(cur, back_ptr, siz - 1);
    }

    T front() {
        assert(siz);
        return front_ptr->val;
    }
    T back() {
        assert(siz);
        return back_ptr->val;
    }
};
};  // namespace kyopro

/**
 * @brief 永続Queue
 */