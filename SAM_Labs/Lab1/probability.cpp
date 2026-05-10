#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Given values
    double p = 0.02;
    int n = 100;


    
    // P(X = 0) = (1 - p)^n
    double probability = pow(1 - p, n);

    cout << "Probability that no item is defective: " << probability << endl;

    return 0;
}
