#include <iostream>
using namespace std;
    struct sct {
    int t[2];
};
    struct str {
    sct t[2];
};

int main(void){
    str t[2] = { {0, 2, 4, 6}, {1, 3, 5, 7} };
    int c0;
    int steps = 0;
    cin >> c0;
    while (c0 != 1){
        if (c0 % 2 == 0)
            c0 /= 2;
        else
            c0 = (3 * c0) + 1;
        cout << c0 << endl;
        steps++;
    }
    cout << steps << endl;

    cout << t[1].t[0].t[1] << t[0].t[1].t[0];
    return 0;
}