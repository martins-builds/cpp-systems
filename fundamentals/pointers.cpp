#include <iostream>
using namespace std;

int main(){
    int i, *p;
    i = 2;
    p = &i;
    cout << *p << endl;
    cout << "This computing environment uses:" << endl;
    cout << sizeof(char) << " bytes for chars" << endl;
    cout << sizeof(short int) << " bytes for shorts" << endl;
    cout << sizeof(int) << " bytes for ints" << endl;
    cout << sizeof(long int) << " bytes for longs" << endl;
    cout << sizeof(float) << " bytes for floats" << endl;
    cout << sizeof(double) << " bytes for doubles" << endl;
    cout << sizeof(bool) << " byte for bools" << endl;
    cout << sizeof(int * ) << " bytes for pointers" << endl;

    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);

	int *ptr = vector;
	int min = *p;
	ptr++; //go next value
	for(int i = 1; i < n; i++) {
		if(*ptr < min)
			min = *ptr;
		ptr++;
	}
	cout << min << endl;
    return 0;
}