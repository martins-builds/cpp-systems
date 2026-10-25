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

private:
    size_t size_;
    int* data_;
};

int main() {
    IntArray a(4);
    a[0] = 42;

    IntArray b = a;     // copy a into b
    b[0] = 99;

    std::cout << "a[0] = " << a[0] << "\n";
}