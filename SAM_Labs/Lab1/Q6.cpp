#include <iostream>
using namespace std;

int main() {
    // Given rates
    double lambda = 0.1;   // arrival rate
    double mu = 0.2;       // service rate

    
    double rho = lambda / mu;          
    double P0 = 1 - rho;               
    double L = rho / (1 - rho);         // customers
    double W = 1 / (mu - lambda);       // time in system

    cout << "a) Probability customer will not wait: " << P0 << endl;
    cout << "b) Expected number of customers in bank: " << L << endl;
    cout << "c) Expected time in bank (minutes): " << W << endl;

    return 0;
}
