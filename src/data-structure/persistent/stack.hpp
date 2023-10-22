#pragma once
#include <cassert>
namespace kyopro {
template <class T> class persistent_stack {
    class Node {
    public:
        T val;
        Node* prev;
    };

    Node* head;
    int sz;

    persistent_stack(Node* head, int sz) : head(head), sz(sz) {}

public:
    persistent_stack() : head(nullptr) {}

    T top() const {
        assert(head);
        return head->val;
    }
    persistent_stack pop() const {
        assert(head);
        return persistent_stack(head->prev, sz - 1);
    }
    persistent_stack push(const T& v) const {
        return persistent_stack(new Node{v, head}, sz + 1);
    }
    int size() const { return sz; }
    bool empty() const { return (head == nullptr); }
};
};  // namespace kyopro

/**
 * @brief 永続Stack
 */