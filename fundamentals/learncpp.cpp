#include <iostream>
#include <string>

using namespace std;

int add(int a, int b){
    return a+b;
}

int main(){
    int age = 25;
    int year = 2000;
    double price = 19.99;
    char grade = 'A';
    bool isActive = true;
    std::string name = "John";

    cout << "Alive" << endl;
    int result = add(age, year);
    cout << result << endl;
    return 0;
}