#include <iostream>

int main(void){
    int c0;
    int steps = 0;
    std::cin >> c0;
    while (c0 != 1){
        if (c0 % 2 == 0)
            c0 /= 2;
        else
            c0 = (3 * c0) + 1;
        std::cout << c0 << std::endl;
        steps++;
        std::cout << steps << std::endl;
    }
    return 0;
}