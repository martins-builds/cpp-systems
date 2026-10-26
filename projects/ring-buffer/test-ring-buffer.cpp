#include <cassert>
#include <iostream>
#include "ring-buffer.hpp"

struct Sample {
    int t = 0;
    int ax = 0;
};

int main() {
    RingBuffer<int, 3> rb;
    int x = 0;

    RingBuffer<Sample, 4>;

    assert(rb.empty());
    assert(rb.push(1));
    assert(rb.push(2));
    assert(rb.push(3));
    assert(rb.full());
    assert(!rb.push(4));            // full: rejected

    assert(rb.pop(x) && x == 1);
    assert(rb.push(4));             // wraparound
    assert(rb.pop(x) && x == 2);
    assert(rb.pop(x) && x == 3);
    assert(rb.pop(x) && x == 4);
    assert(rb.empty());
    assert(!rb.pop(x));             // empty: rejected

    std::cout << "all tests passed\n";
}