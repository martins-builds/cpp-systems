#include <iostream>

int main(void){
    int c0;
    std::cin >> c0;
    while (c0 != 1){
        if (c0 % 2 == 0)
            c0 /= 2;
        else
            c0 = (3 * c0) + 1;
    }
    
    return 0;
}