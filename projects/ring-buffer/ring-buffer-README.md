# RingBuffer<T, N>

A fixed-capacity circular buffer in C++17. It stores up to `N` items of any type `T`, with no heap allocation. Intended for buffering sensor samples on a microcontroller and in a Linux daemon.

## Features

- Header-only template: `RingBuffer<T, N>`
- No heap allocation: storage is a `std::array<T, N>` inside the object
- `push` returns `false` when full; `pop` returns `false` when empty (no exceptions)
- Works with any default-constructible, copy-assignable type (ints, structs)
- Compile-time check that the capacity is greater than zero

## Usage

```cpp
#include "ring-buffer.hpp"

RingBuffer<int, 8> rb;

rb.push(42);          // true, or false if the buffer is full

int x;
if (rb.pop(x)) {      // true and x == 42, or false if empty
    // use x
}

rb.size();            // items currently stored
rb.capacity();        // 8
rb.empty();
rb.full();
```

## Design

| Member   | Meaning                                         |
|----------|-------------------------------------------------|
| `buf_`   | `std::array<T, N>`, the storage                 |
| `head_`  | index of the oldest item (next to read)         |
| `tail_`  | index where the next item will be written       |
| `count_` | number of items stored                          |

Both indices advance forward with `index = (index + 1) % N`. Keeping a separate `count_` means "full" and "empty" are never ambiguous (when `head_ == tail_` the buffer could be either).

### Special member functions: Rule of 0

The class writes no destructor, copy constructor, copy assignment, move constructor or move assignment. Its only data members are a `std::array` and three `std::size_t` counters, which all copy and move correctly on their own, so the compiler-generated versions are correct. Nothing is allocated with `new`, so there is nothing to free and no pointer that could be copied shallowly.

Compare with an earlier practice class in this repo that owned a raw `new[]` array: that one needed all five functions written by hand (the Rule of 5) to avoid double frees and leaks.

## Build and test

From the `cpp-systems/` folder:

```
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined \
    projects/ring-buffer/test-ring-buffer.cpp -o build/ring-buffer-test
./build/ring-buffer-test
```

Expected output: `all tests passed`

Do not compile with `-DNDEBUG`: it removes `assert`, and the tests would pass without checking anything.

### Covered by the tests

- empty on creation
- push until full, push rejected when full
- pop in first-in, first-out order
- one wraparound (push after a pop)
- pop rejected when empty
- a struct type (`Sample`) stored and read back intact

Planned: a longer loop that wraps around the array many times.

## Results

| Check                                 | Result |
|---------------------------------------|--------|
| Tests under AddressSanitizer + UBSan  | pass   |
| Compiler warnings (`-Wall -Wextra`)   | none   |

## Known limitations

- `T` must be default-constructible, because `std::array<T, N>` is value-initialised.
- Not thread-safe. A single producer and single consumer on different threads (or an interrupt and the main loop) would need atomic indices or a critical section.
- `pop` copies the item out. Moving it out would be cheaper for large types.
- When full, `push` rejects the new item rather than overwriting the oldest. Some sensor use cases prefer overwrite-oldest.

## What I would change

- Add a longer wraparound test and a test with a non-trivial type
- Add an overwrite-oldest variant
- Make it safe for one producer and one consumer, for an interrupt-to-main-loop handoff on the MCU
