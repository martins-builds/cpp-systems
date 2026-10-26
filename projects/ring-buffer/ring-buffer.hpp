#pragma once
#include <array>
#include <cstddef>

template <typename T, std::size_t N>
class RingBuffer {
    static_assert(N > 0, "capacity must be greater than 0");

public:
    bool push(const T& value) {
        if (full()) {
            return false;
        }
        buf_[tail_] = value;
        tail_ = (tail_ + 1) % N;
        ++count_;
        return true;
    }

    bool pop(T& out) {
        if (empty()){
            return false;
        }
        out = buf_[head_];
        head_ = (head_ + 1) % N;
        --count_;
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