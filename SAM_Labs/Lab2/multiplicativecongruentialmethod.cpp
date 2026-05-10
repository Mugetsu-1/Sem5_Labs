#include <iostream>
using namespace std;

int main() {
    int X = 117, a = 43, c = 0, m = 1000;
    for(int i = 0; i < 4; i++) {
        X = (a * X + c) % m;
        double R = (double)X / m;
        cout << X << "\t\t" << R << endl;
    }
    return 0;
}
