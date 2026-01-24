#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate factorial
int factorial(int x) {
    int f = 1;
    for(int i = 1; i <= x; i++)
        f *= i;
    return f;
}

int main() {
    int n = 10, k = 3;
    double p = 0.5;

    // Binomial probability formula
    // P(X=k)=(kn​)pk(1−p)n−k
    double probability = (factorial(n) / (factorial(k) * factorial(n - k)))
                          * pow(p, k) * pow(1 - p, n - k);

    cout << "Binomial probability: " << probability << endl;

    return 0;
}
