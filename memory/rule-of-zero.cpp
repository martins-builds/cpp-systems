#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class IntArray {
public:
    explicit IntArray(size_t n) : data_(n) {}      // n zeroed ints
    size_t size() const { return data_.size(); }
    int& operator[](size_t i) { return data_[i]; }
private:
    std::vector<int> data_;
};

// Part B: ownership with unique_ptr
struct Tracer {
    const char* name;
    explicit Tracer(const char* n) : name(n) { std::cout << "construct " << name << "\n"; }
    ~Tracer() { std::cout << "destroy " << name << "\n"; }
};

int main() {
    {
        IntArray a(4);
        a[0] = 42;

        IntArray b = a;                  // deep copy, for free
        b[0] = 99;
        std::cout << "a[0]=" << a[0] << " b[0]=" << b[0] << "\n";

        IntArray c = std::move(a);       // move, for free
        std::cout << "c.size=" << c.size() << " c[0]=" << c[0]
                  << " a.size=" << a.size() << "\n";
    }

    {
        auto p = std::make_unique<Tracer>("p");
        std::cout << "made p\n";
        auto q = std::move(p);           // ownership moves to q
        std::cout << (p ? "p owns it" : "p is empty") << "\n";
    }
    std::cout << "after scope\n";
}