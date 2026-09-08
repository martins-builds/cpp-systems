#include <iostream>
#include <vector>

void work(int &x){
    //saving memory for large data and can be used to change
    x++;
}

void do_more(std::vector<int> data){
    data[0] = 10000;
}

int main(){
    int a = 5;
    int c = 10;
    int &b = a;
    std::vector<int> data = {10, 101, 30, 50, 40, 200};

    std :: cout << b+5 << std :: endl;
    work(c);
    std :: cout << c << std :: endl;
    std :: cout << data[0] << std :: endl;
    do_more(data);
    std :: cout << data[0] << std :: endl;
    
    return 0;
}