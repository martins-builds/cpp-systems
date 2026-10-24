#include <iostream>

struct Tracer {
    const char* name;

    Tracer(const char* n) : name(n) {          // constructor
        std::cout << "construct " << name << "\n";
    }
    ~Tracer() {                                // destructor
        std::cout << "destroy " << name << "\n";
    }
};

int main() {
    Tracer a("a");
    {
        Tracer b("b");
        std::cout << "inside block\n";
    }
    Tracer* c = new Tracer("c");
    std::cout << "before delete\n";
    delete c;
    std::cout << "end of main\n";
}