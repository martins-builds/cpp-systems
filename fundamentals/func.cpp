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

int main(void) {
  int size_of_ego;

  cout << "How big is your ego? [km]" << endl;
  cin >> size_of_ego;
  greet_many_times(1 + size_of_ego);
  return 0;
}