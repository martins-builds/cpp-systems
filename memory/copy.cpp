#include <iostream>

class IntArray {
public:
    IntArray(size_t n) : size_(n), data_(new int[n]{}) {
        std::cout << "construct\n";
    }
    ~IntArray() {
        delete[] data_;
        std::cout << "destroy\n";
    }
    int& operator[](size_t i) { return data_[i]; }
    size_t size() const { return size_; }

    IntArray(const IntArray& other)
        : size_(other.size_), data_(new int[other.size_]) { //always need the copy constructor and copy assignment too
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
        std::cout << "copy\n";
    }

    IntArray& operator=(const IntArray& other) {
        if (this == &other) {              // guard against a = a
            return *this;
        }
        int* new_data = new int[other.size_];     // allocate first
        for (size_t i = 0; i < other.size_; ++i) {
            new_data[i] = other.data_[i];
        }
        delete[] data_;                           // then free the old array
        data_ = new_data;
        size_ = other.size_;
        return *this;
    }

private:
    size_t size_;
    int* data_;
};

int main() {
    IntArray a(4);
    a[0] = 42;

    IntArray b(2);       // b already exists, with its own 2-element array
    b = a;               // copy ASSIGNMENT, not construction
    b[0] = 99;

    std::cout << "a[0] = " << a[0] << ", b size = " << b.size() << "\n";
}