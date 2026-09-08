#include <iostream>
#include <string>

int main(){
    const int MAX_AGE = 90;
    int *a = new int;
    *a = 2;

    std::cout << *a << std::endl;
    return 0;
}