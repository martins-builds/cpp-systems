#include <iostream>
#include <utility>

class IntArray {
public:
    explicit IntArray(size_t n) : size_(n), data_(new int[n]{}) {
        std::cout << "construct(" << n << ")\n";
    }
    ~IntArray() { delete[] data_; }

    IntArray(const IntArray& o) : size_(o.size_), data_(new int[o.size_]) {
        for (size_t i = 0; i < size_; ++i) data_[i] = o.data_[i];
        std::cout << "copy\n";
    }
    IntArray& operator=(const IntArray& o) {
        if (this == &o) return *this;
        int* nd = new int[o.size_];
        for (size_t i = 0; i < o.size_; ++i) nd[i] = o.data_[i];
        delete[] data_;
        data_ = nd;
        size_ = o.size_;
        std::cout << "copy-assign\n";
        return *this;
    }

    IntArray(IntArray&& o) noexcept : size_(o.size_), data_(o.data_) {
        o.size_ = 0;
        o.data_ = nullptr;                 // leave the source empty
        std::cout << "move\n";
    }
    IntArray& operator=(IntArray&& o) noexcept {
        if (this != &o) {
            delete[] data_;                // free what we had
            data_ = o.data_;               // steal
            size_ = o.size_;
            o.data_ = nullptr;
            o.size_ = 0;
        }
        std::cout << "move-assign\n";
        return *this;
    }

    size_t size() const { return size_; }
    int& operator[](size_t i) { return data_[i]; }

private:
    size_t size_;
    int* data_;
};

IntArray make(size_t n) {
    IntArray t(n);
    t[0] = 7;
    return t;
}

int main() {
    IntArray a(4);
    IntArray b = a;                 // a is a named object
    IntArray c = std::move(a);      // we say "a can be stolen from"
    std::cout << "a.size=" << a.size() << " c.size=" << c.size() << "\n";

    IntArray d(1);
    d = make(3);                    // right-hand side is a temporary
}