#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // Total numbers
    int N = 1000;

    // Observed frequencies
    double O1 = 680;   // All digits different
    double O2 = 289;   // Exactly one pair
    double O3 = 31;    // Three like digits

    // Expected probabilities for 3-digit numbers
    double P1 = 0.72;   // All different  (720/1000)
    double P2 = 0.27;   // Exactly one pair (270/1000)
    double P3 = 0.01;   // Three like digits (10/1000)

    // Expected frequencies
    double E1 = N * P1;
    double E2 = N * P2;
    double E3 = N * P3;

    cout << "H0: Random numbers are independent.\n";
    cout << "H1: Random numbers are not independent.\n\n";

    cout << "Expected Frequencies:\n";
    cout << "All different = " << E1 << endl;
    cout << "One pair = " << E2 << endl;
    cout << "Three like digits = " << E3 << endl << endl;

    // Chi-square calculation
    double chi_square = 
        pow(O1 - E1, 2) / E1 +
        pow(O2 - E2, 2) / E2 +
        pow(O3 - E3, 2) / E3;

    cout << "Calculated Chi-square = " << chi_square << endl;
    cout << "Critical Chi-square (0.05, df=2) = 5.99\n\n";

    // Decision
    if (chi_square > 5.99) {
        cout << "Conclusion: Reject H0\n";
        cout << "Numbers are NOT independent.\n";
    } else {
        cout << "Conclusion: Fail to Reject H0\n";
        cout << "Numbers are independent.\n";
    }

    return 0;
}