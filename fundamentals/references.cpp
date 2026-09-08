#include <iostream>

void work(int x){

}
int main(){
    int a = 5;
    int c = 10;
    int &b = a;

    std :: cout << b+5 << std :: endl;
    work(c);
    return 0;
}