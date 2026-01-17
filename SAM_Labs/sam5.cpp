
#include <cmath>
using namespace std;

class Binomial {
private:
    int n;
    double p;

public:
    // Constructor
    Binomial(int n, double p) {
        this->n = n;
        this->p = p;
    }

    // Function to calculate factorial
    long long factorial(int x) {
        long long fact = 1;
        for (int i = 1; i <= x; i++) {
            fact *= i;
        }
        return fact;
    }

    // Function to calculate probability P(X = k)
    double probability(int k) {
        long long nCk = factorial(n) / (factorial(k) * factorial(n - k));
        return nCk * pow(p, k) * pow(1 - p, n - k);
    }
};

int main() {
    Binomial b(10, 0.5);

    double result = b.probability(3) 
                  + b.probability(6) 
                  + b.probability(9);

    cout << "Required Probability = " << result;
    
    return 0; }
