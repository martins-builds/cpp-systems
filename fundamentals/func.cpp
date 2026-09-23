#include <iostream>
using namespace std;

void greet(void){
    cout << "Ave user!" << endl;
}
void greet_many_times(int how_many_times) {
  while (how_many_times > 0) {
    greet();
    how_many_times--;
  }
}
