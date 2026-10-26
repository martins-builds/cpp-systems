#include <iostream>

struct Point {
    int x;
    int y;
};

void move_copy(Point p) {          // gets a COPY
    p.x += 10;
}

void move_ref(Point& p) {          // gets the ORIGINAL
    p.x += 10;
}

void print(const Point& p) {       // read-only, no copy
    std::cout << "(" << p.x << ", " << p.y << ")\n";
}

int main() {
    Point a{1, 2};                 // on the stack
    move_copy(a);
    print(a);                      // still (1, 2)
    move_ref(a);
    print(a);                      // now (11, 2)

    Point *h = new Point{5, 6};    // on the heap
    print(*h);
    delete h;                      // you must free it yourself
}