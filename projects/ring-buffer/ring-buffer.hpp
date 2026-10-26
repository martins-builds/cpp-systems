#pragma once
#include <array>
#include <cstddef>

template <typename T, std::size_t N>
class RingBuffer {
    static_assert(N > 0, "capacity must be greater than 0");

public:
    bool push(const T& value) {
        // TODO 1: if full, return false
        // TODO 2: store value at buf_[tail_]
        // TODO 3: advance tail_ with wraparound
        // TODO 4: increase count_
        return true;
    }

    bool pop(T& out) {
        // TODO 1: if empty, return false
        // TODO 2: copy buf_[head_] into out
        // TODO 3: advance head_ with wraparound
        // TODO 4: decrease count_
        return true;
    }

    bool empty() const { return count_ == 0; }
    bool full() const { return count_ == N; }
    std::size_t size() const { return count_; }
    static constexpr std::size_t capacity() { return N; }

private:
    std::array<T, N> buf_{};
    std::size_t head_ = 0;
    std::size_t tail_ = 0;
    std::size_t count_ = 0;
};