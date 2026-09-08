#include <iostream>

void work(int &x){
    //saving memory for large data and can be used to change
    x++;
}
int main(){
    int a = 5;
    int c = 10;
    int &b = a;

    std :: cout << b+5 << std :: endl;
    work(c);
    std :: cout << c << std :: endl;
    return 0;
}