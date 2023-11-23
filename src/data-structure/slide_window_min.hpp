#pragma once

#include <cassert>
#include <deque>

namespace kyopro {
template <typename Key, typename Value> class slide_window_min {
    std::deque<std::pair<Key, Value>> deq;

public:
    bool empty() const noexcept { return deq.empty(); }

    /// @note keys given to this method must be increasing.
    void emplace(Key key, Value val) {
        while (!deq.empty() && deq.back().second >= val) {
            deq.pop_back();
        }
        deq.emplace_back(key, val);
    }

    void pop(Key t) {
        while (!deq.empty() && deq.front().first < t) deq.pop_front();
    }

    Value fold() const noexcept {
        assert(!empty());
        return deq.front().second;
    }
};

};  // namespace kyopro

/**
 * @brief Slide Window Minimum(スライド最小値)
*/