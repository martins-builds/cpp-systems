#include <cassert>
#include <iostream>
#include "ring-buffer.hpp"

struct Sample {
    int t = 0;
    int ax = 0;
};

struct Sample {
    unsigned int t;
    short ax, ay, az;
};

void test_sample_struct() {
    RingBuffer<Sample, 4> rb;
    assert(rb.push(Sample{100, 1, 2, 3}));
    assert(rb.push(Sample{110, 4, 5, 6}));

    Sample s{};
    assert(rb.pop(s));
    assert(s.t == 100 && s.ax == 1 && s.ay == 2 && s.az == 3);
    assert(rb.pop(s));
    assert(s.t == 110 && s.ax == 4 && s.ay == 5 && s.az == 6);
    assert(rb.empty());
}

int main() {
    RingBuffer<int, 3> rb;
    int x = 0;

    RingBuffer<Sample, 4> sb;
    Sample s;

    assert(sb.push(Sample{100, 10}));
    assert(sb.push(Sample{110, 12}));
    assert(sb.push(Sample{120, 9}));
    assert(sb.size() == 3);

    assert(sb.pop(s) && s.t == 100 && s.ax == 10);
    assert(sb.pop(s) && s.t == 110 && s.ax == 12);
    assert(sb.pop(s) && s.t == 120 && s.ax == 9);
    assert(sb.empty());

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