#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Observed frequencies
    int O[5] = {1010, 860, 90, 35, 5};
    int total = 2000;
    
    // Expected probabilities for poker test (four-digit numbers)
    double P[5] = {0.504, 0.432, 0.027, 0.036, 0.001}; // Adjust if needed
    double E[5];
    
    cout << "Program 3: Poker Test\n";
    cout << "Critical value (χ²₀.₀₅,₄) = 9.49\n\n";
    
    // Calculate expected frequencies
    for(int i = 0; i < 5; i++) {
        E[i] = total * P[i];
    }
    
    // Calculate Chi-Square statistic
    double chi_square = 0;
    for(int i = 0; i < 5; i++) {
        chi_square += pow(O[i] - E[i], 2) / E[i];
    }
    
    cout << "Category\tObserved\tExpected\n";
    cout << "All diff\t" << O[0] << "\t\t" << E[0] << endl;
    cout << "One pair\t" << O[1] << "\t\t" << E[1] << endl;
    cout << "Two pairs\t" << O[2] << "\t\t" << E[2] << endl;
    cout << "Three kind\t" << O[3] << "\t\t" << E[3] << endl;
    cout << "All same\t" << O[4] << "\t\t" << E[4] << endl;
    
    cout << "\nChi-Square = " << chi_square << endl;
    
    if(chi_square < 9.49)
        cout << "H0 not rejected. Numbers are independent.\n";
    else
        cout << "H0 rejected. Numbers are dependent.\n";
    
    return 0;
}