#pragma once

#include <cassert>
#include <deque>

namespace kyopro {
template <typename Key, typename Value> class slide_window_min {
    std::deque<std::pair<Key, Value>> deq;

public:
    bool empty() const noexcept { return deq.empty(); }

    /// @brief push the element to end of this structure.
    /// @note keys given to this method must be increasing.
    void emplace(Key key, Value val) {
        while (!deq.empty() && deq.back().second >= val) {
            deq.pop_back();
        }
        deq.emplace_back(key, val);
    }

    /// @brief remove elements whose key are less than t from this structure
    void pop(Key t) {
        while (!deq.empty() && deq.front().first < t) deq.pop_front();
    }

    /// @brief find the minimum value from this queue.
    Value fold() const noexcept {
        assert(!empty());
        return deq.front().second;
    }
};

};  // namespace kyopro