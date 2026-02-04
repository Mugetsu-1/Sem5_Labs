#include <iostream>
#include <cmath>
using namespace std;

int factorial(int x) {
    int f = 1;
    for(int i = 1; i <= x; i++)
        f *= i;
    return f;
}

double binomial(int n, int k, double p) {
    return (factorial(n) / (factorial(k) * factorial(n - k)))
           * pow(p, k) * pow(1 - p, n - k);
}

int main() {
    int n = 10;
    double p = 0.5;

    // P(3) + P(6) + P(9)
    double probability = binomial(n, 3, p)
                       + binomial(n, 6, p)
                       + binomial(n, 9, p);

    cout << "Probability: " << probability << endl;

    return 0;
}
