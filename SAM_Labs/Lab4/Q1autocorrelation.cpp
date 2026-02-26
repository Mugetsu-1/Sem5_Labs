#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Given values
    double rho_im = -0.1945;   // Calculated test statistic
    double sigma = 0.1280;     // Standard error
    double Z_critical = 1.96;  // Z(0.025) at alpha = 0.05

    // Step 1: State hypotheses
    cout << "H0: The sequence is independent (no autocorrelation)\n";
    cout << "H1: The sequence is not independent (autocorrelation exists)\n\n";

    // Step 2: Calculate Z value
    double Z_calculated = rho_im / sigma;

    cout << "Calculated Z value = rho_im / sigma\n";
    cout << "Z = " << rho_im << " / " << sigma << " = " 
         << Z_calculated << endl << endl;

    // Step 3: Decision Rule
    cout << "Decision Rule: Reject H0 if |Z| > " << Z_critical << endl;
    cout << "|Z| = " << fabs(Z_calculated) << endl << endl;

    // Step 4: Conclusion
    if (fabs(Z_calculated) > Z_critical) {
        cout << "Conclusion: Reject H0\n";
        cout << "There is autocorrelation. Sequence is NOT independent.\n\n";
    } else {
        cout << "Conclusion: Fail to Reject H0\n\n";
        cout << "No significant autocorrelation. Sequence is independent.\n\n";
    }

    return 0;
}